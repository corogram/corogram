#pragma once
#include <memory>
#include <optional>
#include <string>
#include <variant>

#include <nlohmann/json.hpp>
#include <corogram/network/Exceptions.hpp>
#include <corogram/utils/Utf8Sanitize.hpp>

namespace corogram
{

    template <typename T>
    struct Response
    {
        bool ok = false;
        int error_code = 0;
        std::string description;
        std::optional<T> result;

        explicit operator bool() const { return ok && result.has_value(); }
    };

    class BaseApi
    {
    protected:
        /**
         * @brief Parses a raw JSON string into a Response<T>.
         *
         * Sanitizes the raw input for valid UTF-8, then deserializes
         * the Telegram API response. On success, populates result with
         * the appropriate T. On failure, throws the matching exception.
         *
         * @tparam T Expected result type (bool, shared_ptr<X>, vector<...>, etc.)
         * @param raw Raw JSON string returned by the Telegram API
         * @return Response<T> Parsed response object
         *
         * @throws TelegramRetryAfter        HTTP 429
         * @throws TelegramBadRequest        HTTP 400
         * @throws TelegramUnauthorizedError HTTP 401
         * @throws TelegramForbiddenError    HTTP 403
         * @throws TelegramNotFound          HTTP 404
         * @throws TelegramConflictError     HTTP 409
         * @throws TelegramEntityTooLarge    HTTP 413
         * @throws TelegramServerError       HTTP 500
         * @throws RestartingTelegram        HTTP 503
         * @throws TelegramException         All other error codes
         */
        template <typename T>
        static Response<T> parse_response(const std::string &raw)
        {
            auto clean = sanitize_utf8(raw);
            json j = json::parse(clean);

            Response<T> resp;
            resp.ok = j.value("ok", false);
            resp.error_code = j.value("error_code", 0);
            resp.description = j.value("description", "");

            if (resp.ok && j.contains("result") && !j.at("result").is_null())
            {
                if constexpr (std::is_same_v<T, bool>)
                {
                    resp.result = j.at("result").get<bool>();
                }
                else if constexpr (std::is_same_v<T, std::variant<std::shared_ptr<Message>, bool>>)
                {
                    if (j.at("result").is_boolean())
                        resp.result = j.at("result").get<bool>();
                    else
                    {
                        auto msg = std::make_shared<Message>();
                        from_json(j.at("result"), *msg);
                        resp.result = std::move(msg);
                    }
                }
                else if constexpr (
                    requires { typename T::value_type::element_type; } &&
                    requires { std::declval<T>().push_back(std::declval<typename T::value_type>()); })
                {
                    T vec;
                    for (const auto &item : j.at("result"))
                    {
                        auto elem = std::make_shared<typename T::value_type::element_type>();
                        from_json(item, *elem);
                        vec.push_back(std::move(elem));
                    }
                    resp.result = std::move(vec);
                }
                else if constexpr (
                    requires { std::declval<T>().push_back(std::declval<typename T::value_type>()); })
                {
                    T vec;
                    for (const auto &item : j.at("result"))
                        vec.push_back(item.get<typename T::value_type>());
                    resp.result = std::move(vec);
                }
                else if constexpr (requires { typename T::element_type; })
                {
                    auto obj = std::make_shared<typename T::element_type>();
                    from_json(j.at("result"), *obj);
                    resp.result = std::move(obj);
                }
                else
                {
                    resp.result = j.at("result").get<T>();
                }

                return resp;
            }

            if (j.contains("parameters"))
            {
                if (j["parameters"].contains("migrate_to_chat_id"))
                {
                    int64_t new_chat_id = j["parameters"]["migrate_to_chat_id"].get<int64_t>();
                    throw corogram::TelegramMigrateToChat(new_chat_id, resp.description);
                }
                int retry = j["parameters"].value("retry_after", 0);
                if (retry > 0)
                    throw corogram::TelegramRetryAfter(retry, resp.description);
            }

            switch (resp.error_code)
            {
            case 400:
                throw corogram::TelegramBadRequest(resp.description);
            case 401:
                throw corogram::TelegramUnauthorizedError(resp.description);
            case 403:
                throw corogram::TelegramForbiddenError(resp.description);
            case 404:
                throw corogram::TelegramNotFound(resp.description);
            case 409:
                throw corogram::TelegramConflictError(resp.description);
            case 413:
                throw corogram::TelegramEntityTooLarge(resp.description);
            case 429:
                throw corogram::TelegramRetryAfter(0, resp.description);
            case 500:
                throw corogram::TelegramServerError(resp.description);
            case 503:
                throw corogram::RestartingTelegram(resp.description);
            default:
                throw corogram::TelegramException(resp.description);
            }
        }
    };

} // namespace corogram