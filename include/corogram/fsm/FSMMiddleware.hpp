// include/fsm/FSMMiddleware.hpp
#pragma once
#include <memory>
#include <corogram/core/Middleware.hpp>
#include <corogram/Types.hpp>
#include <corogram/fsm/BaseStorage.hpp>
#include <corogram/fsm/FSMContext.hpp>
#include <corogram/fsm/StorageKey.hpp>

namespace corogram::fsm
{

    // ─────────────────────────────────────────────────────────────────────────
    //  _extract_ids — extracts bot_id, chat_id, user_id from an Update
    //
    //  Each update type exposes different fields.
    //  For types without a chat_id (inline_query, shipping_query, etc.)
    //  user_id is used for both chat_id and user_id —
    //  consistent with aiogram's behaviour.
    // ─────────────────────────────────────────────────────────────────────────
    struct ExtractedIds
    {
        int64_t bot_id = 0;
        int64_t chat_id = 0;
        int64_t user_id = 0;
    };

    inline ExtractedIds extract_ids(const corogram::Update &upd, corogram::Context &ctx)
    {
        ExtractedIds ids;

        // bot_id — from the Bot pointer stored in context
        if (auto *bot = ctx.get_if<corogram::Bot *>("bot"))
            ids.bot_id = (*bot)->id();

        // ── message / edited_message / business_message etc. ──────────────────
        if (upd.message)
        {
            ids.chat_id = upd.message->chat->id;
            if (upd.message->from)
                ids.user_id = upd.message->from->id;
            return ids;
        }
        if (upd.edited_message)
        {
            ids.chat_id = upd.edited_message->chat->id;
            if (upd.edited_message->from)
                ids.user_id = upd.edited_message->from->id;
            return ids;
        }
        if (upd.business_message)
        {
            ids.chat_id = upd.business_message->chat->id;
            if (upd.business_message->from)
                ids.user_id = upd.business_message->from->id;
            return ids;
        }
        if (upd.edited_business_message)
        {
            ids.chat_id = upd.edited_business_message->chat->id;
            if (upd.edited_business_message->from)
                ids.user_id = upd.edited_business_message->from->id;
            return ids;
        }

        // ── callback_query ────────────────────────────────────────────────────
        if (upd.callback_query)
        {
            ids.user_id = upd.callback_query->from->id;
            if (upd.callback_query->message.has_value())
            {
                if (auto *mp = std::get_if<std::shared_ptr<corogram::Message>>(
                        &*upd.callback_query->message))
                    if (*mp)
                        ids.chat_id = (*mp)->chat->id;
            }
            // Fall back to user_id if no chat_id found (aiogram behaviour)
            if (ids.chat_id == 0)
                ids.chat_id = ids.user_id;
            return ids;
        }

        // ── inline_query — no chat_id, use user_id ───────────────────────────
        if (upd.inline_query)
        {
            ids.user_id = upd.inline_query->from->id;
            ids.chat_id = ids.user_id;
            return ids;
        }

        // ── chosen_inline_result ──────────────────────────────────────────────
        if (upd.chosen_inline_result)
        {
            ids.user_id = upd.chosen_inline_result->from->id;
            ids.chat_id = ids.user_id;
            return ids;
        }

        // ── shipping_query ────────────────────────────────────────────────────
        if (upd.shipping_query)
        {
            ids.user_id = upd.shipping_query->from->id;
            ids.chat_id = ids.user_id;
            return ids;
        }

        // ── pre_checkout_query ────────────────────────────────────────────────
        if (upd.pre_checkout_query)
        {
            ids.user_id = upd.pre_checkout_query->from->id;
            ids.chat_id = ids.user_id;
            return ids;
        }

        // ── poll_answer — anonymous vote: voter_chat present, user may be absent
        if (upd.poll_answer)
        {
            if (upd.poll_answer->user)
                ids.user_id = upd.poll_answer->user->id;
            if (upd.poll_answer->voter_chat)
                ids.chat_id = upd.poll_answer->voter_chat->id;
            else
                ids.chat_id = ids.user_id;
            return ids;
        }

        // ── my_chat_member / chat_member ──────────────────────────────────────
        if (upd.my_chat_member)
        {
            ids.chat_id = upd.my_chat_member->chat->id;
            ids.user_id = upd.my_chat_member->from->id;
            return ids;
        }
        if (upd.chat_member)
        {
            ids.chat_id = upd.chat_member->chat->id;
            ids.user_id = upd.chat_member->from->id;
            return ids;
        }

        // ── chat_join_request ─────────────────────────────────────────────────
        if (upd.chat_join_request)
        {
            ids.chat_id = upd.chat_join_request->chat->id;
            ids.user_id = upd.chat_join_request->from->id;
            return ids;
        }

        // ── message_reaction — user is optional (may be anonymous) ────────────
        if (upd.message_reaction)
        {
            ids.chat_id = upd.message_reaction->chat->id;
            if (upd.message_reaction->user)
                ids.user_id = upd.message_reaction->user->id;
            return ids;
        }

        // ── chat_boost — no user, chat only ──────────────────────────────────
        if (upd.chat_boost)
        {
            ids.chat_id = upd.chat_boost->chat->id;
            // user_id stays 0 — FSM state is tracked per chat
            return ids;
        }
        if (upd.removed_chat_boost)
        {
            ids.chat_id = upd.removed_chat_boost->chat->id;
            return ids;
        }

        // ── business_connection — use user_chat_id ────────────────────────────
        if (upd.business_connection)
        {
            ids.user_id = upd.business_connection->user->id;
            ids.chat_id = upd.business_connection->user_chat_id;
            return ids;
        }

        // ── purchased_paid_media ──────────────────────────────────────────────
        if (upd.purchased_paid_media)
        {
            ids.user_id = upd.purchased_paid_media->from->id;
            ids.chat_id = ids.user_id;
            return ids;
        }

        // ── managed_bot ───────────────────────────────────────────────────────
        if (upd.managed_bot)
        {
            ids.user_id = upd.managed_bot->user->id;
            ids.chat_id = ids.user_id;
            return ids;
        }

        return ids; // 0,0,0 — unknown update type
    }

    // ─────────────────────────────────────────────────────────────────────────
    //  make_fsm_middleware
    // ─────────────────────────────────────────────────────────────────────────
    inline corogram::MiddlewareFn make_fsm_middleware(
        std::shared_ptr<BaseStorage> storage)
    {
        return [storage](corogram::NextFn next, const corogram::Update &upd, corogram::Context &ctx)
                   -> drogon::Task<std::any>
        {
            auto ids = extract_ids(upd, ctx);

            StorageKey key{ids.bot_id, ids.chat_id, ids.user_id};
            auto fsm = std::make_shared<FSMContext>(storage, key);
            ctx.set<std::shared_ptr<FSMContext>>("fsm", fsm);

            co_return co_await next(upd, ctx);
        };
    }

} // namespace corogram::fsm