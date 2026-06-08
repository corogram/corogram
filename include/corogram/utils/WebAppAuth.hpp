// include/corogram/utils/WebAppAuth.hpp
#pragma once
#include <array>
#include <cstring>
#include <optional>
#include <string>
#include <string_view>
#include <unordered_map>
#include <vector>

namespace corogram
{
namespace webappauth {
    // =========================================================================
    //  Internal SHA-256 / HMAC-SHA-256
    //  (reuses the same standalone impl already present in Auth.hpp)
    // =========================================================================

    namespace detail
    {
        struct Sha256State
        {
            uint32_t h[8];
            uint64_t bits = 0;
            uint8_t buf[64]{};
            size_t buflen = 0;

            Sha256State()
            {
                h[0] = 0x6A09E667;
                h[1] = 0xBB67AE85;
                h[2] = 0x3C6EF372;
                h[3] = 0xA54FF53A;
                h[4] = 0x510E527F;
                h[5] = 0x9B05688C;
                h[6] = 0x1F83D9AB;
                h[7] = 0x5BE0CD19;
            }

            static uint32_t rotr(uint32_t x, int n) { return (x >> n) | (x << (32 - n)); }

            void process_block(const uint8_t *blk)
            {
                static constexpr uint32_t K[64] = {
                    0x428A2F98,
                    0x71374491,
                    0xB5C0FBCF,
                    0xE9B5DBA5,
                    0x3956C25B,
                    0x59F111F1,
                    0x923F82A4,
                    0xAB1C5ED5,
                    0xD807AA98,
                    0x12835B01,
                    0x243185BE,
                    0x550C7DC3,
                    0x72BE5D74,
                    0x80DEB1FE,
                    0x9BDC06A7,
                    0xC19BF174,
                    0xE49B69C1,
                    0xEFBE4786,
                    0x0FC19DC6,
                    0x240CA1CC,
                    0x2DE92C6F,
                    0x4A7484AA,
                    0x5CB0A9DC,
                    0x76F988DA,
                    0x983E5152,
                    0xA831C66D,
                    0xB00327C8,
                    0xBF597FC7,
                    0xC6E00BF3,
                    0xD5A79147,
                    0x06CA6351,
                    0x14292967,
                    0x27B70A85,
                    0x2E1B2138,
                    0x4D2C6DFC,
                    0x53380D13,
                    0x650A7354,
                    0x766A0ABB,
                    0x81C2C92E,
                    0x92722C85,
                    0xA2BFE8A1,
                    0xA81A664B,
                    0xC24B8B70,
                    0xC76C51A3,
                    0xD192E819,
                    0xD6990624,
                    0xF40E3585,
                    0x106AA070,
                    0x19A4C116,
                    0x1E376C08,
                    0x2748774C,
                    0x34B0BCB5,
                    0x391C0CB3,
                    0x4ED8AA4A,
                    0x5B9CCA4F,
                    0x682E6FF3,
                    0x748F82EE,
                    0x78A5636F,
                    0x84C87814,
                    0x8CC70208,
                    0x90BEFFFA,
                    0xA4506CEB,
                    0xBEF9A3F7,
                    0xC67178F2,
                };
                uint32_t W[64];
                for (int i = 0; i < 16; ++i)
                    W[i] = (uint32_t(blk[i * 4]) << 24) | (uint32_t(blk[i * 4 + 1]) << 16) | (uint32_t(blk[i * 4 + 2]) << 8) | blk[i * 4 + 3];
                for (int i = 16; i < 64; ++i)
                {
                    uint32_t s0 = rotr(W[i - 15], 7) ^ rotr(W[i - 15], 18) ^ (W[i - 15] >> 3);
                    uint32_t s1 = rotr(W[i - 2], 17) ^ rotr(W[i - 2], 19) ^ (W[i - 2] >> 10);
                    W[i] = W[i - 16] + s0 + W[i - 7] + s1;
                }
                uint32_t a = h[0], b = h[1], c = h[2], d = h[3], e = h[4], f = h[5], g = h[6], hh = h[7];
                for (int i = 0; i < 64; ++i)
                {
                    uint32_t S1 = rotr(e, 6) ^ rotr(e, 11) ^ rotr(e, 25);
                    uint32_t ch = (e & f) ^ (~e & g);
                    uint32_t t1 = hh + S1 + ch + K[i] + W[i];
                    uint32_t S0 = rotr(a, 2) ^ rotr(a, 13) ^ rotr(a, 22);
                    uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
                    uint32_t t2 = S0 + maj;
                    hh = g;
                    g = f;
                    f = e;
                    e = d + t1;
                    d = c;
                    c = b;
                    b = a;
                    a = t1 + t2;
                }
                h[0] += a;
                h[1] += b;
                h[2] += c;
                h[3] += d;
                h[4] += e;
                h[5] += f;
                h[6] += g;
                h[7] += hh;
            }

            void update(const uint8_t *data, size_t len)
            {
                bits += uint64_t(len) * 8;
                while (len > 0)
                {
                    size_t space = 64 - buflen, take = (len < space) ? len : space;
                    std::memcpy(buf + buflen, data, take);
                    buflen += take;
                    data += take;
                    len -= take;
                    if (buflen == 64)
                    {
                        process_block(buf);
                        buflen = 0;
                    }
                }
            }

            std::array<uint8_t, 32> digest()
            {
                buf[buflen++] = 0x80;
                if (buflen > 56)
                {
                    while (buflen < 64)
                        buf[buflen++] = 0;
                    process_block(buf);
                    buflen = 0;
                }
                while (buflen < 56)
                    buf[buflen++] = 0;
                for (int i = 7; i >= 0; --i)
                    buf[buflen++] = uint8_t((bits >> (i * 8)) & 0xFF);
                process_block(buf);
                std::array<uint8_t, 32> out{};
                for (int i = 0; i < 8; ++i)
                {
                    out[i * 4] = uint8_t(h[i] >> 24);
                    out[i * 4 + 1] = uint8_t(h[i] >> 16);
                    out[i * 4 + 2] = uint8_t(h[i] >> 8);
                    out[i * 4 + 3] = uint8_t(h[i]);
                }
                return out;
            }
        };

        inline std::array<uint8_t, 32> sha256(const uint8_t *data, size_t len)
        {
            Sha256State s;
            s.update(data, len);
            return s.digest();
        }

        inline std::array<uint8_t, 32> hmac_sha256(
            const uint8_t *key, size_t klen,
            const uint8_t *data, size_t dlen)
        {
            std::array<uint8_t, 32> kh{};
            if (klen > 64)
            {
                kh = sha256(key, klen);
                key = kh.data();
                klen = 32;
            }
            uint8_t ipad[64]{}, opad[64]{};
            std::memcpy(ipad, key, klen);
            std::memcpy(opad, key, klen);
            for (int i = 0; i < 64; ++i)
            {
                ipad[i] ^= 0x36;
                opad[i] ^= 0x5C;
            }
            Sha256State inner;
            inner.update(ipad, 64);
            inner.update(data, dlen);
            auto ih = inner.digest();
            Sha256State outer;
            outer.update(opad, 64);
            outer.update(ih.data(), 32);
            return outer.digest();
        }

        inline bool constant_time_equal(const std::array<uint8_t, 32> &a,
                                        const std::array<uint8_t, 32> &b)
        {
            uint8_t diff = 0;
            for (size_t i = 0; i < 32; ++i)
                diff |= (a[i] ^ b[i]);
            return diff == 0;
        }

        inline bool hex_decode(std::string_view hex, std::array<uint8_t, 32> &out)
        {
            if (hex.size() != 64)
                return false;
            for (size_t i = 0; i < 32; ++i)
            {
                auto nib = [](char c) -> int
                {
                    if (c >= '0' && c <= '9')
                        return c - '0';
                    if (c >= 'a' && c <= 'f')
                        return c - 'a' + 10;
                    if (c >= 'A' && c <= 'F')
                        return c - 'A' + 10;
                    return -1;
                };
                int hi = nib(hex[i * 2]), lo = nib(hex[i * 2 + 1]);
                if (hi < 0 || lo < 0)
                    return false;
                out[i] = uint8_t((hi << 4) | lo);
            }
            return true;
        }

        // Base64url decode (no padding required — Telegram omits '=')
        inline std::optional<std::vector<uint8_t>> base64url_decode(std::string_view in)
        {
            static constexpr int8_t T[256] = {
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                62,
                -1,
                -1,
                52,
                53,
                54,
                55,
                56,
                57,
                58,
                59,
                60,
                61,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                -1,
                0,
                1,
                2,
                3,
                4,
                5,
                6,
                7,
                8,
                9,
                10,
                11,
                12,
                13,
                14,
                15,
                16,
                17,
                18,
                19,
                20,
                21,
                22,
                23,
                24,
                25,
                -1,
                -1,
                -1,
                -1,
                63,
                -1,
                26,
                27,
                28,
                29,
                30,
                31,
                32,
                33,
                34,
                35,
                36,
                37,
                38,
                39,
                40,
                41,
                42,
                43,
                44,
                45,
                46,
                47,
                48,
                49,
                50,
                51,
                -1,
                -1,
                -1,
                -1,
                -1,
            };
            std::vector<uint8_t> out;
            out.reserve((in.size() * 3) / 4 + 1);
            uint32_t acc = 0;
            int bits = 0;
            for (unsigned char c : in)
            {
                if (c == '=')
                    break;
                int v = (c < 256) ? T[c] : -1;
                if (v < 0)
                    return std::nullopt;
                acc = (acc << 6) | uint32_t(v);
                bits += 6;
                if (bits >= 8)
                {
                    bits -= 8;
                    out.push_back(uint8_t(acc >> bits));
                    acc &= (1 << bits) - 1;
                }
            }
            return out;
        }

        // URL-decode a query-string value (%XX and '+' → ' ')
        inline std::string url_decode(std::string_view s)
        {
            std::string out;
            out.reserve(s.size());
            for (size_t i = 0; i < s.size();)
            {
                if (s[i] == '%' && i + 2 < s.size())
                {
                    auto hex = [](char c) -> int
                    {
                        if (c >= '0' && c <= '9')
                            return c - '0';
                        if (c >= 'a' && c <= 'f')
                            return c - 'a' + 10;
                        if (c >= 'A' && c <= 'F')
                            return c - 'A' + 10;
                        return -1;
                    };
                    int hi = hex(s[i + 1]), lo = hex(s[i + 2]);
                    if (hi >= 0 && lo >= 0)
                    {
                        out += (char)((hi << 4) | lo);
                        i += 3;
                        continue;
                    }
                }
                if (s[i] == '+')
                    out += ' ';
                else
                    out += s[i];
                ++i;
            }
            return out;
        }

        // Parse "key=value&key=value" — preserves order, no duplicate merging
        inline std::vector<std::pair<std::string, std::string>>
        parse_qsl(std::string_view qs)
        {
            std::vector<std::pair<std::string, std::string>> result;
            while (!qs.empty())
            {
                auto amp = qs.find('&');
                auto part = (amp == std::string_view::npos) ? qs : qs.substr(0, amp);
                if (amp != std::string_view::npos)
                    qs = qs.substr(amp + 1);
                else
                    qs = {};
                if (part.empty())
                    continue;
                auto eq = part.find('=');
                std::string key = url_decode(eq == std::string_view::npos ? part : part.substr(0, eq));
                std::string val = eq == std::string_view::npos ? std::string{} : url_decode(part.substr(eq + 1));
                result.emplace_back(std::move(key), std::move(val));
            }
            return result;
        }

    } // namespace detail

    // =========================================================================
    //  WebAppInitData
    //
    //  Parsed representation of Telegram Web App init data.
    //  Returned by parse_webapp_init_data() and safe_parse_webapp_init_data().
    // =========================================================================

    struct WebAppInitData
    {
        std::string query_id;
        std::string hash;
        std::string signature; // present in new Ed25519 flow
        std::string auth_date; // Unix timestamp as string
        std::string start_param;
        std::string chat_type;
        std::string chat_instance;
        std::string can_send_after;
        std::string user_json; // raw JSON string for "user"
        std::string receiver_json;
        std::string chat_json;
        std::unordered_map<std::string, std::string> extra; // unknown keys
    };

    // =========================================================================
    //  parse_webapp_init_data
    //
    //  Parses init_data into a WebAppInitData struct WITHOUT verifying
    //  the signature. Use safe_parse_webapp_init_data() for trusted input.
    // =========================================================================

    inline WebAppInitData parse_webapp_init_data(std::string_view init_data)
    {
        WebAppInitData result;
        for (auto &[k, v] : detail::parse_qsl(init_data))
        {
            if (k == "query_id")
                result.query_id = v;
            else if (k == "hash")
                result.hash = v;
            else if (k == "signature")
                result.signature = v;
            else if (k == "auth_date")
                result.auth_date = v;
            else if (k == "start_param")
                result.start_param = v;
            else if (k == "chat_type")
                result.chat_type = v;
            else if (k == "chat_instance")
                result.chat_instance = v;
            else if (k == "can_send_after")
                result.can_send_after = v;
            else if (k == "user")
                result.user_json = v;
            else if (k == "receiver")
                result.receiver_json = v;
            else if (k == "chat")
                result.chat_json = v;
            else
                result.extra[k] = v;
        }
        return result;
    }

    // =========================================================================
    //  check_webapp_signature  (HMAC-SHA256 / bot-token based)
    //
    //  Telegram Web App validation algorithm:
    //    secret_key = HMAC-SHA256(key="WebAppData", msg=bot_token)
    //    data_check_string = sorted key=value pairs (excluding hash), joined by \n
    //    expected = HMAC-SHA256(key=secret_key, msg=data_check_string).hex()
    //    return constant_time_compare(expected, hash)
    //
    //  @param bot_token  Full bot token ("123456:ABC...")
    //  @param init_data  Raw init_data string from Telegram Web App
    //  @return           true if signature is valid
    // =========================================================================

    inline bool check_webapp_signature(std::string_view bot_token,
                                       std::string_view init_data)
    {
        auto pairs = detail::parse_qsl(init_data);

        std::string received_hash;
        std::vector<std::pair<std::string, std::string>> fields;
        fields.reserve(pairs.size());

        for (auto &[k, v] : pairs)
        {
            if (k == "hash")
                received_hash = v;
            else
                fields.emplace_back(k, v);
        }
        if (received_hash.empty())
            return false;

        // Sort alphabetically
        std::sort(fields.begin(), fields.end(),
                  [](const auto &a, const auto &b)
                  { return a.first < b.first; });

        std::string dcs;
        for (size_t i = 0; i < fields.size(); ++i)
        {
            if (i)
                dcs += '\n';
            dcs += fields[i].first + '=' + fields[i].second;
        }

        // secret_key = HMAC-SHA256("WebAppData", bot_token)
        static constexpr uint8_t web_app_data[] = "WebAppData";
        auto secret = detail::hmac_sha256(
            web_app_data, sizeof(web_app_data) - 1,
            reinterpret_cast<const uint8_t *>(bot_token.data()), bot_token.size());

        // expected = HMAC-SHA256(secret_key, data_check_string)
        auto expected = detail::hmac_sha256(
            secret.data(), secret.size(),
            reinterpret_cast<const uint8_t *>(dcs.data()), dcs.size());

        std::array<uint8_t, 32> received{};
        if (!detail::hex_decode(received_hash, received))
            return false;
        return detail::constant_time_equal(expected, received);
    }

    // =========================================================================
    //  check_webapp_signature_ed25519  (Ed25519 / bot-id based, new flow)
    //
    //  For third-party validation without the bot token.
    //  https://core.telegram.org/bots/webapps#validating-data-for-third-party-use
    //
    //  NOTE: Requires a crypto library with Ed25519 support.
    //        This overload is only compiled when COROGRAM_ED25519 is defined
    //        and the include path contains a suitable header.
    //
    //  @param bot_id     Numeric bot ID (extracted from token)
    //  @param init_data  Raw init_data string
    //  @param pub_key    32-byte Ed25519 public key (Telegram's production key by default)
    //  @return           true if signature is valid
    // =========================================================================

#ifdef COROGRAM_ED25519
#include <openssl/evp.h>

    // Telegram production public key (June 2025)
    inline constexpr std::array<uint8_t, 32> TELEGRAM_WEBAPP_PUBKEY = {{
        0xe7,
        0xbf,
        0x03,
        0xa2,
        0xfa,
        0x46,
        0x02,
        0xaf,
        0x45,
        0x80,
        0x70,
        0x3d,
        0x88,
        0xdd,
        0xa5,
        0xbb,
        0x59,
        0xf3,
        0x2e,
        0xd8,
        0xb0,
        0x2a,
        0x56,
        0xc1,
        0x87,
        0xfe,
        0x7d,
        0x34,
        0xca,
        0xed,
        0x24,
        0x2d,
    }};

    inline bool check_webapp_signature_ed25519(
        int64_t bot_id,
        std::string_view init_data,
        const std::array<uint8_t, 32> &pub_key = TELEGRAM_WEBAPP_PUBKEY)
    {
        auto pairs = detail::parse_qsl(init_data);

        std::string signature_b64;
        std::vector<std::pair<std::string, std::string>> fields;
        fields.reserve(pairs.size());

        for (auto &[k, v] : pairs)
        {
            if (k == "signature")
                signature_b64 = v;
            else if (k == "hash")
            {
            } // excluded from Ed25519 check
            else
                fields.emplace_back(k, v);
        }
        if (signature_b64.empty())
            return false;

        auto sig_bytes = detail::base64url_decode(signature_b64);
        if (!sig_bytes || sig_bytes->size() != 64)
            return false;

        // Sort alphabetically
        std::sort(fields.begin(), fields.end(),
                  [](const auto &a, const auto &b)
                  { return a.first < b.first; });

        std::string dcs = std::to_string(bot_id) + ":WebAppData\n";
        for (size_t i = 0; i < fields.size(); ++i)
        {
            if (i)
                dcs += '\n';
            dcs += fields[i].first + '=' + fields[i].second;
        }

        // Verify with OpenSSL EVP (Ed25519)
        EVP_PKEY *pkey = EVP_PKEY_new_raw_public_key(
            EVP_PKEY_ED25519, nullptr, pub_key.data(), pub_key.size());
        if (!pkey)
            return false;

        EVP_MD_CTX *ctx = EVP_MD_CTX_new();
        bool ok = false;
        if (ctx)
        {
            if (EVP_DigestVerifyInit(ctx, nullptr, nullptr, nullptr, pkey) == 1)
            {
                ok = (EVP_DigestVerify(
                          ctx,
                          sig_bytes->data(), sig_bytes->size(),
                          reinterpret_cast<const uint8_t *>(dcs.data()), dcs.size()) == 1);
            }
            EVP_MD_CTX_free(ctx);
        }
        EVP_PKEY_free(pkey);
        return ok;
    }
#endif // COROGRAM_ED25519

    // =========================================================================
    //  safe_parse_webapp_init_data
    //
    //  Validates init_data and returns parsed struct.
    //  Throws std::invalid_argument if signature is invalid.
    // =========================================================================

    inline WebAppInitData safe_parse_webapp_init_data(
        std::string_view bot_token,
        std::string_view init_data)
    {
        if (!check_webapp_signature(bot_token, init_data))
            throw std::invalid_argument("Invalid WebApp init data signature");
        return parse_webapp_init_data(init_data);
    }
} // namespace webappauth
} // namespace corogram