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

std::shared_ptr<Router> make_public_router()
{
    auto r = std::make_shared<Router>();

    r->message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            co_return co_await send_text(bot, upd.message->chat->id,
                                         "👋 Welcome!\n\n"
                                         "📢 Public commands:\n"
                                         "  /start — show this message\n"
                                         "  /help  — command list\n"
                                         "  /ping  — latency check\n\n"
                                         "🔒 Admin commands:\n"
                                         "  /stats     — usage statistics\n"
                                         "  /broadcast — send a message to all users\n\n"
                                         "💬 Private chat only:\n"
                                         "  /subscribe   — subscribe to updates\n"
                                         "  /unsubscribe — unsubscribe");
        },
        {F::Command("start")});

    r->message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            co_return co_await send_text(bot, upd.message->chat->id,
                                         "/start — greeting\n"
                                         "/help  — this message\n"
                                         "/ping  — latency check");
        },
        {F::CommandHelp()});

    r->message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            co_return co_await send_text(bot, upd.message->chat->id, "🏓 Pong!");
        },
        {F::Command("ping")});

    r->on_startup([]() -> drogon::Task<void>
                  {
        std::cout << "[PublicRouter] ready\n";
        co_return; });

    return r;
}

std::shared_ptr<Router> make_admin_router(int64_t admin_id)
{
    auto r = std::make_shared<Router>();

    r->message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            co_return co_await send_text(bot, upd.message->chat->id,
                                         "📊 Stats:\nUsers: 1337\nMsgs today: 2048");
        },
        {F::Command("stats"), F::from_user(admin_id)});

    r->message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            auto &cmd = ctx.get<CommandObject>("command");
            if (!cmd.args.has_value())
                co_return co_await send_text(bot, upd.message->chat->id,
                                             "Usage: /broadcast <message>");
            co_return co_await send_text(bot, upd.message->chat->id,
                                         "📢 Broadcasting: " + *cmd.args);
        },
        {F::Command("broadcast"), F::from_user(admin_id)});

    return r;
}

std::shared_ptr<Router> make_pm_router()
{
    auto r = std::make_shared<Router>();

    r->message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            co_return co_await send_text(bot, upd.message->chat->id, "✅ Subscribed!");
        },
        {F::Command("subscribe")});

    r->message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            co_return co_await send_text(bot, upd.message->chat->id, "❌ Unsubscribed.");
        },
        {F::Command("unsubscribe")});

    return r;
}

int main()
{
    const int64_t admin_id = 123456789; // replace your id
    auto session = make_network();
    auto bot = std::make_shared<Bot>("YOUR_TOKEN_HERE", session);
    Dispatcher dp;

    dp.include_router(make_public_router());
    dp.include_router(make_admin_router(admin_id));
    dp.include_router(make_pm_router(), {F::private_chat()});

    dp.on_startup([]() -> drogon::Task<void>
                  {
        std::cout << "[Dispatcher] Bot started.\n";
        co_return; });

    dp.on_shutdown([]() -> drogon::Task<void>
                   {
        std::cout << "[Dispatcher] Shutting down.\n";
        co_return; });

    dp.attach_bot(bot);
    dp.install_signal_handlers();
    try
    {
        drogon::async_run([&dp]
                          { return dp.start_polling(); });
        drogon::app().run();
    }
    catch (std::exception &err)
    {
        std::cout << "[Error] --" << err.what();
    }
}