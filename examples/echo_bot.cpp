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
            const auto &from = *upd.message->from;
            co_await bot->api().sendMessage(
                upd.message->chat->id,
                "Hello, " + from.first_name + "! Send me any text.");
            co_return true;
        },
        {F::Command("start")});

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            co_await bot->api().sendMessage(
                upd.message->chat->id,
                *upd.message->text);
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