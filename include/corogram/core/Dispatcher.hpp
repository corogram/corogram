// include/core/Dispatcher.hpp
#pragma once
#include <any>
#include <atomic>
#include <chrono>
#include <csignal>
#include <memory>
#include <string>
#include <unordered_map>
#include <vector>

#include <drogon/drogon.h>

#include <corogram/core/Router.hpp>
#include <corogram/core/Middleware.hpp>
#include <corogram/core/middlewares/ErrorMiddleware.hpp>
#include <corogram/core/middlewares/UserContextMiddleware.hpp>
#include <corogram/network/RequestMiddleware.hpp>
#include <corogram/Types.hpp>
#include <corogram/Methods.hpp>
#include <corogram/Logger.hpp>
#include <corogram/network/WebhookServer.hpp>
#include <corogram/fsm/FSMMiddleware.hpp>
#include <corogram/fsm/BaseStorage.hpp>

namespace corogram::ctx_keys
{
    inline constexpr auto bot = "bot";
    inline constexpr auto update = "update";
    inline constexpr auto fsm = "fsm";
}

namespace corogram
{

    struct PollingConfig
    {
        BackoffConfig backoff = {};
        int timeout = 30;
        bool sequential = true;
        int max_concurrent = 10;
        std::optional<int> limit = std::nullopt; // getUpdates limit (1-100)
        std::vector<std::string> allowed_updates = {
            "message", "edited_message", "channel_post", "edited_channel_post",
            "inline_query", "chosen_inline_result", "callback_query",
            "shipping_query", "pre_checkout_query", "poll", "poll_answer",
            "my_chat_member", "chat_member", "chat_join_request",
            "message_reaction", "message_reaction_count", "chat_boost",
            "removed_chat_boost", "business_connection", "business_message",
            "edited_business_message", "deleted_business_messages",
            "purchased_paid_media", "managed_bot"};
    };

    class Dispatcher : public Router
    {
        std::vector<std::shared_ptr<Bot>> bots_;
        std::vector<MiddlewareFn> outer_middlewares_;
        std::atomic<bool> running_{false};
        std::atomic<int> inflight_{0};
        PollingConfig polling_config_;
        std::unique_ptr<WebhookServer> server_;
        std::unordered_map<std::string, std::any> global_data_;
        std::shared_ptr<corogram::fsm::BaseStorage> storage_;

        enum class RunMode
        {
            None,
            Polling,
            Webhook
        };
        std::atomic<RunMode> active_mode_{RunMode::None};

        // Signal handling — one global instance per process.
        // install_signal_handlers() sets this so the handler can call stop().
        inline static std::atomic<Dispatcher *> signal_instance_{nullptr};

    public:
        explicit Dispatcher(std::shared_ptr<corogram::fsm::BaseStorage> storage = nullptr)
        {
            outer_middlewares_.push_back(make_error_middleware(this));
            outer_middlewares_.push_back(make_user_context_middleware());
            if (storage)
            {
                storage_ = std::move(storage);
                outer_middlewares_.push_back(corogram::fsm::make_fsm_middleware(storage_));
            }
        }

        /// Returns the FSM storage, or nullptr if FSM is disabled.
        std::shared_ptr<corogram::fsm::BaseStorage> storage() const noexcept { return storage_; }
        bool fsm_enabled() const noexcept { return storage_ != nullptr; }

        void set_polling_config(PollingConfig cfg) { polling_config_ = std::move(cfg); }

        // =====================================================================
        //  Signal handling — graceful shutdown on SIGINT / SIGTERM
        //
        //  Call once after constructing the Dispatcher, before start_polling()
        //  or start_webhook(). On SIGINT/SIGTERM:
        //    1. running_ → false  (stops the polling loop after current update)
        //    2. storage_->close() (flushes Redis pipeline, closes connections)
        //    3. drogon::app().quit() (stops the event loop)
        //
        //  Only one Dispatcher instance may install signal handlers per process.
        //  A second call overwrites the previous registration (last-wins).
        //
        //  Usage:
        //    Dispatcher dp(storage);
        //    dp.install_signal_handlers();
        //    dp.attach_bot(bot);
        //    drogon::async_run([&dp]{ return dp.start_polling(); });
        //    drogon::app().run();
        // =====================================================================

        void install_signal_handlers()
        {
            signal_instance_.store(this);

            auto handler = [](int sig) noexcept
            {
                // Signal handlers must be async-signal-safe.
                // We only touch atomics and call async-signal-safe functions here.
                auto *dp = signal_instance_.load();
                if (!dp)
                    return;

                // 1. Stop the polling / webhook loop.
                dp->running_.store(false);

                // 2. Schedule storage close + app quit on the event loop.
                //    trantor::EventLoop::runInLoop is async-signal-safe
                //    (it writes to a pipe internally).
                auto *loop = trantor::EventLoop::getEventLoopOfCurrentThread();
                if (!loop)
                    loop = drogon::app().getLoop();

                if (loop)
                {
                    loop->runInLoop([dp]()
                                    {
                        // Close storage (flushes Redis, etc.) then quit.
                        if (dp->storage_)
                        {
                            drogon::async_run([dp]() -> drogon::Task<void>
                            {
                                try { co_await dp->storage_->close(); }
                                catch (...) {}
                                drogon::app().quit();
                            });
                        }
                        else
                        {
                            drogon::app().quit();
                        } });
                }
            };

            std::signal(SIGINT, handler);
            std::signal(SIGTERM, handler);

            loggers::dispatcher.debug("Signal handlers installed (SIGINT, SIGTERM)");
        }

        void attach_bot(std::shared_ptr<Bot> bot) { bots_.push_back(std::move(bot)); }

        void middleware(MiddlewareFn mw) { outer_middlewares_.push_back(std::move(mw)); }

        // =====================================================================
        //  Global data (workflow_data equivalent)
        //
        //  Dispatcher-wide constants — DB sessions, config objects, etc.
        //  Automatically copied into Context on every feed_update() call.
        //
        //  Usage:
        //    dp.set_global("db", std::make_shared<MyDB>("conn"));
        //
        //  Inside a handler:
        //    auto db = ctx.get<std::shared_ptr<MyDB>>("db");
        // =====================================================================

        template <typename T>
        void set_global(std::string_view key, T value)
        {
            global_data_.insert_or_assign(std::string(key), std::any(std::move(value)));
        }

        template <typename T>
        T &get_global(std::string_view key)
        {
            auto it = global_data_.find(std::string(key));
            if (it == global_data_.end())
                throw std::out_of_range("global_data key not found: " + std::string(key));
            return std::any_cast<T &>(it->second);
        }

        void erase_global(std::string_view key) { global_data_.erase(std::string(key)); }

        bool has_global(std::string_view key) const
        {
            return global_data_.count(std::string(key)) > 0;
        }

        // =====================================================================
        //  feed_update — shared entry point for polling and webhook
        //
        //  outer_middlewares_ are not wrapped here directly; they are passed
        //  through propagate_event → Observer::trigger so that outer middleware
        //  runs before each observer's filters — the correct execution order.
        // =====================================================================

        drogon::Task<void> feed_update(std::shared_ptr<Bot> bot, Update upd)
        {
            Context ctx;
            ctx.set<Bot *>(ctx_keys::bot, bot.get());
            ctx.set<const Update *>(ctx_keys::update, &upd);

            for (const auto &[key, val] : global_data_)
                ctx.set_any(key, val);

            co_await _listen_update(upd, ctx);
        }

        // =====================================================================
        //  Polling
        // =====================================================================

        drogon::Task<void> start_polling()
        {
            if (bots_.empty())
                throw std::runtime_error("No bots attached. Call attach_bot() first.");

            RunMode expected = RunMode::None;
            if (!active_mode_.compare_exchange_strong(expected, RunMode::Polling))
                throw std::runtime_error(
                    active_mode_.load() == RunMode::Webhook
                        ? "Cannot start polling: webhook is already running."
                        : "Polling is already running.");

            for (auto &bot : bots_)
            {
                try
                {
                    auto me = co_await bot->me();
                    loggers::dispatcher.info(
                        "Authorized as @" +
                        me->username.value_or(std::to_string(me->id)));
                }
                catch (const corogram::TelegramUnauthorizedError &e)
                {
                    active_mode_.store(RunMode::None);
                    loggers::dispatcher.error(
                        std::string("Invalid bot token: ") + e.what());
                    throw;
                }
                catch (const corogram::TelegramForbiddenError &e)
                {
                    active_mode_.store(RunMode::None);
                    loggers::dispatcher.error(
                        std::string("Bot is forbidden (banned or deactivated?): ") + e.what());
                    throw;
                }
                catch (const std::exception &e)
                {
                    active_mode_.store(RunMode::None);
                    loggers::dispatcher.error(
                        std::string("Failed to connect to Telegram: ") + e.what());
                    throw;
                }
            }

            running_ = true;
            co_await emit_startup();

            std::vector<drogon::Task<void>> tasks;
            for (auto &bot : bots_)
                tasks.push_back(_polling(bot));

            for (auto &t : tasks)
                co_await std::move(t);

            active_mode_.store(RunMode::None);
            co_await emit_shutdown();
        }

        void stop_polling()
        {
            running_ = false;
            active_mode_.store(RunMode::None);
        }

        // =====================================================================
        //  Webhook
        //
        //  Usage:
        //    corogram::WebhookConfig cfg;
        //    cfg.url          = "https://yourdomain.com/webhook/mysecret";
        //    cfg.path         = "/webhook/mysecret";
        //    cfg.port         = 8443;
        //    cfg.secret_token = "mysecret";
        //    dp.start_webhook(cfg);
        //    drogon::app().run();  // blocking — call from main()
        //
        //  start_webhook() is non-blocking. It registers Drogon routes and
        //  listeners and calls setWebhook. The actual event loop is started
        //  by drogon::app().run() in main().
        // =====================================================================

        void start_webhook(WebhookConfig cfg)
        {
            if (bots_.empty())
                throw std::runtime_error("No bots attached. Call attach_bot() first.");

            RunMode expected = RunMode::None;
            if (!active_mode_.compare_exchange_strong(expected, RunMode::Webhook))
                throw std::runtime_error(
                    active_mode_.load() == RunMode::Polling
                        ? "Cannot start webhook: polling is already running."
                        : "Webhook is already running.");

            running_ = true;
            auto bot_ptr = bots_[0];

            corogram::API::SetWebhookArgs args;
            args.url = cfg.url;
            if (cfg.max_connections > 0)
                args.max_connections = cfg.max_connections;
            if (!cfg.allowed_updates.empty())
                args.allowed_updates = cfg.allowed_updates;
            if (cfg.drop_pending)
                args.drop_pending_updates = true;
            if (!cfg.secret_token.empty())
                args.secret_token = cfg.secret_token;

            drogon::async_run([bot_ptr, args = std::move(args)]() mutable
                                  -> drogon::Task<void>
                              {
                    try
                        {
                            bool ok = co_await bot_ptr->api().setWebhook(std::move(args));
                            if (ok)
                                loggers::webhook.info("setWebhook succeeded");
                            else
                                loggers::webhook.error("setWebhook failed");
                        }
                        catch (const std::exception &e)
                        {
                            loggers::webhook.error("setWebhook exception: " + std::string(e.what()));
                        }
                        catch (...)
                        {
                            loggers::webhook.error("setWebhook unknown exception");
                        } });                                                

            auto cb = [this, bot_ptr](std::shared_ptr<Update> upd)
                -> drogon::Task<void>
            {
                co_await _process_update(bot_ptr, std::move(*upd));
            };

            server_ = std::make_unique<WebhookServer>(std::move(cfg), std::move(cb));
            server_->configure_app();
            server_->register_routes();

            drogon::async_run([this]() -> drogon::Task<void>
                              { co_await emit_startup(); });
        }

        /// Removes the webhook and emits shutdown callbacks.
        void stop_webhook()
        {
            if (bots_.empty())
                return;
            running_ = false;
            active_mode_.store(RunMode::None);

            auto bot_ptr = bots_[0];
            drogon::async_run([bot_ptr]() -> drogon::Task<void>
                              {
                corogram::API::DeleteWebhookArgs args;
                args.drop_pending_updates = false;
                co_await bot_ptr->api().deleteWebhook(std::move(args));
                loggers::webhook.info("deleteWebhook succeeded"); });

            drogon::async_run([this]() -> drogon::Task<void>
                              { co_await emit_shutdown(); });
        }

    private:
        drogon::Task<bool> _listen_update(const Update &upd, Context &ctx)
        {
            std::string_view update_type;
            try
            {
                update_type = upd.event_type();
            }
            catch (const std::exception &e)
            {
                loggers::dispatcher.warning(
                    std::string("Unknown update type: ") + e.what());
                co_return false;
            }
            co_return co_await propagate_event(update_type, upd, ctx, outer_middlewares_);
        }

        drogon::Task<void> _process_update(std::shared_ptr<Bot> bot, Update upd)
        {
            std::exception_ptr eptr;

            try
            {
                co_await feed_update(bot, std::move(upd));
                co_return;
            }
            catch (...)
            {
                eptr = std::current_exception();
            }

            Context ctx;
            ctx.set<Bot *>(ctx_keys::bot, bot.get());
            ctx.set<const Update *>(ctx_keys::update, &upd);
            for (const auto &[key, val] : global_data_)
                ctx.set_any(key, val);

            ErrorEvent ev{upd, eptr};
            if (!co_await propagate_error(ev, ctx))
                loggers::middlewares.error(
                    "Unhandled exception in update " +
                    std::to_string(upd.update_id) + ": " + ev.what());
        }

        drogon::Task<void> _polling(std::shared_ptr<Bot> bot)
        {
            int64_t offset = 0;
            double delay = polling_config_.backoff.min_delay;
            bool had_error = false;
            auto *loop = trantor::EventLoop::getEventLoopOfCurrentThread();

            const bool sequential = polling_config_.sequential;
            const int max_concurrent = std::max(1, polling_config_.max_concurrent);

            loggers::dispatcher.info(
                std::string("Polling started [") +
                (sequential ? "sequential" : "concurrent max=" + std::to_string(max_concurrent)) +
                "]");

            while (running_)
            {
                auto fetch_result = co_await _try_get_updates(bot, offset);

                if (!fetch_result.has_value())
                {
                    if (!had_error)
                    {
                        loggers::dispatcher.error(
                            "getUpdates failed - retrying in " +
                            std::to_string(static_cast<int>(delay)) + "s");
                        had_error = true;
                    }
                    auto delay_ms = std::chrono::milliseconds(
                        static_cast<int64_t>(delay * 1000.0));
                    co_await drogon::sleepCoro(loop, delay_ms);
                    delay = (std::min)(delay * polling_config_.backoff.factor + polling_config_.backoff.jitter,
                                       polling_config_.backoff.max_delay);
                    continue;
                }

                if (had_error)
                {
                    loggers::dispatcher.info("Connection restored");
                    delay = polling_config_.backoff.min_delay;
                    had_error = false;
                }

                for (auto &upd : *fetch_result)
                {

                    offset = upd->update_id + 1;

                    if (sequential)
                    {
                        co_await _process_update(bot, *upd);
                    }
                    else
                    {
                        // Backpressure: inflight limit doluysa boşalana kadar bekle.
                        // sleepCoro event loop'u bloke etmez; diğer coroutine'ler
                        // bu arada çalışmaya devam eder.
                        while (inflight_.load(std::memory_order_relaxed) >= max_concurrent)
                            co_await drogon::sleepCoro(loop, std::chrono::milliseconds(5));

                        inflight_.fetch_add(1, std::memory_order_relaxed);
                        drogon::async_run(
                            [this, bot, upd]() mutable -> drogon::Task<void>
                            {
                                co_await _process_update(bot, *upd);
                                inflight_.fetch_sub(1, std::memory_order_relaxed);
                            });
                    }
                }
            }

            if (!sequential)
            {
                while (inflight_.load(std::memory_order_relaxed) > 0)
                    co_await drogon::sleepCoro(loop, std::chrono::milliseconds(5));
            }

            loggers::dispatcher.info("Polling stopped");
        }

        /**
         * @brief Calls getUpdates and returns the result, or nullopt on error.
         *
         * Isolated into its own coroutine because co_await cannot be used
         * inside a catch block.
         */
        drogon::Task<std::optional<std::vector<std::shared_ptr<Update>>>>
        _try_get_updates(std::shared_ptr<Bot> bot, int64_t offset)
        {
            try
            {
                co_return co_await bot->api().getUpdates(
                    offset,
                    polling_config_.limit,
                    polling_config_.timeout,
                    polling_config_.allowed_updates);
            }
            catch (const corogram::TelegramUnauthorizedError &e)
            {
                loggers::dispatcher.error(
                    "Fatal: bot token is invalid or revoked. Stopping polling. " +
                    std::string(e.what()));
                running_.store(false);
                co_return std::nullopt;
            }
            catch (const corogram::TelegramForbiddenError &e)
            {
                loggers::dispatcher.error(
                    "Fatal: bot is forbidden (deactivated or banned). Stopping polling. " +
                    std::string(e.what()));
                running_.store(false);
                co_return std::nullopt;
            }
            catch (const std::exception &e)
            {
                if (std::string_view(e.what()).find("Timeout") != std::string_view::npos)
                {
                    loggers::dispatcher.debug("getUpdates timeout (normal)");
                }
                else
                {
                    loggers::dispatcher.error("getUpdates exception: " + std::string(e.what()));
                }
                co_return std::nullopt;
            }
            catch (...)
            {
                loggers::dispatcher.error("getUpdates unknown exception");
                co_return std::nullopt;
            }
        }
    };

} // namespace corogram