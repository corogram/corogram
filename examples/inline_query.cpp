#include <corogram/corogram.hpp>
#include <cstdlib>

using namespace corogram;

int main()
{
    auto session = make_network();
    auto bot = std::make_shared<Bot>("YOUR_TOKEN_HERE", session);
    Dispatcher dp;

    dp.inline_query().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            auto &query = *upd.inline_query;
            const std::string &q = query.query;

            auto make_article = [](std::string id, std::string title, std::string text)
                -> InlineQueryResult
            {
                auto content = std::make_shared<InputTextMessageContent>();
                content->message_text = std::move(text);

                auto r = std::make_shared<InlineQueryResultArticle>();
                r->type = "article";
                r->id = std::move(id);
                r->title = std::move(title);
                r->input_message_content = content;
                return r;
            };

            std::vector<InlineQueryResult> results;

            if (q.empty() || q == "help")
            {
                results.push_back(make_article(
                    "help", "📖 Help", "Use @bot <query> to search."));
            }
            else
            {
                results.push_back(make_article(
                    "result1",
                    "Result for: " + q,
                    "You searched for: " + q));
                results.push_back(make_article(
                    "result2",
                    "Alternative: " + q + " (alt)",
                    "Alternative result for: " + q));
            }

            API::AnswerInlineQueryArgs ans;
            ans.inline_query_id = query.id;
            ans.results = std::move(results);
            ans.cache_time = 60;
            ans.is_personal = true;

            co_await bot->api().answerInlineQuery(std::move(ans));
            co_return true;
        });

    dp.attach_bot(bot);
    dp.install_signal_handlers();

    drogon::async_run([&dp]
                      { return dp.start_polling(); });
    drogon::app().run();
}