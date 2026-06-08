// include/core/filters/MagicFilter.hpp
#pragma once
#include <functional>
#include <optional>
#include <regex>
#include <set>
#include <string>
#include <vector>

#include <drogon/drogon.h>

#include <corogram/Types.hpp>
#include <corogram/core/Context.hpp>
#include <corogram/core/filters/BaseFilter.hpp> // FilterFn is defined here — do not redeclare

namespace corogram
{

    // =========================================================================
    //  MagicFilter — F.field.op(value) filter chain
    //
    //  Each field type exposes comparison methods that return a FilterFn.
    //
    //  Usage:
    //    MF.text.eq("hello")
    //    MF.text.contains("ell")
    //    MF.text.starts_with("/")
    //    MF.text.in_({"yes", "no"})
    //    MF.text.regex(R"(\d+)")
    //    MF.from_user.id.eq(123456LL)
    //    MF.from_user.is_bot.eq(false)
    //    MF.from_user.id.in_({111, 222, 333})
    //    MF.callback_data.eq("menu_back")
    //    MF.callback_data.starts_with("menu_")
    // =========================================================================

    // ── String field chain ────────────────────────────────────────────────────

    struct StringField
    {
        std::function<std::optional<std::string>(const Update &)> extractor;

        /// Exact match.
        FilterFn eq(std::string expected) const
        {
            auto ex = extractor;
            return [ex, expected = std::move(expected)](const Update &upd, Context &)
                       -> drogon::Task<bool>
            {
                auto val = ex(upd);
                co_return val.has_value() && *val == expected;
            };
        }

        /// Not equal.
        FilterFn ne(std::string expected) const
        {
            auto ex = extractor;
            return [ex, expected = std::move(expected)](const Update &upd, Context &)
                       -> drogon::Task<bool>
            {
                auto val = ex(upd);
                co_return !val.has_value() || *val != expected;
            };
        }

        /// Substring match.
        FilterFn contains(std::string substr) const
        {
            auto ex = extractor;
            return [ex, substr = std::move(substr)](const Update &upd, Context &)
                       -> drogon::Task<bool>
            {
                auto val = ex(upd);
                co_return val.has_value() && val->find(substr) != std::string::npos;
            };
        }

        /// Prefix match.
        FilterFn starts_with(std::string prefix) const
        {
            auto ex = extractor;
            return [ex, prefix = std::move(prefix)](const Update &upd, Context &)
                       -> drogon::Task<bool>
            {
                auto val = ex(upd);
                co_return val.has_value() && val->rfind(prefix, 0) == 0;
            };
        }

        /// Suffix match.
        FilterFn ends_with(std::string suffix) const
        {
            auto ex = extractor;
            return [ex, suffix = std::move(suffix)](const Update &upd, Context &)
                       -> drogon::Task<bool>
            {
                auto val = ex(upd);
                if (!val.has_value())
                    co_return false;
                co_return val->size() >= suffix.size() &&
                    val->compare(val->size() - suffix.size(), suffix.size(), suffix) == 0;
            };
        }

        /// Set membership.
        FilterFn in_(std::vector<std::string> values) const
        {
            auto ex = extractor;
            std::set<std::string> s(values.begin(), values.end());
            return [ex, s = std::move(s)](const Update &upd, Context &)
                       -> drogon::Task<bool>
            {
                auto val = ex(upd);
                co_return val.has_value() && s.count(*val) > 0;
            };
        }

        /// Regex match. Stores the std::smatch result in ctx under "regex_match".
        FilterFn regex(std::string pattern) const
        {
            auto ex = extractor;
            std::regex re(pattern);  // ✅ bir kez compile edilir
            return [ex, re = std::move(re)](const Update &upd, Context &ctx) -> drogon::Task<bool>
            {
                auto val = ex(upd);
                if (!val.has_value()) co_return false;
                std::smatch m;
                if (std::regex_search(*val, m, re)) {
                    ctx.set<std::smatch>("regex_match", m);
                    co_return true;
                }
                co_return false;
            };
        }

        /// True if the field is absent or empty.
        FilterFn empty() const
        {
            auto ex = extractor;
            return [ex](const Update &upd, Context &) -> drogon::Task<bool>
            {
                auto val = ex(upd);
                co_return !val.has_value() || val->empty();
            };
        }

        /// True if the field is present (not nullopt).
        FilterFn exists() const
        {
            auto ex = extractor;
            return [ex](const Update &upd, Context &) -> drogon::Task<bool>
            {
                co_return ex(upd).has_value();
            };
        }
    };

    // ── Int64 field chain ─────────────────────────────────────────────────────

    struct Int64Field
    {
        std::function<std::optional<int64_t>(const Update &)> extractor;

        FilterFn eq(int64_t expected) const
        {
            auto ex = extractor;
            return [ex, expected](const Update &upd, Context &) -> drogon::Task<bool>
            {
                auto val = ex(upd);
                co_return val.has_value() && *val == expected;
            };
        }

        FilterFn ne(int64_t expected) const
        {
            auto ex = extractor;
            return [ex, expected](const Update &upd, Context &) -> drogon::Task<bool>
            {
                auto val = ex(upd);
                co_return !val.has_value() || *val != expected;
            };
        }

        FilterFn gt(int64_t threshold) const
        {
            auto ex = extractor;
            return [ex, threshold](const Update &upd, Context &) -> drogon::Task<bool>
            {
                auto val = ex(upd);
                co_return val.has_value() && *val > threshold;
            };
        }

        FilterFn lt(int64_t threshold) const
        {
            auto ex = extractor;
            return [ex, threshold](const Update &upd, Context &) -> drogon::Task<bool>
            {
                auto val = ex(upd);
                co_return val.has_value() && *val < threshold;
            };
        }

        FilterFn in_(std::vector<int64_t> values) const
        {
            auto ex = extractor;
            std::set<int64_t> s(values.begin(), values.end());
            return [ex, s = std::move(s)](const Update &upd, Context &)
                       -> drogon::Task<bool>
            {
                auto val = ex(upd);
                co_return val.has_value() && s.count(*val) > 0;
            };
        }
    };

    // ── Bool field chain ──────────────────────────────────────────────────────

    struct BoolField
    {
        std::function<std::optional<bool>(const Update &)> extractor;

        FilterFn eq(bool expected) const
        {
            auto ex = extractor;
            return [ex, expected](const Update &upd, Context &) -> drogon::Task<bool>
            {
                auto val = ex(upd);
                co_return val.has_value() && *val == expected;
            };
        }

        FilterFn is_true() const { return eq(true); }
        FilterFn is_false() const { return eq(false); }
    };

    // ── from_user sub-chain ───────────────────────────────────────────────────

    struct FromUserChain
    {
        /// Extracts the sender from a message or callback query.
        static const User *get_user(const Update &upd)
        {
            if (upd.message && upd.message->from)
                return upd.message->from.get();
            if (upd.callback_query)
                return upd.callback_query->from.get();
            return nullptr;
        }

        Int64Field id{{[](const Update &upd) -> std::optional<int64_t>
                       {
                           auto *u = get_user(upd);
                           return u ? std::optional{u->id} : std::nullopt;
                       }}};

        BoolField is_bot{{[](const Update &upd) -> std::optional<bool>
                          {
                              auto *u = get_user(upd);
                              return u ? std::optional{u->is_bot} : std::nullopt;
                          }}};

        StringField username{{[](const Update &upd) -> std::optional<std::string>
                              {
                                  auto *u = get_user(upd);
                                  if (!u || !u->username.has_value())
                                      return std::nullopt;
                                  return *u->username;
                              }}};

        StringField first_name{{[](const Update &upd) -> std::optional<std::string>
                                {
                                    auto *u = get_user(upd);
                                    return u ? std::optional{u->first_name} : std::nullopt;
                                }}};

        StringField language_code{{[](const Update &upd) -> std::optional<std::string>
                                   {
                                       auto *u = get_user(upd);
                                       if (!u || !u->language_code.has_value())
                                           return std::nullopt;
                                       return *u->language_code;
                                   }}};
    };

    // ── Chat sub-chain ────────────────────────────────────────────────────────

    struct ChatChain
    {
        /// Extracts the chat from a message update.
        static const Chat *get_chat(const Update &upd)
        {
            if (upd.message && upd.message->chat)
                return upd.message->chat.get();
            return nullptr;
        }

        Int64Field id{{[](const Update &upd) -> std::optional<int64_t>
                       {
                           auto *c = get_chat(upd);
                           return c ? std::optional{c->id} : std::nullopt;
                       }}};

        StringField type{{[](const Update &upd) -> std::optional<std::string>
                          {
                              auto *c = get_chat(upd);
                              return c ? std::optional{c->type} : std::nullopt;
                          }}};

        StringField title{{[](const Update &upd) -> std::optional<std::string>
                           {
                               auto *c = get_chat(upd);
                               if (!c || !c->title.has_value())
                                   return std::nullopt;
                               return *c->title;
                           }}};
    };

    // =========================================================================
    //  MagicFilterRoot — global singleton accessed as MF.field.op(value)
    // =========================================================================

    struct MagicFilterRoot
    {
        /// Message text field.
        StringField text{{[](const Update &upd) -> std::optional<std::string>
                          {
                              if (upd.message && upd.message->text.has_value())
                                  return *upd.message->text;
                              return std::nullopt;
                          }}};

        /// Message caption field.
        StringField caption{{[](const Update &upd) -> std::optional<std::string>
                             {
                                 if (upd.message && upd.message->caption.has_value())
                                     return *upd.message->caption;
                                 return std::nullopt;
                             }}};

        /// Callback query data field.
        StringField callback_data{{[](const Update &upd) -> std::optional<std::string>
                                   {
                                       if (upd.callback_query && upd.callback_query->data.has_value())
                                           return *upd.callback_query->data;
                                       return std::nullopt;
                                   }}};

        FromUserChain from_user;
        ChatChain chat;
    };

    /// Global MagicFilter instance. Use as: MF.text.eq("hello")
    inline MagicFilterRoot MF;

} // namespace corogram