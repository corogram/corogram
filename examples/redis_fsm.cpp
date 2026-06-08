#include <corogram/corogram.hpp>
#include <corogram/fsm/RedisStorage.hpp>
#include <iostream>
#include <drogon/drogon.h>

using namespace corogram;
using namespace corogram::fsm;

struct Form : StatesGroup<Form>
{
    static inline State step1 = state("step1");
    static inline State step2 = state("step2");
};

static FSMContext &fsm_of(Context &ctx)
{
    return *ctx.get<std::shared_ptr<FSMContext>>(ctx_keys::fsm);
}

int main()
{

    drogon::app().createRedisClient("127.0.0.1", 6379);

    auto session = make_network();
    auto bot = std::make_shared<Bot>("YOUR_TOKEN_HERE", session);
    auto storage = std::make_shared<RedisStorage>(86400, 86400);

    Dispatcher dp(storage);
    dp.attach_bot(bot);
    dp.install_signal_handlers();

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            co_await fsm_of(ctx).set_state(Form::step1.value());
            co_await bot->api().sendMessage(
                upd.message->chat->id,
                "Step 1: What is your name?");
            co_return true;
        },
        {F::Command("start")});

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            auto &fsm = fsm_of(ctx);
            co_await fsm.update_data({{"name", *upd.message->text}});
            co_await fsm.set_state(Form::step2.value());
            co_await bot->api().sendMessage(
                upd.message->chat->id, "Step 2: How old are you?");
            co_return true;
        },
        {F::State(Form::step1), F::text()});

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            auto &fsm = fsm_of(ctx);
            co_await fsm.update_data({{"age", *upd.message->text}});
            auto data = co_await fsm.get_data();
            co_await fsm.clear();
            co_await bot->api().sendMessage(
                upd.message->chat->id,
                "Done! Name=" + data["name"] + ", Age=" + data["age"]);
            co_return true;
        },
        {F::State(Form::step2), F::text()});

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            co_await fsm_of(ctx).clear();
            co_await bot->api().sendMessage(
                upd.message->chat->id, "Cancelled.");
            co_return true;
        },
        {F::CommandCancel()});

    try
    {
        drogon::app()
            .registerBeginningAdvice([&dp]()
                                     { drogon::async_run([&dp]
                                                         { return dp.start_polling(); }); })
            .run();
    }
    catch (const std::exception &e)
    {
        std::cerr << "[error] " << e.what() << "\n";
        return 1;
    }
}