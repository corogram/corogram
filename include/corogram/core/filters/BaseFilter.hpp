// include/core/filters/BaseFilter.hpp
#pragma once
#include <functional>
#include <memory>

#include <drogon/drogon.h>

#include <corogram/Types.hpp>
#include <corogram/core/Context.hpp>

namespace corogram
{

    // FilterFn is defined here as the single source of truth.
    // MagicFilter.hpp and other headers must include this file rather than
    // redeclaring it.
    using FilterFn = std::function<drogon::Task<bool>(const Update &, Context &)>;

    // =========================================================================
    //  BaseFilter
    //
    //  Base class for all filters. Subclass and implement check().
    //  For heap-allocated filters that need safe shared_ptr lifetime,
    //  derive from SharedFilter<Derived> instead.
    //
    //  Usage (class-based filter):
    //
    //    class IsAdmin : public corogram::SharedFilter<IsAdmin> {
    //    public:
    //        explicit IsAdmin(int64_t admin_id) : admin_id_(admin_id) {}
    //
    //        drogon::Task<bool> check(const corogram::Update& upd, corogram::Context&) override {
    //            if (upd.message && upd.message->from)
    //                co_return upd.message->from->id == admin_id_;
    //            co_return false;
    //        }
    //    private:
    //        int64_t admin_id_;
    //    };
    //
    //  Adding to an observer:
    //    router.message().filter(std::make_shared<IsAdmin>(123456));
    //
    //  Adding to a router (applies to all observers):
    //    router.filter(std::make_shared<IsAdmin>(123456));
    //
    //  Via include_router:
    //    dp.include_router(admin_router, { std::make_shared<IsAdmin>(ADMIN_ID) });
    //
    //  As a handler filter:
    //    dp.message().register_handler(handler, { IsAdmin(ADMIN_ID).as_fn() });
    //
    //  Composition (&&, ||, !):
    //    auto f = IsAdmin(ID) && corogram::F::private_chat();
    //    auto g = IsAdmin(ID) || IsAdmin(ID2);
    //    auto h = !IsAdmin(ID);
    // =========================================================================

    class BaseFilter
    {
    public:
        virtual ~BaseFilter() = default;

        /// Subclasses implement only this method.
        virtual drogon::Task<bool> check(const Update &upd, Context &ctx) = 0;

        /**
         * @brief Converts this filter to a FilterFn using a raw this pointer.
         *
         * Safe only when the filter outlives all uses of the returned function.
         * Prefer make_fn(shared_ptr) or SharedFilter<Derived>::as_fn() for
         * heap-allocated filters.
         */
        FilterFn as_fn()
        {
            return [this](const Update &upd, Context &ctx) -> drogon::Task<bool>
            {
                co_return co_await this->check(upd, ctx);
            };
        }

        /**
         * @brief Creates a FilterFn that shares ownership of the filter.
         *
         * Use this when the filter is heap-allocated and the lifetime of the
         * returned FilterFn may exceed the original shared_ptr's scope.
         *
         * @param f Shared pointer to a BaseFilter instance
         * @return FilterFn that keeps f alive
         */
        static FilterFn make_fn(std::shared_ptr<BaseFilter> f)
        {
            return [f](const Update &upd, Context &ctx) -> drogon::Task<bool>
            {
                co_return co_await f->check(upd, ctx);
            };
        }

        // ── Composition operators ─────────────────────────────────────────────

        /// Both filters must return true.
        friend FilterFn operator&&(std::shared_ptr<BaseFilter> a,
                                   std::shared_ptr<BaseFilter> b)
        {
            return [a, b](const Update &upd, Context &ctx) -> drogon::Task<bool>
            {
                if (!co_await a->check(upd, ctx))
                    co_return false;
                co_return co_await b->check(upd, ctx);
            };
        }

        /// At least one filter must return true.
        friend FilterFn operator||(std::shared_ptr<BaseFilter> a,
                                   std::shared_ptr<BaseFilter> b)
        {
            return [a, b](const Update &upd, Context &ctx) -> drogon::Task<bool>
            {
                if (co_await a->check(upd, ctx))
                    co_return true;
                co_return co_await b->check(upd, ctx);
            };
        }

        friend FilterFn operator&&(std::shared_ptr<BaseFilter> a, FilterFn b)
        {
            return [a, b](const Update &upd, Context &ctx) -> drogon::Task<bool>
            {
                if (!co_await a->check(upd, ctx))
                    co_return false;
                co_return co_await b(upd, ctx);
            };
        }

        friend FilterFn operator&&(FilterFn a, std::shared_ptr<BaseFilter> b)
        {
            return [a, b](const Update &upd, Context &ctx) -> drogon::Task<bool>
            {
                if (!co_await a(upd, ctx))
                    co_return false;
                co_return co_await b->check(upd, ctx);
            };
        }

        friend FilterFn operator||(std::shared_ptr<BaseFilter> a, FilterFn b)
        {
            return [a, b](const Update &upd, Context &ctx) -> drogon::Task<bool>
            {
                if (co_await a->check(upd, ctx))
                    co_return true;
                co_return co_await b(upd, ctx);
            };
        }

        friend FilterFn operator||(FilterFn a, std::shared_ptr<BaseFilter> b)
        {
            return [a, b](const Update &upd, Context &ctx) -> drogon::Task<bool>
            {
                if (co_await a(upd, ctx))
                    co_return true;
                co_return co_await b->check(upd, ctx);
            };
        }

        /// Negates the filter result.
        friend FilterFn operator!(std::shared_ptr<BaseFilter> a)
        {
            return [a](const Update &upd, Context &ctx) -> drogon::Task<bool>
            {
                co_return !co_await a->check(upd, ctx);
            };
        }
    };

    // =========================================================================
    //  SharedFilter<Derived>
    //
    //  Mixin for heap-allocated filters. Inheriting from this instead of
    //  BaseFilter directly makes as_fn() capture a shared_ptr to self,
    //  guaranteeing that the filter stays alive as long as the FilterFn does.
    //
    //  Usage:
    //    class IsAdmin : public corogram::SharedFilter<IsAdmin> { ... };
    //    auto f = std::make_shared<IsAdmin>(ADMIN_ID);
    //    router.message().filter(f);
    // =========================================================================

    template <typename Derived>
    class SharedFilter : public BaseFilter,
                         public std::enable_shared_from_this<Derived>
    {
    public:
        /**
         * @brief Returns a FilterFn that shares ownership of this filter.
         *
         * Overrides BaseFilter::as_fn() to capture a shared_ptr instead of
         * a raw pointer, preventing use-after-free when the original
         * shared_ptr goes out of scope.
         */
        FilterFn as_fn()
        {
            auto self = this->shared_from_this();
            return [self](const Update &upd, Context &ctx) -> drogon::Task<bool>
            {
                co_return co_await self->check(upd, ctx);
            };
        }
    };

} // namespace corogram