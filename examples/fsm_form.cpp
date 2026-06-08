#include <corogram/corogram.hpp>
#include <iostream>
#include <sstream>
#include <drogon/drogon.h>

using namespace corogram;
using namespace corogram::fsm;

struct RegistrationForm : StatesGroup<RegistrationForm>
{
    static inline State waiting_name = state("waiting_name");
    static inline State waiting_age = state("waiting_age");
    static inline State waiting_email = state("waiting_email");
    static inline State confirming = state("confirming");
};

static FSMContext &fsm_of(Context &ctx)
{
    return *ctx.get<std::shared_ptr<FSMContext>>(ctx_keys::fsm);
}

int main()
{
    auto session = make_network();
    auto bot = std::make_shared<Bot>("YOUR_TOKEN_HERE", session);
    auto storage = std::make_shared<MemoryStorage>();

    Dispatcher dp(storage);
    dp.attach_bot(bot);
    dp.install_signal_handlers();

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            co_await fsm_of(ctx).set_state(RegistrationForm::waiting_name.value());
            co_await bot->api().sendMessage(
                upd.message->chat->id,
                "Registration started!\n\nStep 1/3 — What is your name?\n(/cancel to abort)");
            co_return true;
        },
        {F::Command("register")});

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            co_await fsm_of(ctx).clear();
            co_await bot->api().sendMessage(
                upd.message->chat->id, "❌ Registration cancelled.");
            co_return true;
        },
        {F::Command("cancel"), F::AnyState()});

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            auto &fsm = fsm_of(ctx);
            co_await fsm.update_data({{"name", *upd.message->text}});
            co_await fsm.set_state(RegistrationForm::waiting_age.value());
            co_await bot->api().sendMessage(
                upd.message->chat->id,
                "✅ Name saved!\n\nStep 2/3 — How old are you? (numbers only)");
            co_return true;
        },
        {F::State(RegistrationForm::waiting_name), F::text()});

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            const std::string &text = *upd.message->text;
            int age = 0;
            bool parse_failed = false;
            try
            {
                age = std::stoi(text);
            }
            catch (...)
            {
                parse_failed = true;
            }

            if (parse_failed)
            {
                co_await bot->api().sendMessage(
                    upd.message->chat->id, "⚠️ Please send a number.");
                co_return true;
            }
            if (age < 1 || age > 150)
            {
                co_await bot->api().sendMessage(
                    upd.message->chat->id, "⚠️ Please enter a valid age (1–150).");
                co_return true;
            }
            auto &fsm = fsm_of(ctx);
            co_await fsm.update_data({{"age", text}});
            co_await fsm.set_state(RegistrationForm::waiting_email.value());
            co_await bot->api().sendMessage(
                upd.message->chat->id,
                "✅ Age saved!\n\nStep 3/3 — What is your email address?");
            co_return true;
        },
        {F::State(RegistrationForm::waiting_age), F::text()});

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            auto &fsm = fsm_of(ctx);
            co_await fsm.update_data({{"email", *upd.message->text}});

            auto data = co_await fsm.get_data();
            co_await fsm.set_state(RegistrationForm::confirming.value());

            std::ostringstream ss;
            ss << "✅ Email saved!\n\n"
               << "📋 Please confirm your details:\n\n"
               << "👤 Name:  " << data["name"] << "\n"
               << "🎂 Age:   " << data["age"] << "\n"
               << "📧 Email: " << data["email"] << "\n\n"
               << "Send /confirm to submit or /cancel to abort.";

            co_await bot->api().sendMessage(upd.message->chat->id, ss.str());
            co_return true;
        },
        {F::State(RegistrationForm::waiting_email), F::text()});

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            auto &fsm = fsm_of(ctx);
            auto data = co_await fsm.get_data();
            co_await fsm.clear();
            co_await bot->api().sendMessage(
                upd.message->chat->id,
                "🎉 Registration complete!\nWelcome, " + data["name"] + "!");
            co_return true;
        },
        {F::State(RegistrationForm::confirming), F::Command("confirm")});

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