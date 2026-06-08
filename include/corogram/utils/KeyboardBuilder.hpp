// include/utils/KeyboardBuilder.hpp
#pragma once
#include <memory>
#include <string>
#include <vector>
#include <optional>
#include <stdexcept>
#include <corogram/Types.hpp>

namespace corogram
{

    /**
     * @brief Generic keyboard builder base class, ported from aiogram's KeyboardBuilder.
     *
     * Manages a 2D grid of buttons and provides layout utilities.
     * Use InlineKeyboardBuilder or ReplyKeyboardBuilder instead of this directly.
     *
     * @tparam ButtonType  InlineKeyboardButton or KeyboardButton
     */
    template <typename ButtonType>
    class KeyboardBuilder
    {
    public:
        using Row = std::vector<std::shared_ptr<ButtonType>>;
        using Markup = std::vector<Row>;

        explicit KeyboardBuilder(int max_width, int min_width, int max_buttons)
            : max_width_(max_width), min_width_(min_width), max_buttons_(max_buttons)
        {
        }

        /**
         * @brief Appends a button to the current row, starting a new row if full.
         */
        KeyboardBuilder &add(std::shared_ptr<ButtonType> btn)
        {
            if (markup_.empty() || (int)markup_.back().size() >= max_width_)
                markup_.push_back({});
            markup_.back().push_back(std::move(btn));
            return *this;
        }

        /**
         * @brief Appends an entire pre-built row.
         *
         * @throws std::invalid_argument if the row exceeds max_width_
         */
        KeyboardBuilder &row(std::vector<std::shared_ptr<ButtonType>> buttons)
        {
            if ((int)buttons.size() > max_width_)
                throw std::invalid_argument(
                    "Row too wide (max: " + std::to_string(max_width_) + ")");
            markup_.push_back(std::move(buttons));
            return *this;
        }

        /**
         * @brief Re-flows all buttons according to the given column widths.
         *
         * @param sizes   Column widths applied in order. The last value repeats
         *                for any remaining rows unless @p repeat is true.
         * @param repeat  If true, cycles through @p sizes instead of holding
         *                the last value.
         *
         * Examples:
         *   adjust(2)          →  every row has 2 buttons
         *   adjust({2, 3})     →  first row: 2, subsequent rows: 3
         *   adjust({2, 3}, true) →  alternates: 2, 3, 2, 3, ...
         */
        KeyboardBuilder &adjust(std::vector<int> sizes, bool repeat = false)
        {
            if (sizes.empty())
                sizes = {max_width_};

            std::vector<std::shared_ptr<ButtonType>> flat;
            for (auto &r : markup_)
                for (auto &b : r)
                    flat.push_back(b);

            markup_.clear();

            size_t size_idx = 0;
            Row current_row;

            for (auto &btn : flat)
            {
                int size = sizes[size_idx < sizes.size() ? size_idx : sizes.size() - 1];

                if ((int)current_row.size() >= size)
                {
                    markup_.push_back(std::move(current_row));
                    current_row.clear();

                    if (repeat)
                        size_idx = (size_idx + 1) % sizes.size();
                    else if (size_idx + 1 < sizes.size())
                        ++size_idx;
                }
                current_row.push_back(btn);
            }

            if (!current_row.empty())
                markup_.push_back(std::move(current_row));

            return *this;
        }

        /** @brief Convenience overload for a single uniform column width. */
        KeyboardBuilder &adjust(int size, bool repeat = false)
        {
            return adjust(std::vector<int>{size}, repeat);
        }

        /**
         * @brief Appends all rows from another builder into this one.
         */
        KeyboardBuilder &attach(const KeyboardBuilder &other)
        {
            for (const auto &row : other.markup_)
                markup_.push_back(row);
            return *this;
        }

        /** @brief Returns a copy of the internal markup grid. */
        Markup export_markup() const { return markup_; }

        /** @brief Returns all buttons as a flat list. */
        std::vector<std::shared_ptr<ButtonType>> buttons() const
        {
            std::vector<std::shared_ptr<ButtonType>> flat;
            for (const auto &r : markup_)
                for (const auto &b : r)
                    flat.push_back(b);
            return flat;
        }

        /** @brief Returns the total number of buttons across all rows. */
        int size() const
        {
            int n = 0;
            for (const auto &r : markup_)
                n += (int)r.size();
            return n;
        }

        /** @brief Returns true if the markup has no rows. */
        bool empty() const { return markup_.empty(); }

    protected:
        Markup markup_;
        int max_width_;
        int min_width_;
        int max_buttons_;
    };

    // =========================================================================
    //  InlineKeyboardBuilder
    // =========================================================================

    /**
     * @brief Builds InlineKeyboardMarkup objects.
     *
     * Telegram limits: 8 buttons per row, 100 buttons total.
     *
     * Usage:
     * @code
     *   auto markup = InlineKeyboardBuilder{}
     *       .button("About",    "menu_about")
     *       .button("Settings", "menu_settings")
     *       .button("Close",    "menu_close")
     *       .adjust(2)          // → [[About, Settings], [Close]]
     *       .as_markup();
     * @endcode
     */
    class InlineKeyboardBuilder : public KeyboardBuilder<InlineKeyboardButton>
    {
    public:
        InlineKeyboardBuilder() : KeyboardBuilder(8, 1, 100) {}

        /**
         * @brief Adds a callback button.
         *
         * @param text           Button label shown to the user
         * @param callback_data  Data sent to the bot on press (max 64 bytes)
         */
        InlineKeyboardBuilder &button(std::string text, std::string callback_data)
        {
            auto btn = std::make_shared<InlineKeyboardButton>();
            btn->text = std::move(text);
            btn->callback_data = std::move(callback_data);
            add(std::move(btn));
            return *this;
        }

        /**
         * @brief Adds a URL button that opens a link when pressed.
         */
        InlineKeyboardBuilder &url_button(std::string text, std::string url)
        {
            auto btn = std::make_shared<InlineKeyboardButton>();
            btn->text = std::move(text);
            btn->url = std::move(url);
            add(std::move(btn));
            return *this;
        }

        /**
         * @brief Adds a switch-inline-query button.
         *
         * @param query  Pre-filled inline query text (empty string is valid)
         */
        InlineKeyboardBuilder &switch_inline_button(std::string text,
                                                    std::string query = "")
        {
            auto btn = std::make_shared<InlineKeyboardButton>();
            btn->text = std::move(text);
            btn->switch_inline_query = std::move(query);
            add(std::move(btn));
            return *this;
        }

        /**
         * @brief Adds a row of callback buttons using brace-init syntax.
         *
         * @code
         *   builder.row({{"Yes", "yes"}, {"No", "no"}});
         * @endcode
         */
        InlineKeyboardBuilder &row(
            std::initializer_list<std::pair<std::string, std::string>> buttons)
        {
            std::vector<std::shared_ptr<InlineKeyboardButton>> row_btns;
            for (auto &[text, data] : buttons)
            {
                auto btn = std::make_shared<InlineKeyboardButton>();
                btn->text = text;
                btn->callback_data = data;
                row_btns.push_back(std::move(btn));
            }
            KeyboardBuilder::row(std::move(row_btns));
            return *this;
        }

        /** @copydoc KeyboardBuilder::adjust(int, bool) */
        InlineKeyboardBuilder &adjust(int size, bool repeat = false)
        {
            KeyboardBuilder::adjust(size, repeat);
            return *this;
        }

        /** @copydoc KeyboardBuilder::adjust(std::vector<int>, bool) */
        InlineKeyboardBuilder &adjust(std::vector<int> sizes, bool repeat = false)
        {
            KeyboardBuilder::adjust(std::move(sizes), repeat);
            return *this;
        }

        /** @brief Converts the builder's current state to an InlineKeyboardMarkup. */
        std::shared_ptr<InlineKeyboardMarkup> as_markup() const
        {
            auto markup = std::make_shared<InlineKeyboardMarkup>();
            markup->inline_keyboard = export_markup();
            return markup;
        }

        /**
         * @brief Constructs a builder pre-populated from an existing markup.
         */
        static InlineKeyboardBuilder from_markup(
            const std::shared_ptr<InlineKeyboardMarkup> &markup)
        {
            InlineKeyboardBuilder builder;
            builder.markup_ = markup->inline_keyboard;
            return builder;
        }

        /** @brief Returns a deep copy of this builder. */
        InlineKeyboardBuilder copy() const
        {
            InlineKeyboardBuilder b;
            b.markup_ = export_markup();
            return b;
        }
    };

    // =========================================================================
    //  ReplyKeyboardBuilder
    // =========================================================================

    /**
     * @brief Builds ReplyKeyboardMarkup objects.
     *
     * Telegram limits: 10 buttons per row, 300 buttons total.
     *
     * Usage:
     * @code
     *   auto markup = ReplyKeyboardBuilder{}
     *       .button("Option A")
     *       .button("Option B")
     *       .button("Option C")
     *       .adjust(2)
     *       .as_markup();
     * @endcode
     */
    class ReplyKeyboardBuilder : public KeyboardBuilder<KeyboardButton>
    {
    public:
        ReplyKeyboardBuilder() : KeyboardBuilder(10, 1, 300) {}

        /** @brief Adds a plain text button. */
        ReplyKeyboardBuilder &button(std::string text)
        {
            auto btn = std::make_shared<KeyboardButton>();
            btn->text = std::move(text);
            add(std::move(btn));
            return *this;
        }

        /** @brief Adds a button that requests the user's current location. */
        ReplyKeyboardBuilder &location_button(std::string text)
        {
            auto btn = std::make_shared<KeyboardButton>();
            btn->text = std::move(text);
            btn->request_location = true;
            add(std::move(btn));
            return *this;
        }

        /** @brief Adds a button that requests the user's phone number. */
        ReplyKeyboardBuilder &contact_button(std::string text)
        {
            auto btn = std::make_shared<KeyboardButton>();
            btn->text = std::move(text);
            btn->request_contact = true;
            add(std::move(btn));
            return *this;
        }

        /**
         * @brief Adds a row of plain text buttons using brace-init syntax.
         *
         * @code
         *   builder.row({"Yes", "No", "Maybe"});
         * @endcode
         */
        ReplyKeyboardBuilder &row(std::initializer_list<std::string> texts)
        {
            std::vector<std::shared_ptr<KeyboardButton>> row_btns;
            for (const auto &text : texts)
            {
                auto btn = std::make_shared<KeyboardButton>();
                btn->text = text;
                row_btns.push_back(std::move(btn));
            }
            KeyboardBuilder::row(std::move(row_btns));
            return *this;
        }

        /** @copydoc KeyboardBuilder::adjust(int, bool) */
        ReplyKeyboardBuilder &adjust(int size, bool repeat = false)
        {
            KeyboardBuilder::adjust(size, repeat);
            return *this;
        }

        /** @copydoc KeyboardBuilder::adjust(std::vector<int>, bool) */
        ReplyKeyboardBuilder &adjust(std::vector<int> sizes, bool repeat = false)
        {
            KeyboardBuilder::adjust(std::move(sizes), repeat);
            return *this;
        }

        /**
         * @brief Converts the builder's current state to a ReplyKeyboardMarkup.
         *
         * @param resize_keyboard     Fit the keyboard to the button count (default: true)
         * @param one_time_keyboard   Hide after first use (default: false)
         * @param selective           Show only to mentioned users (default: false)
         */
        std::shared_ptr<ReplyKeyboardMarkup> as_markup(
            bool resize_keyboard = true,
            bool one_time_keyboard = false,
            bool selective = false) const
        {
            auto markup = std::make_shared<ReplyKeyboardMarkup>();
            markup->keyboard = export_markup();
            markup->resize_keyboard = resize_keyboard;
            markup->one_time_keyboard = one_time_keyboard;
            markup->selective = selective;
            return markup;
        }

        /** @brief Returns a deep copy of this builder. */
        ReplyKeyboardBuilder copy() const
        {
            ReplyKeyboardBuilder b;
            b.markup_ = export_markup();
            return b;
        }
    };

    /**
     * @brief Creates a ReplyKeyboardRemove to hide the reply keyboard.
     *
     * @param selective  Remove only for mentioned users (default: false)
     */
    inline std::shared_ptr<ReplyKeyboardRemove> remove_keyboard(bool selective = false)
    {
        auto r = std::make_shared<ReplyKeyboardRemove>();
        r->remove_keyboard = true;
        r->selective = selective;
        return r;
    }

} // namespace corogram