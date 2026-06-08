/**
 * @file    Methods.h
 * @brief   Telegram Bot API 10.0 — auto-generated API class
 * @date    08-05-2026
 *
 * Generated via schema  —  DO NOT EDIT MANUALLY.
 *
 */
#pragma once
#include <drogon/drogon.h>
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <variant>
#include <vector>
#include <corogram/Types.hpp>
#include <corogram/BaseApi.hpp>
#include <corogram/network/BaseNetwork.hpp>

namespace corogram {


class API : public BaseApi {

    private:
        std::shared_ptr<INetwork> request_;
        std::string               token_; 

    public:
        explicit API(std::shared_ptr<INetwork> network, std::string token)
            : request_(std::move(network))
            , token_("/bot" + std::move(token)) {}

    

    // ── Getting updates ───────────────────────────────────────────────────────

    /**
     * Use this method to receive incoming updates using long polling (wiki). Returns an Array
     * of Update objects.
     *
     * @param offset [optional] Optional.
     * @param limit [optional] Optional.
     * @param timeout [optional] Optional.
     * @param allowed_updates [optional] Optional.
     * @returns std::vector<std::shared_ptr<Update>>
     * @see https://core.telegram.org/bots/api#getupdates
     */
    struct GetUpdatesArgs {
        std::optional<int64_t> offset;
        std::optional<int64_t> limit;
        std::optional<int64_t> timeout;
        std::vector<std::string> allowed_updates;
    };

    drogon::Task<std::vector<std::shared_ptr<Update>>> getUpdates(std::optional<int64_t> offset = std::nullopt,
                                                                  std::optional<int64_t> limit = std::nullopt,
                                                                  std::optional<int64_t> timeout = std::nullopt,
                                                                  std::vector<std::string> allowed_updates = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (offset.has_value()) {
            payload["offset"] = offset.value();
        }
        if (limit.has_value()) {
            payload["limit"] = limit.value();
        }
        if (timeout.has_value()) {
            payload["timeout"] = timeout.value();
        }
        if (!allowed_updates.empty()) {
            json _arr = json::array();
            for (const auto& _item : allowed_updates) {
                _arr.push_back(_item);
            }
            payload["allowed_updates"] = std::move(_arr);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getUpdates", _body)
            : co_await request_->uploadFiles(token_ + "/getUpdates", _body, _uploads);
        co_return parse_response<std::vector<std::shared_ptr<Update>>>(_resp).result.value();
    }

    drogon::Task<std::vector<std::shared_ptr<Update>>> getUpdates(GetUpdatesArgs args) {
        co_return co_await getUpdates(std::move(args.offset),
            std::move(args.limit),
            std::move(args.timeout),
            std::move(args.allowed_updates));
    }

    /**
     * Use this method to specify a URL and receive incoming updates via an outgoing webhook.
     * Whenever there is an update for the bot, we will send an HTTPS POST request to the
     * specified URL, containing a JSON-serialized Update. In case of an unsuccessful request (a
     * request with response HTTP status code different from 2XY), we will repeat the request
     * and give up after a reasonable amount of attempts. Returns True on success.
     * If you'd like to make sure that the webhook was set by you, you can specify secret data
     * in the parameter secret_token. If specified, the request will contain a header
     * 'X-Telegram-Bot-Api-Secret-Token' with the secret token as content.
     *
     * @param url [required] HTTPS URL to send updates to.
     * @param certificate [optional] Optional.
     * @param ip_address [optional] Optional.
     * @param max_connections [optional] Optional.
     * @param allowed_updates [optional] Optional.
     * @param drop_pending_updates [optional] Optional.
     * @param secret_token [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setwebhook
     */
    struct SetWebhookArgs {
        std::string url{""};
        std::shared_ptr<InputFile> certificate;
        std::optional<std::string> ip_address;
        std::optional<int64_t> max_connections;
        std::vector<std::string> allowed_updates;
        std::optional<bool> drop_pending_updates;
        std::optional<std::string> secret_token;
    };

    drogon::Task<bool> setWebhook(std::string url,
                                  std::shared_ptr<InputFile> certificate = nullptr,
                                  std::optional<std::string> ip_address = std::nullopt,
                                  std::optional<int64_t> max_connections = std::nullopt,
                                  std::vector<std::string> allowed_updates = {},
                                  std::optional<bool> drop_pending_updates = std::nullopt,
                                  std::optional<std::string> secret_token = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["url"] = url;
        if (certificate) {
            payload["certificate"] = "attach://" + certificate->filename;
            _uploads.push_back({"certificate", certificate});
        }
        if (ip_address.has_value()) {
            payload["ip_address"] = ip_address.value();
        }
        if (max_connections.has_value()) {
            payload["max_connections"] = max_connections.value();
        }
        if (!allowed_updates.empty()) {
            json _arr = json::array();
            for (const auto& _item : allowed_updates) {
                _arr.push_back(_item);
            }
            payload["allowed_updates"] = std::move(_arr);
        }
        if (drop_pending_updates.has_value()) {
            payload["drop_pending_updates"] = drop_pending_updates.value();
        }
        if (secret_token.has_value()) {
            payload["secret_token"] = secret_token.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setWebhook", _body)
            : co_await request_->uploadFiles(token_ + "/setWebhook", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setWebhook(SetWebhookArgs args) {
        co_return co_await setWebhook(std::move(args.url),
            std::move(args.certificate),
            std::move(args.ip_address),
            std::move(args.max_connections),
            std::move(args.allowed_updates),
            std::move(args.drop_pending_updates),
            std::move(args.secret_token));
    }

    /**
     * Use this method to remove webhook integration if you decide to switch back to getUpdates.
     * Returns True on success.
     *
     * @param drop_pending_updates [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#deletewebhook
     */
    struct DeleteWebhookArgs {
        std::optional<bool> drop_pending_updates;
    };

    drogon::Task<bool> deleteWebhook(std::optional<bool> drop_pending_updates = std::nullopt) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (drop_pending_updates.has_value()) {
            payload["drop_pending_updates"] = drop_pending_updates.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/deleteWebhook", _body)
            : co_await request_->uploadFiles(token_ + "/deleteWebhook", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> deleteWebhook(DeleteWebhookArgs args) {
        co_return co_await deleteWebhook(std::move(args.drop_pending_updates));
    }

    /**
     * Use this method to get current webhook status. Requires no parameters. On success,
     * returns a WebhookInfo object. If the bot is using getUpdates, will return an object with
     * the url field empty.
     *
     * @returns std::shared_ptr<WebhookInfo>
     * @see https://core.telegram.org/bots/api#getwebhookinfo
     */
    drogon::Task<std::shared_ptr<WebhookInfo>> getWebhookInfo() const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getWebhookInfo", _body)
            : co_await request_->uploadFiles(token_ + "/getWebhookInfo", _body, _uploads);
        co_return parse_response<std::shared_ptr<WebhookInfo>>(_resp).result.value();
    }

    // ── Available methods ─────────────────────────────────────────────────────

    /**
     * A simple method for testing your bot's authentication token. Requires no parameters.
     * Returns basic information about the bot in form of a User object.
     *
     * @returns std::shared_ptr<User>
     * @see https://core.telegram.org/bots/api#getme
     */
    drogon::Task<std::shared_ptr<User>> getMe() const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getMe", _body)
            : co_await request_->uploadFiles(token_ + "/getMe", _body, _uploads);
        co_return parse_response<std::shared_ptr<User>>(_resp).result.value();
    }

    /**
     * Use this method to log out from the cloud Bot API server before launching the bot
     * locally. You must log out the bot before running it locally, otherwise there is no
     * guarantee that the bot will receive updates. After a successful call, you can immediately
     * log in on a local server, but will not be able to log in back to the cloud Bot API server
     * for 10 minutes. Returns True on success. Requires no parameters.
     *
     * @returns bool
     * @see https://core.telegram.org/bots/api#logout
     */
    drogon::Task<bool> logOut() const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/logOut", _body)
            : co_await request_->uploadFiles(token_ + "/logOut", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    /**
     * Use this method to close the bot instance before moving it from one local server to
     * another. You need to delete the webhook before calling this method to ensure that the bot
     * isn't launched again after server restart. The method will return error 429 in the first
     * 10 minutes after the bot is launched. Returns True on success. Requires no parameters.
     *
     * @returns bool
     * @see https://core.telegram.org/bots/api#close
     */
    drogon::Task<bool> close() const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/close", _body)
            : co_await request_->uploadFiles(token_ + "/close", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    /**
     * Use this method to send text messages. On success, the sent Message is returned.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param text [required] Text of the message to be sent, 1-4096 characters after entities parsing.
     * @param parse_mode [optional] Optional.
     * @param entities [optional] Optional.
     * @param link_preview_options [optional] Optional.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param suggested_post_parameters [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#sendmessage
     */
    struct SendMessageArgs {
        ChatId chat_id{};
        std::string text{""};
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<std::string> parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> entities;
        std::shared_ptr<LinkPreviewOptions> link_preview_options;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters;
        std::shared_ptr<ReplyParameters> reply_parameters;
        ReplyMarkup reply_markup{};
    };

    drogon::Task<std::shared_ptr<Message>> sendMessage(ChatId chat_id,
                                                       std::string text,
                                                       std::optional<std::string> business_connection_id = std::nullopt,
                                                       std::optional<int64_t> message_thread_id = std::nullopt,
                                                       std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                       std::optional<std::string> parse_mode = std::nullopt,
                                                       std::vector<std::shared_ptr<MessageEntity>> entities = {},
                                                       std::shared_ptr<LinkPreviewOptions> link_preview_options = nullptr,
                                                       std::optional<bool> disable_notification = std::nullopt,
                                                       std::optional<bool> protect_content = std::nullopt,
                                                       std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                       std::optional<std::string> message_effect_id = std::nullopt,
                                                       std::shared_ptr<SuggestedPostParameters> suggested_post_parameters = nullptr,
                                                       std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                       ReplyMarkup reply_markup = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        payload["text"] = text;
        if (parse_mode.has_value()) {
            payload["parse_mode"] = parse_mode.value();
        }
        if (!entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["entities"] = std::move(_arr);
        }
        if (link_preview_options) {
            json _sub;
            to_json(_sub, *link_preview_options);
            payload["link_preview_options"] = std::move(_sub);
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (suggested_post_parameters) {
            json _sub;
            to_json(_sub, *suggested_post_parameters);
            payload["suggested_post_parameters"] = std::move(_sub);
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (auto* _p = std::get_if<std::shared_ptr<InlineKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardRemove>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ForceReply>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendMessage", _body)
            : co_await request_->uploadFiles(token_ + "/sendMessage", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> sendMessage(SendMessageArgs args) {
        co_return co_await sendMessage(std::move(args.chat_id),
            std::move(args.text),
            std::move(args.business_connection_id),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.parse_mode),
            std::move(args.entities),
            std::move(args.link_preview_options),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.message_effect_id),
            std::move(args.suggested_post_parameters),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to forward messages of any kind. Service messages and messages with
     * protected content can't be forwarded. On success, the sent Message is returned.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param from_chat_id [required] Unique identifier for the chat where the original message was sent (or username of the target bot, s.
     * @param video_start_timestamp [optional] Optional.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param suggested_post_parameters [optional] Optional.
     * @param message_id [required] Message identifier in the chat specified in from_chat_id.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#forwardmessage
     */
    struct ForwardMessageArgs {
        ChatId chat_id{};
        ChatId from_chat_id{};
        int64_t message_id{0};
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<int64_t> video_start_timestamp;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters;
    };

    drogon::Task<std::shared_ptr<Message>> forwardMessage(ChatId chat_id,
                                                          ChatId from_chat_id,
                                                          int64_t message_id,
                                                          std::optional<int64_t> message_thread_id = std::nullopt,
                                                          std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                          std::optional<int64_t> video_start_timestamp = std::nullopt,
                                                          std::optional<bool> disable_notification = std::nullopt,
                                                          std::optional<bool> protect_content = std::nullopt,
                                                          std::optional<std::string> message_effect_id = std::nullopt,
                                                          std::shared_ptr<SuggestedPostParameters> suggested_post_parameters = nullptr) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&from_chat_id)) {
            payload["from_chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&from_chat_id)) {
            payload["from_chat_id"] = *_p;
        }
        if (video_start_timestamp.has_value()) {
            payload["video_start_timestamp"] = video_start_timestamp.value();
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (suggested_post_parameters) {
            json _sub;
            to_json(_sub, *suggested_post_parameters);
            payload["suggested_post_parameters"] = std::move(_sub);
        }
        payload["message_id"] = message_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/forwardMessage", _body)
            : co_await request_->uploadFiles(token_ + "/forwardMessage", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> forwardMessage(ForwardMessageArgs args) {
        co_return co_await forwardMessage(std::move(args.chat_id),
            std::move(args.from_chat_id),
            std::move(args.message_id),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.video_start_timestamp),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.message_effect_id),
            std::move(args.suggested_post_parameters));
    }

    /**
     * Use this method to forward multiple messages of any kind. If some of the specified
     * messages can't be found or forwarded, they are skipped. Service messages and messages
     * with protected content can't be forwarded. Album grouping is kept for forwarded messages.
     * On success, an array of MessageId of the sent messages is returned.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param from_chat_id [required] Unique identifier for the chat where the original messages were sent (or username of the target bot,.
     * @param message_ids [required] A JSON-serialized list of 1-100 identifiers of messages in the chat from_chat_id to forward.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @returns std::vector<std::shared_ptr<MessageId>>
     * @see https://core.telegram.org/bots/api#forwardmessages
     */
    struct ForwardMessagesArgs {
        ChatId chat_id{};
        ChatId from_chat_id{};
        std::vector<int64_t> message_ids;
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
    };

    drogon::Task<std::vector<std::shared_ptr<MessageId>>> forwardMessages(ChatId chat_id,
                                                                          ChatId from_chat_id,
                                                                          std::vector<int64_t> message_ids,
                                                                          std::optional<int64_t> message_thread_id = std::nullopt,
                                                                          std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                                          std::optional<bool> disable_notification = std::nullopt,
                                                                          std::optional<bool> protect_content = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&from_chat_id)) {
            payload["from_chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&from_chat_id)) {
            payload["from_chat_id"] = *_p;
        }
        {
            json _arr = json::array();
            for (const auto& _item : message_ids) {
                _arr.push_back(_item);
            }
            payload["message_ids"] = std::move(_arr);
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/forwardMessages", _body)
            : co_await request_->uploadFiles(token_ + "/forwardMessages", _body, _uploads);
        co_return parse_response<std::vector<std::shared_ptr<MessageId>>>(_resp).result.value();
    }

    drogon::Task<std::vector<std::shared_ptr<MessageId>>> forwardMessages(ForwardMessagesArgs args) {
        co_return co_await forwardMessages(std::move(args.chat_id),
            std::move(args.from_chat_id),
            std::move(args.message_ids),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.disable_notification),
            std::move(args.protect_content));
    }

    /**
     * Use this method to copy messages of any kind. Service messages, paid media messages,
     * giveaway messages, giveaway winners messages, and invoice messages can't be copied. A
     * quiz poll can be copied only if the value of the field correct_option_id is known to the
     * bot. The method is analogous to the method forwardMessage, but the copied message doesn't
     * have a link to the original message. Returns the MessageId of the sent message on
     * success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param from_chat_id [required] Unique identifier for the chat where the original message was sent (or username of the target bot, s.
     * @param message_id [required] Message identifier in the chat specified in from_chat_id.
     * @param video_start_timestamp [optional] Optional.
     * @param caption [optional] Optional.
     * @param parse_mode [optional] Optional.
     * @param caption_entities [optional] Optional.
     * @param show_caption_above_media [optional] Optional.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param suggested_post_parameters [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<MessageId>
     * @see https://core.telegram.org/bots/api#copymessage
     */
    struct CopyMessageArgs {
        ChatId chat_id{};
        ChatId from_chat_id{};
        int64_t message_id{0};
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<int64_t> video_start_timestamp;
        std::optional<std::string> caption;
        std::optional<std::string> parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> caption_entities;
        std::optional<bool> show_caption_above_media;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters;
        std::shared_ptr<ReplyParameters> reply_parameters;
        ReplyMarkup reply_markup{};
    };

    drogon::Task<std::shared_ptr<MessageId>> copyMessage(ChatId chat_id,
                                                         ChatId from_chat_id,
                                                         int64_t message_id,
                                                         std::optional<int64_t> message_thread_id = std::nullopt,
                                                         std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                         std::optional<int64_t> video_start_timestamp = std::nullopt,
                                                         std::optional<std::string> caption = std::nullopt,
                                                         std::optional<std::string> parse_mode = std::nullopt,
                                                         std::vector<std::shared_ptr<MessageEntity>> caption_entities = {},
                                                         std::optional<bool> show_caption_above_media = std::nullopt,
                                                         std::optional<bool> disable_notification = std::nullopt,
                                                         std::optional<bool> protect_content = std::nullopt,
                                                         std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                         std::optional<std::string> message_effect_id = std::nullopt,
                                                         std::shared_ptr<SuggestedPostParameters> suggested_post_parameters = nullptr,
                                                         std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                         ReplyMarkup reply_markup = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&from_chat_id)) {
            payload["from_chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&from_chat_id)) {
            payload["from_chat_id"] = *_p;
        }
        payload["message_id"] = message_id;
        if (video_start_timestamp.has_value()) {
            payload["video_start_timestamp"] = video_start_timestamp.value();
        }
        if (caption.has_value()) {
            payload["caption"] = caption.value();
        }
        if (parse_mode.has_value()) {
            payload["parse_mode"] = parse_mode.value();
        }
        if (!caption_entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : caption_entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["caption_entities"] = std::move(_arr);
        }
        if (show_caption_above_media.has_value()) {
            payload["show_caption_above_media"] = show_caption_above_media.value();
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (suggested_post_parameters) {
            json _sub;
            to_json(_sub, *suggested_post_parameters);
            payload["suggested_post_parameters"] = std::move(_sub);
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (auto* _p = std::get_if<std::shared_ptr<InlineKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardRemove>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ForceReply>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/copyMessage", _body)
            : co_await request_->uploadFiles(token_ + "/copyMessage", _body, _uploads);
        co_return parse_response<std::shared_ptr<MessageId>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<MessageId>> copyMessage(CopyMessageArgs args) {
        co_return co_await copyMessage(std::move(args.chat_id),
            std::move(args.from_chat_id),
            std::move(args.message_id),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.video_start_timestamp),
            std::move(args.caption),
            std::move(args.parse_mode),
            std::move(args.caption_entities),
            std::move(args.show_caption_above_media),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.message_effect_id),
            std::move(args.suggested_post_parameters),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to copy messages of any kind. If some of the specified messages can't be
     * found or copied, they are skipped. Service messages, paid media messages, giveaway
     * messages, giveaway winners messages, and invoice messages can't be copied. A quiz poll
     * can be copied only if the value of the field correct_option_id is known to the bot. The
     * method is analogous to the method forwardMessages, but the copied messages don't have a
     * link to the original message. Album grouping is kept for copied messages. On success, an
     * array of MessageId of the sent messages is returned.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param from_chat_id [required] Unique identifier for the chat where the original messages were sent (or username of the target bot,.
     * @param message_ids [required] A JSON-serialized list of 1-100 identifiers of messages in the chat from_chat_id to copy.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param remove_caption [optional] Optional.
     * @returns std::vector<std::shared_ptr<MessageId>>
     * @see https://core.telegram.org/bots/api#copymessages
     */
    struct CopyMessagesArgs {
        ChatId chat_id{};
        ChatId from_chat_id{};
        std::vector<int64_t> message_ids;
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> remove_caption;
    };

    drogon::Task<std::vector<std::shared_ptr<MessageId>>> copyMessages(ChatId chat_id,
                                                                       ChatId from_chat_id,
                                                                       std::vector<int64_t> message_ids,
                                                                       std::optional<int64_t> message_thread_id = std::nullopt,
                                                                       std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                                       std::optional<bool> disable_notification = std::nullopt,
                                                                       std::optional<bool> protect_content = std::nullopt,
                                                                       std::optional<bool> remove_caption = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&from_chat_id)) {
            payload["from_chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&from_chat_id)) {
            payload["from_chat_id"] = *_p;
        }
        {
            json _arr = json::array();
            for (const auto& _item : message_ids) {
                _arr.push_back(_item);
            }
            payload["message_ids"] = std::move(_arr);
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (remove_caption.has_value()) {
            payload["remove_caption"] = remove_caption.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/copyMessages", _body)
            : co_await request_->uploadFiles(token_ + "/copyMessages", _body, _uploads);
        co_return parse_response<std::vector<std::shared_ptr<MessageId>>>(_resp).result.value();
    }

    drogon::Task<std::vector<std::shared_ptr<MessageId>>> copyMessages(CopyMessagesArgs args) {
        co_return co_await copyMessages(std::move(args.chat_id),
            std::move(args.from_chat_id),
            std::move(args.message_ids),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.remove_caption));
    }

    /**
     * Use this method to send photos. On success, the sent Message is returned.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param photo [required] Photo to send.
     * @param caption [optional] Optional.
     * @param parse_mode [optional] Optional.
     * @param caption_entities [optional] Optional.
     * @param show_caption_above_media [optional] Optional.
     * @param has_spoiler [optional] Optional.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param suggested_post_parameters [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#sendphoto
     */
    struct SendPhotoArgs {
        ChatId chat_id{};
        std::variant<std::shared_ptr<InputFile>, std::string> photo{};
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<std::string> caption;
        std::optional<std::string> parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> caption_entities;
        std::optional<bool> show_caption_above_media;
        std::optional<bool> has_spoiler;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters;
        std::shared_ptr<ReplyParameters> reply_parameters;
        ReplyMarkup reply_markup{};
    };

    drogon::Task<std::shared_ptr<Message>> sendPhoto(ChatId chat_id,
                                                     std::variant<std::shared_ptr<InputFile>, std::string> photo,
                                                     std::optional<std::string> business_connection_id = std::nullopt,
                                                     std::optional<int64_t> message_thread_id = std::nullopt,
                                                     std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                     std::optional<std::string> caption = std::nullopt,
                                                     std::optional<std::string> parse_mode = std::nullopt,
                                                     std::vector<std::shared_ptr<MessageEntity>> caption_entities = {},
                                                     std::optional<bool> show_caption_above_media = std::nullopt,
                                                     std::optional<bool> has_spoiler = std::nullopt,
                                                     std::optional<bool> disable_notification = std::nullopt,
                                                     std::optional<bool> protect_content = std::nullopt,
                                                     std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                     std::optional<std::string> message_effect_id = std::nullopt,
                                                     std::shared_ptr<SuggestedPostParameters> suggested_post_parameters = nullptr,
                                                     std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                     ReplyMarkup reply_markup = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        if (auto* _p = std::get_if<std::shared_ptr<InputFile>>(&photo)) {
            if (*_p) {
                payload["photo"] = "attach://" + (*_p)->filename;
                _uploads.push_back({"photo", *_p});
            }
        }
        if (auto* _p = std::get_if<std::string>(&photo)) {
            payload["photo"] = *_p;
        }
        if (caption.has_value()) {
            payload["caption"] = caption.value();
        }
        if (parse_mode.has_value()) {
            payload["parse_mode"] = parse_mode.value();
        }
        if (!caption_entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : caption_entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["caption_entities"] = std::move(_arr);
        }
        if (show_caption_above_media.has_value()) {
            payload["show_caption_above_media"] = show_caption_above_media.value();
        }
        if (has_spoiler.has_value()) {
            payload["has_spoiler"] = has_spoiler.value();
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (suggested_post_parameters) {
            json _sub;
            to_json(_sub, *suggested_post_parameters);
            payload["suggested_post_parameters"] = std::move(_sub);
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (auto* _p = std::get_if<std::shared_ptr<InlineKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardRemove>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ForceReply>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendPhoto", _body)
            : co_await request_->uploadFiles(token_ + "/sendPhoto", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> sendPhoto(SendPhotoArgs args) {
        co_return co_await sendPhoto(std::move(args.chat_id),
            std::move(args.photo),
            std::move(args.business_connection_id),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.caption),
            std::move(args.parse_mode),
            std::move(args.caption_entities),
            std::move(args.show_caption_above_media),
            std::move(args.has_spoiler),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.message_effect_id),
            std::move(args.suggested_post_parameters),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to send live photos. On success, the sent Message is returned.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target channel (in the format @channelusern.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param live_photo [required] Live photo video to send.
     * @param photo [required] The static photo to send.
     * @param caption [optional] Optional.
     * @param parse_mode [optional] Optional.
     * @param caption_entities [optional] Optional.
     * @param show_caption_above_media [optional] Optional.
     * @param has_spoiler [optional] Optional.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param suggested_post_parameters [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#sendlivephoto
     */
    struct SendLivePhotoArgs {
        ChatId chat_id{};
        std::variant<std::shared_ptr<InputFile>, std::string> live_photo{};
        std::variant<std::shared_ptr<InputFile>, std::string> photo{};
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<std::string> caption;
        std::optional<std::string> parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> caption_entities;
        std::optional<bool> show_caption_above_media;
        std::optional<bool> has_spoiler;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters;
        std::shared_ptr<ReplyParameters> reply_parameters;
        ReplyMarkup reply_markup{};
    };

    drogon::Task<std::shared_ptr<Message>> sendLivePhoto(ChatId chat_id,
                                                         std::variant<std::shared_ptr<InputFile>, std::string> live_photo,
                                                         std::variant<std::shared_ptr<InputFile>, std::string> photo,
                                                         std::optional<std::string> business_connection_id = std::nullopt,
                                                         std::optional<int64_t> message_thread_id = std::nullopt,
                                                         std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                         std::optional<std::string> caption = std::nullopt,
                                                         std::optional<std::string> parse_mode = std::nullopt,
                                                         std::vector<std::shared_ptr<MessageEntity>> caption_entities = {},
                                                         std::optional<bool> show_caption_above_media = std::nullopt,
                                                         std::optional<bool> has_spoiler = std::nullopt,
                                                         std::optional<bool> disable_notification = std::nullopt,
                                                         std::optional<bool> protect_content = std::nullopt,
                                                         std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                         std::optional<std::string> message_effect_id = std::nullopt,
                                                         std::shared_ptr<SuggestedPostParameters> suggested_post_parameters = nullptr,
                                                         std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                         ReplyMarkup reply_markup = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        if (auto* _p = std::get_if<std::shared_ptr<InputFile>>(&live_photo)) {
            if (*_p) {
                payload["live_photo"] = "attach://" + (*_p)->filename;
                _uploads.push_back({"live_photo", *_p});
            }
        }
        if (auto* _p = std::get_if<std::string>(&live_photo)) {
            payload["live_photo"] = *_p;
        }
        if (auto* _p = std::get_if<std::shared_ptr<InputFile>>(&photo)) {
            if (*_p) {
                payload["photo"] = "attach://" + (*_p)->filename;
                _uploads.push_back({"photo", *_p});
            }
        }
        if (auto* _p = std::get_if<std::string>(&photo)) {
            payload["photo"] = *_p;
        }
        if (caption.has_value()) {
            payload["caption"] = caption.value();
        }
        if (parse_mode.has_value()) {
            payload["parse_mode"] = parse_mode.value();
        }
        if (!caption_entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : caption_entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["caption_entities"] = std::move(_arr);
        }
        if (show_caption_above_media.has_value()) {
            payload["show_caption_above_media"] = show_caption_above_media.value();
        }
        if (has_spoiler.has_value()) {
            payload["has_spoiler"] = has_spoiler.value();
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (suggested_post_parameters) {
            json _sub;
            to_json(_sub, *suggested_post_parameters);
            payload["suggested_post_parameters"] = std::move(_sub);
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (auto* _p = std::get_if<std::shared_ptr<InlineKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardRemove>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ForceReply>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendLivePhoto", _body)
            : co_await request_->uploadFiles(token_ + "/sendLivePhoto", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> sendLivePhoto(SendLivePhotoArgs args) {
        co_return co_await sendLivePhoto(std::move(args.chat_id),
            std::move(args.live_photo),
            std::move(args.photo),
            std::move(args.business_connection_id),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.caption),
            std::move(args.parse_mode),
            std::move(args.caption_entities),
            std::move(args.show_caption_above_media),
            std::move(args.has_spoiler),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.message_effect_id),
            std::move(args.suggested_post_parameters),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to send audio files, if you want Telegram clients to display them in the
     * music player. Your audio must be in the .MP3 or .M4A format. On success, the sent Message
     * is returned. Bots can currently send audio files of up to 50 MB in size, this limit may
     * be changed in the future.
     * For sending voice messages, use the sendVoice method instead.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param audio [required] Audio file to send.
     * @param caption [optional] Optional.
     * @param parse_mode [optional] Optional.
     * @param caption_entities [optional] Optional.
     * @param duration [optional] Optional.
     * @param performer [optional] Optional.
     * @param title [optional] Optional.
     * @param thumbnail [optional] Optional.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param suggested_post_parameters [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#sendaudio
     */
    struct SendAudioArgs {
        ChatId chat_id{};
        std::variant<std::shared_ptr<InputFile>, std::string> audio{};
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<std::string> caption;
        std::optional<std::string> parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> caption_entities;
        std::optional<int64_t> duration;
        std::optional<std::string> performer;
        std::optional<std::string> title;
        std::variant<std::shared_ptr<InputFile>, std::string> thumbnail{};
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters;
        std::shared_ptr<ReplyParameters> reply_parameters;
        ReplyMarkup reply_markup{};
    };

    drogon::Task<std::shared_ptr<Message>> sendAudio(ChatId chat_id,
                                                     std::variant<std::shared_ptr<InputFile>, std::string> audio,
                                                     std::optional<std::string> business_connection_id = std::nullopt,
                                                     std::optional<int64_t> message_thread_id = std::nullopt,
                                                     std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                     std::optional<std::string> caption = std::nullopt,
                                                     std::optional<std::string> parse_mode = std::nullopt,
                                                     std::vector<std::shared_ptr<MessageEntity>> caption_entities = {},
                                                     std::optional<int64_t> duration = std::nullopt,
                                                     std::optional<std::string> performer = std::nullopt,
                                                     std::optional<std::string> title = std::nullopt,
                                                     std::variant<std::shared_ptr<InputFile>, std::string> thumbnail = {},
                                                     std::optional<bool> disable_notification = std::nullopt,
                                                     std::optional<bool> protect_content = std::nullopt,
                                                     std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                     std::optional<std::string> message_effect_id = std::nullopt,
                                                     std::shared_ptr<SuggestedPostParameters> suggested_post_parameters = nullptr,
                                                     std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                     ReplyMarkup reply_markup = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        if (auto* _p = std::get_if<std::shared_ptr<InputFile>>(&audio)) {
            if (*_p) {
                payload["audio"] = "attach://" + (*_p)->filename;
                _uploads.push_back({"audio", *_p});
            }
        }
        if (auto* _p = std::get_if<std::string>(&audio)) {
            payload["audio"] = *_p;
        }
        if (caption.has_value()) {
            payload["caption"] = caption.value();
        }
        if (parse_mode.has_value()) {
            payload["parse_mode"] = parse_mode.value();
        }
        if (!caption_entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : caption_entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["caption_entities"] = std::move(_arr);
        }
        if (duration.has_value()) {
            payload["duration"] = duration.value();
        }
        if (performer.has_value()) {
            payload["performer"] = performer.value();
        }
        if (title.has_value()) {
            payload["title"] = title.value();
        }
        if (auto* _p = std::get_if<std::shared_ptr<InputFile>>(&thumbnail)) {
            if (*_p) {
                payload["thumbnail"] = "attach://" + (*_p)->filename;
                _uploads.push_back({"thumbnail", *_p});
            }
        }
        if (auto* _p = std::get_if<std::string>(&thumbnail)) {
            payload["thumbnail"] = *_p;
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (suggested_post_parameters) {
            json _sub;
            to_json(_sub, *suggested_post_parameters);
            payload["suggested_post_parameters"] = std::move(_sub);
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (auto* _p = std::get_if<std::shared_ptr<InlineKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardRemove>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ForceReply>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendAudio", _body)
            : co_await request_->uploadFiles(token_ + "/sendAudio", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> sendAudio(SendAudioArgs args) {
        co_return co_await sendAudio(std::move(args.chat_id),
            std::move(args.audio),
            std::move(args.business_connection_id),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.caption),
            std::move(args.parse_mode),
            std::move(args.caption_entities),
            std::move(args.duration),
            std::move(args.performer),
            std::move(args.title),
            std::move(args.thumbnail),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.message_effect_id),
            std::move(args.suggested_post_parameters),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to send general files. On success, the sent Message is returned. Bots can
     * currently send files of any type of up to 50 MB in size, this limit may be changed in the
     * future.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param document [required] File to send.
     * @param thumbnail [optional] Optional.
     * @param caption [optional] Optional.
     * @param parse_mode [optional] Optional.
     * @param caption_entities [optional] Optional.
     * @param disable_content_type_detection [optional] Optional.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param suggested_post_parameters [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#senddocument
     */
    struct SendDocumentArgs {
        ChatId chat_id{};
        std::variant<std::shared_ptr<InputFile>, std::string> document{};
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::variant<std::shared_ptr<InputFile>, std::string> thumbnail{};
        std::optional<std::string> caption;
        std::optional<std::string> parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> caption_entities;
        std::optional<bool> disable_content_type_detection;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters;
        std::shared_ptr<ReplyParameters> reply_parameters;
        ReplyMarkup reply_markup{};
    };

    drogon::Task<std::shared_ptr<Message>> sendDocument(ChatId chat_id,
                                                        std::variant<std::shared_ptr<InputFile>, std::string> document,
                                                        std::optional<std::string> business_connection_id = std::nullopt,
                                                        std::optional<int64_t> message_thread_id = std::nullopt,
                                                        std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                        std::variant<std::shared_ptr<InputFile>, std::string> thumbnail = {},
                                                        std::optional<std::string> caption = std::nullopt,
                                                        std::optional<std::string> parse_mode = std::nullopt,
                                                        std::vector<std::shared_ptr<MessageEntity>> caption_entities = {},
                                                        std::optional<bool> disable_content_type_detection = std::nullopt,
                                                        std::optional<bool> disable_notification = std::nullopt,
                                                        std::optional<bool> protect_content = std::nullopt,
                                                        std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                        std::optional<std::string> message_effect_id = std::nullopt,
                                                        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters = nullptr,
                                                        std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                        ReplyMarkup reply_markup = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        if (auto* _p = std::get_if<std::shared_ptr<InputFile>>(&document)) {
            if (*_p) {
                payload["document"] = "attach://" + (*_p)->filename;
                _uploads.push_back({"document", *_p});
            }
        }
        if (auto* _p = std::get_if<std::string>(&document)) {
            payload["document"] = *_p;
        }
        if (auto* _p = std::get_if<std::shared_ptr<InputFile>>(&thumbnail)) {
            if (*_p) {
                payload["thumbnail"] = "attach://" + (*_p)->filename;
                _uploads.push_back({"thumbnail", *_p});
            }
        }
        if (auto* _p = std::get_if<std::string>(&thumbnail)) {
            payload["thumbnail"] = *_p;
        }
        if (caption.has_value()) {
            payload["caption"] = caption.value();
        }
        if (parse_mode.has_value()) {
            payload["parse_mode"] = parse_mode.value();
        }
        if (!caption_entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : caption_entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["caption_entities"] = std::move(_arr);
        }
        if (disable_content_type_detection.has_value()) {
            payload["disable_content_type_detection"] = disable_content_type_detection.value();
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (suggested_post_parameters) {
            json _sub;
            to_json(_sub, *suggested_post_parameters);
            payload["suggested_post_parameters"] = std::move(_sub);
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (auto* _p = std::get_if<std::shared_ptr<InlineKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardRemove>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ForceReply>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendDocument", _body)
            : co_await request_->uploadFiles(token_ + "/sendDocument", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> sendDocument(SendDocumentArgs args) {
        co_return co_await sendDocument(std::move(args.chat_id),
            std::move(args.document),
            std::move(args.business_connection_id),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.thumbnail),
            std::move(args.caption),
            std::move(args.parse_mode),
            std::move(args.caption_entities),
            std::move(args.disable_content_type_detection),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.message_effect_id),
            std::move(args.suggested_post_parameters),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to send video files, Telegram clients support MPEG4 videos (other formats
     * may be sent as Document). On success, the sent Message is returned. Bots can currently
     * send video files of up to 50 MB in size, this limit may be changed in the future.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param video [required] Video to send.
     * @param duration [optional] Optional.
     * @param width [optional] Optional.
     * @param height [optional] Optional.
     * @param thumbnail [optional] Optional.
     * @param cover [optional] Optional.
     * @param start_timestamp [optional] Optional.
     * @param caption [optional] Optional.
     * @param parse_mode [optional] Optional.
     * @param caption_entities [optional] Optional.
     * @param show_caption_above_media [optional] Optional.
     * @param has_spoiler [optional] Optional.
     * @param supports_streaming [optional] Optional.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param suggested_post_parameters [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#sendvideo
     */
    struct SendVideoArgs {
        ChatId chat_id{};
        std::variant<std::shared_ptr<InputFile>, std::string> video{};
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<int64_t> duration;
        std::optional<int64_t> width;
        std::optional<int64_t> height;
        std::variant<std::shared_ptr<InputFile>, std::string> thumbnail{};
        std::variant<std::shared_ptr<InputFile>, std::string> cover{};
        std::optional<int64_t> start_timestamp;
        std::optional<std::string> caption;
        std::optional<std::string> parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> caption_entities;
        std::optional<bool> show_caption_above_media;
        std::optional<bool> has_spoiler;
        std::optional<bool> supports_streaming;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters;
        std::shared_ptr<ReplyParameters> reply_parameters;
        ReplyMarkup reply_markup{};
    };

    drogon::Task<std::shared_ptr<Message>> sendVideo(ChatId chat_id,
                                                     std::variant<std::shared_ptr<InputFile>, std::string> video,
                                                     std::optional<std::string> business_connection_id = std::nullopt,
                                                     std::optional<int64_t> message_thread_id = std::nullopt,
                                                     std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                     std::optional<int64_t> duration = std::nullopt,
                                                     std::optional<int64_t> width = std::nullopt,
                                                     std::optional<int64_t> height = std::nullopt,
                                                     std::variant<std::shared_ptr<InputFile>, std::string> thumbnail = {},
                                                     std::variant<std::shared_ptr<InputFile>, std::string> cover = {},
                                                     std::optional<int64_t> start_timestamp = std::nullopt,
                                                     std::optional<std::string> caption = std::nullopt,
                                                     std::optional<std::string> parse_mode = std::nullopt,
                                                     std::vector<std::shared_ptr<MessageEntity>> caption_entities = {},
                                                     std::optional<bool> show_caption_above_media = std::nullopt,
                                                     std::optional<bool> has_spoiler = std::nullopt,
                                                     std::optional<bool> supports_streaming = std::nullopt,
                                                     std::optional<bool> disable_notification = std::nullopt,
                                                     std::optional<bool> protect_content = std::nullopt,
                                                     std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                     std::optional<std::string> message_effect_id = std::nullopt,
                                                     std::shared_ptr<SuggestedPostParameters> suggested_post_parameters = nullptr,
                                                     std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                     ReplyMarkup reply_markup = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        if (auto* _p = std::get_if<std::shared_ptr<InputFile>>(&video)) {
            if (*_p) {
                payload["video"] = "attach://" + (*_p)->filename;
                _uploads.push_back({"video", *_p});
            }
        }
        if (auto* _p = std::get_if<std::string>(&video)) {
            payload["video"] = *_p;
        }
        if (duration.has_value()) {
            payload["duration"] = duration.value();
        }
        if (width.has_value()) {
            payload["width"] = width.value();
        }
        if (height.has_value()) {
            payload["height"] = height.value();
        }
        if (auto* _p = std::get_if<std::shared_ptr<InputFile>>(&thumbnail)) {
            if (*_p) {
                payload["thumbnail"] = "attach://" + (*_p)->filename;
                _uploads.push_back({"thumbnail", *_p});
            }
        }
        if (auto* _p = std::get_if<std::string>(&thumbnail)) {
            payload["thumbnail"] = *_p;
        }
        if (auto* _p = std::get_if<std::shared_ptr<InputFile>>(&cover)) {
            if (*_p) {
                payload["cover"] = "attach://" + (*_p)->filename;
                _uploads.push_back({"cover", *_p});
            }
        }
        if (auto* _p = std::get_if<std::string>(&cover)) {
            payload["cover"] = *_p;
        }
        if (start_timestamp.has_value()) {
            payload["start_timestamp"] = start_timestamp.value();
        }
        if (caption.has_value()) {
            payload["caption"] = caption.value();
        }
        if (parse_mode.has_value()) {
            payload["parse_mode"] = parse_mode.value();
        }
        if (!caption_entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : caption_entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["caption_entities"] = std::move(_arr);
        }
        if (show_caption_above_media.has_value()) {
            payload["show_caption_above_media"] = show_caption_above_media.value();
        }
        if (has_spoiler.has_value()) {
            payload["has_spoiler"] = has_spoiler.value();
        }
        if (supports_streaming.has_value()) {
            payload["supports_streaming"] = supports_streaming.value();
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (suggested_post_parameters) {
            json _sub;
            to_json(_sub, *suggested_post_parameters);
            payload["suggested_post_parameters"] = std::move(_sub);
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (auto* _p = std::get_if<std::shared_ptr<InlineKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardRemove>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ForceReply>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendVideo", _body)
            : co_await request_->uploadFiles(token_ + "/sendVideo", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> sendVideo(SendVideoArgs args) {
        co_return co_await sendVideo(std::move(args.chat_id),
            std::move(args.video),
            std::move(args.business_connection_id),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.duration),
            std::move(args.width),
            std::move(args.height),
            std::move(args.thumbnail),
            std::move(args.cover),
            std::move(args.start_timestamp),
            std::move(args.caption),
            std::move(args.parse_mode),
            std::move(args.caption_entities),
            std::move(args.show_caption_above_media),
            std::move(args.has_spoiler),
            std::move(args.supports_streaming),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.message_effect_id),
            std::move(args.suggested_post_parameters),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to send animation files (GIF or H.264/MPEG-4 AVC video without sound). On
     * success, the sent Message is returned. Bots can currently send animation files of up to
     * 50 MB in size, this limit may be changed in the future.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param animation [required] Animation to send.
     * @param duration [optional] Optional.
     * @param width [optional] Optional.
     * @param height [optional] Optional.
     * @param thumbnail [optional] Optional.
     * @param caption [optional] Optional.
     * @param parse_mode [optional] Optional.
     * @param caption_entities [optional] Optional.
     * @param show_caption_above_media [optional] Optional.
     * @param has_spoiler [optional] Optional.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param suggested_post_parameters [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#sendanimation
     */
    struct SendAnimationArgs {
        ChatId chat_id{};
        std::variant<std::shared_ptr<InputFile>, std::string> animation{};
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<int64_t> duration;
        std::optional<int64_t> width;
        std::optional<int64_t> height;
        std::variant<std::shared_ptr<InputFile>, std::string> thumbnail{};
        std::optional<std::string> caption;
        std::optional<std::string> parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> caption_entities;
        std::optional<bool> show_caption_above_media;
        std::optional<bool> has_spoiler;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters;
        std::shared_ptr<ReplyParameters> reply_parameters;
        ReplyMarkup reply_markup{};
    };

    drogon::Task<std::shared_ptr<Message>> sendAnimation(ChatId chat_id,
                                                         std::variant<std::shared_ptr<InputFile>, std::string> animation,
                                                         std::optional<std::string> business_connection_id = std::nullopt,
                                                         std::optional<int64_t> message_thread_id = std::nullopt,
                                                         std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                         std::optional<int64_t> duration = std::nullopt,
                                                         std::optional<int64_t> width = std::nullopt,
                                                         std::optional<int64_t> height = std::nullopt,
                                                         std::variant<std::shared_ptr<InputFile>, std::string> thumbnail = {},
                                                         std::optional<std::string> caption = std::nullopt,
                                                         std::optional<std::string> parse_mode = std::nullopt,
                                                         std::vector<std::shared_ptr<MessageEntity>> caption_entities = {},
                                                         std::optional<bool> show_caption_above_media = std::nullopt,
                                                         std::optional<bool> has_spoiler = std::nullopt,
                                                         std::optional<bool> disable_notification = std::nullopt,
                                                         std::optional<bool> protect_content = std::nullopt,
                                                         std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                         std::optional<std::string> message_effect_id = std::nullopt,
                                                         std::shared_ptr<SuggestedPostParameters> suggested_post_parameters = nullptr,
                                                         std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                         ReplyMarkup reply_markup = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        if (auto* _p = std::get_if<std::shared_ptr<InputFile>>(&animation)) {
            if (*_p) {
                payload["animation"] = "attach://" + (*_p)->filename;
                _uploads.push_back({"animation", *_p});
            }
        }
        if (auto* _p = std::get_if<std::string>(&animation)) {
            payload["animation"] = *_p;
        }
        if (duration.has_value()) {
            payload["duration"] = duration.value();
        }
        if (width.has_value()) {
            payload["width"] = width.value();
        }
        if (height.has_value()) {
            payload["height"] = height.value();
        }
        if (auto* _p = std::get_if<std::shared_ptr<InputFile>>(&thumbnail)) {
            if (*_p) {
                payload["thumbnail"] = "attach://" + (*_p)->filename;
                _uploads.push_back({"thumbnail", *_p});
            }
        }
        if (auto* _p = std::get_if<std::string>(&thumbnail)) {
            payload["thumbnail"] = *_p;
        }
        if (caption.has_value()) {
            payload["caption"] = caption.value();
        }
        if (parse_mode.has_value()) {
            payload["parse_mode"] = parse_mode.value();
        }
        if (!caption_entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : caption_entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["caption_entities"] = std::move(_arr);
        }
        if (show_caption_above_media.has_value()) {
            payload["show_caption_above_media"] = show_caption_above_media.value();
        }
        if (has_spoiler.has_value()) {
            payload["has_spoiler"] = has_spoiler.value();
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (suggested_post_parameters) {
            json _sub;
            to_json(_sub, *suggested_post_parameters);
            payload["suggested_post_parameters"] = std::move(_sub);
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (auto* _p = std::get_if<std::shared_ptr<InlineKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardRemove>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ForceReply>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendAnimation", _body)
            : co_await request_->uploadFiles(token_ + "/sendAnimation", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> sendAnimation(SendAnimationArgs args) {
        co_return co_await sendAnimation(std::move(args.chat_id),
            std::move(args.animation),
            std::move(args.business_connection_id),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.duration),
            std::move(args.width),
            std::move(args.height),
            std::move(args.thumbnail),
            std::move(args.caption),
            std::move(args.parse_mode),
            std::move(args.caption_entities),
            std::move(args.show_caption_above_media),
            std::move(args.has_spoiler),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.message_effect_id),
            std::move(args.suggested_post_parameters),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to send audio files, if you want Telegram clients to display the file as
     * a playable voice message. For this to work, your audio must be in an .OGG file encoded
     * with OPUS, or in .MP3 format, or in .M4A format (other formats may be sent as Audio or
     * Document). On success, the sent Message is returned. Bots can currently send voice
     * messages of up to 50 MB in size, this limit may be changed in the future.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param voice [required] Audio file to send.
     * @param caption [optional] Optional.
     * @param parse_mode [optional] Optional.
     * @param caption_entities [optional] Optional.
     * @param duration [optional] Optional.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param suggested_post_parameters [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#sendvoice
     */
    struct SendVoiceArgs {
        ChatId chat_id{};
        std::variant<std::shared_ptr<InputFile>, std::string> voice{};
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<std::string> caption;
        std::optional<std::string> parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> caption_entities;
        std::optional<int64_t> duration;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters;
        std::shared_ptr<ReplyParameters> reply_parameters;
        ReplyMarkup reply_markup{};
    };

    drogon::Task<std::shared_ptr<Message>> sendVoice(ChatId chat_id,
                                                     std::variant<std::shared_ptr<InputFile>, std::string> voice,
                                                     std::optional<std::string> business_connection_id = std::nullopt,
                                                     std::optional<int64_t> message_thread_id = std::nullopt,
                                                     std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                     std::optional<std::string> caption = std::nullopt,
                                                     std::optional<std::string> parse_mode = std::nullopt,
                                                     std::vector<std::shared_ptr<MessageEntity>> caption_entities = {},
                                                     std::optional<int64_t> duration = std::nullopt,
                                                     std::optional<bool> disable_notification = std::nullopt,
                                                     std::optional<bool> protect_content = std::nullopt,
                                                     std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                     std::optional<std::string> message_effect_id = std::nullopt,
                                                     std::shared_ptr<SuggestedPostParameters> suggested_post_parameters = nullptr,
                                                     std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                     ReplyMarkup reply_markup = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        if (auto* _p = std::get_if<std::shared_ptr<InputFile>>(&voice)) {
            if (*_p) {
                payload["voice"] = "attach://" + (*_p)->filename;
                _uploads.push_back({"voice", *_p});
            }
        }
        if (auto* _p = std::get_if<std::string>(&voice)) {
            payload["voice"] = *_p;
        }
        if (caption.has_value()) {
            payload["caption"] = caption.value();
        }
        if (parse_mode.has_value()) {
            payload["parse_mode"] = parse_mode.value();
        }
        if (!caption_entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : caption_entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["caption_entities"] = std::move(_arr);
        }
        if (duration.has_value()) {
            payload["duration"] = duration.value();
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (suggested_post_parameters) {
            json _sub;
            to_json(_sub, *suggested_post_parameters);
            payload["suggested_post_parameters"] = std::move(_sub);
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (auto* _p = std::get_if<std::shared_ptr<InlineKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardRemove>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ForceReply>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendVoice", _body)
            : co_await request_->uploadFiles(token_ + "/sendVoice", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> sendVoice(SendVoiceArgs args) {
        co_return co_await sendVoice(std::move(args.chat_id),
            std::move(args.voice),
            std::move(args.business_connection_id),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.caption),
            std::move(args.parse_mode),
            std::move(args.caption_entities),
            std::move(args.duration),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.message_effect_id),
            std::move(args.suggested_post_parameters),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * As of v.4.0, Telegram clients support rounded square MPEG4 videos of up to 1 minute long.
     * Use this method to send video messages. On success, the sent Message is returned.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param video_note [required] Video note to send.
     * @param duration [optional] Optional.
     * @param length [optional] Optional.
     * @param thumbnail [optional] Optional.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param suggested_post_parameters [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#sendvideonote
     */
    struct SendVideoNoteArgs {
        ChatId chat_id{};
        std::variant<std::shared_ptr<InputFile>, std::string> video_note{};
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<int64_t> duration;
        std::optional<int64_t> length;
        std::variant<std::shared_ptr<InputFile>, std::string> thumbnail{};
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters;
        std::shared_ptr<ReplyParameters> reply_parameters;
        ReplyMarkup reply_markup{};
    };

    drogon::Task<std::shared_ptr<Message>> sendVideoNote(ChatId chat_id,
                                                         std::variant<std::shared_ptr<InputFile>, std::string> video_note,
                                                         std::optional<std::string> business_connection_id = std::nullopt,
                                                         std::optional<int64_t> message_thread_id = std::nullopt,
                                                         std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                         std::optional<int64_t> duration = std::nullopt,
                                                         std::optional<int64_t> length = std::nullopt,
                                                         std::variant<std::shared_ptr<InputFile>, std::string> thumbnail = {},
                                                         std::optional<bool> disable_notification = std::nullopt,
                                                         std::optional<bool> protect_content = std::nullopt,
                                                         std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                         std::optional<std::string> message_effect_id = std::nullopt,
                                                         std::shared_ptr<SuggestedPostParameters> suggested_post_parameters = nullptr,
                                                         std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                         ReplyMarkup reply_markup = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        if (auto* _p = std::get_if<std::shared_ptr<InputFile>>(&video_note)) {
            if (*_p) {
                payload["video_note"] = "attach://" + (*_p)->filename;
                _uploads.push_back({"video_note", *_p});
            }
        }
        if (auto* _p = std::get_if<std::string>(&video_note)) {
            payload["video_note"] = *_p;
        }
        if (duration.has_value()) {
            payload["duration"] = duration.value();
        }
        if (length.has_value()) {
            payload["length"] = length.value();
        }
        if (auto* _p = std::get_if<std::shared_ptr<InputFile>>(&thumbnail)) {
            if (*_p) {
                payload["thumbnail"] = "attach://" + (*_p)->filename;
                _uploads.push_back({"thumbnail", *_p});
            }
        }
        if (auto* _p = std::get_if<std::string>(&thumbnail)) {
            payload["thumbnail"] = *_p;
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (suggested_post_parameters) {
            json _sub;
            to_json(_sub, *suggested_post_parameters);
            payload["suggested_post_parameters"] = std::move(_sub);
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (auto* _p = std::get_if<std::shared_ptr<InlineKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardRemove>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ForceReply>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendVideoNote", _body)
            : co_await request_->uploadFiles(token_ + "/sendVideoNote", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> sendVideoNote(SendVideoNoteArgs args) {
        co_return co_await sendVideoNote(std::move(args.chat_id),
            std::move(args.video_note),
            std::move(args.business_connection_id),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.duration),
            std::move(args.length),
            std::move(args.thumbnail),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.message_effect_id),
            std::move(args.suggested_post_parameters),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to send paid media. On success, the sent Message is returned.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param star_count [required] The number of Telegram Stars that must be paid to buy access to the media; 1-25000.
     * @param media [required] A JSON-serialized array describing the media to be sent; up to 10 items.
     * @param payload [optional] Optional.
     * @param caption [optional] Optional.
     * @param parse_mode [optional] Optional.
     * @param caption_entities [optional] Optional.
     * @param show_caption_above_media [optional] Optional.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param suggested_post_parameters [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#sendpaidmedia
     */
    struct SendPaidMediaArgs {
        ChatId chat_id{};
        int64_t star_count{0};
        std::vector<InputPaidMedia> media;
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<std::string> invoice_payload;
        std::optional<std::string> caption;
        std::optional<std::string> parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> caption_entities;
        std::optional<bool> show_caption_above_media;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters;
        std::shared_ptr<ReplyParameters> reply_parameters;
        ReplyMarkup reply_markup{};
    };

    drogon::Task<std::shared_ptr<Message>> sendPaidMedia(ChatId chat_id,
                                                         int64_t star_count,
                                                         std::vector<InputPaidMedia> media,
                                                         std::optional<std::string> business_connection_id = std::nullopt,
                                                         std::optional<int64_t> message_thread_id = std::nullopt,
                                                         std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                         std::optional<std::string> invoice_payload = std::nullopt,
                                                         std::optional<std::string> caption = std::nullopt,
                                                         std::optional<std::string> parse_mode = std::nullopt,
                                                         std::vector<std::shared_ptr<MessageEntity>> caption_entities = {},
                                                         std::optional<bool> show_caption_above_media = std::nullopt,
                                                         std::optional<bool> disable_notification = std::nullopt,
                                                         std::optional<bool> protect_content = std::nullopt,
                                                         std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                         std::shared_ptr<SuggestedPostParameters> suggested_post_parameters = nullptr,
                                                         std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                         ReplyMarkup reply_markup = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        payload["star_count"] = star_count;
        {
            json _arr = json::array();
            for (const auto& _item : media) {
                {
                    json _e; to_json(_e, _item); _arr.push_back(std::move(_e));
                }
            }
            payload["media"] = std::move(_arr);
        }
        if (invoice_payload.has_value()) {
            payload["payload"] = invoice_payload.value();
        }
        if (caption.has_value()) {
            payload["caption"] = caption.value();
        }
        if (parse_mode.has_value()) {
            payload["parse_mode"] = parse_mode.value();
        }
        if (!caption_entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : caption_entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["caption_entities"] = std::move(_arr);
        }
        if (show_caption_above_media.has_value()) {
            payload["show_caption_above_media"] = show_caption_above_media.value();
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (suggested_post_parameters) {
            json _sub;
            to_json(_sub, *suggested_post_parameters);
            payload["suggested_post_parameters"] = std::move(_sub);
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (auto* _p = std::get_if<std::shared_ptr<InlineKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardRemove>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ForceReply>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendPaidMedia", _body)
            : co_await request_->uploadFiles(token_ + "/sendPaidMedia", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> sendPaidMedia(SendPaidMediaArgs args) {
        co_return co_await sendPaidMedia(std::move(args.chat_id),
            std::move(args.star_count),
            std::move(args.media),
            std::move(args.business_connection_id),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.invoice_payload),
            std::move(args.caption),
            std::move(args.parse_mode),
            std::move(args.caption_entities),
            std::move(args.show_caption_above_media),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.suggested_post_parameters),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to send a group of photos, live photos, videos, documents or audios as an
     * album. Documents and audio files can be only grouped in an album with messages of the
     * same type. On success, an array of Message objects that were sent is returned.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param media [required] A JSON-serialized array describing messages to be sent, must include 2-10 items.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @returns std::vector<std::shared_ptr<Message>>
     * @see https://core.telegram.org/bots/api#sendmediagroup
     */
    struct SendMediaGroupArgs {
        ChatId chat_id{};
        std::vector<std::variant<std::shared_ptr<InputMediaAudio>, std::shared_ptr<InputMediaDocument>, std::shared_ptr<InputMediaLivePhoto>, std::shared_ptr<InputMediaPhoto>, std::shared_ptr<InputMediaVideo>>> media;
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<ReplyParameters> reply_parameters;
    };

    drogon::Task<std::vector<std::shared_ptr<Message>>> sendMediaGroup(ChatId chat_id,
                                                                       std::vector<MediaVariant> media,
                                                                       std::optional<std::string> business_connection_id = std::nullopt,
                                                                       std::optional<int64_t> message_thread_id = std::nullopt,
                                                                       std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                                       std::optional<bool> disable_notification = std::nullopt,
                                                                       std::optional<bool> protect_content = std::nullopt,
                                                                       std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                                       std::optional<std::string> message_effect_id = std::nullopt,
                                                                       std::shared_ptr<ReplyParameters> reply_parameters = nullptr) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        {
            json _arr = json::array();
            for (const auto& _item : media) {
                json _e;
                std::visit([&](const auto& ptr) {
                    if (ptr) to_json(_e, *ptr);
                }, _item);
                _arr.push_back(std::move(_e));
            }
            payload["media"] = std::move(_arr);
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendMediaGroup", _body)
            : co_await request_->uploadFiles(token_ + "/sendMediaGroup", _body, _uploads);
        co_return parse_response<std::vector<std::shared_ptr<Message>>>(_resp).result.value();
    }

    drogon::Task<std::vector<std::shared_ptr<Message>>> sendMediaGroup(SendMediaGroupArgs args) {
        co_return co_await sendMediaGroup(std::move(args.chat_id),
            std::move(args.media),
            std::move(args.business_connection_id),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.message_effect_id),
            std::move(args.reply_parameters));
    }

    /**
     * Use this method to send point on the map. On success, the sent Message is returned.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param latitude [required] Latitude of the location.
     * @param longitude [required] Longitude of the location.
     * @param horizontal_accuracy [optional] Optional.
     * @param live_period [optional] Optional.
     * @param heading [optional] Optional.
     * @param proximity_alert_radius [optional] Optional.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param suggested_post_parameters [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#sendlocation
     */
    struct SendLocationArgs {
        ChatId chat_id{};
        double latitude{0.0};
        double longitude{0.0};
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<double> horizontal_accuracy;
        std::optional<int64_t> live_period;
        std::optional<int64_t> heading;
        std::optional<int64_t> proximity_alert_radius;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters;
        std::shared_ptr<ReplyParameters> reply_parameters;
        ReplyMarkup reply_markup{};
    };

    drogon::Task<std::shared_ptr<Message>> sendLocation(ChatId chat_id,
                                                        double latitude,
                                                        double longitude,
                                                        std::optional<std::string> business_connection_id = std::nullopt,
                                                        std::optional<int64_t> message_thread_id = std::nullopt,
                                                        std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                        std::optional<double> horizontal_accuracy = std::nullopt,
                                                        std::optional<int64_t> live_period = std::nullopt,
                                                        std::optional<int64_t> heading = std::nullopt,
                                                        std::optional<int64_t> proximity_alert_radius = std::nullopt,
                                                        std::optional<bool> disable_notification = std::nullopt,
                                                        std::optional<bool> protect_content = std::nullopt,
                                                        std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                        std::optional<std::string> message_effect_id = std::nullopt,
                                                        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters = nullptr,
                                                        std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                        ReplyMarkup reply_markup = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        payload["latitude"] = latitude;
        payload["longitude"] = longitude;
        if (horizontal_accuracy.has_value()) {
            payload["horizontal_accuracy"] = horizontal_accuracy.value();
        }
        if (live_period.has_value()) {
            payload["live_period"] = live_period.value();
        }
        if (heading.has_value()) {
            payload["heading"] = heading.value();
        }
        if (proximity_alert_radius.has_value()) {
            payload["proximity_alert_radius"] = proximity_alert_radius.value();
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (suggested_post_parameters) {
            json _sub;
            to_json(_sub, *suggested_post_parameters);
            payload["suggested_post_parameters"] = std::move(_sub);
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (auto* _p = std::get_if<std::shared_ptr<InlineKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardRemove>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ForceReply>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendLocation", _body)
            : co_await request_->uploadFiles(token_ + "/sendLocation", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> sendLocation(SendLocationArgs args) {
        co_return co_await sendLocation(std::move(args.chat_id),
            std::move(args.latitude),
            std::move(args.longitude),
            std::move(args.business_connection_id),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.horizontal_accuracy),
            std::move(args.live_period),
            std::move(args.heading),
            std::move(args.proximity_alert_radius),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.message_effect_id),
            std::move(args.suggested_post_parameters),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to send information about a venue. On success, the sent Message is
     * returned.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param latitude [required] Latitude of the venue.
     * @param longitude [required] Longitude of the venue.
     * @param title [required] Name of the venue.
     * @param address [required] Address of the venue.
     * @param foursquare_id [optional] Optional.
     * @param foursquare_type [optional] Optional.
     * @param google_place_id [optional] Optional.
     * @param google_place_type [optional] Optional.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param suggested_post_parameters [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#sendvenue
     */
    struct SendVenueArgs {
        ChatId chat_id{};
        double latitude{0.0};
        double longitude{0.0};
        std::string title{""};
        std::string address{""};
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<std::string> foursquare_id;
        std::optional<std::string> foursquare_type;
        std::optional<std::string> google_place_id;
        std::optional<std::string> google_place_type;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters;
        std::shared_ptr<ReplyParameters> reply_parameters;
        ReplyMarkup reply_markup{};
    };

    drogon::Task<std::shared_ptr<Message>> sendVenue(ChatId chat_id,
                                                     double latitude,
                                                     double longitude,
                                                     std::string title,
                                                     std::string address,
                                                     std::optional<std::string> business_connection_id = std::nullopt,
                                                     std::optional<int64_t> message_thread_id = std::nullopt,
                                                     std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                     std::optional<std::string> foursquare_id = std::nullopt,
                                                     std::optional<std::string> foursquare_type = std::nullopt,
                                                     std::optional<std::string> google_place_id = std::nullopt,
                                                     std::optional<std::string> google_place_type = std::nullopt,
                                                     std::optional<bool> disable_notification = std::nullopt,
                                                     std::optional<bool> protect_content = std::nullopt,
                                                     std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                     std::optional<std::string> message_effect_id = std::nullopt,
                                                     std::shared_ptr<SuggestedPostParameters> suggested_post_parameters = nullptr,
                                                     std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                     ReplyMarkup reply_markup = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        payload["latitude"] = latitude;
        payload["longitude"] = longitude;
        payload["title"] = title;
        payload["address"] = address;
        if (foursquare_id.has_value()) {
            payload["foursquare_id"] = foursquare_id.value();
        }
        if (foursquare_type.has_value()) {
            payload["foursquare_type"] = foursquare_type.value();
        }
        if (google_place_id.has_value()) {
            payload["google_place_id"] = google_place_id.value();
        }
        if (google_place_type.has_value()) {
            payload["google_place_type"] = google_place_type.value();
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (suggested_post_parameters) {
            json _sub;
            to_json(_sub, *suggested_post_parameters);
            payload["suggested_post_parameters"] = std::move(_sub);
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (auto* _p = std::get_if<std::shared_ptr<InlineKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardRemove>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ForceReply>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendVenue", _body)
            : co_await request_->uploadFiles(token_ + "/sendVenue", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> sendVenue(SendVenueArgs args) {
        co_return co_await sendVenue(std::move(args.chat_id),
            std::move(args.latitude),
            std::move(args.longitude),
            std::move(args.title),
            std::move(args.address),
            std::move(args.business_connection_id),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.foursquare_id),
            std::move(args.foursquare_type),
            std::move(args.google_place_id),
            std::move(args.google_place_type),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.message_effect_id),
            std::move(args.suggested_post_parameters),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to send phone contacts. On success, the sent Message is returned.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param phone_number [required] Contact's phone number.
     * @param first_name [required] Contact's first name.
     * @param last_name [optional] Optional.
     * @param vcard [optional] Optional.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param suggested_post_parameters [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#sendcontact
     */
    struct SendContactArgs {
        ChatId chat_id{};
        std::string phone_number{""};
        std::string first_name{""};
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<std::string> last_name;
        std::optional<std::string> vcard;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters;
        std::shared_ptr<ReplyParameters> reply_parameters;
        ReplyMarkup reply_markup{};
    };

    drogon::Task<std::shared_ptr<Message>> sendContact(ChatId chat_id,
                                                       std::string phone_number,
                                                       std::string first_name,
                                                       std::optional<std::string> business_connection_id = std::nullopt,
                                                       std::optional<int64_t> message_thread_id = std::nullopt,
                                                       std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                       std::optional<std::string> last_name = std::nullopt,
                                                       std::optional<std::string> vcard = std::nullopt,
                                                       std::optional<bool> disable_notification = std::nullopt,
                                                       std::optional<bool> protect_content = std::nullopt,
                                                       std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                       std::optional<std::string> message_effect_id = std::nullopt,
                                                       std::shared_ptr<SuggestedPostParameters> suggested_post_parameters = nullptr,
                                                       std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                       ReplyMarkup reply_markup = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        payload["phone_number"] = phone_number;
        payload["first_name"] = first_name;
        if (last_name.has_value()) {
            payload["last_name"] = last_name.value();
        }
        if (vcard.has_value()) {
            payload["vcard"] = vcard.value();
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (suggested_post_parameters) {
            json _sub;
            to_json(_sub, *suggested_post_parameters);
            payload["suggested_post_parameters"] = std::move(_sub);
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (auto* _p = std::get_if<std::shared_ptr<InlineKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardRemove>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ForceReply>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendContact", _body)
            : co_await request_->uploadFiles(token_ + "/sendContact", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> sendContact(SendContactArgs args) {
        co_return co_await sendContact(std::move(args.chat_id),
            std::move(args.phone_number),
            std::move(args.first_name),
            std::move(args.business_connection_id),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.last_name),
            std::move(args.vcard),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.message_effect_id),
            std::move(args.suggested_post_parameters),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to send a native poll. On success, the sent Message is returned.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param question [required] Poll question, 1-300 characters.
     * @param question_parse_mode [optional] Optional.
     * @param question_entities [optional] Optional.
     * @param options [required] A JSON-serialized list of 1-12 answer options.
     * @param is_anonymous [optional] Optional.
     * @param type [optional] Optional.
     * @param allows_multiple_answers [optional] Optional.
     * @param allows_revoting [optional] Optional.
     * @param shuffle_options [optional] Optional.
     * @param allow_adding_options [optional] Optional.
     * @param hide_results_until_closes [optional] Optional.
     * @param members_only [optional] Optional.
     * @param country_codes [optional] Optional.
     * @param correct_option_ids [optional] Optional.
     * @param explanation [optional] Optional.
     * @param explanation_parse_mode [optional] Optional.
     * @param explanation_entities [optional] Optional.
     * @param explanation_media [optional] Optional.
     * @param open_period [optional] Optional.
     * @param close_date [optional] Optional.
     * @param is_closed [optional] Optional.
     * @param description [optional] Optional.
     * @param description_parse_mode [optional] Optional.
     * @param description_entities [optional] Optional.
     * @param media [optional] Optional.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#sendpoll
     */
    struct SendPollArgs {
        ChatId chat_id{};
        std::string question{""};
        std::vector<std::shared_ptr<InputPollOption>> options;
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_thread_id;
        std::optional<std::string> question_parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> question_entities;
        std::optional<bool> is_anonymous;
        std::optional<std::string> type;
        std::optional<bool> allows_multiple_answers;
        std::optional<bool> allows_revoting;
        std::optional<bool> shuffle_options;
        std::optional<bool> allow_adding_options;
        std::optional<bool> hide_results_until_closes;
        std::optional<bool> members_only;
        std::vector<std::string> country_codes;
        std::vector<int64_t> correct_option_ids;
        std::optional<std::string> explanation;
        std::optional<std::string> explanation_parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> explanation_entities;
        std::optional<InputPollMedia> explanation_media;
        std::optional<int64_t> open_period;
        std::optional<int64_t> close_date;
        std::optional<bool> is_closed;
        std::optional<std::string> description;
        std::optional<std::string> description_parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> description_entities;
        std::optional<InputPollMedia> media;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<ReplyParameters> reply_parameters;
        ReplyMarkup reply_markup{};
    };

    drogon::Task<std::shared_ptr<Message>> sendPoll(ChatId chat_id,
                                                    std::string question,
                                                    std::vector<std::shared_ptr<InputPollOption>> options,
                                                    std::optional<std::string> business_connection_id = std::nullopt,
                                                    std::optional<int64_t> message_thread_id = std::nullopt,
                                                    std::optional<std::string> question_parse_mode = std::nullopt,
                                                    std::vector<std::shared_ptr<MessageEntity>> question_entities = {},
                                                    std::optional<bool> is_anonymous = std::nullopt,
                                                    std::optional<std::string> type = std::nullopt,
                                                    std::optional<bool> allows_multiple_answers = std::nullopt,
                                                    std::optional<bool> allows_revoting = std::nullopt,
                                                    std::optional<bool> shuffle_options = std::nullopt,
                                                    std::optional<bool> allow_adding_options = std::nullopt,
                                                    std::optional<bool> hide_results_until_closes = std::nullopt,
                                                    std::optional<bool> members_only = std::nullopt,
                                                    std::vector<std::string> country_codes = {},
                                                    std::vector<int64_t> correct_option_ids = {},
                                                    std::optional<std::string> explanation = std::nullopt,
                                                    std::optional<std::string> explanation_parse_mode = std::nullopt,
                                                    std::vector<std::shared_ptr<MessageEntity>> explanation_entities = {},
                                                    std::optional<InputPollMedia> explanation_media = std::nullopt,
                                                    std::optional<int64_t> open_period = std::nullopt,
                                                    std::optional<int64_t> close_date = std::nullopt,
                                                    std::optional<bool> is_closed = std::nullopt,
                                                    std::optional<std::string> description = std::nullopt,
                                                    std::optional<std::string> description_parse_mode = std::nullopt,
                                                    std::vector<std::shared_ptr<MessageEntity>> description_entities = {},
                                                    std::optional<InputPollMedia> media = std::nullopt,
                                                    std::optional<bool> disable_notification = std::nullopt,
                                                    std::optional<bool> protect_content = std::nullopt,
                                                    std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                    std::optional<std::string> message_effect_id = std::nullopt,
                                                    std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                    ReplyMarkup reply_markup = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        payload["question"] = question;
        if (question_parse_mode.has_value()) {
            payload["question_parse_mode"] = question_parse_mode.value();
        }
        if (!question_entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : question_entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["question_entities"] = std::move(_arr);
        }
        {
            json _arr = json::array();
            for (const auto& _item : options) {
                {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["options"] = std::move(_arr);
        }
        if (is_anonymous.has_value()) {
            payload["is_anonymous"] = is_anonymous.value();
        }
        if (type.has_value()) {
            payload["type"] = type.value();
        }
        if (allows_multiple_answers.has_value()) {
            payload["allows_multiple_answers"] = allows_multiple_answers.value();
        }
        if (allows_revoting.has_value()) {
            payload["allows_revoting"] = allows_revoting.value();
        }
        if (shuffle_options.has_value()) {
            payload["shuffle_options"] = shuffle_options.value();
        }
        if (allow_adding_options.has_value()) {
            payload["allow_adding_options"] = allow_adding_options.value();
        }
        if (hide_results_until_closes.has_value()) {
            payload["hide_results_until_closes"] = hide_results_until_closes.value();
        }
        if (members_only.has_value()) {
            payload["members_only"] = members_only.value();
        }
        if (!country_codes.empty()) {
            json _arr = json::array();
            for (const auto& _item : country_codes) {
                _arr.push_back(_item);
            }
            payload["country_codes"] = std::move(_arr);
        }
        if (!correct_option_ids.empty()) {
            json _arr = json::array();
            for (const auto& _item : correct_option_ids) {
                _arr.push_back(_item);
            }
            payload["correct_option_ids"] = std::move(_arr);
        }
        if (explanation.has_value()) {
            payload["explanation"] = explanation.value();
        }
        if (explanation_parse_mode.has_value()) {
            payload["explanation_parse_mode"] = explanation_parse_mode.value();
        }
        if (!explanation_entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : explanation_entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["explanation_entities"] = std::move(_arr);
        }
        if (explanation_media.has_value()) {
            json _sub;
            to_json(_sub, explanation_media.value());
            payload["explanation_media"] = std::move(_sub);
        }
        if (open_period.has_value()) {
            payload["open_period"] = open_period.value();
        }
        if (close_date.has_value()) {
            payload["close_date"] = close_date.value();
        }
        if (is_closed.has_value()) {
            payload["is_closed"] = is_closed.value();
        }
        if (description.has_value()) {
            payload["description"] = description.value();
        }
        if (description_parse_mode.has_value()) {
            payload["description_parse_mode"] = description_parse_mode.value();
        }
        if (!description_entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : description_entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["description_entities"] = std::move(_arr);
        }
        if (media.has_value()) {
            json _sub;
            to_json(_sub, media.value());
            payload["media"] = std::move(_sub);
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (auto* _p = std::get_if<std::shared_ptr<InlineKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardRemove>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ForceReply>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendPoll", _body)
            : co_await request_->uploadFiles(token_ + "/sendPoll", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> sendPoll(SendPollArgs args) {
        co_return co_await sendPoll(std::move(args.chat_id),
            std::move(args.question),
            std::move(args.options),
            std::move(args.business_connection_id),
            std::move(args.message_thread_id),
            std::move(args.question_parse_mode),
            std::move(args.question_entities),
            std::move(args.is_anonymous),
            std::move(args.type),
            std::move(args.allows_multiple_answers),
            std::move(args.allows_revoting),
            std::move(args.shuffle_options),
            std::move(args.allow_adding_options),
            std::move(args.hide_results_until_closes),
            std::move(args.members_only),
            std::move(args.country_codes),
            std::move(args.correct_option_ids),
            std::move(args.explanation),
            std::move(args.explanation_parse_mode),
            std::move(args.explanation_entities),
            std::move(args.explanation_media),
            std::move(args.open_period),
            std::move(args.close_date),
            std::move(args.is_closed),
            std::move(args.description),
            std::move(args.description_parse_mode),
            std::move(args.description_entities),
            std::move(args.media),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.message_effect_id),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to send a checklist on behalf of a connected business account. On
     * success, the sent Message is returned.
     *
     * @param business_connection_id [required] Unique identifier of the business connection on behalf of which the message will be sent.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot in the format @username.
     * @param checklist [required] A JSON-serialized object for the checklist to send.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#sendchecklist
     */
    struct SendChecklistArgs {
        std::string business_connection_id{""};
        ChatId chat_id{};
        std::shared_ptr<InputChecklist> checklist;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<ReplyParameters> reply_parameters;
        std::shared_ptr<InlineKeyboardMarkup> reply_markup;
    };

    drogon::Task<std::shared_ptr<Message>> sendChecklist(std::string business_connection_id,
                                                         ChatId chat_id,
                                                         std::shared_ptr<InputChecklist> checklist,
                                                         std::optional<bool> disable_notification = std::nullopt,
                                                         std::optional<bool> protect_content = std::nullopt,
                                                         std::optional<std::string> message_effect_id = std::nullopt,
                                                         std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                         std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        {
            json _sub;
            to_json(_sub, *checklist);
            payload["checklist"] = std::move(_sub);
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (reply_markup) {
            json _sub;
            to_json(_sub, *reply_markup);
            payload["reply_markup"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendChecklist", _body)
            : co_await request_->uploadFiles(token_ + "/sendChecklist", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> sendChecklist(SendChecklistArgs args) {
        co_return co_await sendChecklist(std::move(args.business_connection_id),
            std::move(args.chat_id),
            std::move(args.checklist),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.message_effect_id),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to send an animated emoji that will display a random value. On success,
     * the sent Message is returned.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param emoji [optional] Optional.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param suggested_post_parameters [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#senddice
     */
    struct SendDiceArgs {
        ChatId chat_id{};
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<std::string> emoji;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters;
        std::shared_ptr<ReplyParameters> reply_parameters;
        ReplyMarkup reply_markup{};
    };

    drogon::Task<std::shared_ptr<Message>> sendDice(ChatId chat_id,
                                                    std::optional<std::string> business_connection_id = std::nullopt,
                                                    std::optional<int64_t> message_thread_id = std::nullopt,
                                                    std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                    std::optional<std::string> emoji = std::nullopt,
                                                    std::optional<bool> disable_notification = std::nullopt,
                                                    std::optional<bool> protect_content = std::nullopt,
                                                    std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                    std::optional<std::string> message_effect_id = std::nullopt,
                                                    std::shared_ptr<SuggestedPostParameters> suggested_post_parameters = nullptr,
                                                    std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                    ReplyMarkup reply_markup = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        if (emoji.has_value()) {
            payload["emoji"] = emoji.value();
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (suggested_post_parameters) {
            json _sub;
            to_json(_sub, *suggested_post_parameters);
            payload["suggested_post_parameters"] = std::move(_sub);
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (auto* _p = std::get_if<std::shared_ptr<InlineKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardRemove>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ForceReply>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendDice", _body)
            : co_await request_->uploadFiles(token_ + "/sendDice", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> sendDice(SendDiceArgs args) {
        co_return co_await sendDice(std::move(args.chat_id),
            std::move(args.business_connection_id),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.emoji),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.message_effect_id),
            std::move(args.suggested_post_parameters),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to stream a partial message to a user while the message is being
     * generated. Note that the streamed draft is ephemeral and acts as a temporary 30-second
     * preview - once the output is finalized, you must call sendMessage with the complete
     * message to persist it in the user's chat. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target private chat.
     * @param message_thread_id [optional] Optional.
     * @param draft_id [required] Unique identifier of the message draft; must be non-zero.
     * @param text [optional] Optional.
     * @param parse_mode [optional] Optional.
     * @param entities [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#sendmessagedraft
     */
    struct SendMessageDraftArgs {
        int64_t chat_id{0};
        int64_t draft_id{0};
        std::optional<int64_t> message_thread_id;
        std::optional<std::string> text;
        std::optional<std::string> parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> entities;
    };

    drogon::Task<bool> sendMessageDraft(int64_t chat_id,
                                        int64_t draft_id,
                                        std::optional<int64_t> message_thread_id = std::nullopt,
                                        std::optional<std::string> text = std::nullopt,
                                        std::optional<std::string> parse_mode = std::nullopt,
                                        std::vector<std::shared_ptr<MessageEntity>> entities = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["chat_id"] = chat_id;
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        payload["draft_id"] = draft_id;
        if (text.has_value()) {
            payload["text"] = text.value();
        }
        if (parse_mode.has_value()) {
            payload["parse_mode"] = parse_mode.value();
        }
        if (!entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["entities"] = std::move(_arr);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendMessageDraft", _body)
            : co_await request_->uploadFiles(token_ + "/sendMessageDraft", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> sendMessageDraft(SendMessageDraftArgs args) {
        co_return co_await sendMessageDraft(std::move(args.chat_id),
            std::move(args.draft_id),
            std::move(args.message_thread_id),
            std::move(args.text),
            std::move(args.parse_mode),
            std::move(args.entities));
    }

    /**
     * Use this method when you need to tell the user that something is happening on the bot's
     * side. The status is set for 5 seconds or less (when a message arrives from your bot,
     * Telegram clients clear its typing status). Returns True on success.
     * Example: The ImageBot needs some time to process a request and upload the image. Instead
     * of sending a text message along the lines of 'Retrieving image, please wait…', the bot
     * may use sendChatAction with action = upload_photo. The user will see a 'sending photo'
     * status for the bot.
     * We only recommend using this method when a response from the bot will take a noticeable
     * amount of time to arrive.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param action [required] Type of action to broadcast.
     * @returns bool
     * @see https://core.telegram.org/bots/api#sendchataction
     */
    struct SendChatActionArgs {
        ChatId chat_id{};
        std::string action{""};
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_thread_id;
    };

    drogon::Task<bool> sendChatAction(ChatId chat_id,
                                      std::string action,
                                      std::optional<std::string> business_connection_id = std::nullopt,
                                      std::optional<int64_t> message_thread_id = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        payload["action"] = action;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendChatAction", _body)
            : co_await request_->uploadFiles(token_ + "/sendChatAction", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> sendChatAction(SendChatActionArgs args) {
        co_return co_await sendChatAction(std::move(args.chat_id),
            std::move(args.action),
            std::move(args.business_connection_id),
            std::move(args.message_thread_id));
    }

    /**
     * Use this method to change the chosen reactions on a message. Service messages of some
     * types can't be reacted to. Automatically forwarded messages from a channel to its
     * discussion group have the same available reactions as messages in the channel. Bots can't
     * use paid reactions. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_id [required] Identifier of the target message.
     * @param reaction [optional] Optional.
     * @param is_big [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setmessagereaction
     */
    struct SetMessageReactionArgs {
        ChatId chat_id{};
        int64_t message_id{0};
        std::vector<ReactionType> reaction;
        std::optional<bool> is_big;
    };

    drogon::Task<bool> setMessageReaction(ChatId chat_id,
                                          int64_t message_id,
                                          std::vector<ReactionType> reaction = {},
                                          std::optional<bool> is_big = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["message_id"] = message_id;
        if (!reaction.empty()) {
            json _arr = json::array();
            for (const auto& _item : reaction) {
                {
                    json _e; to_json(_e, _item); _arr.push_back(std::move(_e));
                }
            }
            payload["reaction"] = std::move(_arr);
        }
        if (is_big.has_value()) {
            payload["is_big"] = is_big.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setMessageReaction", _body)
            : co_await request_->uploadFiles(token_ + "/setMessageReaction", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setMessageReaction(SetMessageReactionArgs args) {
        co_return co_await setMessageReaction(std::move(args.chat_id),
            std::move(args.message_id),
            std::move(args.reaction),
            std::move(args.is_big));
    }

    /**
     * Use this method to get a list of profile pictures for a user. Returns a UserProfilePhotos
     * object.
     *
     * @param user_id [required] Unique identifier of the target user.
     * @param offset [optional] Optional.
     * @param limit [optional] Optional.
     * @returns std::shared_ptr<UserProfilePhotos>
     * @see https://core.telegram.org/bots/api#getuserprofilephotos
     */
    struct GetUserProfilePhotosArgs {
        int64_t user_id{0};
        std::optional<int64_t> offset;
        std::optional<int64_t> limit;
    };

    drogon::Task<std::shared_ptr<UserProfilePhotos>> getUserProfilePhotos(int64_t user_id,
                                                                          std::optional<int64_t> offset = std::nullopt,
                                                                          std::optional<int64_t> limit = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        if (offset.has_value()) {
            payload["offset"] = offset.value();
        }
        if (limit.has_value()) {
            payload["limit"] = limit.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getUserProfilePhotos", _body)
            : co_await request_->uploadFiles(token_ + "/getUserProfilePhotos", _body, _uploads);
        co_return parse_response<std::shared_ptr<UserProfilePhotos>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<UserProfilePhotos>> getUserProfilePhotos(GetUserProfilePhotosArgs args) {
        co_return co_await getUserProfilePhotos(std::move(args.user_id),
            std::move(args.offset),
            std::move(args.limit));
    }

    /**
     * Use this method to get a list of profile audios for a user. Returns a UserProfileAudios
     * object.
     *
     * @param user_id [required] Unique identifier of the target user.
     * @param offset [optional] Optional.
     * @param limit [optional] Optional.
     * @returns std::shared_ptr<UserProfileAudios>
     * @see https://core.telegram.org/bots/api#getuserprofileaudios
     */
    struct GetUserProfileAudiosArgs {
        int64_t user_id{0};
        std::optional<int64_t> offset;
        std::optional<int64_t> limit;
    };

    drogon::Task<std::shared_ptr<UserProfileAudios>> getUserProfileAudios(int64_t user_id,
                                                                          std::optional<int64_t> offset = std::nullopt,
                                                                          std::optional<int64_t> limit = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        if (offset.has_value()) {
            payload["offset"] = offset.value();
        }
        if (limit.has_value()) {
            payload["limit"] = limit.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getUserProfileAudios", _body)
            : co_await request_->uploadFiles(token_ + "/getUserProfileAudios", _body, _uploads);
        co_return parse_response<std::shared_ptr<UserProfileAudios>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<UserProfileAudios>> getUserProfileAudios(GetUserProfileAudiosArgs args) {
        co_return co_await getUserProfileAudios(std::move(args.user_id),
            std::move(args.offset),
            std::move(args.limit));
    }

    /**
     * Changes the emoji status for a given user that previously allowed the bot to manage their
     * emoji status via the Mini App method requestEmojiStatusAccess. Returns True on success.
     *
     * @param user_id [required] Unique identifier of the target user.
     * @param emoji_status_custom_emoji_id [optional] Optional.
     * @param emoji_status_expiration_date [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setuseremojistatus
     */
    struct SetUserEmojiStatusArgs {
        int64_t user_id{0};
        std::optional<std::string> emoji_status_custom_emoji_id;
        std::optional<int64_t> emoji_status_expiration_date;
    };

    drogon::Task<bool> setUserEmojiStatus(int64_t user_id,
                                          std::optional<std::string> emoji_status_custom_emoji_id = std::nullopt,
                                          std::optional<int64_t> emoji_status_expiration_date = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        if (emoji_status_custom_emoji_id.has_value()) {
            payload["emoji_status_custom_emoji_id"] = emoji_status_custom_emoji_id.value();
        }
        if (emoji_status_expiration_date.has_value()) {
            payload["emoji_status_expiration_date"] = emoji_status_expiration_date.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setUserEmojiStatus", _body)
            : co_await request_->uploadFiles(token_ + "/setUserEmojiStatus", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setUserEmojiStatus(SetUserEmojiStatusArgs args) {
        co_return co_await setUserEmojiStatus(std::move(args.user_id),
            std::move(args.emoji_status_custom_emoji_id),
            std::move(args.emoji_status_expiration_date));
    }

    /**
     * Use this method to get basic information about a file and prepare it for downloading. For
     * the moment, bots can download files of up to 20MB in size. On success, a File object is
     * returned. The file can then be downloaded via the link
     * https://api.telegram.org/file/bot<token>/<file_path>, where <file_path> is taken from the
     * response. It is guaranteed that the link will be valid for at least 1 hour. When the link
     * expires, a new one can be requested by calling getFile again.
     *
     * @param file_id [required] File identifier to get information about.
     * @returns std::shared_ptr<File>
     * @see https://core.telegram.org/bots/api#getfile
     */
    struct GetFileArgs {
        std::string file_id{""};
    };

    drogon::Task<std::shared_ptr<File>> getFile(std::string file_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["file_id"] = file_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getFile", _body)
            : co_await request_->uploadFiles(token_ + "/getFile", _body, _uploads);
        co_return parse_response<std::shared_ptr<File>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<File>> getFile(GetFileArgs args) {
        co_return co_await getFile(std::move(args.file_id));
    }

    /**
     * Use this method to ban a user in a group, a supergroup or a channel. In the case of
     * supergroups and channels, the user will not be able to return to the chat on their own
     * using invite links, etc., unless unbanned first. The bot must be an administrator in the
     * chat for this to work and must have the appropriate administrator rights. Returns True on
     * success.
     *
     * @param chat_id [required] Unique identifier for the target group or username of the target supergroup or channel in the format.
     * @param user_id [required] Unique identifier of the target user.
     * @param until_date [optional] Optional.
     * @param revoke_messages [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#banchatmember
     */
    struct BanChatMemberArgs {
        ChatId chat_id{};
        int64_t user_id{0};
        std::optional<int64_t> until_date;
        std::optional<bool> revoke_messages;
    };

    drogon::Task<bool> banChatMember(ChatId chat_id,
                                     int64_t user_id,
                                     std::optional<int64_t> until_date = std::nullopt,
                                     std::optional<bool> revoke_messages = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["user_id"] = user_id;
        if (until_date.has_value()) {
            payload["until_date"] = until_date.value();
        }
        if (revoke_messages.has_value()) {
            payload["revoke_messages"] = revoke_messages.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/banChatMember", _body)
            : co_await request_->uploadFiles(token_ + "/banChatMember", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> banChatMember(BanChatMemberArgs args) {
        co_return co_await banChatMember(std::move(args.chat_id),
            std::move(args.user_id),
            std::move(args.until_date),
            std::move(args.revoke_messages));
    }

    /**
     * Use this method to unban a previously banned user in a supergroup or channel. The user
     * will not return to the group or channel automatically, but will be able to join via link,
     * etc. The bot must be an administrator for this to work. By default, this method
     * guarantees that after the call the user is not a member of the chat, but will be able to
     * join it. So if the user is a member of the chat they will also be removed from the chat.
     * If you don't want this, use the parameter only_if_banned. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target group or username of the target supergroup or channel in the format.
     * @param user_id [required] Unique identifier of the target user.
     * @param only_if_banned [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#unbanchatmember
     */
    struct UnbanChatMemberArgs {
        ChatId chat_id{};
        int64_t user_id{0};
        std::optional<bool> only_if_banned;
    };

    drogon::Task<bool> unbanChatMember(ChatId chat_id,
                                       int64_t user_id,
                                       std::optional<bool> only_if_banned = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["user_id"] = user_id;
        if (only_if_banned.has_value()) {
            payload["only_if_banned"] = only_if_banned.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/unbanChatMember", _body)
            : co_await request_->uploadFiles(token_ + "/unbanChatMember", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> unbanChatMember(UnbanChatMemberArgs args) {
        co_return co_await unbanChatMember(std::move(args.chat_id),
            std::move(args.user_id),
            std::move(args.only_if_banned));
    }

    /**
     * Use this method to restrict a user in a supergroup. The bot must be an administrator in
     * the supergroup for this to work and must have the appropriate administrator rights. Pass
     * True for all permissions to lift restrictions from a user. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup in the format @username.
     * @param user_id [required] Unique identifier of the target user.
     * @param permissions [required] A JSON-serialized object for new user permissions.
     * @param use_independent_chat_permissions [optional] Optional.
     * @param until_date [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#restrictchatmember
     */
    struct RestrictChatMemberArgs {
        ChatId chat_id{};
        int64_t user_id{0};
        std::shared_ptr<ChatPermissions> permissions;
        std::optional<bool> use_independent_chat_permissions;
        std::optional<int64_t> until_date;
    };

    drogon::Task<bool> restrictChatMember(ChatId chat_id,
                                          int64_t user_id,
                                          std::shared_ptr<ChatPermissions> permissions,
                                          std::optional<bool> use_independent_chat_permissions = std::nullopt,
                                          std::optional<int64_t> until_date = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["user_id"] = user_id;
        {
            json _sub;
            to_json(_sub, *permissions);
            payload["permissions"] = std::move(_sub);
        }
        if (use_independent_chat_permissions.has_value()) {
            payload["use_independent_chat_permissions"] = use_independent_chat_permissions.value();
        }
        if (until_date.has_value()) {
            payload["until_date"] = until_date.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/restrictChatMember", _body)
            : co_await request_->uploadFiles(token_ + "/restrictChatMember", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> restrictChatMember(RestrictChatMemberArgs args) {
        co_return co_await restrictChatMember(std::move(args.chat_id),
            std::move(args.user_id),
            std::move(args.permissions),
            std::move(args.use_independent_chat_permissions),
            std::move(args.until_date));
    }

    /**
     * Use this method to promote or demote a user in a supergroup or a channel. The bot must be
     * an administrator in the chat for this to work and must have the appropriate administrator
     * rights. Pass False for all boolean parameters to demote a user. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target channel in the format @username.
     * @param user_id [required] Unique identifier of the target user.
     * @param is_anonymous [optional] Optional.
     * @param can_manage_chat [optional] Optional.
     * @param can_delete_messages [optional] Optional.
     * @param can_manage_video_chats [optional] Optional.
     * @param can_restrict_members [optional] Optional.
     * @param can_promote_members [optional] Optional.
     * @param can_change_info [optional] Optional.
     * @param can_invite_users [optional] Optional.
     * @param can_post_stories [optional] Optional.
     * @param can_edit_stories [optional] Optional.
     * @param can_delete_stories [optional] Optional.
     * @param can_post_messages [optional] Optional.
     * @param can_edit_messages [optional] Optional.
     * @param can_pin_messages [optional] Optional.
     * @param can_manage_topics [optional] Optional.
     * @param can_manage_direct_messages [optional] Optional.
     * @param can_manage_tags [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#promotechatmember
     */
    struct PromoteChatMemberArgs {
        ChatId chat_id{};
        int64_t user_id{0};
        std::optional<bool> is_anonymous;
        std::optional<bool> can_manage_chat;
        std::optional<bool> can_delete_messages;
        std::optional<bool> can_manage_video_chats;
        std::optional<bool> can_restrict_members;
        std::optional<bool> can_promote_members;
        std::optional<bool> can_change_info;
        std::optional<bool> can_invite_users;
        std::optional<bool> can_post_stories;
        std::optional<bool> can_edit_stories;
        std::optional<bool> can_delete_stories;
        std::optional<bool> can_post_messages;
        std::optional<bool> can_edit_messages;
        std::optional<bool> can_pin_messages;
        std::optional<bool> can_manage_topics;
        std::optional<bool> can_manage_direct_messages;
        std::optional<bool> can_manage_tags;
    };

    drogon::Task<bool> promoteChatMember(ChatId chat_id,
                                         int64_t user_id,
                                         std::optional<bool> is_anonymous = std::nullopt,
                                         std::optional<bool> can_manage_chat = std::nullopt,
                                         std::optional<bool> can_delete_messages = std::nullopt,
                                         std::optional<bool> can_manage_video_chats = std::nullopt,
                                         std::optional<bool> can_restrict_members = std::nullopt,
                                         std::optional<bool> can_promote_members = std::nullopt,
                                         std::optional<bool> can_change_info = std::nullopt,
                                         std::optional<bool> can_invite_users = std::nullopt,
                                         std::optional<bool> can_post_stories = std::nullopt,
                                         std::optional<bool> can_edit_stories = std::nullopt,
                                         std::optional<bool> can_delete_stories = std::nullopt,
                                         std::optional<bool> can_post_messages = std::nullopt,
                                         std::optional<bool> can_edit_messages = std::nullopt,
                                         std::optional<bool> can_pin_messages = std::nullopt,
                                         std::optional<bool> can_manage_topics = std::nullopt,
                                         std::optional<bool> can_manage_direct_messages = std::nullopt,
                                         std::optional<bool> can_manage_tags = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["user_id"] = user_id;
        if (is_anonymous.has_value()) {
            payload["is_anonymous"] = is_anonymous.value();
        }
        if (can_manage_chat.has_value()) {
            payload["can_manage_chat"] = can_manage_chat.value();
        }
        if (can_delete_messages.has_value()) {
            payload["can_delete_messages"] = can_delete_messages.value();
        }
        if (can_manage_video_chats.has_value()) {
            payload["can_manage_video_chats"] = can_manage_video_chats.value();
        }
        if (can_restrict_members.has_value()) {
            payload["can_restrict_members"] = can_restrict_members.value();
        }
        if (can_promote_members.has_value()) {
            payload["can_promote_members"] = can_promote_members.value();
        }
        if (can_change_info.has_value()) {
            payload["can_change_info"] = can_change_info.value();
        }
        if (can_invite_users.has_value()) {
            payload["can_invite_users"] = can_invite_users.value();
        }
        if (can_post_stories.has_value()) {
            payload["can_post_stories"] = can_post_stories.value();
        }
        if (can_edit_stories.has_value()) {
            payload["can_edit_stories"] = can_edit_stories.value();
        }
        if (can_delete_stories.has_value()) {
            payload["can_delete_stories"] = can_delete_stories.value();
        }
        if (can_post_messages.has_value()) {
            payload["can_post_messages"] = can_post_messages.value();
        }
        if (can_edit_messages.has_value()) {
            payload["can_edit_messages"] = can_edit_messages.value();
        }
        if (can_pin_messages.has_value()) {
            payload["can_pin_messages"] = can_pin_messages.value();
        }
        if (can_manage_topics.has_value()) {
            payload["can_manage_topics"] = can_manage_topics.value();
        }
        if (can_manage_direct_messages.has_value()) {
            payload["can_manage_direct_messages"] = can_manage_direct_messages.value();
        }
        if (can_manage_tags.has_value()) {
            payload["can_manage_tags"] = can_manage_tags.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/promoteChatMember", _body)
            : co_await request_->uploadFiles(token_ + "/promoteChatMember", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> promoteChatMember(PromoteChatMemberArgs args) {
        co_return co_await promoteChatMember(std::move(args.chat_id),
            std::move(args.user_id),
            std::move(args.is_anonymous),
            std::move(args.can_manage_chat),
            std::move(args.can_delete_messages),
            std::move(args.can_manage_video_chats),
            std::move(args.can_restrict_members),
            std::move(args.can_promote_members),
            std::move(args.can_change_info),
            std::move(args.can_invite_users),
            std::move(args.can_post_stories),
            std::move(args.can_edit_stories),
            std::move(args.can_delete_stories),
            std::move(args.can_post_messages),
            std::move(args.can_edit_messages),
            std::move(args.can_pin_messages),
            std::move(args.can_manage_topics),
            std::move(args.can_manage_direct_messages),
            std::move(args.can_manage_tags));
    }

    /**
     * Use this method to set a custom title for an administrator in a supergroup promoted by
     * the bot. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup in the format @username.
     * @param user_id [required] Unique identifier of the target user.
     * @param custom_title [required] New custom title for the administrator; 0-16 characters, emoji are not allowed.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setchatadministratorcustomtitle
     */
    struct SetChatAdministratorCustomTitleArgs {
        ChatId chat_id{};
        int64_t user_id{0};
        std::string custom_title{""};
    };

    drogon::Task<bool> setChatAdministratorCustomTitle(ChatId chat_id,
                                                       int64_t user_id,
                                                       std::string custom_title) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["user_id"] = user_id;
        payload["custom_title"] = custom_title;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setChatAdministratorCustomTitle", _body)
            : co_await request_->uploadFiles(token_ + "/setChatAdministratorCustomTitle", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setChatAdministratorCustomTitle(SetChatAdministratorCustomTitleArgs args) {
        co_return co_await setChatAdministratorCustomTitle(std::move(args.chat_id),
            std::move(args.user_id),
            std::move(args.custom_title));
    }

    /**
     * Use this method to set a tag for a regular member in a group or a supergroup. The bot
     * must be an administrator in the chat for this to work and must have the can_manage_tags
     * administrator right. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup in the format @username.
     * @param user_id [required] Unique identifier of the target user.
     * @param tag [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setchatmembertag
     */
    struct SetChatMemberTagArgs {
        ChatId chat_id{};
        int64_t user_id{0};
        std::optional<std::string> tag;
    };

    drogon::Task<bool> setChatMemberTag(ChatId chat_id,
                                        int64_t user_id,
                                        std::optional<std::string> tag = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["user_id"] = user_id;
        if (tag.has_value()) {
            payload["tag"] = tag.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setChatMemberTag", _body)
            : co_await request_->uploadFiles(token_ + "/setChatMemberTag", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setChatMemberTag(SetChatMemberTagArgs args) {
        co_return co_await setChatMemberTag(std::move(args.chat_id),
            std::move(args.user_id),
            std::move(args.tag));
    }

    /**
     * Use this method to ban a channel chat in a supergroup or a channel. Until the chat is
     * unbanned, the owner of the banned chat won't be able to send messages on behalf of any of
     * their channels. The bot must be an administrator in the supergroup or channel for this to
     * work and must have the appropriate administrator rights. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target channel in the format @username.
     * @param sender_chat_id [required] Unique identifier of the target sender chat.
     * @returns bool
     * @see https://core.telegram.org/bots/api#banchatsenderchat
     */
    struct BanChatSenderChatArgs {
        ChatId chat_id{};
        int64_t sender_chat_id{0};
    };

    drogon::Task<bool> banChatSenderChat(ChatId chat_id,
                                         int64_t sender_chat_id) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["sender_chat_id"] = sender_chat_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/banChatSenderChat", _body)
            : co_await request_->uploadFiles(token_ + "/banChatSenderChat", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> banChatSenderChat(BanChatSenderChatArgs args) {
        co_return co_await banChatSenderChat(std::move(args.chat_id),
            std::move(args.sender_chat_id));
    }

    /**
     * Use this method to unban a previously banned channel chat in a supergroup or channel. The
     * bot must be an administrator for this to work and must have the appropriate administrator
     * rights. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target channel in the format @username.
     * @param sender_chat_id [required] Unique identifier of the target sender chat.
     * @returns bool
     * @see https://core.telegram.org/bots/api#unbanchatsenderchat
     */
    struct UnbanChatSenderChatArgs {
        ChatId chat_id{};
        int64_t sender_chat_id{0};
    };

    drogon::Task<bool> unbanChatSenderChat(ChatId chat_id,
                                           int64_t sender_chat_id) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["sender_chat_id"] = sender_chat_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/unbanChatSenderChat", _body)
            : co_await request_->uploadFiles(token_ + "/unbanChatSenderChat", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> unbanChatSenderChat(UnbanChatSenderChatArgs args) {
        co_return co_await unbanChatSenderChat(std::move(args.chat_id),
            std::move(args.sender_chat_id));
    }

    /**
     * Use this method to set default chat permissions for all members. The bot must be an
     * administrator in the group or a supergroup for this to work and must have the
     * can_restrict_members administrator rights. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup in the format @username.
     * @param permissions [required] A JSON-serialized object for new default chat permissions.
     * @param use_independent_chat_permissions [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setchatpermissions
     */
    struct SetChatPermissionsArgs {
        ChatId chat_id{};
        std::shared_ptr<ChatPermissions> permissions;
        std::optional<bool> use_independent_chat_permissions;
    };

    drogon::Task<bool> setChatPermissions(ChatId chat_id,
                                          std::shared_ptr<ChatPermissions> permissions,
                                          std::optional<bool> use_independent_chat_permissions = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        {
            json _sub;
            to_json(_sub, *permissions);
            payload["permissions"] = std::move(_sub);
        }
        if (use_independent_chat_permissions.has_value()) {
            payload["use_independent_chat_permissions"] = use_independent_chat_permissions.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setChatPermissions", _body)
            : co_await request_->uploadFiles(token_ + "/setChatPermissions", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setChatPermissions(SetChatPermissionsArgs args) {
        co_return co_await setChatPermissions(std::move(args.chat_id),
            std::move(args.permissions),
            std::move(args.use_independent_chat_permissions));
    }

    /**
     * Use this method to generate a new primary invite link for a chat; any previously
     * generated primary link is revoked. The bot must be an administrator in the chat for this
     * to work and must have the appropriate administrator rights. Returns the new invite link
     * as String on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target channel in the format @username.
     * @returns std::string
     * @see https://core.telegram.org/bots/api#exportchatinvitelink
     */
    struct ExportChatInviteLinkArgs {
        ChatId chat_id{};
    };

    drogon::Task<std::string> exportChatInviteLink(ChatId chat_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/exportChatInviteLink", _body)
            : co_await request_->uploadFiles(token_ + "/exportChatInviteLink", _body, _uploads);
        co_return parse_response<std::string>(_resp).result.value();
    }

    drogon::Task<std::string> exportChatInviteLink(ExportChatInviteLinkArgs args) {
        co_return co_await exportChatInviteLink(std::move(args.chat_id));
    }

    /**
     * Use this method to create an additional invite link for a chat. The bot must be an
     * administrator in the chat for this to work and must have the appropriate administrator
     * rights. The link can be revoked using the method revokeChatInviteLink. Returns the new
     * invite link as ChatInviteLink object.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target channel in the format @username.
     * @param name [optional] Optional.
     * @param expire_date [optional] Optional.
     * @param member_limit [optional] Optional.
     * @param creates_join_request [optional] Optional.
     * @returns std::shared_ptr<ChatInviteLink>
     * @see https://core.telegram.org/bots/api#createchatinvitelink
     */
    struct CreateChatInviteLinkArgs {
        ChatId chat_id{};
        std::optional<std::string> name;
        std::optional<int64_t> expire_date;
        std::optional<int64_t> member_limit;
        std::optional<bool> creates_join_request;
    };

    drogon::Task<std::shared_ptr<ChatInviteLink>> createChatInviteLink(ChatId chat_id,
                                                                       std::optional<std::string> name = std::nullopt,
                                                                       std::optional<int64_t> expire_date = std::nullopt,
                                                                       std::optional<int64_t> member_limit = std::nullopt,
                                                                       std::optional<bool> creates_join_request = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (name.has_value()) {
            payload["name"] = name.value();
        }
        if (expire_date.has_value()) {
            payload["expire_date"] = expire_date.value();
        }
        if (member_limit.has_value()) {
            payload["member_limit"] = member_limit.value();
        }
        if (creates_join_request.has_value()) {
            payload["creates_join_request"] = creates_join_request.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/createChatInviteLink", _body)
            : co_await request_->uploadFiles(token_ + "/createChatInviteLink", _body, _uploads);
        co_return parse_response<std::shared_ptr<ChatInviteLink>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<ChatInviteLink>> createChatInviteLink(CreateChatInviteLinkArgs args) {
        co_return co_await createChatInviteLink(std::move(args.chat_id),
            std::move(args.name),
            std::move(args.expire_date),
            std::move(args.member_limit),
            std::move(args.creates_join_request));
    }

    /**
     * Use this method to edit a non-primary invite link created by the bot. The bot must be an
     * administrator in the chat for this to work and must have the appropriate administrator
     * rights. Returns the edited invite link as a ChatInviteLink object.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target channel in the format @username.
     * @param invite_link [required] The invite link to edit.
     * @param name [optional] Optional.
     * @param expire_date [optional] Optional.
     * @param member_limit [optional] Optional.
     * @param creates_join_request [optional] Optional.
     * @returns std::shared_ptr<ChatInviteLink>
     * @see https://core.telegram.org/bots/api#editchatinvitelink
     */
    struct EditChatInviteLinkArgs {
        ChatId chat_id{};
        std::string invite_link{""};
        std::optional<std::string> name;
        std::optional<int64_t> expire_date;
        std::optional<int64_t> member_limit;
        std::optional<bool> creates_join_request;
    };

    drogon::Task<std::shared_ptr<ChatInviteLink>> editChatInviteLink(ChatId chat_id,
                                                                     std::string invite_link,
                                                                     std::optional<std::string> name = std::nullopt,
                                                                     std::optional<int64_t> expire_date = std::nullopt,
                                                                     std::optional<int64_t> member_limit = std::nullopt,
                                                                     std::optional<bool> creates_join_request = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["invite_link"] = invite_link;
        if (name.has_value()) {
            payload["name"] = name.value();
        }
        if (expire_date.has_value()) {
            payload["expire_date"] = expire_date.value();
        }
        if (member_limit.has_value()) {
            payload["member_limit"] = member_limit.value();
        }
        if (creates_join_request.has_value()) {
            payload["creates_join_request"] = creates_join_request.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/editChatInviteLink", _body)
            : co_await request_->uploadFiles(token_ + "/editChatInviteLink", _body, _uploads);
        co_return parse_response<std::shared_ptr<ChatInviteLink>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<ChatInviteLink>> editChatInviteLink(EditChatInviteLinkArgs args) {
        co_return co_await editChatInviteLink(std::move(args.chat_id),
            std::move(args.invite_link),
            std::move(args.name),
            std::move(args.expire_date),
            std::move(args.member_limit),
            std::move(args.creates_join_request));
    }

    /**
     * Use this method to create a subscription invite link for a channel chat. The bot must
     * have the can_invite_users administrator rights. The link can be edited using the method
     * editChatSubscriptionInviteLink or revoked using the method revokeChatInviteLink. Returns
     * the new invite link as a ChatInviteLink object.
     *
     * @param chat_id [required] Unique identifier for the target channel chat or username of the target channel in the format @usern.
     * @param name [optional] Optional.
     * @param subscription_period [required] The number of seconds the subscription will be active for before the next payment.
     * @param subscription_price [required] The amount of Telegram Stars a user must pay initially and after each subsequent subscription period.
     * @returns std::shared_ptr<ChatInviteLink>
     * @see https://core.telegram.org/bots/api#createchatsubscriptioninvitelink
     */
    struct CreateChatSubscriptionInviteLinkArgs {
        ChatId chat_id{};
        int64_t subscription_period{0};
        int64_t subscription_price{0};
        std::optional<std::string> name;
    };

    drogon::Task<std::shared_ptr<ChatInviteLink>> createChatSubscriptionInviteLink(ChatId chat_id,
                                                                                   int64_t subscription_period,
                                                                                   int64_t subscription_price,
                                                                                   std::optional<std::string> name = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (name.has_value()) {
            payload["name"] = name.value();
        }
        payload["subscription_period"] = subscription_period;
        payload["subscription_price"] = subscription_price;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/createChatSubscriptionInviteLink", _body)
            : co_await request_->uploadFiles(token_ + "/createChatSubscriptionInviteLink", _body, _uploads);
        co_return parse_response<std::shared_ptr<ChatInviteLink>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<ChatInviteLink>> createChatSubscriptionInviteLink(CreateChatSubscriptionInviteLinkArgs args) {
        co_return co_await createChatSubscriptionInviteLink(std::move(args.chat_id),
            std::move(args.subscription_period),
            std::move(args.subscription_price),
            std::move(args.name));
    }

    /**
     * Use this method to edit a subscription invite link created by the bot. The bot must have
     * the can_invite_users administrator rights. Returns the edited invite link as a
     * ChatInviteLink object.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target channel in the format @username.
     * @param invite_link [required] The invite link to edit.
     * @param name [optional] Optional.
     * @returns std::shared_ptr<ChatInviteLink>
     * @see https://core.telegram.org/bots/api#editchatsubscriptioninvitelink
     */
    struct EditChatSubscriptionInviteLinkArgs {
        ChatId chat_id{};
        std::string invite_link{""};
        std::optional<std::string> name;
    };

    drogon::Task<std::shared_ptr<ChatInviteLink>> editChatSubscriptionInviteLink(ChatId chat_id,
                                                                                 std::string invite_link,
                                                                                 std::optional<std::string> name = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["invite_link"] = invite_link;
        if (name.has_value()) {
            payload["name"] = name.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/editChatSubscriptionInviteLink", _body)
            : co_await request_->uploadFiles(token_ + "/editChatSubscriptionInviteLink", _body, _uploads);
        co_return parse_response<std::shared_ptr<ChatInviteLink>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<ChatInviteLink>> editChatSubscriptionInviteLink(EditChatSubscriptionInviteLinkArgs args) {
        co_return co_await editChatSubscriptionInviteLink(std::move(args.chat_id),
            std::move(args.invite_link),
            std::move(args.name));
    }

    /**
     * Use this method to revoke an invite link created by the bot. If the primary link is
     * revoked, a new link is automatically generated. The bot must be an administrator in the
     * chat for this to work and must have the appropriate administrator rights. Returns the
     * revoked invite link as ChatInviteLink object.
     *
     * @param chat_id [required] Unique identifier of the target chat or username of the target channel in the format @username.
     * @param invite_link [required] The invite link to revoke.
     * @returns std::shared_ptr<ChatInviteLink>
     * @see https://core.telegram.org/bots/api#revokechatinvitelink
     */
    struct RevokeChatInviteLinkArgs {
        ChatId chat_id{};
        std::string invite_link{""};
    };

    drogon::Task<std::shared_ptr<ChatInviteLink>> revokeChatInviteLink(ChatId chat_id,
                                                                       std::string invite_link) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["invite_link"] = invite_link;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/revokeChatInviteLink", _body)
            : co_await request_->uploadFiles(token_ + "/revokeChatInviteLink", _body, _uploads);
        co_return parse_response<std::shared_ptr<ChatInviteLink>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<ChatInviteLink>> revokeChatInviteLink(RevokeChatInviteLinkArgs args) {
        co_return co_await revokeChatInviteLink(std::move(args.chat_id),
            std::move(args.invite_link));
    }

    /**
     * Use this method to approve a chat join request. The bot must be an administrator in the
     * chat for this to work and must have the can_invite_users administrator right. Returns
     * True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target channel in the format @username.
     * @param user_id [required] Unique identifier of the target user.
     * @returns bool
     * @see https://core.telegram.org/bots/api#approvechatjoinrequest
     */
    struct ApproveChatJoinRequestArgs {
        ChatId chat_id{};
        int64_t user_id{0};
    };

    drogon::Task<bool> approveChatJoinRequest(ChatId chat_id,
                                              int64_t user_id) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["user_id"] = user_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/approveChatJoinRequest", _body)
            : co_await request_->uploadFiles(token_ + "/approveChatJoinRequest", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> approveChatJoinRequest(ApproveChatJoinRequestArgs args) {
        co_return co_await approveChatJoinRequest(std::move(args.chat_id),
            std::move(args.user_id));
    }

    /**
     * Use this method to decline a chat join request. The bot must be an administrator in the
     * chat for this to work and must have the can_invite_users administrator right. Returns
     * True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target channel in the format @username.
     * @param user_id [required] Unique identifier of the target user.
     * @returns bool
     * @see https://core.telegram.org/bots/api#declinechatjoinrequest
     */
    struct DeclineChatJoinRequestArgs {
        ChatId chat_id{};
        int64_t user_id{0};
    };

    drogon::Task<bool> declineChatJoinRequest(ChatId chat_id,
                                              int64_t user_id) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["user_id"] = user_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/declineChatJoinRequest", _body)
            : co_await request_->uploadFiles(token_ + "/declineChatJoinRequest", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> declineChatJoinRequest(DeclineChatJoinRequestArgs args) {
        co_return co_await declineChatJoinRequest(std::move(args.chat_id),
            std::move(args.user_id));
    }

    /**
     * Use this method to set a new profile photo for the chat. Photos can't be changed for
     * private chats. The bot must be an administrator in the chat for this to work and must
     * have the appropriate administrator rights. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target channel in the format @username.
     * @param photo [required] New chat photo, uploaded using multipart/form-data.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setchatphoto
     */
    struct SetChatPhotoArgs {
        ChatId chat_id{};
        std::shared_ptr<InputFile> photo;
    };

    drogon::Task<bool> setChatPhoto(ChatId chat_id,
                                    std::shared_ptr<InputFile> photo) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (photo) {
            payload["photo"] = "attach://" + photo->filename;
            _uploads.push_back({"photo", photo});
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setChatPhoto", _body)
            : co_await request_->uploadFiles(token_ + "/setChatPhoto", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setChatPhoto(SetChatPhotoArgs args) {
        co_return co_await setChatPhoto(std::move(args.chat_id),
            std::move(args.photo));
    }

    /**
     * Use this method to delete a chat photo. Photos can't be changed for private chats. The
     * bot must be an administrator in the chat for this to work and must have the appropriate
     * administrator rights. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target channel in the format @username.
     * @returns bool
     * @see https://core.telegram.org/bots/api#deletechatphoto
     */
    struct DeleteChatPhotoArgs {
        ChatId chat_id{};
    };

    drogon::Task<bool> deleteChatPhoto(ChatId chat_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/deleteChatPhoto", _body)
            : co_await request_->uploadFiles(token_ + "/deleteChatPhoto", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> deleteChatPhoto(DeleteChatPhotoArgs args) {
        co_return co_await deleteChatPhoto(std::move(args.chat_id));
    }

    /**
     * Use this method to change the title of a chat. Titles can't be changed for private chats.
     * The bot must be an administrator in the chat for this to work and must have the
     * appropriate administrator rights. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target channel in the format @username.
     * @param title [required] New chat title, 1-128 characters.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setchattitle
     */
    struct SetChatTitleArgs {
        ChatId chat_id{};
        std::string title{""};
    };

    drogon::Task<bool> setChatTitle(ChatId chat_id,
                                    std::string title) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["title"] = title;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setChatTitle", _body)
            : co_await request_->uploadFiles(token_ + "/setChatTitle", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setChatTitle(SetChatTitleArgs args) {
        co_return co_await setChatTitle(std::move(args.chat_id),
            std::move(args.title));
    }

    /**
     * Use this method to change the description of a group, a supergroup or a channel. The bot
     * must be an administrator in the chat for this to work and must have the appropriate
     * administrator rights. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target channel in the format @username.
     * @param description [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setchatdescription
     */
    struct SetChatDescriptionArgs {
        ChatId chat_id{};
        std::optional<std::string> description;
    };

    drogon::Task<bool> setChatDescription(ChatId chat_id,
                                          std::optional<std::string> description = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (description.has_value()) {
            payload["description"] = description.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setChatDescription", _body)
            : co_await request_->uploadFiles(token_ + "/setChatDescription", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setChatDescription(SetChatDescriptionArgs args) {
        co_return co_await setChatDescription(std::move(args.chat_id),
            std::move(args.description));
    }

    /**
     * Use this method to add a message to the list of pinned messages in a chat. In private
     * chats and channel direct messages chats, all non-service messages can be pinned.
     * Conversely, the bot must be an administrator with the 'can_pin_messages' right or the
     * 'can_edit_messages' right to pin messages in groups and channels respectively. Returns
     * True on success.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target channel in the format @username.
     * @param message_id [required] Identifier of a message to pin.
     * @param disable_notification [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#pinchatmessage
     */
    struct PinChatMessageArgs {
        ChatId chat_id{};
        int64_t message_id{0};
        std::optional<std::string> business_connection_id;
        std::optional<bool> disable_notification;
    };

    drogon::Task<bool> pinChatMessage(ChatId chat_id,
                                      int64_t message_id,
                                      std::optional<std::string> business_connection_id = std::nullopt,
                                      std::optional<bool> disable_notification = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["message_id"] = message_id;
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/pinChatMessage", _body)
            : co_await request_->uploadFiles(token_ + "/pinChatMessage", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> pinChatMessage(PinChatMessageArgs args) {
        co_return co_await pinChatMessage(std::move(args.chat_id),
            std::move(args.message_id),
            std::move(args.business_connection_id),
            std::move(args.disable_notification));
    }

    /**
     * Use this method to remove a message from the list of pinned messages in a chat. In
     * private chats and channel direct messages chats, all messages can be unpinned.
     * Conversely, the bot must be an administrator with the 'can_pin_messages' right or the
     * 'can_edit_messages' right to unpin messages in groups and channels respectively. Returns
     * True on success.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target channel in the format @username.
     * @param message_id [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#unpinchatmessage
     */
    struct UnpinChatMessageArgs {
        ChatId chat_id{};
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_id;
    };

    drogon::Task<bool> unpinChatMessage(ChatId chat_id,
                                        std::optional<std::string> business_connection_id = std::nullopt,
                                        std::optional<int64_t> message_id = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_id.has_value()) {
            payload["message_id"] = message_id.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/unpinChatMessage", _body)
            : co_await request_->uploadFiles(token_ + "/unpinChatMessage", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> unpinChatMessage(UnpinChatMessageArgs args) {
        co_return co_await unpinChatMessage(std::move(args.chat_id),
            std::move(args.business_connection_id),
            std::move(args.message_id));
    }

    /**
     * Use this method to clear the list of pinned messages in a chat. In private chats and
     * channel direct messages chats, no additional rights are required to unpin all pinned
     * messages. Conversely, the bot must be an administrator with the 'can_pin_messages' right
     * or the 'can_edit_messages' right to unpin all pinned messages in groups and channels
     * respectively. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target channel in the format @username.
     * @returns bool
     * @see https://core.telegram.org/bots/api#unpinallchatmessages
     */
    struct UnpinAllChatMessagesArgs {
        ChatId chat_id{};
    };

    drogon::Task<bool> unpinAllChatMessages(ChatId chat_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/unpinAllChatMessages", _body)
            : co_await request_->uploadFiles(token_ + "/unpinAllChatMessages", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> unpinAllChatMessages(UnpinAllChatMessagesArgs args) {
        co_return co_await unpinAllChatMessages(std::move(args.chat_id));
    }

    /**
     * Use this method for your bot to leave a group, supergroup or channel. Returns True on
     * success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup or channel in the format .
     * @returns bool
     * @see https://core.telegram.org/bots/api#leavechat
     */
    struct LeaveChatArgs {
        ChatId chat_id{};
    };

    drogon::Task<bool> leaveChat(ChatId chat_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/leaveChat", _body)
            : co_await request_->uploadFiles(token_ + "/leaveChat", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> leaveChat(LeaveChatArgs args) {
        co_return co_await leaveChat(std::move(args.chat_id));
    }

    /**
     * Use this method to get up-to-date information about the chat. Returns a ChatFullInfo
     * object on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup or channel in the format .
     * @returns std::shared_ptr<ChatFullInfo>
     * @see https://core.telegram.org/bots/api#getchat
     */
    struct GetChatArgs {
        ChatId chat_id{};
    };

    drogon::Task<std::shared_ptr<ChatFullInfo>> getChat(ChatId chat_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getChat", _body)
            : co_await request_->uploadFiles(token_ + "/getChat", _body, _uploads);
        co_return parse_response<std::shared_ptr<ChatFullInfo>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<ChatFullInfo>> getChat(GetChatArgs args) {
        co_return co_await getChat(std::move(args.chat_id));
    }

    /**
     * Use this method to get a list of administrators in a chat. Returns an Array of ChatMember
     * objects.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup or channel in the format .
     * @param return_bots [optional] Optional.
     * @returns std::vector<ChatMember>
     * @see https://core.telegram.org/bots/api#getchatadministrators
     */
    struct GetChatAdministratorsArgs {
        ChatId chat_id{};
        std::optional<bool> return_bots;
    };

    drogon::Task<std::vector<ChatMember>> getChatAdministrators(ChatId chat_id,
                                                                std::optional<bool> return_bots = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (return_bots.has_value()) {
            payload["return_bots"] = return_bots.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getChatAdministrators", _body)
            : co_await request_->uploadFiles(token_ + "/getChatAdministrators", _body, _uploads);
        co_return parse_response<std::vector<ChatMember>>(_resp).result.value();
    }

    drogon::Task<std::vector<ChatMember>> getChatAdministrators(GetChatAdministratorsArgs args) {
        co_return co_await getChatAdministrators(std::move(args.chat_id),
            std::move(args.return_bots));
    }

    /**
     * Use this method to get the number of members in a chat. Returns Int on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup or channel in the format .
     * @returns int64_t
     * @see https://core.telegram.org/bots/api#getchatmembercount
     */
    struct GetChatMemberCountArgs {
        ChatId chat_id{};
    };

    drogon::Task<int64_t> getChatMemberCount(ChatId chat_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getChatMemberCount", _body)
            : co_await request_->uploadFiles(token_ + "/getChatMemberCount", _body, _uploads);
        co_return parse_response<int64_t>(_resp).result.value();
    }

    drogon::Task<int64_t> getChatMemberCount(GetChatMemberCountArgs args) {
        co_return co_await getChatMemberCount(std::move(args.chat_id));
    }

    /**
     * Use this method to get information about a member of a chat. The method is only
     * guaranteed to work for other users if the bot is an administrator in the chat. Returns a
     * ChatMember object on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup or channel in the format .
     * @param user_id [required] Unique identifier of the target user.
     * @returns ChatMember
     * @see https://core.telegram.org/bots/api#getchatmember
     */
    struct GetChatMemberArgs {
        ChatId chat_id{};
        int64_t user_id{0};
    };

    drogon::Task<ChatMember> getChatMember(ChatId chat_id,
                                           int64_t user_id) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["user_id"] = user_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getChatMember", _body)
            : co_await request_->uploadFiles(token_ + "/getChatMember", _body, _uploads);
        co_return parse_response<ChatMember>(_resp).result.value();
    }

    drogon::Task<ChatMember> getChatMember(GetChatMemberArgs args) {
        co_return co_await getChatMember(std::move(args.chat_id),
            std::move(args.user_id));
    }

    /**
     * Use this method to get the last messages from the personal chat (i.e., the chat currently
     * added to their profile) of a given user. On success, an array of Message objects is
     * returned.
     *
     * @param user_id [required] Unique identifier for the target user.
     * @param limit [required] The maximum number of messages to return; 1-20.
     * @returns std::vector<std::shared_ptr<Message>>
     * @see https://core.telegram.org/bots/api#getuserpersonalchatmessages
     */
    struct GetUserPersonalChatMessagesArgs {
        int64_t user_id{0};
        int64_t limit{0};
    };

    drogon::Task<std::vector<std::shared_ptr<Message>>> getUserPersonalChatMessages(int64_t user_id,
                                                                                    int64_t limit) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        payload["limit"] = limit;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getUserPersonalChatMessages", _body)
            : co_await request_->uploadFiles(token_ + "/getUserPersonalChatMessages", _body, _uploads);
        co_return parse_response<std::vector<std::shared_ptr<Message>>>(_resp).result.value();
    }

    drogon::Task<std::vector<std::shared_ptr<Message>>> getUserPersonalChatMessages(GetUserPersonalChatMessagesArgs args) {
        co_return co_await getUserPersonalChatMessages(std::move(args.user_id),
            std::move(args.limit));
    }

    /**
     * Use this method to set a new group sticker set for a supergroup. The bot must be an
     * administrator in the chat for this to work and must have the appropriate administrator
     * rights. Use the field can_set_sticker_set optionally returned in getChat requests to
     * check if the bot can use this method. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup in the format @username.
     * @param sticker_set_name [required] Name of the sticker set to be set as the group sticker set.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setchatstickerset
     */
    struct SetChatStickerSetArgs {
        ChatId chat_id{};
        std::string sticker_set_name{""};
    };

    drogon::Task<bool> setChatStickerSet(ChatId chat_id,
                                         std::string sticker_set_name) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["sticker_set_name"] = sticker_set_name;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setChatStickerSet", _body)
            : co_await request_->uploadFiles(token_ + "/setChatStickerSet", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setChatStickerSet(SetChatStickerSetArgs args) {
        co_return co_await setChatStickerSet(std::move(args.chat_id),
            std::move(args.sticker_set_name));
    }

    /**
     * Use this method to delete a group sticker set from a supergroup. The bot must be an
     * administrator in the chat for this to work and must have the appropriate administrator
     * rights. Use the field can_set_sticker_set optionally returned in getChat requests to
     * check if the bot can use this method. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup in the format @username.
     * @returns bool
     * @see https://core.telegram.org/bots/api#deletechatstickerset
     */
    struct DeleteChatStickerSetArgs {
        ChatId chat_id{};
    };

    drogon::Task<bool> deleteChatStickerSet(ChatId chat_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/deleteChatStickerSet", _body)
            : co_await request_->uploadFiles(token_ + "/deleteChatStickerSet", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> deleteChatStickerSet(DeleteChatStickerSetArgs args) {
        co_return co_await deleteChatStickerSet(std::move(args.chat_id));
    }

    /**
     * Use this method to get custom emoji stickers, which can be used as a forum topic icon by
     * any user. Requires no parameters. Returns an Array of Sticker objects.
     *
     * @returns std::vector<std::shared_ptr<Sticker>>
     * @see https://core.telegram.org/bots/api#getforumtopiciconstickers
     */
    drogon::Task<std::vector<std::shared_ptr<Sticker>>> getForumTopicIconStickers() const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getForumTopicIconStickers", _body)
            : co_await request_->uploadFiles(token_ + "/getForumTopicIconStickers", _body, _uploads);
        co_return parse_response<std::vector<std::shared_ptr<Sticker>>>(_resp).result.value();
    }

    /**
     * Use this method to create a topic in a forum supergroup chat or a private chat with a
     * user. In the case of a supergroup chat the bot must be an administrator in the chat for
     * this to work and must have the can_manage_topics administrator right. Returns information
     * about the created topic as a ForumTopic object.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup in the format @username.
     * @param name [required] Topic name, 1-128 characters.
     * @param icon_color [optional] Optional.
     * @param icon_custom_emoji_id [optional] Optional.
     * @returns std::shared_ptr<ForumTopic>
     * @see https://core.telegram.org/bots/api#createforumtopic
     */
    struct CreateForumTopicArgs {
        ChatId chat_id{};
        std::string name{""};
        std::optional<int64_t> icon_color;
        std::optional<std::string> icon_custom_emoji_id;
    };

    drogon::Task<std::shared_ptr<ForumTopic>> createForumTopic(ChatId chat_id,
                                                               std::string name,
                                                               std::optional<int64_t> icon_color = std::nullopt,
                                                               std::optional<std::string> icon_custom_emoji_id = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["name"] = name;
        if (icon_color.has_value()) {
            payload["icon_color"] = icon_color.value();
        }
        if (icon_custom_emoji_id.has_value()) {
            payload["icon_custom_emoji_id"] = icon_custom_emoji_id.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/createForumTopic", _body)
            : co_await request_->uploadFiles(token_ + "/createForumTopic", _body, _uploads);
        co_return parse_response<std::shared_ptr<ForumTopic>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<ForumTopic>> createForumTopic(CreateForumTopicArgs args) {
        co_return co_await createForumTopic(std::move(args.chat_id),
            std::move(args.name),
            std::move(args.icon_color),
            std::move(args.icon_custom_emoji_id));
    }

    /**
     * Use this method to edit name and icon of a topic in a forum supergroup chat or a private
     * chat with a user. In the case of a supergroup chat the bot must be an administrator in
     * the chat for this to work and must have the can_manage_topics administrator rights,
     * unless it is the creator of the topic. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup in the format @username.
     * @param message_thread_id [required] Unique identifier for the target message thread of the forum topic.
     * @param name [optional] Optional.
     * @param icon_custom_emoji_id [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#editforumtopic
     */
    struct EditForumTopicArgs {
        ChatId chat_id{};
        int64_t message_thread_id{0};
        std::optional<std::string> name;
        std::optional<std::string> icon_custom_emoji_id;
    };

    drogon::Task<bool> editForumTopic(ChatId chat_id,
                                      int64_t message_thread_id,
                                      std::optional<std::string> name = std::nullopt,
                                      std::optional<std::string> icon_custom_emoji_id = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["message_thread_id"] = message_thread_id;
        if (name.has_value()) {
            payload["name"] = name.value();
        }
        if (icon_custom_emoji_id.has_value()) {
            payload["icon_custom_emoji_id"] = icon_custom_emoji_id.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/editForumTopic", _body)
            : co_await request_->uploadFiles(token_ + "/editForumTopic", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> editForumTopic(EditForumTopicArgs args) {
        co_return co_await editForumTopic(std::move(args.chat_id),
            std::move(args.message_thread_id),
            std::move(args.name),
            std::move(args.icon_custom_emoji_id));
    }

    /**
     * Use this method to close an open topic in a forum supergroup chat. The bot must be an
     * administrator in the chat for this to work and must have the can_manage_topics
     * administrator rights, unless it is the creator of the topic. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup in the format @username.
     * @param message_thread_id [required] Unique identifier for the target message thread of the forum topic.
     * @returns bool
     * @see https://core.telegram.org/bots/api#closeforumtopic
     */
    struct CloseForumTopicArgs {
        ChatId chat_id{};
        int64_t message_thread_id{0};
    };

    drogon::Task<bool> closeForumTopic(ChatId chat_id,
                                       int64_t message_thread_id) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["message_thread_id"] = message_thread_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/closeForumTopic", _body)
            : co_await request_->uploadFiles(token_ + "/closeForumTopic", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> closeForumTopic(CloseForumTopicArgs args) {
        co_return co_await closeForumTopic(std::move(args.chat_id),
            std::move(args.message_thread_id));
    }

    /**
     * Use this method to reopen a closed topic in a forum supergroup chat. The bot must be an
     * administrator in the chat for this to work and must have the can_manage_topics
     * administrator rights, unless it is the creator of the topic. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup in the format @username.
     * @param message_thread_id [required] Unique identifier for the target message thread of the forum topic.
     * @returns bool
     * @see https://core.telegram.org/bots/api#reopenforumtopic
     */
    struct ReopenForumTopicArgs {
        ChatId chat_id{};
        int64_t message_thread_id{0};
    };

    drogon::Task<bool> reopenForumTopic(ChatId chat_id,
                                        int64_t message_thread_id) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["message_thread_id"] = message_thread_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/reopenForumTopic", _body)
            : co_await request_->uploadFiles(token_ + "/reopenForumTopic", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> reopenForumTopic(ReopenForumTopicArgs args) {
        co_return co_await reopenForumTopic(std::move(args.chat_id),
            std::move(args.message_thread_id));
    }

    /**
     * Use this method to delete a forum topic along with all its messages in a forum supergroup
     * chat or a private chat with a user. In the case of a supergroup chat the bot must be an
     * administrator in the chat for this to work and must have the can_delete_messages
     * administrator rights. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup in the format @username.
     * @param message_thread_id [required] Unique identifier for the target message thread of the forum topic.
     * @returns bool
     * @see https://core.telegram.org/bots/api#deleteforumtopic
     */
    struct DeleteForumTopicArgs {
        ChatId chat_id{};
        int64_t message_thread_id{0};
    };

    drogon::Task<bool> deleteForumTopic(ChatId chat_id,
                                        int64_t message_thread_id) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["message_thread_id"] = message_thread_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/deleteForumTopic", _body)
            : co_await request_->uploadFiles(token_ + "/deleteForumTopic", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> deleteForumTopic(DeleteForumTopicArgs args) {
        co_return co_await deleteForumTopic(std::move(args.chat_id),
            std::move(args.message_thread_id));
    }

    /**
     * Use this method to clear the list of pinned messages in a forum topic in a forum
     * supergroup chat or a private chat with a user. In the case of a supergroup chat the bot
     * must be an administrator in the chat for this to work and must have the can_pin_messages
     * administrator right in the supergroup. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup in the format @username.
     * @param message_thread_id [required] Unique identifier for the target message thread of the forum topic.
     * @returns bool
     * @see https://core.telegram.org/bots/api#unpinallforumtopicmessages
     */
    struct UnpinAllForumTopicMessagesArgs {
        ChatId chat_id{};
        int64_t message_thread_id{0};
    };

    drogon::Task<bool> unpinAllForumTopicMessages(ChatId chat_id,
                                                  int64_t message_thread_id) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["message_thread_id"] = message_thread_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/unpinAllForumTopicMessages", _body)
            : co_await request_->uploadFiles(token_ + "/unpinAllForumTopicMessages", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> unpinAllForumTopicMessages(UnpinAllForumTopicMessagesArgs args) {
        co_return co_await unpinAllForumTopicMessages(std::move(args.chat_id),
            std::move(args.message_thread_id));
    }

    /**
     * Use this method to edit the name of the 'General' topic in a forum supergroup chat. The
     * bot must be an administrator in the chat for this to work and must have the
     * can_manage_topics administrator rights. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup in the format @username.
     * @param name [required] New topic name, 1-128 characters.
     * @returns bool
     * @see https://core.telegram.org/bots/api#editgeneralforumtopic
     */
    struct EditGeneralForumTopicArgs {
        ChatId chat_id{};
        std::string name{""};
    };

    drogon::Task<bool> editGeneralForumTopic(ChatId chat_id,
                                             std::string name) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["name"] = name;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/editGeneralForumTopic", _body)
            : co_await request_->uploadFiles(token_ + "/editGeneralForumTopic", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> editGeneralForumTopic(EditGeneralForumTopicArgs args) {
        co_return co_await editGeneralForumTopic(std::move(args.chat_id),
            std::move(args.name));
    }

    /**
     * Use this method to close an open 'General' topic in a forum supergroup chat. The bot must
     * be an administrator in the chat for this to work and must have the can_manage_topics
     * administrator rights. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup in the format @username.
     * @returns bool
     * @see https://core.telegram.org/bots/api#closegeneralforumtopic
     */
    struct CloseGeneralForumTopicArgs {
        ChatId chat_id{};
    };

    drogon::Task<bool> closeGeneralForumTopic(ChatId chat_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/closeGeneralForumTopic", _body)
            : co_await request_->uploadFiles(token_ + "/closeGeneralForumTopic", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> closeGeneralForumTopic(CloseGeneralForumTopicArgs args) {
        co_return co_await closeGeneralForumTopic(std::move(args.chat_id));
    }

    /**
     * Use this method to reopen a closed 'General' topic in a forum supergroup chat. The bot
     * must be an administrator in the chat for this to work and must have the can_manage_topics
     * administrator rights. The topic will be automatically unhidden if it was hidden. Returns
     * True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup in the format @username.
     * @returns bool
     * @see https://core.telegram.org/bots/api#reopengeneralforumtopic
     */
    struct ReopenGeneralForumTopicArgs {
        ChatId chat_id{};
    };

    drogon::Task<bool> reopenGeneralForumTopic(ChatId chat_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/reopenGeneralForumTopic", _body)
            : co_await request_->uploadFiles(token_ + "/reopenGeneralForumTopic", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> reopenGeneralForumTopic(ReopenGeneralForumTopicArgs args) {
        co_return co_await reopenGeneralForumTopic(std::move(args.chat_id));
    }

    /**
     * Use this method to hide the 'General' topic in a forum supergroup chat. The bot must be
     * an administrator in the chat for this to work and must have the can_manage_topics
     * administrator rights. The topic will be automatically closed if it was open. Returns True
     * on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup in the format @username.
     * @returns bool
     * @see https://core.telegram.org/bots/api#hidegeneralforumtopic
     */
    struct HideGeneralForumTopicArgs {
        ChatId chat_id{};
    };

    drogon::Task<bool> hideGeneralForumTopic(ChatId chat_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/hideGeneralForumTopic", _body)
            : co_await request_->uploadFiles(token_ + "/hideGeneralForumTopic", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> hideGeneralForumTopic(HideGeneralForumTopicArgs args) {
        co_return co_await hideGeneralForumTopic(std::move(args.chat_id));
    }

    /**
     * Use this method to unhide the 'General' topic in a forum supergroup chat. The bot must be
     * an administrator in the chat for this to work and must have the can_manage_topics
     * administrator rights. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup in the format @username.
     * @returns bool
     * @see https://core.telegram.org/bots/api#unhidegeneralforumtopic
     */
    struct UnhideGeneralForumTopicArgs {
        ChatId chat_id{};
    };

    drogon::Task<bool> unhideGeneralForumTopic(ChatId chat_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/unhideGeneralForumTopic", _body)
            : co_await request_->uploadFiles(token_ + "/unhideGeneralForumTopic", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> unhideGeneralForumTopic(UnhideGeneralForumTopicArgs args) {
        co_return co_await unhideGeneralForumTopic(std::move(args.chat_id));
    }

    /**
     * Use this method to clear the list of pinned messages in a General forum topic. The bot
     * must be an administrator in the chat for this to work and must have the can_pin_messages
     * administrator right in the supergroup. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup in the format @username.
     * @returns bool
     * @see https://core.telegram.org/bots/api#unpinallgeneralforumtopicmessages
     */
    struct UnpinAllGeneralForumTopicMessagesArgs {
        ChatId chat_id{};
    };

    drogon::Task<bool> unpinAllGeneralForumTopicMessages(ChatId chat_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/unpinAllGeneralForumTopicMessages", _body)
            : co_await request_->uploadFiles(token_ + "/unpinAllGeneralForumTopicMessages", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> unpinAllGeneralForumTopicMessages(UnpinAllGeneralForumTopicMessagesArgs args) {
        co_return co_await unpinAllGeneralForumTopicMessages(std::move(args.chat_id));
    }

    /**
     * Use this method to send answers to callback queries sent from inline keyboards. The
     * answer will be displayed to the user as a notification at the top of the chat screen or
     * as an alert. On success, True is returned.
     * Alternatively, the user can be redirected to the specified Game URL. For this option to
     * work, you must first create a game for your bot via @BotFather and accept the terms.
     * Otherwise, you may use links like t.me/your_bot?start=XXXX that open your bot with a
     * parameter.
     *
     * @param callback_query_id [required] Unique identifier for the query to be answered.
     * @param text [optional] Optional.
     * @param show_alert [optional] Optional.
     * @param url [optional] Optional.
     * @param cache_time [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#answercallbackquery
     */
    struct AnswerCallbackQueryArgs {
        std::string callback_query_id{""};
        std::optional<std::string> text;
        std::optional<bool> show_alert;
        std::optional<std::string> url;
        std::optional<int64_t> cache_time;
    };

    drogon::Task<bool> answerCallbackQuery(std::string callback_query_id,
                                           std::optional<std::string> text = std::nullopt,
                                           std::optional<bool> show_alert = std::nullopt,
                                           std::optional<std::string> url = std::nullopt,
                                           std::optional<int64_t> cache_time = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["callback_query_id"] = callback_query_id;
        if (text.has_value()) {
            payload["text"] = text.value();
        }
        if (show_alert.has_value()) {
            payload["show_alert"] = show_alert.value();
        }
        if (url.has_value()) {
            payload["url"] = url.value();
        }
        if (cache_time.has_value()) {
            payload["cache_time"] = cache_time.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/answerCallbackQuery", _body)
            : co_await request_->uploadFiles(token_ + "/answerCallbackQuery", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> answerCallbackQuery(AnswerCallbackQueryArgs args) {
        co_return co_await answerCallbackQuery(std::move(args.callback_query_id),
            std::move(args.text),
            std::move(args.show_alert),
            std::move(args.url),
            std::move(args.cache_time));
    }

    /**
     * Use this method to reply to a received guest message. On success, a SentGuestMessage
     * object is returned.
     *
     * @param guest_query_id [required] Unique identifier for the query to be answered.
     * @param result [required] A JSON-serialized object describing the message to be sent.
     * @returns std::shared_ptr<SentGuestMessage>
     * @see https://core.telegram.org/bots/api#answerguestquery
     */
    struct AnswerGuestQueryArgs {
        std::string guest_query_id{""};
        InlineQueryResult result{};
    };

    drogon::Task<std::shared_ptr<SentGuestMessage>> answerGuestQuery(std::string guest_query_id,
                                                                     const InlineQueryResult& result) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["guest_query_id"] = guest_query_id;
        {
            json _sub;
            to_json(_sub, result);
            payload["result"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/answerGuestQuery", _body)
            : co_await request_->uploadFiles(token_ + "/answerGuestQuery", _body, _uploads);
        co_return parse_response<std::shared_ptr<SentGuestMessage>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<SentGuestMessage>> answerGuestQuery(AnswerGuestQueryArgs args) {
        co_return co_await answerGuestQuery(std::move(args.guest_query_id),
            std::move(args.result));
    }

    /**
     * Use this method to get the list of boosts added to a chat by a user. Requires
     * administrator rights in the chat. Returns a UserChatBoosts object.
     *
     * @param chat_id [required] Unique identifier for the chat or username of the channel in the format @username.
     * @param user_id [required] Unique identifier of the target user.
     * @returns std::shared_ptr<UserChatBoosts>
     * @see https://core.telegram.org/bots/api#getuserchatboosts
     */
    struct GetUserChatBoostsArgs {
        ChatId chat_id{};
        int64_t user_id{0};
    };

    drogon::Task<std::shared_ptr<UserChatBoosts>> getUserChatBoosts(ChatId chat_id,
                                                                    int64_t user_id) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["user_id"] = user_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getUserChatBoosts", _body)
            : co_await request_->uploadFiles(token_ + "/getUserChatBoosts", _body, _uploads);
        co_return parse_response<std::shared_ptr<UserChatBoosts>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<UserChatBoosts>> getUserChatBoosts(GetUserChatBoostsArgs args) {
        co_return co_await getUserChatBoosts(std::move(args.chat_id),
            std::move(args.user_id));
    }

    /**
     * Use this method to get information about the connection of the bot with a business
     * account. Returns a BusinessConnection object on success.
     *
     * @param business_connection_id [required] Unique identifier of the business connection.
     * @returns std::shared_ptr<BusinessConnection>
     * @see https://core.telegram.org/bots/api#getbusinessconnection
     */
    struct GetBusinessConnectionArgs {
        std::string business_connection_id{""};
    };

    drogon::Task<std::shared_ptr<BusinessConnection>> getBusinessConnection(std::string business_connection_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getBusinessConnection", _body)
            : co_await request_->uploadFiles(token_ + "/getBusinessConnection", _body, _uploads);
        co_return parse_response<std::shared_ptr<BusinessConnection>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<BusinessConnection>> getBusinessConnection(GetBusinessConnectionArgs args) {
        co_return co_await getBusinessConnection(std::move(args.business_connection_id));
    }

    /**
     * Use this method to get the token of a managed bot. Returns the token as String on
     * success.
     *
     * @param user_id [required] User identifier of the managed bot whose token will be returned.
     * @returns std::string
     * @see https://core.telegram.org/bots/api#getmanagedbottoken
     */
    struct GetManagedBotTokenArgs {
        int64_t user_id{0};
    };

    drogon::Task<std::string> getManagedBotToken(int64_t user_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getManagedBotToken", _body)
            : co_await request_->uploadFiles(token_ + "/getManagedBotToken", _body, _uploads);
        co_return parse_response<std::string>(_resp).result.value();
    }

    drogon::Task<std::string> getManagedBotToken(GetManagedBotTokenArgs args) {
        co_return co_await getManagedBotToken(std::move(args.user_id));
    }

    /**
     * Use this method to revoke the current token of a managed bot and generate a new one.
     * Returns the new token as String on success.
     *
     * @param user_id [required] User identifier of the managed bot whose token will be replaced.
     * @returns std::string
     * @see https://core.telegram.org/bots/api#replacemanagedbottoken
     */
    struct ReplaceManagedBotTokenArgs {
        int64_t user_id{0};
    };

    drogon::Task<std::string> replaceManagedBotToken(int64_t user_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/replaceManagedBotToken", _body)
            : co_await request_->uploadFiles(token_ + "/replaceManagedBotToken", _body, _uploads);
        co_return parse_response<std::string>(_resp).result.value();
    }

    drogon::Task<std::string> replaceManagedBotToken(ReplaceManagedBotTokenArgs args) {
        co_return co_await replaceManagedBotToken(std::move(args.user_id));
    }

    /**
     * Use this method to get the access settings of a managed bot. Returns a BotAccessSettings
     * object on success.
     *
     * @param user_id [required] User identifier of the managed bot whose access settings will be returned.
     * @returns std::shared_ptr<BotAccessSettings>
     * @see https://core.telegram.org/bots/api#getmanagedbotaccesssettings
     */
    struct GetManagedBotAccessSettingsArgs {
        int64_t user_id{0};
    };

    drogon::Task<std::shared_ptr<BotAccessSettings>> getManagedBotAccessSettings(int64_t user_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getManagedBotAccessSettings", _body)
            : co_await request_->uploadFiles(token_ + "/getManagedBotAccessSettings", _body, _uploads);
        co_return parse_response<std::shared_ptr<BotAccessSettings>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<BotAccessSettings>> getManagedBotAccessSettings(GetManagedBotAccessSettingsArgs args) {
        co_return co_await getManagedBotAccessSettings(std::move(args.user_id));
    }

    /**
     * Use this method to change the access settings of a managed bot. Returns True on success.
     *
     * @param user_id [required] User identifier of the managed bot whose access settings will be changed.
     * @param is_access_restricted [required] Pass True , if only selected users can access the bot.
     * @param added_user_ids [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setmanagedbotaccesssettings
     */
    struct SetManagedBotAccessSettingsArgs {
        int64_t user_id{0};
        bool is_access_restricted{false};
        std::vector<int64_t> added_user_ids;
    };

    drogon::Task<bool> setManagedBotAccessSettings(int64_t user_id,
                                                   bool is_access_restricted,
                                                   std::vector<int64_t> added_user_ids = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        payload["is_access_restricted"] = is_access_restricted;
        if (!added_user_ids.empty()) {
            json _arr = json::array();
            for (const auto& _item : added_user_ids) {
                _arr.push_back(_item);
            }
            payload["added_user_ids"] = std::move(_arr);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setManagedBotAccessSettings", _body)
            : co_await request_->uploadFiles(token_ + "/setManagedBotAccessSettings", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setManagedBotAccessSettings(SetManagedBotAccessSettingsArgs args) {
        co_return co_await setManagedBotAccessSettings(std::move(args.user_id),
            std::move(args.is_access_restricted),
            std::move(args.added_user_ids));
    }

    /**
     * Use this method to change the list of the bot's commands. See this manual for more
     * details about bot commands. Returns True on success.
     *
     * @param commands [required] A JSON-serialized list of bot commands to be set as the list of the bot's commands.
     * @param scope [optional] Optional.
     * @param language_code [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setmycommands
     */
    struct SetMyCommandsArgs {
        std::vector<std::shared_ptr<BotCommand>> commands;
        std::optional<BotCommandScope> scope;
        std::optional<std::string> language_code;
    };

    drogon::Task<bool> setMyCommands(std::vector<std::shared_ptr<BotCommand>> commands,
                                     std::optional<BotCommandScope> scope = std::nullopt,
                                     std::optional<std::string> language_code = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        {
            json _arr = json::array();
            for (const auto& _item : commands) {
                {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["commands"] = std::move(_arr);
        }
        if (scope.has_value()) {
            json _sub;
            to_json(_sub, scope.value());
            payload["scope"] = std::move(_sub);
        }
        if (language_code.has_value()) {
            payload["language_code"] = language_code.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setMyCommands", _body)
            : co_await request_->uploadFiles(token_ + "/setMyCommands", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setMyCommands(SetMyCommandsArgs args) {
        co_return co_await setMyCommands(std::move(args.commands),
            std::move(args.scope),
            std::move(args.language_code));
    }

    /**
     * Use this method to delete the list of the bot's commands for the given scope and user
     * language. After deletion, higher level commands will be shown to affected users. Returns
     * True on success.
     *
     * @param scope [optional] Optional.
     * @param language_code [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#deletemycommands
     */
    struct DeleteMyCommandsArgs {
        std::optional<BotCommandScope> scope;
        std::optional<std::string> language_code;
    };

    drogon::Task<bool> deleteMyCommands(std::optional<BotCommandScope> scope = std::nullopt,
                                        std::optional<std::string> language_code = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (scope.has_value()) {
            json _sub;
            to_json(_sub, scope.value());
            payload["scope"] = std::move(_sub);
        }
        if (language_code.has_value()) {
            payload["language_code"] = language_code.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/deleteMyCommands", _body)
            : co_await request_->uploadFiles(token_ + "/deleteMyCommands", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> deleteMyCommands(DeleteMyCommandsArgs args) {
        co_return co_await deleteMyCommands(std::move(args.scope),
            std::move(args.language_code));
    }

    /**
     * Use this method to get the current list of the bot's commands for the given scope and
     * user language. Returns an Array of BotCommand objects. If commands aren't set, an empty
     * list is returned.
     *
     * @param scope [optional] Optional.
     * @param language_code [optional] Optional.
     * @returns std::vector<std::shared_ptr<BotCommand>>
     * @see https://core.telegram.org/bots/api#getmycommands
     */
    struct GetMyCommandsArgs {
        std::optional<BotCommandScope> scope;
        std::optional<std::string> language_code;
    };

    drogon::Task<std::vector<std::shared_ptr<BotCommand>>> getMyCommands(std::optional<BotCommandScope> scope = std::nullopt,
                                                                         std::optional<std::string> language_code = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (scope.has_value()) {
            json _sub;
            to_json(_sub, scope.value());
            payload["scope"] = std::move(_sub);
        }
        if (language_code.has_value()) {
            payload["language_code"] = language_code.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getMyCommands", _body)
            : co_await request_->uploadFiles(token_ + "/getMyCommands", _body, _uploads);
        co_return parse_response<std::vector<std::shared_ptr<BotCommand>>>(_resp).result.value();
    }

    drogon::Task<std::vector<std::shared_ptr<BotCommand>>> getMyCommands(GetMyCommandsArgs args) {
        co_return co_await getMyCommands(std::move(args.scope),
            std::move(args.language_code));
    }

    /**
     * Use this method to change the bot's name. Returns True on success.
     *
     * @param name [optional] Optional.
     * @param language_code [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setmyname
     */
    struct SetMyNameArgs {
        std::optional<std::string> name;
        std::optional<std::string> language_code;
    };

    drogon::Task<bool> setMyName(std::optional<std::string> name = std::nullopt,
                                 std::optional<std::string> language_code = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (name.has_value()) {
            payload["name"] = name.value();
        }
        if (language_code.has_value()) {
            payload["language_code"] = language_code.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setMyName", _body)
            : co_await request_->uploadFiles(token_ + "/setMyName", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setMyName(SetMyNameArgs args) {
        co_return co_await setMyName(std::move(args.name),
            std::move(args.language_code));
    }

    /**
     * Use this method to get the current bot name for the given user language. Returns BotName
     * on success.
     *
     * @param language_code [optional] Optional.
     * @returns std::shared_ptr<BotName>
     * @see https://core.telegram.org/bots/api#getmyname
     */
    struct GetMyNameArgs {
        std::optional<std::string> language_code;
    };

    drogon::Task<std::shared_ptr<BotName>> getMyName(std::optional<std::string> language_code = std::nullopt) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (language_code.has_value()) {
            payload["language_code"] = language_code.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getMyName", _body)
            : co_await request_->uploadFiles(token_ + "/getMyName", _body, _uploads);
        co_return parse_response<std::shared_ptr<BotName>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<BotName>> getMyName(GetMyNameArgs args) {
        co_return co_await getMyName(std::move(args.language_code));
    }

    /**
     * Use this method to change the bot's description, which is shown in the chat with the bot
     * if the chat is empty. Returns True on success.
     *
     * @param description [optional] Optional.
     * @param language_code [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setmydescription
     */
    struct SetMyDescriptionArgs {
        std::optional<std::string> description;
        std::optional<std::string> language_code;
    };

    drogon::Task<bool> setMyDescription(std::optional<std::string> description = std::nullopt,
                                        std::optional<std::string> language_code = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (description.has_value()) {
            payload["description"] = description.value();
        }
        if (language_code.has_value()) {
            payload["language_code"] = language_code.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setMyDescription", _body)
            : co_await request_->uploadFiles(token_ + "/setMyDescription", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setMyDescription(SetMyDescriptionArgs args) {
        co_return co_await setMyDescription(std::move(args.description),
            std::move(args.language_code));
    }

    /**
     * Use this method to get the current bot description for the given user language. Returns
     * BotDescription on success.
     *
     * @param language_code [optional] Optional.
     * @returns std::shared_ptr<BotDescription>
     * @see https://core.telegram.org/bots/api#getmydescription
     */
    struct GetMyDescriptionArgs {
        std::optional<std::string> language_code;
    };

    drogon::Task<std::shared_ptr<BotDescription>> getMyDescription(std::optional<std::string> language_code = std::nullopt) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (language_code.has_value()) {
            payload["language_code"] = language_code.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getMyDescription", _body)
            : co_await request_->uploadFiles(token_ + "/getMyDescription", _body, _uploads);
        co_return parse_response<std::shared_ptr<BotDescription>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<BotDescription>> getMyDescription(GetMyDescriptionArgs args) {
        co_return co_await getMyDescription(std::move(args.language_code));
    }

    /**
     * Use this method to change the bot's short description, which is shown on the bot's
     * profile page and is sent together with the link when users share the bot. Returns True on
     * success.
     *
     * @param short_description [optional] Optional.
     * @param language_code [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setmyshortdescription
     */
    struct SetMyShortDescriptionArgs {
        std::optional<std::string> short_description;
        std::optional<std::string> language_code;
    };

    drogon::Task<bool> setMyShortDescription(std::optional<std::string> short_description = std::nullopt,
                                             std::optional<std::string> language_code = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (short_description.has_value()) {
            payload["short_description"] = short_description.value();
        }
        if (language_code.has_value()) {
            payload["language_code"] = language_code.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setMyShortDescription", _body)
            : co_await request_->uploadFiles(token_ + "/setMyShortDescription", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setMyShortDescription(SetMyShortDescriptionArgs args) {
        co_return co_await setMyShortDescription(std::move(args.short_description),
            std::move(args.language_code));
    }

    /**
     * Use this method to get the current bot short description for the given user language.
     * Returns BotShortDescription on success.
     *
     * @param language_code [optional] Optional.
     * @returns std::shared_ptr<BotShortDescription>
     * @see https://core.telegram.org/bots/api#getmyshortdescription
     */
    struct GetMyShortDescriptionArgs {
        std::optional<std::string> language_code;
    };

    drogon::Task<std::shared_ptr<BotShortDescription>> getMyShortDescription(std::optional<std::string> language_code = std::nullopt) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (language_code.has_value()) {
            payload["language_code"] = language_code.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getMyShortDescription", _body)
            : co_await request_->uploadFiles(token_ + "/getMyShortDescription", _body, _uploads);
        co_return parse_response<std::shared_ptr<BotShortDescription>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<BotShortDescription>> getMyShortDescription(GetMyShortDescriptionArgs args) {
        co_return co_await getMyShortDescription(std::move(args.language_code));
    }

    /**
     * Changes the profile photo of the bot. Returns True on success.
     *
     * @param photo [required] The new profile photo to set.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setmyprofilephoto
     */
    struct SetMyProfilePhotoArgs {
        InputProfilePhoto photo{};
    };

    drogon::Task<bool> setMyProfilePhoto(const InputProfilePhoto& photo) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        {
            json _sub;
            to_json(_sub, photo);
            payload["photo"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setMyProfilePhoto", _body)
            : co_await request_->uploadFiles(token_ + "/setMyProfilePhoto", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setMyProfilePhoto(SetMyProfilePhotoArgs args) {
        co_return co_await setMyProfilePhoto(std::move(args.photo));
    }

    /**
     * Removes the profile photo of the bot. Requires no parameters. Returns True on success.
     *
     * @returns bool
     * @see https://core.telegram.org/bots/api#removemyprofilephoto
     */
    drogon::Task<bool> removeMyProfilePhoto() const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/removeMyProfilePhoto", _body)
            : co_await request_->uploadFiles(token_ + "/removeMyProfilePhoto", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    /**
     * Use this method to change the bot's menu button in a private chat, or the default menu
     * button. Returns True on success.
     *
     * @param chat_id [optional] Optional.
     * @param menu_button [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setchatmenubutton
     */
    struct SetChatMenuButtonArgs {
        std::optional<int64_t> chat_id;
        std::optional<MenuButton> menu_button;
    };

    drogon::Task<bool> setChatMenuButton(std::optional<int64_t> chat_id = std::nullopt,
                                         std::optional<MenuButton> menu_button = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (chat_id.has_value()) {
            payload["chat_id"] = chat_id.value();
        }
        if (menu_button.has_value()) {
            json _sub;
            to_json(_sub, menu_button.value());
            payload["menu_button"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setChatMenuButton", _body)
            : co_await request_->uploadFiles(token_ + "/setChatMenuButton", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setChatMenuButton(SetChatMenuButtonArgs args) {
        co_return co_await setChatMenuButton(std::move(args.chat_id),
            std::move(args.menu_button));
    }

    /**
     * Use this method to get the current value of the bot's menu button in a private chat, or
     * the default menu button. Returns MenuButton on success.
     *
     * @param chat_id [optional] Optional.
     * @returns MenuButton
     * @see https://core.telegram.org/bots/api#getchatmenubutton
     */
    struct GetChatMenuButtonArgs {
        std::optional<int64_t> chat_id;
    };

    drogon::Task<MenuButton> getChatMenuButton(std::optional<int64_t> chat_id = std::nullopt) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (chat_id.has_value()) {
            payload["chat_id"] = chat_id.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getChatMenuButton", _body)
            : co_await request_->uploadFiles(token_ + "/getChatMenuButton", _body, _uploads);
        co_return parse_response<MenuButton>(_resp).result.value();
    }

    drogon::Task<MenuButton> getChatMenuButton(GetChatMenuButtonArgs args) {
        co_return co_await getChatMenuButton(std::move(args.chat_id));
    }

    /**
     * Use this method to change the default administrator rights requested by the bot when it's
     * added as an administrator to groups or channels. These rights will be suggested to users,
     * but they are free to modify the list before adding the bot. Returns True on success.
     *
     * @param rights [optional] Optional.
     * @param for_channels [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setmydefaultadministratorrights
     */
    struct SetMyDefaultAdministratorRightsArgs {
        std::shared_ptr<ChatAdministratorRights> rights;
        std::optional<bool> for_channels;
    };

    drogon::Task<bool> setMyDefaultAdministratorRights(std::shared_ptr<ChatAdministratorRights> rights = nullptr,
                                                       std::optional<bool> for_channels = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (rights) {
            json _sub;
            to_json(_sub, *rights);
            payload["rights"] = std::move(_sub);
        }
        if (for_channels.has_value()) {
            payload["for_channels"] = for_channels.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setMyDefaultAdministratorRights", _body)
            : co_await request_->uploadFiles(token_ + "/setMyDefaultAdministratorRights", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setMyDefaultAdministratorRights(SetMyDefaultAdministratorRightsArgs args) {
        co_return co_await setMyDefaultAdministratorRights(std::move(args.rights),
            std::move(args.for_channels));
    }

    /**
     * Use this method to get the current default administrator rights of the bot. Returns
     * ChatAdministratorRights on success.
     *
     * @param for_channels [optional] Optional.
     * @returns std::shared_ptr<ChatAdministratorRights>
     * @see https://core.telegram.org/bots/api#getmydefaultadministratorrights
     */
    struct GetMyDefaultAdministratorRightsArgs {
        std::optional<bool> for_channels;
    };

    drogon::Task<std::shared_ptr<ChatAdministratorRights>> getMyDefaultAdministratorRights(std::optional<bool> for_channels = std::nullopt) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (for_channels.has_value()) {
            payload["for_channels"] = for_channels.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getMyDefaultAdministratorRights", _body)
            : co_await request_->uploadFiles(token_ + "/getMyDefaultAdministratorRights", _body, _uploads);
        co_return parse_response<std::shared_ptr<ChatAdministratorRights>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<ChatAdministratorRights>> getMyDefaultAdministratorRights(GetMyDefaultAdministratorRightsArgs args) {
        co_return co_await getMyDefaultAdministratorRights(std::move(args.for_channels));
    }

    /**
     * Returns the list of gifts that can be sent by the bot to users and channel chats.
     * Requires no parameters. Returns a Gifts object.
     *
     * @returns std::shared_ptr<Gifts>
     * @see https://core.telegram.org/bots/api#getavailablegifts
     */
    drogon::Task<std::shared_ptr<Gifts>> getAvailableGifts() const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getAvailableGifts", _body)
            : co_await request_->uploadFiles(token_ + "/getAvailableGifts", _body, _uploads);
        co_return parse_response<std::shared_ptr<Gifts>>(_resp).result.value();
    }

    /**
     * Sends a gift to the given user or channel chat. The gift can't be converted to Telegram
     * Stars by the receiver. Returns True on success.
     *
     * @param user_id [optional] Optional.
     * @param chat_id [optional] Optional.
     * @param gift_id [required] Identifier of the gift; limited gifts can't be sent to channel chats.
     * @param pay_for_upgrade [optional] Optional.
     * @param text [optional] Optional.
     * @param text_parse_mode [optional] Optional.
     * @param text_entities [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#sendgift
     */
    struct SendGiftArgs {
        std::string gift_id{""};
        std::optional<int64_t> user_id;
        ChatId chat_id{};
        std::optional<bool> pay_for_upgrade;
        std::optional<std::string> text;
        std::optional<std::string> text_parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> text_entities;
    };

    drogon::Task<bool> sendGift(std::string gift_id,
                                std::optional<int64_t> user_id = std::nullopt,
                                ChatId chat_id = {},
                                std::optional<bool> pay_for_upgrade = std::nullopt,
                                std::optional<std::string> text = std::nullopt,
                                std::optional<std::string> text_parse_mode = std::nullopt,
                                std::vector<std::shared_ptr<MessageEntity>> text_entities = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (user_id.has_value()) {
            payload["user_id"] = user_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["gift_id"] = gift_id;
        if (pay_for_upgrade.has_value()) {
            payload["pay_for_upgrade"] = pay_for_upgrade.value();
        }
        if (text.has_value()) {
            payload["text"] = text.value();
        }
        if (text_parse_mode.has_value()) {
            payload["text_parse_mode"] = text_parse_mode.value();
        }
        if (!text_entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : text_entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["text_entities"] = std::move(_arr);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendGift", _body)
            : co_await request_->uploadFiles(token_ + "/sendGift", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> sendGift(SendGiftArgs args) {
        co_return co_await sendGift(std::move(args.gift_id),
            std::move(args.user_id),
            std::move(args.chat_id),
            std::move(args.pay_for_upgrade),
            std::move(args.text),
            std::move(args.text_parse_mode),
            std::move(args.text_entities));
    }

    /**
     * Gifts a Telegram Premium subscription to the given user. Returns True on success.
     *
     * @param user_id [required] Unique identifier of the target user who will receive a Telegram Premium subscription.
     * @param month_count [required] Number of months the Telegram Premium subscription will be active for the user; must be one of 3, 6,.
     * @param star_count [required] Number of Telegram Stars to pay for the Telegram Premium subscription; must be 1000 for 3 months, 15.
     * @param text [optional] Optional.
     * @param text_parse_mode [optional] Optional.
     * @param text_entities [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#giftpremiumsubscription
     */
    struct GiftPremiumSubscriptionArgs {
        int64_t user_id{0};
        int64_t month_count{0};
        int64_t star_count{0};
        std::optional<std::string> text;
        std::optional<std::string> text_parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> text_entities;
    };

    drogon::Task<bool> giftPremiumSubscription(int64_t user_id,
                                               int64_t month_count,
                                               int64_t star_count,
                                               std::optional<std::string> text = std::nullopt,
                                               std::optional<std::string> text_parse_mode = std::nullopt,
                                               std::vector<std::shared_ptr<MessageEntity>> text_entities = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        payload["month_count"] = month_count;
        payload["star_count"] = star_count;
        if (text.has_value()) {
            payload["text"] = text.value();
        }
        if (text_parse_mode.has_value()) {
            payload["text_parse_mode"] = text_parse_mode.value();
        }
        if (!text_entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : text_entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["text_entities"] = std::move(_arr);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/giftPremiumSubscription", _body)
            : co_await request_->uploadFiles(token_ + "/giftPremiumSubscription", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> giftPremiumSubscription(GiftPremiumSubscriptionArgs args) {
        co_return co_await giftPremiumSubscription(std::move(args.user_id),
            std::move(args.month_count),
            std::move(args.star_count),
            std::move(args.text),
            std::move(args.text_parse_mode),
            std::move(args.text_entities));
    }

    /**
     * Verifies a user on behalf of the organization which is represented by the bot. Returns
     * True on success.
     *
     * @param user_id [required] Unique identifier of the target user.
     * @param custom_description [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#verifyuser
     */
    struct VerifyUserArgs {
        int64_t user_id{0};
        std::optional<std::string> custom_description;
    };

    drogon::Task<bool> verifyUser(int64_t user_id,
                                  std::optional<std::string> custom_description = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        if (custom_description.has_value()) {
            payload["custom_description"] = custom_description.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/verifyUser", _body)
            : co_await request_->uploadFiles(token_ + "/verifyUser", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> verifyUser(VerifyUserArgs args) {
        co_return co_await verifyUser(std::move(args.user_id),
            std::move(args.custom_description));
    }

    /**
     * Verifies a chat on behalf of the organization which is represented by the bot. Returns
     * True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param custom_description [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#verifychat
     */
    struct VerifyChatArgs {
        ChatId chat_id{};
        std::optional<std::string> custom_description;
    };

    drogon::Task<bool> verifyChat(ChatId chat_id,
                                  std::optional<std::string> custom_description = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (custom_description.has_value()) {
            payload["custom_description"] = custom_description.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/verifyChat", _body)
            : co_await request_->uploadFiles(token_ + "/verifyChat", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> verifyChat(VerifyChatArgs args) {
        co_return co_await verifyChat(std::move(args.chat_id),
            std::move(args.custom_description));
    }

    /**
     * Removes verification from a user who is currently verified on behalf of the organization
     * represented by the bot. Returns True on success.
     *
     * @param user_id [required] Unique identifier of the target user.
     * @returns bool
     * @see https://core.telegram.org/bots/api#removeuserverification
     */
    struct RemoveUserVerificationArgs {
        int64_t user_id{0};
    };

    drogon::Task<bool> removeUserVerification(int64_t user_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/removeUserVerification", _body)
            : co_await request_->uploadFiles(token_ + "/removeUserVerification", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> removeUserVerification(RemoveUserVerificationArgs args) {
        co_return co_await removeUserVerification(std::move(args.user_id));
    }

    /**
     * Removes verification from a chat that is currently verified on behalf of the organization
     * represented by the bot. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot or channel in the format @userna.
     * @returns bool
     * @see https://core.telegram.org/bots/api#removechatverification
     */
    struct RemoveChatVerificationArgs {
        ChatId chat_id{};
    };

    drogon::Task<bool> removeChatVerification(ChatId chat_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/removeChatVerification", _body)
            : co_await request_->uploadFiles(token_ + "/removeChatVerification", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> removeChatVerification(RemoveChatVerificationArgs args) {
        co_return co_await removeChatVerification(std::move(args.chat_id));
    }

    /**
     * Marks incoming message as read on behalf of a business account. Requires the
     * can_read_messages business bot right. Returns True on success.
     *
     * @param business_connection_id [required] Unique identifier of the business connection on behalf of which to read the message.
     * @param chat_id [required] Unique identifier of the chat in which the message was received.
     * @param message_id [required] Unique identifier of the message to mark as read.
     * @returns bool
     * @see https://core.telegram.org/bots/api#readbusinessmessage
     */
    struct ReadBusinessMessageArgs {
        std::string business_connection_id{""};
        int64_t chat_id{0};
        int64_t message_id{0};
    };

    drogon::Task<bool> readBusinessMessage(std::string business_connection_id,
                                           int64_t chat_id,
                                           int64_t message_id) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        payload["chat_id"] = chat_id;
        payload["message_id"] = message_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/readBusinessMessage", _body)
            : co_await request_->uploadFiles(token_ + "/readBusinessMessage", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> readBusinessMessage(ReadBusinessMessageArgs args) {
        co_return co_await readBusinessMessage(std::move(args.business_connection_id),
            std::move(args.chat_id),
            std::move(args.message_id));
    }

    /**
     * Delete messages on behalf of a business account. Requires the can_delete_sent_messages
     * business bot right to delete messages sent by the bot itself, or the
     * can_delete_all_messages business bot right to delete any message. Returns True on
     * success.
     *
     * @param business_connection_id [required] Unique identifier of the business connection on behalf of which to delete the messages.
     * @param message_ids [required] A JSON-serialized list of 1-100 identifiers of messages to delete.
     * @returns bool
     * @see https://core.telegram.org/bots/api#deletebusinessmessages
     */
    struct DeleteBusinessMessagesArgs {
        std::string business_connection_id{""};
        std::vector<int64_t> message_ids;
    };

    drogon::Task<bool> deleteBusinessMessages(std::string business_connection_id,
                                              std::vector<int64_t> message_ids) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        {
            json _arr = json::array();
            for (const auto& _item : message_ids) {
                _arr.push_back(_item);
            }
            payload["message_ids"] = std::move(_arr);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/deleteBusinessMessages", _body)
            : co_await request_->uploadFiles(token_ + "/deleteBusinessMessages", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> deleteBusinessMessages(DeleteBusinessMessagesArgs args) {
        co_return co_await deleteBusinessMessages(std::move(args.business_connection_id),
            std::move(args.message_ids));
    }

    /**
     * Changes the first and last name of a managed business account. Requires the
     * can_change_name business bot right. Returns True on success.
     *
     * @param business_connection_id [required] Unique identifier of the business connection.
     * @param first_name [required] The new value of the first name for the business account; 1-64 characters.
     * @param last_name [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setbusinessaccountname
     */
    struct SetBusinessAccountNameArgs {
        std::string business_connection_id{""};
        std::string first_name{""};
        std::optional<std::string> last_name;
    };

    drogon::Task<bool> setBusinessAccountName(std::string business_connection_id,
                                              std::string first_name,
                                              std::optional<std::string> last_name = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        payload["first_name"] = first_name;
        if (last_name.has_value()) {
            payload["last_name"] = last_name.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setBusinessAccountName", _body)
            : co_await request_->uploadFiles(token_ + "/setBusinessAccountName", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setBusinessAccountName(SetBusinessAccountNameArgs args) {
        co_return co_await setBusinessAccountName(std::move(args.business_connection_id),
            std::move(args.first_name),
            std::move(args.last_name));
    }

    /**
     * Changes the username of a managed business account. Requires the can_change_username
     * business bot right. Returns True on success.
     *
     * @param business_connection_id [required] Unique identifier of the business connection.
     * @param username [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setbusinessaccountusername
     */
    struct SetBusinessAccountUsernameArgs {
        std::string business_connection_id{""};
        std::optional<std::string> username;
    };

    drogon::Task<bool> setBusinessAccountUsername(std::string business_connection_id,
                                                  std::optional<std::string> username = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        if (username.has_value()) {
            payload["username"] = username.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setBusinessAccountUsername", _body)
            : co_await request_->uploadFiles(token_ + "/setBusinessAccountUsername", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setBusinessAccountUsername(SetBusinessAccountUsernameArgs args) {
        co_return co_await setBusinessAccountUsername(std::move(args.business_connection_id),
            std::move(args.username));
    }

    /**
     * Changes the bio of a managed business account. Requires the can_change_bio business bot
     * right. Returns True on success.
     *
     * @param business_connection_id [required] Unique identifier of the business connection.
     * @param bio [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setbusinessaccountbio
     */
    struct SetBusinessAccountBioArgs {
        std::string business_connection_id{""};
        std::optional<std::string> bio;
    };

    drogon::Task<bool> setBusinessAccountBio(std::string business_connection_id,
                                             std::optional<std::string> bio = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        if (bio.has_value()) {
            payload["bio"] = bio.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setBusinessAccountBio", _body)
            : co_await request_->uploadFiles(token_ + "/setBusinessAccountBio", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setBusinessAccountBio(SetBusinessAccountBioArgs args) {
        co_return co_await setBusinessAccountBio(std::move(args.business_connection_id),
            std::move(args.bio));
    }

    /**
     * Changes the profile photo of a managed business account. Requires the
     * can_edit_profile_photo business bot right. Returns True on success.
     *
     * @param business_connection_id [required] Unique identifier of the business connection.
     * @param photo [required] The new profile photo to set.
     * @param is_public [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setbusinessaccountprofilephoto
     */
    struct SetBusinessAccountProfilePhotoArgs {
        std::string business_connection_id{""};
        InputProfilePhoto photo{};
        std::optional<bool> is_public;
    };

    drogon::Task<bool> setBusinessAccountProfilePhoto(std::string business_connection_id,
                                                      const InputProfilePhoto& photo,
                                                      std::optional<bool> is_public = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        {
            json _sub;
            to_json(_sub, photo);
            payload["photo"] = std::move(_sub);
        }
        if (is_public.has_value()) {
            payload["is_public"] = is_public.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setBusinessAccountProfilePhoto", _body)
            : co_await request_->uploadFiles(token_ + "/setBusinessAccountProfilePhoto", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setBusinessAccountProfilePhoto(SetBusinessAccountProfilePhotoArgs args) {
        co_return co_await setBusinessAccountProfilePhoto(std::move(args.business_connection_id),
            std::move(args.photo),
            std::move(args.is_public));
    }

    /**
     * Removes the current profile photo of a managed business account. Requires the
     * can_edit_profile_photo business bot right. Returns True on success.
     *
     * @param business_connection_id [required] Unique identifier of the business connection.
     * @param is_public [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#removebusinessaccountprofilephoto
     */
    struct RemoveBusinessAccountProfilePhotoArgs {
        std::string business_connection_id{""};
        std::optional<bool> is_public;
    };

    drogon::Task<bool> removeBusinessAccountProfilePhoto(std::string business_connection_id,
                                                         std::optional<bool> is_public = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        if (is_public.has_value()) {
            payload["is_public"] = is_public.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/removeBusinessAccountProfilePhoto", _body)
            : co_await request_->uploadFiles(token_ + "/removeBusinessAccountProfilePhoto", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> removeBusinessAccountProfilePhoto(RemoveBusinessAccountProfilePhotoArgs args) {
        co_return co_await removeBusinessAccountProfilePhoto(std::move(args.business_connection_id),
            std::move(args.is_public));
    }

    /**
     * Changes the privacy settings pertaining to incoming gifts in a managed business account.
     * Requires the can_change_gift_settings business bot right. Returns True on success.
     *
     * @param business_connection_id [required] Unique identifier of the business connection.
     * @param show_gift_button [required] Pass True , if a button for sending a gift to the user or by the business account must always be sho.
     * @param accepted_gift_types [required] Types of gifts accepted by the business account.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setbusinessaccountgiftsettings
     */
    struct SetBusinessAccountGiftSettingsArgs {
        std::string business_connection_id{""};
        bool show_gift_button{false};
        std::shared_ptr<AcceptedGiftTypes> accepted_gift_types;
    };

    drogon::Task<bool> setBusinessAccountGiftSettings(std::string business_connection_id,
                                                      bool show_gift_button,
                                                      std::shared_ptr<AcceptedGiftTypes> accepted_gift_types) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        payload["show_gift_button"] = show_gift_button;
        {
            json _sub;
            to_json(_sub, *accepted_gift_types);
            payload["accepted_gift_types"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setBusinessAccountGiftSettings", _body)
            : co_await request_->uploadFiles(token_ + "/setBusinessAccountGiftSettings", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setBusinessAccountGiftSettings(SetBusinessAccountGiftSettingsArgs args) {
        co_return co_await setBusinessAccountGiftSettings(std::move(args.business_connection_id),
            std::move(args.show_gift_button),
            std::move(args.accepted_gift_types));
    }

    /**
     * Returns the amount of Telegram Stars owned by a managed business account. Requires the
     * can_view_gifts_and_stars business bot right. Returns StarAmount on success.
     *
     * @param business_connection_id [required] Unique identifier of the business connection.
     * @returns std::shared_ptr<StarAmount>
     * @see https://core.telegram.org/bots/api#getbusinessaccountstarbalance
     */
    struct GetBusinessAccountStarBalanceArgs {
        std::string business_connection_id{""};
    };

    drogon::Task<std::shared_ptr<StarAmount>> getBusinessAccountStarBalance(std::string business_connection_id) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getBusinessAccountStarBalance", _body)
            : co_await request_->uploadFiles(token_ + "/getBusinessAccountStarBalance", _body, _uploads);
        co_return parse_response<std::shared_ptr<StarAmount>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<StarAmount>> getBusinessAccountStarBalance(GetBusinessAccountStarBalanceArgs args) {
        co_return co_await getBusinessAccountStarBalance(std::move(args.business_connection_id));
    }

    /**
     * Transfers Telegram Stars from the business account balance to the bot's balance. Requires
     * the can_transfer_stars business bot right. Returns True on success.
     *
     * @param business_connection_id [required] Unique identifier of the business connection.
     * @param star_count [required] Number of Telegram Stars to transfer; 1-10000.
     * @returns bool
     * @see https://core.telegram.org/bots/api#transferbusinessaccountstars
     */
    struct TransferBusinessAccountStarsArgs {
        std::string business_connection_id{""};
        int64_t star_count{0};
    };

    drogon::Task<bool> transferBusinessAccountStars(std::string business_connection_id,
                                                    int64_t star_count) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        payload["star_count"] = star_count;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/transferBusinessAccountStars", _body)
            : co_await request_->uploadFiles(token_ + "/transferBusinessAccountStars", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> transferBusinessAccountStars(TransferBusinessAccountStarsArgs args) {
        co_return co_await transferBusinessAccountStars(std::move(args.business_connection_id),
            std::move(args.star_count));
    }

    /**
     * Returns the gifts received and owned by a managed business account. Requires the
     * can_view_gifts_and_stars business bot right. Returns OwnedGifts on success.
     *
     * @param business_connection_id [required] Unique identifier of the business connection.
     * @param exclude_unsaved [optional] Optional.
     * @param exclude_saved [optional] Optional.
     * @param exclude_unlimited [optional] Optional.
     * @param exclude_limited_upgradable [optional] Optional.
     * @param exclude_limited_non_upgradable [optional] Optional.
     * @param exclude_unique [optional] Optional.
     * @param exclude_from_blockchain [optional] Optional.
     * @param sort_by_price [optional] Optional.
     * @param offset [optional] Optional.
     * @param limit [optional] Optional.
     * @returns std::shared_ptr<OwnedGifts>
     * @see https://core.telegram.org/bots/api#getbusinessaccountgifts
     */
    struct GetBusinessAccountGiftsArgs {
        std::string business_connection_id{""};
        std::optional<bool> exclude_unsaved;
        std::optional<bool> exclude_saved;
        std::optional<bool> exclude_unlimited;
        std::optional<bool> exclude_limited_upgradable;
        std::optional<bool> exclude_limited_non_upgradable;
        std::optional<bool> exclude_unique;
        std::optional<bool> exclude_from_blockchain;
        std::optional<bool> sort_by_price;
        std::optional<std::string> offset;
        std::optional<int64_t> limit;
    };

    drogon::Task<std::shared_ptr<OwnedGifts>> getBusinessAccountGifts(std::string business_connection_id,
                                                                      std::optional<bool> exclude_unsaved = std::nullopt,
                                                                      std::optional<bool> exclude_saved = std::nullopt,
                                                                      std::optional<bool> exclude_unlimited = std::nullopt,
                                                                      std::optional<bool> exclude_limited_upgradable = std::nullopt,
                                                                      std::optional<bool> exclude_limited_non_upgradable = std::nullopt,
                                                                      std::optional<bool> exclude_unique = std::nullopt,
                                                                      std::optional<bool> exclude_from_blockchain = std::nullopt,
                                                                      std::optional<bool> sort_by_price = std::nullopt,
                                                                      std::optional<std::string> offset = std::nullopt,
                                                                      std::optional<int64_t> limit = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        if (exclude_unsaved.has_value()) {
            payload["exclude_unsaved"] = exclude_unsaved.value();
        }
        if (exclude_saved.has_value()) {
            payload["exclude_saved"] = exclude_saved.value();
        }
        if (exclude_unlimited.has_value()) {
            payload["exclude_unlimited"] = exclude_unlimited.value();
        }
        if (exclude_limited_upgradable.has_value()) {
            payload["exclude_limited_upgradable"] = exclude_limited_upgradable.value();
        }
        if (exclude_limited_non_upgradable.has_value()) {
            payload["exclude_limited_non_upgradable"] = exclude_limited_non_upgradable.value();
        }
        if (exclude_unique.has_value()) {
            payload["exclude_unique"] = exclude_unique.value();
        }
        if (exclude_from_blockchain.has_value()) {
            payload["exclude_from_blockchain"] = exclude_from_blockchain.value();
        }
        if (sort_by_price.has_value()) {
            payload["sort_by_price"] = sort_by_price.value();
        }
        if (offset.has_value()) {
            payload["offset"] = offset.value();
        }
        if (limit.has_value()) {
            payload["limit"] = limit.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getBusinessAccountGifts", _body)
            : co_await request_->uploadFiles(token_ + "/getBusinessAccountGifts", _body, _uploads);
        co_return parse_response<std::shared_ptr<OwnedGifts>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<OwnedGifts>> getBusinessAccountGifts(GetBusinessAccountGiftsArgs args) {
        co_return co_await getBusinessAccountGifts(std::move(args.business_connection_id),
            std::move(args.exclude_unsaved),
            std::move(args.exclude_saved),
            std::move(args.exclude_unlimited),
            std::move(args.exclude_limited_upgradable),
            std::move(args.exclude_limited_non_upgradable),
            std::move(args.exclude_unique),
            std::move(args.exclude_from_blockchain),
            std::move(args.sort_by_price),
            std::move(args.offset),
            std::move(args.limit));
    }

    /**
     * Returns the gifts owned and hosted by a user. Returns OwnedGifts on success.
     *
     * @param user_id [required] Unique identifier of the user.
     * @param exclude_unlimited [optional] Optional.
     * @param exclude_limited_upgradable [optional] Optional.
     * @param exclude_limited_non_upgradable [optional] Optional.
     * @param exclude_from_blockchain [optional] Optional.
     * @param exclude_unique [optional] Optional.
     * @param sort_by_price [optional] Optional.
     * @param offset [optional] Optional.
     * @param limit [optional] Optional.
     * @returns std::shared_ptr<OwnedGifts>
     * @see https://core.telegram.org/bots/api#getusergifts
     */
    struct GetUserGiftsArgs {
        int64_t user_id{0};
        std::optional<bool> exclude_unlimited;
        std::optional<bool> exclude_limited_upgradable;
        std::optional<bool> exclude_limited_non_upgradable;
        std::optional<bool> exclude_from_blockchain;
        std::optional<bool> exclude_unique;
        std::optional<bool> sort_by_price;
        std::optional<std::string> offset;
        std::optional<int64_t> limit;
    };

    drogon::Task<std::shared_ptr<OwnedGifts>> getUserGifts(int64_t user_id,
                                                           std::optional<bool> exclude_unlimited = std::nullopt,
                                                           std::optional<bool> exclude_limited_upgradable = std::nullopt,
                                                           std::optional<bool> exclude_limited_non_upgradable = std::nullopt,
                                                           std::optional<bool> exclude_from_blockchain = std::nullopt,
                                                           std::optional<bool> exclude_unique = std::nullopt,
                                                           std::optional<bool> sort_by_price = std::nullopt,
                                                           std::optional<std::string> offset = std::nullopt,
                                                           std::optional<int64_t> limit = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        if (exclude_unlimited.has_value()) {
            payload["exclude_unlimited"] = exclude_unlimited.value();
        }
        if (exclude_limited_upgradable.has_value()) {
            payload["exclude_limited_upgradable"] = exclude_limited_upgradable.value();
        }
        if (exclude_limited_non_upgradable.has_value()) {
            payload["exclude_limited_non_upgradable"] = exclude_limited_non_upgradable.value();
        }
        if (exclude_from_blockchain.has_value()) {
            payload["exclude_from_blockchain"] = exclude_from_blockchain.value();
        }
        if (exclude_unique.has_value()) {
            payload["exclude_unique"] = exclude_unique.value();
        }
        if (sort_by_price.has_value()) {
            payload["sort_by_price"] = sort_by_price.value();
        }
        if (offset.has_value()) {
            payload["offset"] = offset.value();
        }
        if (limit.has_value()) {
            payload["limit"] = limit.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getUserGifts", _body)
            : co_await request_->uploadFiles(token_ + "/getUserGifts", _body, _uploads);
        co_return parse_response<std::shared_ptr<OwnedGifts>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<OwnedGifts>> getUserGifts(GetUserGiftsArgs args) {
        co_return co_await getUserGifts(std::move(args.user_id),
            std::move(args.exclude_unlimited),
            std::move(args.exclude_limited_upgradable),
            std::move(args.exclude_limited_non_upgradable),
            std::move(args.exclude_from_blockchain),
            std::move(args.exclude_unique),
            std::move(args.sort_by_price),
            std::move(args.offset),
            std::move(args.limit));
    }

    /**
     * Returns the gifts owned by a chat. Returns OwnedGifts on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target channel in the format @username.
     * @param exclude_unsaved [optional] Optional.
     * @param exclude_saved [optional] Optional.
     * @param exclude_unlimited [optional] Optional.
     * @param exclude_limited_upgradable [optional] Optional.
     * @param exclude_limited_non_upgradable [optional] Optional.
     * @param exclude_from_blockchain [optional] Optional.
     * @param exclude_unique [optional] Optional.
     * @param sort_by_price [optional] Optional.
     * @param offset [optional] Optional.
     * @param limit [optional] Optional.
     * @returns std::shared_ptr<OwnedGifts>
     * @see https://core.telegram.org/bots/api#getchatgifts
     */
    struct GetChatGiftsArgs {
        ChatId chat_id{};
        std::optional<bool> exclude_unsaved;
        std::optional<bool> exclude_saved;
        std::optional<bool> exclude_unlimited;
        std::optional<bool> exclude_limited_upgradable;
        std::optional<bool> exclude_limited_non_upgradable;
        std::optional<bool> exclude_from_blockchain;
        std::optional<bool> exclude_unique;
        std::optional<bool> sort_by_price;
        std::optional<std::string> offset;
        std::optional<int64_t> limit;
    };

    drogon::Task<std::shared_ptr<OwnedGifts>> getChatGifts(ChatId chat_id,
                                                           std::optional<bool> exclude_unsaved = std::nullopt,
                                                           std::optional<bool> exclude_saved = std::nullopt,
                                                           std::optional<bool> exclude_unlimited = std::nullopt,
                                                           std::optional<bool> exclude_limited_upgradable = std::nullopt,
                                                           std::optional<bool> exclude_limited_non_upgradable = std::nullopt,
                                                           std::optional<bool> exclude_from_blockchain = std::nullopt,
                                                           std::optional<bool> exclude_unique = std::nullopt,
                                                           std::optional<bool> sort_by_price = std::nullopt,
                                                           std::optional<std::string> offset = std::nullopt,
                                                           std::optional<int64_t> limit = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (exclude_unsaved.has_value()) {
            payload["exclude_unsaved"] = exclude_unsaved.value();
        }
        if (exclude_saved.has_value()) {
            payload["exclude_saved"] = exclude_saved.value();
        }
        if (exclude_unlimited.has_value()) {
            payload["exclude_unlimited"] = exclude_unlimited.value();
        }
        if (exclude_limited_upgradable.has_value()) {
            payload["exclude_limited_upgradable"] = exclude_limited_upgradable.value();
        }
        if (exclude_limited_non_upgradable.has_value()) {
            payload["exclude_limited_non_upgradable"] = exclude_limited_non_upgradable.value();
        }
        if (exclude_from_blockchain.has_value()) {
            payload["exclude_from_blockchain"] = exclude_from_blockchain.value();
        }
        if (exclude_unique.has_value()) {
            payload["exclude_unique"] = exclude_unique.value();
        }
        if (sort_by_price.has_value()) {
            payload["sort_by_price"] = sort_by_price.value();
        }
        if (offset.has_value()) {
            payload["offset"] = offset.value();
        }
        if (limit.has_value()) {
            payload["limit"] = limit.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getChatGifts", _body)
            : co_await request_->uploadFiles(token_ + "/getChatGifts", _body, _uploads);
        co_return parse_response<std::shared_ptr<OwnedGifts>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<OwnedGifts>> getChatGifts(GetChatGiftsArgs args) {
        co_return co_await getChatGifts(std::move(args.chat_id),
            std::move(args.exclude_unsaved),
            std::move(args.exclude_saved),
            std::move(args.exclude_unlimited),
            std::move(args.exclude_limited_upgradable),
            std::move(args.exclude_limited_non_upgradable),
            std::move(args.exclude_from_blockchain),
            std::move(args.exclude_unique),
            std::move(args.sort_by_price),
            std::move(args.offset),
            std::move(args.limit));
    }

    /**
     * Converts a given regular gift to Telegram Stars. Requires the can_convert_gifts_to_stars
     * business bot right. Returns True on success.
     *
     * @param business_connection_id [required] Unique identifier of the business connection.
     * @param owned_gift_id [required] Unique identifier of the regular gift that should be converted to Telegram Stars.
     * @returns bool
     * @see https://core.telegram.org/bots/api#convertgifttostars
     */
    struct ConvertGiftToStarsArgs {
        std::string business_connection_id{""};
        std::string owned_gift_id{""};
    };

    drogon::Task<bool> convertGiftToStars(std::string business_connection_id,
                                          std::string owned_gift_id) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        payload["owned_gift_id"] = owned_gift_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/convertGiftToStars", _body)
            : co_await request_->uploadFiles(token_ + "/convertGiftToStars", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> convertGiftToStars(ConvertGiftToStarsArgs args) {
        co_return co_await convertGiftToStars(std::move(args.business_connection_id),
            std::move(args.owned_gift_id));
    }

    /**
     * Upgrades a given regular gift to a unique gift. Requires the
     * can_transfer_and_upgrade_gifts business bot right. Additionally requires the
     * can_transfer_stars business bot right if the upgrade is paid. Returns True on success.
     *
     * @param business_connection_id [required] Unique identifier of the business connection.
     * @param owned_gift_id [required] Unique identifier of the regular gift that should be upgraded to a unique one.
     * @param keep_original_details [optional] Optional.
     * @param star_count [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#upgradegift
     */
    struct UpgradeGiftArgs {
        std::string business_connection_id{""};
        std::string owned_gift_id{""};
        std::optional<bool> keep_original_details;
        std::optional<int64_t> star_count;
    };

    drogon::Task<bool> upgradeGift(std::string business_connection_id,
                                   std::string owned_gift_id,
                                   std::optional<bool> keep_original_details = std::nullopt,
                                   std::optional<int64_t> star_count = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        payload["owned_gift_id"] = owned_gift_id;
        if (keep_original_details.has_value()) {
            payload["keep_original_details"] = keep_original_details.value();
        }
        if (star_count.has_value()) {
            payload["star_count"] = star_count.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/upgradeGift", _body)
            : co_await request_->uploadFiles(token_ + "/upgradeGift", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> upgradeGift(UpgradeGiftArgs args) {
        co_return co_await upgradeGift(std::move(args.business_connection_id),
            std::move(args.owned_gift_id),
            std::move(args.keep_original_details),
            std::move(args.star_count));
    }

    /**
     * Transfers an owned unique gift to another user. Requires the
     * can_transfer_and_upgrade_gifts business bot right. Requires can_transfer_stars business
     * bot right if the transfer is paid. Returns True on success.
     *
     * @param business_connection_id [required] Unique identifier of the business connection.
     * @param owned_gift_id [required] Unique identifier of the regular gift that should be transferred.
     * @param new_owner_chat_id [required] Unique identifier of the chat which will own the gift.
     * @param star_count [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#transfergift
     */
    struct TransferGiftArgs {
        std::string business_connection_id{""};
        std::string owned_gift_id{""};
        int64_t new_owner_chat_id{0};
        std::optional<int64_t> star_count;
    };

    drogon::Task<bool> transferGift(std::string business_connection_id,
                                    std::string owned_gift_id,
                                    int64_t new_owner_chat_id,
                                    std::optional<int64_t> star_count = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        payload["owned_gift_id"] = owned_gift_id;
        payload["new_owner_chat_id"] = new_owner_chat_id;
        if (star_count.has_value()) {
            payload["star_count"] = star_count.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/transferGift", _body)
            : co_await request_->uploadFiles(token_ + "/transferGift", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> transferGift(TransferGiftArgs args) {
        co_return co_await transferGift(std::move(args.business_connection_id),
            std::move(args.owned_gift_id),
            std::move(args.new_owner_chat_id),
            std::move(args.star_count));
    }

    /**
     * Posts a story on behalf of a managed business account. Requires the can_manage_stories
     * business bot right. Returns Story on success.
     *
     * @param business_connection_id [required] Unique identifier of the business connection.
     * @param content [required] Content of the story.
     * @param active_period [required] Period after which the story is moved to the archive, in seconds; must be one of 6 * 3600 , 12 * 360.
     * @param caption [optional] Optional.
     * @param parse_mode [optional] Optional.
     * @param caption_entities [optional] Optional.
     * @param areas [optional] Optional.
     * @param post_to_chat_page [optional] Optional.
     * @param protect_content [optional] Optional.
     * @returns std::shared_ptr<Story>
     * @see https://core.telegram.org/bots/api#poststory
     */
    struct PostStoryArgs {
        std::string business_connection_id{""};
        InputStoryContent content{};
        int64_t active_period{0};
        std::optional<std::string> caption;
        std::optional<std::string> parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> caption_entities;
        std::vector<std::shared_ptr<StoryArea>> areas;
        std::optional<bool> post_to_chat_page;
        std::optional<bool> protect_content;
    };

    drogon::Task<std::shared_ptr<Story>> postStory(std::string business_connection_id,
                                                   const InputStoryContent& content,
                                                   int64_t active_period,
                                                   std::optional<std::string> caption = std::nullopt,
                                                   std::optional<std::string> parse_mode = std::nullopt,
                                                   std::vector<std::shared_ptr<MessageEntity>> caption_entities = {},
                                                   std::vector<std::shared_ptr<StoryArea>> areas = {},
                                                   std::optional<bool> post_to_chat_page = std::nullopt,
                                                   std::optional<bool> protect_content = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        {
            json _sub;
            to_json(_sub, content);
            payload["content"] = std::move(_sub);
        }
        payload["active_period"] = active_period;
        if (caption.has_value()) {
            payload["caption"] = caption.value();
        }
        if (parse_mode.has_value()) {
            payload["parse_mode"] = parse_mode.value();
        }
        if (!caption_entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : caption_entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["caption_entities"] = std::move(_arr);
        }
        if (!areas.empty()) {
            json _arr = json::array();
            for (const auto& _item : areas) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["areas"] = std::move(_arr);
        }
        if (post_to_chat_page.has_value()) {
            payload["post_to_chat_page"] = post_to_chat_page.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/postStory", _body)
            : co_await request_->uploadFiles(token_ + "/postStory", _body, _uploads);
        co_return parse_response<std::shared_ptr<Story>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Story>> postStory(PostStoryArgs args) {
        co_return co_await postStory(std::move(args.business_connection_id),
            std::move(args.content),
            std::move(args.active_period),
            std::move(args.caption),
            std::move(args.parse_mode),
            std::move(args.caption_entities),
            std::move(args.areas),
            std::move(args.post_to_chat_page),
            std::move(args.protect_content));
    }

    /**
     * Reposts a story on behalf of a business account from another business account. Both
     * business accounts must be managed by the same bot, and the story on the source account
     * must have been posted (or reposted) by the bot. Requires the can_manage_stories business
     * bot right for both business accounts. Returns Story on success.
     *
     * @param business_connection_id [required] Unique identifier of the business connection.
     * @param from_chat_id [required] Unique identifier of the chat which posted the story that should be reposted.
     * @param from_story_id [required] Unique identifier of the story that should be reposted.
     * @param active_period [required] Period after which the story is moved to the archive, in seconds; must be one of 6 * 3600 , 12 * 360.
     * @param post_to_chat_page [optional] Optional.
     * @param protect_content [optional] Optional.
     * @returns std::shared_ptr<Story>
     * @see https://core.telegram.org/bots/api#repoststory
     */
    struct RepostStoryArgs {
        std::string business_connection_id{""};
        int64_t from_chat_id{0};
        int64_t from_story_id{0};
        int64_t active_period{0};
        std::optional<bool> post_to_chat_page;
        std::optional<bool> protect_content;
    };

    drogon::Task<std::shared_ptr<Story>> repostStory(std::string business_connection_id,
                                                     int64_t from_chat_id,
                                                     int64_t from_story_id,
                                                     int64_t active_period,
                                                     std::optional<bool> post_to_chat_page = std::nullopt,
                                                     std::optional<bool> protect_content = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        payload["from_chat_id"] = from_chat_id;
        payload["from_story_id"] = from_story_id;
        payload["active_period"] = active_period;
        if (post_to_chat_page.has_value()) {
            payload["post_to_chat_page"] = post_to_chat_page.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/repostStory", _body)
            : co_await request_->uploadFiles(token_ + "/repostStory", _body, _uploads);
        co_return parse_response<std::shared_ptr<Story>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Story>> repostStory(RepostStoryArgs args) {
        co_return co_await repostStory(std::move(args.business_connection_id),
            std::move(args.from_chat_id),
            std::move(args.from_story_id),
            std::move(args.active_period),
            std::move(args.post_to_chat_page),
            std::move(args.protect_content));
    }

    /**
     * Edits a story previously posted by the bot on behalf of a managed business account.
     * Requires the can_manage_stories business bot right. Returns Story on success.
     *
     * @param business_connection_id [required] Unique identifier of the business connection.
     * @param story_id [required] Unique identifier of the story to edit.
     * @param content [required] Content of the story.
     * @param caption [optional] Optional.
     * @param parse_mode [optional] Optional.
     * @param caption_entities [optional] Optional.
     * @param areas [optional] Optional.
     * @returns std::shared_ptr<Story>
     * @see https://core.telegram.org/bots/api#editstory
     */
    struct EditStoryArgs {
        std::string business_connection_id{""};
        int64_t story_id{0};
        InputStoryContent content{};
        std::optional<std::string> caption;
        std::optional<std::string> parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> caption_entities;
        std::vector<std::shared_ptr<StoryArea>> areas;
    };

    drogon::Task<std::shared_ptr<Story>> editStory(std::string business_connection_id,
                                                   int64_t story_id,
                                                   const InputStoryContent& content,
                                                   std::optional<std::string> caption = std::nullopt,
                                                   std::optional<std::string> parse_mode = std::nullopt,
                                                   std::vector<std::shared_ptr<MessageEntity>> caption_entities = {},
                                                   std::vector<std::shared_ptr<StoryArea>> areas = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        payload["story_id"] = story_id;
        {
            json _sub;
            to_json(_sub, content);
            payload["content"] = std::move(_sub);
        }
        if (caption.has_value()) {
            payload["caption"] = caption.value();
        }
        if (parse_mode.has_value()) {
            payload["parse_mode"] = parse_mode.value();
        }
        if (!caption_entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : caption_entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["caption_entities"] = std::move(_arr);
        }
        if (!areas.empty()) {
            json _arr = json::array();
            for (const auto& _item : areas) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["areas"] = std::move(_arr);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/editStory", _body)
            : co_await request_->uploadFiles(token_ + "/editStory", _body, _uploads);
        co_return parse_response<std::shared_ptr<Story>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Story>> editStory(EditStoryArgs args) {
        co_return co_await editStory(std::move(args.business_connection_id),
            std::move(args.story_id),
            std::move(args.content),
            std::move(args.caption),
            std::move(args.parse_mode),
            std::move(args.caption_entities),
            std::move(args.areas));
    }

    /**
     * Deletes a story previously posted by the bot on behalf of a managed business account.
     * Requires the can_manage_stories business bot right. Returns True on success.
     *
     * @param business_connection_id [required] Unique identifier of the business connection.
     * @param story_id [required] Unique identifier of the story to delete.
     * @returns bool
     * @see https://core.telegram.org/bots/api#deletestory
     */
    struct DeleteStoryArgs {
        std::string business_connection_id{""};
        int64_t story_id{0};
    };

    drogon::Task<bool> deleteStory(std::string business_connection_id,
                                   int64_t story_id) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        payload["story_id"] = story_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/deleteStory", _body)
            : co_await request_->uploadFiles(token_ + "/deleteStory", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> deleteStory(DeleteStoryArgs args) {
        co_return co_await deleteStory(std::move(args.business_connection_id),
            std::move(args.story_id));
    }

    /**
     * Use this method to set the result of an interaction with a Web App and send a
     * corresponding message on behalf of the user to the chat from which the query originated.
     * On success, a SentWebAppMessage object is returned.
     *
     * @param web_app_query_id [required] Unique identifier for the query to be answered.
     * @param result [required] A JSON-serialized object describing the message to be sent.
     * @returns std::shared_ptr<SentWebAppMessage>
     * @see https://core.telegram.org/bots/api#answerwebappquery
     */
    struct AnswerWebAppQueryArgs {
        std::string web_app_query_id{""};
        InlineQueryResult result{};
    };

    drogon::Task<std::shared_ptr<SentWebAppMessage>> answerWebAppQuery(std::string web_app_query_id,
                                                                       const InlineQueryResult& result) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["web_app_query_id"] = web_app_query_id;
        {
            json _sub;
            to_json(_sub, result);
            payload["result"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/answerWebAppQuery", _body)
            : co_await request_->uploadFiles(token_ + "/answerWebAppQuery", _body, _uploads);
        co_return parse_response<std::shared_ptr<SentWebAppMessage>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<SentWebAppMessage>> answerWebAppQuery(AnswerWebAppQueryArgs args) {
        co_return co_await answerWebAppQuery(std::move(args.web_app_query_id),
            std::move(args.result));
    }

    /**
     * Stores a message that can be sent by a user of a Mini App. Returns a
     * PreparedInlineMessage object.
     *
     * @param user_id [required] Unique identifier of the target user that can use the prepared message.
     * @param result [required] A JSON-serialized object describing the message to be sent.
     * @param allow_user_chats [optional] Optional.
     * @param allow_bot_chats [optional] Optional.
     * @param allow_group_chats [optional] Optional.
     * @param allow_channel_chats [optional] Optional.
     * @returns std::shared_ptr<PreparedInlineMessage>
     * @see https://core.telegram.org/bots/api#savepreparedinlinemessage
     */
    struct SavePreparedInlineMessageArgs {
        int64_t user_id{0};
        InlineQueryResult result{};
        std::optional<bool> allow_user_chats;
        std::optional<bool> allow_bot_chats;
        std::optional<bool> allow_group_chats;
        std::optional<bool> allow_channel_chats;
    };

    drogon::Task<std::shared_ptr<PreparedInlineMessage>> savePreparedInlineMessage(int64_t user_id,
                                                                                   const InlineQueryResult& result,
                                                                                   std::optional<bool> allow_user_chats = std::nullopt,
                                                                                   std::optional<bool> allow_bot_chats = std::nullopt,
                                                                                   std::optional<bool> allow_group_chats = std::nullopt,
                                                                                   std::optional<bool> allow_channel_chats = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        {
            json _sub;
            to_json(_sub, result);
            payload["result"] = std::move(_sub);
        }
        if (allow_user_chats.has_value()) {
            payload["allow_user_chats"] = allow_user_chats.value();
        }
        if (allow_bot_chats.has_value()) {
            payload["allow_bot_chats"] = allow_bot_chats.value();
        }
        if (allow_group_chats.has_value()) {
            payload["allow_group_chats"] = allow_group_chats.value();
        }
        if (allow_channel_chats.has_value()) {
            payload["allow_channel_chats"] = allow_channel_chats.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/savePreparedInlineMessage", _body)
            : co_await request_->uploadFiles(token_ + "/savePreparedInlineMessage", _body, _uploads);
        co_return parse_response<std::shared_ptr<PreparedInlineMessage>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<PreparedInlineMessage>> savePreparedInlineMessage(SavePreparedInlineMessageArgs args) {
        co_return co_await savePreparedInlineMessage(std::move(args.user_id),
            std::move(args.result),
            std::move(args.allow_user_chats),
            std::move(args.allow_bot_chats),
            std::move(args.allow_group_chats),
            std::move(args.allow_channel_chats));
    }

    /**
     * Stores a keyboard button that can be used by a user within a Mini App. Returns a
     * PreparedKeyboardButton object.
     *
     * @param user_id [required] Unique identifier of the target user that can use the button.
     * @param button [required] A JSON-serialized object describing the button to be saved.
     * @returns std::shared_ptr<PreparedKeyboardButton>
     * @see https://core.telegram.org/bots/api#savepreparedkeyboardbutton
     */
    struct SavePreparedKeyboardButtonArgs {
        int64_t user_id{0};
        std::shared_ptr<KeyboardButton> button;
    };

    drogon::Task<std::shared_ptr<PreparedKeyboardButton>> savePreparedKeyboardButton(int64_t user_id,
                                                                                     std::shared_ptr<KeyboardButton> button) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        {
            json _sub;
            to_json(_sub, *button);
            payload["button"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/savePreparedKeyboardButton", _body)
            : co_await request_->uploadFiles(token_ + "/savePreparedKeyboardButton", _body, _uploads);
        co_return parse_response<std::shared_ptr<PreparedKeyboardButton>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<PreparedKeyboardButton>> savePreparedKeyboardButton(SavePreparedKeyboardButtonArgs args) {
        co_return co_await savePreparedKeyboardButton(std::move(args.user_id),
            std::move(args.button));
    }

    // ── Updating messages ─────────────────────────────────────────────────────

    /**
     * Use this method to edit text and game messages. On success, if the edited message is not
     * an inline message, the edited Message is returned, otherwise True is returned. Note that
     * business messages that were not sent by the bot and do not contain an inline keyboard can
     * only be edited within 48 hours from the time they were sent.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [optional] Optional.
     * @param message_id [optional] Optional.
     * @param inline_message_id [optional] Optional.
     * @param text [required] New text of the message, 1-4096 characters after entities parsing.
     * @param parse_mode [optional] Optional.
     * @param entities [optional] Optional.
     * @param link_preview_options [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::variant<std::shared_ptr<Message>, bool>
     * @see https://core.telegram.org/bots/api#editmessagetext
     */
    struct EditMessageTextArgs {
        std::string text{""};
        std::optional<std::string> business_connection_id;
        ChatId chat_id{};
        std::optional<int64_t> message_id;
        std::optional<std::string> inline_message_id;
        std::optional<std::string> parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> entities;
        std::shared_ptr<LinkPreviewOptions> link_preview_options;
        std::shared_ptr<InlineKeyboardMarkup> reply_markup;
    };

    drogon::Task<std::variant<std::shared_ptr<Message>, bool>> editMessageText(std::string text,
                                                                               std::optional<std::string> business_connection_id = std::nullopt,
                                                                               ChatId chat_id = {},
                                                                               std::optional<int64_t> message_id = std::nullopt,
                                                                               std::optional<std::string> inline_message_id = std::nullopt,
                                                                               std::optional<std::string> parse_mode = std::nullopt,
                                                                               std::vector<std::shared_ptr<MessageEntity>> entities = {},
                                                                               std::shared_ptr<LinkPreviewOptions> link_preview_options = nullptr,
                                                                               std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_id.has_value()) {
            payload["message_id"] = message_id.value();
        }
        if (inline_message_id.has_value()) {
            payload["inline_message_id"] = inline_message_id.value();
        }
        payload["text"] = text;
        if (parse_mode.has_value()) {
            payload["parse_mode"] = parse_mode.value();
        }
        if (!entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["entities"] = std::move(_arr);
        }
        if (link_preview_options) {
            json _sub;
            to_json(_sub, *link_preview_options);
            payload["link_preview_options"] = std::move(_sub);
        }
        if (reply_markup) {
            json _sub;
            to_json(_sub, *reply_markup);
            payload["reply_markup"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/editMessageText", _body)
            : co_await request_->uploadFiles(token_ + "/editMessageText", _body, _uploads);
        co_return parse_response<std::variant<std::shared_ptr<Message>, bool>>(_resp).result.value();
    }

    drogon::Task<std::variant<std::shared_ptr<Message>, bool>> editMessageText(EditMessageTextArgs args) {
        co_return co_await editMessageText(std::move(args.text),
            std::move(args.business_connection_id),
            std::move(args.chat_id),
            std::move(args.message_id),
            std::move(args.inline_message_id),
            std::move(args.parse_mode),
            std::move(args.entities),
            std::move(args.link_preview_options),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to edit captions of messages. On success, if the edited message is not an
     * inline message, the edited Message is returned, otherwise True is returned. Note that
     * business messages that were not sent by the bot and do not contain an inline keyboard can
     * only be edited within 48 hours from the time they were sent.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [optional] Optional.
     * @param message_id [optional] Optional.
     * @param inline_message_id [optional] Optional.
     * @param caption [optional] Optional.
     * @param parse_mode [optional] Optional.
     * @param caption_entities [optional] Optional.
     * @param show_caption_above_media [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::variant<std::shared_ptr<Message>, bool>
     * @see https://core.telegram.org/bots/api#editmessagecaption
     */
    struct EditMessageCaptionArgs {
        std::optional<std::string> business_connection_id;
        ChatId chat_id{};
        std::optional<int64_t> message_id;
        std::optional<std::string> inline_message_id;
        std::optional<std::string> caption;
        std::optional<std::string> parse_mode;
        std::vector<std::shared_ptr<MessageEntity>> caption_entities;
        std::optional<bool> show_caption_above_media;
        std::shared_ptr<InlineKeyboardMarkup> reply_markup;
    };

    drogon::Task<std::variant<std::shared_ptr<Message>, bool>> editMessageCaption(std::optional<std::string> business_connection_id = std::nullopt,
                                                                                  ChatId chat_id = {},
                                                                                  std::optional<int64_t> message_id = std::nullopt,
                                                                                  std::optional<std::string> inline_message_id = std::nullopt,
                                                                                  std::optional<std::string> caption = std::nullopt,
                                                                                  std::optional<std::string> parse_mode = std::nullopt,
                                                                                  std::vector<std::shared_ptr<MessageEntity>> caption_entities = {},
                                                                                  std::optional<bool> show_caption_above_media = std::nullopt,
                                                                                  std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_id.has_value()) {
            payload["message_id"] = message_id.value();
        }
        if (inline_message_id.has_value()) {
            payload["inline_message_id"] = inline_message_id.value();
        }
        if (caption.has_value()) {
            payload["caption"] = caption.value();
        }
        if (parse_mode.has_value()) {
            payload["parse_mode"] = parse_mode.value();
        }
        if (!caption_entities.empty()) {
            json _arr = json::array();
            for (const auto& _item : caption_entities) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["caption_entities"] = std::move(_arr);
        }
        if (show_caption_above_media.has_value()) {
            payload["show_caption_above_media"] = show_caption_above_media.value();
        }
        if (reply_markup) {
            json _sub;
            to_json(_sub, *reply_markup);
            payload["reply_markup"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/editMessageCaption", _body)
            : co_await request_->uploadFiles(token_ + "/editMessageCaption", _body, _uploads);
        co_return parse_response<std::variant<std::shared_ptr<Message>, bool>>(_resp).result.value();
    }

    drogon::Task<std::variant<std::shared_ptr<Message>, bool>> editMessageCaption(EditMessageCaptionArgs args) {
        co_return co_await editMessageCaption(std::move(args.business_connection_id),
            std::move(args.chat_id),
            std::move(args.message_id),
            std::move(args.inline_message_id),
            std::move(args.caption),
            std::move(args.parse_mode),
            std::move(args.caption_entities),
            std::move(args.show_caption_above_media),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to edit animation, audio, document, live photo, photo, or video messages,
     * or to add media to text messages. If a message is part of a message album, then it can be
     * edited only to an audio for audio albums, only to a document for document albums and to a
     * photo, a live photo, or a video otherwise. When an inline message is edited, a new file
     * can't be uploaded; use a previously uploaded file via its file_id or specify a URL. On
     * success, if the edited message is not an inline message, the edited Message is returned,
     * otherwise True is returned. Note that business messages that were not sent by the bot and
     * do not contain an inline keyboard can only be edited within 48 hours from the time they
     * were sent.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [optional] Optional.
     * @param message_id [optional] Optional.
     * @param inline_message_id [optional] Optional.
     * @param media [required] A JSON-serialized object for a new media content of the message.
     * @param reply_markup [optional] Optional.
     * @returns std::variant<std::shared_ptr<Message>, bool>
     * @see https://core.telegram.org/bots/api#editmessagemedia
     */
    struct EditMessageMediaArgs {
        InputMedia media{};
        std::optional<std::string> business_connection_id;
        ChatId chat_id{};
        std::optional<int64_t> message_id;
        std::optional<std::string> inline_message_id;
        std::shared_ptr<InlineKeyboardMarkup> reply_markup;
    };

    drogon::Task<std::variant<std::shared_ptr<Message>, bool>> editMessageMedia(const InputMedia& media,
                                                                                std::optional<std::string> business_connection_id = std::nullopt,
                                                                                ChatId chat_id = {},
                                                                                std::optional<int64_t> message_id = std::nullopt,
                                                                                std::optional<std::string> inline_message_id = std::nullopt,
                                                                                std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_id.has_value()) {
            payload["message_id"] = message_id.value();
        }
        if (inline_message_id.has_value()) {
            payload["inline_message_id"] = inline_message_id.value();
        }
        {
            json _sub;
            to_json(_sub, media);
            payload["media"] = std::move(_sub);
        }
        if (reply_markup) {
            json _sub;
            to_json(_sub, *reply_markup);
            payload["reply_markup"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/editMessageMedia", _body)
            : co_await request_->uploadFiles(token_ + "/editMessageMedia", _body, _uploads);
        co_return parse_response<std::variant<std::shared_ptr<Message>, bool>>(_resp).result.value();
    }

    drogon::Task<std::variant<std::shared_ptr<Message>, bool>> editMessageMedia(EditMessageMediaArgs args) {
        co_return co_await editMessageMedia(std::move(args.media),
            std::move(args.business_connection_id),
            std::move(args.chat_id),
            std::move(args.message_id),
            std::move(args.inline_message_id),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to edit live location messages. A location can be edited until its
     * live_period expires or editing is explicitly disabled by a call to
     * stopMessageLiveLocation. On success, if the edited message is not an inline message, the
     * edited Message is returned, otherwise True is returned.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [optional] Optional.
     * @param message_id [optional] Optional.
     * @param inline_message_id [optional] Optional.
     * @param latitude [required] Latitude of new location.
     * @param longitude [required] Longitude of new location.
     * @param live_period [optional] Optional.
     * @param horizontal_accuracy [optional] Optional.
     * @param heading [optional] Optional.
     * @param proximity_alert_radius [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::variant<std::shared_ptr<Message>, bool>
     * @see https://core.telegram.org/bots/api#editmessagelivelocation
     */
    struct EditMessageLiveLocationArgs {
        double latitude{0.0};
        double longitude{0.0};
        std::optional<std::string> business_connection_id;
        ChatId chat_id{};
        std::optional<int64_t> message_id;
        std::optional<std::string> inline_message_id;
        std::optional<int64_t> live_period;
        std::optional<double> horizontal_accuracy;
        std::optional<int64_t> heading;
        std::optional<int64_t> proximity_alert_radius;
        std::shared_ptr<InlineKeyboardMarkup> reply_markup;
    };

    drogon::Task<std::variant<std::shared_ptr<Message>, bool>> editMessageLiveLocation(double latitude,
                                                                                       double longitude,
                                                                                       std::optional<std::string> business_connection_id = std::nullopt,
                                                                                       ChatId chat_id = {},
                                                                                       std::optional<int64_t> message_id = std::nullopt,
                                                                                       std::optional<std::string> inline_message_id = std::nullopt,
                                                                                       std::optional<int64_t> live_period = std::nullopt,
                                                                                       std::optional<double> horizontal_accuracy = std::nullopt,
                                                                                       std::optional<int64_t> heading = std::nullopt,
                                                                                       std::optional<int64_t> proximity_alert_radius = std::nullopt,
                                                                                       std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_id.has_value()) {
            payload["message_id"] = message_id.value();
        }
        if (inline_message_id.has_value()) {
            payload["inline_message_id"] = inline_message_id.value();
        }
        payload["latitude"] = latitude;
        payload["longitude"] = longitude;
        if (live_period.has_value()) {
            payload["live_period"] = live_period.value();
        }
        if (horizontal_accuracy.has_value()) {
            payload["horizontal_accuracy"] = horizontal_accuracy.value();
        }
        if (heading.has_value()) {
            payload["heading"] = heading.value();
        }
        if (proximity_alert_radius.has_value()) {
            payload["proximity_alert_radius"] = proximity_alert_radius.value();
        }
        if (reply_markup) {
            json _sub;
            to_json(_sub, *reply_markup);
            payload["reply_markup"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/editMessageLiveLocation", _body)
            : co_await request_->uploadFiles(token_ + "/editMessageLiveLocation", _body, _uploads);
        co_return parse_response<std::variant<std::shared_ptr<Message>, bool>>(_resp).result.value();
    }

    drogon::Task<std::variant<std::shared_ptr<Message>, bool>> editMessageLiveLocation(EditMessageLiveLocationArgs args) {
        co_return co_await editMessageLiveLocation(std::move(args.latitude),
            std::move(args.longitude),
            std::move(args.business_connection_id),
            std::move(args.chat_id),
            std::move(args.message_id),
            std::move(args.inline_message_id),
            std::move(args.live_period),
            std::move(args.horizontal_accuracy),
            std::move(args.heading),
            std::move(args.proximity_alert_radius),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to stop updating a live location message before live_period expires. On
     * success, if the message is not an inline message, the edited Message is returned,
     * otherwise True is returned.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [optional] Optional.
     * @param message_id [optional] Optional.
     * @param inline_message_id [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::variant<std::shared_ptr<Message>, bool>
     * @see https://core.telegram.org/bots/api#stopmessagelivelocation
     */
    struct StopMessageLiveLocationArgs {
        std::optional<std::string> business_connection_id;
        ChatId chat_id{};
        std::optional<int64_t> message_id;
        std::optional<std::string> inline_message_id;
        std::shared_ptr<InlineKeyboardMarkup> reply_markup;
    };

    drogon::Task<std::variant<std::shared_ptr<Message>, bool>> stopMessageLiveLocation(std::optional<std::string> business_connection_id = std::nullopt,
                                                                                       ChatId chat_id = {},
                                                                                       std::optional<int64_t> message_id = std::nullopt,
                                                                                       std::optional<std::string> inline_message_id = std::nullopt,
                                                                                       std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_id.has_value()) {
            payload["message_id"] = message_id.value();
        }
        if (inline_message_id.has_value()) {
            payload["inline_message_id"] = inline_message_id.value();
        }
        if (reply_markup) {
            json _sub;
            to_json(_sub, *reply_markup);
            payload["reply_markup"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/stopMessageLiveLocation", _body)
            : co_await request_->uploadFiles(token_ + "/stopMessageLiveLocation", _body, _uploads);
        co_return parse_response<std::variant<std::shared_ptr<Message>, bool>>(_resp).result.value();
    }

    drogon::Task<std::variant<std::shared_ptr<Message>, bool>> stopMessageLiveLocation(StopMessageLiveLocationArgs args) {
        co_return co_await stopMessageLiveLocation(std::move(args.business_connection_id),
            std::move(args.chat_id),
            std::move(args.message_id),
            std::move(args.inline_message_id),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to edit a checklist on behalf of a connected business account. On
     * success, the edited Message is returned.
     *
     * @param business_connection_id [required] Unique identifier of the business connection on behalf of which the message will be sent.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot in the format @username.
     * @param message_id [required] Unique identifier for the target message.
     * @param checklist [required] A JSON-serialized object for the new checklist.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#editmessagechecklist
     */
    struct EditMessageChecklistArgs {
        std::string business_connection_id{""};
        ChatId chat_id{};
        int64_t message_id{0};
        std::shared_ptr<InputChecklist> checklist;
        std::shared_ptr<InlineKeyboardMarkup> reply_markup;
    };

    drogon::Task<std::shared_ptr<Message>> editMessageChecklist(std::string business_connection_id,
                                                                ChatId chat_id,
                                                                int64_t message_id,
                                                                std::shared_ptr<InputChecklist> checklist,
                                                                std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["business_connection_id"] = business_connection_id;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["message_id"] = message_id;
        {
            json _sub;
            to_json(_sub, *checklist);
            payload["checklist"] = std::move(_sub);
        }
        if (reply_markup) {
            json _sub;
            to_json(_sub, *reply_markup);
            payload["reply_markup"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/editMessageChecklist", _body)
            : co_await request_->uploadFiles(token_ + "/editMessageChecklist", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> editMessageChecklist(EditMessageChecklistArgs args) {
        co_return co_await editMessageChecklist(std::move(args.business_connection_id),
            std::move(args.chat_id),
            std::move(args.message_id),
            std::move(args.checklist),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to edit only the reply markup of messages. On success, if the edited
     * message is not an inline message, the edited Message is returned, otherwise True is
     * returned. Note that business messages that were not sent by the bot and do not contain an
     * inline keyboard can only be edited within 48 hours from the time they were sent.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [optional] Optional.
     * @param message_id [optional] Optional.
     * @param inline_message_id [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::variant<std::shared_ptr<Message>, bool>
     * @see https://core.telegram.org/bots/api#editmessagereplymarkup
     */
    struct EditMessageReplyMarkupArgs {
        std::optional<std::string> business_connection_id;
        ChatId chat_id{};
        std::optional<int64_t> message_id;
        std::optional<std::string> inline_message_id;
        std::shared_ptr<InlineKeyboardMarkup> reply_markup;
    };

    drogon::Task<std::variant<std::shared_ptr<Message>, bool>> editMessageReplyMarkup(std::optional<std::string> business_connection_id = std::nullopt,
                                                                                      ChatId chat_id = {},
                                                                                      std::optional<int64_t> message_id = std::nullopt,
                                                                                      std::optional<std::string> inline_message_id = std::nullopt,
                                                                                      std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_id.has_value()) {
            payload["message_id"] = message_id.value();
        }
        if (inline_message_id.has_value()) {
            payload["inline_message_id"] = inline_message_id.value();
        }
        if (reply_markup) {
            json _sub;
            to_json(_sub, *reply_markup);
            payload["reply_markup"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/editMessageReplyMarkup", _body)
            : co_await request_->uploadFiles(token_ + "/editMessageReplyMarkup", _body, _uploads);
        co_return parse_response<std::variant<std::shared_ptr<Message>, bool>>(_resp).result.value();
    }

    drogon::Task<std::variant<std::shared_ptr<Message>, bool>> editMessageReplyMarkup(EditMessageReplyMarkupArgs args) {
        co_return co_await editMessageReplyMarkup(std::move(args.business_connection_id),
            std::move(args.chat_id),
            std::move(args.message_id),
            std::move(args.inline_message_id),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to stop a poll which was sent by the bot. On success, the stopped Poll is
     * returned.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_id [required] Identifier of the original message with the poll.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Poll>
     * @see https://core.telegram.org/bots/api#stoppoll
     */
    struct StopPollArgs {
        ChatId chat_id{};
        int64_t message_id{0};
        std::optional<std::string> business_connection_id;
        std::shared_ptr<InlineKeyboardMarkup> reply_markup;
    };

    drogon::Task<std::shared_ptr<Poll>> stopPoll(ChatId chat_id,
                                                 int64_t message_id,
                                                 std::optional<std::string> business_connection_id = std::nullopt,
                                                 std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["message_id"] = message_id;
        if (reply_markup) {
            json _sub;
            to_json(_sub, *reply_markup);
            payload["reply_markup"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/stopPoll", _body)
            : co_await request_->uploadFiles(token_ + "/stopPoll", _body, _uploads);
        co_return parse_response<std::shared_ptr<Poll>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Poll>> stopPoll(StopPollArgs args) {
        co_return co_await stopPoll(std::move(args.chat_id),
            std::move(args.message_id),
            std::move(args.business_connection_id),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to approve a suggested post in a direct messages chat. The bot must have
     * the 'can_post_messages' administrator right in the corresponding channel chat. Returns
     * True on success.
     *
     * @param chat_id [required] Unique identifier for the target direct messages chat.
     * @param message_id [required] Identifier of a suggested post message to approve.
     * @param send_date [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#approvesuggestedpost
     */
    struct ApproveSuggestedPostArgs {
        int64_t chat_id{0};
        int64_t message_id{0};
        std::optional<int64_t> send_date;
    };

    drogon::Task<bool> approveSuggestedPost(int64_t chat_id,
                                            int64_t message_id,
                                            std::optional<int64_t> send_date = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["chat_id"] = chat_id;
        payload["message_id"] = message_id;
        if (send_date.has_value()) {
            payload["send_date"] = send_date.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/approveSuggestedPost", _body)
            : co_await request_->uploadFiles(token_ + "/approveSuggestedPost", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> approveSuggestedPost(ApproveSuggestedPostArgs args) {
        co_return co_await approveSuggestedPost(std::move(args.chat_id),
            std::move(args.message_id),
            std::move(args.send_date));
    }

    /**
     * Use this method to decline a suggested post in a direct messages chat. The bot must have
     * the 'can_manage_direct_messages' administrator right in the corresponding channel chat.
     * Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target direct messages chat.
     * @param message_id [required] Identifier of a suggested post message to decline.
     * @param comment [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#declinesuggestedpost
     */
    struct DeclineSuggestedPostArgs {
        int64_t chat_id{0};
        int64_t message_id{0};
        std::optional<std::string> comment;
    };

    drogon::Task<bool> declineSuggestedPost(int64_t chat_id,
                                            int64_t message_id,
                                            std::optional<std::string> comment = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["chat_id"] = chat_id;
        payload["message_id"] = message_id;
        if (comment.has_value()) {
            payload["comment"] = comment.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/declineSuggestedPost", _body)
            : co_await request_->uploadFiles(token_ + "/declineSuggestedPost", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> declineSuggestedPost(DeclineSuggestedPostArgs args) {
        co_return co_await declineSuggestedPost(std::move(args.chat_id),
            std::move(args.message_id),
            std::move(args.comment));
    }

    /**
     * Use this method to delete a message, including service messages, with the following
     * limitations:
     * - A message can only be deleted if it was sent less than 48 hours ago.
     * - Service messages about a supergroup, channel, or forum topic creation can't be deleted.
     * - A dice message in a private chat can only be deleted if it was sent more than 24 hours
     * ago.
     * - Bots can delete outgoing messages in private chats, groups, and supergroups.
     * - Bots can delete incoming messages in private chats.
     * - Bots granted can_post_messages permissions can delete outgoing messages in channels.
     * - If the bot is an administrator of a group, it can delete any message there.
     * - If the bot has can_delete_messages administrator right in a supergroup or a channel, it
     * can delete any message there.
     * - If the bot has can_manage_direct_messages administrator right in a channel, it can
     * delete any message in the corresponding direct messages chat.
     * Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_id [required] Identifier of the message to delete.
     * @returns bool
     * @see https://core.telegram.org/bots/api#deletemessage
     */
    struct DeleteMessageArgs {
        ChatId chat_id{};
        int64_t message_id{0};
    };

    drogon::Task<bool> deleteMessage(ChatId chat_id,
                                     int64_t message_id) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["message_id"] = message_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/deleteMessage", _body)
            : co_await request_->uploadFiles(token_ + "/deleteMessage", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> deleteMessage(DeleteMessageArgs args) {
        co_return co_await deleteMessage(std::move(args.chat_id),
            std::move(args.message_id));
    }

    /**
     * Use this method to delete multiple messages simultaneously. If some of the specified
     * messages can't be found, they are skipped. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_ids [required] A JSON-serialized list of 1-100 identifiers of messages to delete.
     * @returns bool
     * @see https://core.telegram.org/bots/api#deletemessages
     */
    struct DeleteMessagesArgs {
        ChatId chat_id{};
        std::vector<int64_t> message_ids;
    };

    drogon::Task<bool> deleteMessages(ChatId chat_id,
                                      std::vector<int64_t> message_ids) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        {
            json _arr = json::array();
            for (const auto& _item : message_ids) {
                _arr.push_back(_item);
            }
            payload["message_ids"] = std::move(_arr);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/deleteMessages", _body)
            : co_await request_->uploadFiles(token_ + "/deleteMessages", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> deleteMessages(DeleteMessagesArgs args) {
        co_return co_await deleteMessages(std::move(args.chat_id),
            std::move(args.message_ids));
    }

    /**
     * Use this method to remove a reaction from a message in a group or a supergroup chat. The
     * bot must have the 'can_delete_messages' administrator right in the chat. Returns True on
     * success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup (in the format @username .
     * @param message_id [required] Identifier of the target message.
     * @param user_id [optional] Optional.
     * @param actor_chat_id [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#deletemessagereaction
     */
    struct DeleteMessageReactionArgs {
        ChatId chat_id{};
        int64_t message_id{0};
        std::optional<int64_t> user_id;
        std::optional<int64_t> actor_chat_id;
    };

    drogon::Task<bool> deleteMessageReaction(ChatId chat_id,
                                             int64_t message_id,
                                             std::optional<int64_t> user_id = std::nullopt,
                                             std::optional<int64_t> actor_chat_id = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        payload["message_id"] = message_id;
        if (user_id.has_value()) {
            payload["user_id"] = user_id.value();
        }
        if (actor_chat_id.has_value()) {
            payload["actor_chat_id"] = actor_chat_id.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/deleteMessageReaction", _body)
            : co_await request_->uploadFiles(token_ + "/deleteMessageReaction", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> deleteMessageReaction(DeleteMessageReactionArgs args) {
        co_return co_await deleteMessageReaction(std::move(args.chat_id),
            std::move(args.message_id),
            std::move(args.user_id),
            std::move(args.actor_chat_id));
    }

    /**
     * Use this method to remove up to 10000 recent reactions in a group or a supergroup chat
     * added by a given user or chat. The bot must have the 'can_delete_messages' administrator
     * right in the chat. Returns True on success.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target supergroup (in the format @username .
     * @param user_id [optional] Optional.
     * @param actor_chat_id [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#deleteallmessagereactions
     */
    struct DeleteAllMessageReactionsArgs {
        ChatId chat_id{};
        std::optional<int64_t> user_id;
        std::optional<int64_t> actor_chat_id;
    };

    drogon::Task<bool> deleteAllMessageReactions(ChatId chat_id,
                                                 std::optional<int64_t> user_id = std::nullopt,
                                                 std::optional<int64_t> actor_chat_id = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (user_id.has_value()) {
            payload["user_id"] = user_id.value();
        }
        if (actor_chat_id.has_value()) {
            payload["actor_chat_id"] = actor_chat_id.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/deleteAllMessageReactions", _body)
            : co_await request_->uploadFiles(token_ + "/deleteAllMessageReactions", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> deleteAllMessageReactions(DeleteAllMessageReactionsArgs args) {
        co_return co_await deleteAllMessageReactions(std::move(args.chat_id),
            std::move(args.user_id),
            std::move(args.actor_chat_id));
    }

    // ── Stickers ──────────────────────────────────────────────────────────────

    /**
     * Use this method to send static .WEBP, animated .TGS, or video .WEBM stickers. On success,
     * the sent Message is returned.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param sticker [required] Sticker to send.
     * @param emoji [optional] Optional.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param suggested_post_parameters [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#sendsticker
     */
    struct SendStickerArgs {
        ChatId chat_id{};
        std::variant<std::shared_ptr<InputFile>, std::string> sticker{};
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<std::string> emoji;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters;
        std::shared_ptr<ReplyParameters> reply_parameters;
        ReplyMarkup reply_markup{};
    };

    drogon::Task<std::shared_ptr<Message>> sendSticker(ChatId chat_id,
                                                       std::variant<std::shared_ptr<InputFile>, std::string> sticker,
                                                       std::optional<std::string> business_connection_id = std::nullopt,
                                                       std::optional<int64_t> message_thread_id = std::nullopt,
                                                       std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                       std::optional<std::string> emoji = std::nullopt,
                                                       std::optional<bool> disable_notification = std::nullopt,
                                                       std::optional<bool> protect_content = std::nullopt,
                                                       std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                       std::optional<std::string> message_effect_id = std::nullopt,
                                                       std::shared_ptr<SuggestedPostParameters> suggested_post_parameters = nullptr,
                                                       std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                       ReplyMarkup reply_markup = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        if (auto* _p = std::get_if<std::shared_ptr<InputFile>>(&sticker)) {
            if (*_p) {
                payload["sticker"] = "attach://" + (*_p)->filename;
                _uploads.push_back({"sticker", *_p});
            }
        }
        if (auto* _p = std::get_if<std::string>(&sticker)) {
            payload["sticker"] = *_p;
        }
        if (emoji.has_value()) {
            payload["emoji"] = emoji.value();
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (suggested_post_parameters) {
            json _sub;
            to_json(_sub, *suggested_post_parameters);
            payload["suggested_post_parameters"] = std::move(_sub);
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (auto* _p = std::get_if<std::shared_ptr<InlineKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardMarkup>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ReplyKeyboardRemove>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        if (auto* _p = std::get_if<std::shared_ptr<ForceReply>>(&reply_markup)) {
            if (*_p) { json _sub; to_json(_sub, **_p); payload["reply_markup"] = std::move(_sub); }
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendSticker", _body)
            : co_await request_->uploadFiles(token_ + "/sendSticker", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> sendSticker(SendStickerArgs args) {
        co_return co_await sendSticker(std::move(args.chat_id),
            std::move(args.sticker),
            std::move(args.business_connection_id),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.emoji),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.message_effect_id),
            std::move(args.suggested_post_parameters),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to get a sticker set. On success, a StickerSet object is returned.
     *
     * @param name [required] Name of the sticker set.
     * @returns std::shared_ptr<StickerSet>
     * @see https://core.telegram.org/bots/api#getstickerset
     */
    struct GetStickerSetArgs {
        std::string name{""};
    };

    drogon::Task<std::shared_ptr<StickerSet>> getStickerSet(std::string name) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["name"] = name;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getStickerSet", _body)
            : co_await request_->uploadFiles(token_ + "/getStickerSet", _body, _uploads);
        co_return parse_response<std::shared_ptr<StickerSet>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<StickerSet>> getStickerSet(GetStickerSetArgs args) {
        co_return co_await getStickerSet(std::move(args.name));
    }

    /**
     * Use this method to get information about custom emoji stickers by their identifiers.
     * Returns an Array of Sticker objects.
     *
     * @param custom_emoji_ids [required] A JSON-serialized list of custom emoji identifiers.
     * @returns std::vector<std::shared_ptr<Sticker>>
     * @see https://core.telegram.org/bots/api#getcustomemojistickers
     */
    struct GetCustomEmojiStickersArgs {
        std::vector<std::string> custom_emoji_ids;
    };

    drogon::Task<std::vector<std::shared_ptr<Sticker>>> getCustomEmojiStickers(std::vector<std::string> custom_emoji_ids) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        {
            json _arr = json::array();
            for (const auto& _item : custom_emoji_ids) {
                _arr.push_back(_item);
            }
            payload["custom_emoji_ids"] = std::move(_arr);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getCustomEmojiStickers", _body)
            : co_await request_->uploadFiles(token_ + "/getCustomEmojiStickers", _body, _uploads);
        co_return parse_response<std::vector<std::shared_ptr<Sticker>>>(_resp).result.value();
    }

    drogon::Task<std::vector<std::shared_ptr<Sticker>>> getCustomEmojiStickers(GetCustomEmojiStickersArgs args) {
        co_return co_await getCustomEmojiStickers(std::move(args.custom_emoji_ids));
    }

    /**
     * Use this method to upload a file with a sticker for later use in the createNewStickerSet,
     * addStickerToSet, or replaceStickerInSet methods (the file can be used multiple times).
     * Returns the uploaded File on success.
     *
     * @param user_id [required] User identifier of sticker file owner.
     * @param sticker [required] A file with the sticker in .
     * @param sticker_format [required] Format of the sticker, must be one of 'static', 'animated', 'video'.
     * @returns std::shared_ptr<File>
     * @see https://core.telegram.org/bots/api#uploadstickerfile
     */
    struct UploadStickerFileArgs {
        int64_t user_id{0};
        std::shared_ptr<InputFile> sticker;
        std::string sticker_format{""};
    };

    drogon::Task<std::shared_ptr<File>> uploadStickerFile(int64_t user_id,
                                                          std::shared_ptr<InputFile> sticker,
                                                          std::string sticker_format) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        if (sticker) {
            payload["sticker"] = "attach://" + sticker->filename;
            _uploads.push_back({"sticker", sticker});
        }
        payload["sticker_format"] = sticker_format;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/uploadStickerFile", _body)
            : co_await request_->uploadFiles(token_ + "/uploadStickerFile", _body, _uploads);
        co_return parse_response<std::shared_ptr<File>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<File>> uploadStickerFile(UploadStickerFileArgs args) {
        co_return co_await uploadStickerFile(std::move(args.user_id),
            std::move(args.sticker),
            std::move(args.sticker_format));
    }

    /**
     * Use this method to create a new sticker set owned by a user. The bot will be able to edit
     * the sticker set thus created. Returns True on success.
     *
     * @param user_id [required] User identifier of created sticker set owner.
     * @param name [required] Short name of sticker set, to be used in t.
     * @param title [required] Sticker set title, 1-64 characters.
     * @param stickers [required] A JSON-serialized list of 1-50 initial stickers to be added to the sticker set.
     * @param sticker_type [optional] Optional.
     * @param needs_repainting [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#createnewstickerset
     */
    struct CreateNewStickerSetArgs {
        int64_t user_id{0};
        std::string name{""};
        std::string title{""};
        std::vector<std::shared_ptr<InputSticker>> stickers;
        std::optional<std::string> sticker_type;
        std::optional<bool> needs_repainting;
    };

    drogon::Task<bool> createNewStickerSet(int64_t user_id,
                                           std::string name,
                                           std::string title,
                                           std::vector<std::shared_ptr<InputSticker>> stickers,
                                           std::optional<std::string> sticker_type = std::nullopt,
                                           std::optional<bool> needs_repainting = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        payload["name"] = name;
        payload["title"] = title;
        {
            json _arr = json::array();
            for (const auto& _item : stickers) {
                {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["stickers"] = std::move(_arr);
        }
        if (sticker_type.has_value()) {
            payload["sticker_type"] = sticker_type.value();
        }
        if (needs_repainting.has_value()) {
            payload["needs_repainting"] = needs_repainting.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/createNewStickerSet", _body)
            : co_await request_->uploadFiles(token_ + "/createNewStickerSet", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> createNewStickerSet(CreateNewStickerSetArgs args) {
        co_return co_await createNewStickerSet(std::move(args.user_id),
            std::move(args.name),
            std::move(args.title),
            std::move(args.stickers),
            std::move(args.sticker_type),
            std::move(args.needs_repainting));
    }

    /**
     * Use this method to add a new sticker to a set created by the bot. Emoji sticker sets can
     * have up to 200 stickers. Other sticker sets can have up to 120 stickers. Returns True on
     * success.
     *
     * @param user_id [required] User identifier of sticker set owner.
     * @param name [required] Sticker set name.
     * @param sticker [required] A JSON-serialized object with information about the added sticker.
     * @returns bool
     * @see https://core.telegram.org/bots/api#addstickertoset
     */
    struct AddStickerToSetArgs {
        int64_t user_id{0};
        std::string name{""};
        std::shared_ptr<InputSticker> sticker;
    };

    drogon::Task<bool> addStickerToSet(int64_t user_id,
                                       std::string name,
                                       std::shared_ptr<InputSticker> sticker) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        payload["name"] = name;
        {
            json _sub;
            to_json(_sub, *sticker);
            payload["sticker"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/addStickerToSet", _body)
            : co_await request_->uploadFiles(token_ + "/addStickerToSet", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> addStickerToSet(AddStickerToSetArgs args) {
        co_return co_await addStickerToSet(std::move(args.user_id),
            std::move(args.name),
            std::move(args.sticker));
    }

    /**
     * Use this method to move a sticker in a set created by the bot to a specific position.
     * Returns True on success.
     *
     * @param sticker [required] File identifier of the sticker.
     * @param position [required] New sticker position in the set, zero-based.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setstickerpositioninset
     */
    struct SetStickerPositionInSetArgs {
        std::string sticker{""};
        int64_t position{0};
    };

    drogon::Task<bool> setStickerPositionInSet(std::string sticker,
                                               int64_t position) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["sticker"] = sticker;
        payload["position"] = position;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setStickerPositionInSet", _body)
            : co_await request_->uploadFiles(token_ + "/setStickerPositionInSet", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setStickerPositionInSet(SetStickerPositionInSetArgs args) {
        co_return co_await setStickerPositionInSet(std::move(args.sticker),
            std::move(args.position));
    }

    /**
     * Use this method to delete a sticker from a set created by the bot. Returns True on
     * success.
     *
     * @param sticker [required] File identifier of the sticker.
     * @returns bool
     * @see https://core.telegram.org/bots/api#deletestickerfromset
     */
    struct DeleteStickerFromSetArgs {
        std::string sticker{""};
    };

    drogon::Task<bool> deleteStickerFromSet(std::string sticker) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["sticker"] = sticker;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/deleteStickerFromSet", _body)
            : co_await request_->uploadFiles(token_ + "/deleteStickerFromSet", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> deleteStickerFromSet(DeleteStickerFromSetArgs args) {
        co_return co_await deleteStickerFromSet(std::move(args.sticker));
    }

    /**
     * Use this method to replace an existing sticker in a sticker set with a new one. The
     * method is equivalent to calling deleteStickerFromSet, then addStickerToSet, then
     * setStickerPositionInSet. Returns True on success.
     *
     * @param user_id [required] User identifier of the sticker set owner.
     * @param name [required] Sticker set name.
     * @param old_sticker [required] File identifier of the replaced sticker.
     * @param sticker [required] A JSON-serialized object with information about the added sticker.
     * @returns bool
     * @see https://core.telegram.org/bots/api#replacestickerinset
     */
    struct ReplaceStickerInSetArgs {
        int64_t user_id{0};
        std::string name{""};
        std::string old_sticker{""};
        std::shared_ptr<InputSticker> sticker;
    };

    drogon::Task<bool> replaceStickerInSet(int64_t user_id,
                                           std::string name,
                                           std::string old_sticker,
                                           std::shared_ptr<InputSticker> sticker) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        payload["name"] = name;
        payload["old_sticker"] = old_sticker;
        {
            json _sub;
            to_json(_sub, *sticker);
            payload["sticker"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/replaceStickerInSet", _body)
            : co_await request_->uploadFiles(token_ + "/replaceStickerInSet", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> replaceStickerInSet(ReplaceStickerInSetArgs args) {
        co_return co_await replaceStickerInSet(std::move(args.user_id),
            std::move(args.name),
            std::move(args.old_sticker),
            std::move(args.sticker));
    }

    /**
     * Use this method to change the list of emoji assigned to a regular or custom emoji
     * sticker. The sticker must belong to a sticker set created by the bot. Returns True on
     * success.
     *
     * @param sticker [required] File identifier of the sticker.
     * @param emoji_list [required] A JSON-serialized list of 1-20 emoji associated with the sticker.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setstickeremojilist
     */
    struct SetStickerEmojiListArgs {
        std::string sticker{""};
        std::vector<std::string> emoji_list;
    };

    drogon::Task<bool> setStickerEmojiList(std::string sticker,
                                           std::vector<std::string> emoji_list) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["sticker"] = sticker;
        {
            json _arr = json::array();
            for (const auto& _item : emoji_list) {
                _arr.push_back(_item);
            }
            payload["emoji_list"] = std::move(_arr);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setStickerEmojiList", _body)
            : co_await request_->uploadFiles(token_ + "/setStickerEmojiList", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setStickerEmojiList(SetStickerEmojiListArgs args) {
        co_return co_await setStickerEmojiList(std::move(args.sticker),
            std::move(args.emoji_list));
    }

    /**
     * Use this method to change search keywords assigned to a regular or custom emoji sticker.
     * The sticker must belong to a sticker set created by the bot. Returns True on success.
     *
     * @param sticker [required] File identifier of the sticker.
     * @param keywords [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setstickerkeywords
     */
    struct SetStickerKeywordsArgs {
        std::string sticker{""};
        std::vector<std::string> keywords;
    };

    drogon::Task<bool> setStickerKeywords(std::string sticker,
                                          std::vector<std::string> keywords = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["sticker"] = sticker;
        if (!keywords.empty()) {
            json _arr = json::array();
            for (const auto& _item : keywords) {
                _arr.push_back(_item);
            }
            payload["keywords"] = std::move(_arr);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setStickerKeywords", _body)
            : co_await request_->uploadFiles(token_ + "/setStickerKeywords", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setStickerKeywords(SetStickerKeywordsArgs args) {
        co_return co_await setStickerKeywords(std::move(args.sticker),
            std::move(args.keywords));
    }

    /**
     * Use this method to change the mask position of a mask sticker. The sticker must belong to
     * a sticker set that was created by the bot. Returns True on success.
     *
     * @param sticker [required] File identifier of the sticker.
     * @param mask_position [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setstickermaskposition
     */
    struct SetStickerMaskPositionArgs {
        std::string sticker{""};
        std::shared_ptr<MaskPosition> mask_position;
    };

    drogon::Task<bool> setStickerMaskPosition(std::string sticker,
                                              std::shared_ptr<MaskPosition> mask_position = nullptr) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["sticker"] = sticker;
        if (mask_position) {
            json _sub;
            to_json(_sub, *mask_position);
            payload["mask_position"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setStickerMaskPosition", _body)
            : co_await request_->uploadFiles(token_ + "/setStickerMaskPosition", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setStickerMaskPosition(SetStickerMaskPositionArgs args) {
        co_return co_await setStickerMaskPosition(std::move(args.sticker),
            std::move(args.mask_position));
    }

    /**
     * Use this method to set the title of a created sticker set. Returns True on success.
     *
     * @param name [required] Sticker set name.
     * @param title [required] Sticker set title, 1-64 characters.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setstickersettitle
     */
    struct SetStickerSetTitleArgs {
        std::string name{""};
        std::string title{""};
    };

    drogon::Task<bool> setStickerSetTitle(std::string name,
                                          std::string title) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["name"] = name;
        payload["title"] = title;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setStickerSetTitle", _body)
            : co_await request_->uploadFiles(token_ + "/setStickerSetTitle", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setStickerSetTitle(SetStickerSetTitleArgs args) {
        co_return co_await setStickerSetTitle(std::move(args.name),
            std::move(args.title));
    }

    /**
     * Use this method to set the thumbnail of a regular or mask sticker set. The format of the
     * thumbnail file must match the format of the stickers in the set. Returns True on success.
     *
     * @param name [required] Sticker set name.
     * @param user_id [required] User identifier of the sticker set owner.
     * @param thumbnail [optional] Optional.
     * @param format [required] Format of the thumbnail, must be one of 'static' for a .
     * @returns bool
     * @see https://core.telegram.org/bots/api#setstickersetthumbnail
     */
    struct SetStickerSetThumbnailArgs {
        std::string name{""};
        int64_t user_id{0};
        std::string format{""};
        std::variant<std::shared_ptr<InputFile>, std::string> thumbnail{};
    };

    drogon::Task<bool> setStickerSetThumbnail(std::string name,
                                              int64_t user_id,
                                              std::string format,
                                              std::variant<std::shared_ptr<InputFile>, std::string> thumbnail = {}) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["name"] = name;
        payload["user_id"] = user_id;
        if (auto* _p = std::get_if<std::shared_ptr<InputFile>>(&thumbnail)) {
            if (*_p) {
                payload["thumbnail"] = "attach://" + (*_p)->filename;
                _uploads.push_back({"thumbnail", *_p});
            }
        }
        if (auto* _p = std::get_if<std::string>(&thumbnail)) {
            payload["thumbnail"] = *_p;
        }
        payload["format"] = format;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setStickerSetThumbnail", _body)
            : co_await request_->uploadFiles(token_ + "/setStickerSetThumbnail", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setStickerSetThumbnail(SetStickerSetThumbnailArgs args) {
        co_return co_await setStickerSetThumbnail(std::move(args.name),
            std::move(args.user_id),
            std::move(args.format),
            std::move(args.thumbnail));
    }

    /**
     * Use this method to set the thumbnail of a custom emoji sticker set. Returns True on
     * success.
     *
     * @param name [required] Sticker set name.
     * @param custom_emoji_id [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setcustomemojistickersetthumbnail
     */
    struct SetCustomEmojiStickerSetThumbnailArgs {
        std::string name{""};
        std::optional<std::string> custom_emoji_id;
    };

    drogon::Task<bool> setCustomEmojiStickerSetThumbnail(std::string name,
                                                         std::optional<std::string> custom_emoji_id = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["name"] = name;
        if (custom_emoji_id.has_value()) {
            payload["custom_emoji_id"] = custom_emoji_id.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setCustomEmojiStickerSetThumbnail", _body)
            : co_await request_->uploadFiles(token_ + "/setCustomEmojiStickerSetThumbnail", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setCustomEmojiStickerSetThumbnail(SetCustomEmojiStickerSetThumbnailArgs args) {
        co_return co_await setCustomEmojiStickerSetThumbnail(std::move(args.name),
            std::move(args.custom_emoji_id));
    }

    /**
     * Use this method to delete a sticker set that was created by the bot. Returns True on
     * success.
     *
     * @param name [required] Sticker set name.
     * @returns bool
     * @see https://core.telegram.org/bots/api#deletestickerset
     */
    struct DeleteStickerSetArgs {
        std::string name{""};
    };

    drogon::Task<bool> deleteStickerSet(std::string name) const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["name"] = name;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/deleteStickerSet", _body)
            : co_await request_->uploadFiles(token_ + "/deleteStickerSet", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> deleteStickerSet(DeleteStickerSetArgs args) {
        co_return co_await deleteStickerSet(std::move(args.name));
    }

    // ── Inline mode ───────────────────────────────────────────────────────────

    /**
     * Use this method to send answers to an inline query. On success, True is returned.
     * No more than 50 results per query are allowed.
     *
     * @param inline_query_id [required] Unique identifier for the answered query.
     * @param results [required] A JSON-serialized array of results for the inline query.
     * @param cache_time [optional] Optional.
     * @param is_personal [optional] Optional.
     * @param next_offset [optional] Optional.
     * @param button [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#answerinlinequery
     */
    struct AnswerInlineQueryArgs {
        std::string inline_query_id{""};
        std::vector<InlineQueryResult> results;
        std::optional<int64_t> cache_time;
        std::optional<bool> is_personal;
        std::optional<std::string> next_offset;
        std::shared_ptr<InlineQueryResultsButton> button;
    };

    drogon::Task<bool> answerInlineQuery(std::string inline_query_id,
                                         std::vector<InlineQueryResult> results,
                                         std::optional<int64_t> cache_time = std::nullopt,
                                         std::optional<bool> is_personal = std::nullopt,
                                         std::optional<std::string> next_offset = std::nullopt,
                                         std::shared_ptr<InlineQueryResultsButton> button = nullptr) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["inline_query_id"] = inline_query_id;
        {
            json _arr = json::array();
            for (const auto& _item : results) {
                {
                    json _e; to_json(_e, _item); _arr.push_back(std::move(_e));
                }
            }
            payload["results"] = std::move(_arr);
        }
        if (cache_time.has_value()) {
            payload["cache_time"] = cache_time.value();
        }
        if (is_personal.has_value()) {
            payload["is_personal"] = is_personal.value();
        }
        if (next_offset.has_value()) {
            payload["next_offset"] = next_offset.value();
        }
        if (button) {
            json _sub;
            to_json(_sub, *button);
            payload["button"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/answerInlineQuery", _body)
            : co_await request_->uploadFiles(token_ + "/answerInlineQuery", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> answerInlineQuery(AnswerInlineQueryArgs args) {
        co_return co_await answerInlineQuery(std::move(args.inline_query_id),
            std::move(args.results),
            std::move(args.cache_time),
            std::move(args.is_personal),
            std::move(args.next_offset),
            std::move(args.button));
    }

    // ── Payments ──────────────────────────────────────────────────────────────

    /**
     * Use this method to send invoices. On success, the sent Message is returned.
     *
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot, supergroup or channel in the fo.
     * @param message_thread_id [optional] Optional.
     * @param direct_messages_topic_id [optional] Optional.
     * @param title [required] Product name, 1-32 characters.
     * @param description [required] Product description, 1-255 characters.
     * @param payload [required] Bot-defined invoice payload, 1-128 bytes.
     * @param provider_token [optional] Optional.
     * @param currency [required] Three-letter ISO 4217 currency code, see more on currencies .
     * @param prices [required] Price breakdown, a JSON-serialized list of components (e.
     * @param max_tip_amount [optional] Optional.
     * @param suggested_tip_amounts [optional] Optional.
     * @param start_parameter [optional] Optional.
     * @param provider_data [optional] Optional.
     * @param photo_url [optional] Optional.
     * @param photo_size [optional] Optional.
     * @param photo_width [optional] Optional.
     * @param photo_height [optional] Optional.
     * @param need_name [optional] Optional.
     * @param need_phone_number [optional] Optional.
     * @param need_email [optional] Optional.
     * @param need_shipping_address [optional] Optional.
     * @param send_phone_number_to_provider [optional] Optional.
     * @param send_email_to_provider [optional] Optional.
     * @param is_flexible [optional] Optional.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param suggested_post_parameters [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#sendinvoice
     */
    struct SendInvoiceArgs {
        ChatId chat_id{};
        std::string title{""};
        std::string description{""};
        std::string invoice_payload{""};
        std::string currency{""};
        std::vector<std::shared_ptr<LabeledPrice>> prices;
        std::optional<int64_t> message_thread_id;
        std::optional<int64_t> direct_messages_topic_id;
        std::optional<std::string> provider_token;
        std::optional<int64_t> max_tip_amount;
        std::vector<int64_t> suggested_tip_amounts;
        std::optional<std::string> start_parameter;
        std::optional<std::string> provider_data;
        std::optional<std::string> photo_url;
        std::optional<int64_t> photo_size;
        std::optional<int64_t> photo_width;
        std::optional<int64_t> photo_height;
        std::optional<bool> need_name;
        std::optional<bool> need_phone_number;
        std::optional<bool> need_email;
        std::optional<bool> need_shipping_address;
        std::optional<bool> send_phone_number_to_provider;
        std::optional<bool> send_email_to_provider;
        std::optional<bool> is_flexible;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<SuggestedPostParameters> suggested_post_parameters;
        std::shared_ptr<ReplyParameters> reply_parameters;
        std::shared_ptr<InlineKeyboardMarkup> reply_markup;
    };

    drogon::Task<std::shared_ptr<Message>> sendInvoice(ChatId chat_id,
                                                       std::string title,
                                                       std::string description,
                                                       std::string invoice_payload,
                                                       std::string currency,
                                                       std::vector<std::shared_ptr<LabeledPrice>> prices,
                                                       std::optional<int64_t> message_thread_id = std::nullopt,
                                                       std::optional<int64_t> direct_messages_topic_id = std::nullopt,
                                                       std::optional<std::string> provider_token = std::nullopt,
                                                       std::optional<int64_t> max_tip_amount = std::nullopt,
                                                       std::vector<int64_t> suggested_tip_amounts = {},
                                                       std::optional<std::string> start_parameter = std::nullopt,
                                                       std::optional<std::string> provider_data = std::nullopt,
                                                       std::optional<std::string> photo_url = std::nullopt,
                                                       std::optional<int64_t> photo_size = std::nullopt,
                                                       std::optional<int64_t> photo_width = std::nullopt,
                                                       std::optional<int64_t> photo_height = std::nullopt,
                                                       std::optional<bool> need_name = std::nullopt,
                                                       std::optional<bool> need_phone_number = std::nullopt,
                                                       std::optional<bool> need_email = std::nullopt,
                                                       std::optional<bool> need_shipping_address = std::nullopt,
                                                       std::optional<bool> send_phone_number_to_provider = std::nullopt,
                                                       std::optional<bool> send_email_to_provider = std::nullopt,
                                                       std::optional<bool> is_flexible = std::nullopt,
                                                       std::optional<bool> disable_notification = std::nullopt,
                                                       std::optional<bool> protect_content = std::nullopt,
                                                       std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                       std::optional<std::string> message_effect_id = std::nullopt,
                                                       std::shared_ptr<SuggestedPostParameters> suggested_post_parameters = nullptr,
                                                       std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                       std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        if (direct_messages_topic_id.has_value()) {
            payload["direct_messages_topic_id"] = direct_messages_topic_id.value();
        }
        payload["title"] = title;
        payload["description"] = description;
        payload["payload"] = invoice_payload;
        if (provider_token.has_value()) {
            payload["provider_token"] = provider_token.value();
        }
        payload["currency"] = currency;
        {
            json _arr = json::array();
            for (const auto& _item : prices) {
                {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["prices"] = std::move(_arr);
        }
        if (max_tip_amount.has_value()) {
            payload["max_tip_amount"] = max_tip_amount.value();
        }
        if (!suggested_tip_amounts.empty()) {
            json _arr = json::array();
            for (const auto& _item : suggested_tip_amounts) {
                _arr.push_back(_item);
            }
            payload["suggested_tip_amounts"] = std::move(_arr);
        }
        if (start_parameter.has_value()) {
            payload["start_parameter"] = start_parameter.value();
        }
        if (provider_data.has_value()) {
            payload["provider_data"] = provider_data.value();
        }
        if (photo_url.has_value()) {
            payload["photo_url"] = photo_url.value();
        }
        if (photo_size.has_value()) {
            payload["photo_size"] = photo_size.value();
        }
        if (photo_width.has_value()) {
            payload["photo_width"] = photo_width.value();
        }
        if (photo_height.has_value()) {
            payload["photo_height"] = photo_height.value();
        }
        if (need_name.has_value()) {
            payload["need_name"] = need_name.value();
        }
        if (need_phone_number.has_value()) {
            payload["need_phone_number"] = need_phone_number.value();
        }
        if (need_email.has_value()) {
            payload["need_email"] = need_email.value();
        }
        if (need_shipping_address.has_value()) {
            payload["need_shipping_address"] = need_shipping_address.value();
        }
        if (send_phone_number_to_provider.has_value()) {
            payload["send_phone_number_to_provider"] = send_phone_number_to_provider.value();
        }
        if (send_email_to_provider.has_value()) {
            payload["send_email_to_provider"] = send_email_to_provider.value();
        }
        if (is_flexible.has_value()) {
            payload["is_flexible"] = is_flexible.value();
        }
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (suggested_post_parameters) {
            json _sub;
            to_json(_sub, *suggested_post_parameters);
            payload["suggested_post_parameters"] = std::move(_sub);
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (reply_markup) {
            json _sub;
            to_json(_sub, *reply_markup);
            payload["reply_markup"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendInvoice", _body)
            : co_await request_->uploadFiles(token_ + "/sendInvoice", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> sendInvoice(SendInvoiceArgs args) {
        co_return co_await sendInvoice(std::move(args.chat_id),
            std::move(args.title),
            std::move(args.description),
            std::move(args.invoice_payload),
            std::move(args.currency),
            std::move(args.prices),
            std::move(args.message_thread_id),
            std::move(args.direct_messages_topic_id),
            std::move(args.provider_token),
            std::move(args.max_tip_amount),
            std::move(args.suggested_tip_amounts),
            std::move(args.start_parameter),
            std::move(args.provider_data),
            std::move(args.photo_url),
            std::move(args.photo_size),
            std::move(args.photo_width),
            std::move(args.photo_height),
            std::move(args.need_name),
            std::move(args.need_phone_number),
            std::move(args.need_email),
            std::move(args.need_shipping_address),
            std::move(args.send_phone_number_to_provider),
            std::move(args.send_email_to_provider),
            std::move(args.is_flexible),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.message_effect_id),
            std::move(args.suggested_post_parameters),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to create a link for an invoice. Returns the created invoice link as
     * String on success.
     *
     * @param business_connection_id [optional] Optional.
     * @param title [required] Product name, 1-32 characters.
     * @param description [required] Product description, 1-255 characters.
     * @param payload [required] Bot-defined invoice payload, 1-128 bytes.
     * @param provider_token [optional] Optional.
     * @param currency [required] Three-letter ISO 4217 currency code, see more on currencies .
     * @param prices [required] Price breakdown, a JSON-serialized list of components (e.
     * @param subscription_period [optional] Optional.
     * @param max_tip_amount [optional] Optional.
     * @param suggested_tip_amounts [optional] Optional.
     * @param provider_data [optional] Optional.
     * @param photo_url [optional] Optional.
     * @param photo_size [optional] Optional.
     * @param photo_width [optional] Optional.
     * @param photo_height [optional] Optional.
     * @param need_name [optional] Optional.
     * @param need_phone_number [optional] Optional.
     * @param need_email [optional] Optional.
     * @param need_shipping_address [optional] Optional.
     * @param send_phone_number_to_provider [optional] Optional.
     * @param send_email_to_provider [optional] Optional.
     * @param is_flexible [optional] Optional.
     * @returns std::string
     * @see https://core.telegram.org/bots/api#createinvoicelink
     */
    struct CreateInvoiceLinkArgs {
        std::string title{""};
        std::string description{""};
        std::string invoice_payload{""};
        std::string currency{""};
        std::vector<std::shared_ptr<LabeledPrice>> prices;
        std::optional<std::string> business_connection_id;
        std::optional<std::string> provider_token;
        std::optional<int64_t> subscription_period;
        std::optional<int64_t> max_tip_amount;
        std::vector<int64_t> suggested_tip_amounts;
        std::optional<std::string> provider_data;
        std::optional<std::string> photo_url;
        std::optional<int64_t> photo_size;
        std::optional<int64_t> photo_width;
        std::optional<int64_t> photo_height;
        std::optional<bool> need_name;
        std::optional<bool> need_phone_number;
        std::optional<bool> need_email;
        std::optional<bool> need_shipping_address;
        std::optional<bool> send_phone_number_to_provider;
        std::optional<bool> send_email_to_provider;
        std::optional<bool> is_flexible;
    };

    drogon::Task<std::string> createInvoiceLink(std::string title,
                                                std::string description,
                                                std::string invoice_payload,
                                                std::string currency,
                                                std::vector<std::shared_ptr<LabeledPrice>> prices,
                                                std::optional<std::string> business_connection_id = std::nullopt,
                                                std::optional<std::string> provider_token = std::nullopt,
                                                std::optional<int64_t> subscription_period = std::nullopt,
                                                std::optional<int64_t> max_tip_amount = std::nullopt,
                                                std::vector<int64_t> suggested_tip_amounts = {},
                                                std::optional<std::string> provider_data = std::nullopt,
                                                std::optional<std::string> photo_url = std::nullopt,
                                                std::optional<int64_t> photo_size = std::nullopt,
                                                std::optional<int64_t> photo_width = std::nullopt,
                                                std::optional<int64_t> photo_height = std::nullopt,
                                                std::optional<bool> need_name = std::nullopt,
                                                std::optional<bool> need_phone_number = std::nullopt,
                                                std::optional<bool> need_email = std::nullopt,
                                                std::optional<bool> need_shipping_address = std::nullopt,
                                                std::optional<bool> send_phone_number_to_provider = std::nullopt,
                                                std::optional<bool> send_email_to_provider = std::nullopt,
                                                std::optional<bool> is_flexible = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        payload["title"] = title;
        payload["description"] = description;
        payload["payload"] = invoice_payload;
        if (provider_token.has_value()) {
            payload["provider_token"] = provider_token.value();
        }
        payload["currency"] = currency;
        {
            json _arr = json::array();
            for (const auto& _item : prices) {
                {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["prices"] = std::move(_arr);
        }
        if (subscription_period.has_value()) {
            payload["subscription_period"] = subscription_period.value();
        }
        if (max_tip_amount.has_value()) {
            payload["max_tip_amount"] = max_tip_amount.value();
        }
        if (!suggested_tip_amounts.empty()) {
            json _arr = json::array();
            for (const auto& _item : suggested_tip_amounts) {
                _arr.push_back(_item);
            }
            payload["suggested_tip_amounts"] = std::move(_arr);
        }
        if (provider_data.has_value()) {
            payload["provider_data"] = provider_data.value();
        }
        if (photo_url.has_value()) {
            payload["photo_url"] = photo_url.value();
        }
        if (photo_size.has_value()) {
            payload["photo_size"] = photo_size.value();
        }
        if (photo_width.has_value()) {
            payload["photo_width"] = photo_width.value();
        }
        if (photo_height.has_value()) {
            payload["photo_height"] = photo_height.value();
        }
        if (need_name.has_value()) {
            payload["need_name"] = need_name.value();
        }
        if (need_phone_number.has_value()) {
            payload["need_phone_number"] = need_phone_number.value();
        }
        if (need_email.has_value()) {
            payload["need_email"] = need_email.value();
        }
        if (need_shipping_address.has_value()) {
            payload["need_shipping_address"] = need_shipping_address.value();
        }
        if (send_phone_number_to_provider.has_value()) {
            payload["send_phone_number_to_provider"] = send_phone_number_to_provider.value();
        }
        if (send_email_to_provider.has_value()) {
            payload["send_email_to_provider"] = send_email_to_provider.value();
        }
        if (is_flexible.has_value()) {
            payload["is_flexible"] = is_flexible.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/createInvoiceLink", _body)
            : co_await request_->uploadFiles(token_ + "/createInvoiceLink", _body, _uploads);
        co_return parse_response<std::string>(_resp).result.value();
    }

    drogon::Task<std::string> createInvoiceLink(CreateInvoiceLinkArgs args) {
        co_return co_await createInvoiceLink(std::move(args.title),
            std::move(args.description),
            std::move(args.invoice_payload),
            std::move(args.currency),
            std::move(args.prices),
            std::move(args.business_connection_id),
            std::move(args.provider_token),
            std::move(args.subscription_period),
            std::move(args.max_tip_amount),
            std::move(args.suggested_tip_amounts),
            std::move(args.provider_data),
            std::move(args.photo_url),
            std::move(args.photo_size),
            std::move(args.photo_width),
            std::move(args.photo_height),
            std::move(args.need_name),
            std::move(args.need_phone_number),
            std::move(args.need_email),
            std::move(args.need_shipping_address),
            std::move(args.send_phone_number_to_provider),
            std::move(args.send_email_to_provider),
            std::move(args.is_flexible));
    }

    /**
     * If you sent an invoice requesting a shipping address and the parameter is_flexible was
     * specified, the Bot API will send an Update with a shipping_query field to the bot. Use
     * this method to reply to shipping queries. On success, True is returned.
     *
     * @param shipping_query_id [required] Unique identifier for the query to be answered.
     * @param ok [required] Pass True if delivery to the specified address is possible and False if there are any problems (for .
     * @param shipping_options [optional] Optional.
     * @param error_message [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#answershippingquery
     */
    struct AnswerShippingQueryArgs {
        std::string shipping_query_id{""};
        bool ok{false};
        std::vector<std::shared_ptr<ShippingOption>> shipping_options;
        std::optional<std::string> error_message;
    };

    drogon::Task<bool> answerShippingQuery(std::string shipping_query_id,
                                           bool ok,
                                           std::vector<std::shared_ptr<ShippingOption>> shipping_options = {},
                                           std::optional<std::string> error_message = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["shipping_query_id"] = shipping_query_id;
        payload["ok"] = ok;
        if (!shipping_options.empty()) {
            json _arr = json::array();
            for (const auto& _item : shipping_options) {
                if (_item) {
                    json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
                }
            }
            payload["shipping_options"] = std::move(_arr);
        }
        if (error_message.has_value()) {
            payload["error_message"] = error_message.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/answerShippingQuery", _body)
            : co_await request_->uploadFiles(token_ + "/answerShippingQuery", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> answerShippingQuery(AnswerShippingQueryArgs args) {
        co_return co_await answerShippingQuery(std::move(args.shipping_query_id),
            std::move(args.ok),
            std::move(args.shipping_options),
            std::move(args.error_message));
    }

    /**
     * Once the user has confirmed their payment and shipping details, the Bot API sends the
     * final confirmation in the form of an Update with the field pre_checkout_query. Use this
     * method to respond to such pre-checkout queries. On success, True is returned. Note: The
     * Bot API must receive an answer within 10 seconds after the pre-checkout query was sent.
     *
     * @param pre_checkout_query_id [required] Unique identifier for the query to be answered.
     * @param ok [required] Specify True if everything is alright (goods are available, etc.
     * @param error_message [optional] Optional.
     * @returns bool
     * @see https://core.telegram.org/bots/api#answerprecheckoutquery
     */
    struct AnswerPreCheckoutQueryArgs {
        std::string pre_checkout_query_id{""};
        bool ok{false};
        std::optional<std::string> error_message;
    };

    drogon::Task<bool> answerPreCheckoutQuery(std::string pre_checkout_query_id,
                                              bool ok,
                                              std::optional<std::string> error_message = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["pre_checkout_query_id"] = pre_checkout_query_id;
        payload["ok"] = ok;
        if (error_message.has_value()) {
            payload["error_message"] = error_message.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/answerPreCheckoutQuery", _body)
            : co_await request_->uploadFiles(token_ + "/answerPreCheckoutQuery", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> answerPreCheckoutQuery(AnswerPreCheckoutQueryArgs args) {
        co_return co_await answerPreCheckoutQuery(std::move(args.pre_checkout_query_id),
            std::move(args.ok),
            std::move(args.error_message));
    }

    /**
     * A method to get the current Telegram Stars balance of the bot. Requires no parameters. On
     * success, returns a StarAmount object.
     *
     * @returns std::shared_ptr<StarAmount>
     * @see https://core.telegram.org/bots/api#getmystarbalance
     */
    drogon::Task<std::shared_ptr<StarAmount>> getMyStarBalance() const {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getMyStarBalance", _body)
            : co_await request_->uploadFiles(token_ + "/getMyStarBalance", _body, _uploads);
        co_return parse_response<std::shared_ptr<StarAmount>>(_resp).result.value();
    }

    /**
     * Returns the bot's Telegram Star transactions in chronological order. On success, returns
     * a StarTransactions object.
     *
     * @param offset [optional] Optional.
     * @param limit [optional] Optional.
     * @returns std::shared_ptr<StarTransactions>
     * @see https://core.telegram.org/bots/api#getstartransactions
     */
    struct GetStarTransactionsArgs {
        std::optional<int64_t> offset;
        std::optional<int64_t> limit;
    };

    drogon::Task<std::shared_ptr<StarTransactions>> getStarTransactions(std::optional<int64_t> offset = std::nullopt,
                                                                        std::optional<int64_t> limit = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (offset.has_value()) {
            payload["offset"] = offset.value();
        }
        if (limit.has_value()) {
            payload["limit"] = limit.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getStarTransactions", _body)
            : co_await request_->uploadFiles(token_ + "/getStarTransactions", _body, _uploads);
        co_return parse_response<std::shared_ptr<StarTransactions>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<StarTransactions>> getStarTransactions(GetStarTransactionsArgs args) {
        co_return co_await getStarTransactions(std::move(args.offset),
            std::move(args.limit));
    }

    /**
     * Refunds a successful payment in Telegram Stars. Returns True on success.
     *
     * @param user_id [required] Identifier of the user whose payment will be refunded.
     * @param telegram_payment_charge_id [required] Telegram payment identifier.
     * @returns bool
     * @see https://core.telegram.org/bots/api#refundstarpayment
     */
    struct RefundStarPaymentArgs {
        int64_t user_id{0};
        std::string telegram_payment_charge_id{""};
    };

    drogon::Task<bool> refundStarPayment(int64_t user_id,
                                         std::string telegram_payment_charge_id) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        payload["telegram_payment_charge_id"] = telegram_payment_charge_id;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/refundStarPayment", _body)
            : co_await request_->uploadFiles(token_ + "/refundStarPayment", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> refundStarPayment(RefundStarPaymentArgs args) {
        co_return co_await refundStarPayment(std::move(args.user_id),
            std::move(args.telegram_payment_charge_id));
    }

    /**
     * Allows the bot to cancel or re-enable extension of a subscription paid in Telegram Stars.
     * Returns True on success.
     *
     * @param user_id [required] Identifier of the user whose subscription will be edited.
     * @param telegram_payment_charge_id [required] Telegram payment identifier for the subscription.
     * @param is_canceled [required] Pass True to cancel extension of the user subscription; the subscription must be active up to the en.
     * @returns bool
     * @see https://core.telegram.org/bots/api#edituserstarsubscription
     */
    struct EditUserStarSubscriptionArgs {
        int64_t user_id{0};
        std::string telegram_payment_charge_id{""};
        bool is_canceled{false};
    };

    drogon::Task<bool> editUserStarSubscription(int64_t user_id,
                                                std::string telegram_payment_charge_id,
                                                bool is_canceled) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        payload["telegram_payment_charge_id"] = telegram_payment_charge_id;
        payload["is_canceled"] = is_canceled;
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/editUserStarSubscription", _body)
            : co_await request_->uploadFiles(token_ + "/editUserStarSubscription", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> editUserStarSubscription(EditUserStarSubscriptionArgs args) {
        co_return co_await editUserStarSubscription(std::move(args.user_id),
            std::move(args.telegram_payment_charge_id),
            std::move(args.is_canceled));
    }

    // ── Telegram Passport ─────────────────────────────────────────────────────

    /**
     * Informs a user that some of the Telegram Passport elements they provided contains errors.
     * The user will not be able to re-submit their Passport to you until the errors are fixed
     * (the contents of the field for which you returned the error must change). Returns True on
     * success.
     * Use this if the data submitted by the user doesn't satisfy the standards your service
     * requires for any reason. For example, if a birthday date seems invalid, a submitted
     * document is blurry, a scan shows evidence of tampering, etc. Supply some details in the
     * error message to make sure the user knows how to correct the issues.
     *
     * @param user_id [required] User identifier.
     * @param errors [required] A JSON-serialized array describing the errors.
     * @returns bool
     * @see https://core.telegram.org/bots/api#setpassportdataerrors
     */
    struct SetPassportDataErrorsArgs {
        int64_t user_id{0};
        std::vector<PassportElementError> errors;
    };

    drogon::Task<bool> setPassportDataErrors(int64_t user_id,
                                             std::vector<PassportElementError> errors) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        {
            json _arr = json::array();
            for (const auto& _item : errors) {
                {
                    json _e; to_json(_e, _item); _arr.push_back(std::move(_e));
                }
            }
            payload["errors"] = std::move(_arr);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setPassportDataErrors", _body)
            : co_await request_->uploadFiles(token_ + "/setPassportDataErrors", _body, _uploads);
        co_return parse_response<bool>(_resp).result.value();
    }

    drogon::Task<bool> setPassportDataErrors(SetPassportDataErrorsArgs args) {
        co_return co_await setPassportDataErrors(std::move(args.user_id),
            std::move(args.errors));
    }

    // ── Games ─────────────────────────────────────────────────────────────────

    /**
     * Use this method to send a game. On success, the sent Message is returned.
     *
     * @param business_connection_id [optional] Optional.
     * @param chat_id [required] Unique identifier for the target chat or username of the target bot in the format @username .
     * @param message_thread_id [optional] Optional.
     * @param game_short_name [required] Short name of the game, serves as the unique identifier for the game.
     * @param disable_notification [optional] Optional.
     * @param protect_content [optional] Optional.
     * @param allow_paid_broadcast [optional] Optional.
     * @param message_effect_id [optional] Optional.
     * @param reply_parameters [optional] Optional.
     * @param reply_markup [optional] Optional.
     * @returns std::shared_ptr<Message>
     * @see https://core.telegram.org/bots/api#sendgame
     */
    struct SendGameArgs {
        ChatId chat_id{};
        std::string game_short_name{""};
        std::optional<std::string> business_connection_id;
        std::optional<int64_t> message_thread_id;
        std::optional<bool> disable_notification;
        std::optional<bool> protect_content;
        std::optional<bool> allow_paid_broadcast;
        std::optional<std::string> message_effect_id;
        std::shared_ptr<ReplyParameters> reply_parameters;
        std::shared_ptr<InlineKeyboardMarkup> reply_markup;
    };

    drogon::Task<std::shared_ptr<Message>> sendGame(ChatId chat_id,
                                                    std::string game_short_name,
                                                    std::optional<std::string> business_connection_id = std::nullopt,
                                                    std::optional<int64_t> message_thread_id = std::nullopt,
                                                    std::optional<bool> disable_notification = std::nullopt,
                                                    std::optional<bool> protect_content = std::nullopt,
                                                    std::optional<bool> allow_paid_broadcast = std::nullopt,
                                                    std::optional<std::string> message_effect_id = std::nullopt,
                                                    std::shared_ptr<ReplyParameters> reply_parameters = nullptr,
                                                    std::shared_ptr<InlineKeyboardMarkup> reply_markup = nullptr) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        if (business_connection_id.has_value()) {
            payload["business_connection_id"] = business_connection_id.value();
        }
        if (auto* _p = std::get_if<int64_t>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&chat_id)) {
            payload["chat_id"] = *_p;
        }
        if (message_thread_id.has_value()) {
            payload["message_thread_id"] = message_thread_id.value();
        }
        payload["game_short_name"] = game_short_name;
        if (disable_notification.has_value()) {
            payload["disable_notification"] = disable_notification.value();
        }
        if (protect_content.has_value()) {
            payload["protect_content"] = protect_content.value();
        }
        if (allow_paid_broadcast.has_value()) {
            payload["allow_paid_broadcast"] = allow_paid_broadcast.value();
        }
        if (message_effect_id.has_value()) {
            payload["message_effect_id"] = message_effect_id.value();
        }
        if (reply_parameters) {
            json _sub;
            to_json(_sub, *reply_parameters);
            payload["reply_parameters"] = std::move(_sub);
        }
        if (reply_markup) {
            json _sub;
            to_json(_sub, *reply_markup);
            payload["reply_markup"] = std::move(_sub);
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/sendGame", _body)
            : co_await request_->uploadFiles(token_ + "/sendGame", _body, _uploads);
        co_return parse_response<std::shared_ptr<Message>>(_resp).result.value();
    }

    drogon::Task<std::shared_ptr<Message>> sendGame(SendGameArgs args) {
        co_return co_await sendGame(std::move(args.chat_id),
            std::move(args.game_short_name),
            std::move(args.business_connection_id),
            std::move(args.message_thread_id),
            std::move(args.disable_notification),
            std::move(args.protect_content),
            std::move(args.allow_paid_broadcast),
            std::move(args.message_effect_id),
            std::move(args.reply_parameters),
            std::move(args.reply_markup));
    }

    /**
     * Use this method to set the score of the specified user in a game message. On success, if
     * the message is not an inline message, the Message is returned, otherwise True is
     * returned. Returns an error, if the new score is not greater than the user's current score
     * in the chat and force is False.
     *
     * @param user_id [required] User identifier.
     * @param score [required] New score, must be non-negative.
     * @param force [optional] Optional.
     * @param disable_edit_message [optional] Optional.
     * @param chat_id [optional] Optional.
     * @param message_id [optional] Optional.
     * @param inline_message_id [optional] Optional.
     * @returns std::variant<std::shared_ptr<Message>, bool>
     * @see https://core.telegram.org/bots/api#setgamescore
     */
    struct SetGameScoreArgs {
        int64_t user_id{0};
        int64_t score{0};
        std::optional<bool> force;
        std::optional<bool> disable_edit_message;
        std::optional<int64_t> chat_id;
        std::optional<int64_t> message_id;
        std::optional<std::string> inline_message_id;
    };

    drogon::Task<std::variant<std::shared_ptr<Message>, bool>> setGameScore(int64_t user_id,
                                                                            int64_t score,
                                                                            std::optional<bool> force = std::nullopt,
                                                                            std::optional<bool> disable_edit_message = std::nullopt,
                                                                            std::optional<int64_t> chat_id = std::nullopt,
                                                                            std::optional<int64_t> message_id = std::nullopt,
                                                                            std::optional<std::string> inline_message_id = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        payload["score"] = score;
        if (force.has_value()) {
            payload["force"] = force.value();
        }
        if (disable_edit_message.has_value()) {
            payload["disable_edit_message"] = disable_edit_message.value();
        }
        if (chat_id.has_value()) {
            payload["chat_id"] = chat_id.value();
        }
        if (message_id.has_value()) {
            payload["message_id"] = message_id.value();
        }
        if (inline_message_id.has_value()) {
            payload["inline_message_id"] = inline_message_id.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/setGameScore", _body)
            : co_await request_->uploadFiles(token_ + "/setGameScore", _body, _uploads);
        co_return parse_response<std::variant<std::shared_ptr<Message>, bool>>(_resp).result.value();
    }

    drogon::Task<std::variant<std::shared_ptr<Message>, bool>> setGameScore(SetGameScoreArgs args) {
        co_return co_await setGameScore(std::move(args.user_id),
            std::move(args.score),
            std::move(args.force),
            std::move(args.disable_edit_message),
            std::move(args.chat_id),
            std::move(args.message_id),
            std::move(args.inline_message_id));
    }

    /**
     * Use this method to get data for high score tables. Will return the score of the specified
     * user and several of their neighbors in a game. Returns an Array of GameHighScore objects.
     * This method will currently return scores for the target user, plus two of their closest
     * neighbors on each side. Will also return the top three users if the user and their
     * neighbors are not among them. Please note that this behavior is subject to change.
     *
     * @param user_id [required] Target user id.
     * @param chat_id [optional] Optional.
     * @param message_id [optional] Optional.
     * @param inline_message_id [optional] Optional.
     * @returns std::vector<std::shared_ptr<GameHighScore>>
     * @see https://core.telegram.org/bots/api#getgamehighscores
     */
    struct GetGameHighScoresArgs {
        int64_t user_id{0};
        std::optional<int64_t> chat_id;
        std::optional<int64_t> message_id;
        std::optional<std::string> inline_message_id;
    };

    drogon::Task<std::vector<std::shared_ptr<GameHighScore>>> getGameHighScores(int64_t user_id,
                                                                                std::optional<int64_t> chat_id = std::nullopt,
                                                                                std::optional<int64_t> message_id = std::nullopt,
                                                                                std::optional<std::string> inline_message_id = std::nullopt) {
        json payload = json::object();
        std::vector<corogram::UploadEntry> _uploads;
        payload["user_id"] = user_id;
        if (chat_id.has_value()) {
            payload["chat_id"] = chat_id.value();
        }
        if (message_id.has_value()) {
            payload["message_id"] = message_id.value();
        }
        if (inline_message_id.has_value()) {
            payload["inline_message_id"] = inline_message_id.value();
        }
        const std::string _body = payload.dump(-1, ' ', false, nlohmann::json::error_handler_t::replace);
        const std::string _resp = _uploads.empty()
            ? co_await request_->sendRequest(token_ + "/getGameHighScores", _body)
            : co_await request_->uploadFiles(token_ + "/getGameHighScores", _body, _uploads);
        co_return parse_response<std::vector<std::shared_ptr<GameHighScore>>>(_resp).result.value();
    }

    drogon::Task<std::vector<std::shared_ptr<GameHighScore>>> getGameHighScores(GetGameHighScoresArgs args) {
        co_return co_await getGameHighScores(std::move(args.user_id),
            std::move(args.chat_id),
            std::move(args.message_id),
            std::move(args.inline_message_id));
    }

};

} // namespace corogram
