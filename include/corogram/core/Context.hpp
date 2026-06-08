// include/core/Context.hpp
#pragma once
#include <any>
#include <stdexcept>
#include <string>
#include <unordered_map>

namespace corogram
{

    class Context
    {
        std::unordered_map<std::string, std::any> data_;

    public:
        template <typename T>
        void set(std::string_view key, T value)
        {
            data_.insert_or_assign(std::string(key), std::any(std::move(value)));
        }


        void set_any(std::string_view key, const std::any &value)
        {
            data_.insert_or_assign(std::string(key), value);
        }

        template <typename T>
        T &get(std::string_view key)
        {
            auto it = data_.find(std::string(key));
            if (it == data_.end())
                throw std::out_of_range("Context key not found: " + std::string(key));
            return std::any_cast<T &>(it->second);
        }

        template <typename T>
        T *get_if(std::string_view key)
        {
            auto it = data_.find(std::string(key));
            if (it == data_.end())
                return nullptr;
            return std::any_cast<T>(&it->second);
        }

        bool has(std::string_view key) const
        {
            return data_.count(std::string(key)) > 0;
        }

        void erase(std::string_view key)
        {
            data_.erase(std::string(key));
        }
    };

} // namespace corogram