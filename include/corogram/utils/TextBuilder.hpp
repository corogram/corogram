// include/corogram/utils/TextBuilder.hpp
#pragma once

/**
 * @file TextBuilder.hpp
 * @brief Telegram message text builder with entity support.
 *
 * Fixes vs. previous version:
 *  - utf16_encode() is now a standalone helper; html_text/md_text call it
 *    ONCE per message and reuse the result for all entity slices.
 *  - Continuation-byte validation added to utf16_encode().
 *  - reserve() uses a tighter upper bound.
 *  - BlockQuote / ExpandableBlockQuote Markdown wrappers corrected.
 *  - Node::utf16_length() avoids a redundant render().
 */

#include <algorithm>
#include <cassert>
#include <cstdint>
#include <memory>
#include <optional>
#include <regex>
#include <string>
#include <vector>

#include <corogram/Enums.hpp>
#include <corogram/Types.hpp>

namespace corogram
{
    namespace fmt
    {

        using corogram::enums::MessageEntityType;
        using corogram::enums::to_string;

        // ─────────────────────────────────────────────────────────────────────────────
        //  UTF-16 helpers
        // ─────────────────────────────────────────────────────────────────────────────

        namespace detail
        {

            /**
             * @brief Decodes a UTF-8 string into a UTF-16 code-unit vector.
             *
             * - Surrogate pairs are emitted for code points >= U+10000.
             * - Invalid byte sequences (lone continuation bytes, truncated sequences,
             *   non-0x10xxxxxx continuation bytes) are silently skipped, matching
             *   aiogram's behaviour.
             *
             * @param utf8  Source string (arbitrary bytes; need not be NUL-terminated).
             * @return      Vector of UTF-16 code units.
             */
            inline std::vector<uint16_t> utf16_encode(const std::string &utf8)
            {
                // Upper bound: every UTF-8 byte produces at most one UTF-16 unit
                // (4-byte sequences produce *two* units, but they consume 4 bytes, so
                // the byte count still upper-bounds the unit count).
                std::vector<uint16_t> out;
                out.reserve(utf8.size());

                const auto *p = reinterpret_cast<const uint8_t *>(utf8.data());
                const auto *end = p + utf8.size();

                auto is_cont = [](uint8_t b)
                { return (b & 0xC0) == 0x80; };

                while (p < end)
                {
                    uint8_t c = *p;

                    uint32_t cp = 0;
                    int len = 0; // extra continuation bytes expected

                    if (c < 0x80)
                    {
                        cp = c;
                        len = 0;
                    }
                    else if (c < 0xC0)
                    {
                        ++p;
                        continue;
                    } // lone continuation byte
                    else if (c < 0xE0)
                    {
                        cp = c & 0x1F;
                        len = 1;
                    }
                    else if (c < 0xF0)
                    {
                        cp = c & 0x0F;
                        len = 2;
                    }
                    else if (c < 0xF8)
                    {
                        cp = c & 0x07;
                        len = 3;
                    }
                    else
                    {
                        ++p;
                        continue;
                    } // invalid lead byte

                    // Validate that we have enough bytes AND they are continuation bytes
                    if (p + len >= end)
                    {
                        p = end;
                        continue;
                    }

                    bool ok = true;
                    for (int k = 1; k <= len; ++k)
                        if (!is_cont(p[k]))
                        {
                            ok = false;
                            break;
                        }
                    if (!ok)
                    {
                        ++p;
                        continue;
                    }

                    for (int k = 1; k <= len; ++k)
                        cp = (cp << 6) | (p[k] & 0x3F);
                    p += len + 1;

                    // Reject overlong / surrogate / out-of-range sequences
                    if (cp > 0x10FFFF || (cp >= 0xD800 && cp <= 0xDFFF))
                        continue;

                    if (cp < 0x10000)
                    {
                        out.push_back(static_cast<uint16_t>(cp));
                    }
                    else
                    {
                        cp -= 0x10000;
                        out.push_back(static_cast<uint16_t>(0xD800 | (cp >> 10)));
                        out.push_back(static_cast<uint16_t>(0xDC00 | (cp & 0x3FF)));
                    }
                }

                return out;
            }

            /**
             * @brief Returns the UTF-16 code-unit length of a UTF-8 string without
             *        materialising the full vector (used inside Node::render()).
             */
            inline int64_t utf16_len(const std::string &utf8)
            {
                return static_cast<int64_t>(utf16_encode(utf8).size());
            }

            /**
             * @brief Slices a pre-built UTF-16 vector and returns it as UTF-8.
             *
             * Lone surrogates at the boundaries are dropped (matches aiogram's
             * remove_surrogates behaviour).
             *
             * @param utf16   Pre-built UTF-16 code-unit array for the full message text.
             * @param offset  Start offset in UTF-16 code units (clamped to [0, size]).
             * @param length  Length in UTF-16 code units (clamped so end <= size).
             * @return        UTF-8 string of the requested slice.
             */
            inline std::string utf16_slice(
                const std::vector<uint16_t> &utf16,
                int64_t offset,
                int64_t length)
            {
                const int64_t total = static_cast<int64_t>(utf16.size());
                const int64_t start = std::max<int64_t>(0, offset);
                const int64_t end = std::min<int64_t>(total, offset + length);
                if (start >= end)
                    return {};

                std::string result;
                result.reserve(static_cast<size_t>(end - start) * 3);

                for (int64_t j = start; j < end;)
                {
                    const uint16_t w = utf16[static_cast<size_t>(j)];
                    uint32_t cp = 0;

                    if (w >= 0xD800 && w <= 0xDBFF)
                    {
                        // High surrogate — need a following low surrogate
                        if (j + 1 >= end)
                        {
                            ++j;
                            continue;
                        } // lone high surrogate at slice boundary
                        const uint16_t w2 = utf16[static_cast<size_t>(j + 1)];
                        if (w2 < 0xDC00 || w2 > 0xDFFF)
                        {
                            ++j;
                            continue;
                        } // unpaired
                        cp = 0x10000 + (static_cast<uint32_t>(w & 0x3FF) << 10) + static_cast<uint32_t>(w2 & 0x3FF);
                        j += 2;
                    }
                    else if (w >= 0xDC00 && w <= 0xDFFF)
                    {
                        ++j;
                        continue; // lone low surrogate
                    }
                    else
                    {
                        cp = w;
                        ++j;
                    }

                    if (cp < 0x80)
                    {
                        result += static_cast<char>(cp);
                    }
                    else if (cp < 0x800)
                    {
                        result += static_cast<char>(0xC0 | (cp >> 6));
                        result += static_cast<char>(0x80 | (cp & 0x3F));
                    }
                    else if (cp < 0x10000)
                    {
                        result += static_cast<char>(0xE0 | (cp >> 12));
                        result += static_cast<char>(0x80 | ((cp >> 6) & 0x3F));
                        result += static_cast<char>(0x80 | (cp & 0x3F));
                    }
                    else
                    {
                        result += static_cast<char>(0xF0 | (cp >> 18));
                        result += static_cast<char>(0x80 | ((cp >> 12) & 0x3F));
                        result += static_cast<char>(0x80 | ((cp >> 6) & 0x3F));
                        result += static_cast<char>(0x80 | (cp & 0x3F));
                    }
                }

                return result;
            }

            // ── HTML helpers ──────────────────────────────────────────────────────────────

            inline std::string html_escape(const std::string &s)
            {
                std::string out;
                out.reserve(s.size());
                for (unsigned char c : s)
                {
                    switch (c)
                    {
                    case '&':
                        out += "&amp;";
                        break;
                    case '<':
                        out += "&lt;";
                        break;
                    case '>':
                        out += "&gt;";
                        break;
                    default:
                        out += static_cast<char>(c);
                    }
                }
                return out;
            }

            // ── Markdown helpers ──────────────────────────────────────────────────────────

            inline std::string md_escape(const std::string &s)
            {
                static const std::regex special(R"([_*\[\]()~`>#+\-=|{}.!\\])");
                return std::regex_replace(s, special, R"(\$&)");
            }

        } // namespace detail

        // ─────────────────────────────────────────────────────────────────────────────
        //  Forward declarations
        // ─────────────────────────────────────────────────────────────────────────────

        class Node;
        using NodePtr = std::shared_ptr<Node>;

        // ─────────────────────────────────────────────────────────────────────────────
        //  Node  — base building block
        // ─────────────────────────────────────────────────────────────────────────────

        class Node
        {
        public:
            explicit Node(std::string text) : plain_(std::move(text)) {}
            explicit Node(std::vector<NodePtr> children) : children_(std::move(children)) {}
            virtual ~Node() = default;

            virtual std::optional<MessageEntityType> entity_type() const { return std::nullopt; }

            // ── render ────────────────────────────────────────────────────────────────

            struct RenderResult
            {
                std::string text;
                std::vector<std::shared_ptr<MessageEntity>> entities;
            };

            RenderResult render() const
            {
                std::string text;
                std::vector<std::shared_ptr<MessageEntity>> entities;
                int64_t offset = 0;
                render_into(text, entities, offset);
                std::stable_sort(entities.begin(), entities.end(),
                                 [](const auto &a, const auto &b)
                                 { return a->offset < b->offset; });
                return {std::move(text), std::move(entities)};
            }

            std::string as_html() const { return render_html(); }
            std::string as_markdown() const { return render_markdown(); }

            int64_t utf16_length() const
            {
                // Avoid double render: just measure the text half
                auto [text, _] = render();
                return detail::utf16_len(text);
            }

        protected:
            virtual void fill_entity(MessageEntity &) const {}

            void render_into(std::string &text,
                             std::vector<std::shared_ptr<MessageEntity>> &entities,
                             int64_t &offset) const
            {
                const int64_t start = offset;

                if (!plain_.empty())
                {
                    text += plain_;
                    offset += detail::utf16_len(plain_);
                }
                else
                {
                    for (const auto &child : children_)
                        child->render_into(text, entities, offset);
                }

                if (auto et = entity_type(); et.has_value())
                {
                    auto ent = std::make_shared<MessageEntity>();
                    ent->type = std::string(to_string(*et));
                    ent->offset = start;
                    ent->length = offset - start;
                    fill_entity(*ent);
                    entities.push_back(std::move(ent));
                }
            }

            virtual std::string render_html() const
            {
                std::string inner;
                if (!plain_.empty())
                    inner = detail::html_escape(plain_);
                else
                    for (const auto &c : children_)
                        inner += c->render_html();
                return wrap_html(inner);
            }

            virtual std::string render_markdown() const
            {
                std::string inner;
                if (!plain_.empty())
                    inner = detail::md_escape(plain_);
                else
                    for (const auto &c : children_)
                        inner += c->render_markdown();
                return wrap_markdown(inner);
            }

            virtual std::string wrap_html(const std::string &inner) const { return inner; }
            virtual std::string wrap_markdown(const std::string &inner) const { return inner; }

        private:
            std::string plain_;
            std::vector<NodePtr> children_;
        };

        // ─────────────────────────────────────────────────────────────────────────────
        //  detail::to_node
        // ─────────────────────────────────────────────────────────────────────────────

        namespace detail
        {
            inline NodePtr to_node(const std::string &s) { return std::make_shared<Node>(s); }
            inline NodePtr to_node(NodePtr p) { return p; }
        } // namespace detail

        // ─────────────────────────────────────────────────────────────────────────────
        //  Formatting node macro
        // ─────────────────────────────────────────────────────────────────────────────

#define TG_FMT_NODE(ClassName, EntityValue, HtmlOpen, HtmlClose, MdOpen, MdClose) \
    class ClassName final : public Node                                           \
    {                                                                             \
    public:                                                                       \
        explicit ClassName(const std::string &text)                               \
            : Node({detail::to_node(text)}) {}                                    \
        explicit ClassName(NodePtr child)                                         \
            : Node({std::move(child)}) {}                                         \
        explicit ClassName(std::vector<NodePtr> children)                         \
            : Node(std::move(children)) {}                                        \
        std::optional<MessageEntityType> entity_type() const override             \
        {                                                                         \
            return MessageEntityType::EntityValue;                                \
        }                                                                         \
                                                                                  \
    protected:                                                                    \
        std::string wrap_html(const std::string &inner) const override            \
        {                                                                         \
            return HtmlOpen + inner + HtmlClose;                                  \
        }                                                                         \
        std::string wrap_markdown(const std::string &inner) const override        \
        {                                                                         \
            return MdOpen + inner + MdClose;                                      \
        }                                                                         \
    }

        //                    Class                  Enum                   HTML-open                    HTML-close       MD-open   MD-close
        TG_FMT_NODE(Bold, Bold, "<b>", "</b>", "*", "*");
        TG_FMT_NODE(Italic, Italic, "<i>", "</i>", "_\r", "_\r");
        TG_FMT_NODE(Underline, Underline, "<u>", "</u>", "__\r", "__\r");
        TG_FMT_NODE(Strikethrough, Strikethrough, "<s>", "</s>", "~", "~");
        TG_FMT_NODE(Spoiler, Spoiler, "<tg-spoiler>", "</tg-spoiler>", "||", "||");
        TG_FMT_NODE(Code, Code, "<code>", "</code>", "`", "`");
        // BlockQuote: HTML = <blockquote>…</blockquote>; MarkdownV2 = prefix each line with ">"
        // Simple single-line prefix is fine for the common case; multiline is handled by the caller.
        TG_FMT_NODE(BlockQuote, Blockquote, "<blockquote>", "</blockquote>", ">", "");
        // ExpandableBlockQuote: no standard MarkdownV2 representation — emit as plain text
        TG_FMT_NODE(ExpandableBlockQuote, ExpandableBlockquote, "<blockquote expandable>", "</blockquote>", "", "");

#undef TG_FMT_NODE

        // ─────────────────────────────────────────────────────────────────────────────
        //  Pre
        // ─────────────────────────────────────────────────────────────────────────────

        class Pre final : public Node
        {
        public:
            explicit Pre(const std::string &text, std::string language = "")
                : Node({detail::to_node(text)}), language_(std::move(language)) {}

            explicit Pre(NodePtr child, std::string language = "")
                : Node({std::move(child)}), language_(std::move(language)) {}

            std::optional<MessageEntityType> entity_type() const override
            {
                return MessageEntityType::Pre;
            }

        protected:
            void fill_entity(MessageEntity &e) const override
            {
                if (!language_.empty())
                    e.language = language_;
            }

            std::string wrap_html(const std::string &inner) const override
            {
                if (!language_.empty())
                    return "<pre><code class=\"language-" + language_ + "\">" + inner + "</code></pre>";
                return "<pre>" + inner + "</pre>";
            }

            std::string wrap_markdown(const std::string &inner) const override
            {
                if (!language_.empty())
                    return "```" + language_ + "\n" + inner + "\n```";
                return "```\n" + inner + "\n```";
            }

        private:
            std::string language_;
        };

        // ─────────────────────────────────────────────────────────────────────────────
        //  TextLink
        // ─────────────────────────────────────────────────────────────────────────────

        class TextLink final : public Node
        {
        public:
            TextLink(const std::string &text, std::string url)
                : Node({detail::to_node(text)}), url_(std::move(url)) {}
            TextLink(NodePtr child, std::string url)
                : Node({std::move(child)}), url_(std::move(url)) {}

            std::optional<MessageEntityType> entity_type() const override
            {
                return MessageEntityType::TextLink;
            }

        protected:
            void fill_entity(MessageEntity &e) const override { e.url = url_; }

            std::string wrap_html(const std::string &inner) const override
            {
                return "<a href=\"" + url_ + "\">" + inner + "</a>";
            }

            std::string wrap_markdown(const std::string &inner) const override
            {
                return "[" + inner + "](" + url_ + ")";
            }

        private:
            std::string url_;
        };

        // ─────────────────────────────────────────────────────────────────────────────
        //  TextMention
        // ─────────────────────────────────────────────────────────────────────────────

        class TextMention final : public Node
        {
        public:
            TextMention(const std::string &text, int64_t user_id)
                : Node({detail::to_node(text)}), user_id_(user_id) {}

            std::optional<MessageEntityType> entity_type() const override
            {
                return MessageEntityType::TextMention;
            }

        protected:
            void fill_entity(MessageEntity &e) const override
            {
                auto u = std::make_shared<User>();
                u->id = user_id_;
                e.user = std::move(u);
            }

            std::string wrap_html(const std::string &inner) const override
            {
                return "<a href=\"tg://user?id=" + std::to_string(user_id_) + "\">" + inner + "</a>";
            }

            std::string wrap_markdown(const std::string &inner) const override
            {
                return "[" + inner + "](tg://user?id=" + std::to_string(user_id_) + ")";
            }

        private:
            int64_t user_id_;
        };

        // ─────────────────────────────────────────────────────────────────────────────
        //  CustomEmoji
        // ─────────────────────────────────────────────────────────────────────────────

        class CustomEmoji final : public Node
        {
        public:
            CustomEmoji(const std::string &fallback, std::string emoji_id)
                : Node({detail::to_node(fallback)}), emoji_id_(std::move(emoji_id)) {}

            std::optional<MessageEntityType> entity_type() const override
            {
                return MessageEntityType::CustomEmoji;
            }

        protected:
            void fill_entity(MessageEntity &e) const override { e.custom_emoji_id = emoji_id_; }

            std::string wrap_html(const std::string &inner) const override
            {
                return "<tg-emoji emoji-id=\"" + emoji_id_ + "\">" + inner + "</tg-emoji>";
            }

            std::string wrap_markdown(const std::string &inner) const override
            {
                return "![" + inner + "](tg://emoji?id=" + emoji_id_ + ")";
            }

        private:
            std::string emoji_id_;
        };

        // ─────────────────────────────────────────────────────────────────────────────
        //  DateTime
        // ─────────────────────────────────────────────────────────────────────────────

        class DateTime final : public Node
        {
        public:
            DateTime(const std::string &label, int64_t unix_time, std::string format = "")
                : Node({detail::to_node(label)}),
                  unix_time_(unix_time),
                  format_(std::move(format)) {}

            std::optional<MessageEntityType> entity_type() const override
            {
                return MessageEntityType::DateTime;
            }

        protected:
            void fill_entity(MessageEntity &e) const override
            {
                e.unix_time = unix_time_;
                if (!format_.empty())
                    e.date_time_format = format_;
            }

            std::string wrap_html(const std::string &inner) const override
            {
                std::string attrs = " unix=\"" + std::to_string(unix_time_) + "\"";
                if (!format_.empty())
                    attrs += " format=\"" + format_ + "\"";
                return "<tg-time" + attrs + ">" + inner + "</tg-time>";
            }

            std::string wrap_markdown(const std::string &inner) const override
            {
                std::string link = "tg://time?unix=" + std::to_string(unix_time_);
                if (!format_.empty())
                    link += "&format=" + format_;
                return "![" + inner + "](" + link + ")";
            }

        private:
            int64_t unix_time_;
            std::string format_;
        };

        // ─────────────────────────────────────────────────────────────────────────────
        //  Convenience factory
        // ─────────────────────────────────────────────────────────────────────────────

        inline NodePtr Text(const std::string &s) { return std::make_shared<Node>(s); }

        // ─────────────────────────────────────────────────────────────────────────────
        //  Composition helpers
        // ─────────────────────────────────────────────────────────────────────────────

        inline NodePtr combine(std::vector<NodePtr> nodes)
        {
            return std::make_shared<Node>(std::move(nodes));
        }

        inline NodePtr as_line(std::vector<NodePtr> items,
                               const std::string &sep = "",
                               const std::string &end = "\n")
        {
            std::vector<NodePtr> nodes;
            for (size_t i = 0; i < items.size(); ++i)
            {
                nodes.push_back(items[i]);
                if (!sep.empty() && i + 1 < items.size())
                    nodes.push_back(Text(sep));
            }
            nodes.push_back(Text(end));
            return combine(std::move(nodes));
        }

        inline NodePtr as_line(NodePtr a, NodePtr b, const std::string &end = "\n")
        {
            return combine({std::move(a), std::move(b), Text(end)});
        }

        inline NodePtr as_list(std::vector<NodePtr> items, const std::string &sep = "\n")
        {
            std::vector<NodePtr> nodes;
            for (size_t i = 0; i < items.size(); ++i)
            {
                nodes.push_back(items[i]);
                if (i + 1 < items.size())
                    nodes.push_back(Text(sep));
            }
            return combine(std::move(nodes));
        }

        inline NodePtr as_marked_list(std::vector<NodePtr> items, const std::string &marker = "- ")
        {
            std::vector<NodePtr> marked;
            for (auto &item : items)
                marked.push_back(combine({Text(marker), item}));
            return as_list(std::move(marked));
        }

        inline NodePtr as_numbered_list(std::vector<NodePtr> items,
                                        int start = 1,
                                        const std::string &fmt = "{}. ")
        {
            std::vector<NodePtr> numbered;
            int idx = start;
            for (auto &item : items)
            {
                std::string prefix = fmt;
                auto pos = prefix.find("{}");
                if (pos != std::string::npos)
                    prefix.replace(pos, 2, std::to_string(idx));
                numbered.push_back(combine({Text(prefix), item}));
                ++idx;
            }
            return as_list(std::move(numbered));
        }

        inline NodePtr as_section(NodePtr title, std::vector<NodePtr> body)
        {
            std::vector<NodePtr> nodes;
            nodes.push_back(std::move(title));
            nodes.push_back(Text("\n"));
            for (auto &b : body)
                nodes.push_back(b);
            return combine(std::move(nodes));
        }

        inline NodePtr as_marked_section(NodePtr title,
                                         std::vector<NodePtr> body,
                                         const std::string &marker = "- ")
        {
            return as_section(std::move(title), {as_marked_list(std::move(body), marker)});
        }

        inline NodePtr as_numbered_section(NodePtr title,
                                           std::vector<NodePtr> body,
                                           int start = 1,
                                           const std::string &fmt = "{}. ")
        {
            return as_section(std::move(title), {as_numbered_list(std::move(body), start, fmt)});
        }

        inline NodePtr as_key_value(const std::string &key, NodePtr value)
        {
            return combine({std::make_shared<Bold>(key + ":"), Text(" "), std::move(value)});
        }

        // ─────────────────────────────────────────────────────────────────────────────
        //  TextBuilder  — fluent builder
        // ─────────────────────────────────────────────────────────────────────────────

        class TextBuilder
        {
        public:
            TextBuilder() = default;

            // ── add() overloads ───────────────────────────────────────────────────────

            TextBuilder &add(NodePtr node)
            {
                nodes_.push_back(std::move(node));
                return *this;
            }
            TextBuilder &add(const std::string &text)
            {
                nodes_.push_back(Text(text));
                return *this;
            }

            TextBuilder &bold(const std::string &t) { return add(std::make_shared<Bold>(t)); }
            TextBuilder &italic(const std::string &t) { return add(std::make_shared<Italic>(t)); }
            TextBuilder &underline(const std::string &t) { return add(std::make_shared<Underline>(t)); }
            TextBuilder &strikethrough(const std::string &t) { return add(std::make_shared<Strikethrough>(t)); }
            TextBuilder &spoiler(const std::string &t) { return add(std::make_shared<Spoiler>(t)); }
            TextBuilder &code(const std::string &t) { return add(std::make_shared<Code>(t)); }

            TextBuilder &pre(const std::string &t, const std::string &lang = "")
            {
                return add(std::make_shared<Pre>(t, lang));
            }

            TextBuilder &link(const std::string &label, const std::string &url)
            {
                return add(std::make_shared<TextLink>(label, url));
            }

            TextBuilder &mention(const std::string &label, int64_t user_id)
            {
                return add(std::make_shared<TextMention>(label, user_id));
            }

            TextBuilder &emoji(const std::string &fallback, const std::string &emoji_id)
            {
                return add(std::make_shared<CustomEmoji>(fallback, emoji_id));
            }

            TextBuilder &datetime(const std::string &label, int64_t unix_time, const std::string &fmt = "")
            {
                return add(std::make_shared<DateTime>(label, unix_time, fmt));
            }

            TextBuilder &newline(int count = 1)
            {
                nodes_.push_back(Text(std::string(static_cast<size_t>(count), '\n')));
                return *this;
            }

            TextBuilder &space(int count = 1)
            {
                nodes_.push_back(Text(std::string(static_cast<size_t>(count), ' ')));
                return *this;
            }

            TextBuilder &key_value(const std::string &key, const std::string &value)
            {
                return add(as_key_value(key, Text(value)));
            }

            TextBuilder &separator(const std::string &sep = "─────────────────────")
            {
                return add(Text(sep)).newline();
            }

            // ── render ────────────────────────────────────────────────────────────────

            Node::RenderResult render() const { return combine(nodes_)->render(); }
            std::string as_html() const { return combine(nodes_)->as_html(); }
            std::string as_markdown() const { return combine(nodes_)->as_markdown(); }

            struct SendArgs
            {
                std::string text;
                std::vector<std::shared_ptr<MessageEntity>> entities;
            };

            SendArgs as_send_args() const
            {
                auto [text, ents] = render();
                return {std::move(text), std::move(ents)};
            }

            bool empty() const { return nodes_.empty(); }
            TextBuilder &clear()
            {
                nodes_.clear();
                return *this;
            }

        private:
            std::vector<NodePtr> nodes_;
        };

    } // namespace fmt
} // namespace corogram
