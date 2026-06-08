// include/core/ErrorObserver.hpp
#pragma once
#include <functional>
#include <vector>

#include <drogon/drogon.h>

#include <corogram/core/Context.hpp>
#include <corogram/core/ErrorEvent.hpp>

namespace corogram
{

    // Handler type — takes ErrorEvent instead of Update, returns bool
    // (true = handled, stops further propagation)
    using ErrorHandlerFn = std::function<drogon::Task<bool>(const ErrorEvent &, Context &) > ;

    // =========================================================================
    //  ErrorObserver
    //
    //  Holds error handlers registered on the Dispatcher.
    //  Separate from Observer — receives ErrorEvent, not Update.
    //  Filter support is intentionally omitted.
    // =========================================================================

    class ErrorObserver
    {
        std::vector<ErrorHandlerFn> handlers_;

    public:
        void register_handler(ErrorHandlerFn fn)
        {
            handlers_.push_back(std::move(fn));
        }

        bool empty() const noexcept { return handlers_.empty(); }

        /**
         * @brief Runs handlers in registration order until one returns true.
         *
         * @return true if any handler claimed the error, false otherwise
         */
        drogon::Task<bool> trigger(const ErrorEvent &ev, Context &ctx)
        {
            for (auto &handler : handlers_)
            {
                if (co_await handler(ev, ctx))
                    co_return true;
            }
            co_return false;
        }
    };

} // namespace corogram