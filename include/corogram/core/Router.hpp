// include/core/Router.hpp
#pragma once
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <functional>
#include <drogon/drogon.h>
#include <corogram/core/Observer.hpp>
#include <corogram/core/ErrorObserver.hpp>
#include <corogram/core/Context.hpp>
#include <corogram/core/filters/BaseFilter.hpp>
#include <corogram/core/filters/Filters.hpp>
#include <corogram/Types.hpp>

namespace corogram
{

    class Router
    {
    protected:
        std::unordered_map<std::string, Observer> observers_;
        ErrorObserver error_observer_;
        std::vector<std::shared_ptr<Router>> sub_routers_;
        Router *parent_ = nullptr;
        std::vector<FilterFn> self_filters_;

        std::vector<std::function<drogon::Task<void>()>> startup_callbacks_;
        std::vector<std::function<drogon::Task<void>()>> shutdown_callbacks_;

    public:
        Router()
        {
            for (auto &name : {
                     "message", "edited_message", "channel_post",
                     "edited_channel_post", "inline_query",
                     "chosen_inline_result", "callback_query",
                     "shipping_query", "pre_checkout_query",
                     "poll", "poll_answer", "my_chat_member",
                     "chat_member", "chat_join_request",
                     "message_reaction", "message_reaction_count",
                     "chat_boost", "removed_chat_boost",
                     "business_connection", "business_message",
                     "edited_business_message", "deleted_business_messages",
                     "purchased_paid_media", "managed_bot"})
            {
                observers_.emplace(name, Observer{});
            }
        }

        // ── Observer accessors ───────────────────────────────────────────────────
        Observer &message() { return observers_.at("message"); }
        Observer &edited_message() { return observers_.at("edited_message"); }
        Observer &callback_query() { return observers_.at("callback_query"); }
        Observer &inline_query() { return observers_.at("inline_query"); }
        Observer &poll() { return observers_.at("poll"); }
        Observer &poll_answer() { return observers_.at("poll_answer"); }
        Observer &my_chat_member() { return observers_.at("my_chat_member"); }
        Observer &chat_member() { return observers_.at("chat_member"); }
        Observer &chat_join_request() { return observers_.at("chat_join_request"); }
        Observer &chosen_inline_result() { return observers_.at("chosen_inline_result"); }
        Observer &shipping_query() { return observers_.at("shipping_query"); }
        Observer &pre_checkout_query() { return observers_.at("pre_checkout_query"); }
        Observer &chat_boost() { return observers_.at("chat_boost"); }
        Observer &removed_chat_boost() { return observers_.at("removed_chat_boost"); }
        Observer &message_reaction() { return observers_.at("message_reaction"); }
        Observer &message_reaction_count() { return observers_.at("message_reaction_count"); }
        Observer &business_connection() { return observers_.at("business_connection"); }
        Observer &business_message() { return observers_.at("business_message"); }
        Observer &purchased_paid_media() { return observers_.at("purchased_paid_media"); }
        Observer &managed_bot() { return observers_.at("managed_bot"); }
        ErrorObserver &error() { return error_observer_; }

        // ─────────────────────────────────────────────────────────────────────────
        //  chain_head — chain from this router up to the root
        //
        //  Usage:
        //    for (auto* r : router.chain_head()) { ... }
        //  Order: self → parent → grandparent → ... → root
        // ─────────────────────────────────────────────────────────────────────────
        std::vector<const Router *> chain_head() const
        {
            std::vector<const Router *> chain;
            const Router *r = this; // no cast
            while (r)
            {
                chain.push_back(r);
                r = r->parent_;
            }
            return chain;
        }

        // ─────────────────────────────────────────────────────────────────────────
        //  chain_tail — chain from this router down to all sub-routers
        //
        //  Usage:
        //    for (auto* r : router.chain_tail()) { ... }
        //  Order: self, then sub-routers depth-first
        // ─────────────────────────────────────────────────────────────────────────
        std::vector<Router *> chain_tail()
        {
            std::vector<Router *> chain;
            _collect_tail(chain);   // non-const overload çağrılır
            return chain;
        }

        // _collect_tail non-const overload ekle (private'a)
        void _collect_tail(std::vector<Router *> &out)
        {
            out.push_back(this);
            for (auto &sub : sub_routers_)
                sub->_collect_tail(out);
        }

        // ─────────────────────────────────────────────────────────────────────────
        //  filter() — adds a global filter to all observers on this router
        // ─────────────────────────────────────────────────────────────────────────
        void filter(FilterFn f)
        {
            self_filters_.push_back(std::move(f));
            _apply_self_filters_to_observers();
        }
        void filter(std::shared_ptr<BaseFilter> f)
        {
            self_filters_.push_back(BaseFilter::make_fn(f));
            _apply_self_filters_to_observers();
        }
        void filter(Filter f)
        {
            self_filters_.push_back(std::move(f.fn));
            _apply_self_filters_to_observers();
        }

        // ─────────────────────────────────────────────────────────────────────────
        //  include_router — overloads
        // ─────────────────────────────────────────────────────────────────────────
        Router &include_router(std::shared_ptr<Router> router)
        {
            _validate_and_attach(router);
            return *router;
        }

        Router &include_router(std::shared_ptr<Router> router, std::vector<std::shared_ptr<BaseFilter>> filters)
        {
            _validate_and_attach(router);
            for (auto &f : filters)
                router->_inject_filter_to_all_observers(BaseFilter::make_fn(f));
            return *router;
        }

        Router &include_router(std::shared_ptr<Router> router, std::vector<FilterFn> filters)
        {
            _validate_and_attach(router);
            for (auto &f : filters)
                router->_inject_filter_to_all_observers(f);
            return *router;
        }

        Router &include_router(std::shared_ptr<Router> router, std::initializer_list<Filter> filters)
        {
            _validate_and_attach(router);
            for (auto &f : filters)
                router->_inject_filter_to_all_observers(f.fn);
            return *router;
        }

        void include_routers(std::vector<std::shared_ptr<Router>> routers)
        {
            for (auto &r : routers)
                include_router(std::move(r));
        }

        // ─────────────────────────────────────────────────────────────────────────
        //  propagate_event
        //
        //  parent_outer : outer middlewares from the Dispatcher
        //
        //  Collects all inner middlewares up to this observer via
        //  _resolve_inner_middlewares over chain_head, then passes them to
        //  trigger(). This ensures dp.message().middleware(A) →
        //  admin_router.message().middleware(B) → handler executes in order
        //  A then B (root to leaf, same as aiogram).
        // ─────────────────────────────────────────────────────────────────────────
        drogon::Task<bool> propagate_event(
            std::string_view update_type,
            const Update &upd,
            Context &ctx,
            const std::vector<MiddlewareFn> &parent_outer = {})
        {
            auto it = observers_.find(std::string(update_type));
            if (it != observers_.end())
            {
                // Collect inner middlewares from parent routers via chain_head
                auto parent_inner = _resolve_inner_middlewares(std::string(update_type));

                bool handled = co_await it->second.trigger(upd, ctx, parent_outer, parent_inner);
                if (handled)
                    co_return true;
            }

            for (auto &sub : sub_routers_)
            {
                bool handled = co_await sub->propagate_event(update_type, upd, ctx, parent_outer);
                if (handled)
                    co_return true;
            }

            co_return false;
        }

        drogon::Task<bool> propagate_error(const ErrorEvent &ev, Context &ctx)
        {
            bool handled = co_await error_observer_.trigger(ev, ctx);
            if (handled)
                co_return true;
            for (auto &sub : sub_routers_)
                if (co_await sub->propagate_error(ev, ctx))
                    co_return true;
            co_return false;
        }

        // ── Startup / Shutdown ───────────────────────────────────────────────────
        void on_startup(std::function<drogon::Task<void>()> cb) { startup_callbacks_.push_back(std::move(cb)); }
        void on_shutdown(std::function<drogon::Task<void>()> cb) { shutdown_callbacks_.push_back(std::move(cb)); }

        drogon::Task<void> emit_startup()
        {
            for (auto &cb : startup_callbacks_)
                co_await cb();
            for (auto &sub : sub_routers_)
                co_await sub->emit_startup();
        }

        drogon::Task<void> emit_shutdown()
        {
            for (auto &cb : shutdown_callbacks_)
                co_await cb();
            for (auto &sub : sub_routers_)
                co_await sub->emit_shutdown();
        }

    private:
        // ─────────────────────────────────────────────────────────────────────────
        //  _resolve_inner_middlewares — equivalent to aiogram's _resolve_middlewares
        //
        //  Traverses chain_head in reverse (root to this router) and collects
        //  the inner middlewares of each router for the given event type.
        //
        //  Example:
        //    dp.message().middleware(A)           <- root
        //    admin_router.message().middleware(B) <- child
        //    -> result: [A, B]  (root to leaf)
        //    -> execution: A wraps B, B wraps the handler
        // ─────────────────────────────────────────────────────────────────────────
        std::vector<MiddlewareFn> _resolve_inner_middlewares(const std::string &event_name) const
        {
            // chain_head: self → parent → ... → root  →  reverse: root → ... → self
            auto head = chain_head();
            std::reverse(head.begin(), head.end()); // root first

            std::vector<MiddlewareFn> result;
            for (auto *r : head)
            {
                auto obs_it = r->observers_.find(event_name);
                if (obs_it == r->observers_.end())
                    continue;
                const auto &inner = obs_it->second.inner_middlewares();
                result.insert(result.end(), inner.begin(), inner.end());
            }
            // The last element of head is self, whose inner middlewares were
            // just appended. Since trigger() appends its own inner_middlewares_
            // to all_inner itself, we remove self's contribution from parent_inner
            // to avoid double-counting.
            if (!result.empty())
            {
                auto self_it = observers_.find(event_name);
                if (self_it != observers_.end())
                {
                    const auto &self_inner = self_it->second.inner_middlewares();
                    if (result.size() >= self_inner.size())
                    {
                        result.resize(result.size() - self_inner.size());
                    }
                }
            }
            return result;
        }

        void _validate_and_attach(const std::shared_ptr<Router> &router)
        {
            if (!router)
                throw std::runtime_error("include_router: null router");
            if (router.get() == this)
                throw std::runtime_error("include_router: a router cannot include itself");
            if (router->parent_)
                throw std::runtime_error("include_router: router is already attached to another router");

            // Circular reference check — walk the parent chain to the root
            Router *p = this;
            while (p)
            {
                if (p == router.get())
                    throw std::runtime_error("include_router: circular reference detected");
                p = p->parent_;
            }

            router->parent_ = this;
            sub_routers_.push_back(router);

            // Inject the sub-router's self_filters_ into its own observers
            for (auto &f : router->self_filters_)
                router->_inject_filter_to_all_observers(f);
        }

        void _inject_filter_to_all_observers(const FilterFn &f)
        {
            for (auto &[name, obs] : observers_)
                obs.add_router_filter(f);
        }

        void _apply_self_filters_to_observers()
        {
            if (self_filters_.empty())
                return;
            const auto &last = self_filters_.back();
            for (auto &[name, obs] : observers_)
                obs.add_router_filter(last);
        }

        void _collect_tail(std::vector<const Router *> &out) const
        {
            out.push_back(this); // no cast
            for (const auto &sub : sub_routers_)
                sub->_collect_tail(out);
        }
    };

} // namespace corogram