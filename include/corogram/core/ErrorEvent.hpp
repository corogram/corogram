// include/core/ErrorEvent.hpp
#pragma once
#include <exception>
#include <stdexcept>
#include <corogram/Types.hpp>

namespace corogram
{

    // =========================================================================
    //  ErrorEvent
    //
    //  Passed to error handlers registered on the Dispatcher:
    //
    //    dp.error().register_handler(
    //        [](const corogram::ErrorEvent& ev, corogram::Context& ctx) -> drogon::Task<bool> {
    //            // log ev.what(), inspect ev.update, etc.
    //            co_return true;  // mark as handled
    //        }
    //    );
    // =========================================================================

    struct ErrorEvent
    {
        const Update &update; // the update that triggered the error
        std::exception_ptr exception;

        /// Returns the exception message, or a fallback string if unavailable.
        std::string what() const noexcept
        {
            if (!exception)
                return "(null exception)";
            try
            {
                std::rethrow_exception(exception);
            }
            catch (const std::exception &e)
            {
                return e.what();
            }
            catch (...)
            {
                return "(unknown exception)";
            }
        }

        /**
         * @brief Attempts to cast the stored exception to type T.
         *
         * @tparam T Exception type to check for
         * @return Pointer to the exception if it matches T, nullptr otherwise
         *
         * Usage:
         *   if (auto* e = ev.as<corogram::TelegramBadRequest>()) { ... }
         */
        template <typename T>
        const T *as() const noexcept
        {
            if (!exception)
                return nullptr;
            try
            {
                std::rethrow_exception(exception);
            }
            catch (const T &e)
            {
                return &e;
            }
            catch (...)
            {
                return nullptr;
            }
        }
    };

} // namespace corogram