// include/core/Middleware.hpp
#pragma once
#include <any>
#include <functional>
#include <stdexcept>
#include <vector>

#include <drogon/drogon.h>

#include <corogram/core/Context.hpp>
#include <corogram/Types.hpp>

namespace corogram
{

    // =========================================================================
    //  Control flow exceptions
    // =========================================================================

    /// Skips the current handler and passes control to the next one.
    /// Caught inside Observer.
    struct SkipHandler : std::exception
    {
        const char *what() const noexcept override { return "SkipHandler"; }
    };

    /// Cancels the entire handler chain — no further handlers run.
    /// Caught at the Dispatcher level.
    struct CancelHandler : std::exception
    {
        const char *what() const noexcept override { return "CancelHandler"; }
    };

    // =========================================================================
    //  Sentinel types
    //
    //  Used as return values from middleware and handlers instead of
    //  std::any(true) / std::any(false) to preserve type safety.
    //
    //  Usage:
    //    co_return corogram::Handled{};    // update was handled — stop the chain
    //    co_return corogram::Unhandled{};  // filter did not match — try next handler
    // =========================================================================

    struct Handled
    {
    }; ///< Update was handled — chain stops here.
    struct Unhandled
    {
    }; ///< Update was not handled — next handler is tried.

    inline bool is_handled(const std::any &result) noexcept
    {
        return result.type() == typeid(Handled);
    }

    inline bool is_unhandled(const std::any &result) noexcept
    {
        return !result.has_value() || result.type() == typeid(Unhandled);
    }

    // =========================================================================
    //  Core types
    // =========================================================================

    /// Calls the next layer in the middleware chain.
    using NextFn = std::function<drogon::Task<std::any>(const Update &, Context &) > ;

    /// Middleware function type: (next, update, ctx) → any
    using MiddlewareFn = std::function<drogon::Task<std::any>(NextFn, const Update &, Context &) > ;

    // =========================================================================
    //  BaseMiddleware — base class for class-based middleware
    //
    //  Usage:
    //    class MyMiddleware : public corogram::BaseMiddleware {
    //    public:
    //        drogon::Task<std::any> operator()(
    //            NextFn next, const Update& upd, Context& ctx) override
    //        {
    //            // before
    //            auto result = co_await next(upd, ctx);
    //            // after
    //            co_return result;
    //        }
    //    };
    //
    //    dp.middleware(std::make_shared<MyMiddleware>());
    // =========================================================================

    class BaseMiddleware
    {
    public:
        virtual ~BaseMiddleware() = default;

        virtual drogon::Task<std::any> operator()(
            NextFn next, const Update &upd, Context &ctx) = 0;

        /// Converts this middleware to a MiddlewareFn using a raw this pointer.
        /// Safe only when the middleware outlives all uses of the returned function.
        MiddlewareFn as_fn()
        {
            return [this](NextFn next, const Update &upd, Context &ctx)
                       -> drogon::Task<std::any>
            {
                co_return co_await (*this)(std::move(next), upd, ctx);
            };
        }

        /// Creates a MiddlewareFn that shares ownership of the middleware.
        static MiddlewareFn make(std::shared_ptr<BaseMiddleware> mw)
        {
            return [mw](NextFn next, const Update &upd, Context &ctx)
                       -> drogon::Task<std::any>
            {
                co_return co_await (*mw)(std::move(next), upd, ctx);
            };
        }
    };

    // =========================================================================
    //  build_chain
    //
    //  Wraps inner with the full middleware chain.
    //  middlewares[0] is the outermost layer; inner is the actual handler.
    // =========================================================================

    inline NextFn build_chain(
        const std::vector<MiddlewareFn> &middlewares,
        NextFn inner)
    {
        NextFn chain = std::move(inner);
        for (auto it = middlewares.rbegin(); it != middlewares.rend(); ++it)
        {
            const auto &mw = *it;
            auto current = chain;
            chain = [mw, current](const Update &upd, Context &ctx)
                -> drogon::Task<std::any>
            {
                co_return co_await mw(current, upd, ctx);
            };
        }
        return chain;
    }

} // namespace corogram