// include/fsm/StateFilter.hpp
#pragma once
#include <memory>
#include <optional>
#include <string>
#include <variant>
#include <vector>

#include <drogon/drogon.h>

#include <corogram/core/Context.hpp>
#include <corogram/core/filters/BaseFilter.hpp>
#include <corogram/fsm/FSMContext.hpp>
#include <corogram/fsm/State.hpp>
#include <corogram/Types.hpp>

namespace corogram::fsm
{

    // =========================================================================
    //  StateType — the set of things you can pass to StateFilter
    //
    //  StateFilter accepts any mix of:
    //
    //    State            — exact state match:   Form::waiting_name
    //    std::string      — raw value match:     "Form:waiting_name"
    //                       or wildcard "*"       — any active state
    //    std::nullptr_t   — no active state      (nullopt in storage)
    //
    //  A StatesGroup itself is not a runtime value (it has no instances), but
    //  its nested State members carry the "GroupName:field" prefix, so you
    //  can pass them individually or pass the group name as a prefix string.
    //
    //  For group-wide matching use StateFilter::for_group<MyGroup>() below.
    // =========================================================================

    /// A single allowed-state entry.
    using StateEntry = std::variant<
        State,         // exact State object
        std::string,   // raw string ("*" = wildcard)
        std::nullptr_t // no state (nullopt)
        >;

    // =========================================================================
    //  StateInfo
    //
    //  Injected into ctx["state"] when the filter passes.
    //  Gives handlers easy access to the current raw state string.
    //
    //  Usage inside a handler:
    //    if (auto* info = ctx.get_if<corogram::fsm::StateInfo>("state"))
    //        LOG_INFO << "current state: " << info->raw.value_or("none");
    // =========================================================================

    struct StateInfo
    {
        /// The raw string currently stored in FSM, or nullopt if no state.
        std::optional<std::string> raw;

        /// True when there is an active state.
        bool active() const noexcept { return raw.has_value(); }
    };

    // =========================================================================
    //  StateFilter
    //
    //  Class-based filter that:
    //    1. Requires FSMMiddleware to have placed an FSMContext in ctx["fsm"].
    //    2. Fetches the current raw state from storage (async).
    //    3. Matches against the registered StateEntry list.
    //    4. On success, injects a StateInfo into ctx["state"].
    //
    //  ── Construction ─────────────────────────────────────────────────────────
    //
    //    // Single exact state
    //    std::make_shared<StateFilter>(Form::waiting_name)
    //
    //    // Multiple states (any match)
    //    std::make_shared<StateFilter>(
    //        std::vector<StateEntry>{Form::waiting_name, Form::waiting_age})
    //
    //    // Raw string (useful when the State object is not in scope)
    //    std::make_shared<StateFilter>(std::string("Form:waiting_name"))
    //
    //    // Wildcard — any active state
    //    std::make_shared<StateFilter>(std::string("*"))
    //
    //    // No state
    //    std::make_shared<StateFilter>(nullptr)
    //
    //    // Group-wide match (any state whose value starts with "Form:")
    //    StateFilter::for_group<Form>()
    //
    //  ── Convenience via F:: namespace (defined below) ─────────────────────
    //
    //    F::State(Form::waiting_name)
    //    F::State({Form::waiting_name, Form::waiting_age})
    //    F::State("*")          // any active state
    //    F::State(nullptr)      // no state
    //    F::AnyState()          // alias for F::State("*")
    //    F::NoState()           // alias for F::State(nullptr)
    //    F::StateGroup<Form>()  // any state inside the Form group
    //
    //  ── Handler access ────────────────────────────────────────────────────
    //
    //    auto& info = ctx.get<corogram::fsm::StateInfo>("state");
    //    // info.raw  → std::optional<std::string>
    //    // info.active() → bool
    // =========================================================================

    class StateFilter : public corogram::SharedFilter<StateFilter>
    {
    public:
        // ── Constructors ──────────────────────────────────────────────────────

        /// Single State object.
        explicit StateFilter(State s)
        {
            entries_.emplace_back(std::move(s));
        }

        /// Single raw string ("*" for wildcard).
        explicit StateFilter(std::string raw)
        {
            entries_.emplace_back(std::move(raw));
        }

        /// No-state sentinel.
        explicit StateFilter(std::nullptr_t)
        {
            entries_.emplace_back(nullptr);
        }

        /// Arbitrary mix of StateEntry values.
        explicit StateFilter(std::vector<StateEntry> entries)
            : entries_(std::move(entries))
        {
        }

        // ── Group factory ─────────────────────────────────────────────────────

        /// Matches any state whose raw value starts with "GroupName:".
        /// Example:
        ///   StateFilter::for_group<Form>()
        ///   // matches "Form:waiting_name", "Form:waiting_age", …
        template <typename G>
        static std::shared_ptr<StateFilter> for_group()
        {
            auto prefix = std::string(G::group_name()) + ":";
            auto f = std::make_shared<StateFilter>(std::vector<StateEntry>{});
            f->group_prefix_ = std::move(prefix);
            return f;
        }

        // ── BaseFilter interface ──────────────────────────────────────────────

        drogon::Task<bool> check(const corogram::Update &, corogram::Context &ctx) override
        {
            // FSMMiddleware must have placed an FSMContext in ctx["fsm"].
            auto *ptr = ctx.get_if<std::shared_ptr<FSMContext>>("fsm");
            if (!ptr)
                co_return false;

            const std::optional<std::string> current =
                co_await (*ptr)->get_state();

            bool matched = false;

            // ── Group-prefix check (from for_group<G>()) ──────────────────────
            if (!group_prefix_.empty())
            {
                if (current.has_value() &&
                    current->rfind(group_prefix_, 0) == 0)
                {
                    matched = true;
                }
            }
            else
            {
                // ── Per-entry matching ─────────────────────────────────────────
                for (const auto &entry : entries_)
                {
                    if (std::holds_alternative<std::nullptr_t>(entry))
                    {
                        // nullptr → match when there is NO active state
                        if (!current.has_value())
                        {
                            matched = true;
                            break;
                        }
                    }
                    else if (const auto *raw = std::get_if<std::string>(&entry))
                    {
                        if (*raw == "*")
                        {
                            // Wildcard → any active state
                            if (current.has_value())
                            {
                                matched = true;
                                break;
                            }
                        }
                        else
                        {
                            // Exact raw string match
                            if (current.has_value() && *current == *raw)
                            {
                                matched = true;
                                break;
                            }
                        }
                    }
                    else if (const auto *s = std::get_if<State>(&entry))
                    {
                        if (s->matches(current))
                        {
                            matched = true;
                            break;
                        }
                    }
                }
            }

            if (!matched)
                co_return false;

            // Inject StateInfo into context so handlers can read it cheaply.
            ctx.set<StateInfo>("state", StateInfo{current});
            co_return true;
        }

    private:
        std::vector<StateEntry> entries_;
        std::string group_prefix_; // non-empty only for for_group<G>()
    };

} // namespace corogram::fsm

// =============================================================================
//  F:: convenience wrappers — placed in the corogram::F namespace so they sit
//  next to the existing F::state() / F::any_state() / F::no_state() stubs.
//
//  These wrappers use the full class-based StateFilter, which injects a
//  StateInfo into ctx["state"] on success.  The old inline stubs in Filters.hpp
//  only return bool and do not inject anything — they are kept for backwards
//  compatibility but the class-based versions are preferred.
// =============================================================================

namespace corogram::F
{
    // ── F::State ──────────────────────────────────────────────────────────────

    /// Exact state match.  Injects StateInfo into ctx["state"].
    inline corogram::Filter State(fsm::State s)
    {
        return Filter(std::static_pointer_cast<BaseFilter>(
            std::make_shared<fsm::StateFilter>(std::move(s))));
        
    }

    /// Multiple states (any match).  Injects StateInfo into ctx["state"].
    inline corogram::Filter State(std::vector<fsm::StateEntry> entries)
    {
        return Filter(std::static_pointer_cast<BaseFilter>(
            std::make_shared<fsm::StateFilter>(std::move(entries))));
    }

    /// Raw string match.  Pass "*" for wildcard, or an exact "Group:field"
    /// string.  Injects StateInfo into ctx["state"].
    inline corogram::Filter State(std::string raw)
    {
        return Filter(std::static_pointer_cast<BaseFilter>(
            std::make_shared<fsm::StateFilter>(std::move(raw))));
    }

    /// No-state match — triggers when the user has no active FSM state.
    /// Injects StateInfo{nullopt} into ctx["state"].
    inline corogram::Filter State(std::nullptr_t)
    {
        return Filter(std::static_pointer_cast<BaseFilter>(
            std::make_shared<fsm::StateFilter>(nullptr)));
    }

    // ── F::AnyState / F::NoState ──────────────────────────────────────────────

    /// Matches any active FSM state (equivalent to F::State("*")).
    inline corogram::Filter AnyState()
    {
        return Filter(std::static_pointer_cast<BaseFilter>(
            std::make_shared<fsm::StateFilter>(std::string("*"))));
    }

    /// Matches when there is no active FSM state (equivalent to F::State(nullptr)).
    inline corogram::Filter NoState()
    {
        return Filter(std::static_pointer_cast<BaseFilter>(
            std::make_shared<fsm::StateFilter>(nullptr)));
    }

    // ── F::StateGroup<G> ──────────────────────────────────────────────────────

    /// Matches any state belonging to the given StatesGroup subclass.
    ///
    ///   struct Form : corogram::fsm::StatesGroup<Form> {
    ///       inline static auto waiting_name = state("waiting_name");
    ///       inline static auto waiting_age  = state("waiting_age");
    ///   };
    ///
    ///   dp.message().filter(F::StateGroup<Form>());
    ///   // passes for "Form:waiting_name" AND "Form:waiting_age"
    template <typename G>
    corogram::Filter StateGroup()
    {
        return fsm::StateFilter::for_group<G>();
    }

} // namespace corogram::F