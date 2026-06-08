// include/corogram/utils/Link.hpp
#pragma once

/**
 * @file    Link.hpp
 * @brief   Telegram URL / deep-link builder helpers.
 *
 * C++ port of aiogram's link.py.
 * All functions return std::string URLs; no network calls are made.
 *
 * Quick-start:
 * @code
 *   using namespace corogram::links;
 *
 *   auto user_url  = create_tg_link("user", {{"id", "123456789"}});
 *   auto bot_url   = create_telegram_link({"MyBot"}, {{"start", "ref42"}});
 *   auto group_url = create_channel_bot_link("MyBot", {
 *       .parameter     = "hello",
 *       .invite_users  = true,
 *       .pin_messages  = true,
 *   });
 * @endcode
 */

#include <optional>
#include <string>
#include <string_view>
#include <vector>

namespace corogram
{
    namespace links
    {

        namespace detail
        {

            /**
             * @brief Percent-encodes a single byte value (RFC 3986).
             *
             * Unreserved characters (A-Z a-z 0-9 - _ . ~) are passed through.
             * Everything else is %-encoded as uppercase hex.
             */
            inline std::string url_encode(const std::string &s)
            {
                static constexpr char kHex[] = "0123456789ABCDEF";

                std::string out;
                out.reserve(s.size() * 3); // worst case every byte is encoded
                for (unsigned char c : s)
                {
                    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') ||
                        (c >= '0' && c <= '9') ||
                        c == '-' || c == '_' || c == '.' || c == '~')
                    {
                        out += static_cast<char>(c);
                    }
                    else
                    {
                        out += '%';
                        out += kHex[c >> 4];
                        out += kHex[c & 0x0F];
                    }
                }
                return out;
            }

            /**
             * @brief Builds a query string from key=value pairs.
             *
             * Keys are Telegram-internal ASCII identifiers and are NOT percent-encoded
             * (they never contain special characters).  Values are encoded.
             */
            inline std::string build_query(
                const std::vector<std::pair<std::string, std::string>> &params)
            {
                std::string q;
                for (const auto &[k, v] : params)
                {
                    if (!q.empty())
                        q += '&';
                    // Keys are always safe ASCII — skip encoding overhead
                    q += k;
                    q += '=';
                    q += url_encode(v);
                }
                return q;
            }

            /**
             * @brief Appends path segments and optional query/fragment to a base URL.
             *
             * Mirrors Python's urljoin + urlencode behaviour used by aiogram's
             * _format_url().
             *
             * @param base      Base URL (must be non-empty).
             * @param path      Path segments joined with '/'.
             * @param query     Optional key=value query parameters.
             * @param fragment  Optional URL fragment (after '#').
             */
            inline std::string format_url(
                const std::string &base,
                const std::vector<std::string> &path = {},
                const std::vector<std::pair<std::string, std::string>> &query = {},
                const std::string &fragment = "")
            {
                std::string url = base;

                for (const auto &seg : path)
                {
                    // Guard against empty base or bases that already end with '/'
                    if (!url.empty() && url.back() != '/')
                        url += '/';
                    url += seg;
                }

                if (!query.empty())
                {
                    url += '?';
                    url += build_query(query);
                }

                if (!fragment.empty())
                {
                    url += '#';
                    url += fragment;
                }

                return url;
            }

        } // namespace detail

        // ─────────────────────────────────────────────────────────────────────────────
        //  Public API
        // ─────────────────────────────────────────────────────────────────────────────

        /**
         * @brief Builds a tg:// deep link.
         *
         * @code
         *   create_tg_link("user", {{"id", "123456789"}})
         *   // → "tg://user?id=123456789"
         * @endcode
         *
         * @param link   Deep-link scheme path (e.g. "user", "resolve").
         * @param query  Optional key=value query parameters.
         */
        inline std::string create_tg_link(
            const std::string &link,
            const std::vector<std::pair<std::string, std::string>> &query = {})
        {
            return detail::format_url("tg://" + link, {}, query);
        }

        /**
         * @brief Builds an https://t.me/… link.
         *
         * @code
         *   create_telegram_link({"MyBot"}, {{"start", "ref42"}})
         *   // → "https://t.me/MyBot?start=ref42"
         * @endcode
         *
         * @param path   Path segments joined with '/'.
         * @param query  Optional query parameters.
         */
        inline std::string create_telegram_link(
            const std::vector<std::string> &path = {},
            const std::vector<std::pair<std::string, std::string>> &query = {})
        {
            return detail::format_url("https://t.me", path, query);
        }

        // ─────────────────────────────────────────────────────────────────────────────
        //  Channel / group bot invite link builder
        // ─────────────────────────────────────────────────────────────────────────────

        /**
         * @brief Options for create_channel_bot_link().
         *
         * Mirrors every bool parameter from aiogram's create_channel_bot_link().
         */
        struct ChannelBotLinkOptions
        {
            /** Deep-link start parameter passed as ?startgroup=<parameter>. */
            std::optional<std::string> parameter;

            bool change_info = false;
            bool post_messages = false;
            bool edit_messages = false;
            bool delete_messages = false;
            bool restrict_members = false;
            bool invite_users = false;
            bool pin_messages = false;
            bool promote_members = false;
            bool manage_video_chats = false;
            bool anonymous_admin = false;
            bool manage_chat = false;
        };

        /**
         * @brief Builds a bot-to-channel invite link with optional admin permissions.
         *
         * @code
         *   create_channel_bot_link("MyBot", {
         *       .parameter    = "hello",
         *       .invite_users = true,
         *       .pin_messages = true,
         *   });
         *   // → "https://t.me/MyBot?startgroup=hello&admin=invite_users+pin_messages"
         * @endcode
         *
         * @param username  Bot username (without @).
         * @param opts      Permission flags and optional start parameter.
         */
        inline std::string create_channel_bot_link(
            const std::string &username,
            const ChannelBotLinkOptions &opts = {})
        {
            std::vector<std::pair<std::string, std::string>> query;

            if (opts.parameter.has_value())
                query.emplace_back("startgroup", *opts.parameter);

            std::string admin;
            auto add = [&](bool flag, std::string_view name)
            {
                if (!flag)
                    return;
                if (!admin.empty())
                    admin += '+';
                admin.append(name);
            };

            add(opts.change_info, "change_info");
            add(opts.post_messages, "post_messages");
            add(opts.edit_messages, "edit_messages");
            add(opts.delete_messages, "delete_messages");
            add(opts.restrict_members, "restrict_members");
            add(opts.invite_users, "invite_users");
            add(opts.pin_messages, "pin_messages");
            add(opts.promote_members, "promote_members");
            add(opts.manage_video_chats, "manage_video_chats");
            add(opts.anonymous_admin, "anonymous");
            add(opts.manage_chat, "manage_chat");

            if (!admin.empty())
                query.emplace_back("admin", std::move(admin));

            return create_telegram_link({username}, query);
        }

        // ─────────────────────────────────────────────────────────────────────────────
        //  Convenience: user / chat tg:// links
        // ─────────────────────────────────────────────────────────────────────────────

        /**
         * @brief Returns the tg://user?id=… link for a Telegram user.
         *
         * Mirrors aiogram's User.url when no username is set.
         */
        inline std::string user_tg_link(int64_t user_id)
        {
            return create_tg_link("user", {{"id", std::to_string(user_id)}});
        }

        /**
         * @brief Returns the https://t.me/<username> link for a user/chat.
         *
         * Mirrors aiogram's User.url when a username is available.
         */
        inline std::string username_link(const std::string &username)
        {
            return create_telegram_link({username});
        }

    } // namespace links

    // ─────────────────────────────────────────────────────────────────────────────
    //  Payload  (encode / decode — URL-safe base64url)
    // ─────────────────────────────────────────────────────────────────────────────

    /**
     * @brief Utilities for encoding and decoding Telegram deep-link payloads.
     *
     * Port of aiogram's payload.py.
     *
     * Basic usage:
     * @code
     *   std::string enc = corogram::payload::encode("hello");   // → "aGVsbG8"
     *   std::string dec = corogram::payload::decode(enc);        // → "hello"
     * @endcode
     *
     * Custom encoder/decoder (e.g. AES):
     * @code
     *   auto enc = corogram::payload::encode("hello", [](std::vector<uint8_t> b) {
     *       return aes_encrypt(b); // returns std::vector<uint8_t>
     *   });
     *   auto dec = corogram::payload::decode(enc, [](std::vector<uint8_t> b) {
     *       return aes_decrypt(b);
     *   });
     * @endcode
     */
    namespace payload
    {

        namespace detail
        {

            /// URL-safe base64 alphabet (RFC 4648 §5): A-Z a-z 0-9 - _
            static constexpr char kB64Chars[] =
                "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789-_";

            /// Inverse table: byte → 6-bit value, 0xFF = invalid
            inline uint8_t b64_val(unsigned char c)
            {
                if (c >= 'A' && c <= 'Z')
                    return static_cast<uint8_t>(c - 'A');
                if (c >= 'a' && c <= 'z')
                    return static_cast<uint8_t>(c - 'a' + 26);
                if (c >= '0' && c <= '9')
                    return static_cast<uint8_t>(c - '0' + 52);
                if (c == '-')
                    return 62;
                if (c == '_')
                    return 63;
                return 0xFF; // padding / invalid
            }

            /// Encode raw bytes → URL-safe base64 (no padding).
            inline std::string b64_encode(const std::vector<uint8_t> &in)
            {
                std::string out;
                out.reserve((in.size() + 2) / 3 * 4);

                const size_t full = (in.size() / 3) * 3;
                for (size_t i = 0; i < full; i += 3)
                {
                    const uint32_t v = (static_cast<uint32_t>(in[i]) << 16) | (static_cast<uint32_t>(in[i + 1]) << 8) | static_cast<uint32_t>(in[i + 2]);
                    out += kB64Chars[(v >> 18) & 0x3F];
                    out += kB64Chars[(v >> 12) & 0x3F];
                    out += kB64Chars[(v >> 6) & 0x3F];
                    out += kB64Chars[(v) & 0x3F];
                }
                const size_t rem = in.size() - full;
                if (rem == 1)
                {
                    const uint32_t v = static_cast<uint32_t>(in[full]) << 16;
                    out += kB64Chars[(v >> 18) & 0x3F];
                    out += kB64Chars[(v >> 12) & 0x3F];
                    // no padding
                }
                else if (rem == 2)
                {
                    const uint32_t v = (static_cast<uint32_t>(in[full]) << 16) | (static_cast<uint32_t>(in[full + 1]) << 8);
                    out += kB64Chars[(v >> 18) & 0x3F];
                    out += kB64Chars[(v >> 12) & 0x3F];
                    out += kB64Chars[(v >> 6) & 0x3F];
                    // no padding
                }
                return out;
            }

            /// Decode URL-safe base64 (with or without padding) → raw bytes.
            /// Throws std::invalid_argument on malformed input.
            inline std::vector<uint8_t> b64_decode(std::string s)
            {
                // Re-add stripped padding so length is a multiple of 4.
                const size_t rem = s.size() % 4;
                if (rem != 0)
                    s.append(4 - rem, '=');

                std::vector<uint8_t> out;
                out.reserve(s.size() / 4 * 3);

                for (size_t i = 0; i < s.size(); i += 4)
                {
                    const uint8_t a = b64_val(static_cast<unsigned char>(s[i]));
                    const uint8_t b = b64_val(static_cast<unsigned char>(s[i + 1]));
                    const uint8_t c = (s[i + 2] == '=') ? 0 : b64_val(static_cast<unsigned char>(s[i + 2]));
                    const uint8_t d = (s[i + 3] == '=') ? 0 : b64_val(static_cast<unsigned char>(s[i + 3]));

                    if (a == 0xFF || b == 0xFF)
                        throw std::invalid_argument("corogram::payload::decode: invalid base64 character");

                    const uint32_t v = (static_cast<uint32_t>(a) << 18) | (static_cast<uint32_t>(b) << 12) | (static_cast<uint32_t>(c) << 6) | static_cast<uint32_t>(d);

                    out.push_back(static_cast<uint8_t>(v >> 16));
                    if (s[i + 2] != '=')
                        out.push_back(static_cast<uint8_t>((v >> 8) & 0xFF));
                    if (s[i + 3] != '=')
                        out.push_back(static_cast<uint8_t>(v & 0xFF));
                }
                return out;
            }

        } // namespace detail

        /**
         * @brief Encodes a UTF-8 string to URL-safe base64url (no padding).
         *
         * @param payload  Plain-text payload.
         * @param encoder  Optional transform applied to raw bytes BEFORE base64
         *                 (e.g. AES encryption). Receives and returns raw byte vectors.
         * @return         Base64url-encoded string, safe for use as a Telegram deep-link parameter.
         */
        inline std::string encode(
            const std::string &payload,
            std::function<std::vector<uint8_t>(std::vector<uint8_t>)> encoder = nullptr)
        {
            std::vector<uint8_t> bytes(payload.begin(), payload.end());
            if (encoder)
                bytes = encoder(std::move(bytes));
            return detail::b64_encode(bytes);
        }

        /**
         * @brief Decodes a URL-safe base64url payload back to a UTF-8 string.
         *
         * @param payload  Base64url-encoded string (padding optional).
         * @param decoder  Optional transform applied to raw bytes AFTER base64 decoding
         *                 (e.g. AES decryption).
         * @return         Decoded UTF-8 string.
         * @throws std::invalid_argument  on malformed base64 input.
         */
        inline std::string decode(
            const std::string &payload,
            std::function<std::vector<uint8_t>(std::vector<uint8_t>)> decoder = nullptr)
        {
            std::vector<uint8_t> bytes = detail::b64_decode(payload);
            if (decoder)
                bytes = decoder(std::move(bytes));
            return std::string(bytes.begin(), bytes.end());
        }

    } // namespace payload

    // ─────────────────────────────────────────────────────────────────────────────
    //  Deep links  (create_start_link, create_startgroup_link, …)
    // ─────────────────────────────────────────────────────────────────────────────

    /**
     * @brief Telegram deep-link builders.
     *
     * Port of aiogram's deep_linking.py.
     *
     * @code
     *   using namespace corogram::deep;
     *
     *   // Simple start link
     *   std::string link = create_start("MyBot", "ref42");
     *   // → "https://t.me/MyBot?start=ref42"
     *
     *   // Encoded payload (base64url)
     *   std::string link2 = create_start("MyBot", "hello world", true);
     *   // → "https://t.me/MyBot?start=aGVsbG8gd29ybGQ"
     * @endcode
     */
    namespace deep
    {

        /// Allowed characters in a raw (un-encoded) deep-link payload: A-Z a-z 0-9 - _
        inline bool is_valid_raw_payload(const std::string &payload)
        {
            for (unsigned char c : payload)
            {
                const bool ok = (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9') || c == '-' || c == '_';
                if (!ok)
                    return false;
            }
            return true;
        }

        /// Maximum raw payload length accepted by Telegram (64 characters).
        static constexpr size_t kMaxPayloadLength = 64;

        /**
         * @brief Core deep-link builder (synchronous, bot username supplied by caller).
         *
         * @param username   Bot username (without @).
         * @param link_type  One of: "start", "startgroup", "startapp".
         * @param payload    Arbitrary string data.
         * @param app_name   Optional Mini App name (for "startapp" direct links).
         * @param encode     If true, encode the payload with URL-safe base64url first.
         * @param encoder    Optional custom encoder applied before base64 (e.g. AES).
         * @return           Full https://t.me/… URL.
         * @throws std::invalid_argument  if the (possibly encoded) payload is invalid or too long.
         */
        inline std::string create(
            const std::string &username,
            const std::string &link_type,
            std::string payload,
            const std::string &app_name = "",
            bool encode = false,
            std::function<std::vector<uint8_t>(std::vector<uint8_t>)> encoder = nullptr)
        {
            if (encode || encoder)
                payload = corogram::payload::encode(payload, std::move(encoder));

            if (!is_valid_raw_payload(payload))
                throw std::invalid_argument(
                    "corogram::deep::create: wrong payload — only A-Z, a-z, 0-9, '-' and '_' are allowed. "
                    "Pass encode=true or encode the payload manually.");

            if (payload.size() > kMaxPayloadLength)
                throw std::invalid_argument(
                    "corogram::deep::create: payload must be at most " + std::to_string(kMaxPayloadLength) + " characters long.");

            const std::vector<std::pair<std::string, std::string>> query{{link_type, payload}};

            if (app_name.empty())
                return corogram::links::create_telegram_link({username}, query);
            return corogram::links::create_telegram_link({username, app_name}, query);
        }

        /**
         * @brief Creates a https://t.me/<bot>?start=<payload> link.
         *
         * @param username  Bot username (without @).
         * @param payload   Deep-link payload (max 64 chars; only A-Z a-z 0-9 - _ when raw).
         * @param encode    Set true to auto-encode with base64url.
         * @param encoder   Optional custom byte encoder (applied before base64).
         */
        inline std::string create_start(
            const std::string &username,
            const std::string &payload,
            bool encode = false,
            std::function<std::vector<uint8_t>(std::vector<uint8_t>)> encoder = nullptr)
        {
            return create(username, "start", payload, "", encode, std::move(encoder));
        }

        /**
         * @brief Creates a https://t.me/<bot>?startgroup=<payload> link.
         */
        inline std::string create_startgroup(
            const std::string &username,
            const std::string &payload,
            bool encode = false,
            std::function<std::vector<uint8_t>(std::vector<uint8_t>)> encoder = nullptr)
        {
            return create(username, "startgroup", payload, "", encode, std::move(encoder));
        }

        /**
         * @brief Creates a https://t.me/<bot>?startapp=<payload> or
         *        https://t.me/<bot>/<app>?startapp=<payload> link.
         *
         * @param app_name  Optional: if set, produces a direct mini-app link.
         */
        inline std::string create_startapp(
            const std::string &username,
            const std::string &payload,
            const std::string &app_name = "",
            bool encode = false,
            std::function<std::vector<uint8_t>(std::vector<uint8_t>)> encoder = nullptr)
        {
            return create(username, "startapp", payload, app_name, encode, std::move(encoder));
        }

    } // namespace deep

} // namespace corogram