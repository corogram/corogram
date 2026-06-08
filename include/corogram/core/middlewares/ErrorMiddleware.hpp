// include/core/middlewares/ErrorMiddleware.hpp
#pragma once
#include <chrono>

#include <corogram/core/Middleware.hpp>
#include <corogram/core/ErrorEvent.hpp>
#include <corogram/core/Router.hpp>
#include <corogram/network/Exceptions.hpp>
#include <corogram/Logger.hpp>

namespace corogram
{

    // detail helpers are forward-declared before make_error_middleware because
    // MSVC requires prior declaration for functions used inside a lambda body.
    //
    // co_await cannot be used inside a catch block (C++ standard).
    // FloodWait handling is therefore split: catch stores the exception_ptr,
    // then co_await is called outside the catch.

    namespace detail
    {

        /**
         * @brief Calls next() and captures any exception as an exception_ptr.
         *
         * SkipHandler and CancelHandler are rethrown immediately so they
         * bypass error handling and propagate normally up the chain.
         *
         * @return nullptr on success, or the caught exception_ptr on failure
         */
        struct InvokeResult
        {
            std::any value;
            std::exception_ptr eptr;
        };

        inline drogon::Task<InvokeResult> try_invoke_next(
            NextFn &next,
            const Update &upd,
            Context &ctx)
        {
            try
            {
                auto result = co_await next(upd, ctx);
                co_return InvokeResult{std::move(result), nullptr};
            }
            catch (const SkipHandler &)
            {
                throw;
            }
            catch (const CancelHandler &)
            {
                throw;
            }
            catch (...)
            {
                co_return InvokeResult{{}, std::current_exception()};
            }
        }

        /**
         * @brief Extracts the retry_after value (in seconds) from an exception_ptr.
         *
         * Returns 0 if the exception is not a TelegramRetryAfter or if eptr is null.
         */
        inline int extract_retry_after(std::exception_ptr eptr)
        {
            if (!eptr)
                return 0;
            try
            {
                std::rethrow_exception(eptr);
            }
            catch (const TelegramRetryAfter &e)
            {
                return e.retry_after();
            }
            catch (...)
            {
            }
            return 0;
        }

        /// Returns true if the exception is a TelegramRetryAfter.
        inline bool is_flood_or_retry(std::exception_ptr eptr)
        {
            if (!eptr)
                return false;
            try
            {
                std::rethrow_exception(eptr);
            }
            catch (const TelegramRetryAfter &)
            {
                return true;
            }
            catch (...)
            {
            }
            return false;
        }

        /// Returns true if the exception is a TelegramUnauthorizedError.
        inline bool is_unauthorized(std::exception_ptr eptr)
        {
            if (!eptr)
                return false;
            try
            {
                std::rethrow_exception(eptr);
            }
            catch (const TelegramUnauthorizedError &)
            {
                return true;
            }
            catch (...)
            {
            }
            return false;
        }

        /// Returns true if the exception is a TelegramMigrateToChat.
        inline bool is_migration(std::exception_ptr eptr)
        {
            if (!eptr)
                return false;
            try
            {
                std::rethrow_exception(eptr);
            }
            catch (const TelegramMigrateToChat &)
            {
                return true;
            }
            catch (...)
            {
            }
            return false;
        }

        /// Returns the migrate_to_chat_id from a TelegramMigrateToChat exception_ptr, or 0.
        inline int64_t extract_migrate_to_chat_id(std::exception_ptr eptr)
        {
            if (!eptr)
                return 0;
            try
            {
                std::rethrow_exception(eptr);
            }
            catch (const TelegramMigrateToChat &e)
            {
                return e.migrate_to_chat_id;
            }
            catch (...)
            {
            }
            return 0;
        }
        inline bool is_skip_or_cancel(std::exception_ptr eptr)
        {
            if (!eptr)
                return false;
            try
            {
                std::rethrow_exception(eptr);
            }
            catch (const SkipHandler &)
            {
                return true;
            }
            catch (const CancelHandler &)
            {
                return true;
            }
            catch (...)
            {
            }
            return false;
        }

    } // namespace detail

    /**
     * @brief Creates a middleware that handles exceptions from downstream handlers.
     *
     * Processing order:
     *   1. SkipHandler / CancelHandler  — rethrown immediately (not errors)
     *   2. TelegramRetryAfter           — sleeps retry_after seconds, then rethrows
     *   3. TelegramUnauthorizedError    — logged as fatal, then rethrown
     *   4. Everything else              — forwarded to router's error observers;
     *                                     rethrown if unhandled
     *
     * @param router Optional pointer to the Router that holds error observers.
     *               Pass nullptr (default) when no router is available.
     */
    inline MiddlewareFn make_error_middleware(Router *router = nullptr)
    {
        return [router](NextFn next, const Update &upd, Context &ctx)
                   -> drogon::Task<std::any>
        {
            auto inv_ = co_await detail::try_invoke_next(next, upd, ctx);
            auto eptr = inv_.eptr;

            if (!eptr)
                co_return std::move(inv_.value);

            if (detail::is_skip_or_cancel(eptr))
                std::rethrow_exception(eptr);

            // FloodWait — sleep outside the catch block (co_await in catch is ill-formed)
            if (detail::is_flood_or_retry(eptr))
            {
                int secs = detail::extract_retry_after(eptr);
                loggers::middlewares.warning(
                    "FloodWait — retrying after " + std::to_string(secs) + "s");
                co_await drogon::sleepCoro(
                    trantor::EventLoop::getEventLoopOfCurrentThread(),
                    std::chrono::seconds(secs));
                std::rethrow_exception(eptr);
            }

            if (detail::is_migration(eptr))
            {
                int64_t new_id = detail::extract_migrate_to_chat_id(eptr);
                loggers::middlewares.warning(
                    "Chat migrated to supergroup " + std::to_string(new_id) +
                    " — update " + std::to_string(upd.update_id) + " dropped.");
                // Migration is not retriable and not an application error:
                // silently drop the update so the bot stays alive.
                co_return corogram::Handled{};
            }

            if (detail::is_unauthorized(eptr))
            {
                try
                {
                    std::rethrow_exception(eptr);
                }
                catch (const TelegramUnauthorizedError &e)
                {
                    loggers::middlewares.fatal(
                        std::string("Unauthorized: ") + e.what());
                }
                catch (...)
                {
                }
                std::rethrow_exception(eptr);
            }

            if (router)
            {
                ErrorEvent ev{upd, eptr};
                bool handled = co_await router->propagate_error(ev, ctx);
                if (handled)
                    co_return corogram::Handled{};

                loggers::middlewares.error(
                    "Unhandled exception in update " +
                    std::to_string(upd.update_id) + ": " + ev.what());
            }
            else
            {
                loggers::middlewares.error(
                    "Unhandled exception in update " +
                    std::to_string(upd.update_id));
            }

            std::rethrow_exception(eptr);
        };
    }

    /// Overload taking a Router reference — forwards to the pointer overload.
    inline MiddlewareFn make_error_middleware(Router &router)
    {
        return make_error_middleware(&router);
    }

} // namespace corogram