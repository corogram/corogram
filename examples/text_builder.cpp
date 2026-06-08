// TextBuilder.hpp must be included BEFORE corogram.hpp on MSVC
#include <corogram/utils/TextBuilder.hpp>
#include <corogram/corogram.hpp>
#include <iostream>
#include <drogon/drogon.h>

using namespace corogram;
using namespace corogram::fmt;

// ── /html ────────────────────────────────────────────────────────────────────
static drogon::Task<bool> handle_html(const Update &upd, Context &ctx)
{
    auto *bot = ctx.get<Bot *>(ctx_keys::bot);

    TextBuilder tb;
    tb.bold("corogram TextBuilder").newline(2).add("Normal • ").italic("italic • ").underline("underline • ").strikethrough("strike").newline().code("auto result = co_await api.sendMessage(args);").newline().pre("def hello():\n    return 42", "python").newline().link("Telegram Bot API", "https://core.telegram.org/bots/api").newline().spoiler("This is hidden until tapped");

    API::SendMessageArgs args;
    args.chat_id = upd.message->chat->id;
    args.text = tb.as_html();
    args.parse_mode = "HTML";
    co_await bot->api().sendMessage(std::move(args));
    co_return true;
}

// ── /md ──────────────────────────────────────────────────────────────────────
static drogon::Task<bool> handle_md(const Update &upd, Context &ctx)
{
    auto *bot = ctx.get<Bot *>(ctx_keys::bot);

    TextBuilder tb;
    tb.bold("Bold title").newline().italic("Italic subtitle").newline().code("inline code").newline().link("Docs", "https://core.telegram.org/bots");

    API::SendMessageArgs args;
    args.chat_id = upd.message->chat->id;
    args.text = tb.as_markdown();
    args.parse_mode = "MarkdownV2";
    co_await bot->api().sendMessage(std::move(args));
    co_return true;
}

// ── /status ───────────────────────────────────────────────────────────────────
// as_send_args() returns a struct with .text and .entities — no structured binding needed.
static drogon::Task<bool> handle_status(const Update &upd, Context &ctx)
{
    auto *bot = ctx.get<Bot *>(ctx_keys::bot);

    TextBuilder tb;
    tb.bold("🖥️ Server Status").newline().separator().key_value("CPU", "12%").newline().key_value("Memory", "2.1 GB / 8 GB").newline().key_value("Disk", "45 GB free").newline().key_value("Uptime", "7d 14h 22m");

    TextBuilder::SendArgs sa = tb.as_send_args();

    API::SendMessageArgs args;
    args.chat_id = upd.message->chat->id;
    args.text = std::move(sa.text);
    args.entities = std::move(sa.entities);
    co_await bot->api().sendMessage(std::move(args));
    co_return true;
}

// ── /list ─────────────────────────────────────────────────────────────────────
// Builds a node tree manually and sends it via native entities.
static drogon::Task<bool> handle_list(const Update &upd, Context &ctx)
{
    auto *bot = ctx.get<Bot *>(ctx_keys::bot);

    NodePtr list = as_marked_list(
        {
            Text("Buy groceries"),
            combine({std::make_shared<Bold>("Call"), Text(" Alice")}),
            Text("Review pull requests"),
            Text("Deploy to production"),
        },
        "• ");

    NodePtr root = combine({
        std::make_shared<Bold>("📝 Todo list:\n"),
        list,
    });

    Node::RenderResult res = root->render();

    API::SendMessageArgs args;
    args.chat_id = upd.message->chat->id;
    args.text = std::move(res.text);
    args.entities = std::move(res.entities);
    co_await bot->api().sendMessage(std::move(args));
    co_return true;
}

int main()
{
    auto session = make_network();
    auto bot = std::make_shared<Bot>("YOUR_TOKEN_HERE", session);

    Dispatcher dp;
    dp.attach_bot(bot);
    dp.install_signal_handlers();

    dp.message().register_handler(handle_html, {F::Command("html")});
    dp.message().register_handler(handle_md, {F::Command("md")});
    dp.message().register_handler(handle_status, {F::Command("status")});
    dp.message().register_handler(handle_list, {F::Command("list")});

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