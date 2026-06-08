// include/network/RequestMiddleware.hpp
#pragma once

#ifndef NOMINMAX
#define NOMINMAX
#endif

#include <algorithm>
#include <chrono>
#include <functional>
#include <random>
#include <string>
#include <vector>

#include <drogon/drogon.h>

#include <corogram/network/Exceptions.hpp>
#include <corogram/Logger.hpp>

namespace corogram
{

    // =========================================================================
    //  RequestContext — metadata carried through every API call
    //
    //  Passed to MakeRequestFn and all middleware in the chain.
    //  method_name holds the bare Telegram method name ("sendMessage", etc.)
    // =========================================================================

    struct RequestContext
    {
        std::string method_name;  // Telegram API method name ("sendMessage", etc.)
        std::string path;         // Full URL path ("/bot<token>/sendMessage")
        std::string body;         // JSON body
        std::string content_type; // "application/json" or "multipart/..."
        int attempt = 0;          // Retry attempt index (set by retry middleware)
    };

    // =========================================================================
    //  Type aliases
    //
    //  MakeRequestFn      — the actual HTTP function (DrogonSession::_raw_post)
    //  RequestMiddlewareFn — (next, ctx) → Task<string>
    //                        next is either the next middleware or MakeRequestFn
    // =========================================================================

    using MakeRequestFn = std::function<drogon::Task<std::string>(RequestContext)>;

    using RequestMiddlewareFn = std::function<
        drogon::Task<std::string>(MakeRequestFn, RequestContext)>;

    // =========================================================================
    //  BaseRequestMiddleware — base class for class-based middleware
    //
    //  Usage:
    //    class MyMiddleware : public corogram::BaseRequestMiddleware {
    //    public:
    //        drogon::Task<std::string> operator()(
    //            MakeRequestFn next, RequestContext ctx) override
    //        {
    //            // before
    //            auto result = co_await next(ctx);
    //            // after
    //            co_return result;
    //        }
    //    };
    //    session->middleware().add(std::make_shared<MyMiddleware>());
    // =========================================================================

    class BaseRequestMiddleware
    {
    public:
        virtual ~BaseRequestMiddleware() = default;

        virtual drogon::Task<std::string> operator()(
            MakeRequestFn next, RequestContext ctx) = 0;

        RequestMiddlewareFn as_fn()
        {
            return [this](MakeRequestFn next, RequestContext ctx)
                       -> drogon::Task<std::string>
            {
                co_return co_await (*this)(std::move(next), std::move(ctx));
            };
        }

        static RequestMiddlewareFn make(std::shared_ptr<BaseRequestMiddleware> mw)
        {
            return [mw](MakeRequestFn next, RequestContext ctx)
                       -> drogon::Task<std::string>
            {
                co_return co_await (*mw)(std::move(next), std::move(ctx));
            };
        }
    };

    // =========================================================================
    //  RequestMiddlewareManager
    //
    //  Stores middleware and builds the execution chain.
    //
    //  Usage:
    //    session->middleware().add(fn);
    //    session->middleware().add(std::make_shared<MyMiddleware>());
    // =========================================================================

    class RequestMiddlewareManager
    {
    public:
        void add(RequestMiddlewareFn fn)
        {
            middlewares_.push_back(std::move(fn));
        }

        void add(std::shared_ptr<BaseRequestMiddleware> mw)
        {
            middlewares_.push_back(BaseRequestMiddleware::make(std::move(mw)));
        }

        std::size_t size() const noexcept { return middlewares_.size(); }
        bool empty() const noexcept { return middlewares_.empty(); }

        /**
         * @brief Wraps inner with the full middleware chain.
         *
         * The outermost middleware runs first. Chain is built by iterating
         * in reverse so that middlewares_[0] is the first to execute.
         *
         * @param inner The core request function to wrap
         * @return A MakeRequestFn representing the full chain
         */
        MakeRequestFn wrap(MakeRequestFn inner) const
        {
            MakeRequestFn chain = std::move(inner);
            for (auto it = middlewares_.rbegin(); it != middlewares_.rend(); ++it)
            {
                const auto &mw = *it;
                auto current = chain;
                chain = [mw, current](RequestContext ctx) -> drogon::Task<std::string>
                {
                    co_return co_await mw(current, std::move(ctx));
                };
            }
            return chain;
        }

    private:
        std::vector<RequestMiddlewareFn> middlewares_;
    };

    // =========================================================================
    //  Built-in middleware: RequestLogging
    //
    //  Logs each API call and its duration via loggers::network.
    //
    //  Usage:
    //    session->middleware().add(corogram::make_request_logging());
    //
    //    // Skip specific methods:
    //    session->middleware().add(corogram::make_request_logging({"getUpdates"}));
    // =========================================================================

    inline RequestMiddlewareFn make_request_logging(
        std::vector<std::string> ignore = {})
    {
        return [ignore = std::move(ignore)](MakeRequestFn next, RequestContext ctx)
                   -> drogon::Task<std::string>
        {
            bool should_log = ignore.empty() ||
                              std::find(ignore.begin(), ignore.end(), ctx.method_name) == ignore.end();

            if (should_log)
            {
                std::string msg = "→ " + ctx.method_name;
                if (ctx.attempt > 0)
                    msg += " (retry #" + std::to_string(ctx.attempt) + ")";
                loggers::network.debug(msg);
            }

            auto t0 = std::chrono::steady_clock::now();
            auto result = co_await next(ctx);
            auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(
                          std::chrono::steady_clock::now() - t0)
                          .count();

            if (should_log)
                loggers::network.debug("← " + ctx.method_name +
                                       " (" + std::to_string(ms) + "ms)");

            co_return result;
        };
    }

    // =========================================================================
    //  Built-in middleware: RetryMiddleware
    //
    //  Automatically retries on FloodWait and transient network errors
    //  using exponential backoff.
    //
    //  Usage:
    //    session->middleware().add(corogram::make_retry_middleware());
    //
    //    // Custom config:
    //    session->middleware().add(corogram::make_retry_middleware({
    //        .max_retries    = 5,
    //        .base_delay_ms  = 500,
    //        .backoff_factor = 2.0,
    //    }));
    // =========================================================================

    // =========================================================================
    //  BackoffConfig / Backoff
    //
    //  Mirrors aiogram's BackoffConfig + Backoff but in C++.
    //
    //  next() returns the delay to sleep, then advances the internal state:
    //    delay[0] = min_delay
    //    delay[n] = clamp(delay[n-1] * factor + gaussian(0, jitter), min, max)
    //
    //  jitter is a *standard-deviation* (in seconds), matching aiogram's
    //  normalvariate(mu, sigma) call.  Uses std::normal_distribution so
    //  the result can go slightly below min_delay on the first step;
    //  we clamp to [min_delay, max_delay] to keep it sane.
    // =========================================================================

    struct BackoffConfig
    {
        double min_delay = 1.0; // seconds
        double max_delay = 5.0; // seconds
        double factor = 1.3;
        double jitter = 0.1; // std-dev in seconds (aiogram default)
    };

    class Backoff
    {
    public:
        explicit Backoff(BackoffConfig cfg = {})
            : cfg_(cfg), next_delay_(cfg.min_delay), current_delay_(0.0), counter_(0), rng_(std::random_device{}())
        {
        }

        // Returns delay in ms for the current step, then advances state.
        // First call always returns min_delay (+ jitter), NOT zero.
        std::chrono::milliseconds next()
        {
            current_delay_ = next_delay_;
            ++counter_;

            // advance: clamp(prev * factor + gaussian_noise, min, max)
            std::normal_distribution<double> dist(0.0, cfg_.jitter);
            double raw = current_delay_ * cfg_.factor + dist(rng_);
            next_delay_ = std::clamp(raw, cfg_.min_delay, cfg_.max_delay);

            return std::chrono::milliseconds(
                static_cast<int64_t>(current_delay_ * 1000.0));
        }

        void reset()
        {
            current_delay_ = 0.0;
            next_delay_ = cfg_.min_delay;
            counter_ = 0;
        }

        int counter() const noexcept { return counter_; }
        double next_delay_s() const noexcept { return next_delay_; }
        double current_delay_s() const noexcept { return current_delay_; }

    private:
        BackoffConfig cfg_;
        double next_delay_;
        double current_delay_;
        int counter_;
        std::mt19937 rng_;
    };

    // =========================================================================
    //  RetryConfig / make_retry_middleware
    //
    //  Retry behaviour:
    //    • TelegramRetryAfter  — always sleep exactly retry_after seconds
    //                            (Telegram tells us how long; ignore backoff)
    //    • NetworkException    — exponential backoff via Backoff (shared across
    //                            retries so the delay actually grows each time)
    //    • anything else       — rethrown immediately, no retry
    //
    //  Bug fixed: previously NetworkException backoff recalculated factor from
    //  scratch on every attempt using a local loop, which meant attempt 0 and
    //  attempt 1 both used base_delay_ms * 1.0.  Now a single Backoff instance
    //  persists across the retry loop so state accumulates correctly.
    // =========================================================================

    struct RetryConfig
    {
        int max_retries = 3;
        BackoffConfig backoff = {}; // min=1s, max=5s, factor=1.3, jitter=0.1s
    };

    inline RequestMiddlewareFn make_retry_middleware(RetryConfig cfg = {})
    {
        return [cfg](MakeRequestFn next, RequestContext ctx)
                   -> drogon::Task<std::string>
        {
            auto *loop = trantor::EventLoop::getEventLoopOfCurrentThread();

            // One Backoff instance lives for the entire retry sequence so the
            // delay accumulates: 1s → 1.3s → 1.69s → … up to max_delay.
            Backoff backoff(cfg.backoff);

            for (int attempt = 0; attempt <= cfg.max_retries; ++attempt)
            {
                ctx.attempt = attempt;

                std::exception_ptr eptr;
                std::string result;

                // co_await cannot be used inside a catch block (C++ standard).
                try
                {
                    result = co_await next(ctx);
                    co_return result;
                }
                catch (...)
                {
                    eptr = std::current_exception();
                }

                if (attempt >= cfg.max_retries)
                    std::rethrow_exception(eptr);

                // Determine delay and log — outside any catch block.
                std::chrono::milliseconds delay_ms{0};
                bool should_retry = false;

                try
                {
                    std::rethrow_exception(eptr);
                }
                catch (const TelegramRetryAfter &e)
                {
                    // Telegram says exactly how long to wait — respect it.
                    // Reset backoff so the next NetworkException sequence
                    // starts fresh (unrelated failure mode).
                    delay_ms = std::chrono::milliseconds(e.retry_after() * 1000);
                    backoff.reset();
                    should_retry = true;
                    loggers::network.warning(
                        "FloodWait " + std::to_string(e.retry_after()) +
                        "s — " + ctx.method_name +
                        " (attempt " + std::to_string(attempt + 1) +
                        "/" + std::to_string(cfg.max_retries) + ")");
                }
                catch (const NetworkException &)
                {
                    // Accumulated backoff — delay grows each retry.
                    delay_ms = backoff.next();
                    should_retry = true;
                    loggers::network.warning(
                        "NetworkError — " + ctx.method_name +
                        " backing off " + std::to_string(delay_ms.count()) + "ms" +
                        " (attempt " + std::to_string(attempt + 1) +
                        "/" + std::to_string(cfg.max_retries) + ")");
                }
                catch (...)
                {
                    // Non-retryable error (TelegramBadRequest, etc.) — rethrow now.
                    std::rethrow_exception(eptr);
                }

                if (!should_retry)
                    std::rethrow_exception(eptr);

                co_await drogon::sleepCoro(loop, delay_ms);
            }

            // Unreachable — the loop rethrows on the final attempt.
            throw NetworkException("Max retries exceeded: " + ctx.method_name);
        };
    }

} // namespace corogram