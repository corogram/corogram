#include <corogram/corogram.hpp>
#include <cstdlib>
#include <iostream>

using namespace corogram;

static drogon::Task<bool> send_text(Bot *bot, int64_t chat_id, std::string text)
{
    API::SendMessageArgs args;
    args.chat_id = chat_id;
    args.text = std::move(text);
    co_await bot->api().sendMessage(std::move(args));
    co_return true;
}

static drogon::Task<std::string> try_send_bad_request(Bot *bot)
{
    try
    {
        API::SendMessageArgs args;
        args.chat_id = -99999999;
        args.text = "This will fail.";
        co_await bot->api().sendMessage(std::move(args));
        co_return "";
    }
    catch (const TelegramBadRequest &e)
    {
        co_return "Caught BadRequest: " + std::string(e.what());
    }
}

int main()
{
    auto session = make_network();
    auto bot = std::make_shared<Bot>("YOUR_TOKEN_HERE", session);

    loggers::set_level(LogLevel::Debug);

    Dispatcher dp;

    dp.message().register_handler(
        [](const Update &, Context &) -> drogon::Task<bool>
        {
            throw std::runtime_error("Intentional crash!");
            co_return true;
        },
        {F::Command("crash")});

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            auto msg = co_await try_send_bad_request(bot);
            if (!msg.empty())
                co_await send_text(bot, upd.message->chat->id, msg);
            co_return true;
        },
        {F::Command("badrequest")});

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            co_await send_text(bot, upd.message->chat->id,
                               "Flood wait: 5s");
            co_return true;
        },
        {F::Command("retry")});

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            co_await send_text(bot, upd.message->chat->id,
                               "Error demo:\n/crash /badrequest /retry");
            co_return true;
        },
        {F::Command("start")});

    dp.error().register_handler(
        [](const ErrorEvent &ev, Context &ctx) -> drogon::Task<bool>
        {
            loggers::dispatcher.exception("Handler error", ev.exception);

            auto *bot_ptr = ctx.get_if<Bot *>(ctx_keys::bot);
            auto *upd_ptr = ctx.get_if<const Update *>(ctx_keys::update);

            if (bot_ptr && upd_ptr && (*upd_ptr)->message)
            {
                try
                {
                    co_await send_text(*bot_ptr, (*upd_ptr)->message->chat->id,
                                       "An internal error occurred. Please try again.");
                }
                catch (...)
                {
                }
            }

            co_return true;
        });

    dp.attach_bot(bot);
    dp.install_signal_handlers();

    drogon::async_run([&dp]
                      { return dp.start_polling(); });
    drogon::app().run();
}