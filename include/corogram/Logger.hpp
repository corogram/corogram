// include/Logger.hpp
#pragma once

#include <atomic>
#include <chrono>
#include <cstdio>
#include <ctime>
#include <functional>
#include <memory>
#include <mutex>
#include <sstream>
#include <string>
#include <string_view>
#include <typeinfo>

namespace corogram
{

    // =========================================================================
    //  LogLevel
    // =========================================================================

    enum class LogLevel : int
    {
        Debug = 0,
        Info = 1,
        Warning = 2,
        Error = 3,
        Fatal = 4,
        Off = 99,
    };

    inline std::string_view level_name(LogLevel l)
    {
        switch (l)
        {
        case LogLevel::Debug:
            return "DEBUG";
        case LogLevel::Info:
            return "INFO ";
        case LogLevel::Warning:
            return "WARN ";
        case LogLevel::Error:
            return "ERROR";
        case LogLevel::Fatal:
            return "FATAL";
        default:
            return "?    ";
        }
    }

    // =========================================================================
    //  LogRecord — all data for a single log line
    // =========================================================================

    struct LogRecord
    {
        LogLevel level;
        std::string logger_name;
        std::string message;
        std::chrono::system_clock::time_point time;
    };

    // =========================================================================
    //  LogSink — implement this interface to redirect output
    //
    //  Example (spdlog):
    //    struct SpdlogSink : corogram::LogSink {
    //        void write(const corogram::LogRecord& r) override {
    //            spdlog::get(r.logger_name)->log(to_spdlog_level(r.level), r.message);
    //        }
    //    };
    //    corogram::Logger::set_sink(std::make_shared<SpdlogSink>());
    // =========================================================================

    struct LogSink
    {
        virtual ~LogSink() = default;
        virtual void write(const LogRecord &record) = 0;
    };

    struct StderrSink : LogSink
    {
        void write(const LogRecord &r) override
        {
            auto tt = std::chrono::system_clock::to_time_t(r.time);
            char tbuf[20];
            std::tm tm_buf{};
        #ifdef _WIN32
            localtime_s(&tm_buf, &tt);
        #else
            localtime_r(&tt, &tm_buf);
        #endif
            std::strftime(tbuf, sizeof(tbuf), "%H:%M:%S", &tm_buf);

            const char *color = "";
            const char *reset = "\033[0m";
            switch (r.level)
            {
            case LogLevel::Debug:
                color = "\033[36m";
                break; // cyan
            case LogLevel::Info:
                color = "\033[32m";
                break; // green
            case LogLevel::Warning:
                color = "\033[33m";
                break; // yellow
            case LogLevel::Error:
                color = "\033[31m";
                break; // red
            case LogLevel::Fatal:
                color = "\033[35m";
                break; // magenta
            default:
                break;
            }

            // Build the suffix separately to avoid a dangling c_str() from a temporary
            std::string suffix = r.message.empty() ? "" : ": " + r.message;
            std::fprintf(stderr, "%s[%s] %s%s %s%s\n",
                         color,
                         tbuf,
                         level_name(r.level).data(),
                         reset,
                         r.logger_name.c_str(),
                         suffix.c_str());
        }
    };

    // =========================================================================
    //  Logger
    // =========================================================================

    class Logger
    {
    public:
        explicit Logger(std::string name)
            : name_(std::move(name)) {}

        void set_level(LogLevel l) { level_.store(l, std::memory_order_relaxed); }
        LogLevel level() const { return level_.load(std::memory_order_relaxed); }
        bool enabled(LogLevel l) const { return l >= level(); }

        void debug(std::string msg) { _emit(LogLevel::Debug, std::move(msg)); }
        void info(std::string msg) { _emit(LogLevel::Info, std::move(msg)); }
        void warning(std::string msg) { _emit(LogLevel::Warning, std::move(msg)); }
        void error(std::string msg) { _emit(LogLevel::Error, std::move(msg)); }
        void fatal(std::string msg) { _emit(LogLevel::Fatal, std::move(msg)); }

        /**
         * @brief Logs an exception at Error level.
         *
         * Note: typeid(e).name() is implementation-defined and may return a
         * mangled name on GCC/Clang. Demangle with abi::__cxa_demangle if needed.
         *
         * @param msg  Context message prepended to the exception details
         * @param e    The caught exception
         */
        void exception(std::string msg, const std::exception &e)
        {
            std::string full = std::move(msg);
            full += "\n  ";
            full += typeid(e).name();
            full += ": ";
            full += e.what();
            _emit(LogLevel::Error, std::move(full));
        }

        /**
         * @brief Logs an exception_ptr at Error level.
         *
         * Rethrows and dispatches to the exception(msg, std::exception&) overload.
         * Falls back to a generic message for non-std exceptions.
         *
         * @param msg   Context message
         * @param eptr  Exception pointer (no-op if null)
         */
        void exception(std::string msg, std::exception_ptr eptr)
        {
            if (!eptr)
            {
                _emit(LogLevel::Error, std::move(msg));
                return;
            }
            try
            {
                std::rethrow_exception(eptr);
            }
            catch (const std::exception &e)
            {
                exception(std::move(msg), e);
            }
            catch (...)
            {
                _emit(LogLevel::Error, msg + "\n  (unknown exception)");
            }
        }

        const std::string &name() const { return name_; }

        // Global sink — all Logger instances share one sink
        static void set_sink(std::shared_ptr<LogSink> sink)
        {
            std::lock_guard<std::mutex> g(_sink_mutex());
            _sink_storage() = std::move(sink);
        }

        static std::shared_ptr<LogSink> get_sink()
        {
            return _sink();
        }

    private:
        void _emit(LogLevel l, std::string msg)
        {
            if (!enabled(l))
                return;
            auto sink = _sink();
            if (!sink)
                return;

            LogRecord rec;
            rec.level = l;
            rec.logger_name = name_;
            rec.message = std::move(msg);
            rec.time = std::chrono::system_clock::now();
            sink->write(rec);
        }

        static std::shared_ptr<LogSink> _sink()
        {
            std::lock_guard<std::mutex> g(_sink_mutex());
            return _sink_storage();
        }

        static std::mutex &_sink_mutex()
        {
            static std::mutex m;
            return m;
        }

        static std::shared_ptr<LogSink> &_sink_storage()
        {
            static std::shared_ptr<LogSink> s = std::make_shared<StderrSink>();
            return s;
        }

        std::string name_;
        std::atomic<LogLevel> level_{LogLevel::Info};
    };

    // =========================================================================
    //  Named loggers
    // =========================================================================

    namespace loggers
    {

        inline Logger dispatcher{"corogram.dispatcher"};
        inline Logger event{"corogram.event"};
        inline Logger middlewares{"corogram.middlewares"};
        inline Logger webhook{"corogram.webhook"};
        inline Logger fsm{"corogram.fsm"};
        inline Logger network{"corogram.network"};

        /// Sets the minimum log level on all named loggers.
        inline void set_level(LogLevel l)
        {
            dispatcher.set_level(l);
            event.set_level(l);
            middlewares.set_level(l);
            webhook.set_level(l);
            fsm.set_level(l);
            network.set_level(l);
        }

        /// Redirects all logger output to the given sink.
        inline void set_sink(std::shared_ptr<LogSink> sink)
        {
            Logger::set_sink(std::move(sink));
        }

    } // namespace loggers

} // namespace corogram