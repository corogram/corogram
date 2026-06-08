// include/core/Observer.hpp
#pragma once
#include <any>
#include <functional>
#include <vector>

#include <drogon/drogon.h>

#include <corogram/core/Context.hpp>
#include <corogram/core/Middleware.hpp>
#include <corogram/core/filters/BaseFilter.hpp>
#include <corogram/core/filters/Filters.hpp>
#include <corogram/Types.hpp>

namespace corogram
{

    using HandlerFn = std::function<drogon::Task<bool>(const Update &, Context &)>;

    struct HandlerEntry
    {
        HandlerFn handler;
        std::vector<FilterFn> filters;
    };

    // =========================================================================
    //  Observer
    //
    //  Middleware execution order (outermost to innermost):
    //
    //  ┌─ outer_middleware ──────────────────────────────────────────────────┐
    //  │  Always runs — even if filters do not match.                        │
    //  │  dp.message().outer_middleware(rate_limiter);                       │
    //  │                                                                     │
    //  │  ┌─ router_filters + global_filters ──────────────────────────┐   │
    //  │  │  If any filter fails, inner layers are skipped.             │   │
    //  │  │                                                              │   │
    //  │  │  ┌─ inner_middleware (from parent routers + this one) ──┐  │   │
    //  │  │  │  Runs only when all filters pass.                     │  │   │
    //  │  │  │  Inner middlewares are collected from the root router  │  │   │
    //  │  │  │  down to this observer and concatenated.              │  │   │
    //  │  │  │  dp.message().middleware(db_session);                  │  │   │
    //  │  │  │                                                         │  │   │
    //  │  │  │  handler()                                              │  │   │
    //  │  │  └─────────────────────────────────────────────────────┘  │   │
    //  │  └─────────────────────────────────────────────────────────────┘   │
    //  └─────────────────────────────────────────────────────────────────────┘
    //
    //  parent_inner is collected by Router::propagate_event via chain_head
    //  and passed in — users do not provide it directly.
    // =========================================================================

    class Observer
    {
        std::vector<HandlerEntry> handlers_;
        std::vector<MiddlewareFn> outer_middlewares_; // run before filters
        std::vector<MiddlewareFn> inner_middlewares_; // run after filters
        std::vector<FilterFn> global_filters_;
        std::vector<FilterFn> router_filters_;

    public:
        // ── Middleware registration ───────────────────────────────────────────

        void outer_middleware(MiddlewareFn mw)
        {
            outer_middlewares_.push_back(std::move(mw));
        }
        void outer_middleware(std::shared_ptr<BaseMiddleware> mw)
        {
            outer_middlewares_.push_back(BaseMiddleware::make(std::move(mw)));
        }

        void middleware(MiddlewareFn mw)
        {
            inner_middlewares_.push_back(std::move(mw));
        }
        void middleware(std::shared_ptr<BaseMiddleware> mw)
        {
            inner_middlewares_.push_back(BaseMiddleware::make(std::move(mw)));
        }

        // ── Filter registration ───────────────────────────────────────────────

        void filter(FilterFn f) { global_filters_.push_back(std::move(f)); }
        void filter(std::shared_ptr<BaseFilter> f) { global_filters_.push_back(BaseFilter::make_fn(std::move(f))); }
        void filter(Filter f) { global_filters_.push_back(std::move(f.fn)); }

        void add_router_filter(FilterFn f) { router_filters_.push_back(std::move(f)); }
        void add_router_filter(std::shared_ptr<BaseFilter> f)
        {
            router_filters_.push_back(BaseFilter::make_fn(std::move(f)));
        }

        // ── Handler registration ──────────────────────────────────────────────

        void register_handler(HandlerFn fn, std::vector<FilterFn> filters = {})
        {
            handlers_.push_back({std::move(fn), std::move(filters)});
        }

        void register_handler(HandlerFn fn, std::vector<std::shared_ptr<BaseFilter>> filters)
        {
            std::vector<FilterFn> fns;
            for (auto &f : filters)
                fns.push_back(BaseFilter::make_fn(std::move(f)));
            handlers_.push_back({std::move(fn), std::move(fns)});
        }

        void register_handler(HandlerFn fn, std::initializer_list<Filter> filters)
        {
            std::vector<FilterFn> fns;
            for (auto &f : filters)
                fns.push_back(f.fn);
            handlers_.push_back({std::move(fn), std::move(fns)});
        }

        /// Exposes inner_middlewares_ so Router::propagate_event can collect
        /// the full chain from root to this observer.
        const std::vector<MiddlewareFn> &inner_middlewares() const
        {
            return inner_middlewares_;
        }

        // ── Trigger ───────────────────────────────────────────────────────────

        /**
         * @brief Runs the full middleware and handler chain for an update.
         *
         * @param upd          Incoming update
         * @param ctx          Request context
         * @param parent_outer Dispatcher-level outer middlewares (outermost layer)
         * @param parent_inner Inner middlewares collected from root down to this observer
         * @return true if any handler claimed the update
         */
        drogon::Task<bool> trigger(
            const Update &upd,
            Context &ctx,
            const std::vector<MiddlewareFn> &parent_outer = {},
            const std::vector<MiddlewareFn> &parent_inner = {})
        {
            std::vector<MiddlewareFn> all_outer;
            all_outer.insert(all_outer.end(), parent_outer.begin(), parent_outer.end());
            all_outer.insert(all_outer.end(), outer_middlewares_.begin(), outer_middlewares_.end());

            std::vector<MiddlewareFn> all_inner;
            all_inner.insert(all_inner.end(), parent_inner.begin(), parent_inner.end());
            all_inner.insert(all_inner.end(), inner_middlewares_.begin(), inner_middlewares_.end());

            auto filtered_and_handled = [this, all_inner](const Update &upd, Context &ctx)
                -> drogon::Task<std::any>
            {
                for (auto &f : router_filters_)
                    if (!co_await f(upd, ctx))
                        co_return corogram::Unhandled{};
                for (auto &f : global_filters_)
                    if (!co_await f(upd, ctx))
                        co_return corogram::Unhandled{};

                co_return co_await _run_with_inner(upd, ctx, all_inner);
            };

            if (all_outer.empty())
            {
                for (auto &f : router_filters_)
                    if (!co_await f(upd, ctx))
                        co_return false;
                for (auto &f : global_filters_)
                    if (!co_await f(upd, ctx))
                        co_return false;

                auto result = co_await _run_with_inner(upd, ctx, all_inner);
                co_return corogram::is_handled(result);
            }

            auto chain = build_chain(all_outer, NextFn(std::move(filtered_and_handled)));
            auto result = co_await chain(upd, ctx);
            co_return corogram::is_handled(result);
        }

    private:
        drogon::Task<std::any> _run_with_inner(
            const Update &upd,
            Context &ctx,
            const std::vector<MiddlewareFn> &all_inner)
        {
            if (all_inner.empty())
                co_return co_await _run_handlers(upd, ctx);

            NextFn handler_fn = [this](const Update &upd, Context &ctx)
                -> drogon::Task<std::any>
            {
                co_return co_await _run_handlers(upd, ctx);
            };
            co_return co_await build_chain(all_inner, std::move(handler_fn))(upd, ctx);
        }

        drogon::Task<std::any> _run_handlers(const Update &upd, Context &ctx)
        {
            for (auto &entry : handlers_)
            {
                bool pass = true;
                for (auto &f : entry.filters)
                    if (!co_await f(upd, ctx))
                    {
                        pass = false;
                        break;
                    }
                if (!pass)
                    continue;

                if (co_await entry.handler(upd, ctx))
                    co_return corogram::Handled{};
            }
            co_return corogram::Unhandled{};
        }
    };

} // namespace corogram