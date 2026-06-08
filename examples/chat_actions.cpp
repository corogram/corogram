#include <corogram/corogram.hpp>
#include <iostream>
#include <drogon/drogon.h>

using namespace corogram;

int main()
{
    auto session = make_network();
    auto bot = std::make_shared<Bot>("YOUR_TOKEN_HERE", session);

    Dispatcher dp;
    dp.attach_bot(bot);
    dp.install_signal_handlers();

    // ── /slow ─────────────────────────────────────────────────────────────────
    // Show "typing…" for 2 seconds, then send a reply.
    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            int64_t chat_id = upd.message->chat->id;

            co_await bot->api().sendChatAction(chat_id, "typing");

            // Simulate slow processing
            co_await drogon::sleepCoro(drogon::app().getIOLoop(0), std::chrono::seconds(2));

            co_await bot->api().sendMessage(chat_id, "⌛ Done thinking!");
            co_return true;
        },
        {F::Command("slow")});

    // ── /edit ─────────────────────────────────────────────────────────────────
    // Send a placeholder, then replace it with the real content.
    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            int64_t chat_id = upd.message->chat->id;

            auto sent = co_await bot->api().sendMessage(chat_id, "⏳ Loading…");

            co_await drogon::sleepCoro(drogon::app().getIOLoop(0), std::chrono::seconds(2));

            API::EditMessageTextArgs edit;
            edit.chat_id = chat_id;
            edit.message_id = sent->message_id;
            edit.text = "✅ Done! Message edited.";
            co_await bot->api().editMessageText(std::move(edit));
            co_return true;
        },
        {F::Command("edit")});

    // ── /delete ───────────────────────────────────────────────────────────────
    // Send a message and delete it after 3 seconds.
    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            int64_t chat_id = upd.message->chat->id;

            auto sent = co_await bot->api().sendMessage(chat_id, "💣 This message will self-destruct in 3s…");

            co_await drogon::sleepCoro(drogon::app().getIOLoop(0), std::chrono::seconds(3));

            co_await bot->api().deleteMessage(chat_id, sent->message_id);
            co_return true;
        },
        {F::Command("delete")});

    // ── /pin ──────────────────────────────────────────────────────────────────
    // Pin the command message in the chat (bot must be admin).
    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);

            API::PinChatMessageArgs args;
            args.chat_id = upd.message->chat->id;
            args.message_id = upd.message->message_id;
            args.disable_notification = true;
            bool ok = co_await bot->api().pinChatMessage(std::move(args));
            co_await bot->api().sendMessage(
                upd.message->chat->id,
                ok ? "📌 Message pinned." : "❌ Failed to pin (am I an admin?)");
            co_return true;
        },
        {F::Command("pin")});

    try
    {
        drogon::async_run([&dp]
                          { return dp.start_polling(); });
        drogon::app().run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "[error] " << e.what() << "\n";
        return 1;
    }
}