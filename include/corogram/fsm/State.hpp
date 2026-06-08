// include/fsm/State.hpp
#pragma once
#include <string>
#include <string_view>
#include <optional>

namespace corogram::fsm
{
    class State
    {
        std::string value_;

    public:
        explicit State(std::string value) : value_(std::move(value)) {}
        explicit State(std::string_view value) : value_(value) {}
        explicit State(const char *value) : value_(value) {}

        const std::string &value() const noexcept { return value_; }

        bool operator==(const State &other) const noexcept
        {
            return value_ == other.value_;
        }
        bool operator!=(const State &other) const noexcept
        {
            return !(*this == other);
        }

        // Compares against a std::optional<string> returned from storage
        bool matches(const std::optional<std::string> &stored) const noexcept
        {
            return stored.has_value() && stored.value() == value_;
        }
    };

    namespace detail
    {

        // Compiler-specific type name extraction
        template <typename T>
        constexpr std::string_view type_name_sv()
        {
#if defined(_MSC_VER)
            // MSVC: "class corogram::fsm::detail::type_name_sv<struct Form>"
            std::string_view sv = __FUNCSIG__;
            auto start = sv.rfind('<');
            auto end = sv.rfind('>');
            sv = sv.substr(start + 1, end - start - 1);
            // "struct Form" or "class Form" — take the last token
            auto space = sv.rfind(' ');
            if (space != std::string_view::npos)
                sv = sv.substr(space + 1);
            return sv;
#elif defined(__clang__) || defined(__GNUC__)
            // GCC/Clang: "corogram::fsm::detail::type_name_sv() [with T = Form]"
            std::string_view sv = __PRETTY_FUNCTION__;
            auto start = sv.rfind("T = ");
            sv = sv.substr(start + 4);
            auto end = sv.find_first_of(";]");
            sv = sv.substr(0, end);
            auto scope = sv.rfind("::");
            if (scope != std::string_view::npos)
                sv = sv.substr(scope + 2);
            return sv;
#else
            return "UnknownGroup";
#endif
        }

    } // namespace detail

    template <typename Derived>
    class StatesGroup
    {
    public:
        static std::string_view group_name()
        {
            static const std::string name{detail::type_name_sv<Derived>()};
            return name;
        }

        static State state(std::string_view field_name)
        {
            return State{std::string(group_name()) + ":" + std::string(field_name)};
        }
    };

} // namespace corogram::fsm