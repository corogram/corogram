// include/fsm/BaseStorage.hpp
#pragma once
#include <string>
#include <optional>
#include <unordered_map>
#include <drogon/drogon.h>
#include <corogram/fsm/StorageKey.hpp>

namespace corogram::fsm {

    class BaseStorage {
    public:
        virtual ~BaseStorage() = default;
        virtual drogon::Task<std::optional<std::string>> get_field(
            const StorageKey &key,
            std::string_view field)
        {
                // Default: mevcut get_data üzerinden — geriye dönük uyumlu
                auto data = co_await get_data(key);
                auto it = data.find(std::string(field));
                if (it == data.end())
                    co_return std::nullopt;
                co_return it->second;
        }
        virtual drogon::Task<void> set_state(
            const StorageKey& key,
            std::optional<std::string> state   // nullopt = state sil
        ) = 0;

        virtual drogon::Task<std::optional<std::string>> get_state(
            const StorageKey& key
        ) = 0;

        virtual drogon::Task<void> set_data(
            const StorageKey& key,
            std::unordered_map<std::string, std::string>   data
        ) = 0;

        virtual drogon::Task<std::unordered_map<std::string, std::string>> get_data(
            const StorageKey& key
        ) = 0;

        virtual drogon::Task<void> update_data(
            const StorageKey& key,
            std::unordered_map<std::string, std::string> new_values
        ) = 0;

        virtual drogon::Task<void> clear(const StorageKey& key) = 0;

        virtual drogon::Task<void> close() { co_return; }
    };

} // namespace corogram::fsm