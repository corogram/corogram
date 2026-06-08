#include <corogram/corogram.hpp>
#include <iostream>
#include <unordered_map>
#include <drogon/drogon.h>

using namespace corogram;

static const std::unordered_map<std::string, std::string> menu = {
    {"pizza", "🍕 One pizza coming up!"},
    {"burger", "🍔 Burger on the grill!"},
    {"sushi", "🍣 Sushi chef is preparing your order."},
    {"taco", "🌮 Taco time!"},
    {"salad", "🥗 Fresh salad incoming!"},
    {"ramen", "🍜 Ramen will be ready in 5 minutes."},
};

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

            auto kb = InlineKeyboardBuilder{}
                          .button("🍕 Pizza", "order:pizza")
                          .button("🍔 Burger", "order:burger")
                          .button("🍣 Sushi", "order:sushi")
                          .button("🌮 Taco", "order:taco")
                          .button("🥗 Salad", "order:salad")
                          .button("🍜 Ramen", "order:ramen")
                          .adjust(2)
                          .url_button("📖 Full menu", "https://example.com/menu")
                          .as_markup();

            API::SendMessageArgs args;
            args.chat_id = upd.message->chat->id;
            args.text = "🍽️ What would you like to order?";
            args.reply_markup = kb;

            co_await bot->api().sendMessage(std::move(args));
            co_return true;
        },
        {F::Command("start")});

    dp.callback_query().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);
            const auto &cq = *upd.callback_query;
            const std::string item = cq.data->substr(6);

            const std::string reply = menu.count(item) ? menu.at(item) : "Unknown item.";

            co_await bot->api().answerCallbackQuery(cq.id, reply);

            if (cq.message.has_value())
            {
                if (auto *mp = std::get_if<std::shared_ptr<Message>>(&*cq.message))
                {
                    API::EditMessageTextArgs edit;
                    edit.chat_id = (*mp)->chat->id;
                    edit.message_id = (*mp)->message_id;
                    edit.text = "✅ " + reply;
                    co_await bot->api().editMessageText(std::move(edit));
                }
            }

            co_return true;
        },
        {F::callback_data_prefix("order:")});

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