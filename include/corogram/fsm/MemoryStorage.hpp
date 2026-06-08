// include/fsm/MemoryStorage.hpp
#pragma once
#include <unordered_map>
#include <drogon/drogon.h>
#include <corogram/fsm/BaseStorage.hpp>

namespace corogram::fsm
{

    // =============================================================================
    //  MemoryStorage — thread-safe in-process FSM storage
    //
    //  Thread safety strategy: pin every operation to Drogon's main event loop
    //  via trantor::EventLoop::runInLoop(). This guarantees that store_ is always
    //  accessed from exactly one thread, eliminating data races without any mutex.
    //
    //  Why not std::mutex?
    //    Holding a mutex across a coroutine suspension point is undefined behaviour
    //    — the coroutine may resume on a different thread while the mutex is still
    //    "owned" by the original thread, causing deadlock or UB. The event-loop
    //    pinning approach avoids this entirely: the critical section completes
    //    synchronously on the loop thread before co_return.
    //
    //  Performance note:
    //    All operations are O(1) hash-map lookups. The runInLoop() hop adds one
    //    cross-thread wakeup (~microseconds) when called from a non-loop thread,
    //    which is negligible for FSM state operations.
    // =============================================================================

    class MemoryStorage : public BaseStorage
    {
        struct Record
        {
            std::optional<std::string> state;
            std::unordered_map<std::string, std::string> data;
        };

        std::unordered_map<std::string, Record> store_;
        trantor::EventLoop *loop_;

        std::string make_key(const StorageKey &k) const
        {
            return std::to_string(k.bot_id) + ":" + std::to_string(k.chat_id) + ":" + std::to_string(k.user_id);
        }

        // Runs fn() on loop_ and suspends the coroutine until it completes.
        // fn() must be noexcept — any exception would be lost across the thread hop.
        template <typename Fn>
        drogon::Task<void> run_on_loop(Fn fn)
        {
            auto *loop = loop_;
            co_await drogon::switchThreadCoro(loop);
            fn();
            // switchThreadCoro already moved us to loop_ — no need to switch back.
            // Drogon will resume the caller on whichever loop it came from naturally.
        }

    public:
        // Pass the event loop to pin onto. Defaults to Drogon's main loop.
        // For multi-loop setups, pass the specific loop your bots run on.
        explicit MemoryStorage(trantor::EventLoop *loop = nullptr)
            : loop_(loop ? loop : drogon::app().getLoop())
        {
        }
        drogon::Task<std::optional<std::string>> get_field(
            const StorageKey& key,
            std::string_view field) override
        {
            auto k = make_key(key);
            std::string f{field};
            std::optional<std::string> result;
            co_await run_on_loop([&]() noexcept {
                auto it = store_.find(k);
                if (it == store_.end()) return;
                auto fit = it->second.data.find(f);
                if (fit != it->second.data.end())
                    result = fit->second;  // tek string kopyası
            });
            co_return result;
        }
        
        drogon::Task<void> set_state(
            const StorageKey &key,
            std::optional<std::string> state) override
        {
            auto k = make_key(key);
            auto s = std::move(state);
            co_await run_on_loop([&]() noexcept
                                 { store_[k].state = std::move(s); });
        }

        drogon::Task<std::optional<std::string>> get_state(
            const StorageKey &key) override
        {
            auto k = make_key(key);
            std::optional<std::string> result;
            co_await run_on_loop([&]() noexcept
                                 {
            auto it = store_.find(k);
            if (it != store_.end())
                result = it->second.state; });
            co_return result;
        }

        drogon::Task<void> set_data(
            const StorageKey &key,
            std::unordered_map<std::string, std::string> data) override
        {
            auto k = make_key(key);
            co_await run_on_loop([&, d = std::move(data)]() mutable noexcept
                                 { store_[k].data = std::move(d); });
        }

        drogon::Task<std::unordered_map<std::string, std::string>> get_data(
            const StorageKey &key) override
        {
            auto k = make_key(key);
            std::unordered_map<std::string, std::string> result;
            co_await run_on_loop([&]() noexcept
                                 {
            auto it = store_.find(k);
            if (it != store_.end())
                result = it->second.data; });
            co_return result;
        }

        drogon::Task<void> update_data(
            const StorageKey &key,
            std::unordered_map<std::string, std::string> values) override
        {
            auto k = make_key(key);
            co_await run_on_loop([&, v = std::move(values)]() mutable noexcept
                                 {
            auto& record = store_[k];
            for (auto& [fk, fv] : v)
                record.data[fk] = std::move(fv); });
        }

        drogon::Task<void> clear(const StorageKey &key) override
        {
            auto k = make_key(key);
            co_await run_on_loop([&]() noexcept
                                 { store_.erase(k); });
        }
    };

} // namespace corogram::fsm