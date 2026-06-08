#pragma once
#include <stdexcept>
#include <string>

namespace corogram
{

    class Exception : public std::runtime_error
    {
    public:
        explicit Exception(const std::string &msg)
            : std::runtime_error(msg) {}
    };

    // ── Telegram API errors ───────────────────────────────────────────────────

    class TelegramException : public Exception
    {
    public:
        explicit TelegramException(const std::string &msg)
            : Exception("Telegram server says: " + msg) {}
    };

    class TelegramBadRequest : public TelegramException
    {
    public:
        explicit TelegramBadRequest(const std::string &msg)
            : TelegramException(msg) {}
    };

    class TelegramUnauthorizedError : public TelegramException
    {
    public:
        explicit TelegramUnauthorizedError(const std::string &msg)
            : TelegramException(msg) {}
    };

    class TelegramForbiddenError : public TelegramException
    {
    public:
        explicit TelegramForbiddenError(const std::string &msg)
            : TelegramException(msg) {}
    };

    class TelegramNotFound : public TelegramException
    {
    public:
        explicit TelegramNotFound(const std::string &msg)
            : TelegramException(msg) {}
    };

    class TelegramConflictError : public TelegramException
    {
    public:
        explicit TelegramConflictError(const std::string &msg)
            : TelegramException(msg) {}
    };

    class TelegramEntityTooLarge : public TelegramException
    {
    public:
        explicit TelegramEntityTooLarge(const std::string &msg)
            : TelegramException(msg) {}
    };

    class TelegramServerError : public TelegramException
    {
    public:
        explicit TelegramServerError(const std::string &msg)
            : TelegramException(msg) {}
    };

    class RestartingTelegram : public TelegramException
    {
    public:
        explicit RestartingTelegram(const std::string &msg)
            : TelegramException(msg) {}
    };

    class TelegramMigrateToChat : public TelegramException
    {
    public:
        TelegramMigrateToChat(int64_t new_chat_id, const std::string &msg)
            : TelegramException(
                  "Group migrated to supergroup " +
                  std::to_string(new_chat_id) +
                  (msg.empty() ? "" : ": " + msg)),
              migrate_to_chat_id(new_chat_id)
        {
        }

        int64_t migrate_to_chat_id;
    };

    /**
     * @brief Thrown when Telegram returns a 429 Too Many Requests response.
     *
     * retry_after() returns the number of seconds to wait before retrying.
     */
    class TelegramRetryAfter : public TelegramException
    {
    public:
        TelegramRetryAfter(int retry, const std::string &msg)
            : TelegramException(msg), retry_after_(retry) {}

        int retry_after() const noexcept { return retry_after_; }

    private:
        int retry_after_;
    };

    // ── Network errors ────────────────────────────────────────────────────────

    class NetworkException : public Exception
    {
    public:
        explicit NetworkException(const std::string &msg)
            : Exception("[Network] " + msg) {}
    };

    class TimeoutException : public NetworkException
    {
    public:
        explicit TimeoutException(const std::string &endpoint)
            : NetworkException("Timeout: " + endpoint) {}
    };

    class SSLException : public NetworkException
    {
    public:
        explicit SSLException(const std::string &msg)
            : NetworkException("SSL: " + msg) {}
    };

    // ── Other errors ──────────────────────────────────────────────────────────

    class ParseException : public Exception
    {
    public:
        explicit ParseException(const std::string &msg)
            : Exception("[Parse] " + msg) {}
    };

    class TokenValidationError : public Exception
    {
    public:
        explicit TokenValidationError(const std::string &token)
            : Exception("[Token] Invalid token format: '" + token + "'") {}
    };

    class FileException : public Exception
    {
    public:
        explicit FileException(const std::string &path)
            : Exception("[File] Could not open: " + path) {}
    };

    class MediaException : public Exception
    {
    public:
        explicit MediaException(const std::string &msg)
            : Exception("[Media] " + msg) {}
    };

} // namespace corogram