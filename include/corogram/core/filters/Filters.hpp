// include/core/filters/Filters.hpp
#pragma once
#include <functional>
#include <memory>
#include <regex>
#include <set>
#include <string>
#include <vector>

#include <drogon/drogon.h>

#include <corogram/Types.hpp>
#include <corogram/fsm/BaseStorage.hpp>
#include <corogram/fsm/FSMContext.hpp>
#include <corogram/fsm/State.hpp>
#include <corogram/core/Context.hpp>
#include <corogram/core/filters/BaseFilter.hpp>
#include <corogram/core/filters/MagicFilter.hpp>
#include <corogram/Bot.hpp>
namespace corogram
{

    // =========================================================================
    //  Filter — FilterFn wrapper with &&, ||, ! operator support.
    //
    //  Can be composed with class-based BaseFilter instances:
    //    auto f = F::private_chat() && std::make_shared<IsAdmin>(ID);
    //    auto g = std::make_shared<IsAdmin>(ID) || F::from_user(ID2);
    // =========================================================================

    struct Filter;
    inline Filter make_filter(FilterFn fn);

    struct Filter
    {
        FilterFn fn;

        Filter() = default;
        explicit Filter(FilterFn f) : fn(std::move(f)) {}

        // Implicit conversion from shared_ptr<BaseFilter>
        Filter(std::shared_ptr<BaseFilter> f)
            : fn(BaseFilter::make_fn(std::move(f))) {}

        operator FilterFn() const { return fn; }

        drogon::Task<bool> operator()(const Update &upd, Context &ctx) const
        {
            co_return co_await fn(upd, ctx);
        }

        Filter operator&&(Filter other) const
        {
            auto a = fn, b = other.fn;
            return make_filter([a, b](const Update &upd, Context &ctx) -> drogon::Task<bool>
                               {
                if (!co_await a(upd, ctx)) co_return false;
                co_return co_await b(upd, ctx); });
        }

        Filter operator||(Filter other) const
        {
            auto a = fn, b = other.fn;
            return make_filter([a, b](const Update &upd, Context &ctx) -> drogon::Task<bool>
                               {
                if (co_await a(upd, ctx)) co_return true;
                co_return co_await b(upd, ctx); });
        }

        Filter operator!() const
        {
            auto a = fn;
            return make_filter([a](const Update &upd, Context &ctx) -> drogon::Task<bool>
                               { co_return !co_await a(upd, ctx); });
        }

        Filter operator&&(std::shared_ptr<BaseFilter> other) const
        {
            auto a = fn, b = BaseFilter::make_fn(std::move(other));
            return make_filter([a, b](const Update &upd, Context &ctx) -> drogon::Task<bool>
                               {
                if (!co_await a(upd, ctx)) co_return false;
                co_return co_await b(upd, ctx); });
        }

        Filter operator||(std::shared_ptr<BaseFilter> other) const
        {
            auto a = fn, b = BaseFilter::make_fn(std::move(other));
            return make_filter([a, b](const Update &upd, Context &ctx) -> drogon::Task<bool>
                               {
                if (co_await a(upd, ctx)) co_return true;
                co_return co_await b(upd, ctx); });
        }
    };

    inline Filter make_filter(FilterFn fn) { return Filter(std::move(fn)); }

    inline Filter operator&&(std::shared_ptr<BaseFilter> a, Filter b)
    {
        auto fa = BaseFilter::make_fn(std::move(a)), fb = b.fn;
        return make_filter([fa, fb](const Update &upd, Context &ctx) -> drogon::Task<bool>
                           {
            if (!co_await fa(upd, ctx)) co_return false;
            co_return co_await fb(upd, ctx); });
    }

    inline Filter operator||(std::shared_ptr<BaseFilter> a, Filter b)
    {
        auto fa = BaseFilter::make_fn(std::move(a)), fb = b.fn;
        return make_filter([fa, fb](const Update &upd, Context &ctx) -> drogon::Task<bool>
                           {
            if (co_await fa(upd, ctx)) co_return true;
            co_return co_await fb(upd, ctx); });
    }

    // =========================================================================
    //  ChatType
    // =========================================================================

    enum class ChatType
    {
        Private,
        Group,
        Supergroup,
        Channel
    };


    
    struct CommandObject
    {
        /// The prefix character (e.g. "/").
        std::string prefix;

        /// The command name without prefix or mention (e.g. "start").
        std::string command;

        /// Bot mention if present (e.g. "MyBot" from "/start@MyBot").
        std::optional<std::string> mention;

        /// Everything after the command and the first space, if any.
        std::optional<std::string> args;

        /// Non-empty if the command was matched via a regex pattern.
        std::optional<std::smatch> regexp_match;

        // ── Convenience ──────────────────────────────────────────────────────

        /// True when the message had a @mention.
        bool mentioned() const { return mention.has_value(); }

        /// Reconstructs the original command string.
        std::string text() const
        {
            std::string s = prefix + command;
            if (mention)
                s += "@" + *mention;
            if (args)
                s += " " + *args;
            return s;
        }
    };

    // =========================================================================
    //  CommandFilter
    //
    //  Class-based filter that:
    //    1. Validates that the update is a message with text starting with
    //       one of the allowed prefixes.
    //    2. Checks that the command name matches one of the registered names
    //       or regex patterns.
    //    3. Optionally validates the bot @mention.
    //    4. On success, injects a CommandObject into Context under "command".
    //
    //  Usage:
    //    // Single command — heap-allocated, safe lifetime via SharedFilter
    //    auto f = std::make_shared<CommandFilter>("start");
    //    dp.message().filter(f);
    //
    //    // Multiple commands
    //    auto f = std::make_shared<CommandFilter>(
    //                 std::vector<std::string>{"help", "info"});
    //
    //    // With regex
    //    auto f = std::make_shared<CommandFilter>(std::regex("set_.+"));
    //
    //    // Custom prefix (e.g. "!" or "/!")
    //    auto f = std::make_shared<CommandFilter>("ban", "!");
    //
    //    // Ignore mention (accept /start@OtherBot too)
    //    auto f = std::make_shared<CommandFilter>("start", "/", true);
    //
    //    // Access parsed object inside handler
    //    auto& cmd = ctx.get<corogram::CommandObject>("command");
    //
    //  Convenience wrappers live in F::command() / F::command_start() below.
    // =========================================================================

    class CommandFilter : public SharedFilter<CommandFilter>
    {
    public:
        using Pattern = std::variant<std::string, std::regex>;

        // ── Constructors ──────────────────────────────────────────────────────

        /// Single command name.
        explicit CommandFilter(std::string cmd,
                               std::string prefix = "/",
                               bool ignore_case = false,
                               bool ignore_mention = false)
            : prefix_(std::move(prefix)), ignore_case_(ignore_case), ignore_mention_(ignore_mention)
        {
            if (ignore_case_)
                for (auto &c : cmd)
                    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
            patterns_.emplace_back(std::move(cmd));
        }

        /// Multiple command names.
        explicit CommandFilter(std::vector<std::string> cmds,
                               std::string prefix = "/",
                               bool ignore_case = false,
                               bool ignore_mention = false)
            : prefix_(std::move(prefix)), ignore_case_(ignore_case), ignore_mention_(ignore_mention)
        {
            for (auto &cmd : cmds)
            {
                if (ignore_case_)
                    for (auto &c : cmd)
                        c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
                patterns_.emplace_back(std::move(cmd));
            }
        }

        /// Single regex pattern.
        explicit CommandFilter(std::regex pattern,
                               std::string prefix = "/",
                               bool ignore_mention = false)
            : prefix_(std::move(prefix)), ignore_case_(false), ignore_mention_(ignore_mention)
        {
            patterns_.emplace_back(std::move(pattern));
        }

        /// Mixed: strings + regexes.
        explicit CommandFilter(std::vector<Pattern> patterns,
                               std::string prefix = "/",
                               bool ignore_case = false,
                               bool ignore_mention = false)
            : patterns_(std::move(patterns)), prefix_(std::move(prefix)), ignore_case_(ignore_case), ignore_mention_(ignore_mention)
        {
        }

        // ── BaseFilter interface ──────────────────────────────────────────────

        drogon::Task<bool> check(const Update &upd, Context &ctx) override
        {
            // Only handle message updates with text.
            if (!upd.message || !upd.message->text.has_value())
                co_return false;

            const std::string &text = *upd.message->text;

            // Parse the raw command object.
            auto maybe = parse(text);
            if (!maybe)
                co_return false;

            CommandObject obj = std::move(*maybe);

            // Prefix check.
            if (prefix_.find(obj.prefix) == std::string::npos)
                co_return false;

            // Mention check: if the command has a @mention and we are not
            // ignoring mentions, the mention must equal our bot's username.
            // NOTE: We do not have bot reference here; callers that need strict
            // mention validation should use a composed filter or override.
            // By default ignore_mention=false means we only reject commands
            // that mention a *different* bot — but since we don't know our
            // username here, we simply skip unknown mentions.
            // Set ignore_mention=true to accept commands for any bot.
            if (obj.mention && !ignore_mention_)
            {
                auto *bot_ptr = ctx.get_if<Bot *>("bot");
                if (bot_ptr && *bot_ptr)
                {
                    auto me = co_await (*bot_ptr)->me();
                    if (me && me->username.has_value())
                    {
                        std::string mention_lower = *obj.mention;
                        std::string username_lower = *me->username;
                        for (auto &c : mention_lower)
                            c = std::tolower((unsigned char)c);
                        for (auto &c : username_lower)
                            c = std::tolower((unsigned char)c);
                        if (mention_lower != username_lower)
                            co_return false;
                    }
                }
            } 

            // Command name matching.
            std::string name = obj.command;
            if (ignore_case_)
                for (auto &c : name)
                    c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));

            bool matched = false;
            for (const auto &pat : patterns_)
            {
                if (auto *str = std::get_if<std::string>(&pat))
                {
                    if (name == *str)
                    {
                        matched = true;
                        break;
                    }
                }
                else if (auto *re = std::get_if<std::regex>(&pat))
                {
                    std::smatch m;
                    if (std::regex_match(name, m, *re))
                    {
                        obj.regexp_match = m;
                        matched = true;
                        break;
                    }
                }
            }

            if (!matched)
                co_return false;

            // Inject the parsed object into the context.
            ctx.set<CommandObject>("command", std::move(obj));
            co_return true;
        }

    private:
        std::vector<Pattern> patterns_;
        std::string prefix_;
        bool ignore_case_;
        bool ignore_mention_;

        // ── Static parser ─────────────────────────────────────────────────────

        /// Parses "/cmd@mention arg1 arg2" into a CommandObject.
        /// Returns nullopt if the text does not look like a command.
        static std::optional<CommandObject> parse(const std::string &text)
        {
            if (text.empty())
                return std::nullopt;

            // Split on the first whitespace: "/cmd@mention" and optional "args"
            auto space_pos = text.find(' ');
            std::string head = text.substr(0, space_pos);
            std::optional<std::string> args;
            if (space_pos != std::string::npos)
            {
                std::string rest = text.substr(space_pos + 1);
                if (!rest.empty())
                    args = std::move(rest);
            }

            if (head.empty())
                return std::nullopt;

            // The first character is the prefix.
            std::string prefix_char(1, head[0]);
            std::string rest = head.substr(1); // "cmd@mention" or "cmd"

            // Split on '@'
            auto at_pos = rest.find('@');
            std::string cmd_name;
            std::optional<std::string> mention;
            if (at_pos != std::string::npos)
            {
                cmd_name = rest.substr(0, at_pos);
                std::string m = rest.substr(at_pos + 1);
                if (!m.empty())
                    mention = std::move(m);
            }
            else
            {
                cmd_name = rest;
            }

            if (cmd_name.empty())
                return std::nullopt;

            return CommandObject{
                .prefix = prefix_char,
                .command = cmd_name,
                .mention = mention,
                .args = args,
            };
        }
    };



    // =========================================================================
    //  F namespace — built-in filters
    // =========================================================================

    namespace F
    {

        // ── Command filters — see CommandFilter.hpp / F::Command() ───────────
        //
        //  The old F::command() stubs have been replaced by F::Command() and
        //  F::CommandStart() which use the full CommandFilter class and inject
        //  a CommandObject into ctx["command"].
        //
        //  Quick reference:
        //    F::Command("start")
        //    F::Command({"help", "info"})
        //    F::Command(std::regex("set_.+"))
        //    F::CommandStart()
        //    F::CommandStart(true)      // requires deep-link
        //    F::CommandStart(false)     // no deep-link allowed
        //    F::CommandHelp()
        //    F::CommandCancel()
        //
        //  All of the above are defined in <corogram/core/filters/CommandFilter.hpp>
        //  which is included automatically via this header.

        // ── Text filters ──────────────────────────────────────────────────────

        inline Filter text()
        {
            return make_filter([](const Update &upd, Context &) -> drogon::Task<bool>
                               { co_return upd.message &&upd.message->text.has_value() && !upd.message->text->empty(); });
        }

        inline Filter text(std::string expected)
        {
            return make_filter([expected = std::move(expected)](const Update &upd, Context &) -> drogon::Task<bool>
                               { co_return upd.message &&upd.message->text.has_value() && *upd.message->text == expected; });
        }

        inline Filter regex(std::string pattern)
        {
            std::regex re(pattern); // ✅ bir kez compile edilir
            return make_filter([re = std::move(re)](const Update &upd, Context &ctx) -> drogon::Task<bool>
                               {
            if (!upd.message || !upd.message->text.has_value()) co_return false;
            std::smatch m;
            if (std::regex_search(*upd.message->text, m, re)) {
                ctx.set<std::smatch>("regex_match", m);
                co_return true;
            }
            co_return false; });
        }

        // ── Chat type filters ─────────────────────────────────────────────────

        inline Filter chat_type(ChatType type)
        {
            return make_filter([type](const Update &upd, Context &) -> drogon::Task<bool>
                               {
                const Chat* chat = nullptr;
                if (upd.message)
                    chat = upd.message->chat.get();
                else if (upd.callback_query && upd.callback_query->message.has_value()) {
                    if (auto* mp = std::get_if<std::shared_ptr<Message>>(
                            &*upd.callback_query->message))
                        if (*mp) chat = (*mp)->chat.get();
                }
                if (!chat) co_return false;
                switch (type) {
                    case ChatType::Private:    co_return chat->type == "private";
                    case ChatType::Group:      co_return chat->type == "group";
                    case ChatType::Supergroup: co_return chat->type == "supergroup";
                    case ChatType::Channel:    co_return chat->type == "channel";
                }
                co_return false; });
        }

        inline Filter private_chat() { return chat_type(ChatType::Private); }
        inline Filter group_chat() { return chat_type(ChatType::Group); }
        inline Filter supergroup_chat() { return chat_type(ChatType::Supergroup); }
        inline Filter channel_post() { return chat_type(ChatType::Channel); }

        // ── User filters ──────────────────────────────────────────────────────

        inline Filter is_bot()
        {
            return make_filter([](const Update &upd, Context &) -> drogon::Task<bool>
                               {
                if (upd.message && upd.message->from) co_return upd.message->from->is_bot;
                co_return false; });
        }

        inline Filter from_user(int64_t user_id)
        {
            return make_filter([user_id](const Update &upd, Context &) -> drogon::Task<bool>
                               {
                if (upd.message && upd.message->from)
                    co_return upd.message->from->id == user_id;
                if (upd.callback_query)
                    co_return upd.callback_query->from->id == user_id;
                co_return false; });
        }

        inline Filter from_users(std::vector<int64_t> user_ids)
        {
            std::set<int64_t> s(user_ids.begin(), user_ids.end());
            return make_filter([s = std::move(s)](const Update &upd, Context &) -> drogon::Task<bool>
                               {
                int64_t uid = 0;
                if (upd.message && upd.message->from) uid = upd.message->from->id;
                else if (upd.callback_query)          uid = upd.callback_query->from->id;
                co_return uid && s.count(uid); });
        }

        // ── Callback query filters ────────────────────────────────────────────

        inline Filter callback_query()
        {
            return make_filter([](const Update &upd, Context &) -> drogon::Task<bool>
                               { co_return upd.callback_query != nullptr; });
        }

        inline Filter callback_data(std::string data)
        {
            return make_filter([data = std::move(data)](const Update &upd, Context &) -> drogon::Task<bool>
                               { co_return upd.callback_query
                                         &&upd.callback_query->data.has_value() &&
                                     *upd.callback_query->data == data; });
        }

        inline Filter callback_data_prefix(std::string prefix)
        {
            return make_filter([prefix = std::move(prefix)](const Update &upd, Context &) -> drogon::Task<bool>
                               {
                if (!upd.callback_query || !upd.callback_query->data.has_value()) co_return false;
                co_return upd.callback_query->data->rfind(prefix, 0) == 0; });
        }

        inline Filter callback_data_regex(std::string pattern)
        {
            std::regex re(pattern); // ✅ bir kez compile edilir
            return make_filter([re = std::move(re)](const Update &upd, Context &ctx) -> drogon::Task<bool>
                                {
            if (!upd.callback_query || !upd.callback_query->data.has_value()) co_return false;
            std::smatch m;
            if (std::regex_search(*upd.callback_query->data, m, re)) {
                ctx.set<std::smatch>("regex_match", m);
                co_return true;
            }
            co_return false; });
        }

        // ── Media filters ─────────────────────────────────────────────────────

        inline Filter photo()
        {
            return make_filter([](const Update &u, Context &) -> drogon::Task<bool>
                               { co_return u.message && !u.message->photo.empty(); });
        }
        inline Filter video()
        {
            return make_filter([](const Update &u, Context &) -> drogon::Task<bool>
                               { co_return u.message &&u.message->video != nullptr; });
        }
        inline Filter audio()
        {
            return make_filter([](const Update &u, Context &) -> drogon::Task<bool>
                               { co_return u.message &&u.message->audio != nullptr; });
        }
        inline Filter document()
        {
            return make_filter([](const Update &u, Context &) -> drogon::Task<bool>
                               { co_return u.message &&u.message->document != nullptr; });
        }
        inline Filter sticker()
        {
            return make_filter([](const Update &u, Context &) -> drogon::Task<bool>
                               { co_return u.message &&u.message->sticker != nullptr; });
        }
        inline Filter voice()
        {
            return make_filter([](const Update &u, Context &) -> drogon::Task<bool>
                               { co_return u.message &&u.message->voice != nullptr; });
        }
        inline Filter location()
        {
            return make_filter([](const Update &u, Context &) -> drogon::Task<bool>
                               { co_return u.message &&u.message->location != nullptr; });
        }

        // ── Reply / forward filters ───────────────────────────────────────────

        inline Filter is_forwarded()
        {
            return make_filter([](const Update &upd, Context &) -> drogon::Task<bool>
                               { co_return upd.message &&upd.message->forward_origin.has_value(); });
        }

        inline Filter is_reply()
        {
            return make_filter([](const Update &upd, Context &) -> drogon::Task<bool>
                               { co_return upd.message &&upd.message->reply_to_message != nullptr; });
        }

        // ── FSM state filters — see StateFilter.hpp / F::State() ─────────────
        //
        //  The stubs below are kept for backwards compatibility.
        //  They only return bool and do NOT inject StateInfo into the context.
        //
        //  Prefer the class-based wrappers from <corogram/fsm/StateFilter.hpp>:
        //
        //    F::State(Form::waiting_name)           // exact state
        //    F::State({Form::waiting_name, ...})    // any of these
        //    F::State("*")                          // any active state
        //    F::State(nullptr)                      // no state
        //    F::AnyState()                          // alias for F::State("*")
        //    F::NoState()                           // alias for F::State(nullptr)
        //    F::StateGroup<Form>()                  // any state in the Form group
        //
        //  All of the above inject corogram::fsm::StateInfo into ctx["state"].

        /// @deprecated  Use F::State(s) from <corogram/fsm/StateFilter.hpp>.
        inline Filter state(fsm::State expected)
        {
            return make_filter([expected = std::move(expected)](const Update &, Context &ctx) -> drogon::Task<bool>
                               {
                auto* ptr = ctx.get_if<std::shared_ptr<fsm::FSMContext>>("fsm");
                if (!ptr) co_return false;
                co_return expected.matches(co_await (*ptr)->get_state()); });
        }

        /// @deprecated  Use F::State({s1, s2}) from <corogram/fsm/StateFilter.hpp>.
        inline Filter state(std::vector<fsm::State> states)
        {
            return make_filter([states = std::move(states)](const Update &, Context &ctx) -> drogon::Task<bool>
                               {
                auto* ptr = ctx.get_if<std::shared_ptr<fsm::FSMContext>>("fsm");
                if (!ptr) co_return false;
                auto current = co_await (*ptr)->get_state();
                for (const auto& s : states)
                    if (s.matches(current)) co_return true;
                co_return false; });
        }

        /// @deprecated  Use F::AnyState() from <corogram/fsm/StateFilter.hpp>.
        inline Filter any_state()
        {
            return make_filter([](const Update &, Context &ctx) -> drogon::Task<bool>
                               {
                auto* ptr = ctx.get_if<std::shared_ptr<fsm::FSMContext>>("fsm");
                if (!ptr) co_return false;
                co_return (co_await (*ptr)->get_state()).has_value(); });
        }

        /// @deprecated  Use F::NoState() from <corogram/fsm/StateFilter.hpp>.
        inline Filter no_state()
        {
            return make_filter([](const Update &, Context &ctx) -> drogon::Task<bool>
                               {
                auto* ptr = ctx.get_if<std::shared_ptr<fsm::FSMContext>>("fsm");
                if (!ptr) co_return true;
                co_return !(co_await (*ptr)->get_state()).has_value(); });
        }

        // ── Catch-all ─────────────────────────────────────────────────────────

        inline Filter all()
        {
            return make_filter([](const Update &, Context &) -> drogon::Task<bool>
                               { co_return true; });
        }
        inline Filter none()
        {
            return make_filter([](const Update &, Context &) -> drogon::Task<bool>
                               { co_return false; });
        }


        /// Match a single command and inject CommandObject into context.
        inline Filter Command(std::string cmd,
                                std::string prefix = "/",
                                bool ignore_case = false,
                                bool ignore_mention = false)
        {
            return Filter(std::static_pointer_cast<BaseFilter>(
                std::make_shared<CommandFilter>(
                    std::move(cmd), std::move(prefix), ignore_case, ignore_mention)));
        }

        /// Match any of the given commands and inject CommandObject into context.
        inline Filter Command(std::vector<std::string> cmds,
                                std::string prefix = "/",
                                bool ignore_case = false,
                                bool ignore_mention = false)
        {
            return Filter(std::static_pointer_cast<BaseFilter>(
                std::make_shared<CommandFilter>(
                    std::move(cmds), std::move(prefix), ignore_case, ignore_mention)));
        }

        /// Match a command by regex and inject CommandObject into context.
        inline Filter Command(std::regex pattern,
                                std::string prefix = "/",
                                bool ignore_mention = false)
        {
            return Filter(std::static_pointer_cast<BaseFilter>(
                std::make_shared<CommandFilter>(
                    std::move(pattern), std::move(prefix), ignore_mention)));
        }

        // ── /start ───────────────────────────────────────────────────────────

        /// Matches the /start command. Optionally requires a deep-link argument.
        ///
        ///   F::CommandStart()           — any /start (with or without args)
        ///   F::CommandStart(true)       — /start with a deep-link payload
        ///   F::CommandStart(false)      — /start without any arguments
        ///
        /// The parsed CommandObject is always injected into ctx["command"].
        /// Deep-link payload is available via cmd.args.
        inline Filter CommandStart(std::optional<bool> require_deep_link = std::nullopt,
                                    bool ignore_case = false,
                                    bool ignore_mention = false)
        {
            auto base = std::make_shared<CommandFilter>(
                "start", "/", ignore_case, ignore_mention);

            if (!require_deep_link.has_value())
                return Filter(std::static_pointer_cast<BaseFilter>(base)); // no deep-link constraint

            bool required = *require_deep_link;

            return make_filter(
                [base, required](const Update &upd, Context &ctx) -> drogon::Task<bool>
                {
                    if (!co_await base->check(upd, ctx))
                        co_return false;

                    // CommandFilter already injected the object.
                    auto *obj = ctx.get_if<CommandObject>("command");
                    if (!obj)
                        co_return false;

                    if (required && !obj->args.has_value())
                        co_return false; // deep-link required but absent

                    if (!required && obj->args.has_value())
                        co_return false; // no deep-link expected but present

                    co_return true;
                });
        }

        // ── /help ─────────────────────────────────────────────────────────────

        /// Matches the /help command.
        inline Filter CommandHelp(bool ignore_case = false,
                                    bool ignore_mention = false)
        {
            return Filter(std::static_pointer_cast<BaseFilter>(
                std::make_shared<CommandFilter>(
                    "help", "/", ignore_case, ignore_mention)));
        }

        // ── /cancel ───────────────────────────────────────────────────────────

        /// Matches the /cancel command (commonly used to abort FSM flows).
        inline Filter CommandCancel(bool ignore_case = false,
                                    bool ignore_mention = false)
        {

            return Filter(std::static_pointer_cast<BaseFilter>(
                std::make_shared<CommandFilter>(
                    "cancel", "/", ignore_case, ignore_mention)));
        }

    } // namespace F
} // namespace corogram