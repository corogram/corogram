#pragma once
#include <algorithm>
#include <atomic>
#include <chrono>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#include <trantor/net/EventLoopThread.h>
#include <drogon/HttpClient.h>
#include <drogon/drogon.h>
#include <nlohmann/json.hpp>

#include <corogram/network/BaseNetwork.hpp>
#include <corogram/network/Exceptions.hpp>
#include <corogram/network/RequestMiddleware.hpp>
#include <corogram/Types.hpp>
#include <corogram/utils/Utf8Sanitize.hpp>

using json = nlohmann::json;

namespace corogram
{

    /**
     * @brief Drogon-backed HTTP session for the Telegram Bot API.
     *
     * ## Connection model
     * Each `HttpClient` instance owns exactly one persistent TCP connection
     * (HTTP/1.1 keep-alive). Concurrent throughput per connection is controlled
     * by HTTP pipelining (RFC 7230 §6.3.2):
     *
     *   depth = 0  →  one in-flight request at a time (Drogon default)
     *   depth = N  →  up to N+1 requests in-flight simultaneously
     *
     * Requests that exceed the pipeline window are queued in `requestsBuffer_`
     * inside `HttpClientImpl` and dispatched automatically as responses arrive.
     * `requestsBufferSize()` reflects that queue, but it blocks the calling
     * thread via `promise/future` when called outside the event-loop thread —
     * unsafe from a coroutine. Round-robin distribution is therefore used
     * instead of least-loaded selection.
     *
     * ## Pool sizing
     * Total concurrent capacity = pool_size × (pipeline_depth + 1).
     * The defaults (pool=4, depth=32) yield 132 simultaneous requests, which
     * is sufficient for thousands of bots sharing a single session in webhook
     * mode. Increase pool_size only if profiling shows all connections
     * saturated; each additional client opens a new TLS handshake.
     *
     * ## Long-poll isolation
     * getUpdates runs on a dedicated `EventLoopThread` so a 30-second long-poll
     * never occupies a slot in the API pool and never blocks the main loop.
     * In webhook mode the polling client is never created.
     */
    class DrogonSession final : public INetwork
    {
    public:
        /**
         * @param timeout_sec    Per-request timeout in seconds.
         * @param pool_size      Number of persistent API connections.
         * @param pipeline_depth Pipelining depth per connection (RFC 7230).
         */
        explicit DrogonSession(double timeout_sec = 30.0)
            : timeout_sec_(timeout_sec), pool_size_(1), pipeline_depth_(0)
        {
            polling_loop_thread_ = std::make_shared<trantor::EventLoopThread>();
            polling_loop_thread_->run();

            // getUpdates için ayrı loop — long-poll API pool'u bloklamasın
            polling_client_ = drogon::HttpClient::newHttpClient(
                "https://api.telegram.org",
                polling_loop_thread_->getLoop(),
                /*useOldTLS=*/false,
                /*validateCert=*/true);

            // API client — HTTP/2 ile tek connection yeterli, pool gereksiz
            auto c = drogon::HttpClient::newHttpClient(
                "https://api.telegram.org",
                drogon::app().getLoop(),
                /*useOldTLS=*/false,
                /*validateCert=*/true);
            api_pool_.push_back(std::move(c));
        }
        ~DrogonSession() override = default;

        RequestMiddlewareManager &middleware() override { return middleware_; }

        /**
         * @brief POST a JSON payload through the middleware chain.
         *
         * @param path  Full API path, e.g. "/bot<token>/sendMessage".
         * @param body  Serialised JSON string.
         * @return      Raw JSON response body.
         */
        drogon::Task<std::string> sendRequest(
            const std::string &path,
            const std::string &body) override
        {
            RequestContext ctx;
            ctx.path = path;
            ctx.body = body;
            ctx.content_type = "application/json";
            ctx.method_name = _method_name(path);
            co_return co_await _dispatch(std::move(ctx));
        }

        /**
         * @brief POST a multipart/form-data payload through the middleware chain.
         *
         * URL-sourced `InputFile` entries are downloaded first; their bytes are
         * then embedded in the multipart body alongside the JSON scalar fields.
         *
         * @param path          Full API path.
         * @param json_payload  Serialised JSON string of non-file parameters.
         * @param uploads       File attachments.
         * @return              Raw JSON response body.
         */
        drogon::Task<std::string> uploadFiles(
            const std::string &path,
            const std::string &json_payload,
            const std::vector<UploadEntry> &uploads) override
        {
            const std::string boundary = "----TGBotBoundary7f3a9b";

            std::vector<std::tuple<std::string, Bytes, std::string>> resolved;
            resolved.reserve(uploads.size());

            for (const auto &entry : uploads)
            {
                const auto &file = entry.file;
                Bytes data;
                if (file->source == InputFile::Source::Url)
                {
                    auto dl = co_await downloadFile(file->url);
                    data = std::move(dl.data);
                }
                else
                {
                    data = file->bytes();
                }
                resolved.emplace_back(entry.field_name, std::move(data), file->filename);
            }

            RequestContext ctx;
            ctx.path = path;
            ctx.body = _build_multipart(boundary, json_payload, resolved);
            ctx.content_type = "multipart/form-data; boundary=" + boundary;
            ctx.method_name = _method_name(path);
            co_return co_await _dispatch(std::move(ctx));
        }

        /**
         * @brief Download an arbitrary URL outside the API middleware chain.
         *
         * A one-shot `HttpClient` is created for the target host so that file
         * downloads do not occupy a slot in the shared API pool.
         *
         * @param url  Absolute HTTPS URL.
         * @return     `DownloadResult` containing raw bytes, MIME type, and filename.
         * @throws NetworkException  on connection failure or non-200 status.
         * @throws MediaException    on non-200 HTTP status.
         */
        drogon::Task<DownloadResult> downloadFile(const std::string &url) override
        {
            auto [host, path] = _parse_url(url);

            auto client = drogon::HttpClient::newHttpClient(
                "https://" + host,
                drogon::app().getLoop(),
                /*useOldTLS=*/false,
                /*validateCert=*/false);

            auto req = drogon::HttpRequest::newHttpRequest();
            req->setMethod(drogon::Get);
            req->setPath(path);

            auto resp = co_await client->sendRequestCoro(req, timeout_sec_);

            if (!resp)
                throw NetworkException("File download failed: " + url);
            if (resp->statusCode() != drogon::k200OK)
                throw MediaException("HTTP " + std::to_string(resp->statusCode()) + " — " + url);

            DownloadResult result;
            const std::string body_str(resp->body());
            result.data = Bytes(body_str.begin(), body_str.end());
            result.mime_type = resp->getHeader("content-type");

            const std::string cd = resp->getHeader("content-disposition");
            if (auto pos = cd.find("filename="); pos != std::string::npos)
            {
                result.filename = cd.substr(pos + 9);
                result.filename.erase(
                    std::remove(result.filename.begin(), result.filename.end(), '"'),
                    result.filename.end());
            }

            co_return result;
        }

    private:
        drogon::Task<std::string> _dispatch(RequestContext ctx)
        {
            MakeRequestFn raw = [this](RequestContext c) -> drogon::Task<std::string>
            {
                co_return co_await _raw_post(std::move(c));
            };

            if (middleware_.empty())
                co_return co_await raw(std::move(ctx));

            co_return co_await middleware_.wrap(std::move(raw))(std::move(ctx));
        }

        /**
         * @brief Execute the raw HTTP POST and return the response body.
         *
         * Client selection:
         *   - getUpdates  → dedicated polling client on its own event-loop thread.
         *   - everything  → round-robin over `api_pool_`.
         *
         * `requestsBufferSize()` is intentionally not used for load-based
         * selection: it acquires a `promise/future` lock when called from outside
         * the client's event-loop thread, which would block the coroutine scheduler.
         * Round-robin distributes load uniformly across connections; the pipelining
         * queue inside each `HttpClientImpl` absorbs burst traffic automatically.
         *
         * @throws TelegramRetryAfter  on HTTP 429.
         * @throws NetworkException    on connection failure or null response.
         */
        drogon::Task<std::string> _raw_post(RequestContext ctx)
        {
            const bool is_polling = (ctx.method_name == "getUpdates");

            drogon::HttpClientPtr &client =
                is_polling
                    ? polling_client_
                    : api_pool_[api_pool_idx_.fetch_add(1, std::memory_order_relaxed) % static_cast<size_t>(pool_size_)];

            auto req = drogon::HttpRequest::newHttpRequest();
            req->setMethod(drogon::Post);
            req->setPath(ctx.path);
            req->setContentTypeCode(drogon::CT_NONE);
            req->addHeader("Content-Type", ctx.content_type);
            req->setBody(ctx.body);

            const auto t0 = std::chrono::steady_clock::now();
            auto resp = co_await client->sendRequestCoro(req, timeout_sec_);
            const auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                                std::chrono::steady_clock::now() - t0)
                                .count();

            if (!resp)
                throw NetworkException("Request failed: " + ctx.path);
            if (resp->statusCode() == drogon::k429TooManyRequests)
                throw TelegramRetryAfter(1, "FloodWait on " + ctx.method_name);

            co_return std::string(resp->body());
        }

        // ── helpers ───────────────────────────────────────────────────────────────

        /// Extracts the bare method name from a full API path.
        /// "/bot<token>/sendMessage" → "sendMessage"
        static std::string _method_name(const std::string &path)
        {
            const auto slash = path.rfind('/');
            return slash == std::string::npos ? path : path.substr(slash + 1);
        }

        /// Splits an absolute URL into (host, path).
        static std::pair<std::string, std::string> _parse_url(const std::string &url)
        {
            const size_t proto = url.find("://");
            if (proto == std::string::npos)
                throw NetworkException("Invalid URL: " + url);

            const size_t host_start = proto + 3;
            const size_t slash = url.find('/', host_start);

            if (slash == std::string::npos)
                return {url.substr(host_start), "/"};

            return {url.substr(host_start, slash - host_start), url.substr(slash)};
        }

        /**
         * @brief Serialise JSON scalar fields and binary file parts into a
         *        multipart/form-data body.
         *
         * JSON values whose string representation begins with "attach://" are
         * skipped — they are back-references to named file parts already present
         * in `files`.
         */
        static std::string _build_multipart(
            const std::string &boundary,
            const std::string &json_payload,
            const std::vector<std::tuple<std::string, Bytes, std::string>> &files)
        {
            json j;
            try
            {
                j = json::parse(json_payload);
            }
            catch (...)
            {
            }

            std::ostringstream oss;
            const std::string sep = "--" + boundary + "\r\n";

            for (auto &[key, val] : j.items())
            {
                if (val.is_string() && val.get<std::string>().rfind("attach://", 0) == 0)
                    continue;

                oss << sep
                    << "Content-Disposition: form-data; name=\"" << key << "\"\r\n\r\n"
                    << (val.is_string() ? val.get<std::string>() : val.dump())
                    << "\r\n";
            }

            for (const auto &[field_name, data, filename] : files)
            {
                oss << sep
                    << "Content-Disposition: form-data; name=\""
                    << field_name << "\"; filename=\"" << filename << "\"\r\n"
                    << "Content-Type: application/octet-stream\r\n\r\n";
                oss.write(reinterpret_cast<const char *>(data.data()),
                          static_cast<std::streamsize>(data.size()));
                oss << "\r\n";
            }

            oss << "--" << boundary << "--\r\n";
            return oss.str();
        }

        // ── members ───────────────────────────────────────────────────────────────

        double timeout_sec_;
        int pool_size_;
        size_t pipeline_depth_;

        std::shared_ptr<trantor::EventLoopThread> polling_loop_thread_;
        drogon::HttpClientPtr polling_client_;

        std::vector<drogon::HttpClientPtr> api_pool_;
        std::atomic<size_t> api_pool_idx_{0};

        RequestMiddlewareManager middleware_;
    };

    /**
     * @brief Construct a shared `DrogonSession`.
     *
     * The returned instance is safe to share across any number of `Bot` objects.
     *
     * @param timeout_sec    Per-request timeout in seconds (default: 30).
     */
    inline std::shared_ptr<DrogonSession> make_network(
        double timeout_sec = 30.0)
    {
        return std::make_shared<DrogonSession>(timeout_sec);
    }

} // namespace corogram