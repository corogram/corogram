// include/core/middlewares/UserContextMiddleware.hpp
#pragma once
#include <memory>
#include <optional>
#include <string>
#include <variant>

#include <corogram/core/Middleware.hpp>
#include <corogram/Types.hpp>

namespace corogram
{

    // =========================================================================
    //  EventContext
    //
    //  Mirrors python-telegram-bot's effective_user / effective_chat /
    //  effective_message / effective_sender pattern.
    //
    //  All shared_ptr members are null when not applicable to the update type.
    //  Reference-counted — safe to hold beyond the lifetime of the Update.
    //
    //  Stored in Context under "event_context".
    //  Individual keys are also set for ergonomic handler access:
    //
    //    "user"                   → shared_ptr<const User>
    //    "chat"                   → shared_ptr<const Chat>
    //    "message"                → shared_ptr<const Message>
    //    "chat_id"                → int64_t
    //    "thread_id"              → int64_t              (if present)
    //    "business_connection_id" → std::string          (if present)
    //
    //  effective_sender is either a User or a Chat (anonymous admins,
    //  channel posts, voter_chat in poll answers).
    // =========================================================================

    using EffectiveSender = std::variant<
        std::shared_ptr<const User>,
        std::shared_ptr<const Chat>>;

    struct EventContext
    {
        /// The acting user. Null for channel posts, anonymous polls,
        /// chat_boost, removed_chat_boost, message_reaction_count,
        /// deleted_business_messages.
        std::shared_ptr<const User> effective_user;

        /// The originating chat. Null for inline queries, shipping/checkout
        /// queries, poll, poll_answer, business_connection, purchased_paid_media.
        std::shared_ptr<const Chat> effective_chat;

        /// The associated message (message, edited_message, channel_post,
        /// edited_channel_post, callback_query.message, business_message,
        /// edited_business_message). Null otherwise.
        std::shared_ptr<const Message> effective_message;

        /// The actual sender — either a User or a Chat (anonymous admin /
        /// channel / voter_chat). Null only when no sender is available at all
        /// (poll, chat_boost, removed_chat_boost, message_reaction_count,
        /// deleted_business_messages).
        std::optional<EffectiveSender> effective_sender;

        std::optional<int64_t> thread_id;
        std::optional<std::string> business_connection_id;

        // ── Convenience ───────────────────────────────────────────────────────

        int64_t user_id() const noexcept
        {
            return effective_user ? effective_user->id : 0;
        }

        int64_t chat_id() const noexcept
        {
            return effective_chat ? effective_chat->id : 0;
        }

        bool has_user() const noexcept { return effective_user != nullptr; }
        bool has_chat() const noexcept { return effective_chat != nullptr; }
        bool has_message() const noexcept { return effective_message != nullptr; }
        bool has_sender() const noexcept { return effective_sender.has_value(); }

        /// Returns the sender as a User, or nullptr if sender is a Chat or absent.
        const User *sender_user() const noexcept
        {
            if (!effective_sender)
                return nullptr;
            auto *u = std::get_if<std::shared_ptr<const User>>(&*effective_sender);
            return u ? u->get() : nullptr;
        }

        /// Returns the sender as a Chat, or nullptr if sender is a User or absent.
        const Chat *sender_chat() const noexcept
        {
            if (!effective_sender)
                return nullptr;
            auto *c = std::get_if<std::shared_ptr<const Chat>>(&*effective_sender);
            return c ? c->get() : nullptr;
        }
    };

    // =========================================================================
    //  ctx_keys — type-safe context key descriptors
    //
    //  Usage:
    //    ctx_keys::user.set(ctx, ptr);
    //    auto* u = ctx_keys::user.get(ctx);   // shared_ptr<const User>*
    //
    //  Or classic string access (still works):
    //    ctx.get_if<std::shared_ptr<const User>>("user")
    // =========================================================================

    namespace ctx_keys
    {
        template <typename T>
        struct Key
        {
            const char *name;

            void set(Context &ctx, T value) const
            {
                ctx.set<T>(name, std::move(value));
            }

            T *get(Context &ctx) const
            {
                return ctx.get_if<T>(name);
            }

            bool has(const Context &ctx) const
            {
                return ctx.has(name);
            }
        };

        inline constexpr Key<EventContext> event_context{"event_context"};
        inline constexpr Key<std::shared_ptr<const User>> user{"user"};
        inline constexpr Key<std::shared_ptr<const Chat>> chat{"chat"};
        inline constexpr Key<std::shared_ptr<const Message>> message{"message"};
        inline constexpr Key<int64_t> chat_id{"chat_id"};
        inline constexpr Key<int64_t> thread_id{"thread_id"};
        inline constexpr Key<std::string> business_connection_id{"business_connection_id"};

    } // namespace ctx_keys

    // =========================================================================
    //  resolve_event_context
    //
    //  Logic mirrors python-telegram-bot's Update.effective_user /
    //  effective_chat / effective_message / effective_sender properties.
    // =========================================================================

    inline EventContext resolve_event_context(const Update &upd)
    {
        EventContext ec;

        // ── Helper: fill thread_id / business_connection_id from a Message ────
        auto fill_extras = [&](const Message &msg)
        {
            if (msg.is_topic_message.value_or(false))
                ec.thread_id = msg.message_thread_id;
            if (msg.business_connection_id.has_value())
                ec.business_connection_id = msg.business_connection_id;
        };

        // ─────────────────────────────────────────────────────────────────────
        //  effective_user  (matches PTB order exactly)
        // ─────────────────────────────────────────────────────────────────────
        if (upd.message)
            ec.effective_user = upd.message->from;
        else if (upd.edited_message)
            ec.effective_user = upd.edited_message->from;
        else if (upd.inline_query)
            ec.effective_user = upd.inline_query->from;
        else if (upd.chosen_inline_result)
            ec.effective_user = upd.chosen_inline_result->from;
        else if (upd.callback_query)
            ec.effective_user = upd.callback_query->from;
        else if (upd.shipping_query)
            ec.effective_user = upd.shipping_query->from;
        else if (upd.pre_checkout_query)
            ec.effective_user = upd.pre_checkout_query->from;
        else if (upd.poll_answer)
            ec.effective_user = upd.poll_answer->user;
        else if (upd.my_chat_member)
            ec.effective_user = upd.my_chat_member->from;
        else if (upd.chat_member)
            ec.effective_user = upd.chat_member->from;
        else if (upd.chat_join_request)
            ec.effective_user = upd.chat_join_request->from;
        else if (upd.message_reaction)
            ec.effective_user = upd.message_reaction->user;
        else if (upd.business_message)
            ec.effective_user = upd.business_message->from;
        else if (upd.edited_business_message)
            ec.effective_user = upd.edited_business_message->from;
        else if (upd.business_connection)
            ec.effective_user = upd.business_connection->user;
        else if (upd.purchased_paid_media)
            ec.effective_user = upd.purchased_paid_media->from;
        else if (upd.managed_bot)
            ec.effective_user = upd.managed_bot->user;

        // ─────────────────────────────────────────────────────────────────────
        //  effective_chat  (matches PTB order exactly)
        // ─────────────────────────────────────────────────────────────────────
        if (upd.message)
            ec.effective_chat = upd.message->chat;
        else if (upd.edited_message)
            ec.effective_chat = upd.edited_message->chat;
        else if (upd.callback_query && upd.callback_query->message.has_value())
        {
            if (auto *mp = std::get_if<std::shared_ptr<Message>>(
                    &upd.callback_query->message.value()))
                if (*mp)
                    ec.effective_chat = (*mp)->chat;
        }
        else if (upd.channel_post)
            ec.effective_chat = upd.channel_post->chat;
        else if (upd.edited_channel_post)
            ec.effective_chat = upd.edited_channel_post->chat;
        else if (upd.my_chat_member)
            ec.effective_chat = upd.my_chat_member->chat;
        else if (upd.chat_member)
            ec.effective_chat = upd.chat_member->chat;
        else if (upd.chat_join_request)
            ec.effective_chat = upd.chat_join_request->chat;
        else if (upd.chat_boost)
            ec.effective_chat = upd.chat_boost->chat;
        else if (upd.removed_chat_boost)
            ec.effective_chat = upd.removed_chat_boost->chat;
        else if (upd.message_reaction)
            ec.effective_chat = upd.message_reaction->chat;
        else if (upd.message_reaction_count)
            ec.effective_chat = upd.message_reaction_count->chat;
        else if (upd.business_message)
            ec.effective_chat = upd.business_message->chat;
        else if (upd.edited_business_message)
            ec.effective_chat = upd.edited_business_message->chat;
        else if (upd.deleted_business_messages)
            ec.effective_chat = upd.deleted_business_messages->chat;

        // ─────────────────────────────────────────────────────────────────────
        //  effective_message  (matches PTB order exactly)
        // ─────────────────────────────────────────────────────────────────────
        if (upd.message)
        {
            ec.effective_message = upd.message;
            fill_extras(*upd.message);
        }
        else if (upd.edited_message)
        {
            ec.effective_message = upd.edited_message;
            fill_extras(*upd.edited_message);
        }
        else if (upd.callback_query && upd.callback_query->message.has_value())
        {
            if (auto *mp = std::get_if<std::shared_ptr<Message>>(
                    &upd.callback_query->message.value()))
                if (*mp)
                {
                    ec.effective_message = *mp;
                    fill_extras(**mp);
                }
        }
        else if (upd.channel_post)
        {
            ec.effective_message = upd.channel_post;
            fill_extras(*upd.channel_post);
        }
        else if (upd.edited_channel_post)
        {
            ec.effective_message = upd.edited_channel_post;
            fill_extras(*upd.edited_channel_post);
        }
        else if (upd.business_message)
        {
            ec.effective_message = upd.business_message;
            fill_extras(*upd.business_message);
        }
        else if (upd.edited_business_message)
        {
            ec.effective_message = upd.edited_business_message;
            fill_extras(*upd.edited_business_message);
        }

        // ─────────────────────────────────────────────────────────────────────
        //  effective_sender  (matches PTB logic)
        //
        //  Priority: sender_chat (anonymous) → effective_user
        // ─────────────────────────────────────────────────────────────────────
        {
            std::shared_ptr<const Chat> sender_chat;

            // Messages with sender_chat (anonymous admin / channel)
            auto try_sender_chat = [&](const Message &msg)
            {
                if (msg.sender_chat)
                    sender_chat = msg.sender_chat;
            };

            if (upd.message)
                try_sender_chat(*upd.message);
            else if (upd.edited_message)
                try_sender_chat(*upd.edited_message);
            else if (upd.channel_post)
                try_sender_chat(*upd.channel_post);
            else if (upd.edited_channel_post)
                try_sender_chat(*upd.edited_channel_post);
            else if (upd.business_message)
                try_sender_chat(*upd.business_message);
            else if (upd.edited_business_message)
                try_sender_chat(*upd.edited_business_message);
            else if (upd.poll_answer && upd.poll_answer->voter_chat)
                sender_chat = upd.poll_answer->voter_chat;
            else if (upd.message_reaction && upd.message_reaction->actor_chat)
                sender_chat = upd.message_reaction->actor_chat;

            if (sender_chat)
                ec.effective_sender = sender_chat;
            else if (ec.effective_user)
                ec.effective_sender = ec.effective_user;

            // business_connection_id for non-message updates
            if (!ec.business_connection_id.has_value())
            {
                if (upd.deleted_business_messages)
                    ec.business_connection_id = upd.deleted_business_messages->business_connection_id;
                else if (upd.business_connection)
                    ec.business_connection_id = upd.business_connection->id;
            }
        }

        return ec;
    }

    // =========================================================================
    //  make_user_context_middleware
    // =========================================================================

    inline MiddlewareFn make_user_context_middleware()
    {
        return [](NextFn next, const Update &upd, Context &ctx)
                   -> drogon::Task<std::any>
        {
            EventContext ec = resolve_event_context(upd);

            ctx.set<EventContext>("event_context", ec);

            if (ec.effective_user)
                ctx.set<std::shared_ptr<const User>>("user", ec.effective_user);

            if (ec.effective_chat)
            {
                ctx.set<std::shared_ptr<const Chat>>("chat", ec.effective_chat);
                ctx.set<int64_t>("chat_id", ec.effective_chat->id);
            }

            if (ec.effective_message)
                ctx.set<std::shared_ptr<const Message>>("message", ec.effective_message);

            if (ec.thread_id.has_value())
                ctx.set<int64_t>("thread_id", *ec.thread_id);

            if (ec.business_connection_id.has_value())
                ctx.set<std::string>("business_connection_id", *ec.business_connection_id);

            co_return co_await next(upd, ctx);
        };
    }

} // namespace corogram