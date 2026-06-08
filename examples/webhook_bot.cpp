#include <corogram/corogram.hpp>
#include <cstdlib>
#include <iostream>

using namespace corogram;

static drogon::Task<bool> handle_start(const Update &upd, Context &ctx)
{
    auto *bot = ctx.get<Bot *>(ctx_keys::bot);
    co_await bot->api().sendMessage(upd.message->chat->id,
                                    "Hello from webhook! 🪝");
    co_return true;
}

static drogon::Task<bool> handle_echo(const Update &upd, Context &ctx)
{
    auto *bot = ctx.get<Bot *>(ctx_keys::bot);
    co_await bot->api().sendMessage(upd.message->chat->id,
                                    "Webhook echo: " + *upd.message->text);
    co_return true;
}

static drogon::Task<bool> handle_error(const ErrorEvent &ev, Context &)
{
    std::cerr << "[webhook error] " << ev.what() << "\n";
    co_return true;
}

int main()
{
    auto session = make_network();
    auto bot = std::make_shared<Bot>("YOUR_TOKEN_HERE", session);

    Dispatcher dp;
    dp.attach_bot(bot);
    dp.install_signal_handlers();

    dp.message().register_handler(handle_start, {F::Command("start")});
    dp.message().register_handler(handle_echo, {F::text()});
    dp.error().register_handler(handle_error);

    WebhookConfig cfg;
    cfg.url = "https://yourdomain.com/bot";
    cfg.path = "/bot";                     // must match the URL path above
    cfg.port = 8443;                       // Telegram allows: 443, 80, 88, 8443
    cfg.secret_token = "my_random_secret"; // always set in production
    cfg.max_connections = 100;
    cfg.drop_pending = true;
    cfg.allowed_updates = {"message", "callback_query", "inline_query"};

    // Optional: TLS handled directly by Drogon (omit if behind a terminating proxy)
    // cfg.ssl_cert_path = "/path/to/fullchain.pem";
    // cfg.ssl_key_path  = "/path/to/privkey.pem";

    // Optional: trust reverse proxy X-Forwarded-For header
    cfg.trust_forwarded_for = true;

    std::cout << "Starting webhook: " << cfg.url << "\n";

    // start_webhook() registers routes and calls setWebhook — non-blocking.
    // drogon::app().run() starts the event loop.
    dp.start_webhook(std::move(cfg));

    try
    {
        drogon::app().run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "[error] " << e.what() << "\n";
        return 1;
    }
}