// include/fsm/RedisStorage.hpp
#pragma once
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>
#include <vector>
#include <drogon/drogon.h>
#include <drogon/nosql/RedisClient.h>
#include <hiredis/hiredis.h>
#include <nlohmann/json.hpp>
#include <corogram/fsm/BaseStorage.hpp>
#include <corogram/fsm/StorageKey.hpp>

namespace corogram::fsm
{

    // =========================================================================
    //  RedisStorage — Redis-backed FSM storage
    //
    //  Key format:
    //    state : "fsm:{bot_id}:{chat_id}:{user_id}:state"
    //    data  : "fsm:{bot_id}:{chat_id}:{user_id}:data"
    //
    //  Thread safety:
    //    set_state / get_state / set_data / get_data / clear — atomic Redis
    //
    //  Setup (in main.cpp, before app().run()):
    //    app().createRedisClient("127.0.0.1", 6379);
    //
    //  Usage:
    //    auto storage = std::make_shared<corogram::fsm::RedisStorage>();
    //    dp.middleware(corogram::fsm::make_fsm_middleware(storage));
    //
    //  With TTL:
    //    auto storage = std::make_shared<corogram::fsm::RedisStorage>(
    //        /*state_ttl=*/3600,   // 1 hour
    //        /*data_ttl=*/ 3600
    //    );
    // =========================================================================

    class RedisStorage : public BaseStorage
    {
    public:
        // ttl = 0 → no expiry
        explicit RedisStorage(
            int state_ttl = 0,
            int data_ttl = 0,
            std::string key_prefix = "fsm")
            : state_ttl_(state_ttl), data_ttl_(data_ttl), prefix_(std::move(key_prefix))
        {
        }

        // ── set_state ─────────────────────────────────────────────────────────
        //  nullopt → DEL
        //  string  → SET
        drogon::Task<void> set_state(
            const StorageKey &key,
            std::optional<std::string> state) override
        {
            auto redis = get_client();
            auto k = state_key(key);

            if (!state.has_value())
            {
                co_await redis->execCommandCoro("DEL %s", k.c_str());
            }
            else if (state_ttl_ > 0)
            {
                co_await redis->execCommandCoro(
                    "SET %s %s EX %d",
                    k.c_str(),
                    state->c_str(),
                    state_ttl_);
            }
            else
            {
                co_await redis->execCommandCoro(
                    "SET %s %s",
                    k.c_str(),
                    state->c_str());
            }
        }

        // ── get_state ─────────────────────────────────────────────────────────
        drogon::Task<std::optional<std::string>> get_state(
            const StorageKey &key) override
        {
            auto redis = get_client();
            auto k = state_key(key);

            auto result = co_await redis->execCommandCoro("GET %s", k.c_str());

            if (result.type() == drogon::nosql::RedisResultType::kNil)
                co_return std::nullopt;

            co_return result.asString();
        }
        drogon::Task<std::optional<std::string>> get_field(
            const StorageKey &key,
            std::string_view field) override
        {
            // JSON formatında HGET yok; tam parse gerekiyor.
            // İleride Redis Hash formatına geçilirse burası HGET olur.
            auto data = co_await get_data(key);
            auto it = data.find(std::string(field));
            if (it == data.end())
                co_return std::nullopt;
            co_return it->second;
        }
        // ── set_data ──────────────────────────────────────────────────────────
        //  Stores the entire data map serialized as JSON.
        //  Empty map → DEL
        drogon::Task<void> set_data(
            const StorageKey &key,
            std::unordered_map<std::string, std::string> data) override
        {
            auto redis = get_client();
            auto k = data_key(key);

            if (data.empty())
            {
                co_await redis->execCommandCoro("DEL %s", k.c_str());
                co_return;
            }

            // unordered_map → JSON string
            nlohmann::json j = data;
            std::string json_str = j.dump();

            if (data_ttl_ > 0)
            {
                co_await redis->execCommandCoro(
                    "SET %s %s EX %d",
                    k.c_str(),
                    json_str.c_str(),
                    data_ttl_);
            }
            else
            {
                co_await redis->execCommandCoro(
                    "SET %s %s",
                    k.c_str(),
                    json_str.c_str());
            }
        }

        // ── get_data ──────────────────────────────────────────────────────────
        drogon::Task<std::unordered_map<std::string, std::string>> get_data(
            const StorageKey &key) override
        {
            auto redis = get_client();
            auto k = data_key(key);

            auto result = co_await redis->execCommandCoro("GET %s", k.c_str());

            if (result.type() == drogon::nosql::RedisResultType::kNil)
                co_return std::unordered_map<std::string, std::string>{};

            try
            {
                auto j = nlohmann::json::parse(result.asString());
                co_return j.get<std::unordered_map<std::string, std::string>>();
            }
            catch (...)
            {
                co_return std::unordered_map<std::string, std::string>{};
            }
        }

        // ── update_data ───────────────────────────────────────────────────────
        //
        //  Atomik merge — GET+merge+SET üç ayrı round-trip değil, tek bir
        //  EVAL çağrısıyla sunucu tarafında gerçekleşir.
        //
        //  Neden Lua?
        //    GET → (uygulama katmanı merge) → SET yaklaşımı, iki coroutine
        //    aynı key'i eş zamanlı okuduğunda "last-write-wins" race'e düşer:
        //      T1: GET → {a:1}
        //      T2: GET → {a:1}
        //      T1: SET {a:1, b:2}
        //      T2: SET {a:1, c:3}   ← T1'in b:2 yazısı kayboldu
        //    Redis, Lua scriptlerini atomik olarak çalıştırır (single-threaded
        //    event loop); script çalışırken hiçbir başka komut araya giremez.
        //
        //  Script mantığı:
        //    1. Mevcut JSON'ı GET et (yoksa boş obje kabul et).
        //    2. ARGV[2..n] çiftlerini (key, value) şeklinde parse edip merge et.
        //    3. Sonucu SET et; TTL varsa EX ile birlikte yaz.
        //    4. Yeni JSON'ı döndür (hata ayıklama / test için).
        //
        //  ARGV protokolü:
        //    ARGV[1]          = data_ttl (saniye; "0" ise TTL uygulanmaz)
        //    ARGV[2], ARGV[3] = key1, val1
        //    ARGV[4], ARGV[5] = key2, val2
        //    ...
        //
        drogon::Task<void> update_data(
            const StorageKey &key,
            std::unordered_map<std::string, std::string> new_values) override
        {
            if (new_values.empty())
                co_return;

            auto redis = get_client();
            auto data_k = data_key(key);

            // ── Lua script ────────────────────────────────────────────────────
            // Inline script — her çağrıda EVAL ile gönderilir.
            // Redis, scripti SHA ile önbelleğe alır; ilk çağrıdan sonra
            // ağ üzerinden yalnızca SHA gönderilir (EVALSHA davranışı).
            static constexpr std::string_view kScript = R"lua(
local raw = redis.call('GET', KEYS[1])
local obj = {}
if raw and raw ~= '' then
    local ok, parsed = pcall(cjson.decode, raw)
    if ok and type(parsed) == 'table' then
        obj = parsed
    end
end
local ttl = tonumber(ARGV[1]) or 0
local i = 2
while i <= #ARGV do
    obj[ARGV[i]] = ARGV[i + 1]
    i = i + 2
end
local encoded = cjson.encode(obj)
if ttl > 0 then
    redis.call('SET', KEYS[1], encoded, 'EX', ttl)
else
    redis.call('SET', KEYS[1], encoded)
end
return encoded
)lua";

            // ── ARGV listesini oluştur ────────────────────────────────────────
            // execCommandCoro C-style format-string kullandığından argümanları
            // önce bir vektöre derleyip tek bir komut stringi kuruyoruz.
            // EVAL <script> <numkeys> <key> <argv...>
            //
            // Drogon'un execCommandCoro variadic %s argümanlarını destekler;
            // ancak Lua script'i binary-safe %b ile geçmek gerekir (script
            // içinde newline ve özel karakter olabileceğinden).
            // TTL her zaman ARGV[1]:
            std::string ttl_str = std::to_string(data_ttl_);

            // Tüm ARGV değerlerini düz vektöre yaz: [ttl, k1, v1, k2, v2, ...]
            std::vector<std::string> argv_vals;
            argv_vals.reserve(1 + new_values.size() * 2);
            argv_vals.push_back(ttl_str);
            for (auto &[fk, fv] : new_values)
            {
                argv_vals.push_back(fk);
                argv_vals.push_back(fv);
            }

            // Redis EVAL protokolü: EVAL script numkeys key [argv...]
            // execCommandCoro format-string ile dinamik argüman sayısını
            // doğrudan desteklemez; redisFormatCommandArgv seviyesine inmeden
            // bunu yapmanın en temiz yolu komutu parça parça string olarak
            // kurmak yerine Drogon'un transaction API'sini kullanmaktır.
            //
            // Ancak transaction burada gerekmez; tek komut atomik.
            // Drogon'un execCommandCoro variadic overload'ı mevcut,
            // argv_vals'ı elle EVAL komutuna dönüştürüyoruz:
            co_await _eval_update(redis, data_k, kScript, argv_vals);
        }

        // ── clear ─────────────────────────────────────────────────────────────
        drogon::Task<void> clear(const StorageKey &key) override
        {
            auto redis = get_client();
            // DEL accepts multiple keys in a single command
            co_await redis->execCommandCoro(
                "DEL %s %s",
                state_key(key).c_str(),
                data_key(key).c_str());
        }

        // ── close ─────────────────────────────────────────────────────────────
        drogon::Task<void> close() override { co_return; }

    private:
        int state_ttl_;
        int data_ttl_;
        std::string prefix_;

        // ── Key builders ──────────────────────────────────────────────────────
        //    "fsm:{bot_id}:{chat_id}:{user_id}:state"
        //    "fsm:{bot_id}:{chat_id}:{user_id}:data"
        std::string make_key(const StorageKey &key, std::string_view suffix) const
        {
            return prefix_ + ":" +
                   std::to_string(key.bot_id) + ":" +
                   std::to_string(key.chat_id) + ":" +
                   std::to_string(key.user_id) + ":" +
                   std::string(suffix);
        }

        std::string state_key(const StorageKey &key) const { return make_key(key, "state"); }
        std::string data_key(const StorageKey &key) const { return make_key(key, "data"); }

        // ── Redis client ──────────────────────────────────────────────────────
        //  Uses Drogon's global Redis client, available after app().run().
        //  getFastRedisClient: thread-local, better performance
        //  getRedisClient:     shared,       safer
        drogon::nosql::RedisClientPtr get_client() const
        {
            auto client = drogon::app().getRedisClient();
            if (!client)
                throw std::runtime_error(
                    "RedisStorage: Redis client not found. "
                    "Did you call app().createRedisClient()?");
            return client;
        }

        drogon::Task<void> _eval_update(
            drogon::nosql::RedisClientPtr redis,
            const std::string &data_key_str,
            std::string_view script,
            const std::vector<std::string> &argv_vals)
        {
            // EVAL <script> 1 <key> <argv...>
            // Drogon'un execCommandCoro'su format string + variadics kullanır.
            // Dinamik argüman sayısı için komutu elle string olarak kur:
            //   "EVAL %b 1 %s %s %s ..."  — her argv için bir %s

            // Format string'i oluştur
            std::string fmt = "EVAL %b 1 %s";
            for (size_t i = 0; i < argv_vals.size(); ++i)
                fmt += " %s";

            // execCommandCoro doğrudan variadic almaz; Drogon'un
            // RedisClient::execCommandCoro(const char* format, ...) overload'ı var.
            // argv_vals'ı bir RedisCommand'a dönüştürüp gönder:
            std::vector<const char *> args;
            args.reserve(argv_vals.size() + 2); // script ptr+len, key, argv...
            // script binary olarak: %b için ptr + len çifti gerekir
            // key ve argv'ler %s ile

            // En temiz yol: newTransactionCoro yerine direkt sendCommand kullan
            // Drogon'da execCommandCoro overload'ları:
            //   (const char* fmt, ...)
            // %b → (const char* ptr, size_t len) çifti
            // %s → (const char* ptr)

            // argv argümanlarını c_str olarak al
            std::vector<const char *> argv_ptrs;
            argv_ptrs.reserve(argv_vals.size());
            for (const auto &a : argv_vals)
                argv_ptrs.push_back(a.c_str());

            // Drogon execCommandCoro variadic'i doğrudan std::vector alamaz.
            // Bu yüzden argv sayısına göre switch ya da recursive template gerekir.
            // En pratik çözüm: argv'leri tek string'e encode et, Lua'da parse et.

            // ARGV[1] = ttl, ARGV[2] = JSON encoded key-value pairs
            // Lua script'i buna göre güncelle:
            nlohmann::json patch;
            // argv_vals = [ttl, k1, v1, k2, v2, ...]
            for (size_t i = 1; i + 1 < argv_vals.size(); i += 2)
                patch[argv_vals[i]] = argv_vals[i + 1];

            std::string ttl_str = argv_vals[0];
            std::string patch_json = patch.dump();

            static constexpr std::string_view kScript2 = R"lua(
local raw = redis.call('GET', KEYS[1])
local obj = {}
if raw and raw ~= '' then
    local ok, parsed = pcall(cjson.decode, raw)
    if ok and type(parsed) == 'table' then obj = parsed end
end
local ttl = tonumber(ARGV[1]) or 0
local patch = cjson.decode(ARGV[2])
for k, v in pairs(patch) do obj[k] = v end
local encoded = cjson.encode(obj)
if ttl > 0 then
    redis.call('SET', KEYS[1], encoded, 'EX', ttl)
else
    redis.call('SET', KEYS[1], encoded)
end
return encoded
)lua";

            co_await redis->execCommandCoro(
                "EVAL %s 1 %s %s %s",
                std::string(kScript2).c_str(),
                data_key_str.c_str(),
                ttl_str.c_str(),
                patch_json.c_str());
        }
    };

} // namespace corogram::fsm