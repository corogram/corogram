#pragma once

#include <cctype>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include <corogram/Types.hpp>
#include <corogram/Methods.hpp>
#include <corogram/network/BaseNetwork.hpp>
#include <corogram/network/Exceptions.hpp>

using json = nlohmann::json;

namespace corogram
{

    // ─────────────────────────────────────────────────────────────────────────────
    //  Bot
    //
    //  Thin wrapper around corogram::API.
    //  Intentionally decoupled from Dispatcher, FSM, and Middleware Router —
    //  this class only owns the token, network session, and raw API calls.
    //
    //  Constructor:
    //    Bot(token, session)
    //      token   : Telegram bot token — format is validated on construction;
    //                throws TokenValidationError if invalid.
    //      session : std::shared_ptr<INetwork>  — DrogonNetwork, MockNetwork, etc.
    //                The same session may be shared across multiple Bot instances.
    //
    //  Polling and on() are delegated to Router/Dispatcher.
    // ─────────────────────────────────────────────────────────────────────────────
    class Bot
    {
    public:
        /**
         * @brief Constructs a Bot with the given token and network session.
         *
         * @param token    Telegram bot token (validated on construction)
         * @param session  Network backend to use for all API calls
         * @throws corogram::TokenValidationError if the token format is invalid
         */
        explicit Bot(std::string token, std::shared_ptr<INetwork> session)
            : token_(std::move(token)), session_(std::move(session)), api_(session_, token_)
        {
            validate_token(token_);
        }

        const std::string &token() const noexcept { return token_; }
        std::shared_ptr<INetwork> session() const noexcept { return session_; }
        corogram::API &api() noexcept { return api_; }
        const corogram::API &api() const noexcept { return api_; }

        const corogram::API *operator->() const { return &api_; }
        corogram::API *operator->() { return &api_; }

        /** @brief Returns the numeric bot ID extracted from the token. */
        int64_t id() const
        {
            const auto colon = token_.find(':');
            if (colon == std::string::npos)
                return 0;
            try
            {
                return std::stoll(token_.substr(0, colon));
            }
            catch (...)
            {
                return 0;
            }
        }

        /**
         * @brief Returns the bot's User object, cached after the first call.
         *
         * The first call makes a getMe() network request; subsequent calls
         * return the cached result.
         *
         * @throws corogram::ApiException
         * @throws corogram::NetworkException
         */
        drogon::Task<std::shared_ptr<corogram::User>> me()
        {
            if (!me_cache_)
                me_cache_ = co_await api_.getMe();
            co_return me_cache_;
        }

        /** @brief Clears the cached getMe() result (e.g. after a token change). */
        void reset_me() noexcept { me_cache_.reset(); }

        /** @brief Equality is based on token identity, matching aiogram's __eq__ logic. */
        bool operator==(const Bot &other) const noexcept
        {
            return token_ == other.token_;
        }
        bool operator!=(const Bot &other) const noexcept { return !(*this == other); }

    private:
        /**
         * @brief Validates the token format: "<bot_id>:<hash>"
         *
         * Rules:
         *   - bot_id : one or more digits
         *   - ":"    : separator
         *   - hash   : at least 35 characters, only [A-Za-z0-9_-]
         *
         * @throws corogram::TokenValidationError if any rule is violated
         */
        static void validate_token(const std::string &token)
        {
            const auto colon = token.find(':');
            if (colon == std::string::npos || colon == 0)
                throw corogram::TokenValidationError(token);

            for (size_t i = 0; i < colon; ++i)
            {
                if (!std::isdigit(static_cast<unsigned char>(token[i])))
                    throw corogram::TokenValidationError(token);
            }

            const std::string hash_part = token.substr(colon + 1);
            if (hash_part.size() < 35)
                throw corogram::TokenValidationError(token);
            for (char c : hash_part)
            {
                if (!std::isalnum(static_cast<unsigned char>(c)) && c != '-' && c != '_')
                    throw corogram::TokenValidationError(token);
            }
        }

        std::string token_;                  ///< Bot token
        std::shared_ptr<INetwork> session_;  ///< Shared network session
        corogram::API api_;                        ///< Generated raw API wrapper
        std::shared_ptr<corogram::User> me_cache_; ///< Cached result of getMe()
    };

} // namespace corogram