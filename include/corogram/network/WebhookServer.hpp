// include/network/WebhookServer.hpp
#pragma once

#include <array>
#include <bitset>
#include <cstdint>
#include <functional>
#include <initializer_list>
#include <memory>
#include <optional>
#include <string>
#include <string_view>
#include <vector>

#include <drogon/drogon.h>
#include <nlohmann/json.hpp>

#include <corogram/Types.hpp>
#include <corogram/utils/Utf8Sanitize.hpp>
#include <corogram/Logger.hpp>

namespace corogram
{

    // =============================================================================
    //  Telegram official IP ranges (as of June 2025)
    //  https://core.telegram.org/bots/webhooks#the-short-version
    // =============================================================================
    namespace detail
    {

        /// Parses a dotted-decimal IPv4 string into a big-endian uint32_t.
        inline uint32_t parse_ipv4(std::string_view s)
        {
            uint32_t result = 0;
            int octet = 0, shift = 24;
            for (char c : s)
            {
                if (c == '.')
                {
                    result |= (static_cast<uint32_t>(octet) << shift);
                    shift -= 8;
                    octet = 0;
                }
                else
                {
                    octet = octet * 10 + (c - '0');
                }
            }
            result |= static_cast<uint32_t>(octet);
            return result;
        }

        struct CidrBlock
        {
            uint32_t network;
            uint32_t mask;

            constexpr bool contains(uint32_t ip) const noexcept
            {
                return (ip & mask) == (network & mask);
            }
        };

        /// Parses "a.b.c.d/prefix" into a CidrBlock.
        inline CidrBlock parse_cidr(std::string_view cidr)
        {
            auto slash = cidr.find('/');
            auto net = parse_ipv4(cidr.substr(0, slash));
            int prefix = std::stoi(std::string(cidr.substr(slash + 1)));
            uint32_t mask = prefix == 0 ? 0u : (~0u << (32 - prefix));
            return {net, mask};
        }

    } // namespace detail

    // =============================================================================
    //  IPFilter
    //
    //  Usage:
    //    // Telegram servers only (default)
    //    auto f = IPFilter::telegram();
    //
    //    // Add custom ranges
    //    IPFilter f;
    //    f.allow_cidr("10.0.0.0/8");
    //    f.allow_ip("192.168.1.1");
    //
    //    // Check
    //    if (!f.check("1.2.3.4")) { /* reject */ }
    // =============================================================================

    class IPFilter
    {
    public:
        IPFilter() = default;

        /// Allows a CIDR range: "149.154.160.0/20"
        void allow_cidr(std::string_view cidr)
        {
            blocks_.push_back(detail::parse_cidr(cidr));
        }

        /// Allows a single IP address: "149.154.167.220"
        void allow_ip(std::string_view ip)
        {
            uint32_t addr = detail::parse_ipv4(ip);
            blocks_.push_back({addr, ~0u});
        }

        /// Convenience overload — accepts a mix of CIDRs and plain IPs.
        void allow(std::initializer_list<std::string_view> cidrs)
        {
            for (auto &c : cidrs)
                (c.find('/') != std::string_view::npos) ? allow_cidr(c) : allow_ip(c);
        }

        /// Returns true if the given IP is covered by any allowed block.
        bool check(std::string_view ip) const noexcept
        {
            uint32_t addr = detail::parse_ipv4(ip);
            for (const auto &b : blocks_)
                if (b.contains(addr))
                    return true;
            return false;
        }

        bool operator()(std::string_view ip) const noexcept { return check(ip); }

        // ── Factory methods ───────────────────────────────────────────────────────

        /// Allows only Telegram's official server ranges.
        /// https://core.telegram.org/bots/webhooks#the-short-version
        static IPFilter telegram()
        {
            IPFilter f;
            f.allow_cidr("149.154.160.0/20");
            f.allow_cidr("91.108.4.0/22");
            return f;
        }

        /// Telegram ranges plus additional custom CIDRs or IPs.
        static IPFilter telegram_plus(std::initializer_list<std::string_view> extra)
        {
            auto f = telegram();
            for (auto &c : extra)
                (c.find('/') != std::string_view::npos) ? f.allow_cidr(c) : f.allow_ip(c);
            return f;
        }

        /// No restrictions — use behind a trusted reverse proxy with secret_token.
        static IPFilter allow_all()
        {
            IPFilter f;
            f.allow_all_ = true;
            return f;
        }

        bool is_allow_all() const noexcept { return allow_all_; }

    private:
        std::vector<detail::CidrBlock> blocks_;
        bool allow_all_ = false;
    };

    // =============================================================================
    //  WebhookConfig
    // =============================================================================

    struct WebhookConfig
    {
        // ── Required ──────────────────────────────────────────────────────────────
        std::string url;               // "https://yourdomain.com/webhook/SECRET"
        std::string path = "/webhook"; // URL path Drogon listens on

        // ── Security ──────────────────────────────────────────────────────────────

        // X-Telegram-Bot-Api-Secret-Token header validation.
        // Leave empty to skip (not recommended for production).
        std::string secret_token = "";

        // IP filter. Default: Telegram's official IP ranges only.
        // Behind a reverse proxy, use allow_all() and rely on secret_token instead.
        IPFilter ip_filter = IPFilter::telegram();

        // Trust the X-Forwarded-For header (set true behind a reverse proxy).
        // When false, only the TCP peer address is used.
        bool trust_forwarded_for = false;

        // ── Network ───────────────────────────────────────────────────────────────
        uint16_t port = 8443;

        // SSL paths — leave empty for plain HTTP (e.g. behind a terminating proxy).
        std::string ssl_cert_path = "";
        std::string ssl_key_path = "";

        // ── setWebhook parameters ─────────────────────────────────────────────────
        int32_t max_connections = 40;
        bool drop_pending = false;
        std::vector<std::string> allowed_updates = {};

        // ── Helpers ───────────────────────────────────────────────────────────────

        /**
         * @brief Throws if the config is insecure for production use.
         *
         * A config is considered insecure when BOTH defences are absent:
         *   - secret_token is empty  (no header validation)
         *   - ip_filter is allow_all (no IP restriction)
         *
         * Either defence alone is sufficient. Call this before start_webhook()
         * if you want a hard failure instead of a runtime warning.
         *
         * @throws std::runtime_error if both secret_token and IP filter are absent
         */
        void validate() const
        {
            if (secret_token.empty() && ip_filter.is_allow_all())
                throw std::runtime_error(
                    "WebhookConfig is insecure: secret_token is empty and "
                    "ip_filter is allow_all. Set at least one.");
        }

        /**
         * @brief Returns true if at least one security layer is active.
         *
         * Either a non-empty secret_token OR a non-allow_all IP filter suffices.
         */
        bool is_secure() const noexcept
        {
            return !secret_token.empty() || !ip_filter.is_allow_all();
        }
    };

    // =============================================================================
    //  WebhookServer
    //
    //  Security layers (in order):
    //    1. IP check    — is the request from a Telegram IP block?
    //    2. Secret token — X-Telegram-Bot-Api-Secret-Token header validation
    //    3. JSON parse  — malformed body → 400
    //    4. Update parse — invalid schema → 400
    //
    //  Constructed by Dispatcher; users typically do not instantiate this directly.
    // =============================================================================

    class WebhookServer
    {
    public:
        using UpdateCallback = std::function<drogon::Task<void>(std::shared_ptr<Update>)>;

        explicit WebhookServer(WebhookConfig cfg, UpdateCallback cb)
            : cfg_(std::move(cfg)), callback_(std::move(cb))
        {
        }

        /// Registers the POST handler with Drogon's router.
        void register_routes()
        {
            const auto &path = cfg_.path;
            const auto &secret = cfg_.secret_token;
            const auto &ip_filter = cfg_.ip_filter;
            const bool trust_xff = cfg_.trust_forwarded_for;
            auto callback = callback_;

            drogon::app().registerHandler(
                path,
                // FIX: Drogon coroutine handlers must take HttpRequestPtr by value
                // (not const ref) and the callback by value (not rvalue ref).
                [secret, ip_filter, trust_xff, callback](
                    drogon::HttpRequestPtr req,
                    std::function<void(const drogon::HttpResponsePtr &)> send)
                    -> drogon::Task<void>
                {
                    // ── 1. IP filter ──────────────────────────────────────────
                    if (!ip_filter.is_allow_all())
                    {
                        std::string peer_ip = _resolve_ip(req, trust_xff);
                        if (!ip_filter.check(peer_ip))
                        {
                            loggers::webhook.warning("Unauthorized IP blocked: " + peer_ip);
                            auto resp = drogon::HttpResponse::newHttpResponse();
                            resp->setStatusCode(drogon::k401Unauthorized);
                            resp->setBody("Unauthorized");
                            send(resp);
                            co_return;
                        }
                    }

                    // ── 2. Secret token ───────────────────────────────────────
                    if (!secret.empty())
                    {
                        auto header = req->getHeader("X-Telegram-Bot-Api-Secret-Token");
                        if (!_secure_compare(header, secret))
                        {
                            loggers::webhook.warning("Invalid secret token");
                            auto resp = drogon::HttpResponse::newHttpResponse();
                            resp->setStatusCode(drogon::k401Unauthorized);
                            resp->setBody("Unauthorized");
                            send(resp);
                            co_return;
                        }
                    }

                    // ── 3. Body check ─────────────────────────────────────────
                    auto body = std::string(req->body());
                    if (body.empty())
                    {
                        auto resp = drogon::HttpResponse::newHttpResponse();
                        resp->setStatusCode(drogon::k400BadRequest);
                        resp->setBody("Empty body");
                        send(resp);
                        co_return;
                    }

                    // ── 4. Parse ──────────────────────────────────────────────
                    std::shared_ptr<Update> upd;
                    try
                    {
                        auto j = nlohmann::json::parse(sanitize_utf8(body));
                        upd = std::make_shared<Update>();
                        from_json(j, *upd);
                    }
                    catch (const nlohmann::json::parse_error &e)
                    {
                        loggers::webhook.error(std::string("JSON parse error: ") + e.what());
                        auto resp = drogon::HttpResponse::newHttpResponse();
                        resp->setStatusCode(drogon::k400BadRequest);
                        resp->setBody("Bad Request");
                        send(resp);
                        co_return;
                    }

                    // ── 5. Respond 200 immediately, then dispatch ─────────────
                    // Telegram will retry if it waits too long for a response.
                    // Sending 200 first prevents spurious retries.
                    {
                        auto resp = drogon::HttpResponse::newHttpResponse();
                        resp->setStatusCode(drogon::k200OK);
                        send(resp);
                    }

                    // ── 6. Dispatch after 200 is sent ─────────────────────────
                    try
                    {
                        co_await callback(upd);
                    }
                    catch (const std::exception &e)
                    {
                        loggers::webhook.exception("Handler error", e);
                    }
                },
                {drogon::Post});

            if (secret.empty())
            {
                loggers::webhook.warning(
                    "Webhook secret_token is not set — endpoint is open to anyone. "
                    "Set WebhookConfig::secret_token for production.");
            }
            loggers::webhook.info("Route registered: POST " + path);
        }

        /// Configures Drogon's listener (port, SSL, thread count).
        void configure_app() const
        {
            auto &app = drogon::app();

            if (!cfg_.ssl_cert_path.empty() && !cfg_.ssl_key_path.empty())
            {
                app.addListener("0.0.0.0", cfg_.port, true,
                                cfg_.ssl_cert_path, cfg_.ssl_key_path);
                loggers::webhook.info("HTTPS listening on port " + std::to_string(cfg_.port));
            }
            else
            {
                app.addListener("0.0.0.0", cfg_.port);
                loggers::webhook.info("HTTP listening on port " +
                                      std::to_string(cfg_.port) + " (assuming reverse proxy)");
            }

            app.setThreadNum(4);
        }

        const WebhookConfig &config() const { return cfg_; }

    private:
        /**
         * @brief Resolves the client IP from the request.
         *
         * When trust_xff is true, takes the leftmost (client) IP from
         * X-Forwarded-For, which may contain a proxy chain:
         *   "client_ip, proxy1_ip, proxy2_ip"
         * Falls back to the TCP peer address if the header is absent.
         *
         * @param req        Incoming HTTP request
         * @param trust_xff  Whether to trust X-Forwarded-For
         * @return Resolved client IP string
         */
        static std::string _resolve_ip(const drogon::HttpRequestPtr &req,
                                       bool trust_xff)
        {
            if (trust_xff)
            {
                auto xff = req->getHeader("X-Forwarded-For");
                if (!xff.empty())
                {
                    auto comma = xff.find(',');
                    auto ip = (comma == std::string::npos)
                                  ? xff
                                  : xff.substr(0, comma);
                    auto start = ip.find_first_not_of(' ');
                    return (start == std::string::npos) ? ip : ip.substr(start);
                }
            }
            return req->getPeerAddr().toIp();
        }

        /**
         * @brief Constant-time string comparison for secret token validation.
         *
         * A standard == comparison is vulnerable to timing attacks: the early
         * exit on the first mismatched byte leaks information that allows
         * token recovery character by character.
         *
         * This implementation always iterates the full length of both strings.
         * The length mismatch branch also performs a dummy XOR loop to avoid
         * leaking length information through execution time.
         *
         * @param a First string (e.g. value from request header)
         * @param b Second string (e.g. expected secret token)
         * @return true if a and b are identical
         */
        static bool _secure_compare(std::string_view a, std::string_view b) noexcept
        {
            if (a.size() != b.size())
            {
                volatile uint8_t dummy = 0;
                for (char c : a)
                    dummy ^= static_cast<uint8_t>(c);
                for (char c : b)
                    dummy ^= static_cast<uint8_t>(c);
                (void)dummy;
                return false;
            }
            volatile uint8_t diff = 0;
            for (size_t i = 0; i < a.size(); ++i)
                diff |= static_cast<uint8_t>(a[i]) ^ static_cast<uint8_t>(b[i]);
            return diff == 0;
        }

        WebhookConfig cfg_;
        UpdateCallback callback_;
    };

} // namespace corogram