// include/fsm/FSMContext.hpp
#pragma once
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>
#include <drogon/drogon.h>
#include <corogram/fsm/BaseStorage.hpp>
#include <corogram/fsm/StorageKey.hpp>

namespace corogram::fsm {

    class FSMContext {
        std::shared_ptr<BaseStorage> storage_;
        StorageKey                   key_;

    public:
        FSMContext(std::shared_ptr<BaseStorage> storage, StorageKey key)
            : storage_(std::move(storage))
            , key_(std::move(key))
        {
        }

        // ── State ────────────────────────────────────────────────────
        drogon::Task<void> set_state(std::optional<std::string> state) {
            co_await storage_->set_state(key_, std::move(state));
        }

        drogon::Task<std::optional<std::string>> get_state() {
            co_return co_await storage_->get_state(key_);
        }

        drogon::Task<void> clear() {
            co_await storage_->clear(key_);
        }

        // ── Data ─────────────────────────────────────────────────────
        drogon::Task<void> set_data(
            std::unordered_map<std::string, std::string> data)
        {
            co_await storage_->set_data(key_, std::move(data));
        }

        drogon::Task<std::unordered_map<std::string, std::string>> get_data() {
            co_return co_await storage_->get_data(key_);
        }

        drogon::Task<void> update_data(
            std::unordered_map<std::string, std::string> values)
        {
            co_await storage_->update_data(key_, std::move(values));
        }

        drogon::Task<std::optional<std::string>> get_value(std::string_view field) {
            co_return co_await storage_->get_field(key_, field);  
        }
    };

} // namespace corogram::fsm