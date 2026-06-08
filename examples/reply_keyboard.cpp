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

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);

            auto kb2 = ReplyKeyboardBuilder{}
                           .button("⬆️ Up")
                           .button("⬇️ Down")
                           .button("⬅️ Left")
                           .button("➡️ Right")
                           .button("❌ Close")
                           .adjust(2)
                           .as_markup();

            API::SendMessageArgs args2;
            args2.chat_id = upd.message->chat->id;
            args2.text = "Pick a direction:";
            args2.reply_markup = kb2;
            co_await bot->api().sendMessage(std::move(args2));

            co_return true;
        },
        {F::Command("start")});

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);

            API::SendMessageArgs args;
            args.chat_id = upd.message->chat->id;
            args.text = "Keyboard closed.";
            args.reply_markup = remove_keyboard();
            co_await bot->api().sendMessage(std::move(args));

            co_return true;
        },
        {F::text("❌ Close")});

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            co_await bot->api().sendMessage(
                upd.message->chat->id,
                "You picked: " + *upd.message->text);
            co_return true;
        },
        {F::text()});

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