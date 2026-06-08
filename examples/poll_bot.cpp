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

            auto make_option = [](std::string text)
            {
                auto opt = std::make_shared<InputPollOption>();
                opt->text = std::move(text);
                return opt;
            };

            API::SendPollArgs args;
            args.chat_id = upd.message->chat->id;
            args.question = "What is your favourite C++ feature?";
            args.options = {
                make_option("Coroutines (co_await)"),
                make_option("Concepts"),
                make_option("Ranges"),
                make_option("Modules"),
            };
            args.is_anonymous = false;
            args.type = "quiz";
            args.correct_option_ids = {0};
            args.explanation = "C++20 coroutines enable async code without callbacks!";

            co_await bot->api().sendPoll(std::move(args));
            co_return true;
        },
        {F::Command("poll")});

    dp.poll_answer().register_handler(
        [](const Update &upd, Context &) -> drogon::Task<bool>
        {
            const auto &answer = *upd.poll_answer;
            if (!answer.user)
                co_return true;

            std::string options;
            for (int64_t idx : answer.option_ids)
                options += std::to_string(idx) + " ";

            std::cout << "User " << answer.user->id
                      << " voted: [" << options << "]\n";
            co_return true;
        });

    dp.poll().register_handler(
        [](const Update &upd, Context &) -> drogon::Task<bool>
        {
            const auto &poll = *upd.poll;
            std::cout << "Poll " << poll.id
                      << " total_voter_count=" << poll.total_voter_count << "\n";
            co_return true;
        });

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