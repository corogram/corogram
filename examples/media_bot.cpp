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

            API::SendPhotoArgs args;
            args.chat_id = upd.message->chat->id;
            args.photo = std::string("https://picsum.photos/seed/corogram/800/600");
            args.caption = "📷 Photo from URL";
            args.parse_mode = "HTML";
            co_await bot->api().sendPhoto(std::move(args));
            co_return true;
        },
        {F::Command("photo_url")});

    // ── /photo_file ───────────────────────────────────────────────────────────
    // Send a photo by uploading a local file.
    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);

            auto file = InputFile::from_file("media/photo.png", "photo.jpg", "image/jpeg");

            API::SendPhotoArgs args;
            args.chat_id = upd.message->chat->id;
            args.photo = file;
            args.caption = "📁 Photo from disk";
            co_await bot->api().sendPhoto(std::move(args));
            co_return true;
        },
        {F::Command("photo_file")});

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);

            auto file = InputFile::from_file("media/report.pdf", "report.pdf", "application/pdf");

            API::SendDocumentArgs args;
            args.chat_id = upd.message->chat->id;
            args.document = file;
            args.caption = "📄 Here is your report.";
            co_await bot->api().sendDocument(std::move(args));
            co_return true;
        },
        {F::Command("doc")});

    dp.message().register_handler(
        [](const Update &upd, Context &ctx) -> drogon::Task<bool>
        {
            auto *bot = ctx.get<Bot *>(ctx_keys::bot);

            auto make_photo = [](const std::string &url, const std::string &caption = "")
            {
                auto p = std::make_shared<InputMediaPhoto>();
                p->type = "photo";
                p->media = url;
                if (!caption.empty())
                    p->caption = caption;
                return p;
            };

            API::SendMediaGroupArgs args;
            args.chat_id = upd.message->chat->id;
            args.media = {
                make_photo("https://picsum.photos/seed/a/800/600", "First photo"),
                make_photo("https://picsum.photos/seed/b/800/600"),
                make_photo("https://picsum.photos/seed/c/800/600"),
            };
            co_await bot->api().sendMediaGroup(std::move(args));
            co_return true;
        },
        {F::Command("album")});

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