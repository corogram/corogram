#include <algorithm>
#include <array>
#include <cstring>
#include <ctime>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

/**
 * @brief Helpers for verifying Telegram Login Widget (and Web App) auth data.
 *
 * Algorithm (official Telegram docs):
 *   1. Sort all received fields (except `hash`) as "key=value" strings.
 *   2. Join them with '\n' → data_check_string.
 *   3. secret_key = SHA-256(bot_token).
 *   4. expected   = HMAC-SHA-256(secret_key, data_check_string).hexdigest()
 *   5. Compare expected == received hash (constant-time).
 *
 * @code
 *   bool ok = corogram::auth::check_signature(
 *       "123456:ABC-DEF...",
 *       received_hash,
 *       {{"id","123"},{"first_name","Alice"},{"auth_date","1700000000"}}
 *   );
 * @endcode
 */
namespace corogram {
namespace auth
{

    namespace detail
    {

        // ── Minimal SHA-256 implementation ───────────────────────────────────────────
        // Avoids an OpenSSL/libsodium dependency for a single use-case.
        // Implements FIPS 180-4.

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
                    W[i] = (static_cast<uint32_t>(blk[i * 4]) << 24) |
                           (static_cast<uint32_t>(blk[i * 4 + 1]) << 16) |
                           (static_cast<uint32_t>(blk[i * 4 + 2]) << 8) |
                           static_cast<uint32_t>(blk[i * 4 + 3]);
                for (int i = 16; i < 64; ++i)
                {
                    const uint32_t s0 = rotr(W[i - 15], 7) ^ rotr(W[i - 15], 18) ^ (W[i - 15] >> 3);
                    const uint32_t s1 = rotr(W[i - 2], 17) ^ rotr(W[i - 2], 19) ^ (W[i - 2] >> 10);
                    W[i] = W[i - 16] + s0 + W[i - 7] + s1;
                }

                uint32_t a = h[0], b = h[1], c = h[2], d = h[3],
                         e = h[4], f = h[5], g = h[6], hh = h[7];
                for (int i = 0; i < 64; ++i)
                {
                    const uint32_t S1 = rotr(e, 6) ^ rotr(e, 11) ^ rotr(e, 25);
                    const uint32_t ch = (e & f) ^ (~e & g);
                    const uint32_t t1 = hh + S1 + ch + K[i] + W[i];
                    const uint32_t S0 = rotr(a, 2) ^ rotr(a, 13) ^ rotr(a, 22);
                    const uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
                    const uint32_t t2 = S0 + maj;
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
                bits += static_cast<uint64_t>(len) * 8;
                while (len > 0)
                {
                    const size_t space = 64 - buflen;
                    const size_t take = (len < space) ? len : space;
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
                    buf[buflen++] = static_cast<uint8_t>((bits >> (i * 8)) & 0xFF);
                process_block(buf);

                std::array<uint8_t, 32> out{};
                for (int i = 0; i < 8; ++i)
                {
                    out[i * 4] = static_cast<uint8_t>(h[i] >> 24);
                    out[i * 4 + 1] = static_cast<uint8_t>(h[i] >> 16);
                    out[i * 4 + 2] = static_cast<uint8_t>(h[i] >> 8);
                    out[i * 4 + 3] = static_cast<uint8_t>(h[i]);
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

        // ── Minimal HMAC-SHA-256 ──────────────────────────────────────────────────────

        inline std::array<uint8_t, 32> hmac_sha256(
            const uint8_t *key, size_t key_len,
            const uint8_t *data, size_t data_len)
        {
            std::array<uint8_t, 32> key_hash{};
            if (key_len > 64)
            {
                key_hash = sha256(key, key_len);
                key = key_hash.data();
                key_len = 32;
            }

            uint8_t ipad[64]{}, opad[64]{};
            std::memcpy(ipad, key, key_len);
            std::memcpy(opad, key, key_len);
            for (int i = 0; i < 64; ++i)
            {
                ipad[i] ^= 0x36;
                opad[i] ^= 0x5C;
            }

            Sha256State inner;
            inner.update(ipad, 64);
            inner.update(data, data_len);
            const auto inner_hash = inner.digest();

            Sha256State outer;
            outer.update(opad, 64);
            outer.update(inner_hash.data(), 32);
            return outer.digest();
        }

        /// Constant-time comparison of two byte arrays (prevents timing attacks).
        inline bool constant_time_equal(const std::array<uint8_t, 32> &a,
                                        const std::array<uint8_t, 32> &b)
        {
            uint8_t diff = 0;
            for (size_t i = 0; i < 32; ++i)
                diff |= (a[i] ^ b[i]);
            return diff == 0;
        }

        /// Hex-decode a lowercase 64-char string → 32 bytes.
        /// Returns false if the string is not a valid 64-char hex string.
        inline bool hex_decode(const std::string &hex, std::array<uint8_t, 32> &out)
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
                const int hi = nib(hex[i * 2]);
                const int lo = nib(hex[i * 2 + 1]);
                if (hi < 0 || lo < 0)
                    return false;
                out[i] = static_cast<uint8_t>((hi << 4) | lo);
            }
            return true;
        }

    } // namespace detail

    /**
     * @brief Verifies the HMAC-SHA-256 signature of Telegram Login Widget data.
     *
     * Algorithm:
     *  1. Build data-check-string: sort fields by key, join as "key=value\n…".
     *  2. secret = SHA-256(bot_token).
     *  3. expected = HMAC-SHA-256(secret, data_check_string).
     *  4. Compare expected == received_hash (constant-time).
     *
     * @param token          Bot token (e.g. "123456:ABC-DEF…").
     * @param received_hash  The `hash` field received from Telegram (64 hex chars).
     * @param fields         All other fields received (key → value), without "hash".
     * @return               true if the signature is valid.
     */
    inline bool check_signature(
        const std::string &token,
        const std::string &received_hash,
        const std::vector<std::pair<std::string, std::string>> &fields)
    {
        // 1. Sort fields and build data-check-string
        auto sorted = fields;
        std::sort(sorted.begin(), sorted.end(),
                  [](const auto &a, const auto &b)
                  { return a.first < b.first; });

        std::string check_string;
        for (size_t i = 0; i < sorted.size(); ++i)
        {
            if (i != 0)
                check_string += '\n';
            check_string += sorted[i].first + '=' + sorted[i].second;
        }

        // 2. secret = SHA-256(token)
        const auto secret = detail::sha256(
            reinterpret_cast<const uint8_t *>(token.data()), token.size());

        // 3. HMAC-SHA-256(secret, check_string)
        const auto expected = detail::hmac_sha256(
            secret.data(), secret.size(),
            reinterpret_cast<const uint8_t *>(check_string.data()), check_string.size());

        // 4. Constant-time comparison
        std::array<uint8_t, 32> received{};
        if (!detail::hex_decode(received_hash, received))
            return false;
        return detail::constant_time_equal(expected, received);
    }

    /**
     * @brief Verifies integrity of all data received from the Telegram Login Widget.
     *
     * Extracts the "hash" key from the data map and calls check_signature().
     * Optionally verifies that auth_date is not older than max_age_seconds.
     *
     * @param token           Bot token.
     * @param data            All fields received from Telegram, including "hash".
     * @param max_age_seconds If > 0, reject logins older than this many seconds
     *                        (Telegram recommends 86400 = 24 h). Default: 86400.
     * @return                true if the data is authentic and not expired.
     */
    inline bool check_integrity(
        const std::string &token,
        std::vector<std::pair<std::string, std::string>> data,
        int64_t max_age_seconds = 86400)
    {
        // Extract hash field
        std::string received_hash;
        std::string auth_date_str;
        std::vector<std::pair<std::string, std::string>> fields;
        fields.reserve(data.size());

        for (auto &[k, v] : data)
        {
            if (k == "hash")
                received_hash = std::move(v);
            else
            {
                if (k == "auth_date")
                    auth_date_str = v; // keep a copy before moving
                fields.emplace_back(k, std::move(v));
            }
        }

        if (received_hash.empty())
            return false;

        // Verify auth_date freshness (Telegram requirement)
        if (max_age_seconds > 0)
        {
            if (auth_date_str.empty())
                return false; // auth_date is mandatory

            // std::stoll throws on invalid input; treat that as failure
            int64_t auth_date = 0;
            try
            {
                auth_date = std::stoll(auth_date_str);
            }
            catch (...)
            {
                return false;
            }

            const int64_t now = static_cast<int64_t>(std::time(nullptr));
            if (now - auth_date > max_age_seconds)
                return false; // data is too old
        }

        return check_signature(token, received_hash, fields);
    }

} // namespace auth
} // namespace corogram