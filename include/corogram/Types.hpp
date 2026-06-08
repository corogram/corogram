/**
 * @file    Types.h
 * @brief   Telegram Bot API 10.0 — auto-generated type definitions
 * @date    08-05-2026
 *
 * Generated via schema  —  DO NOT EDIT MANUALLY.
 */
#pragma once
#include <cstdint>
#include <memory>
#include <optional>
#include <string>
#include <variant>
#include <vector>
#include <nlohmann/json.hpp>
#include <fstream>
#include <corogram/Enums.hpp>
#include <corogram/utils/Link.hpp>

// Single definition of the json alias — Methods.hpp must NOT redefine it.
using json = nlohmann::json;

namespace corogram {


// ── Forward declarations ─────────────────────────────────────
struct AcceptedGiftTypes;
struct AffiliateInfo;
struct Animation;
struct Audio;
struct BackgroundFillFreeformGradient;
struct BackgroundFillGradient;
struct BackgroundFillSolid;
struct BackgroundTypeChatTheme;
struct BackgroundTypeFill;
struct BackgroundTypePattern;
struct BackgroundTypeWallpaper;
struct Birthdate;
struct BotAccessSettings;
struct BotCommand;
struct BotCommandScopeAllChatAdministrators;
struct BotCommandScopeAllGroupChats;
struct BotCommandScopeAllPrivateChats;
struct BotCommandScopeChat;
struct BotCommandScopeChatAdministrators;
struct BotCommandScopeChatMember;
struct BotCommandScopeDefault;
struct BotDescription;
struct BotName;
struct BotShortDescription;
struct BusinessBotRights;
struct BusinessConnection;
struct BusinessIntro;
struct BusinessLocation;
struct BusinessMessagesDeleted;
struct BusinessOpeningHours;
struct BusinessOpeningHoursInterval;
struct CallbackGame;
struct CallbackQuery;
struct Chat;
struct ChatAdministratorRights;
struct ChatBackground;
struct ChatBoost;
struct ChatBoostAdded;
struct ChatBoostRemoved;
struct ChatBoostSourceGiftCode;
struct ChatBoostSourceGiveaway;
struct ChatBoostSourcePremium;
struct ChatBoostUpdated;
struct ChatFullInfo;
struct ChatInviteLink;
struct ChatJoinRequest;
struct ChatLocation;
struct ChatMemberAdministrator;
struct ChatMemberBanned;
struct ChatMemberLeft;
struct ChatMemberMember;
struct ChatMemberOwner;
struct ChatMemberRestricted;
struct ChatMemberUpdated;
struct ChatOwnerChanged;
struct ChatOwnerLeft;
struct ChatPermissions;
struct ChatPhoto;
struct ChatShared;
struct Checklist;
struct ChecklistTask;
struct ChecklistTasksAdded;
struct ChecklistTasksDone;
struct ChosenInlineResult;
struct Contact;
struct CopyTextButton;
struct Dice;
struct DirectMessagePriceChanged;
struct DirectMessagesTopic;
struct Document;
struct EncryptedCredentials;
struct EncryptedPassportElement;
struct ExternalReplyInfo;
struct File;
struct ForceReply;
struct ForumTopic;
struct ForumTopicClosed;
struct ForumTopicCreated;
struct ForumTopicEdited;
struct ForumTopicReopened;
struct Game;
struct GameHighScore;
struct GeneralForumTopicHidden;
struct GeneralForumTopicUnhidden;
struct Gift;
struct GiftBackground;
struct GiftInfo;
struct Gifts;
struct Giveaway;
struct GiveawayCompleted;
struct GiveawayCreated;
struct GiveawayWinners;
struct InaccessibleMessage;
struct InlineKeyboardButton;
struct InlineKeyboardMarkup;
struct InlineQuery;
struct InlineQueryResultArticle;
struct InlineQueryResultAudio;
struct InlineQueryResultCachedAudio;
struct InlineQueryResultCachedDocument;
struct InlineQueryResultCachedGif;
struct InlineQueryResultCachedMpeg4Gif;
struct InlineQueryResultCachedPhoto;
struct InlineQueryResultCachedSticker;
struct InlineQueryResultCachedVideo;
struct InlineQueryResultCachedVoice;
struct InlineQueryResultContact;
struct InlineQueryResultDocument;
struct InlineQueryResultGame;
struct InlineQueryResultGif;
struct InlineQueryResultLocation;
struct InlineQueryResultMpeg4Gif;
struct InlineQueryResultPhoto;
struct InlineQueryResultVenue;
struct InlineQueryResultVideo;
struct InlineQueryResultVoice;
struct InlineQueryResultsButton;
struct InputChecklist;
struct InputChecklistTask;
struct InputContactMessageContent;
struct InputFile;
struct InputInvoiceMessageContent;
struct InputLocationMessageContent;
struct InputMediaAnimation;
struct InputMediaAudio;
struct InputMediaDocument;
struct InputMediaLivePhoto;
struct InputMediaLocation;
struct InputMediaPhoto;
struct InputMediaSticker;
struct InputMediaVenue;
struct InputMediaVideo;
struct InputPaidMediaLivePhoto;
struct InputPaidMediaPhoto;
struct InputPaidMediaVideo;
struct InputPollOption;
struct InputProfilePhotoAnimated;
struct InputProfilePhotoStatic;
struct InputSticker;
struct InputStoryContentPhoto;
struct InputStoryContentVideo;
struct InputTextMessageContent;
struct InputVenueMessageContent;
struct Invoice;
struct KeyboardButton;
struct KeyboardButtonPollType;
struct KeyboardButtonRequestChat;
struct KeyboardButtonRequestManagedBot;
struct KeyboardButtonRequestUsers;
struct LabeledPrice;
struct LinkPreviewOptions;
struct LivePhoto;
struct Location;
struct LocationAddress;
struct LoginUrl;
struct ManagedBotCreated;
struct ManagedBotUpdated;
struct MaskPosition;
struct MenuButtonCommands;
struct MenuButtonDefault;
struct MenuButtonWebApp;
struct Message;
struct MessageAutoDeleteTimerChanged;
struct MessageEntity;
struct MessageId;
struct MessageOriginChannel;
struct MessageOriginChat;
struct MessageOriginHiddenUser;
struct MessageOriginUser;
struct MessageReactionCountUpdated;
struct MessageReactionUpdated;
struct OrderInfo;
struct OwnedGiftRegular;
struct OwnedGiftUnique;
struct OwnedGifts;
struct PaidMediaInfo;
struct PaidMediaLivePhoto;
struct PaidMediaPhoto;
struct PaidMediaPreview;
struct PaidMediaPurchased;
struct PaidMediaVideo;
struct PaidMessagePriceChanged;
struct PassportData;
struct PassportElementErrorDataField;
struct PassportElementErrorFile;
struct PassportElementErrorFiles;
struct PassportElementErrorFrontSide;
struct PassportElementErrorReverseSide;
struct PassportElementErrorSelfie;
struct PassportElementErrorTranslationFile;
struct PassportElementErrorTranslationFiles;
struct PassportElementErrorUnspecified;
struct PassportFile;
struct PhotoSize;
struct Poll;
struct PollAnswer;
struct PollMedia;
struct PollOption;
struct PollOptionAdded;
struct PollOptionDeleted;
struct PreCheckoutQuery;
struct PreparedInlineMessage;
struct PreparedKeyboardButton;
struct ProximityAlertTriggered;
struct ReactionCount;
struct ReactionTypeCustomEmoji;
struct ReactionTypeEmoji;
struct ReactionTypePaid;
struct RefundedPayment;
struct ReplyKeyboardMarkup;
struct ReplyKeyboardRemove;
struct ReplyParameters;
struct ResponseParameters;
struct RevenueWithdrawalStateFailed;
struct RevenueWithdrawalStatePending;
struct RevenueWithdrawalStateSucceeded;
struct SentGuestMessage;
struct SentWebAppMessage;
struct SharedUser;
struct ShippingAddress;
struct ShippingOption;
struct ShippingQuery;
struct StarAmount;
struct StarTransaction;
struct StarTransactions;
struct Sticker;
struct StickerSet;
struct Story;
struct StoryArea;
struct StoryAreaPosition;
struct StoryAreaTypeLink;
struct StoryAreaTypeLocation;
struct StoryAreaTypeSuggestedReaction;
struct StoryAreaTypeUniqueGift;
struct StoryAreaTypeWeather;
struct SuccessfulPayment;
struct SuggestedPostApprovalFailed;
struct SuggestedPostApproved;
struct SuggestedPostDeclined;
struct SuggestedPostInfo;
struct SuggestedPostPaid;
struct SuggestedPostParameters;
struct SuggestedPostPrice;
struct SuggestedPostRefunded;
struct SwitchInlineQueryChosenChat;
struct TextQuote;
struct TransactionPartnerAffiliateProgram;
struct TransactionPartnerChat;
struct TransactionPartnerFragment;
struct TransactionPartnerOther;
struct TransactionPartnerTelegramAds;
struct TransactionPartnerTelegramApi;
struct TransactionPartnerUser;
struct UniqueGift;
struct UniqueGiftBackdrop;
struct UniqueGiftBackdropColors;
struct UniqueGiftColors;
struct UniqueGiftInfo;
struct UniqueGiftModel;
struct UniqueGiftSymbol;
struct Update;
struct User;
struct UserChatBoosts;
struct UserProfileAudios;
struct UserProfilePhotos;
struct UserRating;
struct UsersShared;
struct Venue;
struct Video;
struct VideoChatEnded;
struct VideoChatParticipantsInvited;
struct VideoChatScheduled;
struct VideoChatStarted;
struct VideoNote;
struct VideoQuality;
struct Voice;
struct WebAppData;
struct WebAppInfo;
struct WebhookInfo;
struct WriteAccessAllowed;

// ── Primitive variant aliases ────────────────────────────────

using ChatId    = std::variant<int64_t, std::string>;
using ReplyMarkup = std::variant<
    std::shared_ptr<InlineKeyboardMarkup>,
    std::shared_ptr<ReplyKeyboardMarkup>,
    std::shared_ptr<ReplyKeyboardRemove>,
    std::shared_ptr<ForceReply>>;

// ── Named variant aliases ────────────────────────────────────
using MediaVariant = std::variant<
    std::shared_ptr<InputMediaAudio>,
    std::shared_ptr<InputMediaDocument>,
    std::shared_ptr<InputMediaLivePhoto>,
    std::shared_ptr<InputMediaPhoto>,
    std::shared_ptr<InputMediaVideo>
>;

// ── Variant type aliases ─────────────────────────────────────

using MaybeInaccessibleMessage = std::variant<
    std::shared_ptr<Message>,
    std::shared_ptr<InaccessibleMessage>
>;

using MessageOrigin = std::variant<
    std::shared_ptr<MessageOriginUser>,
    std::shared_ptr<MessageOriginHiddenUser>,
    std::shared_ptr<MessageOriginChat>,
    std::shared_ptr<MessageOriginChannel>
>;

using PaidMedia = std::variant<
    std::shared_ptr<PaidMediaLivePhoto>,
    std::shared_ptr<PaidMediaPhoto>,
    std::shared_ptr<PaidMediaPreview>,
    std::shared_ptr<PaidMediaVideo>
>;

using InputPollMedia = std::variant<
    std::shared_ptr<InputMediaAnimation>,
    std::shared_ptr<InputMediaAudio>,
    std::shared_ptr<InputMediaDocument>,
    std::shared_ptr<InputMediaLivePhoto>,
    std::shared_ptr<InputMediaLocation>,
    std::shared_ptr<InputMediaPhoto>,
    std::shared_ptr<InputMediaVenue>,
    std::shared_ptr<InputMediaVideo>
>;

using InputPollOptionMedia = std::variant<
    std::shared_ptr<InputMediaAnimation>,
    std::shared_ptr<InputMediaLivePhoto>,
    std::shared_ptr<InputMediaLocation>,
    std::shared_ptr<InputMediaPhoto>,
    std::shared_ptr<InputMediaSticker>,
    std::shared_ptr<InputMediaVenue>,
    std::shared_ptr<InputMediaVideo>
>;

using BackgroundFill = std::variant<
    std::shared_ptr<BackgroundFillSolid>,
    std::shared_ptr<BackgroundFillGradient>,
    std::shared_ptr<BackgroundFillFreeformGradient>
>;

using BackgroundType = std::variant<
    std::shared_ptr<BackgroundTypeFill>,
    std::shared_ptr<BackgroundTypeWallpaper>,
    std::shared_ptr<BackgroundTypePattern>,
    std::shared_ptr<BackgroundTypeChatTheme>
>;

using ChatMember = std::variant<
    std::shared_ptr<ChatMemberOwner>,
    std::shared_ptr<ChatMemberAdministrator>,
    std::shared_ptr<ChatMemberMember>,
    std::shared_ptr<ChatMemberRestricted>,
    std::shared_ptr<ChatMemberLeft>,
    std::shared_ptr<ChatMemberBanned>
>;

using StoryAreaType = std::variant<
    std::shared_ptr<StoryAreaTypeLocation>,
    std::shared_ptr<StoryAreaTypeSuggestedReaction>,
    std::shared_ptr<StoryAreaTypeLink>,
    std::shared_ptr<StoryAreaTypeWeather>,
    std::shared_ptr<StoryAreaTypeUniqueGift>
>;

using ReactionType = std::variant<
    std::shared_ptr<ReactionTypeEmoji>,
    std::shared_ptr<ReactionTypeCustomEmoji>,
    std::shared_ptr<ReactionTypePaid>
>;

using OwnedGift = std::variant<
    std::shared_ptr<OwnedGiftRegular>,
    std::shared_ptr<OwnedGiftUnique>
>;

using BotCommandScope = std::variant<
    std::shared_ptr<BotCommandScopeDefault>,
    std::shared_ptr<BotCommandScopeAllPrivateChats>,
    std::shared_ptr<BotCommandScopeAllGroupChats>,
    std::shared_ptr<BotCommandScopeAllChatAdministrators>,
    std::shared_ptr<BotCommandScopeChat>,
    std::shared_ptr<BotCommandScopeChatAdministrators>,
    std::shared_ptr<BotCommandScopeChatMember>
>;

using MenuButton = std::variant<
    std::shared_ptr<MenuButtonCommands>,
    std::shared_ptr<MenuButtonWebApp>,
    std::shared_ptr<MenuButtonDefault>
>;

using ChatBoostSource = std::variant<
    std::shared_ptr<ChatBoostSourcePremium>,
    std::shared_ptr<ChatBoostSourceGiftCode>,
    std::shared_ptr<ChatBoostSourceGiveaway>
>;

using InputMedia = std::variant<
    std::shared_ptr<InputMediaAnimation>,
    std::shared_ptr<InputMediaAudio>,
    std::shared_ptr<InputMediaDocument>,
    std::shared_ptr<InputMediaLivePhoto>,
    std::shared_ptr<InputMediaPhoto>,
    std::shared_ptr<InputMediaVideo>
>;

using InputPaidMedia = std::variant<
    std::shared_ptr<InputPaidMediaLivePhoto>,
    std::shared_ptr<InputPaidMediaPhoto>,
    std::shared_ptr<InputPaidMediaVideo>
>;

using InputProfilePhoto = std::variant<
    std::shared_ptr<InputProfilePhotoStatic>,
    std::shared_ptr<InputProfilePhotoAnimated>
>;

using InputStoryContent = std::variant<
    std::shared_ptr<InputStoryContentPhoto>,
    std::shared_ptr<InputStoryContentVideo>
>;

using InlineQueryResult = std::variant<
    std::shared_ptr<InlineQueryResultCachedAudio>,
    std::shared_ptr<InlineQueryResultCachedDocument>,
    std::shared_ptr<InlineQueryResultCachedGif>,
    std::shared_ptr<InlineQueryResultCachedMpeg4Gif>,
    std::shared_ptr<InlineQueryResultCachedPhoto>,
    std::shared_ptr<InlineQueryResultCachedSticker>,
    std::shared_ptr<InlineQueryResultCachedVideo>,
    std::shared_ptr<InlineQueryResultCachedVoice>,
    std::shared_ptr<InlineQueryResultArticle>,
    std::shared_ptr<InlineQueryResultAudio>,
    std::shared_ptr<InlineQueryResultContact>,
    std::shared_ptr<InlineQueryResultGame>,
    std::shared_ptr<InlineQueryResultDocument>,
    std::shared_ptr<InlineQueryResultGif>,
    std::shared_ptr<InlineQueryResultLocation>,
    std::shared_ptr<InlineQueryResultMpeg4Gif>,
    std::shared_ptr<InlineQueryResultPhoto>,
    std::shared_ptr<InlineQueryResultVenue>,
    std::shared_ptr<InlineQueryResultVideo>,
    std::shared_ptr<InlineQueryResultVoice>
>;

using InputMessageContent = std::variant<
    std::shared_ptr<InputTextMessageContent>,
    std::shared_ptr<InputLocationMessageContent>,
    std::shared_ptr<InputVenueMessageContent>,
    std::shared_ptr<InputContactMessageContent>,
    std::shared_ptr<InputInvoiceMessageContent>
>;

using RevenueWithdrawalState = std::variant<
    std::shared_ptr<RevenueWithdrawalStatePending>,
    std::shared_ptr<RevenueWithdrawalStateSucceeded>,
    std::shared_ptr<RevenueWithdrawalStateFailed>
>;

using TransactionPartner = std::variant<
    std::shared_ptr<TransactionPartnerUser>,
    std::shared_ptr<TransactionPartnerChat>,
    std::shared_ptr<TransactionPartnerAffiliateProgram>,
    std::shared_ptr<TransactionPartnerFragment>,
    std::shared_ptr<TransactionPartnerTelegramAds>,
    std::shared_ptr<TransactionPartnerTelegramApi>,
    std::shared_ptr<TransactionPartnerOther>
>;

using PassportElementError = std::variant<
    std::shared_ptr<PassportElementErrorDataField>,
    std::shared_ptr<PassportElementErrorFrontSide>,
    std::shared_ptr<PassportElementErrorReverseSide>,
    std::shared_ptr<PassportElementErrorSelfie>,
    std::shared_ptr<PassportElementErrorFile>,
    std::shared_ptr<PassportElementErrorFiles>,
    std::shared_ptr<PassportElementErrorTranslationFile>,
    std::shared_ptr<PassportElementErrorTranslationFiles>,
    std::shared_ptr<PassportElementErrorUnspecified>
>;

// ── Getting updates ─────────────────────────────────────────────────────────

/**
 * This object represents an incoming update.
 * At most one of the optional fields can be present in any given update.
 * @see https://core.telegram.org/bots/api#update
 */
struct Update {
    /** The update's unique identifier. */
    int64_t update_id{0};
    /** Optional. New incoming message of any kind - text, photo, sticker, etc. */
    std::shared_ptr<Message> message; ///< Optional
    /** Optional. New version of a message that is known to the bot and was edited. */
    std::shared_ptr<Message> edited_message; ///< Optional
    /** Optional. New incoming channel post of any kind - text, photo, sticker, etc. */
    std::shared_ptr<Message> channel_post; ///< Optional
    /** Optional. New version of a channel post that is known to the bot and was edited. */
    std::shared_ptr<Message> edited_channel_post; ///< Optional
    /** Optional. The bot was connected to or disconnected from a business account, or a user edited an existing connection with. */
    std::shared_ptr<BusinessConnection> business_connection; ///< Optional
    /** Optional. New message from a connected business account. */
    std::shared_ptr<Message> business_message; ///< Optional
    /** Optional. New version of a message from a connected business account. */
    std::shared_ptr<Message> edited_business_message; ///< Optional
    /** Optional. Messages were deleted from a connected business account. */
    std::shared_ptr<BusinessMessagesDeleted> deleted_business_messages; ///< Optional
    /** Optional. New guest message. */
    std::shared_ptr<Message> guest_message; ///< Optional
    /** Optional. A reaction to a message was changed by a user. */
    std::shared_ptr<MessageReactionUpdated> message_reaction; ///< Optional
    /** Optional. Reactions to a message with anonymous reactions were changed. */
    std::shared_ptr<MessageReactionCountUpdated> message_reaction_count; ///< Optional
    /** Optional. New incoming inline query. */
    std::shared_ptr<InlineQuery> inline_query; ///< Optional
    /** Optional. The result of an inline query that was chosen by a user and sent to their chat partner. */
    std::shared_ptr<ChosenInlineResult> chosen_inline_result; ///< Optional
    /** Optional. New incoming callback query. */
    std::shared_ptr<CallbackQuery> callback_query; ///< Optional
    /** Optional. New incoming shipping query. */
    std::shared_ptr<ShippingQuery> shipping_query; ///< Optional
    /** Optional. New incoming pre-checkout query. */
    std::shared_ptr<PreCheckoutQuery> pre_checkout_query; ///< Optional
    /** Optional. A user purchased paid media with a non-empty payload sent by the bot in a non-channel chat. */
    std::shared_ptr<PaidMediaPurchased> purchased_paid_media; ///< Optional
    /** Optional. New poll state. */
    std::shared_ptr<Poll> poll; ///< Optional
    /** Optional. A user changed their answer in a non-anonymous poll. */
    std::shared_ptr<PollAnswer> poll_answer; ///< Optional
    /** Optional. The bot's chat member status was updated in a chat. */
    std::shared_ptr<ChatMemberUpdated> my_chat_member; ///< Optional
    /** Optional. A chat member's status was updated in a chat. */
    std::shared_ptr<ChatMemberUpdated> chat_member; ///< Optional
    /** Optional. A request to join the chat has been sent. */
    std::shared_ptr<ChatJoinRequest> chat_join_request; ///< Optional
    /** Optional. A chat boost was added or changed. */
    std::shared_ptr<ChatBoostUpdated> chat_boost; ///< Optional
    /** Optional. A boost was removed from a chat. */
    std::shared_ptr<ChatBoostRemoved> removed_chat_boost; ///< Optional
    /** Optional. A new bot was created to be managed by the bot, or token or owner of a managed bot was changed. */
    std::shared_ptr<ManagedBotUpdated> managed_bot; ///< Optional

    // ── Extension methods ──────
    std::string_view event_type() const {
        if (message)                    return "message";
        if (edited_message)             return "edited_message";
        if (channel_post)               return "channel_post";
        if (edited_channel_post)        return "edited_channel_post";
        if (inline_query)               return "inline_query";
        if (chosen_inline_result)       return "chosen_inline_result";
        if (callback_query)             return "callback_query";
        if (shipping_query)             return "shipping_query";
        if (pre_checkout_query)         return "pre_checkout_query";
        if (poll)                       return "poll";
        if (poll_answer)                return "poll_answer";
        if (my_chat_member)             return "my_chat_member";
        if (chat_member)                return "chat_member";
        if (chat_join_request)          return "chat_join_request";
        if (message_reaction)           return "message_reaction";
        if (message_reaction_count)     return "message_reaction_count";
        if (chat_boost)                 return "chat_boost";
        if (removed_chat_boost)         return "removed_chat_boost";
        if (deleted_business_messages)  return "deleted_business_messages";
        if (business_connection)        return "business_connection";
        if (edited_business_message)    return "edited_business_message";
        if (business_message)           return "business_message";
        if (purchased_paid_media)       return "purchased_paid_media";
        if (managed_bot)                return "managed_bot";
        throw std::runtime_error("Update does not contain any known event type.");
    }

};

/**
 * Describes the current status of a webhook.
 * @see https://core.telegram.org/bots/api#webhookinfo
 */
struct WebhookInfo {
    /** Webhook URL, may be empty if webhook is not set up. */
    std::string url{""};
    /** True , if a custom certificate was provided for webhook certificate checks. */
    bool has_custom_certificate{false};
    /** Number of updates awaiting delivery. */
    int64_t pending_update_count{0};
    /** Optional. Currently used webhook IP address. */
    std::optional<std::string> ip_address; ///< Optional
    /** Optional. Unix time for the most recent error that happened when trying to deliver an update via webhook. */
    std::optional<int64_t> last_error_date; ///< Optional
    /** Optional. Error message in human-readable format for the most recent error that happened when trying to deliver an updat. */
    std::optional<std::string> last_error_message; ///< Optional
    /** Optional. Unix time of the most recent error that happened when trying to synchronize available updates with Telegram da. */
    std::optional<int64_t> last_synchronization_error_date; ///< Optional
    /** Optional. The maximum allowed number of simultaneous HTTPS connections to the webhook for update delivery. */
    std::optional<int64_t> max_connections; ///< Optional
    /** Optional. A list of update types the bot is subscribed to. */
    std::vector<std::string> allowed_updates; ///< Optional
};

// ── Available types ─────────────────────────────────────────────────────────

/**
 * This object represents a Telegram user or bot.
 * @see https://core.telegram.org/bots/api#user
 */
struct User {
    /** Unique identifier for this user or bot. */
    int64_t id{0};
    /** True , if this user is a bot. */
    bool is_bot{false};
    /** User's or bot's first name. */
    std::string first_name{""};
    /** Optional. User's or bot's last name. */
    std::optional<std::string> last_name; ///< Optional
    /** Optional. User's or bot's username. */
    std::optional<std::string> username; ///< Optional
    /** Optional. IETF language tag of the user's language. */
    std::optional<std::string> language_code; ///< Optional
    /** Optional. True , if this user is a Telegram Premium user. */
    std::optional<bool> is_premium; ///< Optional
    /** Optional. True , if this user added the bot to the attachment menu. */
    std::optional<bool> added_to_attachment_menu; ///< Optional
    /** Optional. True , if the bot can be invited to groups. */
    std::optional<bool> can_join_groups; ///< Optional
    /** Optional. True , if privacy mode is disabled for the bot. */
    std::optional<bool> can_read_all_group_messages; ///< Optional
    /** Optional. True , if the bot supports guest queries from chats it is not a member of. */
    std::optional<bool> supports_guest_queries; ///< Optional
    /** Optional. True , if the bot supports inline queries. */
    std::optional<bool> supports_inline_queries; ///< Optional
    /** Optional. True , if the bot can be connected to a user account to manage it. */
    std::optional<bool> can_connect_to_business; ///< Optional
    /** Optional. True , if the bot has a main Web App. */
    std::optional<bool> has_main_web_app; ///< Optional
    /** Optional. True , if the bot has forum topic mode enabled in private chats. */
    std::optional<bool> has_topics_enabled; ///< Optional
    /** Optional. True , if the bot allows users to create and delete topics in private chats. */
    std::optional<bool> allows_users_to_create_topics; ///< Optional
    /** Optional. True , if other bots can be created to be controlled by the bot. */
    std::optional<bool> can_manage_bots; ///< Optional
};

/**
 * This object represents a chat.
 * @see https://core.telegram.org/bots/api#chat
 */
struct Chat {
    /** Unique identifier for this chat. */
    int64_t id{0};
    /** Type of the chat, can be either 'private', 'group', 'supergroup' or 'channel'. */
    std::string type{""};
    /** Optional. Title, for supergroups, channels and group chats. */
    std::optional<std::string> title; ///< Optional
    /** Optional. Username, for private chats, supergroups and channels if available. */
    std::optional<std::string> username; ///< Optional
    /** Optional. First name of the other party in a private chat. */
    std::optional<std::string> first_name; ///< Optional
    /** Optional. Last name of the other party in a private chat. */
    std::optional<std::string> last_name; ///< Optional
    /** Optional. True , if the supergroup chat is a forum (has topics enabled). */
    std::optional<bool> is_forum; ///< Optional
    /** Optional. True , if the chat is the direct messages chat of a channel. */
    std::optional<bool> is_direct_messages; ///< Optional

    // ── Extension methods ──────
    std::string full_name() const noexcept {
        if (title.has_value() && !title->empty()) return *title;
        if (first_name.has_value() && last_name.has_value() && !last_name->empty())
          return *first_name + " " + *last_name;
        if (first_name.has_value()) return *first_name;
        return {};
    }

    int64_t shifted_id() const noexcept {
        // Strips the "-100" prefix that Telegram adds for supergroups/channels
        // and returns the "short" numeric ID as a negative number consistent
        // with the Telegram Bot API convention.
        std::string short_id = std::to_string(id);
        const auto pos = short_id.find("-100");
        if (pos != std::string::npos) short_id.erase(pos, 4);
        const int64_t shift = static_cast<int64_t>(
            -1 * std::pow(10.0, static_cast<double>(short_id.size() + 2)));
        return shift - id;
    }

};

/**
 * This object contains full information about a chat.
 * @see https://core.telegram.org/bots/api#chatfullinfo
 */
struct ChatFullInfo {
    /** Unique identifier for this chat. */
    int64_t id{0};
    /** Type of the chat, can be either 'private', 'group', 'supergroup' or 'channel'. */
    std::string type{""};
    /** Optional. Title, for supergroups, channels and group chats. */
    std::optional<std::string> title; ///< Optional
    /** Optional. Username, for private chats, supergroups and channels if available. */
    std::optional<std::string> username; ///< Optional
    /** Optional. First name of the other party in a private chat. */
    std::optional<std::string> first_name; ///< Optional
    /** Optional. Last name of the other party in a private chat. */
    std::optional<std::string> last_name; ///< Optional
    /** Optional. True , if the supergroup chat is a forum (has topics enabled). */
    std::optional<bool> is_forum; ///< Optional
    /** Optional. True , if the chat is the direct messages chat of a channel. */
    std::optional<bool> is_direct_messages; ///< Optional
    /** Identifier of the accent color for the chat name and backgrounds of the chat photo, reply header, and link preview. */
    int64_t accent_color_id{0};
    /** The maximum number of reactions that can be set on a message in the chat. */
    int64_t max_reaction_count{0};
    /** Optional. Chat photo. */
    std::shared_ptr<ChatPhoto> photo; ///< Optional
    /** Optional. If non-empty, the list of all active chat usernames ; for private chats, supergroups and channels. */
    std::vector<std::string> active_usernames; ///< Optional
    /** Optional. For private chats, the date of birth of the user. */
    std::shared_ptr<Birthdate> birthdate; ///< Optional
    /** Optional. For private chats with business accounts, the intro of the business. */
    std::shared_ptr<BusinessIntro> business_intro; ///< Optional
    /** Optional. For private chats with business accounts, the location of the business. */
    std::shared_ptr<BusinessLocation> business_location; ///< Optional
    /** Optional. For private chats with business accounts, the opening hours of the business. */
    std::shared_ptr<BusinessOpeningHours> business_opening_hours; ///< Optional
    /** Optional. For private chats, the personal channel of the user. */
    std::shared_ptr<Chat> personal_chat; ///< Optional
    /** Optional. Information about the corresponding channel chat; for direct messages chats only. */
    std::shared_ptr<Chat> parent_chat; ///< Optional
    /** Optional. List of available reactions allowed in the chat. */
    std::vector<ReactionType> available_reactions; ///< Optional
    /** Optional. Custom emoji identifier of the emoji chosen by the chat for the reply header and link preview background. */
    std::optional<std::string> background_custom_emoji_id; ///< Optional
    /** Optional. Identifier of the accent color for the chat's profile background. */
    std::optional<int64_t> profile_accent_color_id; ///< Optional
    /** Optional. Custom emoji identifier of the emoji chosen by the chat for its profile background. */
    std::optional<std::string> profile_background_custom_emoji_id; ///< Optional
    /** Optional. Custom emoji identifier of the emoji status of the chat or the other party in a private chat. */
    std::optional<std::string> emoji_status_custom_emoji_id; ///< Optional
    /** Optional. Expiration date of the emoji status of the chat or the other party in a private chat, in Unix time, if any. */
    std::optional<int64_t> emoji_status_expiration_date; ///< Optional
    /** Optional. Bio of the other party in a private chat. */
    std::optional<std::string> bio; ///< Optional
    /** Optional. True , if privacy settings of the other party in the private chat allows to use tg://user?id=<user_id> links o. */
    std::optional<bool> has_private_forwards; ///< Optional
    /** Optional. True , if the privacy settings of the other party restrict sending voice and video note messages in the privat. */
    std::optional<bool> has_restricted_voice_and_video_messages; ///< Optional
    /** Optional. True , if users need to join the supergroup before they can send messages. */
    std::optional<bool> join_to_send_messages; ///< Optional
    /** Optional. True , if all users directly joining the supergroup without using an invite link need to be approved by superg. */
    std::optional<bool> join_by_request; ///< Optional
    /** Optional. Description, for groups, supergroups and channel chats. */
    std::optional<std::string> description; ///< Optional
    /** Optional. Primary invite link, for groups, supergroups and channel chats. */
    std::optional<std::string> invite_link; ///< Optional
    /** Optional. The most recent pinned message (by sending date). */
    std::shared_ptr<Message> pinned_message; ///< Optional
    /** Optional. Default chat member permissions, for groups and supergroups. */
    std::shared_ptr<ChatPermissions> permissions; ///< Optional
    /** Information about types of gifts that are accepted by the chat or by the corresponding user for private chats. */
    std::shared_ptr<AcceptedGiftTypes> accepted_gift_types;
    /** Optional. True , if paid media messages can be sent or forwarded to the channel chat. */
    std::optional<bool> can_send_paid_media; ///< Optional
    /** Optional. For supergroups, the minimum allowed delay between consecutive messages sent by each unprivileged user; in sec. */
    std::optional<int64_t> slow_mode_delay; ///< Optional
    /** Optional. For supergroups, the minimum number of boosts that a non-administrator user needs to add in order to ignore sl. */
    std::optional<int64_t> unrestrict_boost_count; ///< Optional
    /** Optional. The time after which all messages sent to the chat will be automatically deleted; in seconds. */
    std::optional<int64_t> message_auto_delete_time; ///< Optional
    /** Optional. True , if aggressive anti-spam checks are enabled in the supergroup. */
    std::optional<bool> has_aggressive_anti_spam_enabled; ///< Optional
    /** Optional. True , if non-administrators can only get the list of bots and administrators in the chat. */
    std::optional<bool> has_hidden_members; ///< Optional
    /** Optional. True , if messages from the chat can't be forwarded to other chats. */
    std::optional<bool> has_protected_content; ///< Optional
    /** Optional. True , if new chat members will have access to old messages; available only to chat administrators. */
    std::optional<bool> has_visible_history; ///< Optional
    /** Optional. For supergroups, name of the group sticker set. */
    std::optional<std::string> sticker_set_name; ///< Optional
    /** Optional. True , if the bot can change the group sticker set. */
    std::optional<bool> can_set_sticker_set; ///< Optional
    /** Optional. For supergroups, the name of the group's custom emoji sticker set. */
    std::optional<std::string> custom_emoji_sticker_set_name; ///< Optional
    /** Optional. Unique identifier for the linked chat, i. */
    std::optional<int64_t> linked_chat_id; ///< Optional
    /** Optional. For supergroups, the location to which the supergroup is connected. */
    std::shared_ptr<ChatLocation> location; ///< Optional
    /** Optional. For private chats, the rating of the user if any. */
    std::shared_ptr<UserRating> rating; ///< Optional
    /** Optional. For private chats, the first audio added to the profile of the user. */
    std::shared_ptr<Audio> first_profile_audio; ///< Optional
    /** Optional. The color scheme based on a unique gift that must be used for the chat's name, message replies and link previe. */
    std::shared_ptr<UniqueGiftColors> unique_gift_colors; ///< Optional
    /** Optional. The number of Telegram Stars a general user have to pay to send a message to the chat. */
    std::optional<int64_t> paid_message_star_count; ///< Optional
};

/**
 * This object represents a message.
 * @see https://core.telegram.org/bots/api#message
 */
struct Message {
    /** Unique message identifier inside this chat. */
    int64_t message_id{0};
    /** Optional. Unique identifier of a message thread or forum topic to which the message belongs; for supergroups and private. */
    std::optional<int64_t> message_thread_id; ///< Optional
    /** Optional. Information about the direct messages chat topic that contains the message. */
    std::shared_ptr<DirectMessagesTopic> direct_messages_topic; ///< Optional
    /** Optional. Sender of the message; may be empty for messages sent to channels. */
    std::shared_ptr<User> from; ///< Optional
    /** Optional. Sender of the message when sent on behalf of a chat. */
    std::shared_ptr<Chat> sender_chat; ///< Optional
    /** Optional. If the sender of the message boosted the chat, the number of boosts added by the user. */
    std::optional<int64_t> sender_boost_count; ///< Optional
    /** Optional. The bot that actually sent the message on behalf of the business account. */
    std::shared_ptr<User> sender_business_bot; ///< Optional
    /** Optional. Tag or custom title of the sender of the message; for supergroups only. */
    std::optional<std::string> sender_tag; ///< Optional
    /** Date the message was sent in Unix time. */
    int64_t date{0};
    /** Optional. The unique identifier for the guest query. */
    std::optional<std::string> guest_query_id; ///< Optional
    /** Optional. Unique identifier of the business connection from which the message was received. */
    std::optional<std::string> business_connection_id; ///< Optional
    /** Chat the message belongs to. */
    std::shared_ptr<Chat> chat;
    /** Optional. Information about the original message for forwarded messages. */
    std::optional<MessageOrigin> forward_origin; ///< Optional
    /** Optional. True , if the message is sent to a topic in a forum supergroup or a private chat with the bot. */
    std::optional<bool> is_topic_message; ///< Optional
    /** Optional. True , if the message is a channel post that was automatically forwarded to the connected discussion group. */
    std::optional<bool> is_automatic_forward; ///< Optional
    /** Optional. For replies in the same chat and message thread, the original message. */
    std::shared_ptr<Message> reply_to_message; ///< Optional
    /** Optional. Information about the message that is being replied to, which may come from another chat or forum topic. */
    std::shared_ptr<ExternalReplyInfo> external_reply; ///< Optional
    /** Optional. For replies that quote part of the original message, the quoted part of the message. */
    std::shared_ptr<TextQuote> quote; ///< Optional
    /** Optional. For replies to a story, the original story. */
    std::shared_ptr<Story> reply_to_story; ///< Optional
    /** Optional. Identifier of the specific checklist task that is being replied to. */
    std::optional<int64_t> reply_to_checklist_task_id; ///< Optional
    /** Optional. Persistent identifier of the specific poll option that is being replied to. */
    std::optional<std::string> reply_to_poll_option_id; ///< Optional
    /** Optional. Bot through which the message was sent. */
    std::shared_ptr<User> via_bot; ///< Optional
    /** Optional. For a message sent by a guest bot, this is the user whose original message triggered the bot's response. */
    std::shared_ptr<User> guest_bot_caller_user; ///< Optional
    /** Optional. For a message sent by a guest bot, this is the chat whose original message triggered the bot's response. */
    std::shared_ptr<Chat> guest_bot_caller_chat; ///< Optional
    /** Optional. Date the message was last edited in Unix time. */
    std::optional<int64_t> edit_date; ///< Optional
    /** Optional. True , if the message can't be forwarded. */
    std::optional<bool> has_protected_content; ///< Optional
    /** Optional. True , if the message was sent by an implicit action, for example, as an away or a greeting business message, . */
    std::optional<bool> is_from_offline; ///< Optional
    /** Optional. True , if the message is a paid post. */
    std::optional<bool> is_paid_post; ///< Optional
    /** Optional. The unique identifier inside this chat of a media message group this message belongs to. */
    std::optional<std::string> media_group_id; ///< Optional
    /** Optional. Signature of the post author for messages in channels, or the custom title of an anonymous group administrator. */
    std::optional<std::string> author_signature; ///< Optional
    /** Optional. The number of Telegram Stars that were paid by the sender of the message to send it. */
    std::optional<int64_t> paid_star_count; ///< Optional
    /** Optional. For text messages, the actual UTF-8 text of the message. */
    std::optional<std::string> text; ///< Optional
    /** Optional. For text messages, special entities like usernames, URLs, bot commands, etc. */
    std::vector<std::shared_ptr<MessageEntity>> entities; ///< Optional
    /** Optional. Options used for link preview generation for the message, if it is a text message and link preview options wer. */
    std::shared_ptr<LinkPreviewOptions> link_preview_options; ///< Optional
    /** Optional. Information about suggested post parameters if the message is a suggested post in a channel direct messages ch. */
    std::shared_ptr<SuggestedPostInfo> suggested_post_info; ///< Optional
    /** Optional. Unique identifier of the message effect added to the message. */
    std::optional<std::string> effect_id; ///< Optional
    /** Optional. Message is an animation, information about the animation. */
    std::shared_ptr<Animation> animation; ///< Optional
    /** Optional. Message is an audio file, information about the file. */
    std::shared_ptr<Audio> audio; ///< Optional
    /** Optional. Message is a general file, information about the file. */
    std::shared_ptr<Document> document; ///< Optional
    /** Optional. Message is a live photo, information about the live photo. */
    std::shared_ptr<LivePhoto> live_photo; ///< Optional
    /** Optional. Message contains paid media; information about the paid media. */
    std::shared_ptr<PaidMediaInfo> paid_media; ///< Optional
    /** Optional. Message is a photo, available sizes of the photo. */
    std::vector<std::shared_ptr<PhotoSize>> photo; ///< Optional
    /** Optional. Message is a sticker, information about the sticker. */
    std::shared_ptr<Sticker> sticker; ///< Optional
    /** Optional. Message is a forwarded story. */
    std::shared_ptr<Story> story; ///< Optional
    /** Optional. Message is a video, information about the video. */
    std::shared_ptr<Video> video; ///< Optional
    /** Optional. Message is a video note , information about the video message. */
    std::shared_ptr<VideoNote> video_note; ///< Optional
    /** Optional. Message is a voice message, information about the file. */
    std::shared_ptr<Voice> voice; ///< Optional
    /** Optional. Caption for the animation, audio, document, paid media, photo, video or voice. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. For messages with a caption, special entities like usernames, URLs, bot commands, etc. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. True , if the caption must be shown above the message media. */
    std::optional<bool> show_caption_above_media; ///< Optional
    /** Optional. True , if the message media is covered by a spoiler animation. */
    std::optional<bool> has_media_spoiler; ///< Optional
    /** Optional. Message is a checklist. */
    std::shared_ptr<Checklist> checklist; ///< Optional
    /** Optional. Message is a shared contact, information about the contact. */
    std::shared_ptr<Contact> contact; ///< Optional
    /** Optional. Message is a dice with random value. */
    std::shared_ptr<Dice> dice; ///< Optional
    /** Optional. Message is a game, information about the game. */
    std::shared_ptr<Game> game; ///< Optional
    /** Optional. Message is a native poll, information about the poll. */
    std::shared_ptr<Poll> poll; ///< Optional
    /** Optional. Message is a venue, information about the venue. */
    std::shared_ptr<Venue> venue; ///< Optional
    /** Optional. Message is a shared location, information about the location. */
    std::shared_ptr<Location> location; ///< Optional
    /** Optional. New members that were added to the group or supergroup and information about them (the bot itself may be one o. */
    std::vector<std::shared_ptr<User>> new_chat_members; ///< Optional
    /** Optional. A member was removed from the group, information about them (this member may be the bot itself). */
    std::shared_ptr<User> left_chat_member; ///< Optional
    /** Optional. Service message: chat owner has left. */
    std::shared_ptr<ChatOwnerLeft> chat_owner_left; ///< Optional
    /** Optional. Service message: chat owner has changed. */
    std::shared_ptr<ChatOwnerChanged> chat_owner_changed; ///< Optional
    /** Optional. A chat title was changed to this value. */
    std::optional<std::string> new_chat_title; ///< Optional
    /** Optional. A chat photo was change to this value. */
    std::vector<std::shared_ptr<PhotoSize>> new_chat_photo; ///< Optional
    /** Optional. Service message: the chat photo was deleted. */
    std::optional<bool> delete_chat_photo; ///< Optional
    /** Optional. Service message: the group has been created. */
    std::optional<bool> group_chat_created; ///< Optional
    /** Optional. Service message: the supergroup has been created. */
    std::optional<bool> supergroup_chat_created; ///< Optional
    /** Optional. Service message: the channel has been created. */
    std::optional<bool> channel_chat_created; ///< Optional
    /** Optional. Service message: auto-delete timer settings changed in the chat. */
    std::shared_ptr<MessageAutoDeleteTimerChanged> message_auto_delete_timer_changed; ///< Optional
    /** Optional. The group has been migrated to a supergroup with the specified identifier. */
    std::optional<int64_t> migrate_to_chat_id; ///< Optional
    /** Optional. The supergroup has been migrated from a group with the specified identifier. */
    std::optional<int64_t> migrate_from_chat_id; ///< Optional
    /** Optional. Specified message was pinned. */
    std::optional<MaybeInaccessibleMessage> pinned_message; ///< Optional
    /** Optional. Message is an invoice for a payment , information about the invoice. */
    std::shared_ptr<Invoice> invoice; ///< Optional
    /** Optional. Message is a service message about a successful payment, information about the payment. */
    std::shared_ptr<SuccessfulPayment> successful_payment; ///< Optional
    /** Optional. Message is a service message about a refunded payment, information about the payment. */
    std::shared_ptr<RefundedPayment> refunded_payment; ///< Optional
    /** Optional. Service message: users were shared with the bot. */
    std::shared_ptr<UsersShared> users_shared; ///< Optional
    /** Optional. Service message: a chat was shared with the bot. */
    std::shared_ptr<ChatShared> chat_shared; ///< Optional
    /** Optional. Service message: a regular gift was sent or received. */
    std::shared_ptr<GiftInfo> gift; ///< Optional
    /** Optional. Service message: a unique gift was sent or received. */
    std::shared_ptr<UniqueGiftInfo> unique_gift; ///< Optional
    /** Optional. Service message: upgrade of a gift was purchased after the gift was sent. */
    std::shared_ptr<GiftInfo> gift_upgrade_sent; ///< Optional
    /** Optional. The domain name of the website on which the user has logged in. */
    std::optional<std::string> connected_website; ///< Optional
    /** Optional. Service message: the user allowed the bot to write messages after adding it to the attachment or side menu, la. */
    std::shared_ptr<WriteAccessAllowed> write_access_allowed; ///< Optional
    /** Optional. Telegram Passport data. */
    std::shared_ptr<PassportData> passport_data; ///< Optional
    /** Optional. Service message. */
    std::shared_ptr<ProximityAlertTriggered> proximity_alert_triggered; ///< Optional
    /** Optional. Service message: user boosted the chat. */
    std::shared_ptr<ChatBoostAdded> boost_added; ///< Optional
    /** Optional. Service message: chat background set. */
    std::shared_ptr<ChatBackground> chat_background_set; ///< Optional
    /** Optional. Service message: some tasks in a checklist were marked as done or not done. */
    std::shared_ptr<ChecklistTasksDone> checklist_tasks_done; ///< Optional
    /** Optional. Service message: tasks were added to a checklist. */
    std::shared_ptr<ChecklistTasksAdded> checklist_tasks_added; ///< Optional
    /** Optional. Service message: the price for paid messages in the corresponding direct messages chat of a channel has change. */
    std::shared_ptr<DirectMessagePriceChanged> direct_message_price_changed; ///< Optional
    /** Optional. Service message: forum topic created. */
    std::shared_ptr<ForumTopicCreated> forum_topic_created; ///< Optional
    /** Optional. Service message: forum topic edited. */
    std::shared_ptr<ForumTopicEdited> forum_topic_edited; ///< Optional
    /** Optional. Service message: forum topic closed. */
    std::shared_ptr<ForumTopicClosed> forum_topic_closed; ///< Optional
    /** Optional. Service message: forum topic reopened. */
    std::shared_ptr<ForumTopicReopened> forum_topic_reopened; ///< Optional
    /** Optional. Service message: the 'General' forum topic hidden. */
    std::shared_ptr<GeneralForumTopicHidden> general_forum_topic_hidden; ///< Optional
    /** Optional. Service message: the 'General' forum topic unhidden. */
    std::shared_ptr<GeneralForumTopicUnhidden> general_forum_topic_unhidden; ///< Optional
    /** Optional. Service message: a scheduled giveaway was created. */
    std::shared_ptr<GiveawayCreated> giveaway_created; ///< Optional
    /** Optional. The message is a scheduled giveaway message. */
    std::shared_ptr<Giveaway> giveaway; ///< Optional
    /** Optional. A giveaway with public winners was completed. */
    std::shared_ptr<GiveawayWinners> giveaway_winners; ///< Optional
    /** Optional. Service message: a giveaway without public winners was completed. */
    std::shared_ptr<GiveawayCompleted> giveaway_completed; ///< Optional
    /** Optional. Service message: user created a bot that will be managed by the current bot. */
    std::shared_ptr<ManagedBotCreated> managed_bot_created; ///< Optional
    /** Optional. Service message: the price for paid messages has changed in the chat. */
    std::shared_ptr<PaidMessagePriceChanged> paid_message_price_changed; ///< Optional
    /** Optional. Service message: answer option was added to a poll. */
    std::shared_ptr<PollOptionAdded> poll_option_added; ///< Optional
    /** Optional. Service message: answer option was deleted from a poll. */
    std::shared_ptr<PollOptionDeleted> poll_option_deleted; ///< Optional
    /** Optional. Service message: a suggested post was approved. */
    std::shared_ptr<SuggestedPostApproved> suggested_post_approved; ///< Optional
    /** Optional. Service message: approval of a suggested post has failed. */
    std::shared_ptr<SuggestedPostApprovalFailed> suggested_post_approval_failed; ///< Optional
    /** Optional. Service message: a suggested post was declined. */
    std::shared_ptr<SuggestedPostDeclined> suggested_post_declined; ///< Optional
    /** Optional. Service message: payment for a suggested post was received. */
    std::shared_ptr<SuggestedPostPaid> suggested_post_paid; ///< Optional
    /** Optional. Service message: payment for a suggested post was refunded. */
    std::shared_ptr<SuggestedPostRefunded> suggested_post_refunded; ///< Optional
    /** Optional. Service message: video chat scheduled. */
    std::shared_ptr<VideoChatScheduled> video_chat_scheduled; ///< Optional
    /** Optional. Service message: video chat started. */
    std::shared_ptr<VideoChatStarted> video_chat_started; ///< Optional
    /** Optional. Service message: video chat ended. */
    std::shared_ptr<VideoChatEnded> video_chat_ended; ///< Optional
    /** Optional. Service message: new participants invited to a video chat. */
    std::shared_ptr<VideoChatParticipantsInvited> video_chat_participants_invited; ///< Optional
    /** Optional. Service message: data sent by a Web App. */
    std::shared_ptr<WebAppData> web_app_data; ///< Optional
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
};

/**
 * This object represents a unique message identifier.
 * @see https://core.telegram.org/bots/api#messageid
 */
struct MessageId {
    /** Unique message identifier. */
    int64_t message_id{0};
};

/**
 * This object describes a message that was deleted or is otherwise inaccessible to the bot.
 * @see https://core.telegram.org/bots/api#inaccessiblemessage
 */
struct InaccessibleMessage {
    /** Chat the message belonged to. */
    std::shared_ptr<Chat> chat;
    /** Unique message identifier inside the chat. */
    int64_t message_id{0};
    /** Always 0. */
    int64_t date{0};
};

/**
 * This object represents one special entity in a text message. For example, hashtags, usernames,
 * URLs, etc.
 * @see https://core.telegram.org/bots/api#messageentity
 */
struct MessageEntity {
    /** Type of the entity. */
    std::string type{""};
    /** Offset in UTF-16 code units to the start of the entity. */
    int64_t offset{0};
    /** Length of the entity in UTF-16 code units. */
    int64_t length{0};
    /** Optional. For 'text_link' only, URL that will be opened after user taps on the text. */
    std::optional<std::string> url; ///< Optional
    /** Optional. For 'text_mention' only, the mentioned user. */
    std::shared_ptr<User> user; ///< Optional
    /** Optional. For 'pre' only, the programming language of the entity text. */
    std::optional<std::string> language; ///< Optional
    /** Optional. For 'custom_emoji' only, unique identifier of the custom emoji. */
    std::optional<std::string> custom_emoji_id; ///< Optional
    /** Optional. For 'date_time' only, the Unix time associated with the entity. */
    std::optional<int64_t> unix_time; ///< Optional
    /** Optional. For 'date_time' only, the string that defines the formatting of the date and time. */
    std::optional<std::string> date_time_format; ///< Optional
};

/**
 * This object contains information about the quoted part of a message that is replied to by the
 * given message.
 * @see https://core.telegram.org/bots/api#textquote
 */
struct TextQuote {
    /** Text of the quoted part of a message that is replied to by the given message. */
    std::string text{""};
    /** Optional. Special entities that appear in the quote. */
    std::vector<std::shared_ptr<MessageEntity>> entities; ///< Optional
    /** Approximate quote position in the original message in UTF-16 code units as specified by the sender. */
    int64_t position{0};
    /** Optional. True , if the quote was chosen manually by the message sender. */
    std::optional<bool> is_manual; ///< Optional
};

/**
 * This object contains information about a message that is being replied to, which may come from
 * another chat or forum topic.
 * @see https://core.telegram.org/bots/api#externalreplyinfo
 */
struct ExternalReplyInfo {
    /** Origin of the message replied to by the given message. */
    MessageOrigin origin{};
    /** Optional. Chat the original message belongs to. */
    std::shared_ptr<Chat> chat; ///< Optional
    /** Optional. Unique message identifier inside the original chat. */
    std::optional<int64_t> message_id; ///< Optional
    /** Optional. Options used for link preview generation for the original message, if it is a text message. */
    std::shared_ptr<LinkPreviewOptions> link_preview_options; ///< Optional
    /** Optional. Message is an animation, information about the animation. */
    std::shared_ptr<Animation> animation; ///< Optional
    /** Optional. Message is an audio file, information about the file. */
    std::shared_ptr<Audio> audio; ///< Optional
    /** Optional. Message is a general file, information about the file. */
    std::shared_ptr<Document> document; ///< Optional
    /** Optional. Message is a live photo, information about the live photo. */
    std::shared_ptr<LivePhoto> live_photo; ///< Optional
    /** Optional. Message contains paid media; information about the paid media. */
    std::shared_ptr<PaidMediaInfo> paid_media; ///< Optional
    /** Optional. Message is a photo, available sizes of the photo. */
    std::vector<std::shared_ptr<PhotoSize>> photo; ///< Optional
    /** Optional. Message is a sticker, information about the sticker. */
    std::shared_ptr<Sticker> sticker; ///< Optional
    /** Optional. Message is a forwarded story. */
    std::shared_ptr<Story> story; ///< Optional
    /** Optional. Message is a video, information about the video. */
    std::shared_ptr<Video> video; ///< Optional
    /** Optional. Message is a video note , information about the video message. */
    std::shared_ptr<VideoNote> video_note; ///< Optional
    /** Optional. Message is a voice message, information about the file. */
    std::shared_ptr<Voice> voice; ///< Optional
    /** Optional. True , if the message media is covered by a spoiler animation. */
    std::optional<bool> has_media_spoiler; ///< Optional
    /** Optional. Message is a checklist. */
    std::shared_ptr<Checklist> checklist; ///< Optional
    /** Optional. Message is a shared contact, information about the contact. */
    std::shared_ptr<Contact> contact; ///< Optional
    /** Optional. Message is a dice with random value. */
    std::shared_ptr<Dice> dice; ///< Optional
    /** Optional. Message is a game, information about the game. */
    std::shared_ptr<Game> game; ///< Optional
    /** Optional. Message is a scheduled giveaway, information about the giveaway. */
    std::shared_ptr<Giveaway> giveaway; ///< Optional
    /** Optional. A giveaway with public winners was completed. */
    std::shared_ptr<GiveawayWinners> giveaway_winners; ///< Optional
    /** Optional. Message is an invoice for a payment , information about the invoice. */
    std::shared_ptr<Invoice> invoice; ///< Optional
    /** Optional. Message is a shared location, information about the location. */
    std::shared_ptr<Location> location; ///< Optional
    /** Optional. Message is a native poll, information about the poll. */
    std::shared_ptr<Poll> poll; ///< Optional
    /** Optional. Message is a venue, information about the venue. */
    std::shared_ptr<Venue> venue; ///< Optional
};

/**
 * Describes reply parameters for the message that is being sent.
 * @see https://core.telegram.org/bots/api#replyparameters
 */
struct ReplyParameters {
    /** Identifier of the message that will be replied to in the current chat, or in the chat chat_id if it is specified. */
    int64_t message_id{0};
    /** Optional. If the message to be replied to is from a different chat, unique identifier for the chat or username of the bo. */
    std::optional<ChatId> chat_id{}; ///< Optional
    /** Optional. Pass True if the message should be sent even if the specified message to be replied to is not found. */
    std::optional<bool> allow_sending_without_reply; ///< Optional
    /** Optional. Quoted part of the message to be replied to; 0-1024 characters after entities parsing. */
    std::optional<std::string> quote; ///< Optional
    /** Optional. Mode for parsing entities in the quote. */
    std::optional<std::string> quote_parse_mode; ///< Optional
    /** Optional. A JSON-serialized list of special entities that appear in the quote. */
    std::vector<std::shared_ptr<MessageEntity>> quote_entities; ///< Optional
    /** Optional. Position of the quote in the original message in UTF-16 code units. */
    std::optional<int64_t> quote_position; ///< Optional
    /** Optional. Identifier of the specific checklist task to be replied to. */
    std::optional<int64_t> checklist_task_id; ///< Optional
    /** Optional. Persistent identifier of the specific poll option to be replied to. */
    std::optional<std::string> poll_option_id; ///< Optional
};

/**
 * The message was originally sent by a known user.
 * @see https://core.telegram.org/bots/api#messageoriginuser
 */
struct MessageOriginUser {
    /** Type of the message origin, always 'user'. */
    std::string type{""};
    /** Date the message was sent originally in Unix time. */
    int64_t date{0};
    /** User that sent the message originally. */
    std::shared_ptr<User> sender_user;
};

/**
 * The message was originally sent by an unknown user.
 * @see https://core.telegram.org/bots/api#messageoriginhiddenuser
 */
struct MessageOriginHiddenUser {
    /** Type of the message origin, always 'hidden_user'. */
    std::string type{""};
    /** Date the message was sent originally in Unix time. */
    int64_t date{0};
    /** Name of the user that sent the message originally. */
    std::string sender_user_name{""};
};

/**
 * The message was originally sent on behalf of a chat to a group chat.
 * @see https://core.telegram.org/bots/api#messageoriginchat
 */
struct MessageOriginChat {
    /** Type of the message origin, always 'chat'. */
    std::string type{""};
    /** Date the message was sent originally in Unix time. */
    int64_t date{0};
    /** Chat that sent the message originally. */
    std::shared_ptr<Chat> sender_chat;
    /** Optional. For messages originally sent by an anonymous chat administrator, original message author signature. */
    std::optional<std::string> author_signature; ///< Optional
};

/**
 * The message was originally sent to a channel chat.
 * @see https://core.telegram.org/bots/api#messageoriginchannel
 */
struct MessageOriginChannel {
    /** Type of the message origin, always 'channel'. */
    std::string type{""};
    /** Date the message was sent originally in Unix time. */
    int64_t date{0};
    /** Channel chat to which the message was originally sent. */
    std::shared_ptr<Chat> chat;
    /** Unique message identifier inside the chat. */
    int64_t message_id{0};
    /** Optional. Signature of the original post author. */
    std::optional<std::string> author_signature; ///< Optional
};

/**
 * This object represents one size of a photo or a file / sticker thumbnail.
 * @see https://core.telegram.org/bots/api#photosize
 */
struct PhotoSize {
    /** Identifier for this file, which can be used to download or reuse the file. */
    std::string file_id{""};
    /** Unique identifier for this file, which is supposed to be the same over time and for different bots. */
    std::string file_unique_id{""};
    /** Photo width. */
    int64_t width{0};
    /** Photo height. */
    int64_t height{0};
    /** Optional. File size in bytes. */
    std::optional<int64_t> file_size; ///< Optional
};

/**
 * This object represents an animation file (GIF or H.264/MPEG-4 AVC video without sound).
 * @see https://core.telegram.org/bots/api#animation
 */
struct Animation {
    /** Identifier for this file, which can be used to download or reuse the file. */
    std::string file_id{""};
    /** Unique identifier for this file, which is supposed to be the same over time and for different bots. */
    std::string file_unique_id{""};
    /** Video width as defined by the sender. */
    int64_t width{0};
    /** Video height as defined by the sender. */
    int64_t height{0};
    /** Duration of the video in seconds as defined by the sender. */
    int64_t duration{0};
    /** Optional. Animation thumbnail as defined by the sender. */
    std::shared_ptr<PhotoSize> thumbnail; ///< Optional
    /** Optional. Original animation filename as defined by the sender. */
    std::optional<std::string> file_name; ///< Optional
    /** Optional. MIME type of the file as defined by the sender. */
    std::optional<std::string> mime_type; ///< Optional
    /** Optional. File size in bytes. */
    std::optional<int64_t> file_size; ///< Optional
};

/**
 * This object represents an audio file to be treated as music by the Telegram clients.
 * @see https://core.telegram.org/bots/api#audio
 */
struct Audio {
    /** Identifier for this file, which can be used to download or reuse the file. */
    std::string file_id{""};
    /** Unique identifier for this file, which is supposed to be the same over time and for different bots. */
    std::string file_unique_id{""};
    /** Duration of the audio in seconds as defined by the sender. */
    int64_t duration{0};
    /** Optional. Performer of the audio as defined by the sender or by audio tags. */
    std::optional<std::string> performer; ///< Optional
    /** Optional. Title of the audio as defined by the sender or by audio tags. */
    std::optional<std::string> title; ///< Optional
    /** Optional. Original filename as defined by the sender. */
    std::optional<std::string> file_name; ///< Optional
    /** Optional. MIME type of the file as defined by the sender. */
    std::optional<std::string> mime_type; ///< Optional
    /** Optional. File size in bytes. */
    std::optional<int64_t> file_size; ///< Optional
    /** Optional. Thumbnail of the album cover to which the music file belongs. */
    std::shared_ptr<PhotoSize> thumbnail; ///< Optional
};

/**
 * This object represents a general file (as opposed to photos, voice messages and audio files).
 * @see https://core.telegram.org/bots/api#document
 */
struct Document {
    /** Identifier for this file, which can be used to download or reuse the file. */
    std::string file_id{""};
    /** Unique identifier for this file, which is supposed to be the same over time and for different bots. */
    std::string file_unique_id{""};
    /** Optional. Document thumbnail as defined by the sender. */
    std::shared_ptr<PhotoSize> thumbnail; ///< Optional
    /** Optional. Original filename as defined by the sender. */
    std::optional<std::string> file_name; ///< Optional
    /** Optional. MIME type of the file as defined by the sender. */
    std::optional<std::string> mime_type; ///< Optional
    /** Optional. File size in bytes. */
    std::optional<int64_t> file_size; ///< Optional
};

/**
 * This object represents a live photo.
 * @see https://core.telegram.org/bots/api#livephoto
 */
struct LivePhoto {
    /** Optional. Available sizes of the corresponding static photo. */
    std::vector<std::shared_ptr<PhotoSize>> photo; ///< Optional
    /** Identifier for the video file which can be used to download or reuse the file. */
    std::string file_id{""};
    /** Unique identifier for the video file which is supposed to be the same over time and for different bots. */
    std::string file_unique_id{""};
    /** Video width as defined by the sender. */
    int64_t width{0};
    /** Video height as defined by the sender. */
    int64_t height{0};
    /** Duration of the video in seconds as defined by the sender. */
    int64_t duration{0};
    /** Optional. MIME type of the file as defined by the sender. */
    std::optional<std::string> mime_type; ///< Optional
    /** Optional. File size in bytes. */
    std::optional<int64_t> file_size; ///< Optional
};

/**
 * This object represents a story.
 * @see https://core.telegram.org/bots/api#story
 */
struct Story {
    /** Chat that posted the story. */
    std::shared_ptr<Chat> chat;
    /** Unique identifier for the story in the chat. */
    int64_t id{0};
};

/**
 * This object represents a video file of a specific quality.
 * @see https://core.telegram.org/bots/api#videoquality
 */
struct VideoQuality {
    /** Identifier for this file, which can be used to download or reuse the file. */
    std::string file_id{""};
    /** Unique identifier for this file, which is supposed to be the same over time and for different bots. */
    std::string file_unique_id{""};
    /** Video width. */
    int64_t width{0};
    /** Video height. */
    int64_t height{0};
    /** Codec that was used to encode the video, for example, 'h264', 'h265', or 'av01'. */
    std::string codec{""};
    /** Optional. File size in bytes. */
    std::optional<int64_t> file_size; ///< Optional
};

/**
 * This object represents a video file.
 * @see https://core.telegram.org/bots/api#video
 */
struct Video {
    /** Identifier for this file, which can be used to download or reuse the file. */
    std::string file_id{""};
    /** Unique identifier for this file, which is supposed to be the same over time and for different bots. */
    std::string file_unique_id{""};
    /** Video width as defined by the sender. */
    int64_t width{0};
    /** Video height as defined by the sender. */
    int64_t height{0};
    /** Duration of the video in seconds as defined by the sender. */
    int64_t duration{0};
    /** Optional. Video thumbnail. */
    std::shared_ptr<PhotoSize> thumbnail; ///< Optional
    /** Optional. Available sizes of the cover of the video in the message. */
    std::vector<std::shared_ptr<PhotoSize>> cover; ///< Optional
    /** Optional. Timestamp in seconds from which the video will play in the message. */
    std::optional<int64_t> start_timestamp; ///< Optional
    /** Optional. List of available qualities of the video. */
    std::vector<std::shared_ptr<VideoQuality>> qualities; ///< Optional
    /** Optional. Original filename as defined by the sender. */
    std::optional<std::string> file_name; ///< Optional
    /** Optional. MIME type of the file as defined by the sender. */
    std::optional<std::string> mime_type; ///< Optional
    /** Optional. File size in bytes. */
    std::optional<int64_t> file_size; ///< Optional
};

/**
 * This object represents a video message (available in Telegram apps as of v.4.0).
 * @see https://core.telegram.org/bots/api#videonote
 */
struct VideoNote {
    /** Identifier for this file, which can be used to download or reuse the file. */
    std::string file_id{""};
    /** Unique identifier for this file, which is supposed to be the same over time and for different bots. */
    std::string file_unique_id{""};
    /** Video width and height (diameter of the video message) as defined by the sender. */
    int64_t length{0};
    /** Duration of the video in seconds as defined by the sender. */
    int64_t duration{0};
    /** Optional. Video thumbnail. */
    std::shared_ptr<PhotoSize> thumbnail; ///< Optional
    /** Optional. File size in bytes. */
    std::optional<int64_t> file_size; ///< Optional
};

/**
 * This object represents a voice note.
 * @see https://core.telegram.org/bots/api#voice
 */
struct Voice {
    /** Identifier for this file, which can be used to download or reuse the file. */
    std::string file_id{""};
    /** Unique identifier for this file, which is supposed to be the same over time and for different bots. */
    std::string file_unique_id{""};
    /** Duration of the audio in seconds as defined by the sender. */
    int64_t duration{0};
    /** Optional. MIME type of the file as defined by the sender. */
    std::optional<std::string> mime_type; ///< Optional
    /** Optional. File size in bytes. */
    std::optional<int64_t> file_size; ///< Optional
};

/**
 * Describes the paid media added to a message.
 * @see https://core.telegram.org/bots/api#paidmediainfo
 */
struct PaidMediaInfo {
    /** The number of Telegram Stars that must be paid to buy access to the media. */
    int64_t star_count{0};
    /** Information about the paid media. */
    std::vector<PaidMedia> paid_media;
};

/**
 * The paid media is a live photo.
 * @see https://core.telegram.org/bots/api#paidmedialivephoto
 */
struct PaidMediaLivePhoto {
    /** Type of the paid media, always 'live_photo'. */
    std::string type{""};
    /** The photo. */
    std::shared_ptr<LivePhoto> live_photo;
};

/**
 * The paid media is a photo.
 * @see https://core.telegram.org/bots/api#paidmediaphoto
 */
struct PaidMediaPhoto {
    /** Type of the paid media, always 'photo'. */
    std::string type{""};
    /** The photo. */
    std::vector<std::shared_ptr<PhotoSize>> photo;
};

/**
 * The paid media isn't available before the payment.
 * @see https://core.telegram.org/bots/api#paidmediapreview
 */
struct PaidMediaPreview {
    /** Type of the paid media, always 'preview'. */
    std::string type{""};
    /** Optional. Media width as defined by the sender. */
    std::optional<int64_t> width; ///< Optional
    /** Optional. Media height as defined by the sender. */
    std::optional<int64_t> height; ///< Optional
    /** Optional. Duration of the media in seconds as defined by the sender. */
    std::optional<int64_t> duration; ///< Optional
};

/**
 * The paid media is a video.
 * @see https://core.telegram.org/bots/api#paidmediavideo
 */
struct PaidMediaVideo {
    /** Type of the paid media, always 'video'. */
    std::string type{""};
    /** The video. */
    std::shared_ptr<Video> video;
};

/**
 * This object represents a phone contact.
 * @see https://core.telegram.org/bots/api#contact
 */
struct Contact {
    /** Contact's phone number. */
    std::string phone_number{""};
    /** Contact's first name. */
    std::string first_name{""};
    /** Optional. Contact's last name. */
    std::optional<std::string> last_name; ///< Optional
    /** Optional. Contact's user identifier in Telegram. */
    std::optional<int64_t> user_id; ///< Optional
    /** Optional. Additional data about the contact in the form of a vCard. */
    std::optional<std::string> vcard; ///< Optional

    // ── Extension methods ──────
    std::string full_name() const {
        if (last_name.has_value() && !last_name->empty())
          return first_name + " " + *last_name;
        return first_name;
    }

};

/**
 * This object represents an animated emoji that displays a random value.
 * @see https://core.telegram.org/bots/api#dice
 */
struct Dice {
    /** Emoji on which the dice throw animation is based. */
    std::string emoji{""};
    /** Value of the dice, 1-6 for ' ', ' ' and ' ' base emoji, 1-5 for ' ' and ' ' base emoji, 1-64 for ' ' base emoji. */
    int64_t value{0};
};

/**
 * At most one of the optional fields can be present in any given object.
 * @see https://core.telegram.org/bots/api#pollmedia
 */
struct PollMedia {
    /** Optional. Media is an animation, information about the animation. */
    std::shared_ptr<Animation> animation; ///< Optional
    /** Optional. Media is an audio file, information about the file; currently, can't be received in a poll option. */
    std::shared_ptr<Audio> audio; ///< Optional
    /** Optional. Media is a general file, information about the file; currently, can't be received in a poll option. */
    std::shared_ptr<Document> document; ///< Optional
    /** Optional. Media is a live photo, information about the live photo. */
    std::shared_ptr<LivePhoto> live_photo; ///< Optional
    /** Optional. Media is a shared location, information about the location. */
    std::shared_ptr<Location> location; ///< Optional
    /** Optional. Media is a photo, available sizes of the photo. */
    std::vector<std::shared_ptr<PhotoSize>> photo; ///< Optional
    /** Optional. Media is a sticker, information about the sticker; currently, for poll options only. */
    std::shared_ptr<Sticker> sticker; ///< Optional
    /** Optional. Media is a venue, information about the venue. */
    std::shared_ptr<Venue> venue; ///< Optional
    /** Optional. Media is a video, information about the video. */
    std::shared_ptr<Video> video; ///< Optional
};

/**
 * This object contains information about one answer option in a poll.
 * @see https://core.telegram.org/bots/api#polloption
 */
struct PollOption {
    /** Unique identifier of the option, persistent on option addition and deletion. */
    std::string persistent_id{""};
    /** Option text, 1-100 characters. */
    std::string text{""};
    /** Optional. Special entities that appear in the option text . */
    std::vector<std::shared_ptr<MessageEntity>> text_entities; ///< Optional
    /** Optional. Media added to the poll option. */
    std::shared_ptr<PollMedia> media; ///< Optional
    /** Number of users who voted for this option; may be 0 if unknown. */
    int64_t voter_count{0};
    /** Optional. User who added the option; omitted if the option wasn't added by a user after poll creation. */
    std::shared_ptr<User> added_by_user; ///< Optional
    /** Optional. Chat that added the option; omitted if the option wasn't added by a chat after poll creation. */
    std::shared_ptr<Chat> added_by_chat; ///< Optional
    /** Optional. Point in time (Unix timestamp) when the option was added; omitted if the option existed in the original poll. */
    std::optional<int64_t> addition_date; ///< Optional
};

/**
 * This object contains information about one answer option in a poll to be sent.
 * @see https://core.telegram.org/bots/api#inputpolloption
 */
struct InputPollOption {
    /** Option text, 1-100 characters. */
    std::string text{""};
    /** Optional. Mode for parsing entities in the text. */
    std::optional<std::string> text_parse_mode; ///< Optional
    /** Optional. A JSON-serialized list of special entities that appear in the poll option text. */
    std::vector<std::shared_ptr<MessageEntity>> text_entities; ///< Optional
    /** Optional. Media added to the poll option. */
    std::optional<InputPollOptionMedia> media; ///< Optional
};

/**
 * This object represents an answer of a user in a non-anonymous poll.
 * @see https://core.telegram.org/bots/api#pollanswer
 */
struct PollAnswer {
    /** Unique poll identifier. */
    std::string poll_id{""};
    /** Optional. The chat that changed the answer to the poll, if the voter is anonymous. */
    std::shared_ptr<Chat> voter_chat; ///< Optional
    /** Optional. The user that changed the answer to the poll, if the voter isn't anonymous. */
    std::shared_ptr<User> user; ///< Optional
    /** 0-based identifiers of chosen answer options. */
    std::vector<int64_t> option_ids;
    /** Persistent identifiers of the chosen answer options. */
    std::vector<std::string> option_persistent_ids;
};

/**
 * This object contains information about a poll.
 * @see https://core.telegram.org/bots/api#poll
 */
struct Poll {
    /** Unique poll identifier. */
    std::string id{""};
    /** Poll question, 1-300 characters. */
    std::string question{""};
    /** Optional. Special entities that appear in the question . */
    std::vector<std::shared_ptr<MessageEntity>> question_entities; ///< Optional
    /** List of poll options. */
    std::vector<std::shared_ptr<PollOption>> options;
    /** Total number of users that voted in the poll. */
    int64_t total_voter_count{0};
    /** True , if the poll is closed. */
    bool is_closed{false};
    /** True , if the poll is anonymous. */
    bool is_anonymous{false};
    /** Poll type, currently can be 'regular' or 'quiz'. */
    std::string type{""};
    /** True , if the poll allows multiple answers. */
    bool allows_multiple_answers{false};
    /** True , if the poll allows to change the chosen answer options. */
    bool allows_revoting{false};
    /** True if voting is limited to users who have been members of the chat where the poll was originally sent for more than 24. */
    bool members_only{false};
    /** Optional. A list of two-letter ISO 3166-1 alpha-2 country codes indicating the countries from which users can vote in th. */
    std::vector<std::string> country_codes; ///< Optional
    /** Optional. Array of 0-based identifiers of the correct answer options. */
    std::vector<int64_t> correct_option_ids; ///< Optional
    /** Optional. Text that is shown when a user chooses an incorrect answer or taps on the lamp icon in a quiz-style poll, 0-20. */
    std::optional<std::string> explanation; ///< Optional
    /** Optional. Special entities like usernames, URLs, bot commands, etc. */
    std::vector<std::shared_ptr<MessageEntity>> explanation_entities; ///< Optional
    /** Optional. Media added to the quiz explanation. */
    std::shared_ptr<PollMedia> explanation_media; ///< Optional
    /** Optional. Amount of time in seconds the poll will be active after creation. */
    std::optional<int64_t> open_period; ///< Optional
    /** Optional. Point in time (Unix timestamp) when the poll will be automatically closed. */
    std::optional<int64_t> close_date; ///< Optional
    /** Optional. Description of the poll; for polls inside the Message object only. */
    std::optional<std::string> description; ///< Optional
    /** Optional. Special entities like usernames, URLs, bot commands, etc. */
    std::vector<std::shared_ptr<MessageEntity>> description_entities; ///< Optional
    /** Optional. Media added to the poll description; for polls inside the Message object only. */
    std::shared_ptr<PollMedia> media; ///< Optional
};

/**
 * Describes a task in a checklist.
 * @see https://core.telegram.org/bots/api#checklisttask
 */
struct ChecklistTask {
    /** Unique identifier of the task. */
    int64_t id{0};
    /** Text of the task. */
    std::string text{""};
    /** Optional. Special entities that appear in the task text. */
    std::vector<std::shared_ptr<MessageEntity>> text_entities; ///< Optional
    /** Optional. User that completed the task; omitted if the task wasn't completed by a user. */
    std::shared_ptr<User> completed_by_user; ///< Optional
    /** Optional. Chat that completed the task; omitted if the task wasn't completed by a chat. */
    std::shared_ptr<Chat> completed_by_chat; ///< Optional
    /** Optional. Point in time (Unix timestamp) when the task was completed; 0 if the task wasn't completed. */
    std::optional<int64_t> completion_date; ///< Optional
};

/**
 * Describes a checklist.
 * @see https://core.telegram.org/bots/api#checklist
 */
struct Checklist {
    /** Title of the checklist. */
    std::string title{""};
    /** Optional. Special entities that appear in the checklist title. */
    std::vector<std::shared_ptr<MessageEntity>> title_entities; ///< Optional
    /** List of tasks in the checklist. */
    std::vector<std::shared_ptr<ChecklistTask>> tasks;
    /** Optional. True , if users other than the creator of the list can add tasks to the list. */
    std::optional<bool> others_can_add_tasks; ///< Optional
    /** Optional. True , if users other than the creator of the list can mark tasks as done or not done. */
    std::optional<bool> others_can_mark_tasks_as_done; ///< Optional
};

/**
 * Describes a task to add to a checklist.
 * @see https://core.telegram.org/bots/api#inputchecklisttask
 */
struct InputChecklistTask {
    /** Unique identifier of the task; must be positive and unique among all task identifiers currently present in the checklist. */
    int64_t id{0};
    /** Text of the task; 1-100 characters after entities parsing. */
    std::string text{""};
    /** Optional. Mode for parsing entities in the text. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the text, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> text_entities; ///< Optional
};

/**
 * Describes a checklist to create.
 * @see https://core.telegram.org/bots/api#inputchecklist
 */
struct InputChecklist {
    /** Title of the checklist; 1-255 characters after entities parsing. */
    std::string title{""};
    /** Optional. Mode for parsing entities in the title. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the title, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> title_entities; ///< Optional
    /** List of 1-30 tasks in the checklist. */
    std::vector<std::shared_ptr<InputChecklistTask>> tasks;
    /** Optional. Pass True if other users can add tasks to the checklist. */
    std::optional<bool> others_can_add_tasks; ///< Optional
    /** Optional. Pass True if other users can mark tasks as done or not done in the checklist. */
    std::optional<bool> others_can_mark_tasks_as_done; ///< Optional
};

/**
 * Describes a service message about checklist tasks marked as done or not done.
 * @see https://core.telegram.org/bots/api#checklisttasksdone
 */
struct ChecklistTasksDone {
    /** Optional. Message containing the checklist whose tasks were marked as done or not done. */
    std::shared_ptr<Message> checklist_message; ///< Optional
    /** Optional. Identifiers of the tasks that were marked as done. */
    std::vector<int64_t> marked_as_done_task_ids; ///< Optional
    /** Optional. Identifiers of the tasks that were marked as not done. */
    std::vector<int64_t> marked_as_not_done_task_ids; ///< Optional
};

/**
 * Describes a service message about tasks added to a checklist.
 * @see https://core.telegram.org/bots/api#checklisttasksadded
 */
struct ChecklistTasksAdded {
    /** Optional. Message containing the checklist to which the tasks were added. */
    std::shared_ptr<Message> checklist_message; ///< Optional
    /** List of tasks added to the checklist. */
    std::vector<std::shared_ptr<ChecklistTask>> tasks;
};

/**
 * This object represents a point on the map.
 * @see https://core.telegram.org/bots/api#location
 */
struct Location {
    /** Latitude as defined by the sender. */
    double latitude{0.0};
    /** Longitude as defined by the sender. */
    double longitude{0.0};
    /** Optional. The radius of uncertainty for the location, measured in meters; 0-1500. */
    std::optional<double> horizontal_accuracy; ///< Optional
    /** Optional. Time relative to the message sending date, during which the location can be updated; in seconds. */
    std::optional<int64_t> live_period; ///< Optional
    /** Optional. The direction in which user is moving, in degrees; 1-360. */
    std::optional<int64_t> heading; ///< Optional
    /** Optional. The maximum distance for proximity alerts about approaching another chat member, in meters. */
    std::optional<int64_t> proximity_alert_radius; ///< Optional
};

/**
 * This object represents a venue.
 * @see https://core.telegram.org/bots/api#venue
 */
struct Venue {
    /** Venue location. */
    std::shared_ptr<Location> location;
    /** Name of the venue. */
    std::string title{""};
    /** Address of the venue. */
    std::string address{""};
    /** Optional. Foursquare identifier of the venue. */
    std::optional<std::string> foursquare_id; ///< Optional
    /** Optional. Foursquare type of the venue. */
    std::optional<std::string> foursquare_type; ///< Optional
    /** Optional. Google Places identifier of the venue. */
    std::optional<std::string> google_place_id; ///< Optional
    /** Optional. Google Places type of the venue. */
    std::optional<std::string> google_place_type; ///< Optional
};

/**
 * Describes data sent from a Web App to the bot.
 * @see https://core.telegram.org/bots/api#webappdata
 */
struct WebAppData {
    /** The data. */
    std::string data{""};
    /** Text of the web_app keyboard button from which the Web App was opened. */
    std::string button_text{""};
};

/**
 * This object represents the content of a service message, sent whenever a user in the chat
 * triggers a proximity alert set by another user.
 * @see https://core.telegram.org/bots/api#proximityalerttriggered
 */
struct ProximityAlertTriggered {
    /** User that triggered the alert. */
    std::shared_ptr<User> traveler;
    /** User that set the alert. */
    std::shared_ptr<User> watcher;
    /** The distance between the users. */
    int64_t distance{0};
};

/**
 * This object represents a service message about a change in auto-delete timer settings.
 * @see https://core.telegram.org/bots/api#messageautodeletetimerchanged
 */
struct MessageAutoDeleteTimerChanged {
    /** New auto-delete time for messages in the chat; in seconds. */
    int64_t message_auto_delete_time{0};
};

/**
 * This object contains information about the bot that was created to be managed by the current bot.
 * @see https://core.telegram.org/bots/api#managedbotcreated
 */
struct ManagedBotCreated {
    /** Information about the bot. */
    std::shared_ptr<User> bot;
};

/**
 * This object contains information about the creation, token update, or owner update of a bot that
 * is managed by the current bot.
 * @see https://core.telegram.org/bots/api#managedbotupdated
 */
struct ManagedBotUpdated {
    /** User that created the bot. */
    std::shared_ptr<User> user;
    /** Information about the bot. */
    std::shared_ptr<User> bot;
};

/**
 * Describes a service message about an option added to a poll.
 * @see https://core.telegram.org/bots/api#polloptionadded
 */
struct PollOptionAdded {
    /** Optional. Message containing the poll to which the option was added, if known. */
    std::optional<MaybeInaccessibleMessage> poll_message; ///< Optional
    /** Unique identifier of the added option. */
    std::string option_persistent_id{""};
    /** Option text. */
    std::string option_text{""};
    /** Optional. Special entities that appear in the option_text. */
    std::vector<std::shared_ptr<MessageEntity>> option_text_entities; ///< Optional
};

/**
 * Describes a service message about an option deleted from a poll.
 * @see https://core.telegram.org/bots/api#polloptiondeleted
 */
struct PollOptionDeleted {
    /** Optional. Message containing the poll from which the option was deleted, if known. */
    std::optional<MaybeInaccessibleMessage> poll_message; ///< Optional
    /** Unique identifier of the deleted option. */
    std::string option_persistent_id{""};
    /** Option text. */
    std::string option_text{""};
    /** Optional. Special entities that appear in the option_text. */
    std::vector<std::shared_ptr<MessageEntity>> option_text_entities; ///< Optional
};

/**
 * This object represents a service message about a user boosting a chat.
 * @see https://core.telegram.org/bots/api#chatboostadded
 */
struct ChatBoostAdded {
    /** Number of boosts added by the user. */
    int64_t boost_count{0};
};

/**
 * The background is filled using the selected color.
 * @see https://core.telegram.org/bots/api#backgroundfillsolid
 */
struct BackgroundFillSolid {
    /** Type of the background fill, always 'solid'. */
    std::string type{""};
    /** The color of the background fill in the RGB24 format. */
    int64_t color{0};
};

/**
 * The background is a gradient fill.
 * @see https://core.telegram.org/bots/api#backgroundfillgradient
 */
struct BackgroundFillGradient {
    /** Type of the background fill, always 'gradient'. */
    std::string type{""};
    /** Top color of the gradient in the RGB24 format. */
    int64_t top_color{0};
    /** Bottom color of the gradient in the RGB24 format. */
    int64_t bottom_color{0};
    /** Clockwise rotation angle of the background fill in degrees; 0-359. */
    int64_t rotation_angle{0};
};

/**
 * The background is a freeform gradient that rotates after every message in the chat.
 * @see https://core.telegram.org/bots/api#backgroundfillfreeformgradient
 */
struct BackgroundFillFreeformGradient {
    /** Type of the background fill, always 'freeform_gradient'. */
    std::string type{""};
    /** A list of the 3 or 4 base colors that are used to generate the freeform gradient in the RGB24 format. */
    std::vector<int64_t> colors;
};

/**
 * The background is automatically filled based on the selected colors.
 * @see https://core.telegram.org/bots/api#backgroundtypefill
 */
struct BackgroundTypeFill {
    /** Type of the background, always 'fill'. */
    std::string type{""};
    /** The background fill. */
    BackgroundFill fill{};
    /** Dimming of the background in dark themes, as a percentage; 0-100. */
    int64_t dark_theme_dimming{0};
};

/**
 * The background is a wallpaper in the JPEG format.
 * @see https://core.telegram.org/bots/api#backgroundtypewallpaper
 */
struct BackgroundTypeWallpaper {
    /** Type of the background, always 'wallpaper'. */
    std::string type{""};
    /** Document with the wallpaper. */
    std::shared_ptr<Document> document;
    /** Dimming of the background in dark themes, as a percentage; 0-100. */
    int64_t dark_theme_dimming{0};
    /** Optional. True , if the wallpaper is downscaled to fit in a 450x450 square and then box-blurred with radius 12. */
    std::optional<bool> is_blurred; ///< Optional
    /** Optional. True , if the background moves slightly when the device is tilted. */
    std::optional<bool> is_moving; ///< Optional
};

/**
 * The background is a .PNG or .TGV (gzipped subset of SVG with MIME type
 * 'application/x-tgwallpattern') pattern to be combined with the background fill chosen by the
 * user.
 * @see https://core.telegram.org/bots/api#backgroundtypepattern
 */
struct BackgroundTypePattern {
    /** Type of the background, always 'pattern'. */
    std::string type{""};
    /** Document with the pattern. */
    std::shared_ptr<Document> document;
    /** The background fill that is combined with the pattern. */
    BackgroundFill fill{};
    /** Intensity of the pattern when it is shown above the filled background; 0-100. */
    int64_t intensity{0};
    /** Optional. True , if the background fill must be applied only to the pattern itself. */
    std::optional<bool> is_inverted; ///< Optional
    /** Optional. True , if the background moves slightly when the device is tilted. */
    std::optional<bool> is_moving; ///< Optional
};

/**
 * The background is taken directly from a built-in chat theme.
 * @see https://core.telegram.org/bots/api#backgroundtypechattheme
 */
struct BackgroundTypeChatTheme {
    /** Type of the background, always 'chat_theme'. */
    std::string type{""};
    /** Name of the chat theme, which is usually an emoji. */
    std::string theme_name{""};
};

/**
 * This object represents a chat background.
 * @see https://core.telegram.org/bots/api#chatbackground
 */
struct ChatBackground {
    /** Type of the background. */
    BackgroundType type{};
};

/**
 * This object represents a service message about a new forum topic created in the chat.
 * @see https://core.telegram.org/bots/api#forumtopiccreated
 */
struct ForumTopicCreated {
    /** Name of the topic. */
    std::string name{""};
    /** Color of the topic icon in RGB format. */
    int64_t icon_color{0};
    /** Optional. Unique identifier of the custom emoji shown as the topic icon. */
    std::optional<std::string> icon_custom_emoji_id; ///< Optional
    /** Optional. True , if the name of the topic wasn't specified explicitly by its creator and likely needs to be changed by t. */
    std::optional<bool> is_name_implicit; ///< Optional
};

/**
 * This object represents a service message about a forum topic closed in the chat. Currently holds
 * no information.
 * @see https://core.telegram.org/bots/api#forumtopicclosed
 */
struct ForumTopicClosed {
};

/**
 * This object represents a service message about an edited forum topic.
 * @see https://core.telegram.org/bots/api#forumtopicedited
 */
struct ForumTopicEdited {
    /** Optional. New name of the topic, if it was edited. */
    std::optional<std::string> name; ///< Optional
    /** Optional. New identifier of the custom emoji shown as the topic icon, if it was edited; an empty string if the icon was . */
    std::optional<std::string> icon_custom_emoji_id; ///< Optional
};

/**
 * This object represents a service message about a forum topic reopened in the chat. Currently
 * holds no information.
 * @see https://core.telegram.org/bots/api#forumtopicreopened
 */
struct ForumTopicReopened {
};

/**
 * This object represents a service message about General forum topic hidden in the chat. Currently
 * holds no information.
 * @see https://core.telegram.org/bots/api#generalforumtopichidden
 */
struct GeneralForumTopicHidden {
};

/**
 * This object represents a service message about General forum topic unhidden in the chat.
 * Currently holds no information.
 * @see https://core.telegram.org/bots/api#generalforumtopicunhidden
 */
struct GeneralForumTopicUnhidden {
};

/**
 * This object contains information about a user that was shared with the bot using a
 * KeyboardButtonRequestUsers button.
 * @see https://core.telegram.org/bots/api#shareduser
 */
struct SharedUser {
    /** Identifier of the shared user. */
    int64_t user_id{0};
    /** Optional. First name of the user, if the name was requested by the bot. */
    std::optional<std::string> first_name; ///< Optional
    /** Optional. Last name of the user, if the name was requested by the bot. */
    std::optional<std::string> last_name; ///< Optional
    /** Optional. Username of the user, if the username was requested by the bot. */
    std::optional<std::string> username; ///< Optional
    /** Optional. Available sizes of the chat photo, if the photo was requested by the bot. */
    std::vector<std::shared_ptr<PhotoSize>> photo; ///< Optional
};

/**
 * This object contains information about the users whose identifiers were shared with the bot using
 * a KeyboardButtonRequestUsers button.
 * @see https://core.telegram.org/bots/api#usersshared
 */
struct UsersShared {
    /** Identifier of the request. */
    int64_t request_id{0};
    /** Information about users shared with the bot. */
    std::vector<std::shared_ptr<SharedUser>> users;
};

/**
 * This object contains information about a chat that was shared with the bot using a
 * KeyboardButtonRequestChat button.
 * @see https://core.telegram.org/bots/api#chatshared
 */
struct ChatShared {
    /** Identifier of the request. */
    int64_t request_id{0};
    /** Identifier of the shared chat. */
    int64_t chat_id{0};
    /** Optional. Title of the chat, if the title was requested by the bot. */
    std::optional<std::string> title; ///< Optional
    /** Optional. Username of the chat, if the username was requested by the bot and available. */
    std::optional<std::string> username; ///< Optional
    /** Optional. Available sizes of the chat photo, if the photo was requested by the bot. */
    std::vector<std::shared_ptr<PhotoSize>> photo; ///< Optional
};

/**
 * This object represents a service message about a user allowing a bot to write messages after
 * adding it to the attachment menu, launching a Web App from a link, or accepting an explicit
 * request from a Web App sent by the method requestWriteAccess.
 * @see https://core.telegram.org/bots/api#writeaccessallowed
 */
struct WriteAccessAllowed {
    /** Optional. True , if the access was granted after the user accepted an explicit request from a Web App sent by the method. */
    std::optional<bool> from_request; ///< Optional
    /** Optional. Name of the Web App, if the access was granted when the Web App was launched from a link. */
    std::optional<std::string> web_app_name; ///< Optional
    /** Optional. True , if the access was granted when the bot was added to the attachment or side menu. */
    std::optional<bool> from_attachment_menu; ///< Optional
};

/**
 * This object represents a service message about a video chat scheduled in the chat.
 * @see https://core.telegram.org/bots/api#videochatscheduled
 */
struct VideoChatScheduled {
    /** Point in time (Unix timestamp) when the video chat is supposed to be started by a chat administrator. */
    int64_t start_date{0};
};

/**
 * This object represents a service message about a video chat started in the chat. Currently holds
 * no information.
 * @see https://core.telegram.org/bots/api#videochatstarted
 */
struct VideoChatStarted {
};

/**
 * This object represents a service message about a video chat ended in the chat.
 * @see https://core.telegram.org/bots/api#videochatended
 */
struct VideoChatEnded {
    /** Video chat duration in seconds. */
    int64_t duration{0};
};

/**
 * This object represents a service message about new members invited to a video chat.
 * @see https://core.telegram.org/bots/api#videochatparticipantsinvited
 */
struct VideoChatParticipantsInvited {
    /** New members that were invited to the video chat. */
    std::vector<std::shared_ptr<User>> users;
};

/**
 * Describes a service message about a change in the price of paid messages within a chat.
 * @see https://core.telegram.org/bots/api#paidmessagepricechanged
 */
struct PaidMessagePriceChanged {
    /** The new number of Telegram Stars that must be paid by non-administrator users of the supergroup chat for each sent messa. */
    int64_t paid_message_star_count{0};
};

/**
 * Describes a service message about a change in the price of direct messages sent to a channel
 * chat.
 * @see https://core.telegram.org/bots/api#directmessagepricechanged
 */
struct DirectMessagePriceChanged {
    /** True , if direct messages are enabled for the channel chat; false otherwise. */
    bool are_direct_messages_enabled{false};
    /** Optional. The new number of Telegram Stars that must be paid by users for each direct message sent to the channel. */
    std::optional<int64_t> direct_message_star_count; ///< Optional
};

/**
 * Describes a service message about the approval of a suggested post.
 * @see https://core.telegram.org/bots/api#suggestedpostapproved
 */
struct SuggestedPostApproved {
    /** Optional. Message containing the suggested post. */
    std::shared_ptr<Message> suggested_post_message; ///< Optional
    /** Optional. Amount paid for the post. */
    std::shared_ptr<SuggestedPostPrice> price; ///< Optional
    /** Date when the post will be published. */
    int64_t send_date{0};
};

/**
 * Describes a service message about the failed approval of a suggested post. Currently, only caused
 * by insufficient user funds at the time of approval.
 * @see https://core.telegram.org/bots/api#suggestedpostapprovalfailed
 */
struct SuggestedPostApprovalFailed {
    /** Optional. Message containing the suggested post whose approval has failed. */
    std::shared_ptr<Message> suggested_post_message; ///< Optional
    /** Expected price of the post. */
    std::shared_ptr<SuggestedPostPrice> price;
};

/**
 * Describes a service message about the rejection of a suggested post.
 * @see https://core.telegram.org/bots/api#suggestedpostdeclined
 */
struct SuggestedPostDeclined {
    /** Optional. Message containing the suggested post. */
    std::shared_ptr<Message> suggested_post_message; ///< Optional
    /** Optional. Comment with which the post was declined. */
    std::optional<std::string> comment; ///< Optional
};

/**
 * Describes a service message about a successful payment for a suggested post.
 * @see https://core.telegram.org/bots/api#suggestedpostpaid
 */
struct SuggestedPostPaid {
    /** Optional. Message containing the suggested post. */
    std::shared_ptr<Message> suggested_post_message; ///< Optional
    /** Currency in which the payment was made. */
    std::string currency{""};
    /** Optional. The amount of the currency that was received by the channel in nanotoncoins; for payments in toncoins only. */
    std::optional<int64_t> amount; ///< Optional
    /** Optional. The amount of Telegram Stars that was received by the channel; for payments in Telegram Stars only. */
    std::shared_ptr<StarAmount> star_amount; ///< Optional
};

/**
 * Describes a service message about a payment refund for a suggested post.
 * @see https://core.telegram.org/bots/api#suggestedpostrefunded
 */
struct SuggestedPostRefunded {
    /** Optional. Message containing the suggested post. */
    std::shared_ptr<Message> suggested_post_message; ///< Optional
    /** Reason for the refund. */
    std::string reason{""};
};

/**
 * This object represents a service message about the creation of a scheduled giveaway.
 * @see https://core.telegram.org/bots/api#giveawaycreated
 */
struct GiveawayCreated {
    /** Optional. The number of Telegram Stars to be split between giveaway winners; for Telegram Star giveaways only. */
    std::optional<int64_t> prize_star_count; ///< Optional
};

/**
 * This object represents a message about a scheduled giveaway.
 * @see https://core.telegram.org/bots/api#giveaway
 */
struct Giveaway {
    /** The list of chats which the user must join to participate in the giveaway. */
    std::vector<std::shared_ptr<Chat>> chats;
    /** Point in time (Unix timestamp) when winners of the giveaway will be selected. */
    int64_t winners_selection_date{0};
    /** The number of users which are supposed to be selected as winners of the giveaway. */
    int64_t winner_count{0};
    /** Optional. True , if only users who join the chats after the giveaway started should be eligible to win. */
    std::optional<bool> only_new_members; ///< Optional
    /** Optional. True , if the list of giveaway winners will be visible to everyone. */
    std::optional<bool> has_public_winners; ///< Optional
    /** Optional. Description of additional giveaway prize. */
    std::optional<std::string> prize_description; ///< Optional
    /** Optional. A list of two-letter ISO 3166-1 alpha-2 country codes indicating the countries from which eligible users for t. */
    std::vector<std::string> country_codes; ///< Optional
    /** Optional. The number of Telegram Stars to be split between giveaway winners; for Telegram Star giveaways only. */
    std::optional<int64_t> prize_star_count; ///< Optional
    /** Optional. The number of months the Telegram Premium subscription won from the giveaway will be active for; for Telegram . */
    std::optional<int64_t> premium_subscription_month_count; ///< Optional
};

/**
 * This object represents a message about the completion of a giveaway with public winners.
 * @see https://core.telegram.org/bots/api#giveawaywinners
 */
struct GiveawayWinners {
    /** The chat that created the giveaway. */
    std::shared_ptr<Chat> chat;
    /** Identifier of the message with the giveaway in the chat. */
    int64_t giveaway_message_id{0};
    /** Point in time (Unix timestamp) when winners of the giveaway were selected. */
    int64_t winners_selection_date{0};
    /** Total number of winners in the giveaway. */
    int64_t winner_count{0};
    /** List of up to 100 winners of the giveaway. */
    std::vector<std::shared_ptr<User>> winners;
    /** Optional. The number of other chats the user had to join in order to be eligible for the giveaway. */
    std::optional<int64_t> additional_chat_count; ///< Optional
    /** Optional. The number of Telegram Stars that were split between giveaway winners; for Telegram Star giveaways only. */
    std::optional<int64_t> prize_star_count; ///< Optional
    /** Optional. The number of months the Telegram Premium subscription won from the giveaway will be active for; for Telegram . */
    std::optional<int64_t> premium_subscription_month_count; ///< Optional
    /** Optional. Number of undistributed prizes. */
    std::optional<int64_t> unclaimed_prize_count; ///< Optional
    /** Optional. True , if only users who had joined the chats after the giveaway started were eligible to win. */
    std::optional<bool> only_new_members; ///< Optional
    /** Optional. True , if the giveaway was canceled because the payment for it was refunded. */
    std::optional<bool> was_refunded; ///< Optional
    /** Optional. Description of additional giveaway prize. */
    std::optional<std::string> prize_description; ///< Optional
};

/**
 * This object represents a service message about the completion of a giveaway without public
 * winners.
 * @see https://core.telegram.org/bots/api#giveawaycompleted
 */
struct GiveawayCompleted {
    /** Number of winners in the giveaway. */
    int64_t winner_count{0};
    /** Optional. Number of undistributed prizes. */
    std::optional<int64_t> unclaimed_prize_count; ///< Optional
    /** Optional. Message with the giveaway that was completed, if it wasn't deleted. */
    std::shared_ptr<Message> giveaway_message; ///< Optional
    /** Optional. True , if the giveaway is a Telegram Star giveaway. */
    std::optional<bool> is_star_giveaway; ///< Optional
};

/**
 * Describes the options used for link preview generation.
 * @see https://core.telegram.org/bots/api#linkpreviewoptions
 */
struct LinkPreviewOptions {
    /** Optional. True , if the link preview is disabled. */
    std::optional<bool> is_disabled; ///< Optional
    /** Optional. URL to use for the link preview. */
    std::optional<std::string> url; ///< Optional
    /** Optional. True , if the media in the link preview is supposed to be shrunk; ignored if the URL isn't explicitly specifie. */
    std::optional<bool> prefer_small_media; ///< Optional
    /** Optional. True , if the media in the link preview is supposed to be enlarged; ignored if the URL isn't explicitly specif. */
    std::optional<bool> prefer_large_media; ///< Optional
    /** Optional. True , if the link preview must be shown above the message text; otherwise, the link preview will be shown bel. */
    std::optional<bool> show_above_text; ///< Optional
};

/**
 * Describes the price of a suggested post.
 * @see https://core.telegram.org/bots/api#suggestedpostprice
 */
struct SuggestedPostPrice {
    /** Currency in which the post will be paid. */
    std::string currency{""};
    /** The amount of the currency that will be paid for the post in the smallest units of the currency, i. */
    int64_t amount{0};
};

/**
 * Contains information about a suggested post.
 * @see https://core.telegram.org/bots/api#suggestedpostinfo
 */
struct SuggestedPostInfo {
    /** State of the suggested post. */
    std::string state{""};
    /** Optional. Proposed price of the post. */
    std::shared_ptr<SuggestedPostPrice> price; ///< Optional
    /** Optional. Proposed send date of the post. */
    std::optional<int64_t> send_date; ///< Optional
};

/**
 * Contains parameters of a post that is being suggested by the bot.
 * @see https://core.telegram.org/bots/api#suggestedpostparameters
 */
struct SuggestedPostParameters {
    /** Optional. Proposed price for the post. */
    std::shared_ptr<SuggestedPostPrice> price; ///< Optional
    /** Optional. Proposed send date of the post. */
    std::optional<int64_t> send_date; ///< Optional
};

/**
 * Describes a topic of a direct messages chat.
 * @see https://core.telegram.org/bots/api#directmessagestopic
 */
struct DirectMessagesTopic {
    /** Unique identifier of the topic. */
    int64_t topic_id{0};
    /** Optional. Information about the user that created the topic. */
    std::shared_ptr<User> user; ///< Optional
};

/**
 * This object represent a user's profile pictures.
 * @see https://core.telegram.org/bots/api#userprofilephotos
 */
struct UserProfilePhotos {
    /** Total number of profile pictures the target user has. */
    int64_t total_count{0};
    /** Requested profile pictures (in up to 4 sizes each). */
    std::vector<std::vector<std::shared_ptr<PhotoSize>>> photos;
};

/**
 * This object represents the audios displayed on a user's profile.
 * @see https://core.telegram.org/bots/api#userprofileaudios
 */
struct UserProfileAudios {
    /** Total number of profile audios for the target user. */
    int64_t total_count{0};
    /** Requested profile audios. */
    std::vector<std::shared_ptr<Audio>> audios;
};

/**
 * This object represents a file ready to be downloaded. The file can be downloaded via the link
 * https://api.telegram.org/file/bot<token>/<file_path>. It is guaranteed that the link will be
 * valid for at least 1 hour. When the link expires, a new one can be requested by calling getFile.
 * The maximum file size to download is 20 MB
 * @see https://core.telegram.org/bots/api#file
 */
struct File {
    /** Identifier for this file, which can be used to download or reuse the file. */
    std::string file_id{""};
    /** Unique identifier for this file, which is supposed to be the same over time and for different bots. */
    std::string file_unique_id{""};
    /** Optional. File size in bytes. */
    std::optional<int64_t> file_size; ///< Optional
    /** Optional. File path. */
    std::optional<std::string> file_path; ///< Optional
};

/**
 * Describes a Web App.
 * @see https://core.telegram.org/bots/api#webappinfo
 */
struct WebAppInfo {
    /** An HTTPS URL of a Web App to be opened with additional data as specified in Initializing Web Apps. */
    std::string url{""};
};

/**
 * This object represents a custom keyboard with reply options (see Introduction to bots for details
 * and examples). Not supported in channels and for messages sent on behalf of a business account.
 * @see https://core.telegram.org/bots/api#replykeyboardmarkup
 */
struct ReplyKeyboardMarkup {
    /** Array of button rows, each represented by an Array of KeyboardButton objects. */
    std::vector<std::vector<std::shared_ptr<KeyboardButton>>> keyboard;
    /** Optional. Requests clients to always show the keyboard when the regular keyboard is hidden. */
    std::optional<bool> is_persistent; ///< Optional
    /** Optional. Requests clients to resize the keyboard vertically for optimal fit (e. */
    std::optional<bool> resize_keyboard; ///< Optional
    /** Optional. Requests clients to hide the keyboard as soon as it's been used. */
    std::optional<bool> one_time_keyboard; ///< Optional
    /** Optional. The placeholder to be shown in the input field when the keyboard is active; 1-64 characters. */
    std::optional<std::string> input_field_placeholder; ///< Optional
    /** Optional. Use this parameter if you want to show the keyboard to specific users only. */
    std::optional<bool> selective; ///< Optional
};

/**
 * This object represents one button of the reply keyboard. At most one of the fields other than
 * text, icon_custom_emoji_id, and style must be used to specify the type of the button. For simple
 * text buttons, String can be used instead of this object to specify the button text.
 * @see https://core.telegram.org/bots/api#keyboardbutton
 */
struct KeyboardButton {
    /** Text of the button. */
    std::string text{""};
    /** Optional. Unique identifier of the custom emoji shown before the text of the button. */
    std::optional<std::string> icon_custom_emoji_id; ///< Optional
    /** Optional. Style of the button. */
    std::optional<std::string> style; ///< Optional
    /** Optional. If specified, pressing the button will open a list of suitable users. */
    std::shared_ptr<KeyboardButtonRequestUsers> request_users; ///< Optional
    /** Optional. If specified, pressing the button will open a list of suitable chats. */
    std::shared_ptr<KeyboardButtonRequestChat> request_chat; ///< Optional
    /** Optional. If specified, pressing the button will ask the user to create and share a bot that will be managed by the curr. */
    std::shared_ptr<KeyboardButtonRequestManagedBot> request_managed_bot; ///< Optional
    /** Optional. If True , the user's phone number will be sent as a contact when the button is pressed. */
    std::optional<bool> request_contact; ///< Optional
    /** Optional. If True , the user's current location will be sent when the button is pressed. */
    std::optional<bool> request_location; ///< Optional
    /** Optional. If specified, the user will be asked to create a poll and send it to the bot when the button is pressed. */
    std::shared_ptr<KeyboardButtonPollType> request_poll; ///< Optional
    /** Optional. If specified, the described Web App will be launched when the button is pressed. */
    std::shared_ptr<WebAppInfo> web_app; ///< Optional
};

/**
 * This object defines the criteria used to request suitable users. Information about the selected
 * users will be shared with the bot when the corresponding button is pressed.
 * @see https://core.telegram.org/bots/api#keyboardbuttonrequestusers
 */
struct KeyboardButtonRequestUsers {
    /** Signed 32-bit identifier of the request that will be received back in the UsersShared object. */
    int64_t request_id{0};
    /** Optional. Pass True to request bots, pass False to request regular users. */
    std::optional<bool> user_is_bot; ///< Optional
    /** Optional. Pass True to request premium users, pass False to request non-premium users. */
    std::optional<bool> user_is_premium; ///< Optional
    /** Optional. The maximum number of users to be selected; 1-10. */
    std::optional<int64_t> max_quantity; ///< Optional
    /** Optional. Pass True to request the users' first and last names. */
    std::optional<bool> request_name; ///< Optional
    /** Optional. Pass True to request the users' usernames. */
    std::optional<bool> request_username; ///< Optional
    /** Optional. Pass True to request the users' photos. */
    std::optional<bool> request_photo; ///< Optional
};

/**
 * This object defines the criteria used to request a suitable chat. Information about the selected
 * chat will be shared with the bot when the corresponding button is pressed. The bot will be
 * granted requested rights in the chat if appropriate.
 * @see https://core.telegram.org/bots/api#keyboardbuttonrequestchat
 */
struct KeyboardButtonRequestChat {
    /** Signed 32-bit identifier of the request, which will be received back in the ChatShared object. */
    int64_t request_id{0};
    /** Pass True to request a channel chat, pass False to request a group or a supergroup chat. */
    bool chat_is_channel{false};
    /** Optional. Pass True to request a forum supergroup, pass False to request a non-forum chat. */
    std::optional<bool> chat_is_forum; ///< Optional
    /** Optional. Pass True to request a supergroup or a channel with a username, pass False to request a chat without a usernam. */
    std::optional<bool> chat_has_username; ///< Optional
    /** Optional. Pass True to request a chat owned by the user. */
    std::optional<bool> chat_is_created; ///< Optional
    /** Optional. A JSON-serialized object listing the required administrator rights of the user in the chat. */
    std::shared_ptr<ChatAdministratorRights> user_administrator_rights; ///< Optional
    /** Optional. A JSON-serialized object listing the required administrator rights of the bot in the chat. */
    std::shared_ptr<ChatAdministratorRights> bot_administrator_rights; ///< Optional
    /** Optional. Pass True to request a chat with the bot as a member. */
    std::optional<bool> bot_is_member; ///< Optional
    /** Optional. Pass True to request the chat's title. */
    std::optional<bool> request_title; ///< Optional
    /** Optional. Pass True to request the chat's username. */
    std::optional<bool> request_username; ///< Optional
    /** Optional. Pass True to request the chat's photo. */
    std::optional<bool> request_photo; ///< Optional
};

/**
 * This object defines the parameters for the creation of a managed bot. Information about the
 * created bot will be shared with the bot using the update managed_bot and a Message with the field
 * managed_bot_created.
 * @see https://core.telegram.org/bots/api#keyboardbuttonrequestmanagedbot
 */
struct KeyboardButtonRequestManagedBot {
    /** Signed 32-bit identifier of the request. */
    int64_t request_id{0};
    /** Optional. Suggested name for the bot. */
    std::optional<std::string> suggested_name; ///< Optional
    /** Optional. Suggested username for the bot. */
    std::optional<std::string> suggested_username; ///< Optional
};

/**
 * This object represents type of a poll, which is allowed to be created and sent when the
 * corresponding button is pressed.
 * @see https://core.telegram.org/bots/api#keyboardbuttonpolltype
 */
struct KeyboardButtonPollType {
    /** Optional. If quiz is passed, the user will be allowed to create only polls in the quiz mode. */
    std::optional<std::string> type; ///< Optional
};

/**
 * Upon receiving a message with this object, Telegram clients will remove the current custom
 * keyboard and display the default letter-keyboard. By default, custom keyboards are displayed
 * until a new keyboard is sent by a bot. An exception is made for one-time keyboards that are
 * hidden immediately after the user presses a button (see ReplyKeyboardMarkup). Not supported in
 * channels and for messages sent on behalf of a business account.
 * @see https://core.telegram.org/bots/api#replykeyboardremove
 */
struct ReplyKeyboardRemove {
    /** Requests clients to remove the custom keyboard (user will not be able to summon this keyboard; if you want to hide the k. */
    bool remove_keyboard{false};
    /** Optional. Use this parameter if you want to remove the keyboard for specific users only. */
    std::optional<bool> selective; ///< Optional
};

/**
 * This object represents an inline keyboard that appears right next to the message it belongs to.
 * @see https://core.telegram.org/bots/api#inlinekeyboardmarkup
 */
struct InlineKeyboardMarkup {
    /** Array of button rows, each represented by an Array of InlineKeyboardButton objects. */
    std::vector<std::vector<std::shared_ptr<InlineKeyboardButton>>> inline_keyboard;
};

/**
 * This object represents one button of an inline keyboard. Exactly one of the fields other than
 * text, icon_custom_emoji_id, and style must be used to specify the type of the button.
 * @see https://core.telegram.org/bots/api#inlinekeyboardbutton
 */
struct InlineKeyboardButton {
    /** Label text on the button. */
    std::string text{""};
    /** Optional. Unique identifier of the custom emoji shown before the text of the button. */
    std::optional<std::string> icon_custom_emoji_id; ///< Optional
    /** Optional. Style of the button. */
    std::optional<std::string> style; ///< Optional
    /** Optional. HTTP or tg:// URL to be opened when the button is pressed. */
    std::optional<std::string> url; ///< Optional
    /** Optional. Data to be sent in a callback query to the bot when the button is pressed, 1-64 bytes. */
    std::optional<std::string> callback_data; ///< Optional
    /** Optional. Description of the Web App that will be launched when the user presses the button. */
    std::shared_ptr<WebAppInfo> web_app; ///< Optional
    /** Optional. An HTTPS URL used to automatically authorize the user. */
    std::shared_ptr<LoginUrl> login_url; ///< Optional
    /** Optional. If set, pressing the button will prompt the user to select one of their chats, open that chat and insert the b. */
    std::optional<std::string> switch_inline_query; ///< Optional
    /** Optional. If set, pressing the button will insert the bot's username and the specified inline query in the current chat'. */
    std::optional<std::string> switch_inline_query_current_chat; ///< Optional
    /** Optional. If set, pressing the button will prompt the user to select one of their chats of the specified type, open that. */
    std::shared_ptr<SwitchInlineQueryChosenChat> switch_inline_query_chosen_chat; ///< Optional
    /** Optional. Description of the button that copies the specified text to the clipboard. */
    std::shared_ptr<CopyTextButton> copy_text; ///< Optional
    /** Optional. Description of the game that will be launched when the user presses the button. */
    std::shared_ptr<CallbackGame> callback_game; ///< Optional
    /** Optional. Specify True , to send a Pay button . */
    std::optional<bool> pay; ///< Optional
};

/**
 * This object represents a parameter of the inline keyboard button used to automatically authorize
 * a user. Serves as a great replacement for the Telegram Login Widget when the user is coming from
 * Telegram. All the user needs to do is tap/click a button and confirm that they want to log in:
 * Telegram apps support these buttons as of version 5.7.
 * Sample bot: @discussbot
 * @see https://core.telegram.org/bots/api#loginurl
 */
struct LoginUrl {
    /** An HTTPS URL to be opened with user authorization data added to the query string when the button is pressed. */
    std::string url{""};
    /** Optional. New text of the button in forwarded messages. */
    std::optional<std::string> forward_text; ///< Optional
    /** Optional. Username of a bot, which will be used for user authorization. */
    std::optional<std::string> bot_username; ///< Optional
    /** Optional. Pass True to request the permission for your bot to send messages to the user. */
    std::optional<bool> request_write_access; ///< Optional
};

/**
 * This object represents an inline button that switches the current user to inline mode in a chosen
 * chat, with an optional default inline query.
 * @see https://core.telegram.org/bots/api#switchinlinequerychosenchat
 */
struct SwitchInlineQueryChosenChat {
    /** Optional. The default inline query to be inserted in the input field. */
    std::optional<std::string> query; ///< Optional
    /** Optional. True , if private chats with users can be chosen. */
    std::optional<bool> allow_user_chats; ///< Optional
    /** Optional. True , if private chats with bots can be chosen. */
    std::optional<bool> allow_bot_chats; ///< Optional
    /** Optional. True , if group and supergroup chats can be chosen. */
    std::optional<bool> allow_group_chats; ///< Optional
    /** Optional. True , if channel chats can be chosen. */
    std::optional<bool> allow_channel_chats; ///< Optional
};

/**
 * This object represents an inline keyboard button that copies specified text to the clipboard.
 * @see https://core.telegram.org/bots/api#copytextbutton
 */
struct CopyTextButton {
    /** The text to be copied to the clipboard; 1-256 characters. */
    std::string text{""};
};

/**
 * This object represents an incoming callback query from a callback button in an inline keyboard.
 * If the button that originated the query was attached to a message sent by the bot, the field
 * message will be present. If the button was attached to a message sent via the bot (in inline
 * mode), the field inline_message_id will be present. Exactly one of the fields data or
 * game_short_name will be present.
 * @see https://core.telegram.org/bots/api#callbackquery
 */
struct CallbackQuery {
    /** Unique identifier for this query. */
    std::string id{""};
    /** Sender. */
    std::shared_ptr<User> from;
    /** Optional. Message sent by the bot with the callback button that originated the query. */
    std::optional<MaybeInaccessibleMessage> message; ///< Optional
    /** Optional. Identifier of the message sent via the bot in inline mode, that originated the query. */
    std::optional<std::string> inline_message_id; ///< Optional
    /** Global identifier, uniquely corresponding to the chat to which the message with the callback button was sent. */
    std::string chat_instance{""};
    /** Optional. Data associated with the callback button. */
    std::optional<std::string> data; ///< Optional
    /** Optional. Short name of a Game to be returned, serves as the unique identifier for the game. */
    std::optional<std::string> game_short_name; ///< Optional
};

/**
 * Upon receiving a message with this object, Telegram clients will display a reply interface to the
 * user (act as if the user has selected the bot's message and tapped 'Reply'). This can be
 * extremely useful if you want to create user-friendly step-by-step interfaces without having to
 * sacrifice privacy mode. Not supported in channels and for messages sent on behalf of a user
 * account.
 * @see https://core.telegram.org/bots/api#forcereply
 */
struct ForceReply {
    /** Shows reply interface to the user, as if they manually selected the bot's message and tapped 'Reply'. */
    bool force_reply{false};
    /** Optional. The placeholder to be shown in the input field when the reply is active; 1-64 characters. */
    std::optional<std::string> input_field_placeholder; ///< Optional
    /** Optional. Use this parameter if you want to force reply from specific users only. */
    std::optional<bool> selective; ///< Optional
};

/**
 * This object represents a chat photo.
 * @see https://core.telegram.org/bots/api#chatphoto
 */
struct ChatPhoto {
    /** File identifier of small (160x160) chat photo. */
    std::string small_file_id{""};
    /** Unique file identifier of small (160x160) chat photo, which is supposed to be the same over time and for different bots. */
    std::string small_file_unique_id{""};
    /** File identifier of big (640x640) chat photo. */
    std::string big_file_id{""};
    /** Unique file identifier of big (640x640) chat photo, which is supposed to be the same over time and for different bots. */
    std::string big_file_unique_id{""};
};

/**
 * Represents an invite link for a chat.
 * @see https://core.telegram.org/bots/api#chatinvitelink
 */
struct ChatInviteLink {
    /** The invite link. */
    std::string invite_link{""};
    /** Creator of the link. */
    std::shared_ptr<User> creator;
    /** True , if users joining the chat via the link need to be approved by chat administrators. */
    bool creates_join_request{false};
    /** True , if the link is primary. */
    bool is_primary{false};
    /** True , if the link is revoked. */
    bool is_revoked{false};
    /** Optional. Invite link name. */
    std::optional<std::string> name; ///< Optional
    /** Optional. Point in time (Unix timestamp) when the link will expire or has been expired. */
    std::optional<int64_t> expire_date; ///< Optional
    /** Optional. The maximum number of users that can be members of the chat simultaneously after joining the chat via this inv. */
    std::optional<int64_t> member_limit; ///< Optional
    /** Optional. Number of pending join requests created using this link. */
    std::optional<int64_t> pending_join_request_count; ///< Optional
    /** Optional. The number of seconds the subscription will be active for before the next payment. */
    std::optional<int64_t> subscription_period; ///< Optional
    /** Optional. The amount of Telegram Stars a user must pay initially and after each subsequent subscription period to be a m. */
    std::optional<int64_t> subscription_price; ///< Optional
};

/**
 * Represents the rights of an administrator in a chat.
 * @see https://core.telegram.org/bots/api#chatadministratorrights
 */
struct ChatAdministratorRights {
    /** True , if the user's presence in the chat is hidden. */
    bool is_anonymous{false};
    /** True , if the administrator can access the chat event log, get boost list, see hidden supergroup and channel members, re. */
    bool can_manage_chat{false};
    /** True , if the administrator can delete messages of other users. */
    bool can_delete_messages{false};
    /** True , if the administrator can manage video chats. */
    bool can_manage_video_chats{false};
    /** True , if the administrator can restrict, ban or unban chat members, or access supergroup statistics. */
    bool can_restrict_members{false};
    /** True , if the administrator can add new administrators with a subset of their own privileges or demote administrators th. */
    bool can_promote_members{false};
    /** True , if the user is allowed to change the chat title, photo and other settings. */
    bool can_change_info{false};
    /** True , if the user is allowed to invite new users to the chat. */
    bool can_invite_users{false};
    /** True , if the administrator can post stories to the chat. */
    bool can_post_stories{false};
    /** True , if the administrator can edit stories posted by other users, post stories to the chat page, pin chat stories, and. */
    bool can_edit_stories{false};
    /** True , if the administrator can delete stories posted by other users. */
    bool can_delete_stories{false};
    /** Optional. True , if the administrator can post messages in the channel, approve suggested posts, or access channel stati. */
    std::optional<bool> can_post_messages; ///< Optional
    /** Optional. True , if the administrator can edit messages of other users and can pin messages; for channels only. */
    std::optional<bool> can_edit_messages; ///< Optional
    /** Optional. True , if the user is allowed to pin messages; for groups and supergroups only. */
    std::optional<bool> can_pin_messages; ///< Optional
    /** Optional. True , if the user is allowed to create, rename, close, and reopen forum topics; for supergroups only. */
    std::optional<bool> can_manage_topics; ///< Optional
    /** Optional. True , if the administrator can manage direct messages of the channel and decline suggested posts; for channel. */
    std::optional<bool> can_manage_direct_messages; ///< Optional
    /** Optional. True , if the administrator can edit the tags of regular members; for groups and supergroups only. */
    std::optional<bool> can_manage_tags; ///< Optional
};

/**
 * This object represents changes in the status of a chat member.
 * @see https://core.telegram.org/bots/api#chatmemberupdated
 */
struct ChatMemberUpdated {
    /** Chat the user belongs to. */
    std::shared_ptr<Chat> chat;
    /** Performer of the action, which resulted in the change. */
    std::shared_ptr<User> from;
    /** Date the change was done in Unix time. */
    int64_t date{0};
    /** Previous information about the chat member. */
    ChatMember old_chat_member{};
    /** New information about the chat member. */
    ChatMember new_chat_member{};
    /** Optional. Chat invite link, which was used by the user to join the chat; for joining by invite link events only. */
    std::shared_ptr<ChatInviteLink> invite_link; ///< Optional
    /** Optional. True , if the user joined the chat after sending a direct join request without using an invite link and being . */
    std::optional<bool> via_join_request; ///< Optional
    /** Optional. True , if the user joined the chat via a chat folder invite link. */
    std::optional<bool> via_chat_folder_invite_link; ///< Optional
};

/**
 * Represents a chat member that owns the chat and has all administrator privileges.
 * @see https://core.telegram.org/bots/api#chatmemberowner
 */
struct ChatMemberOwner {
    /** The member's status in the chat, always 'creator'. */
    std::string status{""};
    /** Information about the user. */
    std::shared_ptr<User> user;
    /** True , if the user's presence in the chat is hidden. */
    bool is_anonymous{false};
    /** Optional. Custom title for this user. */
    std::optional<std::string> custom_title; ///< Optional
};

/**
 * Represents a chat member that has some additional privileges.
 * @see https://core.telegram.org/bots/api#chatmemberadministrator
 */
struct ChatMemberAdministrator {
    /** The member's status in the chat, always 'administrator'. */
    std::string status{""};
    /** Information about the user. */
    std::shared_ptr<User> user;
    /** True , if the bot is allowed to edit administrator privileges of that user. */
    bool can_be_edited{false};
    /** True , if the user's presence in the chat is hidden. */
    bool is_anonymous{false};
    /** True , if the administrator can access the chat event log, get boost list, see hidden supergroup and channel members, re. */
    bool can_manage_chat{false};
    /** True , if the administrator can delete messages of other users. */
    bool can_delete_messages{false};
    /** True , if the administrator can manage video chats. */
    bool can_manage_video_chats{false};
    /** True , if the administrator can restrict, ban or unban chat members, or access supergroup statistics. */
    bool can_restrict_members{false};
    /** True , if the administrator can add new administrators with a subset of their own privileges or demote administrators th. */
    bool can_promote_members{false};
    /** True , if the user is allowed to change the chat title, photo and other settings. */
    bool can_change_info{false};
    /** True , if the user is allowed to invite new users to the chat. */
    bool can_invite_users{false};
    /** True , if the administrator can post stories to the chat. */
    bool can_post_stories{false};
    /** True , if the administrator can edit stories posted by other users, post stories to the chat page, pin chat stories, and. */
    bool can_edit_stories{false};
    /** True , if the administrator can delete stories posted by other users. */
    bool can_delete_stories{false};
    /** Optional. True , if the administrator can post messages in the channel, approve suggested posts, or access channel stati. */
    std::optional<bool> can_post_messages; ///< Optional
    /** Optional. True , if the administrator can edit messages of other users and can pin messages; for channels only. */
    std::optional<bool> can_edit_messages; ///< Optional
    /** Optional. True , if the user is allowed to pin messages; for groups and supergroups only. */
    std::optional<bool> can_pin_messages; ///< Optional
    /** Optional. True , if the user is allowed to create, rename, close, and reopen forum topics; for supergroups only. */
    std::optional<bool> can_manage_topics; ///< Optional
    /** Optional. True , if the administrator can manage direct messages of the channel and decline suggested posts; for channel. */
    std::optional<bool> can_manage_direct_messages; ///< Optional
    /** Optional. True , if the administrator can edit the tags of regular members; for groups and supergroups only. */
    std::optional<bool> can_manage_tags; ///< Optional
    /** Optional. Custom title for this user. */
    std::optional<std::string> custom_title; ///< Optional
};

/**
 * Represents a chat member that has no additional privileges or restrictions.
 * @see https://core.telegram.org/bots/api#chatmembermember
 */
struct ChatMemberMember {
    /** The member's status in the chat, always 'member'. */
    std::string status{""};
    /** Optional. Tag of the member. */
    std::optional<std::string> tag; ///< Optional
    /** Information about the user. */
    std::shared_ptr<User> user;
    /** Optional. Date when the user's subscription will expire; Unix time. */
    std::optional<int64_t> until_date; ///< Optional
};

/**
 * Represents a chat member that is under certain restrictions in the chat. Supergroups only.
 * @see https://core.telegram.org/bots/api#chatmemberrestricted
 */
struct ChatMemberRestricted {
    /** The member's status in the chat, always 'restricted'. */
    std::string status{""};
    /** Optional. Tag of the member. */
    std::optional<std::string> tag; ///< Optional
    /** Information about the user. */
    std::shared_ptr<User> user;
    /** True , if the user is a member of the chat at the moment of the request. */
    bool is_member{false};
    /** True , if the user is allowed to send text messages, contacts, giveaways, giveaway winners, invoices, locations and venu. */
    bool can_send_messages{false};
    /** True , if the user is allowed to send audios. */
    bool can_send_audios{false};
    /** True , if the user is allowed to send documents. */
    bool can_send_documents{false};
    /** True , if the user is allowed to send photos. */
    bool can_send_photos{false};
    /** True , if the user is allowed to send videos. */
    bool can_send_videos{false};
    /** True , if the user is allowed to send video notes. */
    bool can_send_video_notes{false};
    /** True , if the user is allowed to send voice notes. */
    bool can_send_voice_notes{false};
    /** True , if the user is allowed to send polls and checklists. */
    bool can_send_polls{false};
    /** True , if the user is allowed to send animations, games, stickers and use inline bots. */
    bool can_send_other_messages{false};
    /** True , if the user is allowed to add web page previews to their messages. */
    bool can_add_web_page_previews{false};
    /** True , if the user is allowed to react to messages. */
    bool can_react_to_messages{false};
    /** True , if the user is allowed to edit their own tag. */
    bool can_edit_tag{false};
    /** True , if the user is allowed to change the chat title, photo and other settings. */
    bool can_change_info{false};
    /** True , if the user is allowed to invite new users to the chat. */
    bool can_invite_users{false};
    /** True , if the user is allowed to pin messages. */
    bool can_pin_messages{false};
    /** True , if the user is allowed to create forum topics. */
    bool can_manage_topics{false};
    /** Date when restrictions will be lifted for this user; Unix time. */
    int64_t until_date{0};
};

/**
 * Represents a chat member that isn't currently a member of the chat, but may join it themselves.
 * @see https://core.telegram.org/bots/api#chatmemberleft
 */
struct ChatMemberLeft {
    /** The member's status in the chat, always 'left'. */
    std::string status{""};
    /** Information about the user. */
    std::shared_ptr<User> user;
};

/**
 * Represents a chat member that was banned in the chat and can't return to the chat or view chat
 * messages.
 * @see https://core.telegram.org/bots/api#chatmemberbanned
 */
struct ChatMemberBanned {
    /** The member's status in the chat, always 'kicked'. */
    std::string status{""};
    /** Information about the user. */
    std::shared_ptr<User> user;
    /** Date when restrictions will be lifted for this user; Unix time. */
    int64_t until_date{0};
};

/**
 * Represents a join request sent to a chat.
 * @see https://core.telegram.org/bots/api#chatjoinrequest
 */
struct ChatJoinRequest {
    /** Chat to which the request was sent. */
    std::shared_ptr<Chat> chat;
    /** User that sent the join request. */
    std::shared_ptr<User> from;
    /** Identifier of a private chat with the user who sent the join request. */
    int64_t user_chat_id{0};
    /** Date the request was sent in Unix time. */
    int64_t date{0};
    /** Optional. Bio of the user. */
    std::optional<std::string> bio; ///< Optional
    /** Optional. Chat invite link that was used by the user to send the join request. */
    std::shared_ptr<ChatInviteLink> invite_link; ///< Optional
};

/**
 * Describes actions that a non-administrator user is allowed to take in a chat.
 * @see https://core.telegram.org/bots/api#chatpermissions
 */
struct ChatPermissions {
    /** Optional. True , if the user is allowed to send text messages, contacts, giveaways, giveaway winners, invoices, location. */
    std::optional<bool> can_send_messages; ///< Optional
    /** Optional. True , if the user is allowed to send audios. */
    std::optional<bool> can_send_audios; ///< Optional
    /** Optional. True , if the user is allowed to send documents. */
    std::optional<bool> can_send_documents; ///< Optional
    /** Optional. True , if the user is allowed to send photos. */
    std::optional<bool> can_send_photos; ///< Optional
    /** Optional. True , if the user is allowed to send videos. */
    std::optional<bool> can_send_videos; ///< Optional
    /** Optional. True , if the user is allowed to send video notes. */
    std::optional<bool> can_send_video_notes; ///< Optional
    /** Optional. True , if the user is allowed to send voice notes. */
    std::optional<bool> can_send_voice_notes; ///< Optional
    /** Optional. True , if the user is allowed to send polls and checklists. */
    std::optional<bool> can_send_polls; ///< Optional
    /** Optional. True , if the user is allowed to send animations, games, stickers and use inline bots. */
    std::optional<bool> can_send_other_messages; ///< Optional
    /** Optional. True , if the user is allowed to add web page previews to their messages. */
    std::optional<bool> can_add_web_page_previews; ///< Optional
    /** Optional. True , if the user is allowed to react to messages. */
    std::optional<bool> can_react_to_messages; ///< Optional
    /** Optional. True , if the user is allowed to edit their own tag. */
    std::optional<bool> can_edit_tag; ///< Optional
    /** Optional. True , if the user is allowed to change the chat title, photo and other settings. */
    std::optional<bool> can_change_info; ///< Optional
    /** Optional. True , if the user is allowed to invite new users to the chat. */
    std::optional<bool> can_invite_users; ///< Optional
    /** Optional. True , if the user is allowed to pin messages. */
    std::optional<bool> can_pin_messages; ///< Optional
    /** Optional. True , if the user is allowed to create forum topics. */
    std::optional<bool> can_manage_topics; ///< Optional
};

/**
 * Describes the birthdate of a user.
 * @see https://core.telegram.org/bots/api#birthdate
 */
struct Birthdate {
    /** Day of the user's birth; 1-31. */
    int64_t day{0};
    /** Month of the user's birth; 1-12. */
    int64_t month{0};
    /** Optional. Year of the user's birth. */
    std::optional<int64_t> year; ///< Optional
};

/**
 * Contains information about the start page settings of a Telegram Business account.
 * @see https://core.telegram.org/bots/api#businessintro
 */
struct BusinessIntro {
    /** Optional. Title text of the business intro. */
    std::optional<std::string> title; ///< Optional
    /** Optional. Message text of the business intro. */
    std::optional<std::string> message; ///< Optional
    /** Optional. Sticker of the business intro. */
    std::shared_ptr<Sticker> sticker; ///< Optional
};

/**
 * Contains information about the location of a Telegram Business account.
 * @see https://core.telegram.org/bots/api#businesslocation
 */
struct BusinessLocation {
    /** Address of the business. */
    std::string address{""};
    /** Optional. Location of the business. */
    std::shared_ptr<Location> location; ///< Optional
};

/**
 * Describes an interval of time during which a business is open.
 * @see https://core.telegram.org/bots/api#businessopeninghoursinterval
 */
struct BusinessOpeningHoursInterval {
    /** The minute's sequence number in a week, starting on Monday, marking the start of the time interval during which the busi. */
    int64_t opening_minute{0};
    /** The minute's sequence number in a week, starting on Monday, marking the end of the time interval during which the busine. */
    int64_t closing_minute{0};
};

/**
 * Describes the opening hours of a business.
 * @see https://core.telegram.org/bots/api#businessopeninghours
 */
struct BusinessOpeningHours {
    /** Unique name of the time zone for which the opening hours are defined. */
    std::string time_zone_name{""};
    /** List of time intervals describing business opening hours. */
    std::vector<std::shared_ptr<BusinessOpeningHoursInterval>> opening_hours;
};

/**
 * This object describes the rating of a user based on their Telegram Star spendings.
 * @see https://core.telegram.org/bots/api#userrating
 */
struct UserRating {
    /** Current level of the user, indicating their reliability when purchasing digital goods and services. */
    int64_t level{0};
    /** Numerical value of the user's rating; the higher the rating, the better. */
    int64_t rating{0};
    /** The rating value required to get the current level. */
    int64_t current_level_rating{0};
    /** Optional. The rating value required to get to the next level; omitted if the maximum level was reached. */
    std::optional<int64_t> next_level_rating; ///< Optional
};

/**
 * Describes the position of a clickable area within a story.
 * @see https://core.telegram.org/bots/api#storyareaposition
 */
struct StoryAreaPosition {
    /** The abscissa of the area's center, as a percentage of the media width. */
    double x_percentage{0.0};
    /** The ordinate of the area's center, as a percentage of the media height. */
    double y_percentage{0.0};
    /** The width of the area's rectangle, as a percentage of the media width. */
    double width_percentage{0.0};
    /** The height of the area's rectangle, as a percentage of the media height. */
    double height_percentage{0.0};
    /** The clockwise rotation angle of the rectangle, in degrees; 0-360. */
    double rotation_angle{0.0};
    /** The radius of the rectangle corner rounding, as a percentage of the media width. */
    double corner_radius_percentage{0.0};
};

/**
 * Describes the physical address of a location.
 * @see https://core.telegram.org/bots/api#locationaddress
 */
struct LocationAddress {
    /** The two-letter ISO 3166-1 alpha-2 country code of the country where the location is located. */
    std::string country_code{""};
    /** Optional. State of the location. */
    std::optional<std::string> state; ///< Optional
    /** Optional. City of the location. */
    std::optional<std::string> city; ///< Optional
    /** Optional. Street address of the location. */
    std::optional<std::string> street; ///< Optional
};

/**
 * Describes a story area pointing to a location. Currently, a story can have up to 10 location
 * areas.
 * @see https://core.telegram.org/bots/api#storyareatypelocation
 */
struct StoryAreaTypeLocation {
    /** Type of the area, always 'location'. */
    std::string type{""};
    /** Location latitude in degrees. */
    double latitude{0.0};
    /** Location longitude in degrees. */
    double longitude{0.0};
    /** Optional. Address of the location. */
    std::shared_ptr<LocationAddress> address; ///< Optional
};

/**
 * Describes a story area pointing to a suggested reaction. Currently, a story can have up to 5
 * suggested reaction areas.
 * @see https://core.telegram.org/bots/api#storyareatypesuggestedreaction
 */
struct StoryAreaTypeSuggestedReaction {
    /** Type of the area, always 'suggested_reaction'. */
    std::string type{""};
    /** Type of the reaction. */
    ReactionType reaction_type{};
    /** Optional. Pass True if the reaction area has a dark background. */
    std::optional<bool> is_dark; ///< Optional
    /** Optional. Pass True if reaction area corner is flipped. */
    std::optional<bool> is_flipped; ///< Optional
};

/**
 * Describes a story area pointing to an HTTP or tg:// link. Currently, a story can have up to 3
 * link areas.
 * @see https://core.telegram.org/bots/api#storyareatypelink
 */
struct StoryAreaTypeLink {
    /** Type of the area, always 'link'. */
    std::string type{""};
    /** HTTP or tg:// URL to be opened when the area is clicked. */
    std::string url{""};
};

/**
 * Describes a story area containing weather information. Currently, a story can have up to 3
 * weather areas.
 * @see https://core.telegram.org/bots/api#storyareatypeweather
 */
struct StoryAreaTypeWeather {
    /** Type of the area, always 'weather'. */
    std::string type{""};
    /** Temperature, in degree Celsius. */
    double temperature{0.0};
    /** Emoji representing the weather. */
    std::string emoji{""};
    /** A color of the area background in the ARGB format. */
    int64_t background_color{0};
};

/**
 * Describes a story area pointing to a unique gift. Currently, a story can have at most 1 unique
 * gift area.
 * @see https://core.telegram.org/bots/api#storyareatypeuniquegift
 */
struct StoryAreaTypeUniqueGift {
    /** Type of the area, always 'unique_gift'. */
    std::string type{""};
    /** Unique name of the gift. */
    std::string name{""};
};

/**
 * Describes a clickable area on a story media.
 * @see https://core.telegram.org/bots/api#storyarea
 */
struct StoryArea {
    /** Position of the area. */
    std::shared_ptr<StoryAreaPosition> position;
    /** Type of the area. */
    StoryAreaType type{};
};

/**
 * Represents a location to which a chat is connected.
 * @see https://core.telegram.org/bots/api#chatlocation
 */
struct ChatLocation {
    /** The location to which the supergroup is connected. */
    std::shared_ptr<Location> location;
    /** Location address; 1-64 characters, as defined by the chat owner. */
    std::string address{""};
};

/**
 * The reaction is based on an emoji.
 * @see https://core.telegram.org/bots/api#reactiontypeemoji
 */
struct ReactionTypeEmoji {
    /** Type of the reaction, always 'emoji'. */
    std::string type{""};
    /** Reaction emoji. */
    std::string emoji{""};
};

/**
 * The reaction is based on a custom emoji.
 * @see https://core.telegram.org/bots/api#reactiontypecustomemoji
 */
struct ReactionTypeCustomEmoji {
    /** Type of the reaction, always 'custom_emoji'. */
    std::string type{""};
    /** Custom emoji identifier. */
    std::string custom_emoji_id{""};
};

/**
 * The reaction is paid.
 * @see https://core.telegram.org/bots/api#reactiontypepaid
 */
struct ReactionTypePaid {
    /** Type of the reaction, always 'paid'. */
    std::string type{""};
};

/**
 * Represents a reaction added to a message along with the number of times it was added.
 * @see https://core.telegram.org/bots/api#reactioncount
 */
struct ReactionCount {
    /** Type of the reaction. */
    ReactionType type{};
    /** Number of times the reaction was added. */
    int64_t total_count{0};
};

/**
 * This object represents a change of a reaction on a message performed by a user.
 * @see https://core.telegram.org/bots/api#messagereactionupdated
 */
struct MessageReactionUpdated {
    /** The chat containing the message the user reacted to. */
    std::shared_ptr<Chat> chat;
    /** Unique identifier of the message inside the chat. */
    int64_t message_id{0};
    /** Optional. The user that changed the reaction, if the user isn't anonymous. */
    std::shared_ptr<User> user; ///< Optional
    /** Optional. The chat on behalf of which the reaction was changed, if the user is anonymous. */
    std::shared_ptr<Chat> actor_chat; ///< Optional
    /** Date of the change in Unix time. */
    int64_t date{0};
    /** Previous list of reaction types that were set by the user. */
    std::vector<ReactionType> old_reaction;
    /** New list of reaction types that have been set by the user. */
    std::vector<ReactionType> new_reaction;
};

/**
 * This object represents reaction changes on a message with anonymous reactions.
 * @see https://core.telegram.org/bots/api#messagereactioncountupdated
 */
struct MessageReactionCountUpdated {
    /** The chat containing the message. */
    std::shared_ptr<Chat> chat;
    /** Unique message identifier inside the chat. */
    int64_t message_id{0};
    /** Date of the change in Unix time. */
    int64_t date{0};
    /** List of reactions that are present on the message. */
    std::vector<std::shared_ptr<ReactionCount>> reactions;
};

/**
 * This object represents a forum topic.
 * @see https://core.telegram.org/bots/api#forumtopic
 */
struct ForumTopic {
    /** Unique identifier of the forum topic. */
    int64_t message_thread_id{0};
    /** Name of the topic. */
    std::string name{""};
    /** Color of the topic icon in RGB format. */
    int64_t icon_color{0};
    /** Optional. Unique identifier of the custom emoji shown as the topic icon. */
    std::optional<std::string> icon_custom_emoji_id; ///< Optional
    /** Optional. True , if the name of the topic wasn't specified explicitly by its creator and likely needs to be changed by t. */
    std::optional<bool> is_name_implicit; ///< Optional
};

/**
 * This object describes the background of a gift.
 * @see https://core.telegram.org/bots/api#giftbackground
 */
struct GiftBackground {
    /** Center color of the background in RGB format. */
    int64_t center_color{0};
    /** Edge color of the background in RGB format. */
    int64_t edge_color{0};
    /** Text color of the background in RGB format. */
    int64_t text_color{0};
};

/**
 * This object represents a gift that can be sent by the bot.
 * @see https://core.telegram.org/bots/api#gift
 */
struct Gift {
    /** Unique identifier of the gift. */
    std::string id{""};
    /** The sticker that represents the gift. */
    std::shared_ptr<Sticker> sticker;
    /** The number of Telegram Stars that must be paid to send the sticker. */
    int64_t star_count{0};
    /** Optional. The number of Telegram Stars that must be paid to upgrade the gift to a unique one. */
    std::optional<int64_t> upgrade_star_count; ///< Optional
    /** Optional. True , if the gift can only be purchased by Telegram Premium subscribers. */
    std::optional<bool> is_premium; ///< Optional
    /** Optional. True , if the gift can be used (after being upgraded) to customize a user's appearance. */
    std::optional<bool> has_colors; ///< Optional
    /** Optional. The total number of gifts of this type that can be sent by all users; for limited gifts only. */
    std::optional<int64_t> total_count; ///< Optional
    /** Optional. The number of remaining gifts of this type that can be sent by all users; for limited gifts only. */
    std::optional<int64_t> remaining_count; ///< Optional
    /** Optional. The total number of gifts of this type that can be sent by the bot; for limited gifts only. */
    std::optional<int64_t> personal_total_count; ///< Optional
    /** Optional. The number of remaining gifts of this type that can be sent by the bot; for limited gifts only. */
    std::optional<int64_t> personal_remaining_count; ///< Optional
    /** Optional. Background of the gift. */
    std::shared_ptr<GiftBackground> background; ///< Optional
    /** Optional. The total number of different unique gifts that can be obtained by upgrading the gift. */
    std::optional<int64_t> unique_gift_variant_count; ///< Optional
    /** Optional. Information about the chat that published the gift. */
    std::shared_ptr<Chat> publisher_chat; ///< Optional
};

/**
 * This object represent a list of gifts.
 * @see https://core.telegram.org/bots/api#gifts
 */
struct Gifts {
    /** The list of gifts. */
    std::vector<std::shared_ptr<Gift>> gifts;
};

/**
 * This object describes the model of a unique gift.
 * @see https://core.telegram.org/bots/api#uniquegiftmodel
 */
struct UniqueGiftModel {
    /** Name of the model. */
    std::string name{""};
    /** The sticker that represents the unique gift. */
    std::shared_ptr<Sticker> sticker;
    /** The number of unique gifts that receive this model for every 1000 gift upgrades. */
    int64_t rarity_per_mille{0};
    /** Optional. Rarity of the model if it is a crafted model. */
    std::optional<std::string> rarity; ///< Optional
};

/**
 * This object describes the symbol shown on the pattern of a unique gift.
 * @see https://core.telegram.org/bots/api#uniquegiftsymbol
 */
struct UniqueGiftSymbol {
    /** Name of the symbol. */
    std::string name{""};
    /** The sticker that represents the unique gift. */
    std::shared_ptr<Sticker> sticker;
    /** The number of unique gifts that receive this model for every 1000 gifts upgraded. */
    int64_t rarity_per_mille{0};
};

/**
 * This object describes the colors of the backdrop of a unique gift.
 * @see https://core.telegram.org/bots/api#uniquegiftbackdropcolors
 */
struct UniqueGiftBackdropColors {
    /** The color in the center of the backdrop in RGB format. */
    int64_t center_color{0};
    /** The color on the edges of the backdrop in RGB format. */
    int64_t edge_color{0};
    /** The color to be applied to the symbol in RGB format. */
    int64_t symbol_color{0};
    /** The color for the text on the backdrop in RGB format. */
    int64_t text_color{0};
};

/**
 * This object describes the backdrop of a unique gift.
 * @see https://core.telegram.org/bots/api#uniquegiftbackdrop
 */
struct UniqueGiftBackdrop {
    /** Name of the backdrop. */
    std::string name{""};
    /** Colors of the backdrop. */
    std::shared_ptr<UniqueGiftBackdropColors> colors;
    /** The number of unique gifts that receive this backdrop for every 1000 gifts upgraded. */
    int64_t rarity_per_mille{0};
};

/**
 * This object contains information about the color scheme for a user's name, message replies and
 * link previews based on a unique gift.
 * @see https://core.telegram.org/bots/api#uniquegiftcolors
 */
struct UniqueGiftColors {
    /** Custom emoji identifier of the unique gift's model. */
    std::string model_custom_emoji_id{""};
    /** Custom emoji identifier of the unique gift's symbol. */
    std::string symbol_custom_emoji_id{""};
    /** Main color used in light themes; RGB format. */
    int64_t light_theme_main_color{0};
    /** List of 1-3 additional colors used in light themes; RGB format. */
    std::vector<int64_t> light_theme_other_colors;
    /** Main color used in dark themes; RGB format. */
    int64_t dark_theme_main_color{0};
    /** List of 1-3 additional colors used in dark themes; RGB format. */
    std::vector<int64_t> dark_theme_other_colors;
};

/**
 * This object describes a unique gift that was upgraded from a regular gift.
 * @see https://core.telegram.org/bots/api#uniquegift
 */
struct UniqueGift {
    /** Identifier of the regular gift from which the gift was upgraded. */
    std::string gift_id{""};
    /** Human-readable name of the regular gift from which this unique gift was upgraded. */
    std::string base_name{""};
    /** Unique name of the gift. */
    std::string name{""};
    /** Unique number of the upgraded gift among gifts upgraded from the same regular gift. */
    int64_t number{0};
    /** Model of the gift. */
    std::shared_ptr<UniqueGiftModel> model;
    /** Symbol of the gift. */
    std::shared_ptr<UniqueGiftSymbol> symbol;
    /** Backdrop of the gift. */
    std::shared_ptr<UniqueGiftBackdrop> backdrop;
    /** Optional. True , if the original regular gift was exclusively purchaseable by Telegram Premium subscribers. */
    std::optional<bool> is_premium; ///< Optional
    /** Optional. True , if the gift was used to craft another gift and isn't available anymore. */
    std::optional<bool> is_burned; ///< Optional
    /** Optional. True , if the gift is assigned from the TON blockchain and can't be resold or transferred in Telegram. */
    std::optional<bool> is_from_blockchain; ///< Optional
    /** Optional. The color scheme that can be used by the gift's owner for the chat's name, replies to messages and link previe. */
    std::shared_ptr<UniqueGiftColors> colors; ///< Optional
    /** Optional. Information about the chat that published the gift. */
    std::shared_ptr<Chat> publisher_chat; ///< Optional
};

/**
 * Describes a service message about a regular gift that was sent or received.
 * @see https://core.telegram.org/bots/api#giftinfo
 */
struct GiftInfo {
    /** Information about the gift. */
    std::shared_ptr<Gift> gift;
    /** Optional. Unique identifier of the received gift for the bot; only present for gifts received on behalf of business acco. */
    std::optional<std::string> owned_gift_id; ///< Optional
    /** Optional. Number of Telegram Stars that can be claimed by the receiver by converting the gift; omitted if conversion to . */
    std::optional<int64_t> convert_star_count; ///< Optional
    /** Optional. Number of Telegram Stars that were prepaid for the ability to upgrade the gift. */
    std::optional<int64_t> prepaid_upgrade_star_count; ///< Optional
    /** Optional. True , if the gift's upgrade was purchased after the gift was sent. */
    std::optional<bool> is_upgrade_separate; ///< Optional
    /** Optional. True , if the gift can be upgraded to a unique gift. */
    std::optional<bool> can_be_upgraded; ///< Optional
    /** Optional. Text of the message that was added to the gift. */
    std::optional<std::string> text; ///< Optional
    /** Optional. Special entities that appear in the text. */
    std::vector<std::shared_ptr<MessageEntity>> entities; ///< Optional
    /** Optional. True , if the sender and gift text are shown only to the gift receiver; otherwise, everyone will be able to se. */
    std::optional<bool> is_private; ///< Optional
    /** Optional. Unique number reserved for this gift when upgraded. */
    std::optional<int64_t> unique_gift_number; ///< Optional
};

/**
 * Describes a service message about a unique gift that was sent or received.
 * @see https://core.telegram.org/bots/api#uniquegiftinfo
 */
struct UniqueGiftInfo {
    /** Information about the gift. */
    std::shared_ptr<UniqueGift> gift;
    /** Origin of the gift. */
    std::string origin{""};
    /** Optional. For gifts bought from other users, the currency in which the payment for the gift was done. */
    std::optional<std::string> last_resale_currency; ///< Optional
    /** Optional. For gifts bought from other users, the price paid for the gift in either Telegram Stars or nanotoncoins. */
    std::optional<int64_t> last_resale_amount; ///< Optional
    /** Optional. Unique identifier of the received gift for the bot; only present for gifts received on behalf of business acco. */
    std::optional<std::string> owned_gift_id; ///< Optional
    /** Optional. Number of Telegram Stars that must be paid to transfer the gift; omitted if the bot cannot transfer the gift. */
    std::optional<int64_t> transfer_star_count; ///< Optional
    /** Optional. Point in time (Unix timestamp) when the gift can be transferred. */
    std::optional<int64_t> next_transfer_date; ///< Optional
};

/**
 * Describes a regular gift owned by a user or a chat.
 * @see https://core.telegram.org/bots/api#ownedgiftregular
 */
struct OwnedGiftRegular {
    /** Type of the gift, always 'regular'. */
    std::string type{""};
    /** Information about the regular gift. */
    std::shared_ptr<Gift> gift;
    /** Optional. Unique identifier of the gift for the bot; for gifts received on behalf of business accounts only. */
    std::optional<std::string> owned_gift_id; ///< Optional
    /** Optional. Sender of the gift if it is a known user. */
    std::shared_ptr<User> sender_user; ///< Optional
    /** Date the gift was sent in Unix time. */
    int64_t send_date{0};
    /** Optional. Text of the message that was added to the gift. */
    std::optional<std::string> text; ///< Optional
    /** Optional. Special entities that appear in the text. */
    std::vector<std::shared_ptr<MessageEntity>> entities; ///< Optional
    /** Optional. True , if the sender and gift text are shown only to the gift receiver; otherwise, everyone will be able to se. */
    std::optional<bool> is_private; ///< Optional
    /** Optional. True , if the gift is displayed on the account's profile page; for gifts received on behalf of business accoun. */
    std::optional<bool> is_saved; ///< Optional
    /** Optional. True , if the gift can be upgraded to a unique gift; for gifts received on behalf of business accounts only. */
    std::optional<bool> can_be_upgraded; ///< Optional
    /** Optional. True , if the gift was refunded and isn't available anymore. */
    std::optional<bool> was_refunded; ///< Optional
    /** Optional. Number of Telegram Stars that can be claimed by the receiver instead of the gift; omitted if the gift cannot b. */
    std::optional<int64_t> convert_star_count; ///< Optional
    /** Optional. Number of Telegram Stars that were paid for the ability to upgrade the gift. */
    std::optional<int64_t> prepaid_upgrade_star_count; ///< Optional
    /** Optional. True , if the gift's upgrade was purchased after the gift was sent; for gifts received on behalf of business a. */
    std::optional<bool> is_upgrade_separate; ///< Optional
    /** Optional. Unique number reserved for this gift when upgraded. */
    std::optional<int64_t> unique_gift_number; ///< Optional
};

/**
 * Describes a unique gift received and owned by a user or a chat.
 * @see https://core.telegram.org/bots/api#ownedgiftunique
 */
struct OwnedGiftUnique {
    /** Type of the gift, always 'unique'. */
    std::string type{""};
    /** Information about the unique gift. */
    std::shared_ptr<UniqueGift> gift;
    /** Optional. Unique identifier of the received gift for the bot; for gifts received on behalf of business accounts only. */
    std::optional<std::string> owned_gift_id; ///< Optional
    /** Optional. Sender of the gift if it is a known user. */
    std::shared_ptr<User> sender_user; ///< Optional
    /** Date the gift was sent in Unix time. */
    int64_t send_date{0};
    /** Optional. True , if the gift is displayed on the account's profile page; for gifts received on behalf of business accoun. */
    std::optional<bool> is_saved; ///< Optional
    /** Optional. True , if the gift can be transferred to another owner; for gifts received on behalf of business accounts only. */
    std::optional<bool> can_be_transferred; ///< Optional
    /** Optional. Number of Telegram Stars that must be paid to transfer the gift; omitted if the bot cannot transfer the gift. */
    std::optional<int64_t> transfer_star_count; ///< Optional
    /** Optional. Point in time (Unix timestamp) when the gift can be transferred. */
    std::optional<int64_t> next_transfer_date; ///< Optional
};

/**
 * Contains the list of gifts received and owned by a user or a chat.
 * @see https://core.telegram.org/bots/api#ownedgifts
 */
struct OwnedGifts {
    /** The total number of gifts owned by the user or the chat. */
    int64_t total_count{0};
    /** The list of gifts. */
    std::vector<OwnedGift> gifts;
    /** Optional. Offset for the next request. */
    std::optional<std::string> next_offset; ///< Optional
};

/**
 * This object describes the access settings of a bot.
 * @see https://core.telegram.org/bots/api#botaccesssettings
 */
struct BotAccessSettings {
    /** True , if only selected users can access the bot. */
    bool is_access_restricted{false};
    /** Optional. The list of other users who have access to the bot if the access is restricted. */
    std::vector<std::shared_ptr<User>> added_users; ///< Optional
};

/**
 * This object describes the types of gifts that can be gifted to a user or a chat.
 * @see https://core.telegram.org/bots/api#acceptedgifttypes
 */
struct AcceptedGiftTypes {
    /** True , if unlimited regular gifts are accepted. */
    bool unlimited_gifts{false};
    /** True , if limited regular gifts are accepted. */
    bool limited_gifts{false};
    /** True , if unique gifts or gifts that can be upgraded to unique for free are accepted. */
    bool unique_gifts{false};
    /** True , if a Telegram Premium subscription is accepted. */
    bool premium_subscription{false};
    /** True , if transfers of unique gifts from channels are accepted. */
    bool gifts_from_channels{false};
};

/**
 * Describes an amount of Telegram Stars.
 * @see https://core.telegram.org/bots/api#staramount
 */
struct StarAmount {
    /** Integer amount of Telegram Stars, rounded to 0; can be negative. */
    int64_t amount{0};
    /** Optional. The number of 1/1000000000 shares of Telegram Stars; from -999999999 to 999999999; can be negative if and only. */
    std::optional<int64_t> nanostar_amount; ///< Optional
};

/**
 * This object represents a bot command.
 * @see https://core.telegram.org/bots/api#botcommand
 */
struct BotCommand {
    /** Text of the command; 1-32 characters. */
    std::string command{""};
    /** Description of the command; 1-256 characters. */
    std::string description{""};
};

/**
 * Represents the default scope of bot commands. Default commands are used if no commands with a
 * narrower scope are specified for the user.
 * @see https://core.telegram.org/bots/api#botcommandscopedefault
 */
struct BotCommandScopeDefault {
    /** Scope type, must be default. */
    std::string type{""};
};

/**
 * Represents the scope of bot commands, covering all private chats.
 * @see https://core.telegram.org/bots/api#botcommandscopeallprivatechats
 */
struct BotCommandScopeAllPrivateChats {
    /** Scope type, must be all_private_chats. */
    std::string type{""};
};

/**
 * Represents the scope of bot commands, covering all group and supergroup chats.
 * @see https://core.telegram.org/bots/api#botcommandscopeallgroupchats
 */
struct BotCommandScopeAllGroupChats {
    /** Scope type, must be all_group_chats. */
    std::string type{""};
};

/**
 * Represents the scope of bot commands, covering all group and supergroup chat administrators.
 * @see https://core.telegram.org/bots/api#botcommandscopeallchatadministrators
 */
struct BotCommandScopeAllChatAdministrators {
    /** Scope type, must be all_chat_administrators. */
    std::string type{""};
};

/**
 * Represents the scope of bot commands, covering a specific chat.
 * @see https://core.telegram.org/bots/api#botcommandscopechat
 */
struct BotCommandScopeChat {
    /** Scope type, must be chat. */
    std::string type{""};
    /** Unique identifier for the target chat or username of the target supergroup in the format @username . */
    ChatId chat_id{};
};

/**
 * Represents the scope of bot commands, covering all administrators of a specific group or
 * supergroup chat.
 * @see https://core.telegram.org/bots/api#botcommandscopechatadministrators
 */
struct BotCommandScopeChatAdministrators {
    /** Scope type, must be chat_administrators. */
    std::string type{""};
    /** Unique identifier for the target chat or username of the target supergroup in the format @username . */
    ChatId chat_id{};
};

/**
 * Represents the scope of bot commands, covering a specific member of a group or supergroup chat.
 * @see https://core.telegram.org/bots/api#botcommandscopechatmember
 */
struct BotCommandScopeChatMember {
    /** Scope type, must be chat_member. */
    std::string type{""};
    /** Unique identifier for the target chat or username of the target supergroup in the format @username . */
    ChatId chat_id{};
    /** Unique identifier of the target user. */
    int64_t user_id{0};
};

/**
 * This object represents the bot's name.
 * @see https://core.telegram.org/bots/api#botname
 */
struct BotName {
    /** The bot's name. */
    std::string name{""};
};

/**
 * This object represents the bot's description.
 * @see https://core.telegram.org/bots/api#botdescription
 */
struct BotDescription {
    /** The bot's description. */
    std::string description{""};
};

/**
 * This object represents the bot's short description.
 * @see https://core.telegram.org/bots/api#botshortdescription
 */
struct BotShortDescription {
    /** The bot's short description. */
    std::string short_description{""};
};

/**
 * Represents a menu button, which opens the bot's list of commands.
 * @see https://core.telegram.org/bots/api#menubuttoncommands
 */
struct MenuButtonCommands {
    /** Type of the button, must be commands. */
    std::string type{""};
};

/**
 * Represents a menu button, which launches a Web App.
 * @see https://core.telegram.org/bots/api#menubuttonwebapp
 */
struct MenuButtonWebApp {
    /** Type of the button, must be web_app. */
    std::string type{""};
    /** Text on the button. */
    std::string text{""};
    /** Description of the Web App that will be launched when the user presses the button. */
    std::shared_ptr<WebAppInfo> web_app;
};

/**
 * Describes that no specific value for the menu button was set.
 * @see https://core.telegram.org/bots/api#menubuttondefault
 */
struct MenuButtonDefault {
    /** Type of the button, must be default. */
    std::string type{""};
};

/**
 * The boost was obtained by subscribing to Telegram Premium or by gifting a Telegram Premium
 * subscription to another user.
 * @see https://core.telegram.org/bots/api#chatboostsourcepremium
 */
struct ChatBoostSourcePremium {
    /** Source of the boost, always 'premium'. */
    std::string source{""};
    /** User that boosted the chat. */
    std::shared_ptr<User> user;
};

/**
 * The boost was obtained by the creation of Telegram Premium gift codes to boost a chat. Each such
 * code boosts the chat 4 times for the duration of the corresponding Telegram Premium subscription.
 * @see https://core.telegram.org/bots/api#chatboostsourcegiftcode
 */
struct ChatBoostSourceGiftCode {
    /** Source of the boost, always 'gift_code'. */
    std::string source{""};
    /** User for which the gift code was created. */
    std::shared_ptr<User> user;
};

/**
 * The boost was obtained by the creation of a Telegram Premium or a Telegram Star giveaway. This
 * boosts the chat 4 times for the duration of the corresponding Telegram Premium subscription for
 * Telegram Premium giveaways and prize_star_count / 500 times for one year for Telegram Star
 * giveaways.
 * @see https://core.telegram.org/bots/api#chatboostsourcegiveaway
 */
struct ChatBoostSourceGiveaway {
    /** Source of the boost, always 'giveaway'. */
    std::string source{""};
    /** Identifier of a message in the chat with the giveaway; the message could have been deleted already. */
    int64_t giveaway_message_id{0};
    /** Optional. User that won the prize in the giveaway if any; for Telegram Premium giveaways only. */
    std::shared_ptr<User> user; ///< Optional
    /** Optional. The number of Telegram Stars to be split between giveaway winners; for Telegram Star giveaways only. */
    std::optional<int64_t> prize_star_count; ///< Optional
    /** Optional. True , if the giveaway was completed, but there was no user to win the prize. */
    std::optional<bool> is_unclaimed; ///< Optional
};

/**
 * This object contains information about a chat boost.
 * @see https://core.telegram.org/bots/api#chatboost
 */
struct ChatBoost {
    /** Unique identifier of the boost. */
    std::string boost_id{""};
    /** Point in time (Unix timestamp) when the chat was boosted. */
    int64_t add_date{0};
    /** Point in time (Unix timestamp) when the boost will automatically expire, unless the booster's Telegram Premium subscript. */
    int64_t expiration_date{0};
    /** Source of the added boost. */
    ChatBoostSource source{};
};

/**
 * This object represents a boost added to a chat or changed.
 * @see https://core.telegram.org/bots/api#chatboostupdated
 */
struct ChatBoostUpdated {
    /** Chat which was boosted. */
    std::shared_ptr<Chat> chat;
    /** Information about the chat boost. */
    std::shared_ptr<ChatBoost> boost;
};

/**
 * This object represents a boost removed from a chat.
 * @see https://core.telegram.org/bots/api#chatboostremoved
 */
struct ChatBoostRemoved {
    /** Chat which was boosted. */
    std::shared_ptr<Chat> chat;
    /** Unique identifier of the boost. */
    std::string boost_id{""};
    /** Point in time (Unix timestamp) when the boost was removed. */
    int64_t remove_date{0};
    /** Source of the removed boost. */
    ChatBoostSource source{};
};

/**
 * Describes a service message about the chat owner leaving the chat.
 * @see https://core.telegram.org/bots/api#chatownerleft
 */
struct ChatOwnerLeft {
    /** Optional. The user who will become the new owner of the chat if the previous owner does not return to the chat. */
    std::shared_ptr<User> new_owner; ///< Optional
};

/**
 * Describes a service message about an ownership change in the chat.
 * @see https://core.telegram.org/bots/api#chatownerchanged
 */
struct ChatOwnerChanged {
    /** The new owner of the chat. */
    std::shared_ptr<User> new_owner;
};

/**
 * This object represents a list of boosts added to a chat by a user.
 * @see https://core.telegram.org/bots/api#userchatboosts
 */
struct UserChatBoosts {
    /** The list of boosts added to the chat by the user. */
    std::vector<std::shared_ptr<ChatBoost>> boosts;
};

/**
 * Represents the rights of a business bot.
 * @see https://core.telegram.org/bots/api#businessbotrights
 */
struct BusinessBotRights {
    /** Optional. True , if the bot can send and edit messages in the private chats that had incoming messages in the last 24 ho. */
    std::optional<bool> can_reply; ///< Optional
    /** Optional. True , if the bot can mark incoming private messages as read. */
    std::optional<bool> can_read_messages; ///< Optional
    /** Optional. True , if the bot can delete messages sent by the bot. */
    std::optional<bool> can_delete_sent_messages; ///< Optional
    /** Optional. True , if the bot can delete all private messages in managed chats. */
    std::optional<bool> can_delete_all_messages; ///< Optional
    /** Optional. True , if the bot can edit the first and last name of the business account. */
    std::optional<bool> can_edit_name; ///< Optional
    /** Optional. True , if the bot can edit the bio of the business account. */
    std::optional<bool> can_edit_bio; ///< Optional
    /** Optional. True , if the bot can edit the profile photo of the business account. */
    std::optional<bool> can_edit_profile_photo; ///< Optional
    /** Optional. True , if the bot can edit the username of the business account. */
    std::optional<bool> can_edit_username; ///< Optional
    /** Optional. True , if the bot can change the privacy settings pertaining to gifts for the business account. */
    std::optional<bool> can_change_gift_settings; ///< Optional
    /** Optional. True , if the bot can view gifts and the amount of Telegram Stars owned by the business account. */
    std::optional<bool> can_view_gifts_and_stars; ///< Optional
    /** Optional. True , if the bot can convert regular gifts owned by the business account to Telegram Stars. */
    std::optional<bool> can_convert_gifts_to_stars; ///< Optional
    /** Optional. True , if the bot can transfer and upgrade gifts owned by the business account. */
    std::optional<bool> can_transfer_and_upgrade_gifts; ///< Optional
    /** Optional. True , if the bot can transfer Telegram Stars received by the business account to its own account, or use them. */
    std::optional<bool> can_transfer_stars; ///< Optional
    /** Optional. True , if the bot can post, edit and delete stories on behalf of the business account. */
    std::optional<bool> can_manage_stories; ///< Optional
};

/**
 * Describes the connection of the bot with a business account.
 * @see https://core.telegram.org/bots/api#businessconnection
 */
struct BusinessConnection {
    /** Unique identifier of the business connection. */
    std::string id{""};
    /** Business account user that created the business connection. */
    std::shared_ptr<User> user;
    /** Identifier of a private chat with the user who created the business connection. */
    int64_t user_chat_id{0};
    /** Date the connection was established in Unix time. */
    int64_t date{0};
    /** Optional. Rights of the business bot. */
    std::shared_ptr<BusinessBotRights> rights; ///< Optional
    /** True , if the connection is active. */
    bool is_enabled{false};
};

/**
 * This object is received when messages are deleted from a connected business account.
 * @see https://core.telegram.org/bots/api#businessmessagesdeleted
 */
struct BusinessMessagesDeleted {
    /** Unique identifier of the business connection. */
    std::string business_connection_id{""};
    /** Information about a chat in the business account. */
    std::shared_ptr<Chat> chat;
    /** The list of identifiers of deleted messages in the chat of the business account. */
    std::vector<int64_t> message_ids;
};

/**
 * Describes an inline message sent by a Web App on behalf of a user.
 * @see https://core.telegram.org/bots/api#sentwebappmessage
 */
struct SentWebAppMessage {
    /** Optional. Identifier of the sent inline message. */
    std::optional<std::string> inline_message_id; ///< Optional
};

/**
 * Describes an inline message sent by a guest bot.
 * @see https://core.telegram.org/bots/api#sentguestmessage
 */
struct SentGuestMessage {
    /** Identifier of the sent inline message. */
    std::string inline_message_id{""};
};

/**
 * Describes an inline message to be sent by a user of a Mini App.
 * @see https://core.telegram.org/bots/api#preparedinlinemessage
 */
struct PreparedInlineMessage {
    /** Unique identifier of the prepared message. */
    std::string id{""};
    /** Expiration date of the prepared message, in Unix time. */
    int64_t expiration_date{0};
};

/**
 * Describes a keyboard button to be used by a user of a Mini App.
 * @see https://core.telegram.org/bots/api#preparedkeyboardbutton
 */
struct PreparedKeyboardButton {
    /** Unique identifier of the keyboard button. */
    std::string id{""};
};

/**
 * Describes why a request was unsuccessful.
 * @see https://core.telegram.org/bots/api#responseparameters
 */
struct ResponseParameters {
    /** Optional. The group has been migrated to a supergroup with the specified identifier. */
    std::optional<int64_t> migrate_to_chat_id; ///< Optional
    /** Optional. In case of exceeding flood control, the number of seconds left to wait before the request can be repeated. */
    std::optional<int64_t> retry_after; ///< Optional
};

/**
 * Represents an animation file (GIF or H.264/MPEG-4 AVC video without sound) to be sent.
 * @see https://core.telegram.org/bots/api#inputmediaanimation
 */
struct InputMediaAnimation {
    /** Type of the result, must be animation. */
    std::string type{""};
    /** File to send. */
    std::string media{""};
    /** Optional. Thumbnail of the file sent; can be ignored if thumbnail generation for the file is supported server-side. */
    std::optional<std::string> thumbnail; ///< Optional
    /** Optional. Caption of the animation to be sent, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the animation caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. Pass True , if the caption must be shown above the message media. */
    std::optional<bool> show_caption_above_media; ///< Optional
    /** Optional. Animation width. */
    std::optional<int64_t> width; ///< Optional
    /** Optional. Animation height. */
    std::optional<int64_t> height; ///< Optional
    /** Optional. Animation duration in seconds. */
    std::optional<int64_t> duration; ///< Optional
    /** Optional. Pass True if the animation needs to be covered with a spoiler animation. */
    std::optional<bool> has_spoiler; ///< Optional
};

/**
 * Represents an audio file to be treated as music to be sent.
 * @see https://core.telegram.org/bots/api#inputmediaaudio
 */
struct InputMediaAudio {
    /** Type of the result, must be audio. */
    std::string type{""};
    /** File to send. */
    std::string media{""};
    /** Optional. Thumbnail of the file sent; can be ignored if thumbnail generation for the file is supported server-side. */
    std::optional<std::string> thumbnail; ///< Optional
    /** Optional. Caption of the audio to be sent, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the audio caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. Duration of the audio in seconds. */
    std::optional<int64_t> duration; ///< Optional
    /** Optional. Performer of the audio. */
    std::optional<std::string> performer; ///< Optional
    /** Optional. Title of the audio. */
    std::optional<std::string> title; ///< Optional
};

/**
 * Represents a general file to be sent.
 * @see https://core.telegram.org/bots/api#inputmediadocument
 */
struct InputMediaDocument {
    /** Type of the result, must be document. */
    std::string type{""};
    /** File to send. */
    std::string media{""};
    /** Optional. Thumbnail of the file sent; can be ignored if thumbnail generation for the file is supported server-side. */
    std::optional<std::string> thumbnail; ///< Optional
    /** Optional. Caption of the document to be sent, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the document caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. Disables automatic server-side content type detection for files uploaded using multipart/form-data. */
    std::optional<bool> disable_content_type_detection; ///< Optional
};

/**
 * Represents a live photo to be sent.
 * @see https://core.telegram.org/bots/api#inputmedialivephoto
 */
struct InputMediaLivePhoto {
    /** Type of the result, must be live_photo. */
    std::string type{""};
    /** Video of the live photo to send. */
    std::string media{""};
    /** The static photo to send. */
    std::string photo{""};
    /** Optional. Caption of the live photo to be sent, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the live photo caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. Pass True , if the caption must be shown above the message media. */
    std::optional<bool> show_caption_above_media; ///< Optional
    /** Optional. Pass True if the live photo needs to be covered with a spoiler animation. */
    std::optional<bool> has_spoiler; ///< Optional
};

/**
 * Represents a location to be sent.
 * @see https://core.telegram.org/bots/api#inputmedialocation
 */
struct InputMediaLocation {
    /** Type of the result, must be location. */
    std::string type{""};
    /** Latitude of the location. */
    double latitude{0.0};
    /** Longitude of the location. */
    double longitude{0.0};
    /** Optional. The radius of uncertainty for the location, measured in meters; 0-1500. */
    std::optional<double> horizontal_accuracy; ///< Optional
};

/**
 * Represents a photo to be sent.
 * @see https://core.telegram.org/bots/api#inputmediaphoto
 */
struct InputMediaPhoto {
    /** Type of the result, must be photo. */
    std::string type{""};
    /** File to send. */
    std::string media{""};
    /** Optional. Caption of the photo to be sent, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the photo caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. Pass True , if the caption must be shown above the message media. */
    std::optional<bool> show_caption_above_media; ///< Optional
    /** Optional. Pass True if the photo needs to be covered with a spoiler animation. */
    std::optional<bool> has_spoiler; ///< Optional
};

/**
 * Represents a sticker file to be sent.
 * @see https://core.telegram.org/bots/api#inputmediasticker
 */
struct InputMediaSticker {
    /** Type of the result, must be sticker. */
    std::string type{""};
    /** File to send. */
    std::string media{""};
    /** Optional. Emoji associated with the sticker; only for just uploaded stickers. */
    std::optional<std::string> emoji; ///< Optional
};

/**
 * Represents a venue to be sent.
 * @see https://core.telegram.org/bots/api#inputmediavenue
 */
struct InputMediaVenue {
    /** Type of the result, must be venue. */
    std::string type{""};
    /** Latitude of the location. */
    double latitude{0.0};
    /** Longitude of the location. */
    double longitude{0.0};
    /** Name of the venue. */
    std::string title{""};
    /** Address of the venue. */
    std::string address{""};
    /** Optional. Foursquare identifier of the venue. */
    std::optional<std::string> foursquare_id; ///< Optional
    /** Optional. Foursquare type of the venue, if known. */
    std::optional<std::string> foursquare_type; ///< Optional
    /** Optional. Google Places identifier of the venue. */
    std::optional<std::string> google_place_id; ///< Optional
    /** Optional. Google Places type of the venue. */
    std::optional<std::string> google_place_type; ///< Optional
};

/**
 * Represents a video to be sent.
 * @see https://core.telegram.org/bots/api#inputmediavideo
 */
struct InputMediaVideo {
    /** Type of the result, must be video. */
    std::string type{""};
    /** File to send. */
    std::string media{""};
    /** Optional. Thumbnail of the file sent; can be ignored if thumbnail generation for the file is supported server-side. */
    std::optional<std::string> thumbnail; ///< Optional
    /** Optional. Cover for the video in the message. */
    std::optional<std::string> cover; ///< Optional
    /** Optional. Start timestamp for the video in the message. */
    std::optional<int64_t> start_timestamp; ///< Optional
    /** Optional. Caption of the video to be sent, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the video caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. Pass True , if the caption must be shown above the message media. */
    std::optional<bool> show_caption_above_media; ///< Optional
    /** Optional. Video width. */
    std::optional<int64_t> width; ///< Optional
    /** Optional. Video height. */
    std::optional<int64_t> height; ///< Optional
    /** Optional. Video duration in seconds. */
    std::optional<int64_t> duration; ///< Optional
    /** Optional. Pass True if the uploaded video is suitable for streaming. */
    std::optional<bool> supports_streaming; ///< Optional
    /** Optional. Pass True if the video needs to be covered with a spoiler animation. */
    std::optional<bool> has_spoiler; ///< Optional
};

/**
 * Represents a file to be uploaded. Use factory methods to create.
 * @see https://core.telegram.org/bots/api#inputfile
 */
struct InputFile {
    enum class Source { Bytes, FilePath, Url };

    Source               source    = Source::Bytes;
    std::string          filename;
    std::string          mime_type = "application/octet-stream";
    std::vector<uint8_t> data;   ///< Source::Bytes
    std::string          path;   ///< Source::FilePath
    std::string          url;    ///< Source::Url

    static std::shared_ptr<InputFile> from_bytes(
        std::vector<uint8_t> data_, std::string filename_,
        std::string mime_ = "application/octet-stream")
    {
        auto f = std::make_shared<InputFile>();
        f->source = Source::Bytes; f->data = std::move(data_);
        f->filename = std::move(filename_); f->mime_type = std::move(mime_);
        return f;
    }

    static std::shared_ptr<InputFile> from_bytes(
        std::string_view data_, std::string filename_,
        std::string mime_ = "application/octet-stream")
    {
        return from_bytes(std::vector<uint8_t>(data_.begin(), data_.end()),
            std::move(filename_), std::move(mime_));
    }

    static std::shared_ptr<InputFile> from_file(
        std::string path_, std::string filename_ = "",
        std::string mime_ = "application/octet-stream")
    {
        auto f = std::make_shared<InputFile>();
        f->source = Source::FilePath; f->path = path_;
        f->mime_type = std::move(mime_);
        if (filename_.empty()) {
            const auto slash = path_.rfind('/');
            const auto bslash = path_.rfind('\\');
            const auto sep = (bslash != std::string::npos && (slash == std::string::npos || bslash > slash)) ? bslash : slash;
            f->filename = (sep != std::string::npos) ? path_.substr(sep + 1) : path_;
        } else { f->filename = std::move(filename_); }
        return f;
    }

    static std::shared_ptr<InputFile> from_url(
        std::string url_, std::string filename_ = "",
        std::string mime_ = "application/octet-stream")
    {
        auto f = std::make_shared<InputFile>();
        f->source = Source::Url; f->url = url_;
        f->mime_type = std::move(mime_);
        if (filename_.empty()) {
            const auto slash = url_.rfind('/');
            const auto q = url_.rfind('?');
            const auto end = (q != std::string::npos) ? q : url_.size();
            f->filename = (slash != std::string::npos && slash + 1 < end)
                ? url_.substr(slash + 1, end - slash - 1) : "file";
        } else { f->filename = std::move(filename_); }
        return f;
    }

    const std::vector<uint8_t>& bytes() const {
        if (source == Source::Bytes) return data;
        if (source == Source::FilePath) {
            if (!loaded_) {
                std::ifstream ifs(path, std::ios::binary);
                if (!ifs) throw std::runtime_error("[InputFile] Cannot open: " + path);
                loaded_data_ = std::vector<uint8_t>(
                    std::istreambuf_iterator<char>(ifs), {});
                loaded_ = true;
            }
            return loaded_data_;
        }
        throw std::runtime_error("[InputFile] bytes() called on URL source");
    }

private:
    mutable bool                 loaded_      = false;
    mutable std::vector<uint8_t> loaded_data_;
};

struct UploadEntry {
    std::string                field_name;
    std::shared_ptr<InputFile> file;
};


/**
 * The paid media to send is a live photo.
 * @see https://core.telegram.org/bots/api#inputpaidmedialivephoto
 */
struct InputPaidMediaLivePhoto {
    /** Type of the media, must be live_photo. */
    std::string type{""};
    /** Video of the live photo to send. */
    std::string media{""};
    /** The static photo to send. */
    std::string photo{""};
};

/**
 * The paid media to send is a photo.
 * @see https://core.telegram.org/bots/api#inputpaidmediaphoto
 */
struct InputPaidMediaPhoto {
    /** Type of the media, must be photo. */
    std::string type{""};
    /** File to send. */
    std::string media{""};
};

/**
 * The paid media to send is a video.
 * @see https://core.telegram.org/bots/api#inputpaidmediavideo
 */
struct InputPaidMediaVideo {
    /** Type of the media, must be video. */
    std::string type{""};
    /** File to send. */
    std::string media{""};
    /** Optional. Thumbnail of the file sent; can be ignored if thumbnail generation for the file is supported server-side. */
    std::optional<std::string> thumbnail; ///< Optional
    /** Optional. Cover for the video in the message. */
    std::optional<std::string> cover; ///< Optional
    /** Optional. Start timestamp for the video in the message. */
    std::optional<int64_t> start_timestamp; ///< Optional
    /** Optional. Video width. */
    std::optional<int64_t> width; ///< Optional
    /** Optional. Video height. */
    std::optional<int64_t> height; ///< Optional
    /** Optional. Video duration in seconds. */
    std::optional<int64_t> duration; ///< Optional
    /** Optional. Pass True if the uploaded video is suitable for streaming. */
    std::optional<bool> supports_streaming; ///< Optional
};

/**
 * A static profile photo in the .JPG format.
 * @see https://core.telegram.org/bots/api#inputprofilephotostatic
 */
struct InputProfilePhotoStatic {
    /** Type of the profile photo, must be static. */
    std::string type{""};
    /** The static profile photo. */
    std::string photo{""};
};

/**
 * An animated profile photo in the MPEG4 format.
 * @see https://core.telegram.org/bots/api#inputprofilephotoanimated
 */
struct InputProfilePhotoAnimated {
    /** Type of the profile photo, must be animated. */
    std::string type{""};
    /** The animated profile photo. */
    std::string animation{""};
    /** Optional. Timestamp in seconds of the frame that will be used as the static profile photo. */
    std::optional<double> main_frame_timestamp; ///< Optional
};

/**
 * Describes a photo to post as a story.
 * @see https://core.telegram.org/bots/api#inputstorycontentphoto
 */
struct InputStoryContentPhoto {
    /** Type of the content, must be photo. */
    std::string type{""};
    /** The photo to post as a story. */
    std::string photo{""};
};

/**
 * Describes a video to post as a story.
 * @see https://core.telegram.org/bots/api#inputstorycontentvideo
 */
struct InputStoryContentVideo {
    /** Type of the content, must be video. */
    std::string type{""};
    /** The video to post as a story. */
    std::string video{""};
    /** Optional. Precise duration of the video in seconds; 0-60. */
    std::optional<double> duration; ///< Optional
    /** Optional. Timestamp in seconds of the frame that will be used as the static cover for the story. */
    std::optional<double> cover_frame_timestamp; ///< Optional
    /** Optional. Pass True if the video has no sound. */
    std::optional<bool> is_animation; ///< Optional
};

// ── Stickers ────────────────────────────────────────────────────────────────

/**
 * This object represents a sticker.
 * @see https://core.telegram.org/bots/api#sticker
 */
struct Sticker {
    /** Identifier for this file, which can be used to download or reuse the file. */
    std::string file_id{""};
    /** Unique identifier for this file, which is supposed to be the same over time and for different bots. */
    std::string file_unique_id{""};
    /** Type of the sticker, currently one of 'regular', 'mask', 'custom_emoji'. */
    std::string type{""};
    /** Sticker width. */
    int64_t width{0};
    /** Sticker height. */
    int64_t height{0};
    /** True , if the sticker is animated. */
    bool is_animated{false};
    /** True , if the sticker is a video sticker. */
    bool is_video{false};
    /** Optional. Sticker thumbnail in the . */
    std::shared_ptr<PhotoSize> thumbnail; ///< Optional
    /** Optional. Emoji associated with the sticker. */
    std::optional<std::string> emoji; ///< Optional
    /** Optional. Name of the sticker set to which the sticker belongs. */
    std::optional<std::string> set_name; ///< Optional
    /** Optional. For premium regular stickers, premium animation for the sticker. */
    std::shared_ptr<File> premium_animation; ///< Optional
    /** Optional. For mask stickers, the position where the mask should be placed. */
    std::shared_ptr<MaskPosition> mask_position; ///< Optional
    /** Optional. For custom emoji stickers, unique identifier of the custom emoji. */
    std::optional<std::string> custom_emoji_id; ///< Optional
    /** Optional. True , if the sticker must be repainted to a text color in messages, the color of the Telegram Premium badge i. */
    std::optional<bool> needs_repainting; ///< Optional
    /** Optional. File size in bytes. */
    std::optional<int64_t> file_size; ///< Optional
};

/**
 * This object represents a sticker set.
 * @see https://core.telegram.org/bots/api#stickerset
 */
struct StickerSet {
    /** Sticker set name. */
    std::string name{""};
    /** Sticker set title. */
    std::string title{""};
    /** Type of stickers in the set, currently one of 'regular', 'mask', 'custom_emoji'. */
    std::string sticker_type{""};
    /** List of all set stickers. */
    std::vector<std::shared_ptr<Sticker>> stickers;
    /** Optional. Sticker set thumbnail in the . */
    std::shared_ptr<PhotoSize> thumbnail; ///< Optional
};

/**
 * This object describes the position on faces where a mask should be placed by default.
 * @see https://core.telegram.org/bots/api#maskposition
 */
struct MaskPosition {
    /** The part of the face relative to which the mask should be placed. */
    std::string point{""};
    /** Shift by X-axis measured in widths of the mask scaled to the face size, from left to right. */
    double x_shift{0.0};
    /** Shift by Y-axis measured in heights of the mask scaled to the face size, from top to bottom. */
    double y_shift{0.0};
    /** Mask scaling coefficient. */
    double scale{0.0};
};

/**
 * This object describes a sticker to be added to a sticker set.
 * @see https://core.telegram.org/bots/api#inputsticker
 */
struct InputSticker {
    /** The added sticker. */
    std::string sticker{""};
    /** Format of the added sticker, must be one of 'static' for a . */
    std::string format{""};
    /** List of 1-20 emoji associated with the sticker. */
    std::vector<std::string> emoji_list;
    /** Optional. Position where the mask should be placed on faces. */
    std::shared_ptr<MaskPosition> mask_position; ///< Optional
    /** Optional. List of 0-20 search keywords for the sticker with total length of up to 64 characters. */
    std::vector<std::string> keywords; ///< Optional
};

// ── Inline mode ─────────────────────────────────────────────────────────────

/**
 * This object represents an incoming inline query. When the user sends an empty query, your bot
 * could return some default or trending results.
 * @see https://core.telegram.org/bots/api#inlinequery
 */
struct InlineQuery {
    /** Unique identifier for this query. */
    std::string id{""};
    /** Sender. */
    std::shared_ptr<User> from;
    /** Text of the query (up to 256 characters). */
    std::string query{""};
    /** Offset of the results to be returned, can be controlled by the bot. */
    std::string offset{""};
    /** Optional. Type of the chat from which the inline query was sent. */
    std::optional<std::string> chat_type; ///< Optional
    /** Optional. Sender location, only for bots that request user location. */
    std::shared_ptr<Location> location; ///< Optional
};

/**
 * This object represents a button to be shown above inline query results. You must use exactly one
 * of the optional fields.
 * @see https://core.telegram.org/bots/api#inlinequeryresultsbutton
 */
struct InlineQueryResultsButton {
    /** Label text on the button. */
    std::string text{""};
    /** Optional. Description of the Web App that will be launched when the user presses the button. */
    std::shared_ptr<WebAppInfo> web_app; ///< Optional
    /** Optional. Deep-linking parameter for the /start message sent to the bot when a user presses the button. */
    std::optional<std::string> start_parameter; ///< Optional
};

/**
 * Represents a link to an article or web page.
 * @see https://core.telegram.org/bots/api#inlinequeryresultarticle
 */
struct InlineQueryResultArticle {
    /** Type of the result, must be article. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 Bytes. */
    std::string id{""};
    /** Title of the result. */
    std::string title{""};
    /** Content of the message to be sent. */
    InputMessageContent input_message_content{};
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
    /** Optional. URL of the result. */
    std::optional<std::string> url; ///< Optional
    /** Optional. Short description of the result. */
    std::optional<std::string> description; ///< Optional
    /** Optional. Url of the thumbnail for the result. */
    std::optional<std::string> thumbnail_url; ///< Optional
    /** Optional. Thumbnail width. */
    std::optional<int64_t> thumbnail_width; ///< Optional
    /** Optional. Thumbnail height. */
    std::optional<int64_t> thumbnail_height; ///< Optional
};

/**
 * Represents a link to a photo. By default, this photo will be sent by the user with optional
 * caption. Alternatively, you can use input_message_content to send a message with the specified
 * content instead of the photo.
 * @see https://core.telegram.org/bots/api#inlinequeryresultphoto
 */
struct InlineQueryResultPhoto {
    /** Type of the result, must be photo. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 bytes. */
    std::string id{""};
    /** A valid URL of the photo. */
    std::string photo_url{""};
    /** URL of the thumbnail for the photo. */
    std::string thumbnail_url{""};
    /** Optional. Width of the photo. */
    std::optional<int64_t> photo_width; ///< Optional
    /** Optional. Height of the photo. */
    std::optional<int64_t> photo_height; ///< Optional
    /** Optional. Title for the result. */
    std::optional<std::string> title; ///< Optional
    /** Optional. Short description of the result. */
    std::optional<std::string> description; ///< Optional
    /** Optional. Caption of the photo to be sent, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the photo caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. Pass True , if the caption must be shown above the message media. */
    std::optional<bool> show_caption_above_media; ///< Optional
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
    /** Optional. Content of the message to be sent instead of the photo. */
    std::optional<InputMessageContent> input_message_content; ///< Optional
};

/**
 * Represents a link to an animated GIF file. By default, this animated GIF file will be sent by the
 * user with optional caption. Alternatively, you can use input_message_content to send a message
 * with the specified content instead of the animation.
 * @see https://core.telegram.org/bots/api#inlinequeryresultgif
 */
struct InlineQueryResultGif {
    /** Type of the result, must be gif. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 bytes. */
    std::string id{""};
    /** A valid URL for the GIF file. */
    std::string gif_url{""};
    /** Optional. Width of the GIF. */
    std::optional<int64_t> gif_width; ///< Optional
    /** Optional. Height of the GIF. */
    std::optional<int64_t> gif_height; ///< Optional
    /** Optional. Duration of the GIF in seconds. */
    std::optional<int64_t> gif_duration; ///< Optional
    /** URL of the static (JPEG or GIF) or animated (MPEG4) thumbnail for the result. */
    std::string thumbnail_url{""};
    /** Optional. MIME type of the thumbnail, must be one of 'image/jpeg', 'image/gif', or 'video/mp4'. */
    std::optional<std::string> thumbnail_mime_type; ///< Optional
    /** Optional. Title for the result. */
    std::optional<std::string> title; ///< Optional
    /** Optional. Caption of the GIF file to be sent, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. Pass True , if the caption must be shown above the message media. */
    std::optional<bool> show_caption_above_media; ///< Optional
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
    /** Optional. Content of the message to be sent instead of the GIF animation. */
    std::optional<InputMessageContent> input_message_content; ///< Optional
};

/**
 * Represents a link to a video animation (H.264/MPEG-4 AVC video without sound). By default, this
 * animated MPEG-4 file will be sent by the user with optional caption. Alternatively, you can use
 * input_message_content to send a message with the specified content instead of the animation.
 * @see https://core.telegram.org/bots/api#inlinequeryresultmpeg4gif
 */
struct InlineQueryResultMpeg4Gif {
    /** Type of the result, must be mpeg4_gif. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 bytes. */
    std::string id{""};
    /** A valid URL for the MPEG4 file. */
    std::string mpeg4_url{""};
    /** Optional. Video width. */
    std::optional<int64_t> mpeg4_width; ///< Optional
    /** Optional. Video height. */
    std::optional<int64_t> mpeg4_height; ///< Optional
    /** Optional. Video duration in seconds. */
    std::optional<int64_t> mpeg4_duration; ///< Optional
    /** URL of the static (JPEG or GIF) or animated (MPEG4) thumbnail for the result. */
    std::string thumbnail_url{""};
    /** Optional. MIME type of the thumbnail, must be one of 'image/jpeg', 'image/gif', or 'video/mp4'. */
    std::optional<std::string> thumbnail_mime_type; ///< Optional
    /** Optional. Title for the result. */
    std::optional<std::string> title; ///< Optional
    /** Optional. Caption of the MPEG-4 file to be sent, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. Pass True , if the caption must be shown above the message media. */
    std::optional<bool> show_caption_above_media; ///< Optional
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
    /** Optional. Content of the message to be sent instead of the video animation. */
    std::optional<InputMessageContent> input_message_content; ///< Optional
};

/**
 * Represents a link to a page containing an embedded video player or a video file. By default, this
 * video file will be sent by the user with an optional caption. Alternatively, you can use
 * input_message_content to send a message with the specified content instead of the video.
 * If an InlineQueryResultVideo message contains an embedded video (e.g., YouTube), you must replace
 * its content using input_message_content.
 * @see https://core.telegram.org/bots/api#inlinequeryresultvideo
 */
struct InlineQueryResultVideo {
    /** Type of the result, must be video. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 bytes. */
    std::string id{""};
    /** A valid URL for the embedded video player or video file. */
    std::string video_url{""};
    /** MIME type of the content of the video URL, 'text/html' or 'video/mp4'. */
    std::string mime_type{""};
    /** URL of the thumbnail (JPEG only) for the video. */
    std::string thumbnail_url{""};
    /** Title for the result. */
    std::string title{""};
    /** Optional. Caption of the video to be sent, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the video caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. Pass True , if the caption must be shown above the message media. */
    std::optional<bool> show_caption_above_media; ///< Optional
    /** Optional. Video width. */
    std::optional<int64_t> video_width; ///< Optional
    /** Optional. Video height. */
    std::optional<int64_t> video_height; ///< Optional
    /** Optional. Video duration in seconds. */
    std::optional<int64_t> video_duration; ///< Optional
    /** Optional. Short description of the result. */
    std::optional<std::string> description; ///< Optional
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
    /** Optional. Content of the message to be sent instead of the video. */
    std::optional<InputMessageContent> input_message_content; ///< Optional
};

/**
 * Represents a link to an MP3 audio file. By default, this audio file will be sent by the user.
 * Alternatively, you can use input_message_content to send a message with the specified content
 * instead of the audio.
 * @see https://core.telegram.org/bots/api#inlinequeryresultaudio
 */
struct InlineQueryResultAudio {
    /** Type of the result, must be audio. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 bytes. */
    std::string id{""};
    /** A valid URL for the audio file. */
    std::string audio_url{""};
    /** Title. */
    std::string title{""};
    /** Optional. Caption, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the audio caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. Performer. */
    std::optional<std::string> performer; ///< Optional
    /** Optional. Audio duration in seconds. */
    std::optional<int64_t> audio_duration; ///< Optional
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
    /** Optional. Content of the message to be sent instead of the audio. */
    std::optional<InputMessageContent> input_message_content; ///< Optional
};

/**
 * Represents a link to a voice recording in an .OGG container encoded with OPUS. By default, this
 * voice recording will be sent by the user. Alternatively, you can use input_message_content to
 * send a message with the specified content instead of the the voice message.
 * @see https://core.telegram.org/bots/api#inlinequeryresultvoice
 */
struct InlineQueryResultVoice {
    /** Type of the result, must be voice. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 bytes. */
    std::string id{""};
    /** A valid URL for the voice recording. */
    std::string voice_url{""};
    /** Recording title. */
    std::string title{""};
    /** Optional. Caption, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the voice message caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. Recording duration in seconds. */
    std::optional<int64_t> voice_duration; ///< Optional
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
    /** Optional. Content of the message to be sent instead of the voice recording. */
    std::optional<InputMessageContent> input_message_content; ///< Optional
};

/**
 * Represents a link to a file. By default, this file will be sent by the user with an optional
 * caption. Alternatively, you can use input_message_content to send a message with the specified
 * content instead of the file. Currently, only .PDF and .ZIP files can be sent using this method.
 * @see https://core.telegram.org/bots/api#inlinequeryresultdocument
 */
struct InlineQueryResultDocument {
    /** Type of the result, must be document. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 bytes. */
    std::string id{""};
    /** Title for the result. */
    std::string title{""};
    /** Optional. Caption of the document to be sent, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the document caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** A valid URL for the file. */
    std::string document_url{""};
    /** MIME type of the content of the file, either 'application/pdf' or 'application/zip'. */
    std::string mime_type{""};
    /** Optional. Short description of the result. */
    std::optional<std::string> description; ///< Optional
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
    /** Optional. Content of the message to be sent instead of the file. */
    std::optional<InputMessageContent> input_message_content; ///< Optional
    /** Optional. URL of the thumbnail (JPEG only) for the file. */
    std::optional<std::string> thumbnail_url; ///< Optional
    /** Optional. Thumbnail width. */
    std::optional<int64_t> thumbnail_width; ///< Optional
    /** Optional. Thumbnail height. */
    std::optional<int64_t> thumbnail_height; ///< Optional
};

/**
 * Represents a location on a map. By default, the location will be sent by the user. Alternatively,
 * you can use input_message_content to send a message with the specified content instead of the
 * location.
 * @see https://core.telegram.org/bots/api#inlinequeryresultlocation
 */
struct InlineQueryResultLocation {
    /** Type of the result, must be location. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 Bytes. */
    std::string id{""};
    /** Location latitude in degrees. */
    double latitude{0.0};
    /** Location longitude in degrees. */
    double longitude{0.0};
    /** Location title. */
    std::string title{""};
    /** Optional. The radius of uncertainty for the location, measured in meters; 0-1500. */
    std::optional<double> horizontal_accuracy; ///< Optional
    /** Optional. Period in seconds during which the location can be updated, must be between 60 and 86400, or 0x7FFFFFFF for li. */
    std::optional<int64_t> live_period; ///< Optional
    /** Optional. For live locations, a direction in which the user is moving, in degrees. */
    std::optional<int64_t> heading; ///< Optional
    /** Optional. For live locations, a maximum distance for proximity alerts about approaching another chat member, in meters. */
    std::optional<int64_t> proximity_alert_radius; ///< Optional
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
    /** Optional. Content of the message to be sent instead of the location. */
    std::optional<InputMessageContent> input_message_content; ///< Optional
    /** Optional. Url of the thumbnail for the result. */
    std::optional<std::string> thumbnail_url; ///< Optional
    /** Optional. Thumbnail width. */
    std::optional<int64_t> thumbnail_width; ///< Optional
    /** Optional. Thumbnail height. */
    std::optional<int64_t> thumbnail_height; ///< Optional
};

/**
 * Represents a venue. By default, the venue will be sent by the user. Alternatively, you can use
 * input_message_content to send a message with the specified content instead of the venue.
 * @see https://core.telegram.org/bots/api#inlinequeryresultvenue
 */
struct InlineQueryResultVenue {
    /** Type of the result, must be venue. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 Bytes. */
    std::string id{""};
    /** Latitude of the venue location in degrees. */
    double latitude{0.0};
    /** Longitude of the venue location in degrees. */
    double longitude{0.0};
    /** Title of the venue. */
    std::string title{""};
    /** Address of the venue. */
    std::string address{""};
    /** Optional. Foursquare identifier of the venue if known. */
    std::optional<std::string> foursquare_id; ///< Optional
    /** Optional. Foursquare type of the venue, if known. */
    std::optional<std::string> foursquare_type; ///< Optional
    /** Optional. Google Places identifier of the venue. */
    std::optional<std::string> google_place_id; ///< Optional
    /** Optional. Google Places type of the venue. */
    std::optional<std::string> google_place_type; ///< Optional
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
    /** Optional. Content of the message to be sent instead of the venue. */
    std::optional<InputMessageContent> input_message_content; ///< Optional
    /** Optional. Url of the thumbnail for the result. */
    std::optional<std::string> thumbnail_url; ///< Optional
    /** Optional. Thumbnail width. */
    std::optional<int64_t> thumbnail_width; ///< Optional
    /** Optional. Thumbnail height. */
    std::optional<int64_t> thumbnail_height; ///< Optional
};

/**
 * Represents a contact with a phone number. By default, this contact will be sent by the user.
 * Alternatively, you can use input_message_content to send a message with the specified content
 * instead of the contact.
 * @see https://core.telegram.org/bots/api#inlinequeryresultcontact
 */
struct InlineQueryResultContact {
    /** Type of the result, must be contact. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 Bytes. */
    std::string id{""};
    /** Contact's phone number. */
    std::string phone_number{""};
    /** Contact's first name. */
    std::string first_name{""};
    /** Optional. Contact's last name. */
    std::optional<std::string> last_name; ///< Optional
    /** Optional. Additional data about the contact in the form of a vCard , 0-2048 bytes. */
    std::optional<std::string> vcard; ///< Optional
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
    /** Optional. Content of the message to be sent instead of the contact. */
    std::optional<InputMessageContent> input_message_content; ///< Optional
    /** Optional. Url of the thumbnail for the result. */
    std::optional<std::string> thumbnail_url; ///< Optional
    /** Optional. Thumbnail width. */
    std::optional<int64_t> thumbnail_width; ///< Optional
    /** Optional. Thumbnail height. */
    std::optional<int64_t> thumbnail_height; ///< Optional
};

/**
 * Represents a Game.
 * @see https://core.telegram.org/bots/api#inlinequeryresultgame
 */
struct InlineQueryResultGame {
    /** Type of the result, must be game. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 bytes. */
    std::string id{""};
    /** Short name of the game. */
    std::string game_short_name{""};
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
};

/**
 * Represents a link to a photo stored on the Telegram servers. By default, this photo will be sent
 * by the user with an optional caption. Alternatively, you can use input_message_content to send a
 * message with the specified content instead of the photo.
 * @see https://core.telegram.org/bots/api#inlinequeryresultcachedphoto
 */
struct InlineQueryResultCachedPhoto {
    /** Type of the result, must be photo. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 bytes. */
    std::string id{""};
    /** A valid file identifier of the photo. */
    std::string photo_file_id{""};
    /** Optional. Title for the result. */
    std::optional<std::string> title; ///< Optional
    /** Optional. Short description of the result. */
    std::optional<std::string> description; ///< Optional
    /** Optional. Caption of the photo to be sent, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the photo caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. Pass True , if the caption must be shown above the message media. */
    std::optional<bool> show_caption_above_media; ///< Optional
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
    /** Optional. Content of the message to be sent instead of the photo. */
    std::optional<InputMessageContent> input_message_content; ///< Optional
};

/**
 * Represents a link to an animated GIF file stored on the Telegram servers. By default, this
 * animated GIF file will be sent by the user with an optional caption. Alternatively, you can use
 * input_message_content to send a message with specified content instead of the animation.
 * @see https://core.telegram.org/bots/api#inlinequeryresultcachedgif
 */
struct InlineQueryResultCachedGif {
    /** Type of the result, must be gif. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 bytes. */
    std::string id{""};
    /** A valid file identifier for the GIF file. */
    std::string gif_file_id{""};
    /** Optional. Title for the result. */
    std::optional<std::string> title; ///< Optional
    /** Optional. Caption of the GIF file to be sent, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. Pass True , if the caption must be shown above the message media. */
    std::optional<bool> show_caption_above_media; ///< Optional
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
    /** Optional. Content of the message to be sent instead of the GIF animation. */
    std::optional<InputMessageContent> input_message_content; ///< Optional
};

/**
 * Represents a link to a video animation (H.264/MPEG-4 AVC video without sound) stored on the
 * Telegram servers. By default, this animated MPEG-4 file will be sent by the user with an optional
 * caption. Alternatively, you can use input_message_content to send a message with the specified
 * content instead of the animation.
 * @see https://core.telegram.org/bots/api#inlinequeryresultcachedmpeg4gif
 */
struct InlineQueryResultCachedMpeg4Gif {
    /** Type of the result, must be mpeg4_gif. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 bytes. */
    std::string id{""};
    /** A valid file identifier for the MPEG4 file. */
    std::string mpeg4_file_id{""};
    /** Optional. Title for the result. */
    std::optional<std::string> title; ///< Optional
    /** Optional. Caption of the MPEG-4 file to be sent, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. Pass True , if the caption must be shown above the message media. */
    std::optional<bool> show_caption_above_media; ///< Optional
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
    /** Optional. Content of the message to be sent instead of the video animation. */
    std::optional<InputMessageContent> input_message_content; ///< Optional
};

/**
 * Represents a link to a sticker stored on the Telegram servers. By default, this sticker will be
 * sent by the user. Alternatively, you can use input_message_content to send a message with the
 * specified content instead of the sticker.
 * @see https://core.telegram.org/bots/api#inlinequeryresultcachedsticker
 */
struct InlineQueryResultCachedSticker {
    /** Type of the result, must be sticker. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 bytes. */
    std::string id{""};
    /** A valid file identifier of the sticker. */
    std::string sticker_file_id{""};
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
    /** Optional. Content of the message to be sent instead of the sticker. */
    std::optional<InputMessageContent> input_message_content; ///< Optional
};

/**
 * Represents a link to a file stored on the Telegram servers. By default, this file will be sent by
 * the user with an optional caption. Alternatively, you can use input_message_content to send a
 * message with the specified content instead of the file.
 * @see https://core.telegram.org/bots/api#inlinequeryresultcacheddocument
 */
struct InlineQueryResultCachedDocument {
    /** Type of the result, must be document. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 bytes. */
    std::string id{""};
    /** Title for the result. */
    std::string title{""};
    /** A valid file identifier for the file. */
    std::string document_file_id{""};
    /** Optional. Short description of the result. */
    std::optional<std::string> description; ///< Optional
    /** Optional. Caption of the document to be sent, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the document caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
    /** Optional. Content of the message to be sent instead of the file. */
    std::optional<InputMessageContent> input_message_content; ///< Optional
};

/**
 * Represents a link to a video file stored on the Telegram servers. By default, this video file
 * will be sent by the user with an optional caption. Alternatively, you can use
 * input_message_content to send a message with the specified content instead of the video.
 * @see https://core.telegram.org/bots/api#inlinequeryresultcachedvideo
 */
struct InlineQueryResultCachedVideo {
    /** Type of the result, must be video. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 bytes. */
    std::string id{""};
    /** A valid file identifier for the video file. */
    std::string video_file_id{""};
    /** Title for the result. */
    std::string title{""};
    /** Optional. Short description of the result. */
    std::optional<std::string> description; ///< Optional
    /** Optional. Caption of the video to be sent, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the video caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. Pass True , if the caption must be shown above the message media. */
    std::optional<bool> show_caption_above_media; ///< Optional
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
    /** Optional. Content of the message to be sent instead of the video. */
    std::optional<InputMessageContent> input_message_content; ///< Optional
};

/**
 * Represents a link to a voice message stored on the Telegram servers. By default, this voice
 * message will be sent by the user. Alternatively, you can use input_message_content to send a
 * message with the specified content instead of the voice message.
 * @see https://core.telegram.org/bots/api#inlinequeryresultcachedvoice
 */
struct InlineQueryResultCachedVoice {
    /** Type of the result, must be voice. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 bytes. */
    std::string id{""};
    /** A valid file identifier for the voice message. */
    std::string voice_file_id{""};
    /** Voice message title. */
    std::string title{""};
    /** Optional. Caption, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the voice message caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
    /** Optional. Content of the message to be sent instead of the voice message. */
    std::optional<InputMessageContent> input_message_content; ///< Optional
};

/**
 * Represents a link to an MP3 audio file stored on the Telegram servers. By default, this audio
 * file will be sent by the user. Alternatively, you can use input_message_content to send a message
 * with the specified content instead of the audio.
 * @see https://core.telegram.org/bots/api#inlinequeryresultcachedaudio
 */
struct InlineQueryResultCachedAudio {
    /** Type of the result, must be audio. */
    std::string type{""};
    /** Unique identifier for this result, 1-64 bytes. */
    std::string id{""};
    /** A valid file identifier for the audio file. */
    std::string audio_file_id{""};
    /** Optional. Caption, 0-1024 characters after entities parsing. */
    std::optional<std::string> caption; ///< Optional
    /** Optional. Mode for parsing entities in the audio caption. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in the caption, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> caption_entities; ///< Optional
    /** Optional. Inline keyboard attached to the message. */
    std::shared_ptr<InlineKeyboardMarkup> reply_markup; ///< Optional
    /** Optional. Content of the message to be sent instead of the audio. */
    std::optional<InputMessageContent> input_message_content; ///< Optional
};

/**
 * Represents the content of a text message to be sent as the result of an inline query.
 * @see https://core.telegram.org/bots/api#inputtextmessagecontent
 */
struct InputTextMessageContent {
    /** Text of the message to be sent, 1-4096 characters. */
    std::string message_text{""};
    /** Optional. Mode for parsing entities in the message text. */
    std::optional<std::string> parse_mode; ///< Optional
    /** Optional. List of special entities that appear in message text, which can be specified instead of parse_mode. */
    std::vector<std::shared_ptr<MessageEntity>> entities; ///< Optional
    /** Optional. Link preview generation options for the message. */
    std::shared_ptr<LinkPreviewOptions> link_preview_options; ///< Optional
};

/**
 * Represents the content of a location message to be sent as the result of an inline query.
 * @see https://core.telegram.org/bots/api#inputlocationmessagecontent
 */
struct InputLocationMessageContent {
    /** Latitude of the location in degrees. */
    double latitude{0.0};
    /** Longitude of the location in degrees. */
    double longitude{0.0};
    /** Optional. The radius of uncertainty for the location, measured in meters; 0-1500. */
    std::optional<double> horizontal_accuracy; ///< Optional
    /** Optional. Period in seconds during which the location can be updated, must be between 60 and 86400, or 0x7FFFFFFF for li. */
    std::optional<int64_t> live_period; ///< Optional
    /** Optional. For live locations, a direction in which the user is moving, in degrees. */
    std::optional<int64_t> heading; ///< Optional
    /** Optional. For live locations, a maximum distance for proximity alerts about approaching another chat member, in meters. */
    std::optional<int64_t> proximity_alert_radius; ///< Optional
};

/**
 * Represents the content of a venue message to be sent as the result of an inline query.
 * @see https://core.telegram.org/bots/api#inputvenuemessagecontent
 */
struct InputVenueMessageContent {
    /** Latitude of the venue in degrees. */
    double latitude{0.0};
    /** Longitude of the venue in degrees. */
    double longitude{0.0};
    /** Name of the venue. */
    std::string title{""};
    /** Address of the venue. */
    std::string address{""};
    /** Optional. Foursquare identifier of the venue, if known. */
    std::optional<std::string> foursquare_id; ///< Optional
    /** Optional. Foursquare type of the venue, if known. */
    std::optional<std::string> foursquare_type; ///< Optional
    /** Optional. Google Places identifier of the venue. */
    std::optional<std::string> google_place_id; ///< Optional
    /** Optional. Google Places type of the venue. */
    std::optional<std::string> google_place_type; ///< Optional
};

/**
 * Represents the content of a contact message to be sent as the result of an inline query.
 * @see https://core.telegram.org/bots/api#inputcontactmessagecontent
 */
struct InputContactMessageContent {
    /** Contact's phone number. */
    std::string phone_number{""};
    /** Contact's first name. */
    std::string first_name{""};
    /** Optional. Contact's last name. */
    std::optional<std::string> last_name; ///< Optional
    /** Optional. Additional data about the contact in the form of a vCard , 0-2048 bytes. */
    std::optional<std::string> vcard; ///< Optional
};

/**
 * Represents the content of an invoice message to be sent as the result of an inline query.
 * @see https://core.telegram.org/bots/api#inputinvoicemessagecontent
 */
struct InputInvoiceMessageContent {
    /** Product name, 1-32 characters. */
    std::string title{""};
    /** Product description, 1-255 characters. */
    std::string description{""};
    /** Bot-defined invoice payload, 1-128 bytes. */
    std::string invoice_payload{""};
    /** Optional. Payment provider token, obtained via @BotFather . */
    std::optional<std::string> provider_token; ///< Optional
    /** Three-letter ISO 4217 currency code, see more on currencies . */
    std::string currency{""};
    /** Price breakdown, a JSON-serialized list of components (e. */
    std::vector<std::shared_ptr<LabeledPrice>> prices;
    /** Optional. The maximum accepted amount for tips in the smallest units of the currency (integer, not float/double). */
    std::optional<int64_t> max_tip_amount; ///< Optional
    /** Optional. A JSON-serialized array of suggested amounts of tip in the smallest units of the currency (integer, not float/. */
    std::vector<int64_t> suggested_tip_amounts; ///< Optional
    /** Optional. A JSON-serialized object for data about the invoice, which will be shared with the payment provider. */
    std::optional<std::string> provider_data; ///< Optional
    /** Optional. URL of the product photo for the invoice. */
    std::optional<std::string> photo_url; ///< Optional
    /** Optional. Photo size in bytes. */
    std::optional<int64_t> photo_size; ///< Optional
    /** Optional. Photo width. */
    std::optional<int64_t> photo_width; ///< Optional
    /** Optional. Photo height. */
    std::optional<int64_t> photo_height; ///< Optional
    /** Optional. Pass True if you require the user's full name to complete the order. */
    std::optional<bool> need_name; ///< Optional
    /** Optional. Pass True if you require the user's phone number to complete the order. */
    std::optional<bool> need_phone_number; ///< Optional
    /** Optional. Pass True if you require the user's email address to complete the order. */
    std::optional<bool> need_email; ///< Optional
    /** Optional. Pass True if you require the user's shipping address to complete the order. */
    std::optional<bool> need_shipping_address; ///< Optional
    /** Optional. Pass True if the user's phone number should be sent to the provider. */
    std::optional<bool> send_phone_number_to_provider; ///< Optional
    /** Optional. Pass True if the user's email address should be sent to the provider. */
    std::optional<bool> send_email_to_provider; ///< Optional
    /** Optional. Pass True if the final price depends on the shipping method. */
    std::optional<bool> is_flexible; ///< Optional
};

/**
 * Represents a result of an inline query that was chosen by the user and sent to their chat
 * partner.
 * @see https://core.telegram.org/bots/api#choseninlineresult
 */
struct ChosenInlineResult {
    /** The unique identifier for the result that was chosen. */
    std::string result_id{""};
    /** The user that chose the result. */
    std::shared_ptr<User> from;
    /** Optional. Sender location, only for bots that require user location. */
    std::shared_ptr<Location> location; ///< Optional
    /** Optional. Identifier of the sent inline message. */
    std::optional<std::string> inline_message_id; ///< Optional
    /** The query that was used to obtain the result. */
    std::string query{""};
};

// ── Payments ────────────────────────────────────────────────────────────────

/**
 * This object represents a portion of the price for goods or services.
 * @see https://core.telegram.org/bots/api#labeledprice
 */
struct LabeledPrice {
    /** Portion label. */
    std::string label{""};
    /** Price of the product in the smallest units of the currency (integer, not float/double). */
    int64_t amount{0};
};

/**
 * This object contains basic information about an invoice.
 * @see https://core.telegram.org/bots/api#invoice
 */
struct Invoice {
    /** Product name. */
    std::string title{""};
    /** Product description. */
    std::string description{""};
    /** Unique bot deep-linking parameter that can be used to generate this invoice. */
    std::string start_parameter{""};
    /** Three-letter ISO 4217 currency code, or 'XTR' for payments in Telegram Stars. */
    std::string currency{""};
    /** Total price in the smallest units of the currency (integer, not float/double). */
    int64_t total_amount{0};
};

/**
 * This object represents a shipping address.
 * @see https://core.telegram.org/bots/api#shippingaddress
 */
struct ShippingAddress {
    /** Two-letter ISO 3166-1 alpha-2 country code. */
    std::string country_code{""};
    /** State, if applicable. */
    std::string state{""};
    /** City. */
    std::string city{""};
    /** First line for the address. */
    std::string street_line1{""};
    /** Second line for the address. */
    std::string street_line2{""};
    /** Address post code. */
    std::string post_code{""};
};

/**
 * This object represents information about an order.
 * @see https://core.telegram.org/bots/api#orderinfo
 */
struct OrderInfo {
    /** Optional. User name. */
    std::optional<std::string> name; ///< Optional
    /** Optional. User's phone number. */
    std::optional<std::string> phone_number; ///< Optional
    /** Optional. User email. */
    std::optional<std::string> email; ///< Optional
    /** Optional. User shipping address. */
    std::shared_ptr<ShippingAddress> shipping_address; ///< Optional
};

/**
 * This object represents one shipping option.
 * @see https://core.telegram.org/bots/api#shippingoption
 */
struct ShippingOption {
    /** Shipping option identifier. */
    std::string id{""};
    /** Option title. */
    std::string title{""};
    /** List of price portions. */
    std::vector<std::shared_ptr<LabeledPrice>> prices;
};

/**
 * This object contains basic information about a successful payment. Note that if the buyer
 * initiates a chargeback with the relevant payment provider following this transaction, the funds
 * may be debited from your balance. This is outside of Telegram's control.
 * @see https://core.telegram.org/bots/api#successfulpayment
 */
struct SuccessfulPayment {
    /** Three-letter ISO 4217 currency code, or 'XTR' for payments in Telegram Stars. */
    std::string currency{""};
    /** Total price in the smallest units of the currency (integer, not float/double). */
    int64_t total_amount{0};
    /** Bot-specified invoice payload. */
    std::string invoice_payload{""};
    /** Optional. Expiration date of the subscription, in Unix time; for recurring payments only. */
    std::optional<int64_t> subscription_expiration_date; ///< Optional
    /** Optional. True , if the payment is a recurring payment for a subscription. */
    std::optional<bool> is_recurring; ///< Optional
    /** Optional. True , if the payment is the first payment for a subscription. */
    std::optional<bool> is_first_recurring; ///< Optional
    /** Optional. Identifier of the shipping option chosen by the user. */
    std::optional<std::string> shipping_option_id; ///< Optional
    /** Optional. Order information provided by the user. */
    std::shared_ptr<OrderInfo> order_info; ///< Optional
    /** Telegram payment identifier. */
    std::string telegram_payment_charge_id{""};
    /** Provider payment identifier. */
    std::string provider_payment_charge_id{""};
};

/**
 * This object contains basic information about a refunded payment.
 * @see https://core.telegram.org/bots/api#refundedpayment
 */
struct RefundedPayment {
    /** Three-letter ISO 4217 currency code, or 'XTR' for payments in Telegram Stars . */
    std::string currency{""};
    /** Total refunded price in the smallest units of the currency (integer, not float/double). */
    int64_t total_amount{0};
    /** Bot-specified invoice payload. */
    std::string invoice_payload{""};
    /** Telegram payment identifier. */
    std::string telegram_payment_charge_id{""};
    /** Optional. Provider payment identifier. */
    std::optional<std::string> provider_payment_charge_id; ///< Optional
};

/**
 * This object contains information about an incoming shipping query.
 * @see https://core.telegram.org/bots/api#shippingquery
 */
struct ShippingQuery {
    /** Unique query identifier. */
    std::string id{""};
    /** User who sent the query. */
    std::shared_ptr<User> from;
    /** Bot-specified invoice payload. */
    std::string invoice_payload{""};
    /** User specified shipping address. */
    std::shared_ptr<ShippingAddress> shipping_address;
};

/**
 * This object contains information about an incoming pre-checkout query.
 * @see https://core.telegram.org/bots/api#precheckoutquery
 */
struct PreCheckoutQuery {
    /** Unique query identifier. */
    std::string id{""};
    /** User who sent the query. */
    std::shared_ptr<User> from;
    /** Three-letter ISO 4217 currency code, or 'XTR' for payments in Telegram Stars. */
    std::string currency{""};
    /** Total price in the smallest units of the currency (integer, not float/double). */
    int64_t total_amount{0};
    /** Bot-specified invoice payload. */
    std::string invoice_payload{""};
    /** Optional. Identifier of the shipping option chosen by the user. */
    std::optional<std::string> shipping_option_id; ///< Optional
    /** Optional. Order information provided by the user. */
    std::shared_ptr<OrderInfo> order_info; ///< Optional
};

/**
 * This object contains information about a paid media purchase.
 * @see https://core.telegram.org/bots/api#paidmediapurchased
 */
struct PaidMediaPurchased {
    /** User who purchased the media. */
    std::shared_ptr<User> from;
    /** Bot-specified paid media payload. */
    std::string paid_media_payload{""};
};

/**
 * The withdrawal is in progress.
 * @see https://core.telegram.org/bots/api#revenuewithdrawalstatepending
 */
struct RevenueWithdrawalStatePending {
    /** Type of the state, always 'pending'. */
    std::string type{""};
};

/**
 * The withdrawal succeeded.
 * @see https://core.telegram.org/bots/api#revenuewithdrawalstatesucceeded
 */
struct RevenueWithdrawalStateSucceeded {
    /** Type of the state, always 'succeeded'. */
    std::string type{""};
    /** Date the withdrawal was completed in Unix time. */
    int64_t date{0};
    /** An HTTPS URL that can be used to see transaction details. */
    std::string url{""};
};

/**
 * The withdrawal failed and the transaction was refunded.
 * @see https://core.telegram.org/bots/api#revenuewithdrawalstatefailed
 */
struct RevenueWithdrawalStateFailed {
    /** Type of the state, always 'failed'. */
    std::string type{""};
};

/**
 * Contains information about the affiliate that received a commission via this transaction.
 * @see https://core.telegram.org/bots/api#affiliateinfo
 */
struct AffiliateInfo {
    /** Optional. The bot or the user that received an affiliate commission if it was received by a bot or a user. */
    std::shared_ptr<User> affiliate_user; ///< Optional
    /** Optional. The chat that received an affiliate commission if it was received by a chat. */
    std::shared_ptr<Chat> affiliate_chat; ///< Optional
    /** The number of Telegram Stars received by the affiliate for each 1000 Telegram Stars received by the bot from referred us. */
    int64_t commission_per_mille{0};
    /** Integer amount of Telegram Stars received by the affiliate from the transaction, rounded to 0; can be negative for refun. */
    int64_t amount{0};
    /** Optional. The number of 1/1000000000 shares of Telegram Stars received by the affiliate; from -999999999 to 999999999; c. */
    std::optional<int64_t> nanostar_amount; ///< Optional
};

/**
 * Describes a transaction with a user.
 * @see https://core.telegram.org/bots/api#transactionpartneruser
 */
struct TransactionPartnerUser {
    /** Type of the transaction partner, always 'user'. */
    std::string type{""};
    /** Type of the transaction, currently one of 'invoice_payment' for payments via invoices, 'paid_media_payment' for payments. */
    std::string transaction_type{""};
    /** Information about the user. */
    std::shared_ptr<User> user;
    /** Optional. Information about the affiliate that received a commission via this transaction. */
    std::shared_ptr<AffiliateInfo> affiliate; ///< Optional
    /** Optional. Bot-specified invoice payload. */
    std::optional<std::string> invoice_payload; ///< Optional
    /** Optional. The duration of the paid subscription. */
    std::optional<int64_t> subscription_period; ///< Optional
    /** Optional. Information about the paid media bought by the user; for 'paid_media_payment' transactions only. */
    std::vector<PaidMedia> paid_media; ///< Optional
    /** Optional. Bot-specified paid media payload. */
    std::optional<std::string> paid_media_payload; ///< Optional
    /** Optional. The gift sent to the user by the bot; for 'gift_purchase' transactions only. */
    std::shared_ptr<Gift> gift; ///< Optional
    /** Optional. Number of months the gifted Telegram Premium subscription will be active for; for 'premium_purchase' transacti. */
    std::optional<int64_t> premium_subscription_duration; ///< Optional
};

/**
 * Describes a transaction with a chat.
 * @see https://core.telegram.org/bots/api#transactionpartnerchat
 */
struct TransactionPartnerChat {
    /** Type of the transaction partner, always 'chat'. */
    std::string type{""};
    /** Information about the chat. */
    std::shared_ptr<Chat> chat;
    /** Optional. The gift sent to the chat by the bot. */
    std::shared_ptr<Gift> gift; ///< Optional
};

/**
 * Describes the affiliate program that issued the affiliate commission received via this
 * transaction.
 * @see https://core.telegram.org/bots/api#transactionpartneraffiliateprogram
 */
struct TransactionPartnerAffiliateProgram {
    /** Type of the transaction partner, always 'affiliate_program'. */
    std::string type{""};
    /** Optional. Information about the bot that sponsored the affiliate program. */
    std::shared_ptr<User> sponsor_user; ///< Optional
    /** The number of Telegram Stars received by the bot for each 1000 Telegram Stars received by the affiliate program sponsor . */
    int64_t commission_per_mille{0};
};

/**
 * Describes a withdrawal transaction with Fragment.
 * @see https://core.telegram.org/bots/api#transactionpartnerfragment
 */
struct TransactionPartnerFragment {
    /** Type of the transaction partner, always 'fragment'. */
    std::string type{""};
    /** Optional. State of the transaction if the transaction is outgoing. */
    std::optional<RevenueWithdrawalState> withdrawal_state; ///< Optional
};

/**
 * Describes a withdrawal transaction to the Telegram Ads platform.
 * @see https://core.telegram.org/bots/api#transactionpartnertelegramads
 */
struct TransactionPartnerTelegramAds {
    /** Type of the transaction partner, always 'telegram_ads'. */
    std::string type{""};
};

/**
 * Describes a transaction with payment for paid broadcasting.
 * @see https://core.telegram.org/bots/api#transactionpartnertelegramapi
 */
struct TransactionPartnerTelegramApi {
    /** Type of the transaction partner, always 'telegram_api'. */
    std::string type{""};
    /** The number of successful requests that exceeded regular limits and were therefore billed. */
    int64_t request_count{0};
};

/**
 * Describes a transaction with an unknown source or recipient.
 * @see https://core.telegram.org/bots/api#transactionpartnerother
 */
struct TransactionPartnerOther {
    /** Type of the transaction partner, always 'other'. */
    std::string type{""};
};

/**
 * Describes a Telegram Star transaction. Note that if the buyer initiates a chargeback with the
 * payment provider from whom they acquired Stars (e.g., Apple, Google) following this transaction,
 * the refunded Stars will be deducted from the bot's balance. This is outside of Telegram's
 * control.
 * @see https://core.telegram.org/bots/api#startransaction
 */
struct StarTransaction {
    /** Unique identifier of the transaction. */
    std::string id{""};
    /** Integer amount of Telegram Stars transferred by the transaction. */
    int64_t amount{0};
    /** Optional. The number of 1/1000000000 shares of Telegram Stars transferred by the transaction; from 0 to 999999999. */
    std::optional<int64_t> nanostar_amount; ///< Optional
    /** Date the transaction was created in Unix time. */
    int64_t date{0};
    /** Optional. Source of an incoming transaction (e. */
    std::optional<TransactionPartner> source; ///< Optional
    /** Optional. Receiver of an outgoing transaction (e. */
    std::optional<TransactionPartner> receiver; ///< Optional
};

/**
 * Contains a list of Telegram Star transactions.
 * @see https://core.telegram.org/bots/api#startransactions
 */
struct StarTransactions {
    /** The list of transactions. */
    std::vector<std::shared_ptr<StarTransaction>> transactions;
};

// ── Telegram Passport ───────────────────────────────────────────────────────

/**
 * Describes Telegram Passport data shared with the bot by the user.
 * @see https://core.telegram.org/bots/api#passportdata
 */
struct PassportData {
    /** Array with information about documents and other Telegram Passport elements that was shared with the bot. */
    std::vector<std::shared_ptr<EncryptedPassportElement>> data;
    /** Encrypted credentials required to decrypt the data. */
    std::shared_ptr<EncryptedCredentials> credentials;
};

/**
 * This object represents a file uploaded to Telegram Passport. Currently all Telegram Passport
 * files are in JPEG format when decrypted and don't exceed 10MB.
 * @see https://core.telegram.org/bots/api#passportfile
 */
struct PassportFile {
    /** Identifier for this file, which can be used to download or reuse the file. */
    std::string file_id{""};
    /** Unique identifier for this file, which is supposed to be the same over time and for different bots. */
    std::string file_unique_id{""};
    /** File size in bytes. */
    int64_t file_size{0};
    /** Unix time when the file was uploaded. */
    int64_t file_date{0};
};

/**
 * Describes documents or other Telegram Passport elements shared with the bot by the user.
 * @see https://core.telegram.org/bots/api#encryptedpassportelement
 */
struct EncryptedPassportElement {
    /** Element type. */
    std::string type{""};
    /** Optional. Base64-encoded encrypted Telegram Passport element data provided by the user; available only for 'personal_det. */
    std::optional<std::string> data; ///< Optional
    /** Optional. User's verified phone number; available only for 'phone_number' type. */
    std::optional<std::string> phone_number; ///< Optional
    /** Optional. User's verified email address; available only for 'email' type. */
    std::optional<std::string> email; ///< Optional
    /** Optional. Array of encrypted files with documents provided by the user; available only for 'utility_bill', 'bank_stateme. */
    std::vector<std::shared_ptr<PassportFile>> files; ///< Optional
    /** Optional. Encrypted file with the front side of the document, provided by the user; available only for 'passport', 'driv. */
    std::shared_ptr<PassportFile> front_side; ///< Optional
    /** Optional. Encrypted file with the reverse side of the document, provided by the user; available only for 'driver_license. */
    std::shared_ptr<PassportFile> reverse_side; ///< Optional
    /** Optional. Encrypted file with the selfie of the user holding a document, provided by the user; available if requested fo. */
    std::shared_ptr<PassportFile> selfie; ///< Optional
    /** Optional. Array of encrypted files with translated versions of documents provided by the user; available if requested fo. */
    std::vector<std::shared_ptr<PassportFile>> translation; ///< Optional
    /** Base64-encoded element hash for using in PassportElementErrorUnspecified. */
    std::string hash{""};
};

/**
 * Describes data required for decrypting and authenticating EncryptedPassportElement. See the
 * Telegram Passport Documentation for a complete description of the data decryption and
 * authentication processes.
 * @see https://core.telegram.org/bots/api#encryptedcredentials
 */
struct EncryptedCredentials {
    /** Base64-encoded encrypted JSON-serialized data with unique user's payload, data hashes and secrets required for Encrypted. */
    std::string data{""};
    /** Base64-encoded data hash for data authentication. */
    std::string hash{""};
    /** Base64-encoded secret, encrypted with the bot's public RSA key, required for data decryption. */
    std::string secret{""};
};

/**
 * Represents an issue in one of the data fields that was provided by the user. The error is
 * considered resolved when the field's value changes.
 * @see https://core.telegram.org/bots/api#passportelementerrordatafield
 */
struct PassportElementErrorDataField {
    /** Error source, must be data. */
    std::string source{""};
    /** The section of the user's Telegram Passport which has the error, one of 'personal_details', 'passport', 'driver_license'. */
    std::string type{""};
    /** Name of the data field which has the error. */
    std::string field_name{""};
    /** Base64-encoded data hash. */
    std::string data_hash{""};
    /** Error message. */
    std::string message{""};
};

/**
 * Represents an issue with the front side of a document. The error is considered resolved when the
 * file with the front side of the document changes.
 * @see https://core.telegram.org/bots/api#passportelementerrorfrontside
 */
struct PassportElementErrorFrontSide {
    /** Error source, must be front_side. */
    std::string source{""};
    /** The section of the user's Telegram Passport which has the issue, one of 'passport', 'driver_license', 'identity_card', '. */
    std::string type{""};
    /** Base64-encoded hash of the file with the front side of the document. */
    std::string file_hash{""};
    /** Error message. */
    std::string message{""};
};

/**
 * Represents an issue with the reverse side of a document. The error is considered resolved when
 * the file with reverse side of the document changes.
 * @see https://core.telegram.org/bots/api#passportelementerrorreverseside
 */
struct PassportElementErrorReverseSide {
    /** Error source, must be reverse_side. */
    std::string source{""};
    /** The section of the user's Telegram Passport which has the issue, one of 'driver_license', 'identity_card'. */
    std::string type{""};
    /** Base64-encoded hash of the file with the reverse side of the document. */
    std::string file_hash{""};
    /** Error message. */
    std::string message{""};
};

/**
 * Represents an issue with the selfie with a document. The error is considered resolved when the
 * file with the selfie changes.
 * @see https://core.telegram.org/bots/api#passportelementerrorselfie
 */
struct PassportElementErrorSelfie {
    /** Error source, must be selfie. */
    std::string source{""};
    /** The section of the user's Telegram Passport which has the issue, one of 'passport', 'driver_license', 'identity_card', '. */
    std::string type{""};
    /** Base64-encoded hash of the file with the selfie. */
    std::string file_hash{""};
    /** Error message. */
    std::string message{""};
};

/**
 * Represents an issue with a document scan. The error is considered resolved when the file with the
 * document scan changes.
 * @see https://core.telegram.org/bots/api#passportelementerrorfile
 */
struct PassportElementErrorFile {
    /** Error source, must be file. */
    std::string source{""};
    /** The section of the user's Telegram Passport which has the issue, one of 'utility_bill', 'bank_statement', 'rental_agreem. */
    std::string type{""};
    /** Base64-encoded file hash. */
    std::string file_hash{""};
    /** Error message. */
    std::string message{""};
};

/**
 * Represents an issue with a list of scans. The error is considered resolved when the list of files
 * containing the scans changes.
 * @see https://core.telegram.org/bots/api#passportelementerrorfiles
 */
struct PassportElementErrorFiles {
    /** Error source, must be files. */
    std::string source{""};
    /** The section of the user's Telegram Passport which has the issue, one of 'utility_bill', 'bank_statement', 'rental_agreem. */
    std::string type{""};
    /** List of base64-encoded file hashes. */
    std::vector<std::string> file_hashes;
    /** Error message. */
    std::string message{""};
};

/**
 * Represents an issue with one of the files that constitute the translation of a document. The
 * error is considered resolved when the file changes.
 * @see https://core.telegram.org/bots/api#passportelementerrortranslationfile
 */
struct PassportElementErrorTranslationFile {
    /** Error source, must be translation_file. */
    std::string source{""};
    /** Type of element of the user's Telegram Passport which has the issue, one of 'passport', 'driver_license', 'identity_card. */
    std::string type{""};
    /** Base64-encoded file hash. */
    std::string file_hash{""};
    /** Error message. */
    std::string message{""};
};

/**
 * Represents an issue with the translated version of a document. The error is considered resolved
 * when a file with the document translation change.
 * @see https://core.telegram.org/bots/api#passportelementerrortranslationfiles
 */
struct PassportElementErrorTranslationFiles {
    /** Error source, must be translation_files. */
    std::string source{""};
    /** Type of element of the user's Telegram Passport which has the issue, one of 'passport', 'driver_license', 'identity_card. */
    std::string type{""};
    /** List of base64-encoded file hashes. */
    std::vector<std::string> file_hashes;
    /** Error message. */
    std::string message{""};
};

/**
 * Represents an issue in an unspecified place. The error is considered resolved when new data is
 * added.
 * @see https://core.telegram.org/bots/api#passportelementerrorunspecified
 */
struct PassportElementErrorUnspecified {
    /** Error source, must be unspecified. */
    std::string source{""};
    /** Type of element of the user's Telegram Passport which has the issue. */
    std::string type{""};
    /** Base64-encoded element hash. */
    std::string element_hash{""};
    /** Error message. */
    std::string message{""};
};

// ── Games ───────────────────────────────────────────────────────────────────

/**
 * This object represents a game. Use BotFather to create and edit games, their short names will act
 * as unique identifiers.
 * @see https://core.telegram.org/bots/api#game
 */
struct Game {
    /** Title of the game. */
    std::string title{""};
    /** Description of the game. */
    std::string description{""};
    /** Photo that will be displayed in the game message in chats. */
    std::vector<std::shared_ptr<PhotoSize>> photo;
    /** Optional. Brief description of the game or high scores included in the game message. */
    std::optional<std::string> text; ///< Optional
    /** Optional. Special entities that appear in text , such as usernames, URLs, bot commands, etc. */
    std::vector<std::shared_ptr<MessageEntity>> text_entities; ///< Optional
    /** Optional. Animation that will be displayed in the game message in chats. */
    std::shared_ptr<Animation> animation; ///< Optional
};

/**
 * A placeholder, currently holds no information. Use BotFather to set up your game.
 * @see https://core.telegram.org/bots/api#callbackgame
 */
struct CallbackGame {
};

/**
 * This object represents one row of the high scores table for a game.
 * @see https://core.telegram.org/bots/api#gamehighscore
 */
struct GameHighScore {
    /** Position in high score table for the game. */
    int64_t position{0};
    /** User. */
    std::shared_ptr<User> user;
    /** Score. */
    int64_t score{0};
};

// ── JSON serialisation — forward declarations ────────────────

inline void from_json(const json& j, AcceptedGiftTypes& o);
inline void to_json(json& j, const AcceptedGiftTypes& o);
inline void from_json(const json& j, AffiliateInfo& o);
inline void to_json(json& j, const AffiliateInfo& o);
inline void from_json(const json& j, Animation& o);
inline void to_json(json& j, const Animation& o);
inline void from_json(const json& j, Audio& o);
inline void to_json(json& j, const Audio& o);
inline void from_json(const json& j, BackgroundFill& o);
inline void to_json(json& j, const BackgroundFill& o);
inline void from_json(const json& j, BackgroundFillFreeformGradient& o);
inline void to_json(json& j, const BackgroundFillFreeformGradient& o);
inline void from_json(const json& j, BackgroundFillGradient& o);
inline void to_json(json& j, const BackgroundFillGradient& o);
inline void from_json(const json& j, BackgroundFillSolid& o);
inline void to_json(json& j, const BackgroundFillSolid& o);
inline void from_json(const json& j, BackgroundType& o);
inline void to_json(json& j, const BackgroundType& o);
inline void from_json(const json& j, BackgroundTypeChatTheme& o);
inline void to_json(json& j, const BackgroundTypeChatTheme& o);
inline void from_json(const json& j, BackgroundTypeFill& o);
inline void to_json(json& j, const BackgroundTypeFill& o);
inline void from_json(const json& j, BackgroundTypePattern& o);
inline void to_json(json& j, const BackgroundTypePattern& o);
inline void from_json(const json& j, BackgroundTypeWallpaper& o);
inline void to_json(json& j, const BackgroundTypeWallpaper& o);
inline void from_json(const json& j, Birthdate& o);
inline void to_json(json& j, const Birthdate& o);
inline void from_json(const json& j, BotAccessSettings& o);
inline void to_json(json& j, const BotAccessSettings& o);
inline void from_json(const json& j, BotCommand& o);
inline void to_json(json& j, const BotCommand& o);
inline void from_json(const json& j, BotCommandScope& o);
inline void to_json(json& j, const BotCommandScope& o);
inline void from_json(const json& j, BotCommandScopeAllChatAdministrators& o);
inline void to_json(json& j, const BotCommandScopeAllChatAdministrators& o);
inline void from_json(const json& j, BotCommandScopeAllGroupChats& o);
inline void to_json(json& j, const BotCommandScopeAllGroupChats& o);
inline void from_json(const json& j, BotCommandScopeAllPrivateChats& o);
inline void to_json(json& j, const BotCommandScopeAllPrivateChats& o);
inline void from_json(const json& j, BotCommandScopeChat& o);
inline void to_json(json& j, const BotCommandScopeChat& o);
inline void from_json(const json& j, BotCommandScopeChatAdministrators& o);
inline void to_json(json& j, const BotCommandScopeChatAdministrators& o);
inline void from_json(const json& j, BotCommandScopeChatMember& o);
inline void to_json(json& j, const BotCommandScopeChatMember& o);
inline void from_json(const json& j, BotCommandScopeDefault& o);
inline void to_json(json& j, const BotCommandScopeDefault& o);
inline void from_json(const json& j, BotDescription& o);
inline void to_json(json& j, const BotDescription& o);
inline void from_json(const json& j, BotName& o);
inline void to_json(json& j, const BotName& o);
inline void from_json(const json& j, BotShortDescription& o);
inline void to_json(json& j, const BotShortDescription& o);
inline void from_json(const json& j, BusinessBotRights& o);
inline void to_json(json& j, const BusinessBotRights& o);
inline void from_json(const json& j, BusinessConnection& o);
inline void to_json(json& j, const BusinessConnection& o);
inline void from_json(const json& j, BusinessIntro& o);
inline void to_json(json& j, const BusinessIntro& o);
inline void from_json(const json& j, BusinessLocation& o);
inline void to_json(json& j, const BusinessLocation& o);
inline void from_json(const json& j, BusinessMessagesDeleted& o);
inline void to_json(json& j, const BusinessMessagesDeleted& o);
inline void from_json(const json& j, BusinessOpeningHours& o);
inline void to_json(json& j, const BusinessOpeningHours& o);
inline void from_json(const json& j, BusinessOpeningHoursInterval& o);
inline void to_json(json& j, const BusinessOpeningHoursInterval& o);
inline void from_json(const json& j, CallbackGame& o);
inline void to_json(json& j, const CallbackGame& o);
inline void from_json(const json& j, CallbackQuery& o);
inline void to_json(json& j, const CallbackQuery& o);
inline void from_json(const json& j, Chat& o);
inline void to_json(json& j, const Chat& o);
inline void from_json(const json& j, ChatAdministratorRights& o);
inline void to_json(json& j, const ChatAdministratorRights& o);
inline void from_json(const json& j, ChatBackground& o);
inline void to_json(json& j, const ChatBackground& o);
inline void from_json(const json& j, ChatBoost& o);
inline void to_json(json& j, const ChatBoost& o);
inline void from_json(const json& j, ChatBoostAdded& o);
inline void to_json(json& j, const ChatBoostAdded& o);
inline void from_json(const json& j, ChatBoostRemoved& o);
inline void to_json(json& j, const ChatBoostRemoved& o);
inline void from_json(const json& j, ChatBoostSource& o);
inline void to_json(json& j, const ChatBoostSource& o);
inline void from_json(const json& j, ChatBoostSourceGiftCode& o);
inline void to_json(json& j, const ChatBoostSourceGiftCode& o);
inline void from_json(const json& j, ChatBoostSourceGiveaway& o);
inline void to_json(json& j, const ChatBoostSourceGiveaway& o);
inline void from_json(const json& j, ChatBoostSourcePremium& o);
inline void to_json(json& j, const ChatBoostSourcePremium& o);
inline void from_json(const json& j, ChatBoostUpdated& o);
inline void to_json(json& j, const ChatBoostUpdated& o);
inline void from_json(const json& j, ChatFullInfo& o);
inline void to_json(json& j, const ChatFullInfo& o);
inline void from_json(const json& j, ChatInviteLink& o);
inline void to_json(json& j, const ChatInviteLink& o);
inline void from_json(const json& j, ChatJoinRequest& o);
inline void to_json(json& j, const ChatJoinRequest& o);
inline void from_json(const json& j, ChatLocation& o);
inline void to_json(json& j, const ChatLocation& o);
inline void from_json(const json& j, ChatMember& o);
inline void to_json(json& j, const ChatMember& o);
inline void from_json(const json& j, ChatMemberAdministrator& o);
inline void to_json(json& j, const ChatMemberAdministrator& o);
inline void from_json(const json& j, ChatMemberBanned& o);
inline void to_json(json& j, const ChatMemberBanned& o);
inline void from_json(const json& j, ChatMemberLeft& o);
inline void to_json(json& j, const ChatMemberLeft& o);
inline void from_json(const json& j, ChatMemberMember& o);
inline void to_json(json& j, const ChatMemberMember& o);
inline void from_json(const json& j, ChatMemberOwner& o);
inline void to_json(json& j, const ChatMemberOwner& o);
inline void from_json(const json& j, ChatMemberRestricted& o);
inline void to_json(json& j, const ChatMemberRestricted& o);
inline void from_json(const json& j, ChatMemberUpdated& o);
inline void to_json(json& j, const ChatMemberUpdated& o);
inline void from_json(const json& j, ChatOwnerChanged& o);
inline void to_json(json& j, const ChatOwnerChanged& o);
inline void from_json(const json& j, ChatOwnerLeft& o);
inline void to_json(json& j, const ChatOwnerLeft& o);
inline void from_json(const json& j, ChatPermissions& o);
inline void to_json(json& j, const ChatPermissions& o);
inline void from_json(const json& j, ChatPhoto& o);
inline void to_json(json& j, const ChatPhoto& o);
inline void from_json(const json& j, ChatShared& o);
inline void to_json(json& j, const ChatShared& o);
inline void from_json(const json& j, Checklist& o);
inline void to_json(json& j, const Checklist& o);
inline void from_json(const json& j, ChecklistTask& o);
inline void to_json(json& j, const ChecklistTask& o);
inline void from_json(const json& j, ChecklistTasksAdded& o);
inline void to_json(json& j, const ChecklistTasksAdded& o);
inline void from_json(const json& j, ChecklistTasksDone& o);
inline void to_json(json& j, const ChecklistTasksDone& o);
inline void from_json(const json& j, ChosenInlineResult& o);
inline void to_json(json& j, const ChosenInlineResult& o);
inline void from_json(const json& j, Contact& o);
inline void to_json(json& j, const Contact& o);
inline void from_json(const json& j, CopyTextButton& o);
inline void to_json(json& j, const CopyTextButton& o);
inline void from_json(const json& j, Dice& o);
inline void to_json(json& j, const Dice& o);
inline void from_json(const json& j, DirectMessagePriceChanged& o);
inline void to_json(json& j, const DirectMessagePriceChanged& o);
inline void from_json(const json& j, DirectMessagesTopic& o);
inline void to_json(json& j, const DirectMessagesTopic& o);
inline void from_json(const json& j, Document& o);
inline void to_json(json& j, const Document& o);
inline void from_json(const json& j, EncryptedCredentials& o);
inline void to_json(json& j, const EncryptedCredentials& o);
inline void from_json(const json& j, EncryptedPassportElement& o);
inline void to_json(json& j, const EncryptedPassportElement& o);
inline void from_json(const json& j, ExternalReplyInfo& o);
inline void to_json(json& j, const ExternalReplyInfo& o);
inline void from_json(const json& j, File& o);
inline void to_json(json& j, const File& o);
inline void from_json(const json& j, ForceReply& o);
inline void to_json(json& j, const ForceReply& o);
inline void from_json(const json& j, ForumTopic& o);
inline void to_json(json& j, const ForumTopic& o);
inline void from_json(const json& j, ForumTopicClosed& o);
inline void to_json(json& j, const ForumTopicClosed& o);
inline void from_json(const json& j, ForumTopicCreated& o);
inline void to_json(json& j, const ForumTopicCreated& o);
inline void from_json(const json& j, ForumTopicEdited& o);
inline void to_json(json& j, const ForumTopicEdited& o);
inline void from_json(const json& j, ForumTopicReopened& o);
inline void to_json(json& j, const ForumTopicReopened& o);
inline void from_json(const json& j, Game& o);
inline void to_json(json& j, const Game& o);
inline void from_json(const json& j, GameHighScore& o);
inline void to_json(json& j, const GameHighScore& o);
inline void from_json(const json& j, GeneralForumTopicHidden& o);
inline void to_json(json& j, const GeneralForumTopicHidden& o);
inline void from_json(const json& j, GeneralForumTopicUnhidden& o);
inline void to_json(json& j, const GeneralForumTopicUnhidden& o);
inline void from_json(const json& j, Gift& o);
inline void to_json(json& j, const Gift& o);
inline void from_json(const json& j, GiftBackground& o);
inline void to_json(json& j, const GiftBackground& o);
inline void from_json(const json& j, GiftInfo& o);
inline void to_json(json& j, const GiftInfo& o);
inline void from_json(const json& j, Gifts& o);
inline void to_json(json& j, const Gifts& o);
inline void from_json(const json& j, Giveaway& o);
inline void to_json(json& j, const Giveaway& o);
inline void from_json(const json& j, GiveawayCompleted& o);
inline void to_json(json& j, const GiveawayCompleted& o);
inline void from_json(const json& j, GiveawayCreated& o);
inline void to_json(json& j, const GiveawayCreated& o);
inline void from_json(const json& j, GiveawayWinners& o);
inline void to_json(json& j, const GiveawayWinners& o);
inline void from_json(const json& j, InaccessibleMessage& o);
inline void to_json(json& j, const InaccessibleMessage& o);
inline void from_json(const json& j, InlineKeyboardButton& o);
inline void to_json(json& j, const InlineKeyboardButton& o);
inline void from_json(const json& j, InlineKeyboardMarkup& o);
inline void to_json(json& j, const InlineKeyboardMarkup& o);
inline void from_json(const json& j, InlineQuery& o);
inline void to_json(json& j, const InlineQuery& o);
inline void from_json(const json& j, InlineQueryResult& o);
inline void to_json(json& j, const InlineQueryResult& o);
inline void from_json(const json& j, InlineQueryResultArticle& o);
inline void to_json(json& j, const InlineQueryResultArticle& o);
inline void from_json(const json& j, InlineQueryResultAudio& o);
inline void to_json(json& j, const InlineQueryResultAudio& o);
inline void from_json(const json& j, InlineQueryResultCachedAudio& o);
inline void to_json(json& j, const InlineQueryResultCachedAudio& o);
inline void from_json(const json& j, InlineQueryResultCachedDocument& o);
inline void to_json(json& j, const InlineQueryResultCachedDocument& o);
inline void from_json(const json& j, InlineQueryResultCachedGif& o);
inline void to_json(json& j, const InlineQueryResultCachedGif& o);
inline void from_json(const json& j, InlineQueryResultCachedMpeg4Gif& o);
inline void to_json(json& j, const InlineQueryResultCachedMpeg4Gif& o);
inline void from_json(const json& j, InlineQueryResultCachedPhoto& o);
inline void to_json(json& j, const InlineQueryResultCachedPhoto& o);
inline void from_json(const json& j, InlineQueryResultCachedSticker& o);
inline void to_json(json& j, const InlineQueryResultCachedSticker& o);
inline void from_json(const json& j, InlineQueryResultCachedVideo& o);
inline void to_json(json& j, const InlineQueryResultCachedVideo& o);
inline void from_json(const json& j, InlineQueryResultCachedVoice& o);
inline void to_json(json& j, const InlineQueryResultCachedVoice& o);
inline void from_json(const json& j, InlineQueryResultContact& o);
inline void to_json(json& j, const InlineQueryResultContact& o);
inline void from_json(const json& j, InlineQueryResultDocument& o);
inline void to_json(json& j, const InlineQueryResultDocument& o);
inline void from_json(const json& j, InlineQueryResultGame& o);
inline void to_json(json& j, const InlineQueryResultGame& o);
inline void from_json(const json& j, InlineQueryResultGif& o);
inline void to_json(json& j, const InlineQueryResultGif& o);
inline void from_json(const json& j, InlineQueryResultLocation& o);
inline void to_json(json& j, const InlineQueryResultLocation& o);
inline void from_json(const json& j, InlineQueryResultMpeg4Gif& o);
inline void to_json(json& j, const InlineQueryResultMpeg4Gif& o);
inline void from_json(const json& j, InlineQueryResultPhoto& o);
inline void to_json(json& j, const InlineQueryResultPhoto& o);
inline void from_json(const json& j, InlineQueryResultVenue& o);
inline void to_json(json& j, const InlineQueryResultVenue& o);
inline void from_json(const json& j, InlineQueryResultVideo& o);
inline void to_json(json& j, const InlineQueryResultVideo& o);
inline void from_json(const json& j, InlineQueryResultVoice& o);
inline void to_json(json& j, const InlineQueryResultVoice& o);
inline void from_json(const json& j, InlineQueryResultsButton& o);
inline void to_json(json& j, const InlineQueryResultsButton& o);
inline void from_json(const json& j, InputChecklist& o);
inline void to_json(json& j, const InputChecklist& o);
inline void from_json(const json& j, InputChecklistTask& o);
inline void to_json(json& j, const InputChecklistTask& o);
inline void from_json(const json& j, InputContactMessageContent& o);
inline void to_json(json& j, const InputContactMessageContent& o);
inline void from_json(const json& j, InputInvoiceMessageContent& o);
inline void to_json(json& j, const InputInvoiceMessageContent& o);
inline void from_json(const json& j, InputLocationMessageContent& o);
inline void to_json(json& j, const InputLocationMessageContent& o);
inline void from_json(const json& j, InputMedia& o);
inline void to_json(json& j, const InputMedia& o);
inline void from_json(const json& j, InputMediaAnimation& o);
inline void to_json(json& j, const InputMediaAnimation& o);
inline void from_json(const json& j, InputMediaAudio& o);
inline void to_json(json& j, const InputMediaAudio& o);
inline void from_json(const json& j, InputMediaDocument& o);
inline void to_json(json& j, const InputMediaDocument& o);
inline void from_json(const json& j, InputMediaLivePhoto& o);
inline void to_json(json& j, const InputMediaLivePhoto& o);
inline void from_json(const json& j, InputMediaLocation& o);
inline void to_json(json& j, const InputMediaLocation& o);
inline void from_json(const json& j, InputMediaPhoto& o);
inline void to_json(json& j, const InputMediaPhoto& o);
inline void from_json(const json& j, InputMediaSticker& o);
inline void to_json(json& j, const InputMediaSticker& o);
inline void from_json(const json& j, InputMediaVenue& o);
inline void to_json(json& j, const InputMediaVenue& o);
inline void from_json(const json& j, InputMediaVideo& o);
inline void to_json(json& j, const InputMediaVideo& o);
inline void from_json(const json& j, InputMessageContent& o);
inline void to_json(json& j, const InputMessageContent& o);
inline void from_json(const json& j, InputPaidMedia& o);
inline void to_json(json& j, const InputPaidMedia& o);
inline void from_json(const json& j, InputPaidMediaLivePhoto& o);
inline void to_json(json& j, const InputPaidMediaLivePhoto& o);
inline void from_json(const json& j, InputPaidMediaPhoto& o);
inline void to_json(json& j, const InputPaidMediaPhoto& o);
inline void from_json(const json& j, InputPaidMediaVideo& o);
inline void to_json(json& j, const InputPaidMediaVideo& o);
inline void from_json(const json& j, InputPollMedia& o);
inline void to_json(json& j, const InputPollMedia& o);
inline void from_json(const json& j, InputPollOption& o);
inline void to_json(json& j, const InputPollOption& o);
inline void from_json(const json& j, InputPollOptionMedia& o);
inline void to_json(json& j, const InputPollOptionMedia& o);
inline void from_json(const json& j, InputProfilePhoto& o);
inline void to_json(json& j, const InputProfilePhoto& o);
inline void from_json(const json& j, InputProfilePhotoAnimated& o);
inline void to_json(json& j, const InputProfilePhotoAnimated& o);
inline void from_json(const json& j, InputProfilePhotoStatic& o);
inline void to_json(json& j, const InputProfilePhotoStatic& o);
inline void from_json(const json& j, InputSticker& o);
inline void to_json(json& j, const InputSticker& o);
inline void from_json(const json& j, InputStoryContent& o);
inline void to_json(json& j, const InputStoryContent& o);
inline void from_json(const json& j, InputStoryContentPhoto& o);
inline void to_json(json& j, const InputStoryContentPhoto& o);
inline void from_json(const json& j, InputStoryContentVideo& o);
inline void to_json(json& j, const InputStoryContentVideo& o);
inline void from_json(const json& j, InputTextMessageContent& o);
inline void to_json(json& j, const InputTextMessageContent& o);
inline void from_json(const json& j, InputVenueMessageContent& o);
inline void to_json(json& j, const InputVenueMessageContent& o);
inline void from_json(const json& j, Invoice& o);
inline void to_json(json& j, const Invoice& o);
inline void from_json(const json& j, KeyboardButton& o);
inline void to_json(json& j, const KeyboardButton& o);
inline void from_json(const json& j, KeyboardButtonPollType& o);
inline void to_json(json& j, const KeyboardButtonPollType& o);
inline void from_json(const json& j, KeyboardButtonRequestChat& o);
inline void to_json(json& j, const KeyboardButtonRequestChat& o);
inline void from_json(const json& j, KeyboardButtonRequestManagedBot& o);
inline void to_json(json& j, const KeyboardButtonRequestManagedBot& o);
inline void from_json(const json& j, KeyboardButtonRequestUsers& o);
inline void to_json(json& j, const KeyboardButtonRequestUsers& o);
inline void from_json(const json& j, LabeledPrice& o);
inline void to_json(json& j, const LabeledPrice& o);
inline void from_json(const json& j, LinkPreviewOptions& o);
inline void to_json(json& j, const LinkPreviewOptions& o);
inline void from_json(const json& j, LivePhoto& o);
inline void to_json(json& j, const LivePhoto& o);
inline void from_json(const json& j, Location& o);
inline void to_json(json& j, const Location& o);
inline void from_json(const json& j, LocationAddress& o);
inline void to_json(json& j, const LocationAddress& o);
inline void from_json(const json& j, LoginUrl& o);
inline void to_json(json& j, const LoginUrl& o);
inline void from_json(const json& j, ManagedBotCreated& o);
inline void to_json(json& j, const ManagedBotCreated& o);
inline void from_json(const json& j, ManagedBotUpdated& o);
inline void to_json(json& j, const ManagedBotUpdated& o);
inline void from_json(const json& j, MaskPosition& o);
inline void to_json(json& j, const MaskPosition& o);
inline void from_json(const json& j, MaybeInaccessibleMessage& o);
inline void to_json(json& j, const MaybeInaccessibleMessage& o);
inline void from_json(const json& j, MenuButton& o);
inline void to_json(json& j, const MenuButton& o);
inline void from_json(const json& j, MenuButtonCommands& o);
inline void to_json(json& j, const MenuButtonCommands& o);
inline void from_json(const json& j, MenuButtonDefault& o);
inline void to_json(json& j, const MenuButtonDefault& o);
inline void from_json(const json& j, MenuButtonWebApp& o);
inline void to_json(json& j, const MenuButtonWebApp& o);
inline void from_json(const json& j, Message& o);
inline void to_json(json& j, const Message& o);
inline void from_json(const json& j, MessageAutoDeleteTimerChanged& o);
inline void to_json(json& j, const MessageAutoDeleteTimerChanged& o);
inline void from_json(const json& j, MessageEntity& o);
inline void to_json(json& j, const MessageEntity& o);
inline void from_json(const json& j, MessageId& o);
inline void to_json(json& j, const MessageId& o);
inline void from_json(const json& j, MessageOrigin& o);
inline void to_json(json& j, const MessageOrigin& o);
inline void from_json(const json& j, MessageOriginChannel& o);
inline void to_json(json& j, const MessageOriginChannel& o);
inline void from_json(const json& j, MessageOriginChat& o);
inline void to_json(json& j, const MessageOriginChat& o);
inline void from_json(const json& j, MessageOriginHiddenUser& o);
inline void to_json(json& j, const MessageOriginHiddenUser& o);
inline void from_json(const json& j, MessageOriginUser& o);
inline void to_json(json& j, const MessageOriginUser& o);
inline void from_json(const json& j, MessageReactionCountUpdated& o);
inline void to_json(json& j, const MessageReactionCountUpdated& o);
inline void from_json(const json& j, MessageReactionUpdated& o);
inline void to_json(json& j, const MessageReactionUpdated& o);
inline void from_json(const json& j, OrderInfo& o);
inline void to_json(json& j, const OrderInfo& o);
inline void from_json(const json& j, OwnedGift& o);
inline void to_json(json& j, const OwnedGift& o);
inline void from_json(const json& j, OwnedGiftRegular& o);
inline void to_json(json& j, const OwnedGiftRegular& o);
inline void from_json(const json& j, OwnedGiftUnique& o);
inline void to_json(json& j, const OwnedGiftUnique& o);
inline void from_json(const json& j, OwnedGifts& o);
inline void to_json(json& j, const OwnedGifts& o);
inline void from_json(const json& j, PaidMedia& o);
inline void to_json(json& j, const PaidMedia& o);
inline void from_json(const json& j, PaidMediaInfo& o);
inline void to_json(json& j, const PaidMediaInfo& o);
inline void from_json(const json& j, PaidMediaLivePhoto& o);
inline void to_json(json& j, const PaidMediaLivePhoto& o);
inline void from_json(const json& j, PaidMediaPhoto& o);
inline void to_json(json& j, const PaidMediaPhoto& o);
inline void from_json(const json& j, PaidMediaPreview& o);
inline void to_json(json& j, const PaidMediaPreview& o);
inline void from_json(const json& j, PaidMediaPurchased& o);
inline void to_json(json& j, const PaidMediaPurchased& o);
inline void from_json(const json& j, PaidMediaVideo& o);
inline void to_json(json& j, const PaidMediaVideo& o);
inline void from_json(const json& j, PaidMessagePriceChanged& o);
inline void to_json(json& j, const PaidMessagePriceChanged& o);
inline void from_json(const json& j, PassportData& o);
inline void to_json(json& j, const PassportData& o);
inline void from_json(const json& j, PassportElementError& o);
inline void to_json(json& j, const PassportElementError& o);
inline void from_json(const json& j, PassportElementErrorDataField& o);
inline void to_json(json& j, const PassportElementErrorDataField& o);
inline void from_json(const json& j, PassportElementErrorFile& o);
inline void to_json(json& j, const PassportElementErrorFile& o);
inline void from_json(const json& j, PassportElementErrorFiles& o);
inline void to_json(json& j, const PassportElementErrorFiles& o);
inline void from_json(const json& j, PassportElementErrorFrontSide& o);
inline void to_json(json& j, const PassportElementErrorFrontSide& o);
inline void from_json(const json& j, PassportElementErrorReverseSide& o);
inline void to_json(json& j, const PassportElementErrorReverseSide& o);
inline void from_json(const json& j, PassportElementErrorSelfie& o);
inline void to_json(json& j, const PassportElementErrorSelfie& o);
inline void from_json(const json& j, PassportElementErrorTranslationFile& o);
inline void to_json(json& j, const PassportElementErrorTranslationFile& o);
inline void from_json(const json& j, PassportElementErrorTranslationFiles& o);
inline void to_json(json& j, const PassportElementErrorTranslationFiles& o);
inline void from_json(const json& j, PassportElementErrorUnspecified& o);
inline void to_json(json& j, const PassportElementErrorUnspecified& o);
inline void from_json(const json& j, PassportFile& o);
inline void to_json(json& j, const PassportFile& o);
inline void from_json(const json& j, PhotoSize& o);
inline void to_json(json& j, const PhotoSize& o);
inline void from_json(const json& j, Poll& o);
inline void to_json(json& j, const Poll& o);
inline void from_json(const json& j, PollAnswer& o);
inline void to_json(json& j, const PollAnswer& o);
inline void from_json(const json& j, PollMedia& o);
inline void to_json(json& j, const PollMedia& o);
inline void from_json(const json& j, PollOption& o);
inline void to_json(json& j, const PollOption& o);
inline void from_json(const json& j, PollOptionAdded& o);
inline void to_json(json& j, const PollOptionAdded& o);
inline void from_json(const json& j, PollOptionDeleted& o);
inline void to_json(json& j, const PollOptionDeleted& o);
inline void from_json(const json& j, PreCheckoutQuery& o);
inline void to_json(json& j, const PreCheckoutQuery& o);
inline void from_json(const json& j, PreparedInlineMessage& o);
inline void to_json(json& j, const PreparedInlineMessage& o);
inline void from_json(const json& j, PreparedKeyboardButton& o);
inline void to_json(json& j, const PreparedKeyboardButton& o);
inline void from_json(const json& j, ProximityAlertTriggered& o);
inline void to_json(json& j, const ProximityAlertTriggered& o);
inline void from_json(const json& j, ReactionCount& o);
inline void to_json(json& j, const ReactionCount& o);
inline void from_json(const json& j, ReactionType& o);
inline void to_json(json& j, const ReactionType& o);
inline void from_json(const json& j, ReactionTypeCustomEmoji& o);
inline void to_json(json& j, const ReactionTypeCustomEmoji& o);
inline void from_json(const json& j, ReactionTypeEmoji& o);
inline void to_json(json& j, const ReactionTypeEmoji& o);
inline void from_json(const json& j, ReactionTypePaid& o);
inline void to_json(json& j, const ReactionTypePaid& o);
inline void from_json(const json& j, RefundedPayment& o);
inline void to_json(json& j, const RefundedPayment& o);
inline void from_json(const json& j, ReplyKeyboardMarkup& o);
inline void to_json(json& j, const ReplyKeyboardMarkup& o);
inline void from_json(const json& j, ReplyKeyboardRemove& o);
inline void to_json(json& j, const ReplyKeyboardRemove& o);
inline void from_json(const json& j, ReplyParameters& o);
inline void to_json(json& j, const ReplyParameters& o);
inline void from_json(const json& j, ResponseParameters& o);
inline void to_json(json& j, const ResponseParameters& o);
inline void from_json(const json& j, RevenueWithdrawalState& o);
inline void to_json(json& j, const RevenueWithdrawalState& o);
inline void from_json(const json& j, RevenueWithdrawalStateFailed& o);
inline void to_json(json& j, const RevenueWithdrawalStateFailed& o);
inline void from_json(const json& j, RevenueWithdrawalStatePending& o);
inline void to_json(json& j, const RevenueWithdrawalStatePending& o);
inline void from_json(const json& j, RevenueWithdrawalStateSucceeded& o);
inline void to_json(json& j, const RevenueWithdrawalStateSucceeded& o);
inline void from_json(const json& j, SentGuestMessage& o);
inline void to_json(json& j, const SentGuestMessage& o);
inline void from_json(const json& j, SentWebAppMessage& o);
inline void to_json(json& j, const SentWebAppMessage& o);
inline void from_json(const json& j, SharedUser& o);
inline void to_json(json& j, const SharedUser& o);
inline void from_json(const json& j, ShippingAddress& o);
inline void to_json(json& j, const ShippingAddress& o);
inline void from_json(const json& j, ShippingOption& o);
inline void to_json(json& j, const ShippingOption& o);
inline void from_json(const json& j, ShippingQuery& o);
inline void to_json(json& j, const ShippingQuery& o);
inline void from_json(const json& j, StarAmount& o);
inline void to_json(json& j, const StarAmount& o);
inline void from_json(const json& j, StarTransaction& o);
inline void to_json(json& j, const StarTransaction& o);
inline void from_json(const json& j, StarTransactions& o);
inline void to_json(json& j, const StarTransactions& o);
inline void from_json(const json& j, Sticker& o);
inline void to_json(json& j, const Sticker& o);
inline void from_json(const json& j, StickerSet& o);
inline void to_json(json& j, const StickerSet& o);
inline void from_json(const json& j, Story& o);
inline void to_json(json& j, const Story& o);
inline void from_json(const json& j, StoryArea& o);
inline void to_json(json& j, const StoryArea& o);
inline void from_json(const json& j, StoryAreaPosition& o);
inline void to_json(json& j, const StoryAreaPosition& o);
inline void from_json(const json& j, StoryAreaType& o);
inline void to_json(json& j, const StoryAreaType& o);
inline void from_json(const json& j, StoryAreaTypeLink& o);
inline void to_json(json& j, const StoryAreaTypeLink& o);
inline void from_json(const json& j, StoryAreaTypeLocation& o);
inline void to_json(json& j, const StoryAreaTypeLocation& o);
inline void from_json(const json& j, StoryAreaTypeSuggestedReaction& o);
inline void to_json(json& j, const StoryAreaTypeSuggestedReaction& o);
inline void from_json(const json& j, StoryAreaTypeUniqueGift& o);
inline void to_json(json& j, const StoryAreaTypeUniqueGift& o);
inline void from_json(const json& j, StoryAreaTypeWeather& o);
inline void to_json(json& j, const StoryAreaTypeWeather& o);
inline void from_json(const json& j, SuccessfulPayment& o);
inline void to_json(json& j, const SuccessfulPayment& o);
inline void from_json(const json& j, SuggestedPostApprovalFailed& o);
inline void to_json(json& j, const SuggestedPostApprovalFailed& o);
inline void from_json(const json& j, SuggestedPostApproved& o);
inline void to_json(json& j, const SuggestedPostApproved& o);
inline void from_json(const json& j, SuggestedPostDeclined& o);
inline void to_json(json& j, const SuggestedPostDeclined& o);
inline void from_json(const json& j, SuggestedPostInfo& o);
inline void to_json(json& j, const SuggestedPostInfo& o);
inline void from_json(const json& j, SuggestedPostPaid& o);
inline void to_json(json& j, const SuggestedPostPaid& o);
inline void from_json(const json& j, SuggestedPostParameters& o);
inline void to_json(json& j, const SuggestedPostParameters& o);
inline void from_json(const json& j, SuggestedPostPrice& o);
inline void to_json(json& j, const SuggestedPostPrice& o);
inline void from_json(const json& j, SuggestedPostRefunded& o);
inline void to_json(json& j, const SuggestedPostRefunded& o);
inline void from_json(const json& j, SwitchInlineQueryChosenChat& o);
inline void to_json(json& j, const SwitchInlineQueryChosenChat& o);
inline void from_json(const json& j, TextQuote& o);
inline void to_json(json& j, const TextQuote& o);
inline void from_json(const json& j, TransactionPartner& o);
inline void to_json(json& j, const TransactionPartner& o);
inline void from_json(const json& j, TransactionPartnerAffiliateProgram& o);
inline void to_json(json& j, const TransactionPartnerAffiliateProgram& o);
inline void from_json(const json& j, TransactionPartnerChat& o);
inline void to_json(json& j, const TransactionPartnerChat& o);
inline void from_json(const json& j, TransactionPartnerFragment& o);
inline void to_json(json& j, const TransactionPartnerFragment& o);
inline void from_json(const json& j, TransactionPartnerOther& o);
inline void to_json(json& j, const TransactionPartnerOther& o);
inline void from_json(const json& j, TransactionPartnerTelegramAds& o);
inline void to_json(json& j, const TransactionPartnerTelegramAds& o);
inline void from_json(const json& j, TransactionPartnerTelegramApi& o);
inline void to_json(json& j, const TransactionPartnerTelegramApi& o);
inline void from_json(const json& j, TransactionPartnerUser& o);
inline void to_json(json& j, const TransactionPartnerUser& o);
inline void from_json(const json& j, UniqueGift& o);
inline void to_json(json& j, const UniqueGift& o);
inline void from_json(const json& j, UniqueGiftBackdrop& o);
inline void to_json(json& j, const UniqueGiftBackdrop& o);
inline void from_json(const json& j, UniqueGiftBackdropColors& o);
inline void to_json(json& j, const UniqueGiftBackdropColors& o);
inline void from_json(const json& j, UniqueGiftColors& o);
inline void to_json(json& j, const UniqueGiftColors& o);
inline void from_json(const json& j, UniqueGiftInfo& o);
inline void to_json(json& j, const UniqueGiftInfo& o);
inline void from_json(const json& j, UniqueGiftModel& o);
inline void to_json(json& j, const UniqueGiftModel& o);
inline void from_json(const json& j, UniqueGiftSymbol& o);
inline void to_json(json& j, const UniqueGiftSymbol& o);
inline void from_json(const json& j, Update& o);
inline void to_json(json& j, const Update& o);
inline void from_json(const json& j, User& o);
inline void to_json(json& j, const User& o);
inline void from_json(const json& j, UserChatBoosts& o);
inline void to_json(json& j, const UserChatBoosts& o);
inline void from_json(const json& j, UserProfileAudios& o);
inline void to_json(json& j, const UserProfileAudios& o);
inline void from_json(const json& j, UserProfilePhotos& o);
inline void to_json(json& j, const UserProfilePhotos& o);
inline void from_json(const json& j, UserRating& o);
inline void to_json(json& j, const UserRating& o);
inline void from_json(const json& j, UsersShared& o);
inline void to_json(json& j, const UsersShared& o);
inline void from_json(const json& j, Venue& o);
inline void to_json(json& j, const Venue& o);
inline void from_json(const json& j, Video& o);
inline void to_json(json& j, const Video& o);
inline void from_json(const json& j, VideoChatEnded& o);
inline void to_json(json& j, const VideoChatEnded& o);
inline void from_json(const json& j, VideoChatParticipantsInvited& o);
inline void to_json(json& j, const VideoChatParticipantsInvited& o);
inline void from_json(const json& j, VideoChatScheduled& o);
inline void to_json(json& j, const VideoChatScheduled& o);
inline void from_json(const json& j, VideoChatStarted& o);
inline void to_json(json& j, const VideoChatStarted& o);
inline void from_json(const json& j, VideoNote& o);
inline void to_json(json& j, const VideoNote& o);
inline void from_json(const json& j, VideoQuality& o);
inline void to_json(json& j, const VideoQuality& o);
inline void from_json(const json& j, Voice& o);
inline void to_json(json& j, const Voice& o);
inline void from_json(const json& j, WebAppData& o);
inline void to_json(json& j, const WebAppData& o);
inline void from_json(const json& j, WebAppInfo& o);
inline void to_json(json& j, const WebAppInfo& o);
inline void from_json(const json& j, WebhookInfo& o);
inline void to_json(json& j, const WebhookInfo& o);
inline void from_json(const json& j, WriteAccessAllowed& o);
inline void to_json(json& j, const WriteAccessAllowed& o);

// ── JSON serialisation — implementations ─────────────────────

inline void from_json(const json& j, Update& o) {
    o.update_id = j.contains("update_id") && !j.at("update_id").is_null()
        ? j.at("update_id").get<int64_t>() : 0;
    if (j.contains("message") && !j.at("message").is_null()) {
        o.message = std::make_shared<Message>();
        from_json(j.at("message"), *o.message);
    }
    if (j.contains("edited_message") && !j.at("edited_message").is_null()) {
        o.edited_message = std::make_shared<Message>();
        from_json(j.at("edited_message"), *o.edited_message);
    }
    if (j.contains("channel_post") && !j.at("channel_post").is_null()) {
        o.channel_post = std::make_shared<Message>();
        from_json(j.at("channel_post"), *o.channel_post);
    }
    if (j.contains("edited_channel_post") && !j.at("edited_channel_post").is_null()) {
        o.edited_channel_post = std::make_shared<Message>();
        from_json(j.at("edited_channel_post"), *o.edited_channel_post);
    }
    if (j.contains("business_connection") && !j.at("business_connection").is_null()) {
        o.business_connection = std::make_shared<BusinessConnection>();
        from_json(j.at("business_connection"), *o.business_connection);
    }
    if (j.contains("business_message") && !j.at("business_message").is_null()) {
        o.business_message = std::make_shared<Message>();
        from_json(j.at("business_message"), *o.business_message);
    }
    if (j.contains("edited_business_message") && !j.at("edited_business_message").is_null()) {
        o.edited_business_message = std::make_shared<Message>();
        from_json(j.at("edited_business_message"), *o.edited_business_message);
    }
    if (j.contains("deleted_business_messages") && !j.at("deleted_business_messages").is_null()) {
        o.deleted_business_messages = std::make_shared<BusinessMessagesDeleted>();
        from_json(j.at("deleted_business_messages"), *o.deleted_business_messages);
    }
    if (j.contains("guest_message") && !j.at("guest_message").is_null()) {
        o.guest_message = std::make_shared<Message>();
        from_json(j.at("guest_message"), *o.guest_message);
    }
    if (j.contains("message_reaction") && !j.at("message_reaction").is_null()) {
        o.message_reaction = std::make_shared<MessageReactionUpdated>();
        from_json(j.at("message_reaction"), *o.message_reaction);
    }
    if (j.contains("message_reaction_count") && !j.at("message_reaction_count").is_null()) {
        o.message_reaction_count = std::make_shared<MessageReactionCountUpdated>();
        from_json(j.at("message_reaction_count"), *o.message_reaction_count);
    }
    if (j.contains("inline_query") && !j.at("inline_query").is_null()) {
        o.inline_query = std::make_shared<InlineQuery>();
        from_json(j.at("inline_query"), *o.inline_query);
    }
    if (j.contains("chosen_inline_result") && !j.at("chosen_inline_result").is_null()) {
        o.chosen_inline_result = std::make_shared<ChosenInlineResult>();
        from_json(j.at("chosen_inline_result"), *o.chosen_inline_result);
    }
    if (j.contains("callback_query") && !j.at("callback_query").is_null()) {
        o.callback_query = std::make_shared<CallbackQuery>();
        from_json(j.at("callback_query"), *o.callback_query);
    }
    if (j.contains("shipping_query") && !j.at("shipping_query").is_null()) {
        o.shipping_query = std::make_shared<ShippingQuery>();
        from_json(j.at("shipping_query"), *o.shipping_query);
    }
    if (j.contains("pre_checkout_query") && !j.at("pre_checkout_query").is_null()) {
        o.pre_checkout_query = std::make_shared<PreCheckoutQuery>();
        from_json(j.at("pre_checkout_query"), *o.pre_checkout_query);
    }
    if (j.contains("purchased_paid_media") && !j.at("purchased_paid_media").is_null()) {
        o.purchased_paid_media = std::make_shared<PaidMediaPurchased>();
        from_json(j.at("purchased_paid_media"), *o.purchased_paid_media);
    }
    if (j.contains("poll") && !j.at("poll").is_null()) {
        o.poll = std::make_shared<Poll>();
        from_json(j.at("poll"), *o.poll);
    }
    if (j.contains("poll_answer") && !j.at("poll_answer").is_null()) {
        o.poll_answer = std::make_shared<PollAnswer>();
        from_json(j.at("poll_answer"), *o.poll_answer);
    }
    if (j.contains("my_chat_member") && !j.at("my_chat_member").is_null()) {
        o.my_chat_member = std::make_shared<ChatMemberUpdated>();
        from_json(j.at("my_chat_member"), *o.my_chat_member);
    }
    if (j.contains("chat_member") && !j.at("chat_member").is_null()) {
        o.chat_member = std::make_shared<ChatMemberUpdated>();
        from_json(j.at("chat_member"), *o.chat_member);
    }
    if (j.contains("chat_join_request") && !j.at("chat_join_request").is_null()) {
        o.chat_join_request = std::make_shared<ChatJoinRequest>();
        from_json(j.at("chat_join_request"), *o.chat_join_request);
    }
    if (j.contains("chat_boost") && !j.at("chat_boost").is_null()) {
        o.chat_boost = std::make_shared<ChatBoostUpdated>();
        from_json(j.at("chat_boost"), *o.chat_boost);
    }
    if (j.contains("removed_chat_boost") && !j.at("removed_chat_boost").is_null()) {
        o.removed_chat_boost = std::make_shared<ChatBoostRemoved>();
        from_json(j.at("removed_chat_boost"), *o.removed_chat_boost);
    }
    if (j.contains("managed_bot") && !j.at("managed_bot").is_null()) {
        o.managed_bot = std::make_shared<ManagedBotUpdated>();
        from_json(j.at("managed_bot"), *o.managed_bot);
    }
}

inline void to_json(json& j, const Update& o) {
    j = json::object();
    j["update_id"] = o.update_id;
    if (o.message) {
        json _sub; to_json(_sub, *o.message); j["message"] = std::move(_sub);
    }
    if (o.edited_message) {
        json _sub; to_json(_sub, *o.edited_message); j["edited_message"] = std::move(_sub);
    }
    if (o.channel_post) {
        json _sub; to_json(_sub, *o.channel_post); j["channel_post"] = std::move(_sub);
    }
    if (o.edited_channel_post) {
        json _sub; to_json(_sub, *o.edited_channel_post); j["edited_channel_post"] = std::move(_sub);
    }
    if (o.business_connection) {
        json _sub; to_json(_sub, *o.business_connection); j["business_connection"] = std::move(_sub);
    }
    if (o.business_message) {
        json _sub; to_json(_sub, *o.business_message); j["business_message"] = std::move(_sub);
    }
    if (o.edited_business_message) {
        json _sub; to_json(_sub, *o.edited_business_message); j["edited_business_message"] = std::move(_sub);
    }
    if (o.deleted_business_messages) {
        json _sub; to_json(_sub, *o.deleted_business_messages); j["deleted_business_messages"] = std::move(_sub);
    }
    if (o.guest_message) {
        json _sub; to_json(_sub, *o.guest_message); j["guest_message"] = std::move(_sub);
    }
    if (o.message_reaction) {
        json _sub; to_json(_sub, *o.message_reaction); j["message_reaction"] = std::move(_sub);
    }
    if (o.message_reaction_count) {
        json _sub; to_json(_sub, *o.message_reaction_count); j["message_reaction_count"] = std::move(_sub);
    }
    if (o.inline_query) {
        json _sub; to_json(_sub, *o.inline_query); j["inline_query"] = std::move(_sub);
    }
    if (o.chosen_inline_result) {
        json _sub; to_json(_sub, *o.chosen_inline_result); j["chosen_inline_result"] = std::move(_sub);
    }
    if (o.callback_query) {
        json _sub; to_json(_sub, *o.callback_query); j["callback_query"] = std::move(_sub);
    }
    if (o.shipping_query) {
        json _sub; to_json(_sub, *o.shipping_query); j["shipping_query"] = std::move(_sub);
    }
    if (o.pre_checkout_query) {
        json _sub; to_json(_sub, *o.pre_checkout_query); j["pre_checkout_query"] = std::move(_sub);
    }
    if (o.purchased_paid_media) {
        json _sub; to_json(_sub, *o.purchased_paid_media); j["purchased_paid_media"] = std::move(_sub);
    }
    if (o.poll) {
        json _sub; to_json(_sub, *o.poll); j["poll"] = std::move(_sub);
    }
    if (o.poll_answer) {
        json _sub; to_json(_sub, *o.poll_answer); j["poll_answer"] = std::move(_sub);
    }
    if (o.my_chat_member) {
        json _sub; to_json(_sub, *o.my_chat_member); j["my_chat_member"] = std::move(_sub);
    }
    if (o.chat_member) {
        json _sub; to_json(_sub, *o.chat_member); j["chat_member"] = std::move(_sub);
    }
    if (o.chat_join_request) {
        json _sub; to_json(_sub, *o.chat_join_request); j["chat_join_request"] = std::move(_sub);
    }
    if (o.chat_boost) {
        json _sub; to_json(_sub, *o.chat_boost); j["chat_boost"] = std::move(_sub);
    }
    if (o.removed_chat_boost) {
        json _sub; to_json(_sub, *o.removed_chat_boost); j["removed_chat_boost"] = std::move(_sub);
    }
    if (o.managed_bot) {
        json _sub; to_json(_sub, *o.managed_bot); j["managed_bot"] = std::move(_sub);
    }
}

inline void from_json(const json& j, WebhookInfo& o) {
    o.url = j.contains("url") && !j.at("url").is_null()
        ? j.at("url").get<std::string>() : "";
    o.has_custom_certificate = j.contains("has_custom_certificate") && !j.at("has_custom_certificate").is_null()
        ? j.at("has_custom_certificate").get<bool>() : false;
    o.pending_update_count = j.contains("pending_update_count") && !j.at("pending_update_count").is_null()
        ? j.at("pending_update_count").get<int64_t>() : 0;
    if (j.contains("ip_address") && !j.at("ip_address").is_null())
        o.ip_address = j.at("ip_address").get<std::string>();
    if (j.contains("last_error_date") && !j.at("last_error_date").is_null())
        o.last_error_date = j.at("last_error_date").get<int64_t>();
    if (j.contains("last_error_message") && !j.at("last_error_message").is_null())
        o.last_error_message = j.at("last_error_message").get<std::string>();
    if (j.contains("last_synchronization_error_date") && !j.at("last_synchronization_error_date").is_null())
        o.last_synchronization_error_date = j.at("last_synchronization_error_date").get<int64_t>();
    if (j.contains("max_connections") && !j.at("max_connections").is_null())
        o.max_connections = j.at("max_connections").get<int64_t>();
    if (j.contains("allowed_updates") && j.at("allowed_updates").is_array()) {
        for (const auto& _item : j.at("allowed_updates")) {
            o.allowed_updates.push_back(_item.get<std::string>());
        }
    }
}

inline void to_json(json& j, const WebhookInfo& o) {
    j = json::object();
    j["url"] = o.url;
    j["has_custom_certificate"] = o.has_custom_certificate;
    j["pending_update_count"] = o.pending_update_count;
    if (o.ip_address.has_value())
        j["ip_address"] = o.ip_address.value();
    if (o.last_error_date.has_value())
        j["last_error_date"] = o.last_error_date.value();
    if (o.last_error_message.has_value())
        j["last_error_message"] = o.last_error_message.value();
    if (o.last_synchronization_error_date.has_value())
        j["last_synchronization_error_date"] = o.last_synchronization_error_date.value();
    if (o.max_connections.has_value())
        j["max_connections"] = o.max_connections.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.allowed_updates) {
            _arr.push_back(_item);
        }
        j["allowed_updates"] = std::move(_arr);
    }
}

inline void from_json(const json& j, User& o) {
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<int64_t>() : 0;
    o.is_bot = j.contains("is_bot") && !j.at("is_bot").is_null()
        ? j.at("is_bot").get<bool>() : false;
    o.first_name = j.contains("first_name") && !j.at("first_name").is_null()
        ? j.at("first_name").get<std::string>() : "";
    if (j.contains("last_name") && !j.at("last_name").is_null())
        o.last_name = j.at("last_name").get<std::string>();
    if (j.contains("username") && !j.at("username").is_null())
        o.username = j.at("username").get<std::string>();
    if (j.contains("language_code") && !j.at("language_code").is_null())
        o.language_code = j.at("language_code").get<std::string>();
    if (j.contains("is_premium") && !j.at("is_premium").is_null())
        o.is_premium = j.at("is_premium").get<bool>();
    if (j.contains("added_to_attachment_menu") && !j.at("added_to_attachment_menu").is_null())
        o.added_to_attachment_menu = j.at("added_to_attachment_menu").get<bool>();
    if (j.contains("can_join_groups") && !j.at("can_join_groups").is_null())
        o.can_join_groups = j.at("can_join_groups").get<bool>();
    if (j.contains("can_read_all_group_messages") && !j.at("can_read_all_group_messages").is_null())
        o.can_read_all_group_messages = j.at("can_read_all_group_messages").get<bool>();
    if (j.contains("supports_guest_queries") && !j.at("supports_guest_queries").is_null())
        o.supports_guest_queries = j.at("supports_guest_queries").get<bool>();
    if (j.contains("supports_inline_queries") && !j.at("supports_inline_queries").is_null())
        o.supports_inline_queries = j.at("supports_inline_queries").get<bool>();
    if (j.contains("can_connect_to_business") && !j.at("can_connect_to_business").is_null())
        o.can_connect_to_business = j.at("can_connect_to_business").get<bool>();
    if (j.contains("has_main_web_app") && !j.at("has_main_web_app").is_null())
        o.has_main_web_app = j.at("has_main_web_app").get<bool>();
    if (j.contains("has_topics_enabled") && !j.at("has_topics_enabled").is_null())
        o.has_topics_enabled = j.at("has_topics_enabled").get<bool>();
    if (j.contains("allows_users_to_create_topics") && !j.at("allows_users_to_create_topics").is_null())
        o.allows_users_to_create_topics = j.at("allows_users_to_create_topics").get<bool>();
    if (j.contains("can_manage_bots") && !j.at("can_manage_bots").is_null())
        o.can_manage_bots = j.at("can_manage_bots").get<bool>();
}

inline void to_json(json& j, const User& o) {
    j = json::object();
    j["id"] = o.id;
    j["is_bot"] = o.is_bot;
    j["first_name"] = o.first_name;
    if (o.last_name.has_value())
        j["last_name"] = o.last_name.value();
    if (o.username.has_value())
        j["username"] = o.username.value();
    if (o.language_code.has_value())
        j["language_code"] = o.language_code.value();
    if (o.is_premium.has_value())
        j["is_premium"] = o.is_premium.value();
    if (o.added_to_attachment_menu.has_value())
        j["added_to_attachment_menu"] = o.added_to_attachment_menu.value();
    if (o.can_join_groups.has_value())
        j["can_join_groups"] = o.can_join_groups.value();
    if (o.can_read_all_group_messages.has_value())
        j["can_read_all_group_messages"] = o.can_read_all_group_messages.value();
    if (o.supports_guest_queries.has_value())
        j["supports_guest_queries"] = o.supports_guest_queries.value();
    if (o.supports_inline_queries.has_value())
        j["supports_inline_queries"] = o.supports_inline_queries.value();
    if (o.can_connect_to_business.has_value())
        j["can_connect_to_business"] = o.can_connect_to_business.value();
    if (o.has_main_web_app.has_value())
        j["has_main_web_app"] = o.has_main_web_app.value();
    if (o.has_topics_enabled.has_value())
        j["has_topics_enabled"] = o.has_topics_enabled.value();
    if (o.allows_users_to_create_topics.has_value())
        j["allows_users_to_create_topics"] = o.allows_users_to_create_topics.value();
    if (o.can_manage_bots.has_value())
        j["can_manage_bots"] = o.can_manage_bots.value();
}

inline void from_json(const json& j, Chat& o) {
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<int64_t>() : 0;
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("title") && !j.at("title").is_null())
        o.title = j.at("title").get<std::string>();
    if (j.contains("username") && !j.at("username").is_null())
        o.username = j.at("username").get<std::string>();
    if (j.contains("first_name") && !j.at("first_name").is_null())
        o.first_name = j.at("first_name").get<std::string>();
    if (j.contains("last_name") && !j.at("last_name").is_null())
        o.last_name = j.at("last_name").get<std::string>();
    if (j.contains("is_forum") && !j.at("is_forum").is_null())
        o.is_forum = j.at("is_forum").get<bool>();
    if (j.contains("is_direct_messages") && !j.at("is_direct_messages").is_null())
        o.is_direct_messages = j.at("is_direct_messages").get<bool>();
}

inline void to_json(json& j, const Chat& o) {
    j = json::object();
    j["id"] = o.id;
    j["type"] = o.type;
    if (o.title.has_value())
        j["title"] = o.title.value();
    if (o.username.has_value())
        j["username"] = o.username.value();
    if (o.first_name.has_value())
        j["first_name"] = o.first_name.value();
    if (o.last_name.has_value())
        j["last_name"] = o.last_name.value();
    if (o.is_forum.has_value())
        j["is_forum"] = o.is_forum.value();
    if (o.is_direct_messages.has_value())
        j["is_direct_messages"] = o.is_direct_messages.value();
}

inline void from_json(const json& j, ChatFullInfo& o) {
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<int64_t>() : 0;
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("title") && !j.at("title").is_null())
        o.title = j.at("title").get<std::string>();
    if (j.contains("username") && !j.at("username").is_null())
        o.username = j.at("username").get<std::string>();
    if (j.contains("first_name") && !j.at("first_name").is_null())
        o.first_name = j.at("first_name").get<std::string>();
    if (j.contains("last_name") && !j.at("last_name").is_null())
        o.last_name = j.at("last_name").get<std::string>();
    if (j.contains("is_forum") && !j.at("is_forum").is_null())
        o.is_forum = j.at("is_forum").get<bool>();
    if (j.contains("is_direct_messages") && !j.at("is_direct_messages").is_null())
        o.is_direct_messages = j.at("is_direct_messages").get<bool>();
    o.accent_color_id = j.contains("accent_color_id") && !j.at("accent_color_id").is_null()
        ? j.at("accent_color_id").get<int64_t>() : 0;
    o.max_reaction_count = j.contains("max_reaction_count") && !j.at("max_reaction_count").is_null()
        ? j.at("max_reaction_count").get<int64_t>() : 0;
    if (j.contains("photo") && !j.at("photo").is_null()) {
        o.photo = std::make_shared<ChatPhoto>();
        from_json(j.at("photo"), *o.photo);
    }
    if (j.contains("active_usernames") && j.at("active_usernames").is_array()) {
        for (const auto& _item : j.at("active_usernames")) {
            o.active_usernames.push_back(_item.get<std::string>());
        }
    }
    if (j.contains("birthdate") && !j.at("birthdate").is_null()) {
        o.birthdate = std::make_shared<Birthdate>();
        from_json(j.at("birthdate"), *o.birthdate);
    }
    if (j.contains("business_intro") && !j.at("business_intro").is_null()) {
        o.business_intro = std::make_shared<BusinessIntro>();
        from_json(j.at("business_intro"), *o.business_intro);
    }
    if (j.contains("business_location") && !j.at("business_location").is_null()) {
        o.business_location = std::make_shared<BusinessLocation>();
        from_json(j.at("business_location"), *o.business_location);
    }
    if (j.contains("business_opening_hours") && !j.at("business_opening_hours").is_null()) {
        o.business_opening_hours = std::make_shared<BusinessOpeningHours>();
        from_json(j.at("business_opening_hours"), *o.business_opening_hours);
    }
    if (j.contains("personal_chat") && !j.at("personal_chat").is_null()) {
        o.personal_chat = std::make_shared<Chat>();
        from_json(j.at("personal_chat"), *o.personal_chat);
    }
    if (j.contains("parent_chat") && !j.at("parent_chat").is_null()) {
        o.parent_chat = std::make_shared<Chat>();
        from_json(j.at("parent_chat"), *o.parent_chat);
    }
    if (j.contains("available_reactions") && j.at("available_reactions").is_array()) {
        for (const auto& _item : j.at("available_reactions")) {
            {
                ReactionType _elem{};
                from_json(_item, _elem);
                o.available_reactions.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("background_custom_emoji_id") && !j.at("background_custom_emoji_id").is_null())
        o.background_custom_emoji_id = j.at("background_custom_emoji_id").get<std::string>();
    if (j.contains("profile_accent_color_id") && !j.at("profile_accent_color_id").is_null())
        o.profile_accent_color_id = j.at("profile_accent_color_id").get<int64_t>();
    if (j.contains("profile_background_custom_emoji_id") && !j.at("profile_background_custom_emoji_id").is_null())
        o.profile_background_custom_emoji_id = j.at("profile_background_custom_emoji_id").get<std::string>();
    if (j.contains("emoji_status_custom_emoji_id") && !j.at("emoji_status_custom_emoji_id").is_null())
        o.emoji_status_custom_emoji_id = j.at("emoji_status_custom_emoji_id").get<std::string>();
    if (j.contains("emoji_status_expiration_date") && !j.at("emoji_status_expiration_date").is_null())
        o.emoji_status_expiration_date = j.at("emoji_status_expiration_date").get<int64_t>();
    if (j.contains("bio") && !j.at("bio").is_null())
        o.bio = j.at("bio").get<std::string>();
    if (j.contains("has_private_forwards") && !j.at("has_private_forwards").is_null())
        o.has_private_forwards = j.at("has_private_forwards").get<bool>();
    if (j.contains("has_restricted_voice_and_video_messages") && !j.at("has_restricted_voice_and_video_messages").is_null())
        o.has_restricted_voice_and_video_messages = j.at("has_restricted_voice_and_video_messages").get<bool>();
    if (j.contains("join_to_send_messages") && !j.at("join_to_send_messages").is_null())
        o.join_to_send_messages = j.at("join_to_send_messages").get<bool>();
    if (j.contains("join_by_request") && !j.at("join_by_request").is_null())
        o.join_by_request = j.at("join_by_request").get<bool>();
    if (j.contains("description") && !j.at("description").is_null())
        o.description = j.at("description").get<std::string>();
    if (j.contains("invite_link") && !j.at("invite_link").is_null())
        o.invite_link = j.at("invite_link").get<std::string>();
    if (j.contains("pinned_message") && !j.at("pinned_message").is_null()) {
        o.pinned_message = std::make_shared<Message>();
        from_json(j.at("pinned_message"), *o.pinned_message);
    }
    if (j.contains("permissions") && !j.at("permissions").is_null()) {
        o.permissions = std::make_shared<ChatPermissions>();
        from_json(j.at("permissions"), *o.permissions);
    }
    if (j.contains("accepted_gift_types") && !j.at("accepted_gift_types").is_null()) {
        o.accepted_gift_types = std::make_shared<AcceptedGiftTypes>();
        from_json(j.at("accepted_gift_types"), *o.accepted_gift_types);
    }
    if (j.contains("can_send_paid_media") && !j.at("can_send_paid_media").is_null())
        o.can_send_paid_media = j.at("can_send_paid_media").get<bool>();
    if (j.contains("slow_mode_delay") && !j.at("slow_mode_delay").is_null())
        o.slow_mode_delay = j.at("slow_mode_delay").get<int64_t>();
    if (j.contains("unrestrict_boost_count") && !j.at("unrestrict_boost_count").is_null())
        o.unrestrict_boost_count = j.at("unrestrict_boost_count").get<int64_t>();
    if (j.contains("message_auto_delete_time") && !j.at("message_auto_delete_time").is_null())
        o.message_auto_delete_time = j.at("message_auto_delete_time").get<int64_t>();
    if (j.contains("has_aggressive_anti_spam_enabled") && !j.at("has_aggressive_anti_spam_enabled").is_null())
        o.has_aggressive_anti_spam_enabled = j.at("has_aggressive_anti_spam_enabled").get<bool>();
    if (j.contains("has_hidden_members") && !j.at("has_hidden_members").is_null())
        o.has_hidden_members = j.at("has_hidden_members").get<bool>();
    if (j.contains("has_protected_content") && !j.at("has_protected_content").is_null())
        o.has_protected_content = j.at("has_protected_content").get<bool>();
    if (j.contains("has_visible_history") && !j.at("has_visible_history").is_null())
        o.has_visible_history = j.at("has_visible_history").get<bool>();
    if (j.contains("sticker_set_name") && !j.at("sticker_set_name").is_null())
        o.sticker_set_name = j.at("sticker_set_name").get<std::string>();
    if (j.contains("can_set_sticker_set") && !j.at("can_set_sticker_set").is_null())
        o.can_set_sticker_set = j.at("can_set_sticker_set").get<bool>();
    if (j.contains("custom_emoji_sticker_set_name") && !j.at("custom_emoji_sticker_set_name").is_null())
        o.custom_emoji_sticker_set_name = j.at("custom_emoji_sticker_set_name").get<std::string>();
    if (j.contains("linked_chat_id") && !j.at("linked_chat_id").is_null())
        o.linked_chat_id = j.at("linked_chat_id").get<int64_t>();
    if (j.contains("location") && !j.at("location").is_null()) {
        o.location = std::make_shared<ChatLocation>();
        from_json(j.at("location"), *o.location);
    }
    if (j.contains("rating") && !j.at("rating").is_null()) {
        o.rating = std::make_shared<UserRating>();
        from_json(j.at("rating"), *o.rating);
    }
    if (j.contains("first_profile_audio") && !j.at("first_profile_audio").is_null()) {
        o.first_profile_audio = std::make_shared<Audio>();
        from_json(j.at("first_profile_audio"), *o.first_profile_audio);
    }
    if (j.contains("unique_gift_colors") && !j.at("unique_gift_colors").is_null()) {
        o.unique_gift_colors = std::make_shared<UniqueGiftColors>();
        from_json(j.at("unique_gift_colors"), *o.unique_gift_colors);
    }
    if (j.contains("paid_message_star_count") && !j.at("paid_message_star_count").is_null())
        o.paid_message_star_count = j.at("paid_message_star_count").get<int64_t>();
}

inline void to_json(json& j, const ChatFullInfo& o) {
    j = json::object();
    j["id"] = o.id;
    j["type"] = o.type;
    if (o.title.has_value())
        j["title"] = o.title.value();
    if (o.username.has_value())
        j["username"] = o.username.value();
    if (o.first_name.has_value())
        j["first_name"] = o.first_name.value();
    if (o.last_name.has_value())
        j["last_name"] = o.last_name.value();
    if (o.is_forum.has_value())
        j["is_forum"] = o.is_forum.value();
    if (o.is_direct_messages.has_value())
        j["is_direct_messages"] = o.is_direct_messages.value();
    j["accent_color_id"] = o.accent_color_id;
    j["max_reaction_count"] = o.max_reaction_count;
    if (o.photo) {
        json _sub; to_json(_sub, *o.photo); j["photo"] = std::move(_sub);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.active_usernames) {
            _arr.push_back(_item);
        }
        j["active_usernames"] = std::move(_arr);
    }
    if (o.birthdate) {
        json _sub; to_json(_sub, *o.birthdate); j["birthdate"] = std::move(_sub);
    }
    if (o.business_intro) {
        json _sub; to_json(_sub, *o.business_intro); j["business_intro"] = std::move(_sub);
    }
    if (o.business_location) {
        json _sub; to_json(_sub, *o.business_location); j["business_location"] = std::move(_sub);
    }
    if (o.business_opening_hours) {
        json _sub; to_json(_sub, *o.business_opening_hours); j["business_opening_hours"] = std::move(_sub);
    }
    if (o.personal_chat) {
        json _sub; to_json(_sub, *o.personal_chat); j["personal_chat"] = std::move(_sub);
    }
    if (o.parent_chat) {
        json _sub; to_json(_sub, *o.parent_chat); j["parent_chat"] = std::move(_sub);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.available_reactions) {
            {
                json _e; to_json(_e, _item); _arr.push_back(std::move(_e));
            }
        }
        j["available_reactions"] = std::move(_arr);
    }
    if (o.background_custom_emoji_id.has_value())
        j["background_custom_emoji_id"] = o.background_custom_emoji_id.value();
    if (o.profile_accent_color_id.has_value())
        j["profile_accent_color_id"] = o.profile_accent_color_id.value();
    if (o.profile_background_custom_emoji_id.has_value())
        j["profile_background_custom_emoji_id"] = o.profile_background_custom_emoji_id.value();
    if (o.emoji_status_custom_emoji_id.has_value())
        j["emoji_status_custom_emoji_id"] = o.emoji_status_custom_emoji_id.value();
    if (o.emoji_status_expiration_date.has_value())
        j["emoji_status_expiration_date"] = o.emoji_status_expiration_date.value();
    if (o.bio.has_value())
        j["bio"] = o.bio.value();
    if (o.has_private_forwards.has_value())
        j["has_private_forwards"] = o.has_private_forwards.value();
    if (o.has_restricted_voice_and_video_messages.has_value())
        j["has_restricted_voice_and_video_messages"] = o.has_restricted_voice_and_video_messages.value();
    if (o.join_to_send_messages.has_value())
        j["join_to_send_messages"] = o.join_to_send_messages.value();
    if (o.join_by_request.has_value())
        j["join_by_request"] = o.join_by_request.value();
    if (o.description.has_value())
        j["description"] = o.description.value();
    if (o.invite_link.has_value())
        j["invite_link"] = o.invite_link.value();
    if (o.pinned_message) {
        json _sub; to_json(_sub, *o.pinned_message); j["pinned_message"] = std::move(_sub);
    }
    if (o.permissions) {
        json _sub; to_json(_sub, *o.permissions); j["permissions"] = std::move(_sub);
    }
    {
        json _sub; to_json(_sub, *o.accepted_gift_types); j["accepted_gift_types"] = std::move(_sub);
    }
    if (o.can_send_paid_media.has_value())
        j["can_send_paid_media"] = o.can_send_paid_media.value();
    if (o.slow_mode_delay.has_value())
        j["slow_mode_delay"] = o.slow_mode_delay.value();
    if (o.unrestrict_boost_count.has_value())
        j["unrestrict_boost_count"] = o.unrestrict_boost_count.value();
    if (o.message_auto_delete_time.has_value())
        j["message_auto_delete_time"] = o.message_auto_delete_time.value();
    if (o.has_aggressive_anti_spam_enabled.has_value())
        j["has_aggressive_anti_spam_enabled"] = o.has_aggressive_anti_spam_enabled.value();
    if (o.has_hidden_members.has_value())
        j["has_hidden_members"] = o.has_hidden_members.value();
    if (o.has_protected_content.has_value())
        j["has_protected_content"] = o.has_protected_content.value();
    if (o.has_visible_history.has_value())
        j["has_visible_history"] = o.has_visible_history.value();
    if (o.sticker_set_name.has_value())
        j["sticker_set_name"] = o.sticker_set_name.value();
    if (o.can_set_sticker_set.has_value())
        j["can_set_sticker_set"] = o.can_set_sticker_set.value();
    if (o.custom_emoji_sticker_set_name.has_value())
        j["custom_emoji_sticker_set_name"] = o.custom_emoji_sticker_set_name.value();
    if (o.linked_chat_id.has_value())
        j["linked_chat_id"] = o.linked_chat_id.value();
    if (o.location) {
        json _sub; to_json(_sub, *o.location); j["location"] = std::move(_sub);
    }
    if (o.rating) {
        json _sub; to_json(_sub, *o.rating); j["rating"] = std::move(_sub);
    }
    if (o.first_profile_audio) {
        json _sub; to_json(_sub, *o.first_profile_audio); j["first_profile_audio"] = std::move(_sub);
    }
    if (o.unique_gift_colors) {
        json _sub; to_json(_sub, *o.unique_gift_colors); j["unique_gift_colors"] = std::move(_sub);
    }
    if (o.paid_message_star_count.has_value())
        j["paid_message_star_count"] = o.paid_message_star_count.value();
}

inline void from_json(const json& j, Message& o) {
    o.message_id = j.contains("message_id") && !j.at("message_id").is_null()
        ? j.at("message_id").get<int64_t>() : 0;
    if (j.contains("message_thread_id") && !j.at("message_thread_id").is_null())
        o.message_thread_id = j.at("message_thread_id").get<int64_t>();
    if (j.contains("direct_messages_topic") && !j.at("direct_messages_topic").is_null()) {
        o.direct_messages_topic = std::make_shared<DirectMessagesTopic>();
        from_json(j.at("direct_messages_topic"), *o.direct_messages_topic);
    }
    if (j.contains("from") && !j.at("from").is_null()) {
        o.from = std::make_shared<User>();
        from_json(j.at("from"), *o.from);
    }
    if (j.contains("sender_chat") && !j.at("sender_chat").is_null()) {
        o.sender_chat = std::make_shared<Chat>();
        from_json(j.at("sender_chat"), *o.sender_chat);
    }
    if (j.contains("sender_boost_count") && !j.at("sender_boost_count").is_null())
        o.sender_boost_count = j.at("sender_boost_count").get<int64_t>();
    if (j.contains("sender_business_bot") && !j.at("sender_business_bot").is_null()) {
        o.sender_business_bot = std::make_shared<User>();
        from_json(j.at("sender_business_bot"), *o.sender_business_bot);
    }
    if (j.contains("sender_tag") && !j.at("sender_tag").is_null())
        o.sender_tag = j.at("sender_tag").get<std::string>();
    o.date = j.contains("date") && !j.at("date").is_null()
        ? j.at("date").get<int64_t>() : 0;
    if (j.contains("guest_query_id") && !j.at("guest_query_id").is_null())
        o.guest_query_id = j.at("guest_query_id").get<std::string>();
    if (j.contains("business_connection_id") && !j.at("business_connection_id").is_null())
        o.business_connection_id = j.at("business_connection_id").get<std::string>();
    if (j.contains("chat") && !j.at("chat").is_null()) {
        o.chat = std::make_shared<Chat>();
        from_json(j.at("chat"), *o.chat);
    }
    if (j.contains("forward_origin") && !j.at("forward_origin").is_null()) {
        MessageOrigin _tmp{};
        from_json(j.at("forward_origin"), _tmp);
        o.forward_origin = std::move(_tmp);
    }
    if (j.contains("is_topic_message") && !j.at("is_topic_message").is_null())
        o.is_topic_message = j.at("is_topic_message").get<bool>();
    if (j.contains("is_automatic_forward") && !j.at("is_automatic_forward").is_null())
        o.is_automatic_forward = j.at("is_automatic_forward").get<bool>();
    if (j.contains("reply_to_message") && !j.at("reply_to_message").is_null()) {
        o.reply_to_message = std::make_shared<Message>();
        from_json(j.at("reply_to_message"), *o.reply_to_message);
    }
    if (j.contains("external_reply") && !j.at("external_reply").is_null()) {
        o.external_reply = std::make_shared<ExternalReplyInfo>();
        from_json(j.at("external_reply"), *o.external_reply);
    }
    if (j.contains("quote") && !j.at("quote").is_null()) {
        o.quote = std::make_shared<TextQuote>();
        from_json(j.at("quote"), *o.quote);
    }
    if (j.contains("reply_to_story") && !j.at("reply_to_story").is_null()) {
        o.reply_to_story = std::make_shared<Story>();
        from_json(j.at("reply_to_story"), *o.reply_to_story);
    }
    if (j.contains("reply_to_checklist_task_id") && !j.at("reply_to_checklist_task_id").is_null())
        o.reply_to_checklist_task_id = j.at("reply_to_checklist_task_id").get<int64_t>();
    if (j.contains("reply_to_poll_option_id") && !j.at("reply_to_poll_option_id").is_null())
        o.reply_to_poll_option_id = j.at("reply_to_poll_option_id").get<std::string>();
    if (j.contains("via_bot") && !j.at("via_bot").is_null()) {
        o.via_bot = std::make_shared<User>();
        from_json(j.at("via_bot"), *o.via_bot);
    }
    if (j.contains("guest_bot_caller_user") && !j.at("guest_bot_caller_user").is_null()) {
        o.guest_bot_caller_user = std::make_shared<User>();
        from_json(j.at("guest_bot_caller_user"), *o.guest_bot_caller_user);
    }
    if (j.contains("guest_bot_caller_chat") && !j.at("guest_bot_caller_chat").is_null()) {
        o.guest_bot_caller_chat = std::make_shared<Chat>();
        from_json(j.at("guest_bot_caller_chat"), *o.guest_bot_caller_chat);
    }
    if (j.contains("edit_date") && !j.at("edit_date").is_null())
        o.edit_date = j.at("edit_date").get<int64_t>();
    if (j.contains("has_protected_content") && !j.at("has_protected_content").is_null())
        o.has_protected_content = j.at("has_protected_content").get<bool>();
    if (j.contains("is_from_offline") && !j.at("is_from_offline").is_null())
        o.is_from_offline = j.at("is_from_offline").get<bool>();
    if (j.contains("is_paid_post") && !j.at("is_paid_post").is_null())
        o.is_paid_post = j.at("is_paid_post").get<bool>();
    if (j.contains("media_group_id") && !j.at("media_group_id").is_null())
        o.media_group_id = j.at("media_group_id").get<std::string>();
    if (j.contains("author_signature") && !j.at("author_signature").is_null())
        o.author_signature = j.at("author_signature").get<std::string>();
    if (j.contains("paid_star_count") && !j.at("paid_star_count").is_null())
        o.paid_star_count = j.at("paid_star_count").get<int64_t>();
    if (j.contains("text") && !j.at("text").is_null())
        o.text = j.at("text").get<std::string>();
    if (j.contains("entities") && j.at("entities").is_array()) {
        for (const auto& _item : j.at("entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("link_preview_options") && !j.at("link_preview_options").is_null()) {
        o.link_preview_options = std::make_shared<LinkPreviewOptions>();
        from_json(j.at("link_preview_options"), *o.link_preview_options);
    }
    if (j.contains("suggested_post_info") && !j.at("suggested_post_info").is_null()) {
        o.suggested_post_info = std::make_shared<SuggestedPostInfo>();
        from_json(j.at("suggested_post_info"), *o.suggested_post_info);
    }
    if (j.contains("effect_id") && !j.at("effect_id").is_null())
        o.effect_id = j.at("effect_id").get<std::string>();
    if (j.contains("animation") && !j.at("animation").is_null()) {
        o.animation = std::make_shared<Animation>();
        from_json(j.at("animation"), *o.animation);
    }
    if (j.contains("audio") && !j.at("audio").is_null()) {
        o.audio = std::make_shared<Audio>();
        from_json(j.at("audio"), *o.audio);
    }
    if (j.contains("document") && !j.at("document").is_null()) {
        o.document = std::make_shared<Document>();
        from_json(j.at("document"), *o.document);
    }
    if (j.contains("live_photo") && !j.at("live_photo").is_null()) {
        o.live_photo = std::make_shared<LivePhoto>();
        from_json(j.at("live_photo"), *o.live_photo);
    }
    if (j.contains("paid_media") && !j.at("paid_media").is_null()) {
        o.paid_media = std::make_shared<PaidMediaInfo>();
        from_json(j.at("paid_media"), *o.paid_media);
    }
    if (j.contains("photo") && j.at("photo").is_array()) {
        for (const auto& _item : j.at("photo")) {
            {
                auto _elem = std::make_shared<PhotoSize>();
                from_json(_item, *_elem);
                o.photo.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("sticker") && !j.at("sticker").is_null()) {
        o.sticker = std::make_shared<Sticker>();
        from_json(j.at("sticker"), *o.sticker);
    }
    if (j.contains("story") && !j.at("story").is_null()) {
        o.story = std::make_shared<Story>();
        from_json(j.at("story"), *o.story);
    }
    if (j.contains("video") && !j.at("video").is_null()) {
        o.video = std::make_shared<Video>();
        from_json(j.at("video"), *o.video);
    }
    if (j.contains("video_note") && !j.at("video_note").is_null()) {
        o.video_note = std::make_shared<VideoNote>();
        from_json(j.at("video_note"), *o.video_note);
    }
    if (j.contains("voice") && !j.at("voice").is_null()) {
        o.voice = std::make_shared<Voice>();
        from_json(j.at("voice"), *o.voice);
    }
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("show_caption_above_media") && !j.at("show_caption_above_media").is_null())
        o.show_caption_above_media = j.at("show_caption_above_media").get<bool>();
    if (j.contains("has_media_spoiler") && !j.at("has_media_spoiler").is_null())
        o.has_media_spoiler = j.at("has_media_spoiler").get<bool>();
    if (j.contains("checklist") && !j.at("checklist").is_null()) {
        o.checklist = std::make_shared<Checklist>();
        from_json(j.at("checklist"), *o.checklist);
    }
    if (j.contains("contact") && !j.at("contact").is_null()) {
        o.contact = std::make_shared<Contact>();
        from_json(j.at("contact"), *o.contact);
    }
    if (j.contains("dice") && !j.at("dice").is_null()) {
        o.dice = std::make_shared<Dice>();
        from_json(j.at("dice"), *o.dice);
    }
    if (j.contains("game") && !j.at("game").is_null()) {
        o.game = std::make_shared<Game>();
        from_json(j.at("game"), *o.game);
    }
    if (j.contains("poll") && !j.at("poll").is_null()) {
        o.poll = std::make_shared<Poll>();
        from_json(j.at("poll"), *o.poll);
    }
    if (j.contains("venue") && !j.at("venue").is_null()) {
        o.venue = std::make_shared<Venue>();
        from_json(j.at("venue"), *o.venue);
    }
    if (j.contains("location") && !j.at("location").is_null()) {
        o.location = std::make_shared<Location>();
        from_json(j.at("location"), *o.location);
    }
    if (j.contains("new_chat_members") && j.at("new_chat_members").is_array()) {
        for (const auto& _item : j.at("new_chat_members")) {
            {
                auto _elem = std::make_shared<User>();
                from_json(_item, *_elem);
                o.new_chat_members.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("left_chat_member") && !j.at("left_chat_member").is_null()) {
        o.left_chat_member = std::make_shared<User>();
        from_json(j.at("left_chat_member"), *o.left_chat_member);
    }
    if (j.contains("chat_owner_left") && !j.at("chat_owner_left").is_null()) {
        o.chat_owner_left = std::make_shared<ChatOwnerLeft>();
        from_json(j.at("chat_owner_left"), *o.chat_owner_left);
    }
    if (j.contains("chat_owner_changed") && !j.at("chat_owner_changed").is_null()) {
        o.chat_owner_changed = std::make_shared<ChatOwnerChanged>();
        from_json(j.at("chat_owner_changed"), *o.chat_owner_changed);
    }
    if (j.contains("new_chat_title") && !j.at("new_chat_title").is_null())
        o.new_chat_title = j.at("new_chat_title").get<std::string>();
    if (j.contains("new_chat_photo") && j.at("new_chat_photo").is_array()) {
        for (const auto& _item : j.at("new_chat_photo")) {
            {
                auto _elem = std::make_shared<PhotoSize>();
                from_json(_item, *_elem);
                o.new_chat_photo.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("delete_chat_photo") && !j.at("delete_chat_photo").is_null())
        o.delete_chat_photo = j.at("delete_chat_photo").get<bool>();
    if (j.contains("group_chat_created") && !j.at("group_chat_created").is_null())
        o.group_chat_created = j.at("group_chat_created").get<bool>();
    if (j.contains("supergroup_chat_created") && !j.at("supergroup_chat_created").is_null())
        o.supergroup_chat_created = j.at("supergroup_chat_created").get<bool>();
    if (j.contains("channel_chat_created") && !j.at("channel_chat_created").is_null())
        o.channel_chat_created = j.at("channel_chat_created").get<bool>();
    if (j.contains("message_auto_delete_timer_changed") && !j.at("message_auto_delete_timer_changed").is_null()) {
        o.message_auto_delete_timer_changed = std::make_shared<MessageAutoDeleteTimerChanged>();
        from_json(j.at("message_auto_delete_timer_changed"), *o.message_auto_delete_timer_changed);
    }
    if (j.contains("migrate_to_chat_id") && !j.at("migrate_to_chat_id").is_null())
        o.migrate_to_chat_id = j.at("migrate_to_chat_id").get<int64_t>();
    if (j.contains("migrate_from_chat_id") && !j.at("migrate_from_chat_id").is_null())
        o.migrate_from_chat_id = j.at("migrate_from_chat_id").get<int64_t>();
    if (j.contains("pinned_message") && !j.at("pinned_message").is_null()) {
        MaybeInaccessibleMessage _tmp{};
        from_json(j.at("pinned_message"), _tmp);
        o.pinned_message = std::move(_tmp);
    }
    if (j.contains("invoice") && !j.at("invoice").is_null()) {
        o.invoice = std::make_shared<Invoice>();
        from_json(j.at("invoice"), *o.invoice);
    }
    if (j.contains("successful_payment") && !j.at("successful_payment").is_null()) {
        o.successful_payment = std::make_shared<SuccessfulPayment>();
        from_json(j.at("successful_payment"), *o.successful_payment);
    }
    if (j.contains("refunded_payment") && !j.at("refunded_payment").is_null()) {
        o.refunded_payment = std::make_shared<RefundedPayment>();
        from_json(j.at("refunded_payment"), *o.refunded_payment);
    }
    if (j.contains("users_shared") && !j.at("users_shared").is_null()) {
        o.users_shared = std::make_shared<UsersShared>();
        from_json(j.at("users_shared"), *o.users_shared);
    }
    if (j.contains("chat_shared") && !j.at("chat_shared").is_null()) {
        o.chat_shared = std::make_shared<ChatShared>();
        from_json(j.at("chat_shared"), *o.chat_shared);
    }
    if (j.contains("gift") && !j.at("gift").is_null()) {
        o.gift = std::make_shared<GiftInfo>();
        from_json(j.at("gift"), *o.gift);
    }
    if (j.contains("unique_gift") && !j.at("unique_gift").is_null()) {
        o.unique_gift = std::make_shared<UniqueGiftInfo>();
        from_json(j.at("unique_gift"), *o.unique_gift);
    }
    if (j.contains("gift_upgrade_sent") && !j.at("gift_upgrade_sent").is_null()) {
        o.gift_upgrade_sent = std::make_shared<GiftInfo>();
        from_json(j.at("gift_upgrade_sent"), *o.gift_upgrade_sent);
    }
    if (j.contains("connected_website") && !j.at("connected_website").is_null())
        o.connected_website = j.at("connected_website").get<std::string>();
    if (j.contains("write_access_allowed") && !j.at("write_access_allowed").is_null()) {
        o.write_access_allowed = std::make_shared<WriteAccessAllowed>();
        from_json(j.at("write_access_allowed"), *o.write_access_allowed);
    }
    if (j.contains("passport_data") && !j.at("passport_data").is_null()) {
        o.passport_data = std::make_shared<PassportData>();
        from_json(j.at("passport_data"), *o.passport_data);
    }
    if (j.contains("proximity_alert_triggered") && !j.at("proximity_alert_triggered").is_null()) {
        o.proximity_alert_triggered = std::make_shared<ProximityAlertTriggered>();
        from_json(j.at("proximity_alert_triggered"), *o.proximity_alert_triggered);
    }
    if (j.contains("boost_added") && !j.at("boost_added").is_null()) {
        o.boost_added = std::make_shared<ChatBoostAdded>();
        from_json(j.at("boost_added"), *o.boost_added);
    }
    if (j.contains("chat_background_set") && !j.at("chat_background_set").is_null()) {
        o.chat_background_set = std::make_shared<ChatBackground>();
        from_json(j.at("chat_background_set"), *o.chat_background_set);
    }
    if (j.contains("checklist_tasks_done") && !j.at("checklist_tasks_done").is_null()) {
        o.checklist_tasks_done = std::make_shared<ChecklistTasksDone>();
        from_json(j.at("checklist_tasks_done"), *o.checklist_tasks_done);
    }
    if (j.contains("checklist_tasks_added") && !j.at("checklist_tasks_added").is_null()) {
        o.checklist_tasks_added = std::make_shared<ChecklistTasksAdded>();
        from_json(j.at("checklist_tasks_added"), *o.checklist_tasks_added);
    }
    if (j.contains("direct_message_price_changed") && !j.at("direct_message_price_changed").is_null()) {
        o.direct_message_price_changed = std::make_shared<DirectMessagePriceChanged>();
        from_json(j.at("direct_message_price_changed"), *o.direct_message_price_changed);
    }
    if (j.contains("forum_topic_created") && !j.at("forum_topic_created").is_null()) {
        o.forum_topic_created = std::make_shared<ForumTopicCreated>();
        from_json(j.at("forum_topic_created"), *o.forum_topic_created);
    }
    if (j.contains("forum_topic_edited") && !j.at("forum_topic_edited").is_null()) {
        o.forum_topic_edited = std::make_shared<ForumTopicEdited>();
        from_json(j.at("forum_topic_edited"), *o.forum_topic_edited);
    }
    if (j.contains("forum_topic_closed") && !j.at("forum_topic_closed").is_null()) {
        o.forum_topic_closed = std::make_shared<ForumTopicClosed>();
        from_json(j.at("forum_topic_closed"), *o.forum_topic_closed);
    }
    if (j.contains("forum_topic_reopened") && !j.at("forum_topic_reopened").is_null()) {
        o.forum_topic_reopened = std::make_shared<ForumTopicReopened>();
        from_json(j.at("forum_topic_reopened"), *o.forum_topic_reopened);
    }
    if (j.contains("general_forum_topic_hidden") && !j.at("general_forum_topic_hidden").is_null()) {
        o.general_forum_topic_hidden = std::make_shared<GeneralForumTopicHidden>();
        from_json(j.at("general_forum_topic_hidden"), *o.general_forum_topic_hidden);
    }
    if (j.contains("general_forum_topic_unhidden") && !j.at("general_forum_topic_unhidden").is_null()) {
        o.general_forum_topic_unhidden = std::make_shared<GeneralForumTopicUnhidden>();
        from_json(j.at("general_forum_topic_unhidden"), *o.general_forum_topic_unhidden);
    }
    if (j.contains("giveaway_created") && !j.at("giveaway_created").is_null()) {
        o.giveaway_created = std::make_shared<GiveawayCreated>();
        from_json(j.at("giveaway_created"), *o.giveaway_created);
    }
    if (j.contains("giveaway") && !j.at("giveaway").is_null()) {
        o.giveaway = std::make_shared<Giveaway>();
        from_json(j.at("giveaway"), *o.giveaway);
    }
    if (j.contains("giveaway_winners") && !j.at("giveaway_winners").is_null()) {
        o.giveaway_winners = std::make_shared<GiveawayWinners>();
        from_json(j.at("giveaway_winners"), *o.giveaway_winners);
    }
    if (j.contains("giveaway_completed") && !j.at("giveaway_completed").is_null()) {
        o.giveaway_completed = std::make_shared<GiveawayCompleted>();
        from_json(j.at("giveaway_completed"), *o.giveaway_completed);
    }
    if (j.contains("managed_bot_created") && !j.at("managed_bot_created").is_null()) {
        o.managed_bot_created = std::make_shared<ManagedBotCreated>();
        from_json(j.at("managed_bot_created"), *o.managed_bot_created);
    }
    if (j.contains("paid_message_price_changed") && !j.at("paid_message_price_changed").is_null()) {
        o.paid_message_price_changed = std::make_shared<PaidMessagePriceChanged>();
        from_json(j.at("paid_message_price_changed"), *o.paid_message_price_changed);
    }
    if (j.contains("poll_option_added") && !j.at("poll_option_added").is_null()) {
        o.poll_option_added = std::make_shared<PollOptionAdded>();
        from_json(j.at("poll_option_added"), *o.poll_option_added);
    }
    if (j.contains("poll_option_deleted") && !j.at("poll_option_deleted").is_null()) {
        o.poll_option_deleted = std::make_shared<PollOptionDeleted>();
        from_json(j.at("poll_option_deleted"), *o.poll_option_deleted);
    }
    if (j.contains("suggested_post_approved") && !j.at("suggested_post_approved").is_null()) {
        o.suggested_post_approved = std::make_shared<SuggestedPostApproved>();
        from_json(j.at("suggested_post_approved"), *o.suggested_post_approved);
    }
    if (j.contains("suggested_post_approval_failed") && !j.at("suggested_post_approval_failed").is_null()) {
        o.suggested_post_approval_failed = std::make_shared<SuggestedPostApprovalFailed>();
        from_json(j.at("suggested_post_approval_failed"), *o.suggested_post_approval_failed);
    }
    if (j.contains("suggested_post_declined") && !j.at("suggested_post_declined").is_null()) {
        o.suggested_post_declined = std::make_shared<SuggestedPostDeclined>();
        from_json(j.at("suggested_post_declined"), *o.suggested_post_declined);
    }
    if (j.contains("suggested_post_paid") && !j.at("suggested_post_paid").is_null()) {
        o.suggested_post_paid = std::make_shared<SuggestedPostPaid>();
        from_json(j.at("suggested_post_paid"), *o.suggested_post_paid);
    }
    if (j.contains("suggested_post_refunded") && !j.at("suggested_post_refunded").is_null()) {
        o.suggested_post_refunded = std::make_shared<SuggestedPostRefunded>();
        from_json(j.at("suggested_post_refunded"), *o.suggested_post_refunded);
    }
    if (j.contains("video_chat_scheduled") && !j.at("video_chat_scheduled").is_null()) {
        o.video_chat_scheduled = std::make_shared<VideoChatScheduled>();
        from_json(j.at("video_chat_scheduled"), *o.video_chat_scheduled);
    }
    if (j.contains("video_chat_started") && !j.at("video_chat_started").is_null()) {
        o.video_chat_started = std::make_shared<VideoChatStarted>();
        from_json(j.at("video_chat_started"), *o.video_chat_started);
    }
    if (j.contains("video_chat_ended") && !j.at("video_chat_ended").is_null()) {
        o.video_chat_ended = std::make_shared<VideoChatEnded>();
        from_json(j.at("video_chat_ended"), *o.video_chat_ended);
    }
    if (j.contains("video_chat_participants_invited") && !j.at("video_chat_participants_invited").is_null()) {
        o.video_chat_participants_invited = std::make_shared<VideoChatParticipantsInvited>();
        from_json(j.at("video_chat_participants_invited"), *o.video_chat_participants_invited);
    }
    if (j.contains("web_app_data") && !j.at("web_app_data").is_null()) {
        o.web_app_data = std::make_shared<WebAppData>();
        from_json(j.at("web_app_data"), *o.web_app_data);
    }
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
}

inline void to_json(json& j, const Message& o) {
    j = json::object();
    j["message_id"] = o.message_id;
    if (o.message_thread_id.has_value())
        j["message_thread_id"] = o.message_thread_id.value();
    if (o.direct_messages_topic) {
        json _sub; to_json(_sub, *o.direct_messages_topic); j["direct_messages_topic"] = std::move(_sub);
    }
    if (o.from) {
        json _sub; to_json(_sub, *o.from); j["from"] = std::move(_sub);
    }
    if (o.sender_chat) {
        json _sub; to_json(_sub, *o.sender_chat); j["sender_chat"] = std::move(_sub);
    }
    if (o.sender_boost_count.has_value())
        j["sender_boost_count"] = o.sender_boost_count.value();
    if (o.sender_business_bot) {
        json _sub; to_json(_sub, *o.sender_business_bot); j["sender_business_bot"] = std::move(_sub);
    }
    if (o.sender_tag.has_value())
        j["sender_tag"] = o.sender_tag.value();
    j["date"] = o.date;
    if (o.guest_query_id.has_value())
        j["guest_query_id"] = o.guest_query_id.value();
    if (o.business_connection_id.has_value())
        j["business_connection_id"] = o.business_connection_id.value();
    {
        json _sub; to_json(_sub, *o.chat); j["chat"] = std::move(_sub);
    }
    if (o.forward_origin.has_value()) {
        json _sub;
        to_json(_sub, o.forward_origin.value());
        j["forward_origin"] = std::move(_sub);
    }
    if (o.is_topic_message.has_value())
        j["is_topic_message"] = o.is_topic_message.value();
    if (o.is_automatic_forward.has_value())
        j["is_automatic_forward"] = o.is_automatic_forward.value();
    if (o.reply_to_message) {
        json _sub; to_json(_sub, *o.reply_to_message); j["reply_to_message"] = std::move(_sub);
    }
    if (o.external_reply) {
        json _sub; to_json(_sub, *o.external_reply); j["external_reply"] = std::move(_sub);
    }
    if (o.quote) {
        json _sub; to_json(_sub, *o.quote); j["quote"] = std::move(_sub);
    }
    if (o.reply_to_story) {
        json _sub; to_json(_sub, *o.reply_to_story); j["reply_to_story"] = std::move(_sub);
    }
    if (o.reply_to_checklist_task_id.has_value())
        j["reply_to_checklist_task_id"] = o.reply_to_checklist_task_id.value();
    if (o.reply_to_poll_option_id.has_value())
        j["reply_to_poll_option_id"] = o.reply_to_poll_option_id.value();
    if (o.via_bot) {
        json _sub; to_json(_sub, *o.via_bot); j["via_bot"] = std::move(_sub);
    }
    if (o.guest_bot_caller_user) {
        json _sub; to_json(_sub, *o.guest_bot_caller_user); j["guest_bot_caller_user"] = std::move(_sub);
    }
    if (o.guest_bot_caller_chat) {
        json _sub; to_json(_sub, *o.guest_bot_caller_chat); j["guest_bot_caller_chat"] = std::move(_sub);
    }
    if (o.edit_date.has_value())
        j["edit_date"] = o.edit_date.value();
    if (o.has_protected_content.has_value())
        j["has_protected_content"] = o.has_protected_content.value();
    if (o.is_from_offline.has_value())
        j["is_from_offline"] = o.is_from_offline.value();
    if (o.is_paid_post.has_value())
        j["is_paid_post"] = o.is_paid_post.value();
    if (o.media_group_id.has_value())
        j["media_group_id"] = o.media_group_id.value();
    if (o.author_signature.has_value())
        j["author_signature"] = o.author_signature.value();
    if (o.paid_star_count.has_value())
        j["paid_star_count"] = o.paid_star_count.value();
    if (o.text.has_value())
        j["text"] = o.text.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["entities"] = std::move(_arr);
    }
    if (o.link_preview_options) {
        json _sub; to_json(_sub, *o.link_preview_options); j["link_preview_options"] = std::move(_sub);
    }
    if (o.suggested_post_info) {
        json _sub; to_json(_sub, *o.suggested_post_info); j["suggested_post_info"] = std::move(_sub);
    }
    if (o.effect_id.has_value())
        j["effect_id"] = o.effect_id.value();
    if (o.animation) {
        json _sub; to_json(_sub, *o.animation); j["animation"] = std::move(_sub);
    }
    if (o.audio) {
        json _sub; to_json(_sub, *o.audio); j["audio"] = std::move(_sub);
    }
    if (o.document) {
        json _sub; to_json(_sub, *o.document); j["document"] = std::move(_sub);
    }
    if (o.live_photo) {
        json _sub; to_json(_sub, *o.live_photo); j["live_photo"] = std::move(_sub);
    }
    if (o.paid_media) {
        json _sub; to_json(_sub, *o.paid_media); j["paid_media"] = std::move(_sub);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.photo) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["photo"] = std::move(_arr);
    }
    if (o.sticker) {
        json _sub; to_json(_sub, *o.sticker); j["sticker"] = std::move(_sub);
    }
    if (o.story) {
        json _sub; to_json(_sub, *o.story); j["story"] = std::move(_sub);
    }
    if (o.video) {
        json _sub; to_json(_sub, *o.video); j["video"] = std::move(_sub);
    }
    if (o.video_note) {
        json _sub; to_json(_sub, *o.video_note); j["video_note"] = std::move(_sub);
    }
    if (o.voice) {
        json _sub; to_json(_sub, *o.voice); j["voice"] = std::move(_sub);
    }
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.show_caption_above_media.has_value())
        j["show_caption_above_media"] = o.show_caption_above_media.value();
    if (o.has_media_spoiler.has_value())
        j["has_media_spoiler"] = o.has_media_spoiler.value();
    if (o.checklist) {
        json _sub; to_json(_sub, *o.checklist); j["checklist"] = std::move(_sub);
    }
    if (o.contact) {
        json _sub; to_json(_sub, *o.contact); j["contact"] = std::move(_sub);
    }
    if (o.dice) {
        json _sub; to_json(_sub, *o.dice); j["dice"] = std::move(_sub);
    }
    if (o.game) {
        json _sub; to_json(_sub, *o.game); j["game"] = std::move(_sub);
    }
    if (o.poll) {
        json _sub; to_json(_sub, *o.poll); j["poll"] = std::move(_sub);
    }
    if (o.venue) {
        json _sub; to_json(_sub, *o.venue); j["venue"] = std::move(_sub);
    }
    if (o.location) {
        json _sub; to_json(_sub, *o.location); j["location"] = std::move(_sub);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.new_chat_members) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["new_chat_members"] = std::move(_arr);
    }
    if (o.left_chat_member) {
        json _sub; to_json(_sub, *o.left_chat_member); j["left_chat_member"] = std::move(_sub);
    }
    if (o.chat_owner_left) {
        json _sub; to_json(_sub, *o.chat_owner_left); j["chat_owner_left"] = std::move(_sub);
    }
    if (o.chat_owner_changed) {
        json _sub; to_json(_sub, *o.chat_owner_changed); j["chat_owner_changed"] = std::move(_sub);
    }
    if (o.new_chat_title.has_value())
        j["new_chat_title"] = o.new_chat_title.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.new_chat_photo) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["new_chat_photo"] = std::move(_arr);
    }
    if (o.delete_chat_photo.has_value())
        j["delete_chat_photo"] = o.delete_chat_photo.value();
    if (o.group_chat_created.has_value())
        j["group_chat_created"] = o.group_chat_created.value();
    if (o.supergroup_chat_created.has_value())
        j["supergroup_chat_created"] = o.supergroup_chat_created.value();
    if (o.channel_chat_created.has_value())
        j["channel_chat_created"] = o.channel_chat_created.value();
    if (o.message_auto_delete_timer_changed) {
        json _sub; to_json(_sub, *o.message_auto_delete_timer_changed); j["message_auto_delete_timer_changed"] = std::move(_sub);
    }
    if (o.migrate_to_chat_id.has_value())
        j["migrate_to_chat_id"] = o.migrate_to_chat_id.value();
    if (o.migrate_from_chat_id.has_value())
        j["migrate_from_chat_id"] = o.migrate_from_chat_id.value();
    if (o.pinned_message.has_value()) {
        json _sub;
        to_json(_sub, o.pinned_message.value());
        j["pinned_message"] = std::move(_sub);
    }
    if (o.invoice) {
        json _sub; to_json(_sub, *o.invoice); j["invoice"] = std::move(_sub);
    }
    if (o.successful_payment) {
        json _sub; to_json(_sub, *o.successful_payment); j["successful_payment"] = std::move(_sub);
    }
    if (o.refunded_payment) {
        json _sub; to_json(_sub, *o.refunded_payment); j["refunded_payment"] = std::move(_sub);
    }
    if (o.users_shared) {
        json _sub; to_json(_sub, *o.users_shared); j["users_shared"] = std::move(_sub);
    }
    if (o.chat_shared) {
        json _sub; to_json(_sub, *o.chat_shared); j["chat_shared"] = std::move(_sub);
    }
    if (o.gift) {
        json _sub; to_json(_sub, *o.gift); j["gift"] = std::move(_sub);
    }
    if (o.unique_gift) {
        json _sub; to_json(_sub, *o.unique_gift); j["unique_gift"] = std::move(_sub);
    }
    if (o.gift_upgrade_sent) {
        json _sub; to_json(_sub, *o.gift_upgrade_sent); j["gift_upgrade_sent"] = std::move(_sub);
    }
    if (o.connected_website.has_value())
        j["connected_website"] = o.connected_website.value();
    if (o.write_access_allowed) {
        json _sub; to_json(_sub, *o.write_access_allowed); j["write_access_allowed"] = std::move(_sub);
    }
    if (o.passport_data) {
        json _sub; to_json(_sub, *o.passport_data); j["passport_data"] = std::move(_sub);
    }
    if (o.proximity_alert_triggered) {
        json _sub; to_json(_sub, *o.proximity_alert_triggered); j["proximity_alert_triggered"] = std::move(_sub);
    }
    if (o.boost_added) {
        json _sub; to_json(_sub, *o.boost_added); j["boost_added"] = std::move(_sub);
    }
    if (o.chat_background_set) {
        json _sub; to_json(_sub, *o.chat_background_set); j["chat_background_set"] = std::move(_sub);
    }
    if (o.checklist_tasks_done) {
        json _sub; to_json(_sub, *o.checklist_tasks_done); j["checklist_tasks_done"] = std::move(_sub);
    }
    if (o.checklist_tasks_added) {
        json _sub; to_json(_sub, *o.checklist_tasks_added); j["checklist_tasks_added"] = std::move(_sub);
    }
    if (o.direct_message_price_changed) {
        json _sub; to_json(_sub, *o.direct_message_price_changed); j["direct_message_price_changed"] = std::move(_sub);
    }
    if (o.forum_topic_created) {
        json _sub; to_json(_sub, *o.forum_topic_created); j["forum_topic_created"] = std::move(_sub);
    }
    if (o.forum_topic_edited) {
        json _sub; to_json(_sub, *o.forum_topic_edited); j["forum_topic_edited"] = std::move(_sub);
    }
    if (o.forum_topic_closed) {
        json _sub; to_json(_sub, *o.forum_topic_closed); j["forum_topic_closed"] = std::move(_sub);
    }
    if (o.forum_topic_reopened) {
        json _sub; to_json(_sub, *o.forum_topic_reopened); j["forum_topic_reopened"] = std::move(_sub);
    }
    if (o.general_forum_topic_hidden) {
        json _sub; to_json(_sub, *o.general_forum_topic_hidden); j["general_forum_topic_hidden"] = std::move(_sub);
    }
    if (o.general_forum_topic_unhidden) {
        json _sub; to_json(_sub, *o.general_forum_topic_unhidden); j["general_forum_topic_unhidden"] = std::move(_sub);
    }
    if (o.giveaway_created) {
        json _sub; to_json(_sub, *o.giveaway_created); j["giveaway_created"] = std::move(_sub);
    }
    if (o.giveaway) {
        json _sub; to_json(_sub, *o.giveaway); j["giveaway"] = std::move(_sub);
    }
    if (o.giveaway_winners) {
        json _sub; to_json(_sub, *o.giveaway_winners); j["giveaway_winners"] = std::move(_sub);
    }
    if (o.giveaway_completed) {
        json _sub; to_json(_sub, *o.giveaway_completed); j["giveaway_completed"] = std::move(_sub);
    }
    if (o.managed_bot_created) {
        json _sub; to_json(_sub, *o.managed_bot_created); j["managed_bot_created"] = std::move(_sub);
    }
    if (o.paid_message_price_changed) {
        json _sub; to_json(_sub, *o.paid_message_price_changed); j["paid_message_price_changed"] = std::move(_sub);
    }
    if (o.poll_option_added) {
        json _sub; to_json(_sub, *o.poll_option_added); j["poll_option_added"] = std::move(_sub);
    }
    if (o.poll_option_deleted) {
        json _sub; to_json(_sub, *o.poll_option_deleted); j["poll_option_deleted"] = std::move(_sub);
    }
    if (o.suggested_post_approved) {
        json _sub; to_json(_sub, *o.suggested_post_approved); j["suggested_post_approved"] = std::move(_sub);
    }
    if (o.suggested_post_approval_failed) {
        json _sub; to_json(_sub, *o.suggested_post_approval_failed); j["suggested_post_approval_failed"] = std::move(_sub);
    }
    if (o.suggested_post_declined) {
        json _sub; to_json(_sub, *o.suggested_post_declined); j["suggested_post_declined"] = std::move(_sub);
    }
    if (o.suggested_post_paid) {
        json _sub; to_json(_sub, *o.suggested_post_paid); j["suggested_post_paid"] = std::move(_sub);
    }
    if (o.suggested_post_refunded) {
        json _sub; to_json(_sub, *o.suggested_post_refunded); j["suggested_post_refunded"] = std::move(_sub);
    }
    if (o.video_chat_scheduled) {
        json _sub; to_json(_sub, *o.video_chat_scheduled); j["video_chat_scheduled"] = std::move(_sub);
    }
    if (o.video_chat_started) {
        json _sub; to_json(_sub, *o.video_chat_started); j["video_chat_started"] = std::move(_sub);
    }
    if (o.video_chat_ended) {
        json _sub; to_json(_sub, *o.video_chat_ended); j["video_chat_ended"] = std::move(_sub);
    }
    if (o.video_chat_participants_invited) {
        json _sub; to_json(_sub, *o.video_chat_participants_invited); j["video_chat_participants_invited"] = std::move(_sub);
    }
    if (o.web_app_data) {
        json _sub; to_json(_sub, *o.web_app_data); j["web_app_data"] = std::move(_sub);
    }
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
}

inline void from_json(const json& j, MessageId& o) {
    o.message_id = j.contains("message_id") && !j.at("message_id").is_null()
        ? j.at("message_id").get<int64_t>() : 0;
}

inline void to_json(json& j, const MessageId& o) {
    j = json::object();
    j["message_id"] = o.message_id;
}

inline void from_json(const json& j, InaccessibleMessage& o) {
    if (j.contains("chat") && !j.at("chat").is_null()) {
        o.chat = std::make_shared<Chat>();
        from_json(j.at("chat"), *o.chat);
    }
    o.message_id = j.contains("message_id") && !j.at("message_id").is_null()
        ? j.at("message_id").get<int64_t>() : 0;
    o.date = j.contains("date") && !j.at("date").is_null()
        ? j.at("date").get<int64_t>() : 0;
}

inline void to_json(json& j, const InaccessibleMessage& o) {
    j = json::object();
    {
        json _sub; to_json(_sub, *o.chat); j["chat"] = std::move(_sub);
    }
    j["message_id"] = o.message_id;
    j["date"] = o.date;
}

inline void from_json(const json& j, MaybeInaccessibleMessage& v) {
    const int64_t _disc = j.contains("date")
        ? j.at("date").get<int64_t>() : -1;
    if (_disc == 0) {
        auto obj = std::make_shared<InaccessibleMessage>();
        from_json(j, *obj); v = obj; return;
    }
    auto obj = std::make_shared<Message>();
    from_json(j, *obj); v = obj;
}

inline void to_json(json& j, const MaybeInaccessibleMessage& v) {
    if (auto* p = std::get_if <std::shared_ptr<Message>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InaccessibleMessage>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, MessageEntity& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.offset = j.contains("offset") && !j.at("offset").is_null()
        ? j.at("offset").get<int64_t>() : 0;
    o.length = j.contains("length") && !j.at("length").is_null()
        ? j.at("length").get<int64_t>() : 0;
    if (j.contains("url") && !j.at("url").is_null())
        o.url = j.at("url").get<std::string>();
    if (j.contains("user") && !j.at("user").is_null()) {
        o.user = std::make_shared<User>();
        from_json(j.at("user"), *o.user);
    }
    if (j.contains("language") && !j.at("language").is_null())
        o.language = j.at("language").get<std::string>();
    if (j.contains("custom_emoji_id") && !j.at("custom_emoji_id").is_null())
        o.custom_emoji_id = j.at("custom_emoji_id").get<std::string>();
    if (j.contains("unix_time") && !j.at("unix_time").is_null())
        o.unix_time = j.at("unix_time").get<int64_t>();
    if (j.contains("date_time_format") && !j.at("date_time_format").is_null())
        o.date_time_format = j.at("date_time_format").get<std::string>();
}

inline void to_json(json& j, const MessageEntity& o) {
    j = json::object();
    j["type"] = o.type;
    j["offset"] = o.offset;
    j["length"] = o.length;
    if (o.url.has_value())
        j["url"] = o.url.value();
    if (o.user) {
        json _sub; to_json(_sub, *o.user); j["user"] = std::move(_sub);
    }
    if (o.language.has_value())
        j["language"] = o.language.value();
    if (o.custom_emoji_id.has_value())
        j["custom_emoji_id"] = o.custom_emoji_id.value();
    if (o.unix_time.has_value())
        j["unix_time"] = o.unix_time.value();
    if (o.date_time_format.has_value())
        j["date_time_format"] = o.date_time_format.value();
}

inline void from_json(const json& j, TextQuote& o) {
    o.text = j.contains("text") && !j.at("text").is_null()
        ? j.at("text").get<std::string>() : "";
    if (j.contains("entities") && j.at("entities").is_array()) {
        for (const auto& _item : j.at("entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.entities.push_back(std::move(_elem));
            }
        }
    }
    o.position = j.contains("position") && !j.at("position").is_null()
        ? j.at("position").get<int64_t>() : 0;
    if (j.contains("is_manual") && !j.at("is_manual").is_null())
        o.is_manual = j.at("is_manual").get<bool>();
}

inline void to_json(json& j, const TextQuote& o) {
    j = json::object();
    j["text"] = o.text;
    {
        json _arr = json::array();
        for (const auto& _item : o.entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["entities"] = std::move(_arr);
    }
    j["position"] = o.position;
    if (o.is_manual.has_value())
        j["is_manual"] = o.is_manual.value();
}

inline void from_json(const json& j, ExternalReplyInfo& o) {
    if (j.contains("origin") && !j.at("origin").is_null()) {
        from_json(j.at("origin"), o.origin);
    }
    if (j.contains("chat") && !j.at("chat").is_null()) {
        o.chat = std::make_shared<Chat>();
        from_json(j.at("chat"), *o.chat);
    }
    if (j.contains("message_id") && !j.at("message_id").is_null())
        o.message_id = j.at("message_id").get<int64_t>();
    if (j.contains("link_preview_options") && !j.at("link_preview_options").is_null()) {
        o.link_preview_options = std::make_shared<LinkPreviewOptions>();
        from_json(j.at("link_preview_options"), *o.link_preview_options);
    }
    if (j.contains("animation") && !j.at("animation").is_null()) {
        o.animation = std::make_shared<Animation>();
        from_json(j.at("animation"), *o.animation);
    }
    if (j.contains("audio") && !j.at("audio").is_null()) {
        o.audio = std::make_shared<Audio>();
        from_json(j.at("audio"), *o.audio);
    }
    if (j.contains("document") && !j.at("document").is_null()) {
        o.document = std::make_shared<Document>();
        from_json(j.at("document"), *o.document);
    }
    if (j.contains("live_photo") && !j.at("live_photo").is_null()) {
        o.live_photo = std::make_shared<LivePhoto>();
        from_json(j.at("live_photo"), *o.live_photo);
    }
    if (j.contains("paid_media") && !j.at("paid_media").is_null()) {
        o.paid_media = std::make_shared<PaidMediaInfo>();
        from_json(j.at("paid_media"), *o.paid_media);
    }
    if (j.contains("photo") && j.at("photo").is_array()) {
        for (const auto& _item : j.at("photo")) {
            {
                auto _elem = std::make_shared<PhotoSize>();
                from_json(_item, *_elem);
                o.photo.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("sticker") && !j.at("sticker").is_null()) {
        o.sticker = std::make_shared<Sticker>();
        from_json(j.at("sticker"), *o.sticker);
    }
    if (j.contains("story") && !j.at("story").is_null()) {
        o.story = std::make_shared<Story>();
        from_json(j.at("story"), *o.story);
    }
    if (j.contains("video") && !j.at("video").is_null()) {
        o.video = std::make_shared<Video>();
        from_json(j.at("video"), *o.video);
    }
    if (j.contains("video_note") && !j.at("video_note").is_null()) {
        o.video_note = std::make_shared<VideoNote>();
        from_json(j.at("video_note"), *o.video_note);
    }
    if (j.contains("voice") && !j.at("voice").is_null()) {
        o.voice = std::make_shared<Voice>();
        from_json(j.at("voice"), *o.voice);
    }
    if (j.contains("has_media_spoiler") && !j.at("has_media_spoiler").is_null())
        o.has_media_spoiler = j.at("has_media_spoiler").get<bool>();
    if (j.contains("checklist") && !j.at("checklist").is_null()) {
        o.checklist = std::make_shared<Checklist>();
        from_json(j.at("checklist"), *o.checklist);
    }
    if (j.contains("contact") && !j.at("contact").is_null()) {
        o.contact = std::make_shared<Contact>();
        from_json(j.at("contact"), *o.contact);
    }
    if (j.contains("dice") && !j.at("dice").is_null()) {
        o.dice = std::make_shared<Dice>();
        from_json(j.at("dice"), *o.dice);
    }
    if (j.contains("game") && !j.at("game").is_null()) {
        o.game = std::make_shared<Game>();
        from_json(j.at("game"), *o.game);
    }
    if (j.contains("giveaway") && !j.at("giveaway").is_null()) {
        o.giveaway = std::make_shared<Giveaway>();
        from_json(j.at("giveaway"), *o.giveaway);
    }
    if (j.contains("giveaway_winners") && !j.at("giveaway_winners").is_null()) {
        o.giveaway_winners = std::make_shared<GiveawayWinners>();
        from_json(j.at("giveaway_winners"), *o.giveaway_winners);
    }
    if (j.contains("invoice") && !j.at("invoice").is_null()) {
        o.invoice = std::make_shared<Invoice>();
        from_json(j.at("invoice"), *o.invoice);
    }
    if (j.contains("location") && !j.at("location").is_null()) {
        o.location = std::make_shared<Location>();
        from_json(j.at("location"), *o.location);
    }
    if (j.contains("poll") && !j.at("poll").is_null()) {
        o.poll = std::make_shared<Poll>();
        from_json(j.at("poll"), *o.poll);
    }
    if (j.contains("venue") && !j.at("venue").is_null()) {
        o.venue = std::make_shared<Venue>();
        from_json(j.at("venue"), *o.venue);
    }
}

inline void to_json(json& j, const ExternalReplyInfo& o) {
    j = json::object();
    {
        json _sub;
        to_json(_sub, o.origin);
        j["origin"] = std::move(_sub);
    }
    if (o.chat) {
        json _sub; to_json(_sub, *o.chat); j["chat"] = std::move(_sub);
    }
    if (o.message_id.has_value())
        j["message_id"] = o.message_id.value();
    if (o.link_preview_options) {
        json _sub; to_json(_sub, *o.link_preview_options); j["link_preview_options"] = std::move(_sub);
    }
    if (o.animation) {
        json _sub; to_json(_sub, *o.animation); j["animation"] = std::move(_sub);
    }
    if (o.audio) {
        json _sub; to_json(_sub, *o.audio); j["audio"] = std::move(_sub);
    }
    if (o.document) {
        json _sub; to_json(_sub, *o.document); j["document"] = std::move(_sub);
    }
    if (o.live_photo) {
        json _sub; to_json(_sub, *o.live_photo); j["live_photo"] = std::move(_sub);
    }
    if (o.paid_media) {
        json _sub; to_json(_sub, *o.paid_media); j["paid_media"] = std::move(_sub);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.photo) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["photo"] = std::move(_arr);
    }
    if (o.sticker) {
        json _sub; to_json(_sub, *o.sticker); j["sticker"] = std::move(_sub);
    }
    if (o.story) {
        json _sub; to_json(_sub, *o.story); j["story"] = std::move(_sub);
    }
    if (o.video) {
        json _sub; to_json(_sub, *o.video); j["video"] = std::move(_sub);
    }
    if (o.video_note) {
        json _sub; to_json(_sub, *o.video_note); j["video_note"] = std::move(_sub);
    }
    if (o.voice) {
        json _sub; to_json(_sub, *o.voice); j["voice"] = std::move(_sub);
    }
    if (o.has_media_spoiler.has_value())
        j["has_media_spoiler"] = o.has_media_spoiler.value();
    if (o.checklist) {
        json _sub; to_json(_sub, *o.checklist); j["checklist"] = std::move(_sub);
    }
    if (o.contact) {
        json _sub; to_json(_sub, *o.contact); j["contact"] = std::move(_sub);
    }
    if (o.dice) {
        json _sub; to_json(_sub, *o.dice); j["dice"] = std::move(_sub);
    }
    if (o.game) {
        json _sub; to_json(_sub, *o.game); j["game"] = std::move(_sub);
    }
    if (o.giveaway) {
        json _sub; to_json(_sub, *o.giveaway); j["giveaway"] = std::move(_sub);
    }
    if (o.giveaway_winners) {
        json _sub; to_json(_sub, *o.giveaway_winners); j["giveaway_winners"] = std::move(_sub);
    }
    if (o.invoice) {
        json _sub; to_json(_sub, *o.invoice); j["invoice"] = std::move(_sub);
    }
    if (o.location) {
        json _sub; to_json(_sub, *o.location); j["location"] = std::move(_sub);
    }
    if (o.poll) {
        json _sub; to_json(_sub, *o.poll); j["poll"] = std::move(_sub);
    }
    if (o.venue) {
        json _sub; to_json(_sub, *o.venue); j["venue"] = std::move(_sub);
    }
}

inline void from_json(const json& j, ReplyParameters& o) {
    o.message_id = j.contains("message_id") && !j.at("message_id").is_null()
        ? j.at("message_id").get<int64_t>() : 0;
    if (j.contains("chat_id") && !j.at("chat_id").is_null()) {
        if (j.at("chat_id").is_number_integer())
            o.chat_id = j.at("chat_id").get<int64_t>();
        else
            o.chat_id = j.at("chat_id").get<std::string>();
    }
    if (j.contains("allow_sending_without_reply") && !j.at("allow_sending_without_reply").is_null())
        o.allow_sending_without_reply = j.at("allow_sending_without_reply").get<bool>();
    if (j.contains("quote") && !j.at("quote").is_null())
        o.quote = j.at("quote").get<std::string>();
    if (j.contains("quote_parse_mode") && !j.at("quote_parse_mode").is_null())
        o.quote_parse_mode = j.at("quote_parse_mode").get<std::string>();
    if (j.contains("quote_entities") && j.at("quote_entities").is_array()) {
        for (const auto& _item : j.at("quote_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.quote_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("quote_position") && !j.at("quote_position").is_null())
        o.quote_position = j.at("quote_position").get<int64_t>();
    if (j.contains("checklist_task_id") && !j.at("checklist_task_id").is_null())
        o.checklist_task_id = j.at("checklist_task_id").get<int64_t>();
    if (j.contains("poll_option_id") && !j.at("poll_option_id").is_null())
        o.poll_option_id = j.at("poll_option_id").get<std::string>();
}

inline void to_json(json& j, const ReplyParameters& o) {
    j = json::object();
    j["message_id"] = o.message_id;
    if (o.chat_id.has_value()) {
        if (auto* _p = std::get_if<int64_t>(&o.chat_id.value())) {
            j["chat_id"] = *_p;
        }
        if (auto* _p = std::get_if<std::string>(&o.chat_id.value())) {
            j["chat_id"] = *_p;
        }
    }
    if (o.allow_sending_without_reply.has_value())
        j["allow_sending_without_reply"] = o.allow_sending_without_reply.value();
    if (o.quote.has_value())
        j["quote"] = o.quote.value();
    if (o.quote_parse_mode.has_value())
        j["quote_parse_mode"] = o.quote_parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.quote_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["quote_entities"] = std::move(_arr);
    }
    if (o.quote_position.has_value())
        j["quote_position"] = o.quote_position.value();
    if (o.checklist_task_id.has_value())
        j["checklist_task_id"] = o.checklist_task_id.value();
    if (o.poll_option_id.has_value())
        j["poll_option_id"] = o.poll_option_id.value();
}

inline void from_json(const json& j, MessageOrigin& v) {
    std::string type = j.at("type").get<std::string>();
    if (type == "user") {
        auto obj = std::make_shared<MessageOriginUser>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "hidden_user") {
        auto obj = std::make_shared<MessageOriginHiddenUser>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "chat") {
        auto obj = std::make_shared<MessageOriginChat>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "channel") {
        auto obj = std::make_shared<MessageOriginChannel>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const MessageOrigin& v) {
    if (auto* p = std::get_if <std::shared_ptr<MessageOriginUser>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<MessageOriginHiddenUser>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<MessageOriginChat>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<MessageOriginChannel>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, MessageOriginUser& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.date = j.contains("date") && !j.at("date").is_null()
        ? j.at("date").get<int64_t>() : 0;
    if (j.contains("sender_user") && !j.at("sender_user").is_null()) {
        o.sender_user = std::make_shared<User>();
        from_json(j.at("sender_user"), *o.sender_user);
    }
}

inline void to_json(json& j, const MessageOriginUser& o) {
    j = json::object();
    j["type"] = o.type;
    j["date"] = o.date;
    {
        json _sub; to_json(_sub, *o.sender_user); j["sender_user"] = std::move(_sub);
    }
}

inline void from_json(const json& j, MessageOriginHiddenUser& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.date = j.contains("date") && !j.at("date").is_null()
        ? j.at("date").get<int64_t>() : 0;
    o.sender_user_name = j.contains("sender_user_name") && !j.at("sender_user_name").is_null()
        ? j.at("sender_user_name").get<std::string>() : "";
}

inline void to_json(json& j, const MessageOriginHiddenUser& o) {
    j = json::object();
    j["type"] = o.type;
    j["date"] = o.date;
    j["sender_user_name"] = o.sender_user_name;
}

inline void from_json(const json& j, MessageOriginChat& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.date = j.contains("date") && !j.at("date").is_null()
        ? j.at("date").get<int64_t>() : 0;
    if (j.contains("sender_chat") && !j.at("sender_chat").is_null()) {
        o.sender_chat = std::make_shared<Chat>();
        from_json(j.at("sender_chat"), *o.sender_chat);
    }
    if (j.contains("author_signature") && !j.at("author_signature").is_null())
        o.author_signature = j.at("author_signature").get<std::string>();
}

inline void to_json(json& j, const MessageOriginChat& o) {
    j = json::object();
    j["type"] = o.type;
    j["date"] = o.date;
    {
        json _sub; to_json(_sub, *o.sender_chat); j["sender_chat"] = std::move(_sub);
    }
    if (o.author_signature.has_value())
        j["author_signature"] = o.author_signature.value();
}

inline void from_json(const json& j, MessageOriginChannel& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.date = j.contains("date") && !j.at("date").is_null()
        ? j.at("date").get<int64_t>() : 0;
    if (j.contains("chat") && !j.at("chat").is_null()) {
        o.chat = std::make_shared<Chat>();
        from_json(j.at("chat"), *o.chat);
    }
    o.message_id = j.contains("message_id") && !j.at("message_id").is_null()
        ? j.at("message_id").get<int64_t>() : 0;
    if (j.contains("author_signature") && !j.at("author_signature").is_null())
        o.author_signature = j.at("author_signature").get<std::string>();
}

inline void to_json(json& j, const MessageOriginChannel& o) {
    j = json::object();
    j["type"] = o.type;
    j["date"] = o.date;
    {
        json _sub; to_json(_sub, *o.chat); j["chat"] = std::move(_sub);
    }
    j["message_id"] = o.message_id;
    if (o.author_signature.has_value())
        j["author_signature"] = o.author_signature.value();
}

inline void from_json(const json& j, PhotoSize& o) {
    o.file_id = j.contains("file_id") && !j.at("file_id").is_null()
        ? j.at("file_id").get<std::string>() : "";
    o.file_unique_id = j.contains("file_unique_id") && !j.at("file_unique_id").is_null()
        ? j.at("file_unique_id").get<std::string>() : "";
    o.width = j.contains("width") && !j.at("width").is_null()
        ? j.at("width").get<int64_t>() : 0;
    o.height = j.contains("height") && !j.at("height").is_null()
        ? j.at("height").get<int64_t>() : 0;
    if (j.contains("file_size") && !j.at("file_size").is_null())
        o.file_size = j.at("file_size").get<int64_t>();
}

inline void to_json(json& j, const PhotoSize& o) {
    j = json::object();
    j["file_id"] = o.file_id;
    j["file_unique_id"] = o.file_unique_id;
    j["width"] = o.width;
    j["height"] = o.height;
    if (o.file_size.has_value())
        j["file_size"] = o.file_size.value();
}

inline void from_json(const json& j, Animation& o) {
    o.file_id = j.contains("file_id") && !j.at("file_id").is_null()
        ? j.at("file_id").get<std::string>() : "";
    o.file_unique_id = j.contains("file_unique_id") && !j.at("file_unique_id").is_null()
        ? j.at("file_unique_id").get<std::string>() : "";
    o.width = j.contains("width") && !j.at("width").is_null()
        ? j.at("width").get<int64_t>() : 0;
    o.height = j.contains("height") && !j.at("height").is_null()
        ? j.at("height").get<int64_t>() : 0;
    o.duration = j.contains("duration") && !j.at("duration").is_null()
        ? j.at("duration").get<int64_t>() : 0;
    if (j.contains("thumbnail") && !j.at("thumbnail").is_null()) {
        o.thumbnail = std::make_shared<PhotoSize>();
        from_json(j.at("thumbnail"), *o.thumbnail);
    }
    if (j.contains("file_name") && !j.at("file_name").is_null())
        o.file_name = j.at("file_name").get<std::string>();
    if (j.contains("mime_type") && !j.at("mime_type").is_null())
        o.mime_type = j.at("mime_type").get<std::string>();
    if (j.contains("file_size") && !j.at("file_size").is_null())
        o.file_size = j.at("file_size").get<int64_t>();
}

inline void to_json(json& j, const Animation& o) {
    j = json::object();
    j["file_id"] = o.file_id;
    j["file_unique_id"] = o.file_unique_id;
    j["width"] = o.width;
    j["height"] = o.height;
    j["duration"] = o.duration;
    if (o.thumbnail) {
        json _sub; to_json(_sub, *o.thumbnail); j["thumbnail"] = std::move(_sub);
    }
    if (o.file_name.has_value())
        j["file_name"] = o.file_name.value();
    if (o.mime_type.has_value())
        j["mime_type"] = o.mime_type.value();
    if (o.file_size.has_value())
        j["file_size"] = o.file_size.value();
}

inline void from_json(const json& j, Audio& o) {
    o.file_id = j.contains("file_id") && !j.at("file_id").is_null()
        ? j.at("file_id").get<std::string>() : "";
    o.file_unique_id = j.contains("file_unique_id") && !j.at("file_unique_id").is_null()
        ? j.at("file_unique_id").get<std::string>() : "";
    o.duration = j.contains("duration") && !j.at("duration").is_null()
        ? j.at("duration").get<int64_t>() : 0;
    if (j.contains("performer") && !j.at("performer").is_null())
        o.performer = j.at("performer").get<std::string>();
    if (j.contains("title") && !j.at("title").is_null())
        o.title = j.at("title").get<std::string>();
    if (j.contains("file_name") && !j.at("file_name").is_null())
        o.file_name = j.at("file_name").get<std::string>();
    if (j.contains("mime_type") && !j.at("mime_type").is_null())
        o.mime_type = j.at("mime_type").get<std::string>();
    if (j.contains("file_size") && !j.at("file_size").is_null())
        o.file_size = j.at("file_size").get<int64_t>();
    if (j.contains("thumbnail") && !j.at("thumbnail").is_null()) {
        o.thumbnail = std::make_shared<PhotoSize>();
        from_json(j.at("thumbnail"), *o.thumbnail);
    }
}

inline void to_json(json& j, const Audio& o) {
    j = json::object();
    j["file_id"] = o.file_id;
    j["file_unique_id"] = o.file_unique_id;
    j["duration"] = o.duration;
    if (o.performer.has_value())
        j["performer"] = o.performer.value();
    if (o.title.has_value())
        j["title"] = o.title.value();
    if (o.file_name.has_value())
        j["file_name"] = o.file_name.value();
    if (o.mime_type.has_value())
        j["mime_type"] = o.mime_type.value();
    if (o.file_size.has_value())
        j["file_size"] = o.file_size.value();
    if (o.thumbnail) {
        json _sub; to_json(_sub, *o.thumbnail); j["thumbnail"] = std::move(_sub);
    }
}

inline void from_json(const json& j, Document& o) {
    o.file_id = j.contains("file_id") && !j.at("file_id").is_null()
        ? j.at("file_id").get<std::string>() : "";
    o.file_unique_id = j.contains("file_unique_id") && !j.at("file_unique_id").is_null()
        ? j.at("file_unique_id").get<std::string>() : "";
    if (j.contains("thumbnail") && !j.at("thumbnail").is_null()) {
        o.thumbnail = std::make_shared<PhotoSize>();
        from_json(j.at("thumbnail"), *o.thumbnail);
    }
    if (j.contains("file_name") && !j.at("file_name").is_null())
        o.file_name = j.at("file_name").get<std::string>();
    if (j.contains("mime_type") && !j.at("mime_type").is_null())
        o.mime_type = j.at("mime_type").get<std::string>();
    if (j.contains("file_size") && !j.at("file_size").is_null())
        o.file_size = j.at("file_size").get<int64_t>();
}

inline void to_json(json& j, const Document& o) {
    j = json::object();
    j["file_id"] = o.file_id;
    j["file_unique_id"] = o.file_unique_id;
    if (o.thumbnail) {
        json _sub; to_json(_sub, *o.thumbnail); j["thumbnail"] = std::move(_sub);
    }
    if (o.file_name.has_value())
        j["file_name"] = o.file_name.value();
    if (o.mime_type.has_value())
        j["mime_type"] = o.mime_type.value();
    if (o.file_size.has_value())
        j["file_size"] = o.file_size.value();
}

inline void from_json(const json& j, LivePhoto& o) {
    if (j.contains("photo") && j.at("photo").is_array()) {
        for (const auto& _item : j.at("photo")) {
            {
                auto _elem = std::make_shared<PhotoSize>();
                from_json(_item, *_elem);
                o.photo.push_back(std::move(_elem));
            }
        }
    }
    o.file_id = j.contains("file_id") && !j.at("file_id").is_null()
        ? j.at("file_id").get<std::string>() : "";
    o.file_unique_id = j.contains("file_unique_id") && !j.at("file_unique_id").is_null()
        ? j.at("file_unique_id").get<std::string>() : "";
    o.width = j.contains("width") && !j.at("width").is_null()
        ? j.at("width").get<int64_t>() : 0;
    o.height = j.contains("height") && !j.at("height").is_null()
        ? j.at("height").get<int64_t>() : 0;
    o.duration = j.contains("duration") && !j.at("duration").is_null()
        ? j.at("duration").get<int64_t>() : 0;
    if (j.contains("mime_type") && !j.at("mime_type").is_null())
        o.mime_type = j.at("mime_type").get<std::string>();
    if (j.contains("file_size") && !j.at("file_size").is_null())
        o.file_size = j.at("file_size").get<int64_t>();
}

inline void to_json(json& j, const LivePhoto& o) {
    j = json::object();
    {
        json _arr = json::array();
        for (const auto& _item : o.photo) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["photo"] = std::move(_arr);
    }
    j["file_id"] = o.file_id;
    j["file_unique_id"] = o.file_unique_id;
    j["width"] = o.width;
    j["height"] = o.height;
    j["duration"] = o.duration;
    if (o.mime_type.has_value())
        j["mime_type"] = o.mime_type.value();
    if (o.file_size.has_value())
        j["file_size"] = o.file_size.value();
}

inline void from_json(const json& j, Story& o) {
    if (j.contains("chat") && !j.at("chat").is_null()) {
        o.chat = std::make_shared<Chat>();
        from_json(j.at("chat"), *o.chat);
    }
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<int64_t>() : 0;
}

inline void to_json(json& j, const Story& o) {
    j = json::object();
    {
        json _sub; to_json(_sub, *o.chat); j["chat"] = std::move(_sub);
    }
    j["id"] = o.id;
}

inline void from_json(const json& j, VideoQuality& o) {
    o.file_id = j.contains("file_id") && !j.at("file_id").is_null()
        ? j.at("file_id").get<std::string>() : "";
    o.file_unique_id = j.contains("file_unique_id") && !j.at("file_unique_id").is_null()
        ? j.at("file_unique_id").get<std::string>() : "";
    o.width = j.contains("width") && !j.at("width").is_null()
        ? j.at("width").get<int64_t>() : 0;
    o.height = j.contains("height") && !j.at("height").is_null()
        ? j.at("height").get<int64_t>() : 0;
    o.codec = j.contains("codec") && !j.at("codec").is_null()
        ? j.at("codec").get<std::string>() : "";
    if (j.contains("file_size") && !j.at("file_size").is_null())
        o.file_size = j.at("file_size").get<int64_t>();
}

inline void to_json(json& j, const VideoQuality& o) {
    j = json::object();
    j["file_id"] = o.file_id;
    j["file_unique_id"] = o.file_unique_id;
    j["width"] = o.width;
    j["height"] = o.height;
    j["codec"] = o.codec;
    if (o.file_size.has_value())
        j["file_size"] = o.file_size.value();
}

inline void from_json(const json& j, Video& o) {
    o.file_id = j.contains("file_id") && !j.at("file_id").is_null()
        ? j.at("file_id").get<std::string>() : "";
    o.file_unique_id = j.contains("file_unique_id") && !j.at("file_unique_id").is_null()
        ? j.at("file_unique_id").get<std::string>() : "";
    o.width = j.contains("width") && !j.at("width").is_null()
        ? j.at("width").get<int64_t>() : 0;
    o.height = j.contains("height") && !j.at("height").is_null()
        ? j.at("height").get<int64_t>() : 0;
    o.duration = j.contains("duration") && !j.at("duration").is_null()
        ? j.at("duration").get<int64_t>() : 0;
    if (j.contains("thumbnail") && !j.at("thumbnail").is_null()) {
        o.thumbnail = std::make_shared<PhotoSize>();
        from_json(j.at("thumbnail"), *o.thumbnail);
    }
    if (j.contains("cover") && j.at("cover").is_array()) {
        for (const auto& _item : j.at("cover")) {
            {
                auto _elem = std::make_shared<PhotoSize>();
                from_json(_item, *_elem);
                o.cover.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("start_timestamp") && !j.at("start_timestamp").is_null())
        o.start_timestamp = j.at("start_timestamp").get<int64_t>();
    if (j.contains("qualities") && j.at("qualities").is_array()) {
        for (const auto& _item : j.at("qualities")) {
            {
                auto _elem = std::make_shared<VideoQuality>();
                from_json(_item, *_elem);
                o.qualities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("file_name") && !j.at("file_name").is_null())
        o.file_name = j.at("file_name").get<std::string>();
    if (j.contains("mime_type") && !j.at("mime_type").is_null())
        o.mime_type = j.at("mime_type").get<std::string>();
    if (j.contains("file_size") && !j.at("file_size").is_null())
        o.file_size = j.at("file_size").get<int64_t>();
}

inline void to_json(json& j, const Video& o) {
    j = json::object();
    j["file_id"] = o.file_id;
    j["file_unique_id"] = o.file_unique_id;
    j["width"] = o.width;
    j["height"] = o.height;
    j["duration"] = o.duration;
    if (o.thumbnail) {
        json _sub; to_json(_sub, *o.thumbnail); j["thumbnail"] = std::move(_sub);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.cover) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["cover"] = std::move(_arr);
    }
    if (o.start_timestamp.has_value())
        j["start_timestamp"] = o.start_timestamp.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.qualities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["qualities"] = std::move(_arr);
    }
    if (o.file_name.has_value())
        j["file_name"] = o.file_name.value();
    if (o.mime_type.has_value())
        j["mime_type"] = o.mime_type.value();
    if (o.file_size.has_value())
        j["file_size"] = o.file_size.value();
}

inline void from_json(const json& j, VideoNote& o) {
    o.file_id = j.contains("file_id") && !j.at("file_id").is_null()
        ? j.at("file_id").get<std::string>() : "";
    o.file_unique_id = j.contains("file_unique_id") && !j.at("file_unique_id").is_null()
        ? j.at("file_unique_id").get<std::string>() : "";
    o.length = j.contains("length") && !j.at("length").is_null()
        ? j.at("length").get<int64_t>() : 0;
    o.duration = j.contains("duration") && !j.at("duration").is_null()
        ? j.at("duration").get<int64_t>() : 0;
    if (j.contains("thumbnail") && !j.at("thumbnail").is_null()) {
        o.thumbnail = std::make_shared<PhotoSize>();
        from_json(j.at("thumbnail"), *o.thumbnail);
    }
    if (j.contains("file_size") && !j.at("file_size").is_null())
        o.file_size = j.at("file_size").get<int64_t>();
}

inline void to_json(json& j, const VideoNote& o) {
    j = json::object();
    j["file_id"] = o.file_id;
    j["file_unique_id"] = o.file_unique_id;
    j["length"] = o.length;
    j["duration"] = o.duration;
    if (o.thumbnail) {
        json _sub; to_json(_sub, *o.thumbnail); j["thumbnail"] = std::move(_sub);
    }
    if (o.file_size.has_value())
        j["file_size"] = o.file_size.value();
}

inline void from_json(const json& j, Voice& o) {
    o.file_id = j.contains("file_id") && !j.at("file_id").is_null()
        ? j.at("file_id").get<std::string>() : "";
    o.file_unique_id = j.contains("file_unique_id") && !j.at("file_unique_id").is_null()
        ? j.at("file_unique_id").get<std::string>() : "";
    o.duration = j.contains("duration") && !j.at("duration").is_null()
        ? j.at("duration").get<int64_t>() : 0;
    if (j.contains("mime_type") && !j.at("mime_type").is_null())
        o.mime_type = j.at("mime_type").get<std::string>();
    if (j.contains("file_size") && !j.at("file_size").is_null())
        o.file_size = j.at("file_size").get<int64_t>();
}

inline void to_json(json& j, const Voice& o) {
    j = json::object();
    j["file_id"] = o.file_id;
    j["file_unique_id"] = o.file_unique_id;
    j["duration"] = o.duration;
    if (o.mime_type.has_value())
        j["mime_type"] = o.mime_type.value();
    if (o.file_size.has_value())
        j["file_size"] = o.file_size.value();
}

inline void from_json(const json& j, PaidMediaInfo& o) {
    o.star_count = j.contains("star_count") && !j.at("star_count").is_null()
        ? j.at("star_count").get<int64_t>() : 0;
    if (j.contains("paid_media") && j.at("paid_media").is_array()) {
        for (const auto& _item : j.at("paid_media")) {
            {
                PaidMedia _elem{};
                from_json(_item, _elem);
                o.paid_media.push_back(std::move(_elem));
            }
        }
    }
}

inline void to_json(json& j, const PaidMediaInfo& o) {
    j = json::object();
    j["star_count"] = o.star_count;
    {
        json _arr = json::array();
        for (const auto& _item : o.paid_media) {
            {
                json _e; to_json(_e, _item); _arr.push_back(std::move(_e));
            }
        }
        j["paid_media"] = std::move(_arr);
    }
}

inline void from_json(const json& j, PaidMedia& v) {
    std::string type = j.at("type").get<std::string>();
    if (type == "live_photo") {
        auto obj = std::make_shared<PaidMediaLivePhoto>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "photo") {
        auto obj = std::make_shared<PaidMediaPhoto>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "preview") {
        auto obj = std::make_shared<PaidMediaPreview>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "video") {
        auto obj = std::make_shared<PaidMediaVideo>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const PaidMedia& v) {
    if (auto* p = std::get_if <std::shared_ptr<PaidMediaLivePhoto>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<PaidMediaPhoto>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<PaidMediaPreview>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<PaidMediaVideo>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, PaidMediaLivePhoto& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("live_photo") && !j.at("live_photo").is_null()) {
        o.live_photo = std::make_shared<LivePhoto>();
        from_json(j.at("live_photo"), *o.live_photo);
    }
}

inline void to_json(json& j, const PaidMediaLivePhoto& o) {
    j = json::object();
    j["type"] = o.type;
    {
        json _sub; to_json(_sub, *o.live_photo); j["live_photo"] = std::move(_sub);
    }
}

inline void from_json(const json& j, PaidMediaPhoto& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("photo") && j.at("photo").is_array()) {
        for (const auto& _item : j.at("photo")) {
            {
                auto _elem = std::make_shared<PhotoSize>();
                from_json(_item, *_elem);
                o.photo.push_back(std::move(_elem));
            }
        }
    }
}

inline void to_json(json& j, const PaidMediaPhoto& o) {
    j = json::object();
    j["type"] = o.type;
    {
        json _arr = json::array();
        for (const auto& _item : o.photo) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["photo"] = std::move(_arr);
    }
}

inline void from_json(const json& j, PaidMediaPreview& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("width") && !j.at("width").is_null())
        o.width = j.at("width").get<int64_t>();
    if (j.contains("height") && !j.at("height").is_null())
        o.height = j.at("height").get<int64_t>();
    if (j.contains("duration") && !j.at("duration").is_null())
        o.duration = j.at("duration").get<int64_t>();
}

inline void to_json(json& j, const PaidMediaPreview& o) {
    j = json::object();
    j["type"] = o.type;
    if (o.width.has_value())
        j["width"] = o.width.value();
    if (o.height.has_value())
        j["height"] = o.height.value();
    if (o.duration.has_value())
        j["duration"] = o.duration.value();
}

inline void from_json(const json& j, PaidMediaVideo& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("video") && !j.at("video").is_null()) {
        o.video = std::make_shared<Video>();
        from_json(j.at("video"), *o.video);
    }
}

inline void to_json(json& j, const PaidMediaVideo& o) {
    j = json::object();
    j["type"] = o.type;
    {
        json _sub; to_json(_sub, *o.video); j["video"] = std::move(_sub);
    }
}

inline void from_json(const json& j, Contact& o) {
    o.phone_number = j.contains("phone_number") && !j.at("phone_number").is_null()
        ? j.at("phone_number").get<std::string>() : "";
    o.first_name = j.contains("first_name") && !j.at("first_name").is_null()
        ? j.at("first_name").get<std::string>() : "";
    if (j.contains("last_name") && !j.at("last_name").is_null())
        o.last_name = j.at("last_name").get<std::string>();
    if (j.contains("user_id") && !j.at("user_id").is_null())
        o.user_id = j.at("user_id").get<int64_t>();
    if (j.contains("vcard") && !j.at("vcard").is_null())
        o.vcard = j.at("vcard").get<std::string>();
}

inline void to_json(json& j, const Contact& o) {
    j = json::object();
    j["phone_number"] = o.phone_number;
    j["first_name"] = o.first_name;
    if (o.last_name.has_value())
        j["last_name"] = o.last_name.value();
    if (o.user_id.has_value())
        j["user_id"] = o.user_id.value();
    if (o.vcard.has_value())
        j["vcard"] = o.vcard.value();
}

inline void from_json(const json& j, Dice& o) {
    o.emoji = j.contains("emoji") && !j.at("emoji").is_null()
        ? j.at("emoji").get<std::string>() : "";
    o.value = j.contains("value") && !j.at("value").is_null()
        ? j.at("value").get<int64_t>() : 0;
}

inline void to_json(json& j, const Dice& o) {
    j = json::object();
    j["emoji"] = o.emoji;
    j["value"] = o.value;
}

inline void from_json(const json& j, PollMedia& o) {
    if (j.contains("animation") && !j.at("animation").is_null()) {
        o.animation = std::make_shared<Animation>();
        from_json(j.at("animation"), *o.animation);
    }
    if (j.contains("audio") && !j.at("audio").is_null()) {
        o.audio = std::make_shared<Audio>();
        from_json(j.at("audio"), *o.audio);
    }
    if (j.contains("document") && !j.at("document").is_null()) {
        o.document = std::make_shared<Document>();
        from_json(j.at("document"), *o.document);
    }
    if (j.contains("live_photo") && !j.at("live_photo").is_null()) {
        o.live_photo = std::make_shared<LivePhoto>();
        from_json(j.at("live_photo"), *o.live_photo);
    }
    if (j.contains("location") && !j.at("location").is_null()) {
        o.location = std::make_shared<Location>();
        from_json(j.at("location"), *o.location);
    }
    if (j.contains("photo") && j.at("photo").is_array()) {
        for (const auto& _item : j.at("photo")) {
            {
                auto _elem = std::make_shared<PhotoSize>();
                from_json(_item, *_elem);
                o.photo.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("sticker") && !j.at("sticker").is_null()) {
        o.sticker = std::make_shared<Sticker>();
        from_json(j.at("sticker"), *o.sticker);
    }
    if (j.contains("venue") && !j.at("venue").is_null()) {
        o.venue = std::make_shared<Venue>();
        from_json(j.at("venue"), *o.venue);
    }
    if (j.contains("video") && !j.at("video").is_null()) {
        o.video = std::make_shared<Video>();
        from_json(j.at("video"), *o.video);
    }
}

inline void to_json(json& j, const PollMedia& o) {
    j = json::object();
    if (o.animation) {
        json _sub; to_json(_sub, *o.animation); j["animation"] = std::move(_sub);
    }
    if (o.audio) {
        json _sub; to_json(_sub, *o.audio); j["audio"] = std::move(_sub);
    }
    if (o.document) {
        json _sub; to_json(_sub, *o.document); j["document"] = std::move(_sub);
    }
    if (o.live_photo) {
        json _sub; to_json(_sub, *o.live_photo); j["live_photo"] = std::move(_sub);
    }
    if (o.location) {
        json _sub; to_json(_sub, *o.location); j["location"] = std::move(_sub);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.photo) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["photo"] = std::move(_arr);
    }
    if (o.sticker) {
        json _sub; to_json(_sub, *o.sticker); j["sticker"] = std::move(_sub);
    }
    if (o.venue) {
        json _sub; to_json(_sub, *o.venue); j["venue"] = std::move(_sub);
    }
    if (o.video) {
        json _sub; to_json(_sub, *o.video); j["video"] = std::move(_sub);
    }
}

inline void from_json(const json& j, InputPollMedia& v) {
    std::string type = j.at("type").get<std::string>();
    if (type == "animation") {
        auto obj = std::make_shared<InputMediaAnimation>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "audio") {
        auto obj = std::make_shared<InputMediaAudio>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "document") {
        auto obj = std::make_shared<InputMediaDocument>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "live_photo") {
        auto obj = std::make_shared<InputMediaLivePhoto>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "location") {
        auto obj = std::make_shared<InputMediaLocation>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "photo") {
        auto obj = std::make_shared<InputMediaPhoto>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "venue") {
        auto obj = std::make_shared<InputMediaVenue>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "video") {
        auto obj = std::make_shared<InputMediaVideo>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const InputPollMedia& v) {
    if (auto* p = std::get_if <std::shared_ptr<InputMediaAnimation>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputMediaAudio>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputMediaDocument>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputMediaLivePhoto>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputMediaLocation>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputMediaPhoto>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputMediaVenue>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputMediaVideo>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, InputPollOptionMedia& v) {
    std::string type = j.at("type").get<std::string>();
    if (type == "animation") {
        auto obj = std::make_shared<InputMediaAnimation>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "live_photo") {
        auto obj = std::make_shared<InputMediaLivePhoto>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "location") {
        auto obj = std::make_shared<InputMediaLocation>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "photo") {
        auto obj = std::make_shared<InputMediaPhoto>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "sticker") {
        auto obj = std::make_shared<InputMediaSticker>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "venue") {
        auto obj = std::make_shared<InputMediaVenue>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "video") {
        auto obj = std::make_shared<InputMediaVideo>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const InputPollOptionMedia& v) {
    if (auto* p = std::get_if <std::shared_ptr<InputMediaAnimation>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputMediaLivePhoto>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputMediaLocation>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputMediaPhoto>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputMediaSticker>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputMediaVenue>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputMediaVideo>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, PollOption& o) {
    o.persistent_id = j.contains("persistent_id") && !j.at("persistent_id").is_null()
        ? j.at("persistent_id").get<std::string>() : "";
    o.text = j.contains("text") && !j.at("text").is_null()
        ? j.at("text").get<std::string>() : "";
    if (j.contains("text_entities") && j.at("text_entities").is_array()) {
        for (const auto& _item : j.at("text_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.text_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("media") && !j.at("media").is_null()) {
        o.media = std::make_shared<PollMedia>();
        from_json(j.at("media"), *o.media);
    }
    o.voter_count = j.contains("voter_count") && !j.at("voter_count").is_null()
        ? j.at("voter_count").get<int64_t>() : 0;
    if (j.contains("added_by_user") && !j.at("added_by_user").is_null()) {
        o.added_by_user = std::make_shared<User>();
        from_json(j.at("added_by_user"), *o.added_by_user);
    }
    if (j.contains("added_by_chat") && !j.at("added_by_chat").is_null()) {
        o.added_by_chat = std::make_shared<Chat>();
        from_json(j.at("added_by_chat"), *o.added_by_chat);
    }
    if (j.contains("addition_date") && !j.at("addition_date").is_null())
        o.addition_date = j.at("addition_date").get<int64_t>();
}

inline void to_json(json& j, const PollOption& o) {
    j = json::object();
    j["persistent_id"] = o.persistent_id;
    j["text"] = o.text;
    {
        json _arr = json::array();
        for (const auto& _item : o.text_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["text_entities"] = std::move(_arr);
    }
    if (o.media) {
        json _sub; to_json(_sub, *o.media); j["media"] = std::move(_sub);
    }
    j["voter_count"] = o.voter_count;
    if (o.added_by_user) {
        json _sub; to_json(_sub, *o.added_by_user); j["added_by_user"] = std::move(_sub);
    }
    if (o.added_by_chat) {
        json _sub; to_json(_sub, *o.added_by_chat); j["added_by_chat"] = std::move(_sub);
    }
    if (o.addition_date.has_value())
        j["addition_date"] = o.addition_date.value();
}

inline void from_json(const json& j, InputPollOption& o) {
    o.text = j.contains("text") && !j.at("text").is_null()
        ? j.at("text").get<std::string>() : "";
    if (j.contains("text_parse_mode") && !j.at("text_parse_mode").is_null())
        o.text_parse_mode = j.at("text_parse_mode").get<std::string>();
    if (j.contains("text_entities") && j.at("text_entities").is_array()) {
        for (const auto& _item : j.at("text_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.text_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("media") && !j.at("media").is_null()) {
        InputPollOptionMedia _tmp{};
        from_json(j.at("media"), _tmp);
        o.media = std::move(_tmp);
    }
}

inline void to_json(json& j, const InputPollOption& o) {
    j = json::object();
    j["text"] = o.text;
    if (o.text_parse_mode.has_value())
        j["text_parse_mode"] = o.text_parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.text_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["text_entities"] = std::move(_arr);
    }
    if (o.media.has_value()) {
        json _sub;
        to_json(_sub, o.media.value());
        j["media"] = std::move(_sub);
    }
}

inline void from_json(const json& j, PollAnswer& o) {
    o.poll_id = j.contains("poll_id") && !j.at("poll_id").is_null()
        ? j.at("poll_id").get<std::string>() : "";
    if (j.contains("voter_chat") && !j.at("voter_chat").is_null()) {
        o.voter_chat = std::make_shared<Chat>();
        from_json(j.at("voter_chat"), *o.voter_chat);
    }
    if (j.contains("user") && !j.at("user").is_null()) {
        o.user = std::make_shared<User>();
        from_json(j.at("user"), *o.user);
    }
    if (j.contains("option_ids") && j.at("option_ids").is_array()) {
        for (const auto& _item : j.at("option_ids")) {
            o.option_ids.push_back(_item.get<int64_t>());
        }
    }
    if (j.contains("option_persistent_ids") && j.at("option_persistent_ids").is_array()) {
        for (const auto& _item : j.at("option_persistent_ids")) {
            o.option_persistent_ids.push_back(_item.get<std::string>());
        }
    }
}

inline void to_json(json& j, const PollAnswer& o) {
    j = json::object();
    j["poll_id"] = o.poll_id;
    if (o.voter_chat) {
        json _sub; to_json(_sub, *o.voter_chat); j["voter_chat"] = std::move(_sub);
    }
    if (o.user) {
        json _sub; to_json(_sub, *o.user); j["user"] = std::move(_sub);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.option_ids) {
            _arr.push_back(_item);
        }
        j["option_ids"] = std::move(_arr);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.option_persistent_ids) {
            _arr.push_back(_item);
        }
        j["option_persistent_ids"] = std::move(_arr);
    }
}

inline void from_json(const json& j, Poll& o) {
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.question = j.contains("question") && !j.at("question").is_null()
        ? j.at("question").get<std::string>() : "";
    if (j.contains("question_entities") && j.at("question_entities").is_array()) {
        for (const auto& _item : j.at("question_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.question_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("options") && j.at("options").is_array()) {
        for (const auto& _item : j.at("options")) {
            {
                auto _elem = std::make_shared<PollOption>();
                from_json(_item, *_elem);
                o.options.push_back(std::move(_elem));
            }
        }
    }
    o.total_voter_count = j.contains("total_voter_count") && !j.at("total_voter_count").is_null()
        ? j.at("total_voter_count").get<int64_t>() : 0;
    o.is_closed = j.contains("is_closed") && !j.at("is_closed").is_null()
        ? j.at("is_closed").get<bool>() : false;
    o.is_anonymous = j.contains("is_anonymous") && !j.at("is_anonymous").is_null()
        ? j.at("is_anonymous").get<bool>() : false;
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.allows_multiple_answers = j.contains("allows_multiple_answers") && !j.at("allows_multiple_answers").is_null()
        ? j.at("allows_multiple_answers").get<bool>() : false;
    o.allows_revoting = j.contains("allows_revoting") && !j.at("allows_revoting").is_null()
        ? j.at("allows_revoting").get<bool>() : false;
    o.members_only = j.contains("members_only") && !j.at("members_only").is_null()
        ? j.at("members_only").get<bool>() : false;
    if (j.contains("country_codes") && j.at("country_codes").is_array()) {
        for (const auto& _item : j.at("country_codes")) {
            o.country_codes.push_back(_item.get<std::string>());
        }
    }
    if (j.contains("correct_option_ids") && j.at("correct_option_ids").is_array()) {
        for (const auto& _item : j.at("correct_option_ids")) {
            o.correct_option_ids.push_back(_item.get<int64_t>());
        }
    }
    if (j.contains("explanation") && !j.at("explanation").is_null())
        o.explanation = j.at("explanation").get<std::string>();
    if (j.contains("explanation_entities") && j.at("explanation_entities").is_array()) {
        for (const auto& _item : j.at("explanation_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.explanation_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("explanation_media") && !j.at("explanation_media").is_null()) {
        o.explanation_media = std::make_shared<PollMedia>();
        from_json(j.at("explanation_media"), *o.explanation_media);
    }
    if (j.contains("open_period") && !j.at("open_period").is_null())
        o.open_period = j.at("open_period").get<int64_t>();
    if (j.contains("close_date") && !j.at("close_date").is_null())
        o.close_date = j.at("close_date").get<int64_t>();
    if (j.contains("description") && !j.at("description").is_null())
        o.description = j.at("description").get<std::string>();
    if (j.contains("description_entities") && j.at("description_entities").is_array()) {
        for (const auto& _item : j.at("description_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.description_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("media") && !j.at("media").is_null()) {
        o.media = std::make_shared<PollMedia>();
        from_json(j.at("media"), *o.media);
    }
}

inline void to_json(json& j, const Poll& o) {
    j = json::object();
    j["id"] = o.id;
    j["question"] = o.question;
    {
        json _arr = json::array();
        for (const auto& _item : o.question_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["question_entities"] = std::move(_arr);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.options) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["options"] = std::move(_arr);
    }
    j["total_voter_count"] = o.total_voter_count;
    j["is_closed"] = o.is_closed;
    j["is_anonymous"] = o.is_anonymous;
    j["type"] = o.type;
    j["allows_multiple_answers"] = o.allows_multiple_answers;
    j["allows_revoting"] = o.allows_revoting;
    j["members_only"] = o.members_only;
    {
        json _arr = json::array();
        for (const auto& _item : o.country_codes) {
            _arr.push_back(_item);
        }
        j["country_codes"] = std::move(_arr);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.correct_option_ids) {
            _arr.push_back(_item);
        }
        j["correct_option_ids"] = std::move(_arr);
    }
    if (o.explanation.has_value())
        j["explanation"] = o.explanation.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.explanation_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["explanation_entities"] = std::move(_arr);
    }
    if (o.explanation_media) {
        json _sub; to_json(_sub, *o.explanation_media); j["explanation_media"] = std::move(_sub);
    }
    if (o.open_period.has_value())
        j["open_period"] = o.open_period.value();
    if (o.close_date.has_value())
        j["close_date"] = o.close_date.value();
    if (o.description.has_value())
        j["description"] = o.description.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.description_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["description_entities"] = std::move(_arr);
    }
    if (o.media) {
        json _sub; to_json(_sub, *o.media); j["media"] = std::move(_sub);
    }
}

inline void from_json(const json& j, ChecklistTask& o) {
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<int64_t>() : 0;
    o.text = j.contains("text") && !j.at("text").is_null()
        ? j.at("text").get<std::string>() : "";
    if (j.contains("text_entities") && j.at("text_entities").is_array()) {
        for (const auto& _item : j.at("text_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.text_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("completed_by_user") && !j.at("completed_by_user").is_null()) {
        o.completed_by_user = std::make_shared<User>();
        from_json(j.at("completed_by_user"), *o.completed_by_user);
    }
    if (j.contains("completed_by_chat") && !j.at("completed_by_chat").is_null()) {
        o.completed_by_chat = std::make_shared<Chat>();
        from_json(j.at("completed_by_chat"), *o.completed_by_chat);
    }
    if (j.contains("completion_date") && !j.at("completion_date").is_null())
        o.completion_date = j.at("completion_date").get<int64_t>();
}

inline void to_json(json& j, const ChecklistTask& o) {
    j = json::object();
    j["id"] = o.id;
    j["text"] = o.text;
    {
        json _arr = json::array();
        for (const auto& _item : o.text_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["text_entities"] = std::move(_arr);
    }
    if (o.completed_by_user) {
        json _sub; to_json(_sub, *o.completed_by_user); j["completed_by_user"] = std::move(_sub);
    }
    if (o.completed_by_chat) {
        json _sub; to_json(_sub, *o.completed_by_chat); j["completed_by_chat"] = std::move(_sub);
    }
    if (o.completion_date.has_value())
        j["completion_date"] = o.completion_date.value();
}

inline void from_json(const json& j, Checklist& o) {
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    if (j.contains("title_entities") && j.at("title_entities").is_array()) {
        for (const auto& _item : j.at("title_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.title_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("tasks") && j.at("tasks").is_array()) {
        for (const auto& _item : j.at("tasks")) {
            {
                auto _elem = std::make_shared<ChecklistTask>();
                from_json(_item, *_elem);
                o.tasks.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("others_can_add_tasks") && !j.at("others_can_add_tasks").is_null())
        o.others_can_add_tasks = j.at("others_can_add_tasks").get<bool>();
    if (j.contains("others_can_mark_tasks_as_done") && !j.at("others_can_mark_tasks_as_done").is_null())
        o.others_can_mark_tasks_as_done = j.at("others_can_mark_tasks_as_done").get<bool>();
}

inline void to_json(json& j, const Checklist& o) {
    j = json::object();
    j["title"] = o.title;
    {
        json _arr = json::array();
        for (const auto& _item : o.title_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["title_entities"] = std::move(_arr);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.tasks) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["tasks"] = std::move(_arr);
    }
    if (o.others_can_add_tasks.has_value())
        j["others_can_add_tasks"] = o.others_can_add_tasks.value();
    if (o.others_can_mark_tasks_as_done.has_value())
        j["others_can_mark_tasks_as_done"] = o.others_can_mark_tasks_as_done.value();
}

inline void from_json(const json& j, InputChecklistTask& o) {
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<int64_t>() : 0;
    o.text = j.contains("text") && !j.at("text").is_null()
        ? j.at("text").get<std::string>() : "";
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("text_entities") && j.at("text_entities").is_array()) {
        for (const auto& _item : j.at("text_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.text_entities.push_back(std::move(_elem));
            }
        }
    }
}

inline void to_json(json& j, const InputChecklistTask& o) {
    j = json::object();
    j["id"] = o.id;
    j["text"] = o.text;
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.text_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["text_entities"] = std::move(_arr);
    }
}

inline void from_json(const json& j, InputChecklist& o) {
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("title_entities") && j.at("title_entities").is_array()) {
        for (const auto& _item : j.at("title_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.title_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("tasks") && j.at("tasks").is_array()) {
        for (const auto& _item : j.at("tasks")) {
            {
                auto _elem = std::make_shared<InputChecklistTask>();
                from_json(_item, *_elem);
                o.tasks.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("others_can_add_tasks") && !j.at("others_can_add_tasks").is_null())
        o.others_can_add_tasks = j.at("others_can_add_tasks").get<bool>();
    if (j.contains("others_can_mark_tasks_as_done") && !j.at("others_can_mark_tasks_as_done").is_null())
        o.others_can_mark_tasks_as_done = j.at("others_can_mark_tasks_as_done").get<bool>();
}

inline void to_json(json& j, const InputChecklist& o) {
    j = json::object();
    j["title"] = o.title;
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.title_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["title_entities"] = std::move(_arr);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.tasks) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["tasks"] = std::move(_arr);
    }
    if (o.others_can_add_tasks.has_value())
        j["others_can_add_tasks"] = o.others_can_add_tasks.value();
    if (o.others_can_mark_tasks_as_done.has_value())
        j["others_can_mark_tasks_as_done"] = o.others_can_mark_tasks_as_done.value();
}

inline void from_json(const json& j, ChecklistTasksDone& o) {
    if (j.contains("checklist_message") && !j.at("checklist_message").is_null()) {
        o.checklist_message = std::make_shared<Message>();
        from_json(j.at("checklist_message"), *o.checklist_message);
    }
    if (j.contains("marked_as_done_task_ids") && j.at("marked_as_done_task_ids").is_array()) {
        for (const auto& _item : j.at("marked_as_done_task_ids")) {
            o.marked_as_done_task_ids.push_back(_item.get<int64_t>());
        }
    }
    if (j.contains("marked_as_not_done_task_ids") && j.at("marked_as_not_done_task_ids").is_array()) {
        for (const auto& _item : j.at("marked_as_not_done_task_ids")) {
            o.marked_as_not_done_task_ids.push_back(_item.get<int64_t>());
        }
    }
}

inline void to_json(json& j, const ChecklistTasksDone& o) {
    j = json::object();
    if (o.checklist_message) {
        json _sub; to_json(_sub, *o.checklist_message); j["checklist_message"] = std::move(_sub);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.marked_as_done_task_ids) {
            _arr.push_back(_item);
        }
        j["marked_as_done_task_ids"] = std::move(_arr);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.marked_as_not_done_task_ids) {
            _arr.push_back(_item);
        }
        j["marked_as_not_done_task_ids"] = std::move(_arr);
    }
}

inline void from_json(const json& j, ChecklistTasksAdded& o) {
    if (j.contains("checklist_message") && !j.at("checklist_message").is_null()) {
        o.checklist_message = std::make_shared<Message>();
        from_json(j.at("checklist_message"), *o.checklist_message);
    }
    if (j.contains("tasks") && j.at("tasks").is_array()) {
        for (const auto& _item : j.at("tasks")) {
            {
                auto _elem = std::make_shared<ChecklistTask>();
                from_json(_item, *_elem);
                o.tasks.push_back(std::move(_elem));
            }
        }
    }
}

inline void to_json(json& j, const ChecklistTasksAdded& o) {
    j = json::object();
    if (o.checklist_message) {
        json _sub; to_json(_sub, *o.checklist_message); j["checklist_message"] = std::move(_sub);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.tasks) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["tasks"] = std::move(_arr);
    }
}

inline void from_json(const json& j, Location& o) {
    o.latitude = j.contains("latitude") && !j.at("latitude").is_null()
        ? j.at("latitude").get<double>() : 0.0;
    o.longitude = j.contains("longitude") && !j.at("longitude").is_null()
        ? j.at("longitude").get<double>() : 0.0;
    if (j.contains("horizontal_accuracy") && !j.at("horizontal_accuracy").is_null())
        o.horizontal_accuracy = j.at("horizontal_accuracy").get<double>();
    if (j.contains("live_period") && !j.at("live_period").is_null())
        o.live_period = j.at("live_period").get<int64_t>();
    if (j.contains("heading") && !j.at("heading").is_null())
        o.heading = j.at("heading").get<int64_t>();
    if (j.contains("proximity_alert_radius") && !j.at("proximity_alert_radius").is_null())
        o.proximity_alert_radius = j.at("proximity_alert_radius").get<int64_t>();
}

inline void to_json(json& j, const Location& o) {
    j = json::object();
    j["latitude"] = o.latitude;
    j["longitude"] = o.longitude;
    if (o.horizontal_accuracy.has_value())
        j["horizontal_accuracy"] = o.horizontal_accuracy.value();
    if (o.live_period.has_value())
        j["live_period"] = o.live_period.value();
    if (o.heading.has_value())
        j["heading"] = o.heading.value();
    if (o.proximity_alert_radius.has_value())
        j["proximity_alert_radius"] = o.proximity_alert_radius.value();
}

inline void from_json(const json& j, Venue& o) {
    if (j.contains("location") && !j.at("location").is_null()) {
        o.location = std::make_shared<Location>();
        from_json(j.at("location"), *o.location);
    }
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    o.address = j.contains("address") && !j.at("address").is_null()
        ? j.at("address").get<std::string>() : "";
    if (j.contains("foursquare_id") && !j.at("foursquare_id").is_null())
        o.foursquare_id = j.at("foursquare_id").get<std::string>();
    if (j.contains("foursquare_type") && !j.at("foursquare_type").is_null())
        o.foursquare_type = j.at("foursquare_type").get<std::string>();
    if (j.contains("google_place_id") && !j.at("google_place_id").is_null())
        o.google_place_id = j.at("google_place_id").get<std::string>();
    if (j.contains("google_place_type") && !j.at("google_place_type").is_null())
        o.google_place_type = j.at("google_place_type").get<std::string>();
}

inline void to_json(json& j, const Venue& o) {
    j = json::object();
    {
        json _sub; to_json(_sub, *o.location); j["location"] = std::move(_sub);
    }
    j["title"] = o.title;
    j["address"] = o.address;
    if (o.foursquare_id.has_value())
        j["foursquare_id"] = o.foursquare_id.value();
    if (o.foursquare_type.has_value())
        j["foursquare_type"] = o.foursquare_type.value();
    if (o.google_place_id.has_value())
        j["google_place_id"] = o.google_place_id.value();
    if (o.google_place_type.has_value())
        j["google_place_type"] = o.google_place_type.value();
}

inline void from_json(const json& j, WebAppData& o) {
    o.data = j.contains("data") && !j.at("data").is_null()
        ? j.at("data").get<std::string>() : "";
    o.button_text = j.contains("button_text") && !j.at("button_text").is_null()
        ? j.at("button_text").get<std::string>() : "";
}

inline void to_json(json& j, const WebAppData& o) {
    j = json::object();
    j["data"] = o.data;
    j["button_text"] = o.button_text;
}

inline void from_json(const json& j, ProximityAlertTriggered& o) {
    if (j.contains("traveler") && !j.at("traveler").is_null()) {
        o.traveler = std::make_shared<User>();
        from_json(j.at("traveler"), *o.traveler);
    }
    if (j.contains("watcher") && !j.at("watcher").is_null()) {
        o.watcher = std::make_shared<User>();
        from_json(j.at("watcher"), *o.watcher);
    }
    o.distance = j.contains("distance") && !j.at("distance").is_null()
        ? j.at("distance").get<int64_t>() : 0;
}

inline void to_json(json& j, const ProximityAlertTriggered& o) {
    j = json::object();
    {
        json _sub; to_json(_sub, *o.traveler); j["traveler"] = std::move(_sub);
    }
    {
        json _sub; to_json(_sub, *o.watcher); j["watcher"] = std::move(_sub);
    }
    j["distance"] = o.distance;
}

inline void from_json(const json& j, MessageAutoDeleteTimerChanged& o) {
    o.message_auto_delete_time = j.contains("message_auto_delete_time") && !j.at("message_auto_delete_time").is_null()
        ? j.at("message_auto_delete_time").get<int64_t>() : 0;
}

inline void to_json(json& j, const MessageAutoDeleteTimerChanged& o) {
    j = json::object();
    j["message_auto_delete_time"] = o.message_auto_delete_time;
}

inline void from_json(const json& j, ManagedBotCreated& o) {
    if (j.contains("bot") && !j.at("bot").is_null()) {
        o.bot = std::make_shared<User>();
        from_json(j.at("bot"), *o.bot);
    }
}

inline void to_json(json& j, const ManagedBotCreated& o) {
    j = json::object();
    {
        json _sub; to_json(_sub, *o.bot); j["bot"] = std::move(_sub);
    }
}

inline void from_json(const json& j, ManagedBotUpdated& o) {
    if (j.contains("user") && !j.at("user").is_null()) {
        o.user = std::make_shared<User>();
        from_json(j.at("user"), *o.user);
    }
    if (j.contains("bot") && !j.at("bot").is_null()) {
        o.bot = std::make_shared<User>();
        from_json(j.at("bot"), *o.bot);
    }
}

inline void to_json(json& j, const ManagedBotUpdated& o) {
    j = json::object();
    {
        json _sub; to_json(_sub, *o.user); j["user"] = std::move(_sub);
    }
    {
        json _sub; to_json(_sub, *o.bot); j["bot"] = std::move(_sub);
    }
}

inline void from_json(const json& j, PollOptionAdded& o) {
    if (j.contains("poll_message") && !j.at("poll_message").is_null()) {
        MaybeInaccessibleMessage _tmp{};
        from_json(j.at("poll_message"), _tmp);
        o.poll_message = std::move(_tmp);
    }
    o.option_persistent_id = j.contains("option_persistent_id") && !j.at("option_persistent_id").is_null()
        ? j.at("option_persistent_id").get<std::string>() : "";
    o.option_text = j.contains("option_text") && !j.at("option_text").is_null()
        ? j.at("option_text").get<std::string>() : "";
    if (j.contains("option_text_entities") && j.at("option_text_entities").is_array()) {
        for (const auto& _item : j.at("option_text_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.option_text_entities.push_back(std::move(_elem));
            }
        }
    }
}

inline void to_json(json& j, const PollOptionAdded& o) {
    j = json::object();
    if (o.poll_message.has_value()) {
        json _sub;
        to_json(_sub, o.poll_message.value());
        j["poll_message"] = std::move(_sub);
    }
    j["option_persistent_id"] = o.option_persistent_id;
    j["option_text"] = o.option_text;
    {
        json _arr = json::array();
        for (const auto& _item : o.option_text_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["option_text_entities"] = std::move(_arr);
    }
}

inline void from_json(const json& j, PollOptionDeleted& o) {
    if (j.contains("poll_message") && !j.at("poll_message").is_null()) {
        MaybeInaccessibleMessage _tmp{};
        from_json(j.at("poll_message"), _tmp);
        o.poll_message = std::move(_tmp);
    }
    o.option_persistent_id = j.contains("option_persistent_id") && !j.at("option_persistent_id").is_null()
        ? j.at("option_persistent_id").get<std::string>() : "";
    o.option_text = j.contains("option_text") && !j.at("option_text").is_null()
        ? j.at("option_text").get<std::string>() : "";
    if (j.contains("option_text_entities") && j.at("option_text_entities").is_array()) {
        for (const auto& _item : j.at("option_text_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.option_text_entities.push_back(std::move(_elem));
            }
        }
    }
}

inline void to_json(json& j, const PollOptionDeleted& o) {
    j = json::object();
    if (o.poll_message.has_value()) {
        json _sub;
        to_json(_sub, o.poll_message.value());
        j["poll_message"] = std::move(_sub);
    }
    j["option_persistent_id"] = o.option_persistent_id;
    j["option_text"] = o.option_text;
    {
        json _arr = json::array();
        for (const auto& _item : o.option_text_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["option_text_entities"] = std::move(_arr);
    }
}

inline void from_json(const json& j, ChatBoostAdded& o) {
    o.boost_count = j.contains("boost_count") && !j.at("boost_count").is_null()
        ? j.at("boost_count").get<int64_t>() : 0;
}

inline void to_json(json& j, const ChatBoostAdded& o) {
    j = json::object();
    j["boost_count"] = o.boost_count;
}

inline void from_json(const json& j, BackgroundFill& v) {
    std::string type = j.at("type").get<std::string>();
    if (type == "solid") {
        auto obj = std::make_shared<BackgroundFillSolid>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "gradient") {
        auto obj = std::make_shared<BackgroundFillGradient>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "freeform_gradient") {
        auto obj = std::make_shared<BackgroundFillFreeformGradient>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const BackgroundFill& v) {
    if (auto* p = std::get_if <std::shared_ptr<BackgroundFillSolid>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<BackgroundFillGradient>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<BackgroundFillFreeformGradient>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, BackgroundFillSolid& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.color = j.contains("color") && !j.at("color").is_null()
        ? j.at("color").get<int64_t>() : 0;
}

inline void to_json(json& j, const BackgroundFillSolid& o) {
    j = json::object();
    j["type"] = o.type;
    j["color"] = o.color;
}

inline void from_json(const json& j, BackgroundFillGradient& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.top_color = j.contains("top_color") && !j.at("top_color").is_null()
        ? j.at("top_color").get<int64_t>() : 0;
    o.bottom_color = j.contains("bottom_color") && !j.at("bottom_color").is_null()
        ? j.at("bottom_color").get<int64_t>() : 0;
    o.rotation_angle = j.contains("rotation_angle") && !j.at("rotation_angle").is_null()
        ? j.at("rotation_angle").get<int64_t>() : 0;
}

inline void to_json(json& j, const BackgroundFillGradient& o) {
    j = json::object();
    j["type"] = o.type;
    j["top_color"] = o.top_color;
    j["bottom_color"] = o.bottom_color;
    j["rotation_angle"] = o.rotation_angle;
}

inline void from_json(const json& j, BackgroundFillFreeformGradient& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("colors") && j.at("colors").is_array()) {
        for (const auto& _item : j.at("colors")) {
            o.colors.push_back(_item.get<int64_t>());
        }
    }
}

inline void to_json(json& j, const BackgroundFillFreeformGradient& o) {
    j = json::object();
    j["type"] = o.type;
    {
        json _arr = json::array();
        for (const auto& _item : o.colors) {
            _arr.push_back(_item);
        }
        j["colors"] = std::move(_arr);
    }
}

inline void from_json(const json& j, BackgroundType& v) {
    std::string type = j.at("type").get<std::string>();
    if (type == "fill") {
        auto obj = std::make_shared<BackgroundTypeFill>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "wallpaper") {
        auto obj = std::make_shared<BackgroundTypeWallpaper>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "pattern") {
        auto obj = std::make_shared<BackgroundTypePattern>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "chat_theme") {
        auto obj = std::make_shared<BackgroundTypeChatTheme>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const BackgroundType& v) {
    if (auto* p = std::get_if <std::shared_ptr<BackgroundTypeFill>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<BackgroundTypeWallpaper>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<BackgroundTypePattern>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<BackgroundTypeChatTheme>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, BackgroundTypeFill& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("fill") && !j.at("fill").is_null()) {
        from_json(j.at("fill"), o.fill);
    }
    o.dark_theme_dimming = j.contains("dark_theme_dimming") && !j.at("dark_theme_dimming").is_null()
        ? j.at("dark_theme_dimming").get<int64_t>() : 0;
}

inline void to_json(json& j, const BackgroundTypeFill& o) {
    j = json::object();
    j["type"] = o.type;
    {
        json _sub;
        to_json(_sub, o.fill);
        j["fill"] = std::move(_sub);
    }
    j["dark_theme_dimming"] = o.dark_theme_dimming;
}

inline void from_json(const json& j, BackgroundTypeWallpaper& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("document") && !j.at("document").is_null()) {
        o.document = std::make_shared<Document>();
        from_json(j.at("document"), *o.document);
    }
    o.dark_theme_dimming = j.contains("dark_theme_dimming") && !j.at("dark_theme_dimming").is_null()
        ? j.at("dark_theme_dimming").get<int64_t>() : 0;
    if (j.contains("is_blurred") && !j.at("is_blurred").is_null())
        o.is_blurred = j.at("is_blurred").get<bool>();
    if (j.contains("is_moving") && !j.at("is_moving").is_null())
        o.is_moving = j.at("is_moving").get<bool>();
}

inline void to_json(json& j, const BackgroundTypeWallpaper& o) {
    j = json::object();
    j["type"] = o.type;
    {
        json _sub; to_json(_sub, *o.document); j["document"] = std::move(_sub);
    }
    j["dark_theme_dimming"] = o.dark_theme_dimming;
    if (o.is_blurred.has_value())
        j["is_blurred"] = o.is_blurred.value();
    if (o.is_moving.has_value())
        j["is_moving"] = o.is_moving.value();
}

inline void from_json(const json& j, BackgroundTypePattern& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("document") && !j.at("document").is_null()) {
        o.document = std::make_shared<Document>();
        from_json(j.at("document"), *o.document);
    }
    if (j.contains("fill") && !j.at("fill").is_null()) {
        from_json(j.at("fill"), o.fill);
    }
    o.intensity = j.contains("intensity") && !j.at("intensity").is_null()
        ? j.at("intensity").get<int64_t>() : 0;
    if (j.contains("is_inverted") && !j.at("is_inverted").is_null())
        o.is_inverted = j.at("is_inverted").get<bool>();
    if (j.contains("is_moving") && !j.at("is_moving").is_null())
        o.is_moving = j.at("is_moving").get<bool>();
}

inline void to_json(json& j, const BackgroundTypePattern& o) {
    j = json::object();
    j["type"] = o.type;
    {
        json _sub; to_json(_sub, *o.document); j["document"] = std::move(_sub);
    }
    {
        json _sub;
        to_json(_sub, o.fill);
        j["fill"] = std::move(_sub);
    }
    j["intensity"] = o.intensity;
    if (o.is_inverted.has_value())
        j["is_inverted"] = o.is_inverted.value();
    if (o.is_moving.has_value())
        j["is_moving"] = o.is_moving.value();
}

inline void from_json(const json& j, BackgroundTypeChatTheme& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.theme_name = j.contains("theme_name") && !j.at("theme_name").is_null()
        ? j.at("theme_name").get<std::string>() : "";
}

inline void to_json(json& j, const BackgroundTypeChatTheme& o) {
    j = json::object();
    j["type"] = o.type;
    j["theme_name"] = o.theme_name;
}

inline void from_json(const json& j, ChatBackground& o) {
    if (j.contains("type") && !j.at("type").is_null()) {
        from_json(j.at("type"), o.type);
    }
}

inline void to_json(json& j, const ChatBackground& o) {
    j = json::object();
    {
        json _sub;
        to_json(_sub, o.type);
        j["type"] = std::move(_sub);
    }
}

inline void from_json(const json& j, ForumTopicCreated& o) {
    o.name = j.contains("name") && !j.at("name").is_null()
        ? j.at("name").get<std::string>() : "";
    o.icon_color = j.contains("icon_color") && !j.at("icon_color").is_null()
        ? j.at("icon_color").get<int64_t>() : 0;
    if (j.contains("icon_custom_emoji_id") && !j.at("icon_custom_emoji_id").is_null())
        o.icon_custom_emoji_id = j.at("icon_custom_emoji_id").get<std::string>();
    if (j.contains("is_name_implicit") && !j.at("is_name_implicit").is_null())
        o.is_name_implicit = j.at("is_name_implicit").get<bool>();
}

inline void to_json(json& j, const ForumTopicCreated& o) {
    j = json::object();
    j["name"] = o.name;
    j["icon_color"] = o.icon_color;
    if (o.icon_custom_emoji_id.has_value())
        j["icon_custom_emoji_id"] = o.icon_custom_emoji_id.value();
    if (o.is_name_implicit.has_value())
        j["is_name_implicit"] = o.is_name_implicit.value();
}

inline void from_json(const json& j, ForumTopicClosed& o) {
    (void)j; (void)o;
}

inline void to_json(json& j, const ForumTopicClosed& o) {
    j = json::object();
    (void)o;
}

inline void from_json(const json& j, ForumTopicEdited& o) {
    if (j.contains("name") && !j.at("name").is_null())
        o.name = j.at("name").get<std::string>();
    if (j.contains("icon_custom_emoji_id") && !j.at("icon_custom_emoji_id").is_null())
        o.icon_custom_emoji_id = j.at("icon_custom_emoji_id").get<std::string>();
}

inline void to_json(json& j, const ForumTopicEdited& o) {
    j = json::object();
    if (o.name.has_value())
        j["name"] = o.name.value();
    if (o.icon_custom_emoji_id.has_value())
        j["icon_custom_emoji_id"] = o.icon_custom_emoji_id.value();
}

inline void from_json(const json& j, ForumTopicReopened& o) {
    (void)j; (void)o;
}

inline void to_json(json& j, const ForumTopicReopened& o) {
    j = json::object();
    (void)o;
}

inline void from_json(const json& j, GeneralForumTopicHidden& o) {
    (void)j; (void)o;
}

inline void to_json(json& j, const GeneralForumTopicHidden& o) {
    j = json::object();
    (void)o;
}

inline void from_json(const json& j, GeneralForumTopicUnhidden& o) {
    (void)j; (void)o;
}

inline void to_json(json& j, const GeneralForumTopicUnhidden& o) {
    j = json::object();
    (void)o;
}

inline void from_json(const json& j, SharedUser& o) {
    o.user_id = j.contains("user_id") && !j.at("user_id").is_null()
        ? j.at("user_id").get<int64_t>() : 0;
    if (j.contains("first_name") && !j.at("first_name").is_null())
        o.first_name = j.at("first_name").get<std::string>();
    if (j.contains("last_name") && !j.at("last_name").is_null())
        o.last_name = j.at("last_name").get<std::string>();
    if (j.contains("username") && !j.at("username").is_null())
        o.username = j.at("username").get<std::string>();
    if (j.contains("photo") && j.at("photo").is_array()) {
        for (const auto& _item : j.at("photo")) {
            {
                auto _elem = std::make_shared<PhotoSize>();
                from_json(_item, *_elem);
                o.photo.push_back(std::move(_elem));
            }
        }
    }
}

inline void to_json(json& j, const SharedUser& o) {
    j = json::object();
    j["user_id"] = o.user_id;
    if (o.first_name.has_value())
        j["first_name"] = o.first_name.value();
    if (o.last_name.has_value())
        j["last_name"] = o.last_name.value();
    if (o.username.has_value())
        j["username"] = o.username.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.photo) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["photo"] = std::move(_arr);
    }
}

inline void from_json(const json& j, UsersShared& o) {
    o.request_id = j.contains("request_id") && !j.at("request_id").is_null()
        ? j.at("request_id").get<int64_t>() : 0;
    if (j.contains("users") && j.at("users").is_array()) {
        for (const auto& _item : j.at("users")) {
            {
                auto _elem = std::make_shared<SharedUser>();
                from_json(_item, *_elem);
                o.users.push_back(std::move(_elem));
            }
        }
    }
}

inline void to_json(json& j, const UsersShared& o) {
    j = json::object();
    j["request_id"] = o.request_id;
    {
        json _arr = json::array();
        for (const auto& _item : o.users) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["users"] = std::move(_arr);
    }
}

inline void from_json(const json& j, ChatShared& o) {
    o.request_id = j.contains("request_id") && !j.at("request_id").is_null()
        ? j.at("request_id").get<int64_t>() : 0;
    o.chat_id = j.contains("chat_id") && !j.at("chat_id").is_null()
        ? j.at("chat_id").get<int64_t>() : 0;
    if (j.contains("title") && !j.at("title").is_null())
        o.title = j.at("title").get<std::string>();
    if (j.contains("username") && !j.at("username").is_null())
        o.username = j.at("username").get<std::string>();
    if (j.contains("photo") && j.at("photo").is_array()) {
        for (const auto& _item : j.at("photo")) {
            {
                auto _elem = std::make_shared<PhotoSize>();
                from_json(_item, *_elem);
                o.photo.push_back(std::move(_elem));
            }
        }
    }
}

inline void to_json(json& j, const ChatShared& o) {
    j = json::object();
    j["request_id"] = o.request_id;
    j["chat_id"] = o.chat_id;
    if (o.title.has_value())
        j["title"] = o.title.value();
    if (o.username.has_value())
        j["username"] = o.username.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.photo) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["photo"] = std::move(_arr);
    }
}

inline void from_json(const json& j, WriteAccessAllowed& o) {
    if (j.contains("from_request") && !j.at("from_request").is_null())
        o.from_request = j.at("from_request").get<bool>();
    if (j.contains("web_app_name") && !j.at("web_app_name").is_null())
        o.web_app_name = j.at("web_app_name").get<std::string>();
    if (j.contains("from_attachment_menu") && !j.at("from_attachment_menu").is_null())
        o.from_attachment_menu = j.at("from_attachment_menu").get<bool>();
}

inline void to_json(json& j, const WriteAccessAllowed& o) {
    j = json::object();
    if (o.from_request.has_value())
        j["from_request"] = o.from_request.value();
    if (o.web_app_name.has_value())
        j["web_app_name"] = o.web_app_name.value();
    if (o.from_attachment_menu.has_value())
        j["from_attachment_menu"] = o.from_attachment_menu.value();
}

inline void from_json(const json& j, VideoChatScheduled& o) {
    o.start_date = j.contains("start_date") && !j.at("start_date").is_null()
        ? j.at("start_date").get<int64_t>() : 0;
}

inline void to_json(json& j, const VideoChatScheduled& o) {
    j = json::object();
    j["start_date"] = o.start_date;
}

inline void from_json(const json& j, VideoChatStarted& o) {
    (void)j; (void)o;
}

inline void to_json(json& j, const VideoChatStarted& o) {
    j = json::object();
    (void)o;
}

inline void from_json(const json& j, VideoChatEnded& o) {
    o.duration = j.contains("duration") && !j.at("duration").is_null()
        ? j.at("duration").get<int64_t>() : 0;
}

inline void to_json(json& j, const VideoChatEnded& o) {
    j = json::object();
    j["duration"] = o.duration;
}

inline void from_json(const json& j, VideoChatParticipantsInvited& o) {
    if (j.contains("users") && j.at("users").is_array()) {
        for (const auto& _item : j.at("users")) {
            {
                auto _elem = std::make_shared<User>();
                from_json(_item, *_elem);
                o.users.push_back(std::move(_elem));
            }
        }
    }
}

inline void to_json(json& j, const VideoChatParticipantsInvited& o) {
    j = json::object();
    {
        json _arr = json::array();
        for (const auto& _item : o.users) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["users"] = std::move(_arr);
    }
}

inline void from_json(const json& j, PaidMessagePriceChanged& o) {
    o.paid_message_star_count = j.contains("paid_message_star_count") && !j.at("paid_message_star_count").is_null()
        ? j.at("paid_message_star_count").get<int64_t>() : 0;
}

inline void to_json(json& j, const PaidMessagePriceChanged& o) {
    j = json::object();
    j["paid_message_star_count"] = o.paid_message_star_count;
}

inline void from_json(const json& j, DirectMessagePriceChanged& o) {
    o.are_direct_messages_enabled = j.contains("are_direct_messages_enabled") && !j.at("are_direct_messages_enabled").is_null()
        ? j.at("are_direct_messages_enabled").get<bool>() : false;
    if (j.contains("direct_message_star_count") && !j.at("direct_message_star_count").is_null())
        o.direct_message_star_count = j.at("direct_message_star_count").get<int64_t>();
}

inline void to_json(json& j, const DirectMessagePriceChanged& o) {
    j = json::object();
    j["are_direct_messages_enabled"] = o.are_direct_messages_enabled;
    if (o.direct_message_star_count.has_value())
        j["direct_message_star_count"] = o.direct_message_star_count.value();
}

inline void from_json(const json& j, SuggestedPostApproved& o) {
    if (j.contains("suggested_post_message") && !j.at("suggested_post_message").is_null()) {
        o.suggested_post_message = std::make_shared<Message>();
        from_json(j.at("suggested_post_message"), *o.suggested_post_message);
    }
    if (j.contains("price") && !j.at("price").is_null()) {
        o.price = std::make_shared<SuggestedPostPrice>();
        from_json(j.at("price"), *o.price);
    }
    o.send_date = j.contains("send_date") && !j.at("send_date").is_null()
        ? j.at("send_date").get<int64_t>() : 0;
}

inline void to_json(json& j, const SuggestedPostApproved& o) {
    j = json::object();
    if (o.suggested_post_message) {
        json _sub; to_json(_sub, *o.suggested_post_message); j["suggested_post_message"] = std::move(_sub);
    }
    if (o.price) {
        json _sub; to_json(_sub, *o.price); j["price"] = std::move(_sub);
    }
    j["send_date"] = o.send_date;
}

inline void from_json(const json& j, SuggestedPostApprovalFailed& o) {
    if (j.contains("suggested_post_message") && !j.at("suggested_post_message").is_null()) {
        o.suggested_post_message = std::make_shared<Message>();
        from_json(j.at("suggested_post_message"), *o.suggested_post_message);
    }
    if (j.contains("price") && !j.at("price").is_null()) {
        o.price = std::make_shared<SuggestedPostPrice>();
        from_json(j.at("price"), *o.price);
    }
}

inline void to_json(json& j, const SuggestedPostApprovalFailed& o) {
    j = json::object();
    if (o.suggested_post_message) {
        json _sub; to_json(_sub, *o.suggested_post_message); j["suggested_post_message"] = std::move(_sub);
    }
    {
        json _sub; to_json(_sub, *o.price); j["price"] = std::move(_sub);
    }
}

inline void from_json(const json& j, SuggestedPostDeclined& o) {
    if (j.contains("suggested_post_message") && !j.at("suggested_post_message").is_null()) {
        o.suggested_post_message = std::make_shared<Message>();
        from_json(j.at("suggested_post_message"), *o.suggested_post_message);
    }
    if (j.contains("comment") && !j.at("comment").is_null())
        o.comment = j.at("comment").get<std::string>();
}

inline void to_json(json& j, const SuggestedPostDeclined& o) {
    j = json::object();
    if (o.suggested_post_message) {
        json _sub; to_json(_sub, *o.suggested_post_message); j["suggested_post_message"] = std::move(_sub);
    }
    if (o.comment.has_value())
        j["comment"] = o.comment.value();
}

inline void from_json(const json& j, SuggestedPostPaid& o) {
    if (j.contains("suggested_post_message") && !j.at("suggested_post_message").is_null()) {
        o.suggested_post_message = std::make_shared<Message>();
        from_json(j.at("suggested_post_message"), *o.suggested_post_message);
    }
    o.currency = j.contains("currency") && !j.at("currency").is_null()
        ? j.at("currency").get<std::string>() : "";
    if (j.contains("amount") && !j.at("amount").is_null())
        o.amount = j.at("amount").get<int64_t>();
    if (j.contains("star_amount") && !j.at("star_amount").is_null()) {
        o.star_amount = std::make_shared<StarAmount>();
        from_json(j.at("star_amount"), *o.star_amount);
    }
}

inline void to_json(json& j, const SuggestedPostPaid& o) {
    j = json::object();
    if (o.suggested_post_message) {
        json _sub; to_json(_sub, *o.suggested_post_message); j["suggested_post_message"] = std::move(_sub);
    }
    j["currency"] = o.currency;
    if (o.amount.has_value())
        j["amount"] = o.amount.value();
    if (o.star_amount) {
        json _sub; to_json(_sub, *o.star_amount); j["star_amount"] = std::move(_sub);
    }
}

inline void from_json(const json& j, SuggestedPostRefunded& o) {
    if (j.contains("suggested_post_message") && !j.at("suggested_post_message").is_null()) {
        o.suggested_post_message = std::make_shared<Message>();
        from_json(j.at("suggested_post_message"), *o.suggested_post_message);
    }
    o.reason = j.contains("reason") && !j.at("reason").is_null()
        ? j.at("reason").get<std::string>() : "";
}

inline void to_json(json& j, const SuggestedPostRefunded& o) {
    j = json::object();
    if (o.suggested_post_message) {
        json _sub; to_json(_sub, *o.suggested_post_message); j["suggested_post_message"] = std::move(_sub);
    }
    j["reason"] = o.reason;
}

inline void from_json(const json& j, GiveawayCreated& o) {
    if (j.contains("prize_star_count") && !j.at("prize_star_count").is_null())
        o.prize_star_count = j.at("prize_star_count").get<int64_t>();
}

inline void to_json(json& j, const GiveawayCreated& o) {
    j = json::object();
    if (o.prize_star_count.has_value())
        j["prize_star_count"] = o.prize_star_count.value();
}

inline void from_json(const json& j, Giveaway& o) {
    if (j.contains("chats") && j.at("chats").is_array()) {
        for (const auto& _item : j.at("chats")) {
            {
                auto _elem = std::make_shared<Chat>();
                from_json(_item, *_elem);
                o.chats.push_back(std::move(_elem));
            }
        }
    }
    o.winners_selection_date = j.contains("winners_selection_date") && !j.at("winners_selection_date").is_null()
        ? j.at("winners_selection_date").get<int64_t>() : 0;
    o.winner_count = j.contains("winner_count") && !j.at("winner_count").is_null()
        ? j.at("winner_count").get<int64_t>() : 0;
    if (j.contains("only_new_members") && !j.at("only_new_members").is_null())
        o.only_new_members = j.at("only_new_members").get<bool>();
    if (j.contains("has_public_winners") && !j.at("has_public_winners").is_null())
        o.has_public_winners = j.at("has_public_winners").get<bool>();
    if (j.contains("prize_description") && !j.at("prize_description").is_null())
        o.prize_description = j.at("prize_description").get<std::string>();
    if (j.contains("country_codes") && j.at("country_codes").is_array()) {
        for (const auto& _item : j.at("country_codes")) {
            o.country_codes.push_back(_item.get<std::string>());
        }
    }
    if (j.contains("prize_star_count") && !j.at("prize_star_count").is_null())
        o.prize_star_count = j.at("prize_star_count").get<int64_t>();
    if (j.contains("premium_subscription_month_count") && !j.at("premium_subscription_month_count").is_null())
        o.premium_subscription_month_count = j.at("premium_subscription_month_count").get<int64_t>();
}

inline void to_json(json& j, const Giveaway& o) {
    j = json::object();
    {
        json _arr = json::array();
        for (const auto& _item : o.chats) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["chats"] = std::move(_arr);
    }
    j["winners_selection_date"] = o.winners_selection_date;
    j["winner_count"] = o.winner_count;
    if (o.only_new_members.has_value())
        j["only_new_members"] = o.only_new_members.value();
    if (o.has_public_winners.has_value())
        j["has_public_winners"] = o.has_public_winners.value();
    if (o.prize_description.has_value())
        j["prize_description"] = o.prize_description.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.country_codes) {
            _arr.push_back(_item);
        }
        j["country_codes"] = std::move(_arr);
    }
    if (o.prize_star_count.has_value())
        j["prize_star_count"] = o.prize_star_count.value();
    if (o.premium_subscription_month_count.has_value())
        j["premium_subscription_month_count"] = o.premium_subscription_month_count.value();
}

inline void from_json(const json& j, GiveawayWinners& o) {
    if (j.contains("chat") && !j.at("chat").is_null()) {
        o.chat = std::make_shared<Chat>();
        from_json(j.at("chat"), *o.chat);
    }
    o.giveaway_message_id = j.contains("giveaway_message_id") && !j.at("giveaway_message_id").is_null()
        ? j.at("giveaway_message_id").get<int64_t>() : 0;
    o.winners_selection_date = j.contains("winners_selection_date") && !j.at("winners_selection_date").is_null()
        ? j.at("winners_selection_date").get<int64_t>() : 0;
    o.winner_count = j.contains("winner_count") && !j.at("winner_count").is_null()
        ? j.at("winner_count").get<int64_t>() : 0;
    if (j.contains("winners") && j.at("winners").is_array()) {
        for (const auto& _item : j.at("winners")) {
            {
                auto _elem = std::make_shared<User>();
                from_json(_item, *_elem);
                o.winners.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("additional_chat_count") && !j.at("additional_chat_count").is_null())
        o.additional_chat_count = j.at("additional_chat_count").get<int64_t>();
    if (j.contains("prize_star_count") && !j.at("prize_star_count").is_null())
        o.prize_star_count = j.at("prize_star_count").get<int64_t>();
    if (j.contains("premium_subscription_month_count") && !j.at("premium_subscription_month_count").is_null())
        o.premium_subscription_month_count = j.at("premium_subscription_month_count").get<int64_t>();
    if (j.contains("unclaimed_prize_count") && !j.at("unclaimed_prize_count").is_null())
        o.unclaimed_prize_count = j.at("unclaimed_prize_count").get<int64_t>();
    if (j.contains("only_new_members") && !j.at("only_new_members").is_null())
        o.only_new_members = j.at("only_new_members").get<bool>();
    if (j.contains("was_refunded") && !j.at("was_refunded").is_null())
        o.was_refunded = j.at("was_refunded").get<bool>();
    if (j.contains("prize_description") && !j.at("prize_description").is_null())
        o.prize_description = j.at("prize_description").get<std::string>();
}

inline void to_json(json& j, const GiveawayWinners& o) {
    j = json::object();
    {
        json _sub; to_json(_sub, *o.chat); j["chat"] = std::move(_sub);
    }
    j["giveaway_message_id"] = o.giveaway_message_id;
    j["winners_selection_date"] = o.winners_selection_date;
    j["winner_count"] = o.winner_count;
    {
        json _arr = json::array();
        for (const auto& _item : o.winners) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["winners"] = std::move(_arr);
    }
    if (o.additional_chat_count.has_value())
        j["additional_chat_count"] = o.additional_chat_count.value();
    if (o.prize_star_count.has_value())
        j["prize_star_count"] = o.prize_star_count.value();
    if (o.premium_subscription_month_count.has_value())
        j["premium_subscription_month_count"] = o.premium_subscription_month_count.value();
    if (o.unclaimed_prize_count.has_value())
        j["unclaimed_prize_count"] = o.unclaimed_prize_count.value();
    if (o.only_new_members.has_value())
        j["only_new_members"] = o.only_new_members.value();
    if (o.was_refunded.has_value())
        j["was_refunded"] = o.was_refunded.value();
    if (o.prize_description.has_value())
        j["prize_description"] = o.prize_description.value();
}

inline void from_json(const json& j, GiveawayCompleted& o) {
    o.winner_count = j.contains("winner_count") && !j.at("winner_count").is_null()
        ? j.at("winner_count").get<int64_t>() : 0;
    if (j.contains("unclaimed_prize_count") && !j.at("unclaimed_prize_count").is_null())
        o.unclaimed_prize_count = j.at("unclaimed_prize_count").get<int64_t>();
    if (j.contains("giveaway_message") && !j.at("giveaway_message").is_null()) {
        o.giveaway_message = std::make_shared<Message>();
        from_json(j.at("giveaway_message"), *o.giveaway_message);
    }
    if (j.contains("is_star_giveaway") && !j.at("is_star_giveaway").is_null())
        o.is_star_giveaway = j.at("is_star_giveaway").get<bool>();
}

inline void to_json(json& j, const GiveawayCompleted& o) {
    j = json::object();
    j["winner_count"] = o.winner_count;
    if (o.unclaimed_prize_count.has_value())
        j["unclaimed_prize_count"] = o.unclaimed_prize_count.value();
    if (o.giveaway_message) {
        json _sub; to_json(_sub, *o.giveaway_message); j["giveaway_message"] = std::move(_sub);
    }
    if (o.is_star_giveaway.has_value())
        j["is_star_giveaway"] = o.is_star_giveaway.value();
}

inline void from_json(const json& j, LinkPreviewOptions& o) {
    if (j.contains("is_disabled") && !j.at("is_disabled").is_null())
        o.is_disabled = j.at("is_disabled").get<bool>();
    if (j.contains("url") && !j.at("url").is_null())
        o.url = j.at("url").get<std::string>();
    if (j.contains("prefer_small_media") && !j.at("prefer_small_media").is_null())
        o.prefer_small_media = j.at("prefer_small_media").get<bool>();
    if (j.contains("prefer_large_media") && !j.at("prefer_large_media").is_null())
        o.prefer_large_media = j.at("prefer_large_media").get<bool>();
    if (j.contains("show_above_text") && !j.at("show_above_text").is_null())
        o.show_above_text = j.at("show_above_text").get<bool>();
}

inline void to_json(json& j, const LinkPreviewOptions& o) {
    j = json::object();
    if (o.is_disabled.has_value())
        j["is_disabled"] = o.is_disabled.value();
    if (o.url.has_value())
        j["url"] = o.url.value();
    if (o.prefer_small_media.has_value())
        j["prefer_small_media"] = o.prefer_small_media.value();
    if (o.prefer_large_media.has_value())
        j["prefer_large_media"] = o.prefer_large_media.value();
    if (o.show_above_text.has_value())
        j["show_above_text"] = o.show_above_text.value();
}

inline void from_json(const json& j, SuggestedPostPrice& o) {
    o.currency = j.contains("currency") && !j.at("currency").is_null()
        ? j.at("currency").get<std::string>() : "";
    o.amount = j.contains("amount") && !j.at("amount").is_null()
        ? j.at("amount").get<int64_t>() : 0;
}

inline void to_json(json& j, const SuggestedPostPrice& o) {
    j = json::object();
    j["currency"] = o.currency;
    j["amount"] = o.amount;
}

inline void from_json(const json& j, SuggestedPostInfo& o) {
    o.state = j.contains("state") && !j.at("state").is_null()
        ? j.at("state").get<std::string>() : "";
    if (j.contains("price") && !j.at("price").is_null()) {
        o.price = std::make_shared<SuggestedPostPrice>();
        from_json(j.at("price"), *o.price);
    }
    if (j.contains("send_date") && !j.at("send_date").is_null())
        o.send_date = j.at("send_date").get<int64_t>();
}

inline void to_json(json& j, const SuggestedPostInfo& o) {
    j = json::object();
    j["state"] = o.state;
    if (o.price) {
        json _sub; to_json(_sub, *o.price); j["price"] = std::move(_sub);
    }
    if (o.send_date.has_value())
        j["send_date"] = o.send_date.value();
}

inline void from_json(const json& j, SuggestedPostParameters& o) {
    if (j.contains("price") && !j.at("price").is_null()) {
        o.price = std::make_shared<SuggestedPostPrice>();
        from_json(j.at("price"), *o.price);
    }
    if (j.contains("send_date") && !j.at("send_date").is_null())
        o.send_date = j.at("send_date").get<int64_t>();
}

inline void to_json(json& j, const SuggestedPostParameters& o) {
    j = json::object();
    if (o.price) {
        json _sub; to_json(_sub, *o.price); j["price"] = std::move(_sub);
    }
    if (o.send_date.has_value())
        j["send_date"] = o.send_date.value();
}

inline void from_json(const json& j, DirectMessagesTopic& o) {
    o.topic_id = j.contains("topic_id") && !j.at("topic_id").is_null()
        ? j.at("topic_id").get<int64_t>() : 0;
    if (j.contains("user") && !j.at("user").is_null()) {
        o.user = std::make_shared<User>();
        from_json(j.at("user"), *o.user);
    }
}

inline void to_json(json& j, const DirectMessagesTopic& o) {
    j = json::object();
    j["topic_id"] = o.topic_id;
    if (o.user) {
        json _sub; to_json(_sub, *o.user); j["user"] = std::move(_sub);
    }
}

inline void from_json(const json& j, UserProfilePhotos& o) {
    o.total_count = j.contains("total_count") && !j.at("total_count").is_null()
        ? j.at("total_count").get<int64_t>() : 0;
    if (j.contains("photos") && j.at("photos").is_array()) {
        for (const auto& _item : j.at("photos")) {
            std::vector<std::shared_ptr<PhotoSize>> _sv_item;
            if (_item.is_array()) {
                for (const auto& _si_item : _item) {
                    {
                        auto _elem = std::make_shared<PhotoSize>();
                        from_json(_si_item, *_elem);
                        _sv_item.push_back(std::move(_elem));
                    }
                }
            }
            o.photos.push_back(std::move(_sv_item));
        }
    }
}

inline void to_json(json& j, const UserProfilePhotos& o) {
    j = json::object();
    j["total_count"] = o.total_count;
    {
        json _arr = json::array();
        for (const auto& _item : o.photos) {
            {
                json _ia_item = json::array();
                for (const auto& _ii_item : _item) {
                    {
                        json _e; to_json(_e, *_ii_item); _ia_item.push_back(std::move(_e));
                    }
                }
                _arr.push_back(std::move(_ia_item));
            }
        }
        j["photos"] = std::move(_arr);
    }
}

inline void from_json(const json& j, UserProfileAudios& o) {
    o.total_count = j.contains("total_count") && !j.at("total_count").is_null()
        ? j.at("total_count").get<int64_t>() : 0;
    if (j.contains("audios") && j.at("audios").is_array()) {
        for (const auto& _item : j.at("audios")) {
            {
                auto _elem = std::make_shared<Audio>();
                from_json(_item, *_elem);
                o.audios.push_back(std::move(_elem));
            }
        }
    }
}

inline void to_json(json& j, const UserProfileAudios& o) {
    j = json::object();
    j["total_count"] = o.total_count;
    {
        json _arr = json::array();
        for (const auto& _item : o.audios) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["audios"] = std::move(_arr);
    }
}

inline void from_json(const json& j, File& o) {
    o.file_id = j.contains("file_id") && !j.at("file_id").is_null()
        ? j.at("file_id").get<std::string>() : "";
    o.file_unique_id = j.contains("file_unique_id") && !j.at("file_unique_id").is_null()
        ? j.at("file_unique_id").get<std::string>() : "";
    if (j.contains("file_size") && !j.at("file_size").is_null())
        o.file_size = j.at("file_size").get<int64_t>();
    if (j.contains("file_path") && !j.at("file_path").is_null())
        o.file_path = j.at("file_path").get<std::string>();
}

inline void to_json(json& j, const File& o) {
    j = json::object();
    j["file_id"] = o.file_id;
    j["file_unique_id"] = o.file_unique_id;
    if (o.file_size.has_value())
        j["file_size"] = o.file_size.value();
    if (o.file_path.has_value())
        j["file_path"] = o.file_path.value();
}

inline void from_json(const json& j, WebAppInfo& o) {
    o.url = j.contains("url") && !j.at("url").is_null()
        ? j.at("url").get<std::string>() : "";
}

inline void to_json(json& j, const WebAppInfo& o) {
    j = json::object();
    j["url"] = o.url;
}

inline void from_json(const json& j, ReplyKeyboardMarkup& o) {
    if (j.contains("keyboard") && j.at("keyboard").is_array()) {
        for (const auto& _item : j.at("keyboard")) {
            std::vector<std::shared_ptr<KeyboardButton>> _sv_item;
            if (_item.is_array()) {
                for (const auto& _si_item : _item) {
                    {
                        auto _elem = std::make_shared<KeyboardButton>();
                        from_json(_si_item, *_elem);
                        _sv_item.push_back(std::move(_elem));
                    }
                }
            }
            o.keyboard.push_back(std::move(_sv_item));
        }
    }
    if (j.contains("is_persistent") && !j.at("is_persistent").is_null())
        o.is_persistent = j.at("is_persistent").get<bool>();
    if (j.contains("resize_keyboard") && !j.at("resize_keyboard").is_null())
        o.resize_keyboard = j.at("resize_keyboard").get<bool>();
    if (j.contains("one_time_keyboard") && !j.at("one_time_keyboard").is_null())
        o.one_time_keyboard = j.at("one_time_keyboard").get<bool>();
    if (j.contains("input_field_placeholder") && !j.at("input_field_placeholder").is_null())
        o.input_field_placeholder = j.at("input_field_placeholder").get<std::string>();
    if (j.contains("selective") && !j.at("selective").is_null())
        o.selective = j.at("selective").get<bool>();
}

inline void to_json(json& j, const ReplyKeyboardMarkup& o) {
    j = json::object();
    {
        json _arr = json::array();
        for (const auto& _item : o.keyboard) {
            {
                json _ia_item = json::array();
                for (const auto& _ii_item : _item) {
                    {
                        json _e; to_json(_e, *_ii_item); _ia_item.push_back(std::move(_e));
                    }
                }
                _arr.push_back(std::move(_ia_item));
            }
        }
        j["keyboard"] = std::move(_arr);
    }
    if (o.is_persistent.has_value())
        j["is_persistent"] = o.is_persistent.value();
    if (o.resize_keyboard.has_value())
        j["resize_keyboard"] = o.resize_keyboard.value();
    if (o.one_time_keyboard.has_value())
        j["one_time_keyboard"] = o.one_time_keyboard.value();
    if (o.input_field_placeholder.has_value())
        j["input_field_placeholder"] = o.input_field_placeholder.value();
    if (o.selective.has_value())
        j["selective"] = o.selective.value();
}

inline void from_json(const json& j, KeyboardButton& o) {
    o.text = j.contains("text") && !j.at("text").is_null()
        ? j.at("text").get<std::string>() : "";
    if (j.contains("icon_custom_emoji_id") && !j.at("icon_custom_emoji_id").is_null())
        o.icon_custom_emoji_id = j.at("icon_custom_emoji_id").get<std::string>();
    if (j.contains("style") && !j.at("style").is_null())
        o.style = j.at("style").get<std::string>();
    if (j.contains("request_users") && !j.at("request_users").is_null()) {
        o.request_users = std::make_shared<KeyboardButtonRequestUsers>();
        from_json(j.at("request_users"), *o.request_users);
    }
    if (j.contains("request_chat") && !j.at("request_chat").is_null()) {
        o.request_chat = std::make_shared<KeyboardButtonRequestChat>();
        from_json(j.at("request_chat"), *o.request_chat);
    }
    if (j.contains("request_managed_bot") && !j.at("request_managed_bot").is_null()) {
        o.request_managed_bot = std::make_shared<KeyboardButtonRequestManagedBot>();
        from_json(j.at("request_managed_bot"), *o.request_managed_bot);
    }
    if (j.contains("request_contact") && !j.at("request_contact").is_null())
        o.request_contact = j.at("request_contact").get<bool>();
    if (j.contains("request_location") && !j.at("request_location").is_null())
        o.request_location = j.at("request_location").get<bool>();
    if (j.contains("request_poll") && !j.at("request_poll").is_null()) {
        o.request_poll = std::make_shared<KeyboardButtonPollType>();
        from_json(j.at("request_poll"), *o.request_poll);
    }
    if (j.contains("web_app") && !j.at("web_app").is_null()) {
        o.web_app = std::make_shared<WebAppInfo>();
        from_json(j.at("web_app"), *o.web_app);
    }
}

inline void to_json(json& j, const KeyboardButton& o) {
    j = json::object();
    j["text"] = o.text;
    if (o.icon_custom_emoji_id.has_value())
        j["icon_custom_emoji_id"] = o.icon_custom_emoji_id.value();
    if (o.style.has_value())
        j["style"] = o.style.value();
    if (o.request_users) {
        json _sub; to_json(_sub, *o.request_users); j["request_users"] = std::move(_sub);
    }
    if (o.request_chat) {
        json _sub; to_json(_sub, *o.request_chat); j["request_chat"] = std::move(_sub);
    }
    if (o.request_managed_bot) {
        json _sub; to_json(_sub, *o.request_managed_bot); j["request_managed_bot"] = std::move(_sub);
    }
    if (o.request_contact.has_value())
        j["request_contact"] = o.request_contact.value();
    if (o.request_location.has_value())
        j["request_location"] = o.request_location.value();
    if (o.request_poll) {
        json _sub; to_json(_sub, *o.request_poll); j["request_poll"] = std::move(_sub);
    }
    if (o.web_app) {
        json _sub; to_json(_sub, *o.web_app); j["web_app"] = std::move(_sub);
    }
}

inline void from_json(const json& j, KeyboardButtonRequestUsers& o) {
    o.request_id = j.contains("request_id") && !j.at("request_id").is_null()
        ? j.at("request_id").get<int64_t>() : 0;
    if (j.contains("user_is_bot") && !j.at("user_is_bot").is_null())
        o.user_is_bot = j.at("user_is_bot").get<bool>();
    if (j.contains("user_is_premium") && !j.at("user_is_premium").is_null())
        o.user_is_premium = j.at("user_is_premium").get<bool>();
    if (j.contains("max_quantity") && !j.at("max_quantity").is_null())
        o.max_quantity = j.at("max_quantity").get<int64_t>();
    if (j.contains("request_name") && !j.at("request_name").is_null())
        o.request_name = j.at("request_name").get<bool>();
    if (j.contains("request_username") && !j.at("request_username").is_null())
        o.request_username = j.at("request_username").get<bool>();
    if (j.contains("request_photo") && !j.at("request_photo").is_null())
        o.request_photo = j.at("request_photo").get<bool>();
}

inline void to_json(json& j, const KeyboardButtonRequestUsers& o) {
    j = json::object();
    j["request_id"] = o.request_id;
    if (o.user_is_bot.has_value())
        j["user_is_bot"] = o.user_is_bot.value();
    if (o.user_is_premium.has_value())
        j["user_is_premium"] = o.user_is_premium.value();
    if (o.max_quantity.has_value())
        j["max_quantity"] = o.max_quantity.value();
    if (o.request_name.has_value())
        j["request_name"] = o.request_name.value();
    if (o.request_username.has_value())
        j["request_username"] = o.request_username.value();
    if (o.request_photo.has_value())
        j["request_photo"] = o.request_photo.value();
}

inline void from_json(const json& j, KeyboardButtonRequestChat& o) {
    o.request_id = j.contains("request_id") && !j.at("request_id").is_null()
        ? j.at("request_id").get<int64_t>() : 0;
    o.chat_is_channel = j.contains("chat_is_channel") && !j.at("chat_is_channel").is_null()
        ? j.at("chat_is_channel").get<bool>() : false;
    if (j.contains("chat_is_forum") && !j.at("chat_is_forum").is_null())
        o.chat_is_forum = j.at("chat_is_forum").get<bool>();
    if (j.contains("chat_has_username") && !j.at("chat_has_username").is_null())
        o.chat_has_username = j.at("chat_has_username").get<bool>();
    if (j.contains("chat_is_created") && !j.at("chat_is_created").is_null())
        o.chat_is_created = j.at("chat_is_created").get<bool>();
    if (j.contains("user_administrator_rights") && !j.at("user_administrator_rights").is_null()) {
        o.user_administrator_rights = std::make_shared<ChatAdministratorRights>();
        from_json(j.at("user_administrator_rights"), *o.user_administrator_rights);
    }
    if (j.contains("bot_administrator_rights") && !j.at("bot_administrator_rights").is_null()) {
        o.bot_administrator_rights = std::make_shared<ChatAdministratorRights>();
        from_json(j.at("bot_administrator_rights"), *o.bot_administrator_rights);
    }
    if (j.contains("bot_is_member") && !j.at("bot_is_member").is_null())
        o.bot_is_member = j.at("bot_is_member").get<bool>();
    if (j.contains("request_title") && !j.at("request_title").is_null())
        o.request_title = j.at("request_title").get<bool>();
    if (j.contains("request_username") && !j.at("request_username").is_null())
        o.request_username = j.at("request_username").get<bool>();
    if (j.contains("request_photo") && !j.at("request_photo").is_null())
        o.request_photo = j.at("request_photo").get<bool>();
}

inline void to_json(json& j, const KeyboardButtonRequestChat& o) {
    j = json::object();
    j["request_id"] = o.request_id;
    j["chat_is_channel"] = o.chat_is_channel;
    if (o.chat_is_forum.has_value())
        j["chat_is_forum"] = o.chat_is_forum.value();
    if (o.chat_has_username.has_value())
        j["chat_has_username"] = o.chat_has_username.value();
    if (o.chat_is_created.has_value())
        j["chat_is_created"] = o.chat_is_created.value();
    if (o.user_administrator_rights) {
        json _sub; to_json(_sub, *o.user_administrator_rights); j["user_administrator_rights"] = std::move(_sub);
    }
    if (o.bot_administrator_rights) {
        json _sub; to_json(_sub, *o.bot_administrator_rights); j["bot_administrator_rights"] = std::move(_sub);
    }
    if (o.bot_is_member.has_value())
        j["bot_is_member"] = o.bot_is_member.value();
    if (o.request_title.has_value())
        j["request_title"] = o.request_title.value();
    if (o.request_username.has_value())
        j["request_username"] = o.request_username.value();
    if (o.request_photo.has_value())
        j["request_photo"] = o.request_photo.value();
}

inline void from_json(const json& j, KeyboardButtonRequestManagedBot& o) {
    o.request_id = j.contains("request_id") && !j.at("request_id").is_null()
        ? j.at("request_id").get<int64_t>() : 0;
    if (j.contains("suggested_name") && !j.at("suggested_name").is_null())
        o.suggested_name = j.at("suggested_name").get<std::string>();
    if (j.contains("suggested_username") && !j.at("suggested_username").is_null())
        o.suggested_username = j.at("suggested_username").get<std::string>();
}

inline void to_json(json& j, const KeyboardButtonRequestManagedBot& o) {
    j = json::object();
    j["request_id"] = o.request_id;
    if (o.suggested_name.has_value())
        j["suggested_name"] = o.suggested_name.value();
    if (o.suggested_username.has_value())
        j["suggested_username"] = o.suggested_username.value();
}

inline void from_json(const json& j, KeyboardButtonPollType& o) {
    if (j.contains("type") && !j.at("type").is_null())
        o.type = j.at("type").get<std::string>();
}

inline void to_json(json& j, const KeyboardButtonPollType& o) {
    j = json::object();
    if (o.type.has_value())
        j["type"] = o.type.value();
}

inline void from_json(const json& j, ReplyKeyboardRemove& o) {
    o.remove_keyboard = j.contains("remove_keyboard") && !j.at("remove_keyboard").is_null()
        ? j.at("remove_keyboard").get<bool>() : false;
    if (j.contains("selective") && !j.at("selective").is_null())
        o.selective = j.at("selective").get<bool>();
}

inline void to_json(json& j, const ReplyKeyboardRemove& o) {
    j = json::object();
    j["remove_keyboard"] = o.remove_keyboard;
    if (o.selective.has_value())
        j["selective"] = o.selective.value();
}

inline void from_json(const json& j, InlineKeyboardMarkup& o) {
    if (j.contains("inline_keyboard") && j.at("inline_keyboard").is_array()) {
        for (const auto& _item : j.at("inline_keyboard")) {
            std::vector<std::shared_ptr<InlineKeyboardButton>> _sv_item;
            if (_item.is_array()) {
                for (const auto& _si_item : _item) {
                    {
                        auto _elem = std::make_shared<InlineKeyboardButton>();
                        from_json(_si_item, *_elem);
                        _sv_item.push_back(std::move(_elem));
                    }
                }
            }
            o.inline_keyboard.push_back(std::move(_sv_item));
        }
    }
}

inline void to_json(json& j, const InlineKeyboardMarkup& o) {
    j = json::object();
    {
        json _arr = json::array();
        for (const auto& _item : o.inline_keyboard) {
            {
                json _ia_item = json::array();
                for (const auto& _ii_item : _item) {
                    {
                        json _e; to_json(_e, *_ii_item); _ia_item.push_back(std::move(_e));
                    }
                }
                _arr.push_back(std::move(_ia_item));
            }
        }
        j["inline_keyboard"] = std::move(_arr);
    }
}

inline void from_json(const json& j, InlineKeyboardButton& o) {
    o.text = j.contains("text") && !j.at("text").is_null()
        ? j.at("text").get<std::string>() : "";
    if (j.contains("icon_custom_emoji_id") && !j.at("icon_custom_emoji_id").is_null())
        o.icon_custom_emoji_id = j.at("icon_custom_emoji_id").get<std::string>();
    if (j.contains("style") && !j.at("style").is_null())
        o.style = j.at("style").get<std::string>();
    if (j.contains("url") && !j.at("url").is_null())
        o.url = j.at("url").get<std::string>();
    if (j.contains("callback_data") && !j.at("callback_data").is_null())
        o.callback_data = j.at("callback_data").get<std::string>();
    if (j.contains("web_app") && !j.at("web_app").is_null()) {
        o.web_app = std::make_shared<WebAppInfo>();
        from_json(j.at("web_app"), *o.web_app);
    }
    if (j.contains("login_url") && !j.at("login_url").is_null()) {
        o.login_url = std::make_shared<LoginUrl>();
        from_json(j.at("login_url"), *o.login_url);
    }
    if (j.contains("switch_inline_query") && !j.at("switch_inline_query").is_null())
        o.switch_inline_query = j.at("switch_inline_query").get<std::string>();
    if (j.contains("switch_inline_query_current_chat") && !j.at("switch_inline_query_current_chat").is_null())
        o.switch_inline_query_current_chat = j.at("switch_inline_query_current_chat").get<std::string>();
    if (j.contains("switch_inline_query_chosen_chat") && !j.at("switch_inline_query_chosen_chat").is_null()) {
        o.switch_inline_query_chosen_chat = std::make_shared<SwitchInlineQueryChosenChat>();
        from_json(j.at("switch_inline_query_chosen_chat"), *o.switch_inline_query_chosen_chat);
    }
    if (j.contains("copy_text") && !j.at("copy_text").is_null()) {
        o.copy_text = std::make_shared<CopyTextButton>();
        from_json(j.at("copy_text"), *o.copy_text);
    }
    if (j.contains("callback_game") && !j.at("callback_game").is_null()) {
        o.callback_game = std::make_shared<CallbackGame>();
        from_json(j.at("callback_game"), *o.callback_game);
    }
    if (j.contains("pay") && !j.at("pay").is_null())
        o.pay = j.at("pay").get<bool>();
}

inline void to_json(json& j, const InlineKeyboardButton& o) {
    j = json::object();
    j["text"] = o.text;
    if (o.icon_custom_emoji_id.has_value())
        j["icon_custom_emoji_id"] = o.icon_custom_emoji_id.value();
    if (o.style.has_value())
        j["style"] = o.style.value();
    if (o.url.has_value())
        j["url"] = o.url.value();
    if (o.callback_data.has_value())
        j["callback_data"] = o.callback_data.value();
    if (o.web_app) {
        json _sub; to_json(_sub, *o.web_app); j["web_app"] = std::move(_sub);
    }
    if (o.login_url) {
        json _sub; to_json(_sub, *o.login_url); j["login_url"] = std::move(_sub);
    }
    if (o.switch_inline_query.has_value())
        j["switch_inline_query"] = o.switch_inline_query.value();
    if (o.switch_inline_query_current_chat.has_value())
        j["switch_inline_query_current_chat"] = o.switch_inline_query_current_chat.value();
    if (o.switch_inline_query_chosen_chat) {
        json _sub; to_json(_sub, *o.switch_inline_query_chosen_chat); j["switch_inline_query_chosen_chat"] = std::move(_sub);
    }
    if (o.copy_text) {
        json _sub; to_json(_sub, *o.copy_text); j["copy_text"] = std::move(_sub);
    }
    if (o.callback_game) {
        json _sub; to_json(_sub, *o.callback_game); j["callback_game"] = std::move(_sub);
    }
    if (o.pay.has_value())
        j["pay"] = o.pay.value();
}

inline void from_json(const json& j, LoginUrl& o) {
    o.url = j.contains("url") && !j.at("url").is_null()
        ? j.at("url").get<std::string>() : "";
    if (j.contains("forward_text") && !j.at("forward_text").is_null())
        o.forward_text = j.at("forward_text").get<std::string>();
    if (j.contains("bot_username") && !j.at("bot_username").is_null())
        o.bot_username = j.at("bot_username").get<std::string>();
    if (j.contains("request_write_access") && !j.at("request_write_access").is_null())
        o.request_write_access = j.at("request_write_access").get<bool>();
}

inline void to_json(json& j, const LoginUrl& o) {
    j = json::object();
    j["url"] = o.url;
    if (o.forward_text.has_value())
        j["forward_text"] = o.forward_text.value();
    if (o.bot_username.has_value())
        j["bot_username"] = o.bot_username.value();
    if (o.request_write_access.has_value())
        j["request_write_access"] = o.request_write_access.value();
}

inline void from_json(const json& j, SwitchInlineQueryChosenChat& o) {
    if (j.contains("query") && !j.at("query").is_null())
        o.query = j.at("query").get<std::string>();
    if (j.contains("allow_user_chats") && !j.at("allow_user_chats").is_null())
        o.allow_user_chats = j.at("allow_user_chats").get<bool>();
    if (j.contains("allow_bot_chats") && !j.at("allow_bot_chats").is_null())
        o.allow_bot_chats = j.at("allow_bot_chats").get<bool>();
    if (j.contains("allow_group_chats") && !j.at("allow_group_chats").is_null())
        o.allow_group_chats = j.at("allow_group_chats").get<bool>();
    if (j.contains("allow_channel_chats") && !j.at("allow_channel_chats").is_null())
        o.allow_channel_chats = j.at("allow_channel_chats").get<bool>();
}

inline void to_json(json& j, const SwitchInlineQueryChosenChat& o) {
    j = json::object();
    if (o.query.has_value())
        j["query"] = o.query.value();
    if (o.allow_user_chats.has_value())
        j["allow_user_chats"] = o.allow_user_chats.value();
    if (o.allow_bot_chats.has_value())
        j["allow_bot_chats"] = o.allow_bot_chats.value();
    if (o.allow_group_chats.has_value())
        j["allow_group_chats"] = o.allow_group_chats.value();
    if (o.allow_channel_chats.has_value())
        j["allow_channel_chats"] = o.allow_channel_chats.value();
}

inline void from_json(const json& j, CopyTextButton& o) {
    o.text = j.contains("text") && !j.at("text").is_null()
        ? j.at("text").get<std::string>() : "";
}

inline void to_json(json& j, const CopyTextButton& o) {
    j = json::object();
    j["text"] = o.text;
}

inline void from_json(const json& j, CallbackQuery& o) {
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    if (j.contains("from") && !j.at("from").is_null()) {
        o.from = std::make_shared<User>();
        from_json(j.at("from"), *o.from);
    }
    if (j.contains("message") && !j.at("message").is_null()) {
        MaybeInaccessibleMessage _tmp{};
        from_json(j.at("message"), _tmp);
        o.message = std::move(_tmp);
    }
    if (j.contains("inline_message_id") && !j.at("inline_message_id").is_null())
        o.inline_message_id = j.at("inline_message_id").get<std::string>();
    o.chat_instance = j.contains("chat_instance") && !j.at("chat_instance").is_null()
        ? j.at("chat_instance").get<std::string>() : "";
    if (j.contains("data") && !j.at("data").is_null())
        o.data = j.at("data").get<std::string>();
    if (j.contains("game_short_name") && !j.at("game_short_name").is_null())
        o.game_short_name = j.at("game_short_name").get<std::string>();
}

inline void to_json(json& j, const CallbackQuery& o) {
    j = json::object();
    j["id"] = o.id;
    {
        json _sub; to_json(_sub, *o.from); j["from"] = std::move(_sub);
    }
    if (o.message.has_value()) {
        json _sub;
        to_json(_sub, o.message.value());
        j["message"] = std::move(_sub);
    }
    if (o.inline_message_id.has_value())
        j["inline_message_id"] = o.inline_message_id.value();
    j["chat_instance"] = o.chat_instance;
    if (o.data.has_value())
        j["data"] = o.data.value();
    if (o.game_short_name.has_value())
        j["game_short_name"] = o.game_short_name.value();
}

inline void from_json(const json& j, ForceReply& o) {
    o.force_reply = j.contains("force_reply") && !j.at("force_reply").is_null()
        ? j.at("force_reply").get<bool>() : false;
    if (j.contains("input_field_placeholder") && !j.at("input_field_placeholder").is_null())
        o.input_field_placeholder = j.at("input_field_placeholder").get<std::string>();
    if (j.contains("selective") && !j.at("selective").is_null())
        o.selective = j.at("selective").get<bool>();
}

inline void to_json(json& j, const ForceReply& o) {
    j = json::object();
    j["force_reply"] = o.force_reply;
    if (o.input_field_placeholder.has_value())
        j["input_field_placeholder"] = o.input_field_placeholder.value();
    if (o.selective.has_value())
        j["selective"] = o.selective.value();
}

inline void from_json(const json& j, ChatPhoto& o) {
    o.small_file_id = j.contains("small_file_id") && !j.at("small_file_id").is_null()
        ? j.at("small_file_id").get<std::string>() : "";
    o.small_file_unique_id = j.contains("small_file_unique_id") && !j.at("small_file_unique_id").is_null()
        ? j.at("small_file_unique_id").get<std::string>() : "";
    o.big_file_id = j.contains("big_file_id") && !j.at("big_file_id").is_null()
        ? j.at("big_file_id").get<std::string>() : "";
    o.big_file_unique_id = j.contains("big_file_unique_id") && !j.at("big_file_unique_id").is_null()
        ? j.at("big_file_unique_id").get<std::string>() : "";
}

inline void to_json(json& j, const ChatPhoto& o) {
    j = json::object();
    j["small_file_id"] = o.small_file_id;
    j["small_file_unique_id"] = o.small_file_unique_id;
    j["big_file_id"] = o.big_file_id;
    j["big_file_unique_id"] = o.big_file_unique_id;
}

inline void from_json(const json& j, ChatInviteLink& o) {
    o.invite_link = j.contains("invite_link") && !j.at("invite_link").is_null()
        ? j.at("invite_link").get<std::string>() : "";
    if (j.contains("creator") && !j.at("creator").is_null()) {
        o.creator = std::make_shared<User>();
        from_json(j.at("creator"), *o.creator);
    }
    o.creates_join_request = j.contains("creates_join_request") && !j.at("creates_join_request").is_null()
        ? j.at("creates_join_request").get<bool>() : false;
    o.is_primary = j.contains("is_primary") && !j.at("is_primary").is_null()
        ? j.at("is_primary").get<bool>() : false;
    o.is_revoked = j.contains("is_revoked") && !j.at("is_revoked").is_null()
        ? j.at("is_revoked").get<bool>() : false;
    if (j.contains("name") && !j.at("name").is_null())
        o.name = j.at("name").get<std::string>();
    if (j.contains("expire_date") && !j.at("expire_date").is_null())
        o.expire_date = j.at("expire_date").get<int64_t>();
    if (j.contains("member_limit") && !j.at("member_limit").is_null())
        o.member_limit = j.at("member_limit").get<int64_t>();
    if (j.contains("pending_join_request_count") && !j.at("pending_join_request_count").is_null())
        o.pending_join_request_count = j.at("pending_join_request_count").get<int64_t>();
    if (j.contains("subscription_period") && !j.at("subscription_period").is_null())
        o.subscription_period = j.at("subscription_period").get<int64_t>();
    if (j.contains("subscription_price") && !j.at("subscription_price").is_null())
        o.subscription_price = j.at("subscription_price").get<int64_t>();
}

inline void to_json(json& j, const ChatInviteLink& o) {
    j = json::object();
    j["invite_link"] = o.invite_link;
    {
        json _sub; to_json(_sub, *o.creator); j["creator"] = std::move(_sub);
    }
    j["creates_join_request"] = o.creates_join_request;
    j["is_primary"] = o.is_primary;
    j["is_revoked"] = o.is_revoked;
    if (o.name.has_value())
        j["name"] = o.name.value();
    if (o.expire_date.has_value())
        j["expire_date"] = o.expire_date.value();
    if (o.member_limit.has_value())
        j["member_limit"] = o.member_limit.value();
    if (o.pending_join_request_count.has_value())
        j["pending_join_request_count"] = o.pending_join_request_count.value();
    if (o.subscription_period.has_value())
        j["subscription_period"] = o.subscription_period.value();
    if (o.subscription_price.has_value())
        j["subscription_price"] = o.subscription_price.value();
}

inline void from_json(const json& j, ChatAdministratorRights& o) {
    o.is_anonymous = j.contains("is_anonymous") && !j.at("is_anonymous").is_null()
        ? j.at("is_anonymous").get<bool>() : false;
    o.can_manage_chat = j.contains("can_manage_chat") && !j.at("can_manage_chat").is_null()
        ? j.at("can_manage_chat").get<bool>() : false;
    o.can_delete_messages = j.contains("can_delete_messages") && !j.at("can_delete_messages").is_null()
        ? j.at("can_delete_messages").get<bool>() : false;
    o.can_manage_video_chats = j.contains("can_manage_video_chats") && !j.at("can_manage_video_chats").is_null()
        ? j.at("can_manage_video_chats").get<bool>() : false;
    o.can_restrict_members = j.contains("can_restrict_members") && !j.at("can_restrict_members").is_null()
        ? j.at("can_restrict_members").get<bool>() : false;
    o.can_promote_members = j.contains("can_promote_members") && !j.at("can_promote_members").is_null()
        ? j.at("can_promote_members").get<bool>() : false;
    o.can_change_info = j.contains("can_change_info") && !j.at("can_change_info").is_null()
        ? j.at("can_change_info").get<bool>() : false;
    o.can_invite_users = j.contains("can_invite_users") && !j.at("can_invite_users").is_null()
        ? j.at("can_invite_users").get<bool>() : false;
    o.can_post_stories = j.contains("can_post_stories") && !j.at("can_post_stories").is_null()
        ? j.at("can_post_stories").get<bool>() : false;
    o.can_edit_stories = j.contains("can_edit_stories") && !j.at("can_edit_stories").is_null()
        ? j.at("can_edit_stories").get<bool>() : false;
    o.can_delete_stories = j.contains("can_delete_stories") && !j.at("can_delete_stories").is_null()
        ? j.at("can_delete_stories").get<bool>() : false;
    if (j.contains("can_post_messages") && !j.at("can_post_messages").is_null())
        o.can_post_messages = j.at("can_post_messages").get<bool>();
    if (j.contains("can_edit_messages") && !j.at("can_edit_messages").is_null())
        o.can_edit_messages = j.at("can_edit_messages").get<bool>();
    if (j.contains("can_pin_messages") && !j.at("can_pin_messages").is_null())
        o.can_pin_messages = j.at("can_pin_messages").get<bool>();
    if (j.contains("can_manage_topics") && !j.at("can_manage_topics").is_null())
        o.can_manage_topics = j.at("can_manage_topics").get<bool>();
    if (j.contains("can_manage_direct_messages") && !j.at("can_manage_direct_messages").is_null())
        o.can_manage_direct_messages = j.at("can_manage_direct_messages").get<bool>();
    if (j.contains("can_manage_tags") && !j.at("can_manage_tags").is_null())
        o.can_manage_tags = j.at("can_manage_tags").get<bool>();
}

inline void to_json(json& j, const ChatAdministratorRights& o) {
    j = json::object();
    j["is_anonymous"] = o.is_anonymous;
    j["can_manage_chat"] = o.can_manage_chat;
    j["can_delete_messages"] = o.can_delete_messages;
    j["can_manage_video_chats"] = o.can_manage_video_chats;
    j["can_restrict_members"] = o.can_restrict_members;
    j["can_promote_members"] = o.can_promote_members;
    j["can_change_info"] = o.can_change_info;
    j["can_invite_users"] = o.can_invite_users;
    j["can_post_stories"] = o.can_post_stories;
    j["can_edit_stories"] = o.can_edit_stories;
    j["can_delete_stories"] = o.can_delete_stories;
    if (o.can_post_messages.has_value())
        j["can_post_messages"] = o.can_post_messages.value();
    if (o.can_edit_messages.has_value())
        j["can_edit_messages"] = o.can_edit_messages.value();
    if (o.can_pin_messages.has_value())
        j["can_pin_messages"] = o.can_pin_messages.value();
    if (o.can_manage_topics.has_value())
        j["can_manage_topics"] = o.can_manage_topics.value();
    if (o.can_manage_direct_messages.has_value())
        j["can_manage_direct_messages"] = o.can_manage_direct_messages.value();
    if (o.can_manage_tags.has_value())
        j["can_manage_tags"] = o.can_manage_tags.value();
}

inline void from_json(const json& j, ChatMemberUpdated& o) {
    if (j.contains("chat") && !j.at("chat").is_null()) {
        o.chat = std::make_shared<Chat>();
        from_json(j.at("chat"), *o.chat);
    }
    if (j.contains("from") && !j.at("from").is_null()) {
        o.from = std::make_shared<User>();
        from_json(j.at("from"), *o.from);
    }
    o.date = j.contains("date") && !j.at("date").is_null()
        ? j.at("date").get<int64_t>() : 0;
    if (j.contains("old_chat_member") && !j.at("old_chat_member").is_null()) {
        from_json(j.at("old_chat_member"), o.old_chat_member);
    }
    if (j.contains("new_chat_member") && !j.at("new_chat_member").is_null()) {
        from_json(j.at("new_chat_member"), o.new_chat_member);
    }
    if (j.contains("invite_link") && !j.at("invite_link").is_null()) {
        o.invite_link = std::make_shared<ChatInviteLink>();
        from_json(j.at("invite_link"), *o.invite_link);
    }
    if (j.contains("via_join_request") && !j.at("via_join_request").is_null())
        o.via_join_request = j.at("via_join_request").get<bool>();
    if (j.contains("via_chat_folder_invite_link") && !j.at("via_chat_folder_invite_link").is_null())
        o.via_chat_folder_invite_link = j.at("via_chat_folder_invite_link").get<bool>();
}

inline void to_json(json& j, const ChatMemberUpdated& o) {
    j = json::object();
    {
        json _sub; to_json(_sub, *o.chat); j["chat"] = std::move(_sub);
    }
    {
        json _sub; to_json(_sub, *o.from); j["from"] = std::move(_sub);
    }
    j["date"] = o.date;
    {
        json _sub;
        to_json(_sub, o.old_chat_member);
        j["old_chat_member"] = std::move(_sub);
    }
    {
        json _sub;
        to_json(_sub, o.new_chat_member);
        j["new_chat_member"] = std::move(_sub);
    }
    if (o.invite_link) {
        json _sub; to_json(_sub, *o.invite_link); j["invite_link"] = std::move(_sub);
    }
    if (o.via_join_request.has_value())
        j["via_join_request"] = o.via_join_request.value();
    if (o.via_chat_folder_invite_link.has_value())
        j["via_chat_folder_invite_link"] = o.via_chat_folder_invite_link.value();
}

inline void from_json(const json& j, ChatMember& v) {
    std::string type = j.at("status").get<std::string>();
    if (type == "creator") {
        auto obj = std::make_shared<ChatMemberOwner>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "administrator") {
        auto obj = std::make_shared<ChatMemberAdministrator>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "member") {
        auto obj = std::make_shared<ChatMemberMember>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "restricted") {
        auto obj = std::make_shared<ChatMemberRestricted>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "left") {
        auto obj = std::make_shared<ChatMemberLeft>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "kicked") {
        auto obj = std::make_shared<ChatMemberBanned>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const ChatMember& v) {
    if (auto* p = std::get_if <std::shared_ptr<ChatMemberOwner>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<ChatMemberAdministrator>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<ChatMemberMember>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<ChatMemberRestricted>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<ChatMemberLeft>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<ChatMemberBanned>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, ChatMemberOwner& o) {
    o.status = j.contains("status") && !j.at("status").is_null()
        ? j.at("status").get<std::string>() : "";
    if (j.contains("user") && !j.at("user").is_null()) {
        o.user = std::make_shared<User>();
        from_json(j.at("user"), *o.user);
    }
    o.is_anonymous = j.contains("is_anonymous") && !j.at("is_anonymous").is_null()
        ? j.at("is_anonymous").get<bool>() : false;
    if (j.contains("custom_title") && !j.at("custom_title").is_null())
        o.custom_title = j.at("custom_title").get<std::string>();
}

inline void to_json(json& j, const ChatMemberOwner& o) {
    j = json::object();
    j["status"] = o.status;
    {
        json _sub; to_json(_sub, *o.user); j["user"] = std::move(_sub);
    }
    j["is_anonymous"] = o.is_anonymous;
    if (o.custom_title.has_value())
        j["custom_title"] = o.custom_title.value();
}

inline void from_json(const json& j, ChatMemberAdministrator& o) {
    o.status = j.contains("status") && !j.at("status").is_null()
        ? j.at("status").get<std::string>() : "";
    if (j.contains("user") && !j.at("user").is_null()) {
        o.user = std::make_shared<User>();
        from_json(j.at("user"), *o.user);
    }
    o.can_be_edited = j.contains("can_be_edited") && !j.at("can_be_edited").is_null()
        ? j.at("can_be_edited").get<bool>() : false;
    o.is_anonymous = j.contains("is_anonymous") && !j.at("is_anonymous").is_null()
        ? j.at("is_anonymous").get<bool>() : false;
    o.can_manage_chat = j.contains("can_manage_chat") && !j.at("can_manage_chat").is_null()
        ? j.at("can_manage_chat").get<bool>() : false;
    o.can_delete_messages = j.contains("can_delete_messages") && !j.at("can_delete_messages").is_null()
        ? j.at("can_delete_messages").get<bool>() : false;
    o.can_manage_video_chats = j.contains("can_manage_video_chats") && !j.at("can_manage_video_chats").is_null()
        ? j.at("can_manage_video_chats").get<bool>() : false;
    o.can_restrict_members = j.contains("can_restrict_members") && !j.at("can_restrict_members").is_null()
        ? j.at("can_restrict_members").get<bool>() : false;
    o.can_promote_members = j.contains("can_promote_members") && !j.at("can_promote_members").is_null()
        ? j.at("can_promote_members").get<bool>() : false;
    o.can_change_info = j.contains("can_change_info") && !j.at("can_change_info").is_null()
        ? j.at("can_change_info").get<bool>() : false;
    o.can_invite_users = j.contains("can_invite_users") && !j.at("can_invite_users").is_null()
        ? j.at("can_invite_users").get<bool>() : false;
    o.can_post_stories = j.contains("can_post_stories") && !j.at("can_post_stories").is_null()
        ? j.at("can_post_stories").get<bool>() : false;
    o.can_edit_stories = j.contains("can_edit_stories") && !j.at("can_edit_stories").is_null()
        ? j.at("can_edit_stories").get<bool>() : false;
    o.can_delete_stories = j.contains("can_delete_stories") && !j.at("can_delete_stories").is_null()
        ? j.at("can_delete_stories").get<bool>() : false;
    if (j.contains("can_post_messages") && !j.at("can_post_messages").is_null())
        o.can_post_messages = j.at("can_post_messages").get<bool>();
    if (j.contains("can_edit_messages") && !j.at("can_edit_messages").is_null())
        o.can_edit_messages = j.at("can_edit_messages").get<bool>();
    if (j.contains("can_pin_messages") && !j.at("can_pin_messages").is_null())
        o.can_pin_messages = j.at("can_pin_messages").get<bool>();
    if (j.contains("can_manage_topics") && !j.at("can_manage_topics").is_null())
        o.can_manage_topics = j.at("can_manage_topics").get<bool>();
    if (j.contains("can_manage_direct_messages") && !j.at("can_manage_direct_messages").is_null())
        o.can_manage_direct_messages = j.at("can_manage_direct_messages").get<bool>();
    if (j.contains("can_manage_tags") && !j.at("can_manage_tags").is_null())
        o.can_manage_tags = j.at("can_manage_tags").get<bool>();
    if (j.contains("custom_title") && !j.at("custom_title").is_null())
        o.custom_title = j.at("custom_title").get<std::string>();
}

inline void to_json(json& j, const ChatMemberAdministrator& o) {
    j = json::object();
    j["status"] = o.status;
    {
        json _sub; to_json(_sub, *o.user); j["user"] = std::move(_sub);
    }
    j["can_be_edited"] = o.can_be_edited;
    j["is_anonymous"] = o.is_anonymous;
    j["can_manage_chat"] = o.can_manage_chat;
    j["can_delete_messages"] = o.can_delete_messages;
    j["can_manage_video_chats"] = o.can_manage_video_chats;
    j["can_restrict_members"] = o.can_restrict_members;
    j["can_promote_members"] = o.can_promote_members;
    j["can_change_info"] = o.can_change_info;
    j["can_invite_users"] = o.can_invite_users;
    j["can_post_stories"] = o.can_post_stories;
    j["can_edit_stories"] = o.can_edit_stories;
    j["can_delete_stories"] = o.can_delete_stories;
    if (o.can_post_messages.has_value())
        j["can_post_messages"] = o.can_post_messages.value();
    if (o.can_edit_messages.has_value())
        j["can_edit_messages"] = o.can_edit_messages.value();
    if (o.can_pin_messages.has_value())
        j["can_pin_messages"] = o.can_pin_messages.value();
    if (o.can_manage_topics.has_value())
        j["can_manage_topics"] = o.can_manage_topics.value();
    if (o.can_manage_direct_messages.has_value())
        j["can_manage_direct_messages"] = o.can_manage_direct_messages.value();
    if (o.can_manage_tags.has_value())
        j["can_manage_tags"] = o.can_manage_tags.value();
    if (o.custom_title.has_value())
        j["custom_title"] = o.custom_title.value();
}

inline void from_json(const json& j, ChatMemberMember& o) {
    o.status = j.contains("status") && !j.at("status").is_null()
        ? j.at("status").get<std::string>() : "";
    if (j.contains("tag") && !j.at("tag").is_null())
        o.tag = j.at("tag").get<std::string>();
    if (j.contains("user") && !j.at("user").is_null()) {
        o.user = std::make_shared<User>();
        from_json(j.at("user"), *o.user);
    }
    if (j.contains("until_date") && !j.at("until_date").is_null())
        o.until_date = j.at("until_date").get<int64_t>();
}

inline void to_json(json& j, const ChatMemberMember& o) {
    j = json::object();
    j["status"] = o.status;
    if (o.tag.has_value())
        j["tag"] = o.tag.value();
    {
        json _sub; to_json(_sub, *o.user); j["user"] = std::move(_sub);
    }
    if (o.until_date.has_value())
        j["until_date"] = o.until_date.value();
}

inline void from_json(const json& j, ChatMemberRestricted& o) {
    o.status = j.contains("status") && !j.at("status").is_null()
        ? j.at("status").get<std::string>() : "";
    if (j.contains("tag") && !j.at("tag").is_null())
        o.tag = j.at("tag").get<std::string>();
    if (j.contains("user") && !j.at("user").is_null()) {
        o.user = std::make_shared<User>();
        from_json(j.at("user"), *o.user);
    }
    o.is_member = j.contains("is_member") && !j.at("is_member").is_null()
        ? j.at("is_member").get<bool>() : false;
    o.can_send_messages = j.contains("can_send_messages") && !j.at("can_send_messages").is_null()
        ? j.at("can_send_messages").get<bool>() : false;
    o.can_send_audios = j.contains("can_send_audios") && !j.at("can_send_audios").is_null()
        ? j.at("can_send_audios").get<bool>() : false;
    o.can_send_documents = j.contains("can_send_documents") && !j.at("can_send_documents").is_null()
        ? j.at("can_send_documents").get<bool>() : false;
    o.can_send_photos = j.contains("can_send_photos") && !j.at("can_send_photos").is_null()
        ? j.at("can_send_photos").get<bool>() : false;
    o.can_send_videos = j.contains("can_send_videos") && !j.at("can_send_videos").is_null()
        ? j.at("can_send_videos").get<bool>() : false;
    o.can_send_video_notes = j.contains("can_send_video_notes") && !j.at("can_send_video_notes").is_null()
        ? j.at("can_send_video_notes").get<bool>() : false;
    o.can_send_voice_notes = j.contains("can_send_voice_notes") && !j.at("can_send_voice_notes").is_null()
        ? j.at("can_send_voice_notes").get<bool>() : false;
    o.can_send_polls = j.contains("can_send_polls") && !j.at("can_send_polls").is_null()
        ? j.at("can_send_polls").get<bool>() : false;
    o.can_send_other_messages = j.contains("can_send_other_messages") && !j.at("can_send_other_messages").is_null()
        ? j.at("can_send_other_messages").get<bool>() : false;
    o.can_add_web_page_previews = j.contains("can_add_web_page_previews") && !j.at("can_add_web_page_previews").is_null()
        ? j.at("can_add_web_page_previews").get<bool>() : false;
    o.can_react_to_messages = j.contains("can_react_to_messages") && !j.at("can_react_to_messages").is_null()
        ? j.at("can_react_to_messages").get<bool>() : false;
    o.can_edit_tag = j.contains("can_edit_tag") && !j.at("can_edit_tag").is_null()
        ? j.at("can_edit_tag").get<bool>() : false;
    o.can_change_info = j.contains("can_change_info") && !j.at("can_change_info").is_null()
        ? j.at("can_change_info").get<bool>() : false;
    o.can_invite_users = j.contains("can_invite_users") && !j.at("can_invite_users").is_null()
        ? j.at("can_invite_users").get<bool>() : false;
    o.can_pin_messages = j.contains("can_pin_messages") && !j.at("can_pin_messages").is_null()
        ? j.at("can_pin_messages").get<bool>() : false;
    o.can_manage_topics = j.contains("can_manage_topics") && !j.at("can_manage_topics").is_null()
        ? j.at("can_manage_topics").get<bool>() : false;
    o.until_date = j.contains("until_date") && !j.at("until_date").is_null()
        ? j.at("until_date").get<int64_t>() : 0;
}

inline void to_json(json& j, const ChatMemberRestricted& o) {
    j = json::object();
    j["status"] = o.status;
    if (o.tag.has_value())
        j["tag"] = o.tag.value();
    {
        json _sub; to_json(_sub, *o.user); j["user"] = std::move(_sub);
    }
    j["is_member"] = o.is_member;
    j["can_send_messages"] = o.can_send_messages;
    j["can_send_audios"] = o.can_send_audios;
    j["can_send_documents"] = o.can_send_documents;
    j["can_send_photos"] = o.can_send_photos;
    j["can_send_videos"] = o.can_send_videos;
    j["can_send_video_notes"] = o.can_send_video_notes;
    j["can_send_voice_notes"] = o.can_send_voice_notes;
    j["can_send_polls"] = o.can_send_polls;
    j["can_send_other_messages"] = o.can_send_other_messages;
    j["can_add_web_page_previews"] = o.can_add_web_page_previews;
    j["can_react_to_messages"] = o.can_react_to_messages;
    j["can_edit_tag"] = o.can_edit_tag;
    j["can_change_info"] = o.can_change_info;
    j["can_invite_users"] = o.can_invite_users;
    j["can_pin_messages"] = o.can_pin_messages;
    j["can_manage_topics"] = o.can_manage_topics;
    j["until_date"] = o.until_date;
}

inline void from_json(const json& j, ChatMemberLeft& o) {
    o.status = j.contains("status") && !j.at("status").is_null()
        ? j.at("status").get<std::string>() : "";
    if (j.contains("user") && !j.at("user").is_null()) {
        o.user = std::make_shared<User>();
        from_json(j.at("user"), *o.user);
    }
}

inline void to_json(json& j, const ChatMemberLeft& o) {
    j = json::object();
    j["status"] = o.status;
    {
        json _sub; to_json(_sub, *o.user); j["user"] = std::move(_sub);
    }
}

inline void from_json(const json& j, ChatMemberBanned& o) {
    o.status = j.contains("status") && !j.at("status").is_null()
        ? j.at("status").get<std::string>() : "";
    if (j.contains("user") && !j.at("user").is_null()) {
        o.user = std::make_shared<User>();
        from_json(j.at("user"), *o.user);
    }
    o.until_date = j.contains("until_date") && !j.at("until_date").is_null()
        ? j.at("until_date").get<int64_t>() : 0;
}

inline void to_json(json& j, const ChatMemberBanned& o) {
    j = json::object();
    j["status"] = o.status;
    {
        json _sub; to_json(_sub, *o.user); j["user"] = std::move(_sub);
    }
    j["until_date"] = o.until_date;
}

inline void from_json(const json& j, ChatJoinRequest& o) {
    if (j.contains("chat") && !j.at("chat").is_null()) {
        o.chat = std::make_shared<Chat>();
        from_json(j.at("chat"), *o.chat);
    }
    if (j.contains("from") && !j.at("from").is_null()) {
        o.from = std::make_shared<User>();
        from_json(j.at("from"), *o.from);
    }
    o.user_chat_id = j.contains("user_chat_id") && !j.at("user_chat_id").is_null()
        ? j.at("user_chat_id").get<int64_t>() : 0;
    o.date = j.contains("date") && !j.at("date").is_null()
        ? j.at("date").get<int64_t>() : 0;
    if (j.contains("bio") && !j.at("bio").is_null())
        o.bio = j.at("bio").get<std::string>();
    if (j.contains("invite_link") && !j.at("invite_link").is_null()) {
        o.invite_link = std::make_shared<ChatInviteLink>();
        from_json(j.at("invite_link"), *o.invite_link);
    }
}

inline void to_json(json& j, const ChatJoinRequest& o) {
    j = json::object();
    {
        json _sub; to_json(_sub, *o.chat); j["chat"] = std::move(_sub);
    }
    {
        json _sub; to_json(_sub, *o.from); j["from"] = std::move(_sub);
    }
    j["user_chat_id"] = o.user_chat_id;
    j["date"] = o.date;
    if (o.bio.has_value())
        j["bio"] = o.bio.value();
    if (o.invite_link) {
        json _sub; to_json(_sub, *o.invite_link); j["invite_link"] = std::move(_sub);
    }
}

inline void from_json(const json& j, ChatPermissions& o) {
    if (j.contains("can_send_messages") && !j.at("can_send_messages").is_null())
        o.can_send_messages = j.at("can_send_messages").get<bool>();
    if (j.contains("can_send_audios") && !j.at("can_send_audios").is_null())
        o.can_send_audios = j.at("can_send_audios").get<bool>();
    if (j.contains("can_send_documents") && !j.at("can_send_documents").is_null())
        o.can_send_documents = j.at("can_send_documents").get<bool>();
    if (j.contains("can_send_photos") && !j.at("can_send_photos").is_null())
        o.can_send_photos = j.at("can_send_photos").get<bool>();
    if (j.contains("can_send_videos") && !j.at("can_send_videos").is_null())
        o.can_send_videos = j.at("can_send_videos").get<bool>();
    if (j.contains("can_send_video_notes") && !j.at("can_send_video_notes").is_null())
        o.can_send_video_notes = j.at("can_send_video_notes").get<bool>();
    if (j.contains("can_send_voice_notes") && !j.at("can_send_voice_notes").is_null())
        o.can_send_voice_notes = j.at("can_send_voice_notes").get<bool>();
    if (j.contains("can_send_polls") && !j.at("can_send_polls").is_null())
        o.can_send_polls = j.at("can_send_polls").get<bool>();
    if (j.contains("can_send_other_messages") && !j.at("can_send_other_messages").is_null())
        o.can_send_other_messages = j.at("can_send_other_messages").get<bool>();
    if (j.contains("can_add_web_page_previews") && !j.at("can_add_web_page_previews").is_null())
        o.can_add_web_page_previews = j.at("can_add_web_page_previews").get<bool>();
    if (j.contains("can_react_to_messages") && !j.at("can_react_to_messages").is_null())
        o.can_react_to_messages = j.at("can_react_to_messages").get<bool>();
    if (j.contains("can_edit_tag") && !j.at("can_edit_tag").is_null())
        o.can_edit_tag = j.at("can_edit_tag").get<bool>();
    if (j.contains("can_change_info") && !j.at("can_change_info").is_null())
        o.can_change_info = j.at("can_change_info").get<bool>();
    if (j.contains("can_invite_users") && !j.at("can_invite_users").is_null())
        o.can_invite_users = j.at("can_invite_users").get<bool>();
    if (j.contains("can_pin_messages") && !j.at("can_pin_messages").is_null())
        o.can_pin_messages = j.at("can_pin_messages").get<bool>();
    if (j.contains("can_manage_topics") && !j.at("can_manage_topics").is_null())
        o.can_manage_topics = j.at("can_manage_topics").get<bool>();
}

inline void to_json(json& j, const ChatPermissions& o) {
    j = json::object();
    if (o.can_send_messages.has_value())
        j["can_send_messages"] = o.can_send_messages.value();
    if (o.can_send_audios.has_value())
        j["can_send_audios"] = o.can_send_audios.value();
    if (o.can_send_documents.has_value())
        j["can_send_documents"] = o.can_send_documents.value();
    if (o.can_send_photos.has_value())
        j["can_send_photos"] = o.can_send_photos.value();
    if (o.can_send_videos.has_value())
        j["can_send_videos"] = o.can_send_videos.value();
    if (o.can_send_video_notes.has_value())
        j["can_send_video_notes"] = o.can_send_video_notes.value();
    if (o.can_send_voice_notes.has_value())
        j["can_send_voice_notes"] = o.can_send_voice_notes.value();
    if (o.can_send_polls.has_value())
        j["can_send_polls"] = o.can_send_polls.value();
    if (o.can_send_other_messages.has_value())
        j["can_send_other_messages"] = o.can_send_other_messages.value();
    if (o.can_add_web_page_previews.has_value())
        j["can_add_web_page_previews"] = o.can_add_web_page_previews.value();
    if (o.can_react_to_messages.has_value())
        j["can_react_to_messages"] = o.can_react_to_messages.value();
    if (o.can_edit_tag.has_value())
        j["can_edit_tag"] = o.can_edit_tag.value();
    if (o.can_change_info.has_value())
        j["can_change_info"] = o.can_change_info.value();
    if (o.can_invite_users.has_value())
        j["can_invite_users"] = o.can_invite_users.value();
    if (o.can_pin_messages.has_value())
        j["can_pin_messages"] = o.can_pin_messages.value();
    if (o.can_manage_topics.has_value())
        j["can_manage_topics"] = o.can_manage_topics.value();
}

inline void from_json(const json& j, Birthdate& o) {
    o.day = j.contains("day") && !j.at("day").is_null()
        ? j.at("day").get<int64_t>() : 0;
    o.month = j.contains("month") && !j.at("month").is_null()
        ? j.at("month").get<int64_t>() : 0;
    if (j.contains("year") && !j.at("year").is_null())
        o.year = j.at("year").get<int64_t>();
}

inline void to_json(json& j, const Birthdate& o) {
    j = json::object();
    j["day"] = o.day;
    j["month"] = o.month;
    if (o.year.has_value())
        j["year"] = o.year.value();
}

inline void from_json(const json& j, BusinessIntro& o) {
    if (j.contains("title") && !j.at("title").is_null())
        o.title = j.at("title").get<std::string>();
    if (j.contains("message") && !j.at("message").is_null())
        o.message = j.at("message").get<std::string>();
    if (j.contains("sticker") && !j.at("sticker").is_null()) {
        o.sticker = std::make_shared<Sticker>();
        from_json(j.at("sticker"), *o.sticker);
    }
}

inline void to_json(json& j, const BusinessIntro& o) {
    j = json::object();
    if (o.title.has_value())
        j["title"] = o.title.value();
    if (o.message.has_value())
        j["message"] = o.message.value();
    if (o.sticker) {
        json _sub; to_json(_sub, *o.sticker); j["sticker"] = std::move(_sub);
    }
}

inline void from_json(const json& j, BusinessLocation& o) {
    o.address = j.contains("address") && !j.at("address").is_null()
        ? j.at("address").get<std::string>() : "";
    if (j.contains("location") && !j.at("location").is_null()) {
        o.location = std::make_shared<Location>();
        from_json(j.at("location"), *o.location);
    }
}

inline void to_json(json& j, const BusinessLocation& o) {
    j = json::object();
    j["address"] = o.address;
    if (o.location) {
        json _sub; to_json(_sub, *o.location); j["location"] = std::move(_sub);
    }
}

inline void from_json(const json& j, BusinessOpeningHoursInterval& o) {
    o.opening_minute = j.contains("opening_minute") && !j.at("opening_minute").is_null()
        ? j.at("opening_minute").get<int64_t>() : 0;
    o.closing_minute = j.contains("closing_minute") && !j.at("closing_minute").is_null()
        ? j.at("closing_minute").get<int64_t>() : 0;
}

inline void to_json(json& j, const BusinessOpeningHoursInterval& o) {
    j = json::object();
    j["opening_minute"] = o.opening_minute;
    j["closing_minute"] = o.closing_minute;
}

inline void from_json(const json& j, BusinessOpeningHours& o) {
    o.time_zone_name = j.contains("time_zone_name") && !j.at("time_zone_name").is_null()
        ? j.at("time_zone_name").get<std::string>() : "";
    if (j.contains("opening_hours") && j.at("opening_hours").is_array()) {
        for (const auto& _item : j.at("opening_hours")) {
            {
                auto _elem = std::make_shared<BusinessOpeningHoursInterval>();
                from_json(_item, *_elem);
                o.opening_hours.push_back(std::move(_elem));
            }
        }
    }
}

inline void to_json(json& j, const BusinessOpeningHours& o) {
    j = json::object();
    j["time_zone_name"] = o.time_zone_name;
    {
        json _arr = json::array();
        for (const auto& _item : o.opening_hours) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["opening_hours"] = std::move(_arr);
    }
}

inline void from_json(const json& j, UserRating& o) {
    o.level = j.contains("level") && !j.at("level").is_null()
        ? j.at("level").get<int64_t>() : 0;
    o.rating = j.contains("rating") && !j.at("rating").is_null()
        ? j.at("rating").get<int64_t>() : 0;
    o.current_level_rating = j.contains("current_level_rating") && !j.at("current_level_rating").is_null()
        ? j.at("current_level_rating").get<int64_t>() : 0;
    if (j.contains("next_level_rating") && !j.at("next_level_rating").is_null())
        o.next_level_rating = j.at("next_level_rating").get<int64_t>();
}

inline void to_json(json& j, const UserRating& o) {
    j = json::object();
    j["level"] = o.level;
    j["rating"] = o.rating;
    j["current_level_rating"] = o.current_level_rating;
    if (o.next_level_rating.has_value())
        j["next_level_rating"] = o.next_level_rating.value();
}

inline void from_json(const json& j, StoryAreaPosition& o) {
    o.x_percentage = j.contains("x_percentage") && !j.at("x_percentage").is_null()
        ? j.at("x_percentage").get<double>() : 0.0;
    o.y_percentage = j.contains("y_percentage") && !j.at("y_percentage").is_null()
        ? j.at("y_percentage").get<double>() : 0.0;
    o.width_percentage = j.contains("width_percentage") && !j.at("width_percentage").is_null()
        ? j.at("width_percentage").get<double>() : 0.0;
    o.height_percentage = j.contains("height_percentage") && !j.at("height_percentage").is_null()
        ? j.at("height_percentage").get<double>() : 0.0;
    o.rotation_angle = j.contains("rotation_angle") && !j.at("rotation_angle").is_null()
        ? j.at("rotation_angle").get<double>() : 0.0;
    o.corner_radius_percentage = j.contains("corner_radius_percentage") && !j.at("corner_radius_percentage").is_null()
        ? j.at("corner_radius_percentage").get<double>() : 0.0;
}

inline void to_json(json& j, const StoryAreaPosition& o) {
    j = json::object();
    j["x_percentage"] = o.x_percentage;
    j["y_percentage"] = o.y_percentage;
    j["width_percentage"] = o.width_percentage;
    j["height_percentage"] = o.height_percentage;
    j["rotation_angle"] = o.rotation_angle;
    j["corner_radius_percentage"] = o.corner_radius_percentage;
}

inline void from_json(const json& j, LocationAddress& o) {
    o.country_code = j.contains("country_code") && !j.at("country_code").is_null()
        ? j.at("country_code").get<std::string>() : "";
    if (j.contains("state") && !j.at("state").is_null())
        o.state = j.at("state").get<std::string>();
    if (j.contains("city") && !j.at("city").is_null())
        o.city = j.at("city").get<std::string>();
    if (j.contains("street") && !j.at("street").is_null())
        o.street = j.at("street").get<std::string>();
}

inline void to_json(json& j, const LocationAddress& o) {
    j = json::object();
    j["country_code"] = o.country_code;
    if (o.state.has_value())
        j["state"] = o.state.value();
    if (o.city.has_value())
        j["city"] = o.city.value();
    if (o.street.has_value())
        j["street"] = o.street.value();
}

inline void from_json(const json& j, StoryAreaType& v) {
    std::string type = j.at("type").get<std::string>();
    if (type == "location") {
        auto obj = std::make_shared<StoryAreaTypeLocation>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "suggested_reaction") {
        auto obj = std::make_shared<StoryAreaTypeSuggestedReaction>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "link") {
        auto obj = std::make_shared<StoryAreaTypeLink>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "weather") {
        auto obj = std::make_shared<StoryAreaTypeWeather>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "unique_gift") {
        auto obj = std::make_shared<StoryAreaTypeUniqueGift>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const StoryAreaType& v) {
    if (auto* p = std::get_if <std::shared_ptr<StoryAreaTypeLocation>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<StoryAreaTypeSuggestedReaction>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<StoryAreaTypeLink>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<StoryAreaTypeWeather>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<StoryAreaTypeUniqueGift>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, StoryAreaTypeLocation& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.latitude = j.contains("latitude") && !j.at("latitude").is_null()
        ? j.at("latitude").get<double>() : 0.0;
    o.longitude = j.contains("longitude") && !j.at("longitude").is_null()
        ? j.at("longitude").get<double>() : 0.0;
    if (j.contains("address") && !j.at("address").is_null()) {
        o.address = std::make_shared<LocationAddress>();
        from_json(j.at("address"), *o.address);
    }
}

inline void to_json(json& j, const StoryAreaTypeLocation& o) {
    j = json::object();
    j["type"] = o.type;
    j["latitude"] = o.latitude;
    j["longitude"] = o.longitude;
    if (o.address) {
        json _sub; to_json(_sub, *o.address); j["address"] = std::move(_sub);
    }
}

inline void from_json(const json& j, StoryAreaTypeSuggestedReaction& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("reaction_type") && !j.at("reaction_type").is_null()) {
        from_json(j.at("reaction_type"), o.reaction_type);
    }
    if (j.contains("is_dark") && !j.at("is_dark").is_null())
        o.is_dark = j.at("is_dark").get<bool>();
    if (j.contains("is_flipped") && !j.at("is_flipped").is_null())
        o.is_flipped = j.at("is_flipped").get<bool>();
}

inline void to_json(json& j, const StoryAreaTypeSuggestedReaction& o) {
    j = json::object();
    j["type"] = o.type;
    {
        json _sub;
        to_json(_sub, o.reaction_type);
        j["reaction_type"] = std::move(_sub);
    }
    if (o.is_dark.has_value())
        j["is_dark"] = o.is_dark.value();
    if (o.is_flipped.has_value())
        j["is_flipped"] = o.is_flipped.value();
}

inline void from_json(const json& j, StoryAreaTypeLink& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.url = j.contains("url") && !j.at("url").is_null()
        ? j.at("url").get<std::string>() : "";
}

inline void to_json(json& j, const StoryAreaTypeLink& o) {
    j = json::object();
    j["type"] = o.type;
    j["url"] = o.url;
}

inline void from_json(const json& j, StoryAreaTypeWeather& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.temperature = j.contains("temperature") && !j.at("temperature").is_null()
        ? j.at("temperature").get<double>() : 0.0;
    o.emoji = j.contains("emoji") && !j.at("emoji").is_null()
        ? j.at("emoji").get<std::string>() : "";
    o.background_color = j.contains("background_color") && !j.at("background_color").is_null()
        ? j.at("background_color").get<int64_t>() : 0;
}

inline void to_json(json& j, const StoryAreaTypeWeather& o) {
    j = json::object();
    j["type"] = o.type;
    j["temperature"] = o.temperature;
    j["emoji"] = o.emoji;
    j["background_color"] = o.background_color;
}

inline void from_json(const json& j, StoryAreaTypeUniqueGift& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.name = j.contains("name") && !j.at("name").is_null()
        ? j.at("name").get<std::string>() : "";
}

inline void to_json(json& j, const StoryAreaTypeUniqueGift& o) {
    j = json::object();
    j["type"] = o.type;
    j["name"] = o.name;
}

inline void from_json(const json& j, StoryArea& o) {
    if (j.contains("position") && !j.at("position").is_null()) {
        o.position = std::make_shared<StoryAreaPosition>();
        from_json(j.at("position"), *o.position);
    }
    if (j.contains("type") && !j.at("type").is_null()) {
        from_json(j.at("type"), o.type);
    }
}

inline void to_json(json& j, const StoryArea& o) {
    j = json::object();
    {
        json _sub; to_json(_sub, *o.position); j["position"] = std::move(_sub);
    }
    {
        json _sub;
        to_json(_sub, o.type);
        j["type"] = std::move(_sub);
    }
}

inline void from_json(const json& j, ChatLocation& o) {
    if (j.contains("location") && !j.at("location").is_null()) {
        o.location = std::make_shared<Location>();
        from_json(j.at("location"), *o.location);
    }
    o.address = j.contains("address") && !j.at("address").is_null()
        ? j.at("address").get<std::string>() : "";
}

inline void to_json(json& j, const ChatLocation& o) {
    j = json::object();
    {
        json _sub; to_json(_sub, *o.location); j["location"] = std::move(_sub);
    }
    j["address"] = o.address;
}

inline void from_json(const json& j, ReactionType& v) {
    std::string type = j.at("type").get<std::string>();
    if (type == "emoji") {
        auto obj = std::make_shared<ReactionTypeEmoji>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "custom_emoji") {
        auto obj = std::make_shared<ReactionTypeCustomEmoji>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "paid") {
        auto obj = std::make_shared<ReactionTypePaid>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const ReactionType& v) {
    if (auto* p = std::get_if <std::shared_ptr<ReactionTypeEmoji>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<ReactionTypeCustomEmoji>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<ReactionTypePaid>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, ReactionTypeEmoji& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.emoji = j.contains("emoji") && !j.at("emoji").is_null()
        ? j.at("emoji").get<std::string>() : "";
}

inline void to_json(json& j, const ReactionTypeEmoji& o) {
    j = json::object();
    j["type"] = o.type;
    j["emoji"] = o.emoji;
}

inline void from_json(const json& j, ReactionTypeCustomEmoji& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.custom_emoji_id = j.contains("custom_emoji_id") && !j.at("custom_emoji_id").is_null()
        ? j.at("custom_emoji_id").get<std::string>() : "";
}

inline void to_json(json& j, const ReactionTypeCustomEmoji& o) {
    j = json::object();
    j["type"] = o.type;
    j["custom_emoji_id"] = o.custom_emoji_id;
}

inline void from_json(const json& j, ReactionTypePaid& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
}

inline void to_json(json& j, const ReactionTypePaid& o) {
    j = json::object();
    j["type"] = o.type;
}

inline void from_json(const json& j, ReactionCount& o) {
    if (j.contains("type") && !j.at("type").is_null()) {
        from_json(j.at("type"), o.type);
    }
    o.total_count = j.contains("total_count") && !j.at("total_count").is_null()
        ? j.at("total_count").get<int64_t>() : 0;
}

inline void to_json(json& j, const ReactionCount& o) {
    j = json::object();
    {
        json _sub;
        to_json(_sub, o.type);
        j["type"] = std::move(_sub);
    }
    j["total_count"] = o.total_count;
}

inline void from_json(const json& j, MessageReactionUpdated& o) {
    if (j.contains("chat") && !j.at("chat").is_null()) {
        o.chat = std::make_shared<Chat>();
        from_json(j.at("chat"), *o.chat);
    }
    o.message_id = j.contains("message_id") && !j.at("message_id").is_null()
        ? j.at("message_id").get<int64_t>() : 0;
    if (j.contains("user") && !j.at("user").is_null()) {
        o.user = std::make_shared<User>();
        from_json(j.at("user"), *o.user);
    }
    if (j.contains("actor_chat") && !j.at("actor_chat").is_null()) {
        o.actor_chat = std::make_shared<Chat>();
        from_json(j.at("actor_chat"), *o.actor_chat);
    }
    o.date = j.contains("date") && !j.at("date").is_null()
        ? j.at("date").get<int64_t>() : 0;
    if (j.contains("old_reaction") && j.at("old_reaction").is_array()) {
        for (const auto& _item : j.at("old_reaction")) {
            {
                ReactionType _elem{};
                from_json(_item, _elem);
                o.old_reaction.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("new_reaction") && j.at("new_reaction").is_array()) {
        for (const auto& _item : j.at("new_reaction")) {
            {
                ReactionType _elem{};
                from_json(_item, _elem);
                o.new_reaction.push_back(std::move(_elem));
            }
        }
    }
}

inline void to_json(json& j, const MessageReactionUpdated& o) {
    j = json::object();
    {
        json _sub; to_json(_sub, *o.chat); j["chat"] = std::move(_sub);
    }
    j["message_id"] = o.message_id;
    if (o.user) {
        json _sub; to_json(_sub, *o.user); j["user"] = std::move(_sub);
    }
    if (o.actor_chat) {
        json _sub; to_json(_sub, *o.actor_chat); j["actor_chat"] = std::move(_sub);
    }
    j["date"] = o.date;
    {
        json _arr = json::array();
        for (const auto& _item : o.old_reaction) {
            {
                json _e; to_json(_e, _item); _arr.push_back(std::move(_e));
            }
        }
        j["old_reaction"] = std::move(_arr);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.new_reaction) {
            {
                json _e; to_json(_e, _item); _arr.push_back(std::move(_e));
            }
        }
        j["new_reaction"] = std::move(_arr);
    }
}

inline void from_json(const json& j, MessageReactionCountUpdated& o) {
    if (j.contains("chat") && !j.at("chat").is_null()) {
        o.chat = std::make_shared<Chat>();
        from_json(j.at("chat"), *o.chat);
    }
    o.message_id = j.contains("message_id") && !j.at("message_id").is_null()
        ? j.at("message_id").get<int64_t>() : 0;
    o.date = j.contains("date") && !j.at("date").is_null()
        ? j.at("date").get<int64_t>() : 0;
    if (j.contains("reactions") && j.at("reactions").is_array()) {
        for (const auto& _item : j.at("reactions")) {
            {
                auto _elem = std::make_shared<ReactionCount>();
                from_json(_item, *_elem);
                o.reactions.push_back(std::move(_elem));
            }
        }
    }
}

inline void to_json(json& j, const MessageReactionCountUpdated& o) {
    j = json::object();
    {
        json _sub; to_json(_sub, *o.chat); j["chat"] = std::move(_sub);
    }
    j["message_id"] = o.message_id;
    j["date"] = o.date;
    {
        json _arr = json::array();
        for (const auto& _item : o.reactions) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["reactions"] = std::move(_arr);
    }
}

inline void from_json(const json& j, ForumTopic& o) {
    o.message_thread_id = j.contains("message_thread_id") && !j.at("message_thread_id").is_null()
        ? j.at("message_thread_id").get<int64_t>() : 0;
    o.name = j.contains("name") && !j.at("name").is_null()
        ? j.at("name").get<std::string>() : "";
    o.icon_color = j.contains("icon_color") && !j.at("icon_color").is_null()
        ? j.at("icon_color").get<int64_t>() : 0;
    if (j.contains("icon_custom_emoji_id") && !j.at("icon_custom_emoji_id").is_null())
        o.icon_custom_emoji_id = j.at("icon_custom_emoji_id").get<std::string>();
    if (j.contains("is_name_implicit") && !j.at("is_name_implicit").is_null())
        o.is_name_implicit = j.at("is_name_implicit").get<bool>();
}

inline void to_json(json& j, const ForumTopic& o) {
    j = json::object();
    j["message_thread_id"] = o.message_thread_id;
    j["name"] = o.name;
    j["icon_color"] = o.icon_color;
    if (o.icon_custom_emoji_id.has_value())
        j["icon_custom_emoji_id"] = o.icon_custom_emoji_id.value();
    if (o.is_name_implicit.has_value())
        j["is_name_implicit"] = o.is_name_implicit.value();
}

inline void from_json(const json& j, GiftBackground& o) {
    o.center_color = j.contains("center_color") && !j.at("center_color").is_null()
        ? j.at("center_color").get<int64_t>() : 0;
    o.edge_color = j.contains("edge_color") && !j.at("edge_color").is_null()
        ? j.at("edge_color").get<int64_t>() : 0;
    o.text_color = j.contains("text_color") && !j.at("text_color").is_null()
        ? j.at("text_color").get<int64_t>() : 0;
}

inline void to_json(json& j, const GiftBackground& o) {
    j = json::object();
    j["center_color"] = o.center_color;
    j["edge_color"] = o.edge_color;
    j["text_color"] = o.text_color;
}

inline void from_json(const json& j, Gift& o) {
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    if (j.contains("sticker") && !j.at("sticker").is_null()) {
        o.sticker = std::make_shared<Sticker>();
        from_json(j.at("sticker"), *o.sticker);
    }
    o.star_count = j.contains("star_count") && !j.at("star_count").is_null()
        ? j.at("star_count").get<int64_t>() : 0;
    if (j.contains("upgrade_star_count") && !j.at("upgrade_star_count").is_null())
        o.upgrade_star_count = j.at("upgrade_star_count").get<int64_t>();
    if (j.contains("is_premium") && !j.at("is_premium").is_null())
        o.is_premium = j.at("is_premium").get<bool>();
    if (j.contains("has_colors") && !j.at("has_colors").is_null())
        o.has_colors = j.at("has_colors").get<bool>();
    if (j.contains("total_count") && !j.at("total_count").is_null())
        o.total_count = j.at("total_count").get<int64_t>();
    if (j.contains("remaining_count") && !j.at("remaining_count").is_null())
        o.remaining_count = j.at("remaining_count").get<int64_t>();
    if (j.contains("personal_total_count") && !j.at("personal_total_count").is_null())
        o.personal_total_count = j.at("personal_total_count").get<int64_t>();
    if (j.contains("personal_remaining_count") && !j.at("personal_remaining_count").is_null())
        o.personal_remaining_count = j.at("personal_remaining_count").get<int64_t>();
    if (j.contains("background") && !j.at("background").is_null()) {
        o.background = std::make_shared<GiftBackground>();
        from_json(j.at("background"), *o.background);
    }
    if (j.contains("unique_gift_variant_count") && !j.at("unique_gift_variant_count").is_null())
        o.unique_gift_variant_count = j.at("unique_gift_variant_count").get<int64_t>();
    if (j.contains("publisher_chat") && !j.at("publisher_chat").is_null()) {
        o.publisher_chat = std::make_shared<Chat>();
        from_json(j.at("publisher_chat"), *o.publisher_chat);
    }
}

inline void to_json(json& j, const Gift& o) {
    j = json::object();
    j["id"] = o.id;
    {
        json _sub; to_json(_sub, *o.sticker); j["sticker"] = std::move(_sub);
    }
    j["star_count"] = o.star_count;
    if (o.upgrade_star_count.has_value())
        j["upgrade_star_count"] = o.upgrade_star_count.value();
    if (o.is_premium.has_value())
        j["is_premium"] = o.is_premium.value();
    if (o.has_colors.has_value())
        j["has_colors"] = o.has_colors.value();
    if (o.total_count.has_value())
        j["total_count"] = o.total_count.value();
    if (o.remaining_count.has_value())
        j["remaining_count"] = o.remaining_count.value();
    if (o.personal_total_count.has_value())
        j["personal_total_count"] = o.personal_total_count.value();
    if (o.personal_remaining_count.has_value())
        j["personal_remaining_count"] = o.personal_remaining_count.value();
    if (o.background) {
        json _sub; to_json(_sub, *o.background); j["background"] = std::move(_sub);
    }
    if (o.unique_gift_variant_count.has_value())
        j["unique_gift_variant_count"] = o.unique_gift_variant_count.value();
    if (o.publisher_chat) {
        json _sub; to_json(_sub, *o.publisher_chat); j["publisher_chat"] = std::move(_sub);
    }
}

inline void from_json(const json& j, Gifts& o) {
    if (j.contains("gifts") && j.at("gifts").is_array()) {
        for (const auto& _item : j.at("gifts")) {
            {
                auto _elem = std::make_shared<Gift>();
                from_json(_item, *_elem);
                o.gifts.push_back(std::move(_elem));
            }
        }
    }
}

inline void to_json(json& j, const Gifts& o) {
    j = json::object();
    {
        json _arr = json::array();
        for (const auto& _item : o.gifts) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["gifts"] = std::move(_arr);
    }
}

inline void from_json(const json& j, UniqueGiftModel& o) {
    o.name = j.contains("name") && !j.at("name").is_null()
        ? j.at("name").get<std::string>() : "";
    if (j.contains("sticker") && !j.at("sticker").is_null()) {
        o.sticker = std::make_shared<Sticker>();
        from_json(j.at("sticker"), *o.sticker);
    }
    o.rarity_per_mille = j.contains("rarity_per_mille") && !j.at("rarity_per_mille").is_null()
        ? j.at("rarity_per_mille").get<int64_t>() : 0;
    if (j.contains("rarity") && !j.at("rarity").is_null())
        o.rarity = j.at("rarity").get<std::string>();
}

inline void to_json(json& j, const UniqueGiftModel& o) {
    j = json::object();
    j["name"] = o.name;
    {
        json _sub; to_json(_sub, *o.sticker); j["sticker"] = std::move(_sub);
    }
    j["rarity_per_mille"] = o.rarity_per_mille;
    if (o.rarity.has_value())
        j["rarity"] = o.rarity.value();
}

inline void from_json(const json& j, UniqueGiftSymbol& o) {
    o.name = j.contains("name") && !j.at("name").is_null()
        ? j.at("name").get<std::string>() : "";
    if (j.contains("sticker") && !j.at("sticker").is_null()) {
        o.sticker = std::make_shared<Sticker>();
        from_json(j.at("sticker"), *o.sticker);
    }
    o.rarity_per_mille = j.contains("rarity_per_mille") && !j.at("rarity_per_mille").is_null()
        ? j.at("rarity_per_mille").get<int64_t>() : 0;
}

inline void to_json(json& j, const UniqueGiftSymbol& o) {
    j = json::object();
    j["name"] = o.name;
    {
        json _sub; to_json(_sub, *o.sticker); j["sticker"] = std::move(_sub);
    }
    j["rarity_per_mille"] = o.rarity_per_mille;
}

inline void from_json(const json& j, UniqueGiftBackdropColors& o) {
    o.center_color = j.contains("center_color") && !j.at("center_color").is_null()
        ? j.at("center_color").get<int64_t>() : 0;
    o.edge_color = j.contains("edge_color") && !j.at("edge_color").is_null()
        ? j.at("edge_color").get<int64_t>() : 0;
    o.symbol_color = j.contains("symbol_color") && !j.at("symbol_color").is_null()
        ? j.at("symbol_color").get<int64_t>() : 0;
    o.text_color = j.contains("text_color") && !j.at("text_color").is_null()
        ? j.at("text_color").get<int64_t>() : 0;
}

inline void to_json(json& j, const UniqueGiftBackdropColors& o) {
    j = json::object();
    j["center_color"] = o.center_color;
    j["edge_color"] = o.edge_color;
    j["symbol_color"] = o.symbol_color;
    j["text_color"] = o.text_color;
}

inline void from_json(const json& j, UniqueGiftBackdrop& o) {
    o.name = j.contains("name") && !j.at("name").is_null()
        ? j.at("name").get<std::string>() : "";
    if (j.contains("colors") && !j.at("colors").is_null()) {
        o.colors = std::make_shared<UniqueGiftBackdropColors>();
        from_json(j.at("colors"), *o.colors);
    }
    o.rarity_per_mille = j.contains("rarity_per_mille") && !j.at("rarity_per_mille").is_null()
        ? j.at("rarity_per_mille").get<int64_t>() : 0;
}

inline void to_json(json& j, const UniqueGiftBackdrop& o) {
    j = json::object();
    j["name"] = o.name;
    {
        json _sub; to_json(_sub, *o.colors); j["colors"] = std::move(_sub);
    }
    j["rarity_per_mille"] = o.rarity_per_mille;
}

inline void from_json(const json& j, UniqueGiftColors& o) {
    o.model_custom_emoji_id = j.contains("model_custom_emoji_id") && !j.at("model_custom_emoji_id").is_null()
        ? j.at("model_custom_emoji_id").get<std::string>() : "";
    o.symbol_custom_emoji_id = j.contains("symbol_custom_emoji_id") && !j.at("symbol_custom_emoji_id").is_null()
        ? j.at("symbol_custom_emoji_id").get<std::string>() : "";
    o.light_theme_main_color = j.contains("light_theme_main_color") && !j.at("light_theme_main_color").is_null()
        ? j.at("light_theme_main_color").get<int64_t>() : 0;
    if (j.contains("light_theme_other_colors") && j.at("light_theme_other_colors").is_array()) {
        for (const auto& _item : j.at("light_theme_other_colors")) {
            o.light_theme_other_colors.push_back(_item.get<int64_t>());
        }
    }
    o.dark_theme_main_color = j.contains("dark_theme_main_color") && !j.at("dark_theme_main_color").is_null()
        ? j.at("dark_theme_main_color").get<int64_t>() : 0;
    if (j.contains("dark_theme_other_colors") && j.at("dark_theme_other_colors").is_array()) {
        for (const auto& _item : j.at("dark_theme_other_colors")) {
            o.dark_theme_other_colors.push_back(_item.get<int64_t>());
        }
    }
}

inline void to_json(json& j, const UniqueGiftColors& o) {
    j = json::object();
    j["model_custom_emoji_id"] = o.model_custom_emoji_id;
    j["symbol_custom_emoji_id"] = o.symbol_custom_emoji_id;
    j["light_theme_main_color"] = o.light_theme_main_color;
    {
        json _arr = json::array();
        for (const auto& _item : o.light_theme_other_colors) {
            _arr.push_back(_item);
        }
        j["light_theme_other_colors"] = std::move(_arr);
    }
    j["dark_theme_main_color"] = o.dark_theme_main_color;
    {
        json _arr = json::array();
        for (const auto& _item : o.dark_theme_other_colors) {
            _arr.push_back(_item);
        }
        j["dark_theme_other_colors"] = std::move(_arr);
    }
}

inline void from_json(const json& j, UniqueGift& o) {
    o.gift_id = j.contains("gift_id") && !j.at("gift_id").is_null()
        ? j.at("gift_id").get<std::string>() : "";
    o.base_name = j.contains("base_name") && !j.at("base_name").is_null()
        ? j.at("base_name").get<std::string>() : "";
    o.name = j.contains("name") && !j.at("name").is_null()
        ? j.at("name").get<std::string>() : "";
    o.number = j.contains("number") && !j.at("number").is_null()
        ? j.at("number").get<int64_t>() : 0;
    if (j.contains("model") && !j.at("model").is_null()) {
        o.model = std::make_shared<UniqueGiftModel>();
        from_json(j.at("model"), *o.model);
    }
    if (j.contains("symbol") && !j.at("symbol").is_null()) {
        o.symbol = std::make_shared<UniqueGiftSymbol>();
        from_json(j.at("symbol"), *o.symbol);
    }
    if (j.contains("backdrop") && !j.at("backdrop").is_null()) {
        o.backdrop = std::make_shared<UniqueGiftBackdrop>();
        from_json(j.at("backdrop"), *o.backdrop);
    }
    if (j.contains("is_premium") && !j.at("is_premium").is_null())
        o.is_premium = j.at("is_premium").get<bool>();
    if (j.contains("is_burned") && !j.at("is_burned").is_null())
        o.is_burned = j.at("is_burned").get<bool>();
    if (j.contains("is_from_blockchain") && !j.at("is_from_blockchain").is_null())
        o.is_from_blockchain = j.at("is_from_blockchain").get<bool>();
    if (j.contains("colors") && !j.at("colors").is_null()) {
        o.colors = std::make_shared<UniqueGiftColors>();
        from_json(j.at("colors"), *o.colors);
    }
    if (j.contains("publisher_chat") && !j.at("publisher_chat").is_null()) {
        o.publisher_chat = std::make_shared<Chat>();
        from_json(j.at("publisher_chat"), *o.publisher_chat);
    }
}

inline void to_json(json& j, const UniqueGift& o) {
    j = json::object();
    j["gift_id"] = o.gift_id;
    j["base_name"] = o.base_name;
    j["name"] = o.name;
    j["number"] = o.number;
    {
        json _sub; to_json(_sub, *o.model); j["model"] = std::move(_sub);
    }
    {
        json _sub; to_json(_sub, *o.symbol); j["symbol"] = std::move(_sub);
    }
    {
        json _sub; to_json(_sub, *o.backdrop); j["backdrop"] = std::move(_sub);
    }
    if (o.is_premium.has_value())
        j["is_premium"] = o.is_premium.value();
    if (o.is_burned.has_value())
        j["is_burned"] = o.is_burned.value();
    if (o.is_from_blockchain.has_value())
        j["is_from_blockchain"] = o.is_from_blockchain.value();
    if (o.colors) {
        json _sub; to_json(_sub, *o.colors); j["colors"] = std::move(_sub);
    }
    if (o.publisher_chat) {
        json _sub; to_json(_sub, *o.publisher_chat); j["publisher_chat"] = std::move(_sub);
    }
}

inline void from_json(const json& j, GiftInfo& o) {
    if (j.contains("gift") && !j.at("gift").is_null()) {
        o.gift = std::make_shared<Gift>();
        from_json(j.at("gift"), *o.gift);
    }
    if (j.contains("owned_gift_id") && !j.at("owned_gift_id").is_null())
        o.owned_gift_id = j.at("owned_gift_id").get<std::string>();
    if (j.contains("convert_star_count") && !j.at("convert_star_count").is_null())
        o.convert_star_count = j.at("convert_star_count").get<int64_t>();
    if (j.contains("prepaid_upgrade_star_count") && !j.at("prepaid_upgrade_star_count").is_null())
        o.prepaid_upgrade_star_count = j.at("prepaid_upgrade_star_count").get<int64_t>();
    if (j.contains("is_upgrade_separate") && !j.at("is_upgrade_separate").is_null())
        o.is_upgrade_separate = j.at("is_upgrade_separate").get<bool>();
    if (j.contains("can_be_upgraded") && !j.at("can_be_upgraded").is_null())
        o.can_be_upgraded = j.at("can_be_upgraded").get<bool>();
    if (j.contains("text") && !j.at("text").is_null())
        o.text = j.at("text").get<std::string>();
    if (j.contains("entities") && j.at("entities").is_array()) {
        for (const auto& _item : j.at("entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("is_private") && !j.at("is_private").is_null())
        o.is_private = j.at("is_private").get<bool>();
    if (j.contains("unique_gift_number") && !j.at("unique_gift_number").is_null())
        o.unique_gift_number = j.at("unique_gift_number").get<int64_t>();
}

inline void to_json(json& j, const GiftInfo& o) {
    j = json::object();
    {
        json _sub; to_json(_sub, *o.gift); j["gift"] = std::move(_sub);
    }
    if (o.owned_gift_id.has_value())
        j["owned_gift_id"] = o.owned_gift_id.value();
    if (o.convert_star_count.has_value())
        j["convert_star_count"] = o.convert_star_count.value();
    if (o.prepaid_upgrade_star_count.has_value())
        j["prepaid_upgrade_star_count"] = o.prepaid_upgrade_star_count.value();
    if (o.is_upgrade_separate.has_value())
        j["is_upgrade_separate"] = o.is_upgrade_separate.value();
    if (o.can_be_upgraded.has_value())
        j["can_be_upgraded"] = o.can_be_upgraded.value();
    if (o.text.has_value())
        j["text"] = o.text.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["entities"] = std::move(_arr);
    }
    if (o.is_private.has_value())
        j["is_private"] = o.is_private.value();
    if (o.unique_gift_number.has_value())
        j["unique_gift_number"] = o.unique_gift_number.value();
}

inline void from_json(const json& j, UniqueGiftInfo& o) {
    if (j.contains("gift") && !j.at("gift").is_null()) {
        o.gift = std::make_shared<UniqueGift>();
        from_json(j.at("gift"), *o.gift);
    }
    o.origin = j.contains("origin") && !j.at("origin").is_null()
        ? j.at("origin").get<std::string>() : "";
    if (j.contains("last_resale_currency") && !j.at("last_resale_currency").is_null())
        o.last_resale_currency = j.at("last_resale_currency").get<std::string>();
    if (j.contains("last_resale_amount") && !j.at("last_resale_amount").is_null())
        o.last_resale_amount = j.at("last_resale_amount").get<int64_t>();
    if (j.contains("owned_gift_id") && !j.at("owned_gift_id").is_null())
        o.owned_gift_id = j.at("owned_gift_id").get<std::string>();
    if (j.contains("transfer_star_count") && !j.at("transfer_star_count").is_null())
        o.transfer_star_count = j.at("transfer_star_count").get<int64_t>();
    if (j.contains("next_transfer_date") && !j.at("next_transfer_date").is_null())
        o.next_transfer_date = j.at("next_transfer_date").get<int64_t>();
}

inline void to_json(json& j, const UniqueGiftInfo& o) {
    j = json::object();
    {
        json _sub; to_json(_sub, *o.gift); j["gift"] = std::move(_sub);
    }
    j["origin"] = o.origin;
    if (o.last_resale_currency.has_value())
        j["last_resale_currency"] = o.last_resale_currency.value();
    if (o.last_resale_amount.has_value())
        j["last_resale_amount"] = o.last_resale_amount.value();
    if (o.owned_gift_id.has_value())
        j["owned_gift_id"] = o.owned_gift_id.value();
    if (o.transfer_star_count.has_value())
        j["transfer_star_count"] = o.transfer_star_count.value();
    if (o.next_transfer_date.has_value())
        j["next_transfer_date"] = o.next_transfer_date.value();
}

inline void from_json(const json& j, OwnedGift& v) {
    std::string type = j.at("type").get<std::string>();
    if (type == "regular") {
        auto obj = std::make_shared<OwnedGiftRegular>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "unique") {
        auto obj = std::make_shared<OwnedGiftUnique>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const OwnedGift& v) {
    if (auto* p = std::get_if <std::shared_ptr<OwnedGiftRegular>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<OwnedGiftUnique>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, OwnedGiftRegular& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("gift") && !j.at("gift").is_null()) {
        o.gift = std::make_shared<Gift>();
        from_json(j.at("gift"), *o.gift);
    }
    if (j.contains("owned_gift_id") && !j.at("owned_gift_id").is_null())
        o.owned_gift_id = j.at("owned_gift_id").get<std::string>();
    if (j.contains("sender_user") && !j.at("sender_user").is_null()) {
        o.sender_user = std::make_shared<User>();
        from_json(j.at("sender_user"), *o.sender_user);
    }
    o.send_date = j.contains("send_date") && !j.at("send_date").is_null()
        ? j.at("send_date").get<int64_t>() : 0;
    if (j.contains("text") && !j.at("text").is_null())
        o.text = j.at("text").get<std::string>();
    if (j.contains("entities") && j.at("entities").is_array()) {
        for (const auto& _item : j.at("entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("is_private") && !j.at("is_private").is_null())
        o.is_private = j.at("is_private").get<bool>();
    if (j.contains("is_saved") && !j.at("is_saved").is_null())
        o.is_saved = j.at("is_saved").get<bool>();
    if (j.contains("can_be_upgraded") && !j.at("can_be_upgraded").is_null())
        o.can_be_upgraded = j.at("can_be_upgraded").get<bool>();
    if (j.contains("was_refunded") && !j.at("was_refunded").is_null())
        o.was_refunded = j.at("was_refunded").get<bool>();
    if (j.contains("convert_star_count") && !j.at("convert_star_count").is_null())
        o.convert_star_count = j.at("convert_star_count").get<int64_t>();
    if (j.contains("prepaid_upgrade_star_count") && !j.at("prepaid_upgrade_star_count").is_null())
        o.prepaid_upgrade_star_count = j.at("prepaid_upgrade_star_count").get<int64_t>();
    if (j.contains("is_upgrade_separate") && !j.at("is_upgrade_separate").is_null())
        o.is_upgrade_separate = j.at("is_upgrade_separate").get<bool>();
    if (j.contains("unique_gift_number") && !j.at("unique_gift_number").is_null())
        o.unique_gift_number = j.at("unique_gift_number").get<int64_t>();
}

inline void to_json(json& j, const OwnedGiftRegular& o) {
    j = json::object();
    j["type"] = o.type;
    {
        json _sub; to_json(_sub, *o.gift); j["gift"] = std::move(_sub);
    }
    if (o.owned_gift_id.has_value())
        j["owned_gift_id"] = o.owned_gift_id.value();
    if (o.sender_user) {
        json _sub; to_json(_sub, *o.sender_user); j["sender_user"] = std::move(_sub);
    }
    j["send_date"] = o.send_date;
    if (o.text.has_value())
        j["text"] = o.text.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["entities"] = std::move(_arr);
    }
    if (o.is_private.has_value())
        j["is_private"] = o.is_private.value();
    if (o.is_saved.has_value())
        j["is_saved"] = o.is_saved.value();
    if (o.can_be_upgraded.has_value())
        j["can_be_upgraded"] = o.can_be_upgraded.value();
    if (o.was_refunded.has_value())
        j["was_refunded"] = o.was_refunded.value();
    if (o.convert_star_count.has_value())
        j["convert_star_count"] = o.convert_star_count.value();
    if (o.prepaid_upgrade_star_count.has_value())
        j["prepaid_upgrade_star_count"] = o.prepaid_upgrade_star_count.value();
    if (o.is_upgrade_separate.has_value())
        j["is_upgrade_separate"] = o.is_upgrade_separate.value();
    if (o.unique_gift_number.has_value())
        j["unique_gift_number"] = o.unique_gift_number.value();
}

inline void from_json(const json& j, OwnedGiftUnique& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("gift") && !j.at("gift").is_null()) {
        o.gift = std::make_shared<UniqueGift>();
        from_json(j.at("gift"), *o.gift);
    }
    if (j.contains("owned_gift_id") && !j.at("owned_gift_id").is_null())
        o.owned_gift_id = j.at("owned_gift_id").get<std::string>();
    if (j.contains("sender_user") && !j.at("sender_user").is_null()) {
        o.sender_user = std::make_shared<User>();
        from_json(j.at("sender_user"), *o.sender_user);
    }
    o.send_date = j.contains("send_date") && !j.at("send_date").is_null()
        ? j.at("send_date").get<int64_t>() : 0;
    if (j.contains("is_saved") && !j.at("is_saved").is_null())
        o.is_saved = j.at("is_saved").get<bool>();
    if (j.contains("can_be_transferred") && !j.at("can_be_transferred").is_null())
        o.can_be_transferred = j.at("can_be_transferred").get<bool>();
    if (j.contains("transfer_star_count") && !j.at("transfer_star_count").is_null())
        o.transfer_star_count = j.at("transfer_star_count").get<int64_t>();
    if (j.contains("next_transfer_date") && !j.at("next_transfer_date").is_null())
        o.next_transfer_date = j.at("next_transfer_date").get<int64_t>();
}

inline void to_json(json& j, const OwnedGiftUnique& o) {
    j = json::object();
    j["type"] = o.type;
    {
        json _sub; to_json(_sub, *o.gift); j["gift"] = std::move(_sub);
    }
    if (o.owned_gift_id.has_value())
        j["owned_gift_id"] = o.owned_gift_id.value();
    if (o.sender_user) {
        json _sub; to_json(_sub, *o.sender_user); j["sender_user"] = std::move(_sub);
    }
    j["send_date"] = o.send_date;
    if (o.is_saved.has_value())
        j["is_saved"] = o.is_saved.value();
    if (o.can_be_transferred.has_value())
        j["can_be_transferred"] = o.can_be_transferred.value();
    if (o.transfer_star_count.has_value())
        j["transfer_star_count"] = o.transfer_star_count.value();
    if (o.next_transfer_date.has_value())
        j["next_transfer_date"] = o.next_transfer_date.value();
}

inline void from_json(const json& j, OwnedGifts& o) {
    o.total_count = j.contains("total_count") && !j.at("total_count").is_null()
        ? j.at("total_count").get<int64_t>() : 0;
    if (j.contains("gifts") && j.at("gifts").is_array()) {
        for (const auto& _item : j.at("gifts")) {
            {
                OwnedGift _elem{};
                from_json(_item, _elem);
                o.gifts.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("next_offset") && !j.at("next_offset").is_null())
        o.next_offset = j.at("next_offset").get<std::string>();
}

inline void to_json(json& j, const OwnedGifts& o) {
    j = json::object();
    j["total_count"] = o.total_count;
    {
        json _arr = json::array();
        for (const auto& _item : o.gifts) {
            {
                json _e; to_json(_e, _item); _arr.push_back(std::move(_e));
            }
        }
        j["gifts"] = std::move(_arr);
    }
    if (o.next_offset.has_value())
        j["next_offset"] = o.next_offset.value();
}

inline void from_json(const json& j, BotAccessSettings& o) {
    o.is_access_restricted = j.contains("is_access_restricted") && !j.at("is_access_restricted").is_null()
        ? j.at("is_access_restricted").get<bool>() : false;
    if (j.contains("added_users") && j.at("added_users").is_array()) {
        for (const auto& _item : j.at("added_users")) {
            {
                auto _elem = std::make_shared<User>();
                from_json(_item, *_elem);
                o.added_users.push_back(std::move(_elem));
            }
        }
    }
}

inline void to_json(json& j, const BotAccessSettings& o) {
    j = json::object();
    j["is_access_restricted"] = o.is_access_restricted;
    {
        json _arr = json::array();
        for (const auto& _item : o.added_users) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["added_users"] = std::move(_arr);
    }
}

inline void from_json(const json& j, AcceptedGiftTypes& o) {
    o.unlimited_gifts = j.contains("unlimited_gifts") && !j.at("unlimited_gifts").is_null()
        ? j.at("unlimited_gifts").get<bool>() : false;
    o.limited_gifts = j.contains("limited_gifts") && !j.at("limited_gifts").is_null()
        ? j.at("limited_gifts").get<bool>() : false;
    o.unique_gifts = j.contains("unique_gifts") && !j.at("unique_gifts").is_null()
        ? j.at("unique_gifts").get<bool>() : false;
    o.premium_subscription = j.contains("premium_subscription") && !j.at("premium_subscription").is_null()
        ? j.at("premium_subscription").get<bool>() : false;
    o.gifts_from_channels = j.contains("gifts_from_channels") && !j.at("gifts_from_channels").is_null()
        ? j.at("gifts_from_channels").get<bool>() : false;
}

inline void to_json(json& j, const AcceptedGiftTypes& o) {
    j = json::object();
    j["unlimited_gifts"] = o.unlimited_gifts;
    j["limited_gifts"] = o.limited_gifts;
    j["unique_gifts"] = o.unique_gifts;
    j["premium_subscription"] = o.premium_subscription;
    j["gifts_from_channels"] = o.gifts_from_channels;
}

inline void from_json(const json& j, StarAmount& o) {
    o.amount = j.contains("amount") && !j.at("amount").is_null()
        ? j.at("amount").get<int64_t>() : 0;
    if (j.contains("nanostar_amount") && !j.at("nanostar_amount").is_null())
        o.nanostar_amount = j.at("nanostar_amount").get<int64_t>();
}

inline void to_json(json& j, const StarAmount& o) {
    j = json::object();
    j["amount"] = o.amount;
    if (o.nanostar_amount.has_value())
        j["nanostar_amount"] = o.nanostar_amount.value();
}

inline void from_json(const json& j, BotCommand& o) {
    o.command = j.contains("command") && !j.at("command").is_null()
        ? j.at("command").get<std::string>() : "";
    o.description = j.contains("description") && !j.at("description").is_null()
        ? j.at("description").get<std::string>() : "";
}

inline void to_json(json& j, const BotCommand& o) {
    j = json::object();
    j["command"] = o.command;
    j["description"] = o.description;
}

inline void from_json(const json& j, BotCommandScope& v) {
    std::string type = j.at("type").get<std::string>();
    if (type == "default") {
        auto obj = std::make_shared<BotCommandScopeDefault>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "all_private_chats") {
        auto obj = std::make_shared<BotCommandScopeAllPrivateChats>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "all_group_chats") {
        auto obj = std::make_shared<BotCommandScopeAllGroupChats>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "all_chat_administrators") {
        auto obj = std::make_shared<BotCommandScopeAllChatAdministrators>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "chat") {
        auto obj = std::make_shared<BotCommandScopeChat>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "chat_administrators") {
        auto obj = std::make_shared<BotCommandScopeChatAdministrators>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "chat_member") {
        auto obj = std::make_shared<BotCommandScopeChatMember>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const BotCommandScope& v) {
    if (auto* p = std::get_if <std::shared_ptr<BotCommandScopeDefault>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<BotCommandScopeAllPrivateChats>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<BotCommandScopeAllGroupChats>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<BotCommandScopeAllChatAdministrators>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<BotCommandScopeChat>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<BotCommandScopeChatAdministrators>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<BotCommandScopeChatMember>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, BotCommandScopeDefault& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
}

inline void to_json(json& j, const BotCommandScopeDefault& o) {
    j = json::object();
    j["type"] = o.type;
}

inline void from_json(const json& j, BotCommandScopeAllPrivateChats& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
}

inline void to_json(json& j, const BotCommandScopeAllPrivateChats& o) {
    j = json::object();
    j["type"] = o.type;
}

inline void from_json(const json& j, BotCommandScopeAllGroupChats& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
}

inline void to_json(json& j, const BotCommandScopeAllGroupChats& o) {
    j = json::object();
    j["type"] = o.type;
}

inline void from_json(const json& j, BotCommandScopeAllChatAdministrators& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
}

inline void to_json(json& j, const BotCommandScopeAllChatAdministrators& o) {
    j = json::object();
    j["type"] = o.type;
}

inline void from_json(const json& j, BotCommandScopeChat& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("chat_id") && !j.at("chat_id").is_null()) {
        if (j.at("chat_id").is_number_integer())
            o.chat_id = j.at("chat_id").get<int64_t>();
        else
            o.chat_id = j.at("chat_id").get<std::string>();
    }
}

inline void to_json(json& j, const BotCommandScopeChat& o) {
    j = json::object();
    j["type"] = o.type;
    if (auto* _p = std::get_if<int64_t>(&o.chat_id)) {
        j["chat_id"] = *_p;
    }
    if (auto* _p = std::get_if<std::string>(&o.chat_id)) {
        j["chat_id"] = *_p;
    }
}

inline void from_json(const json& j, BotCommandScopeChatAdministrators& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("chat_id") && !j.at("chat_id").is_null()) {
        if (j.at("chat_id").is_number_integer())
            o.chat_id = j.at("chat_id").get<int64_t>();
        else
            o.chat_id = j.at("chat_id").get<std::string>();
    }
}

inline void to_json(json& j, const BotCommandScopeChatAdministrators& o) {
    j = json::object();
    j["type"] = o.type;
    if (auto* _p = std::get_if<int64_t>(&o.chat_id)) {
        j["chat_id"] = *_p;
    }
    if (auto* _p = std::get_if<std::string>(&o.chat_id)) {
        j["chat_id"] = *_p;
    }
}

inline void from_json(const json& j, BotCommandScopeChatMember& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("chat_id") && !j.at("chat_id").is_null()) {
        if (j.at("chat_id").is_number_integer())
            o.chat_id = j.at("chat_id").get<int64_t>();
        else
            o.chat_id = j.at("chat_id").get<std::string>();
    }
    o.user_id = j.contains("user_id") && !j.at("user_id").is_null()
        ? j.at("user_id").get<int64_t>() : 0;
}

inline void to_json(json& j, const BotCommandScopeChatMember& o) {
    j = json::object();
    j["type"] = o.type;
    if (auto* _p = std::get_if<int64_t>(&o.chat_id)) {
        j["chat_id"] = *_p;
    }
    if (auto* _p = std::get_if<std::string>(&o.chat_id)) {
        j["chat_id"] = *_p;
    }
    j["user_id"] = o.user_id;
}

inline void from_json(const json& j, BotName& o) {
    o.name = j.contains("name") && !j.at("name").is_null()
        ? j.at("name").get<std::string>() : "";
}

inline void to_json(json& j, const BotName& o) {
    j = json::object();
    j["name"] = o.name;
}

inline void from_json(const json& j, BotDescription& o) {
    o.description = j.contains("description") && !j.at("description").is_null()
        ? j.at("description").get<std::string>() : "";
}

inline void to_json(json& j, const BotDescription& o) {
    j = json::object();
    j["description"] = o.description;
}

inline void from_json(const json& j, BotShortDescription& o) {
    o.short_description = j.contains("short_description") && !j.at("short_description").is_null()
        ? j.at("short_description").get<std::string>() : "";
}

inline void to_json(json& j, const BotShortDescription& o) {
    j = json::object();
    j["short_description"] = o.short_description;
}

inline void from_json(const json& j, MenuButton& v) {
    std::string type = j.at("type").get<std::string>();
    if (type == "commands") {
        auto obj = std::make_shared<MenuButtonCommands>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "web_app") {
        auto obj = std::make_shared<MenuButtonWebApp>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "default") {
        auto obj = std::make_shared<MenuButtonDefault>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const MenuButton& v) {
    if (auto* p = std::get_if <std::shared_ptr<MenuButtonCommands>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<MenuButtonWebApp>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<MenuButtonDefault>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, MenuButtonCommands& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
}

inline void to_json(json& j, const MenuButtonCommands& o) {
    j = json::object();
    j["type"] = o.type;
}

inline void from_json(const json& j, MenuButtonWebApp& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.text = j.contains("text") && !j.at("text").is_null()
        ? j.at("text").get<std::string>() : "";
    if (j.contains("web_app") && !j.at("web_app").is_null()) {
        o.web_app = std::make_shared<WebAppInfo>();
        from_json(j.at("web_app"), *o.web_app);
    }
}

inline void to_json(json& j, const MenuButtonWebApp& o) {
    j = json::object();
    j["type"] = o.type;
    j["text"] = o.text;
    {
        json _sub; to_json(_sub, *o.web_app); j["web_app"] = std::move(_sub);
    }
}

inline void from_json(const json& j, MenuButtonDefault& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
}

inline void to_json(json& j, const MenuButtonDefault& o) {
    j = json::object();
    j["type"] = o.type;
}

inline void from_json(const json& j, ChatBoostSource& v) {
    std::string type = j.at("source").get<std::string>();
    if (type == "premium") {
        auto obj = std::make_shared<ChatBoostSourcePremium>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "gift_code") {
        auto obj = std::make_shared<ChatBoostSourceGiftCode>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "giveaway") {
        auto obj = std::make_shared<ChatBoostSourceGiveaway>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const ChatBoostSource& v) {
    if (auto* p = std::get_if <std::shared_ptr<ChatBoostSourcePremium>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<ChatBoostSourceGiftCode>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<ChatBoostSourceGiveaway>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, ChatBoostSourcePremium& o) {
    o.source = j.contains("source") && !j.at("source").is_null()
        ? j.at("source").get<std::string>() : "";
    if (j.contains("user") && !j.at("user").is_null()) {
        o.user = std::make_shared<User>();
        from_json(j.at("user"), *o.user);
    }
}

inline void to_json(json& j, const ChatBoostSourcePremium& o) {
    j = json::object();
    j["source"] = o.source;
    {
        json _sub; to_json(_sub, *o.user); j["user"] = std::move(_sub);
    }
}

inline void from_json(const json& j, ChatBoostSourceGiftCode& o) {
    o.source = j.contains("source") && !j.at("source").is_null()
        ? j.at("source").get<std::string>() : "";
    if (j.contains("user") && !j.at("user").is_null()) {
        o.user = std::make_shared<User>();
        from_json(j.at("user"), *o.user);
    }
}

inline void to_json(json& j, const ChatBoostSourceGiftCode& o) {
    j = json::object();
    j["source"] = o.source;
    {
        json _sub; to_json(_sub, *o.user); j["user"] = std::move(_sub);
    }
}

inline void from_json(const json& j, ChatBoostSourceGiveaway& o) {
    o.source = j.contains("source") && !j.at("source").is_null()
        ? j.at("source").get<std::string>() : "";
    o.giveaway_message_id = j.contains("giveaway_message_id") && !j.at("giveaway_message_id").is_null()
        ? j.at("giveaway_message_id").get<int64_t>() : 0;
    if (j.contains("user") && !j.at("user").is_null()) {
        o.user = std::make_shared<User>();
        from_json(j.at("user"), *o.user);
    }
    if (j.contains("prize_star_count") && !j.at("prize_star_count").is_null())
        o.prize_star_count = j.at("prize_star_count").get<int64_t>();
    if (j.contains("is_unclaimed") && !j.at("is_unclaimed").is_null())
        o.is_unclaimed = j.at("is_unclaimed").get<bool>();
}

inline void to_json(json& j, const ChatBoostSourceGiveaway& o) {
    j = json::object();
    j["source"] = o.source;
    j["giveaway_message_id"] = o.giveaway_message_id;
    if (o.user) {
        json _sub; to_json(_sub, *o.user); j["user"] = std::move(_sub);
    }
    if (o.prize_star_count.has_value())
        j["prize_star_count"] = o.prize_star_count.value();
    if (o.is_unclaimed.has_value())
        j["is_unclaimed"] = o.is_unclaimed.value();
}

inline void from_json(const json& j, ChatBoost& o) {
    o.boost_id = j.contains("boost_id") && !j.at("boost_id").is_null()
        ? j.at("boost_id").get<std::string>() : "";
    o.add_date = j.contains("add_date") && !j.at("add_date").is_null()
        ? j.at("add_date").get<int64_t>() : 0;
    o.expiration_date = j.contains("expiration_date") && !j.at("expiration_date").is_null()
        ? j.at("expiration_date").get<int64_t>() : 0;
    if (j.contains("source") && !j.at("source").is_null()) {
        from_json(j.at("source"), o.source);
    }
}

inline void to_json(json& j, const ChatBoost& o) {
    j = json::object();
    j["boost_id"] = o.boost_id;
    j["add_date"] = o.add_date;
    j["expiration_date"] = o.expiration_date;
    {
        json _sub;
        to_json(_sub, o.source);
        j["source"] = std::move(_sub);
    }
}

inline void from_json(const json& j, ChatBoostUpdated& o) {
    if (j.contains("chat") && !j.at("chat").is_null()) {
        o.chat = std::make_shared<Chat>();
        from_json(j.at("chat"), *o.chat);
    }
    if (j.contains("boost") && !j.at("boost").is_null()) {
        o.boost = std::make_shared<ChatBoost>();
        from_json(j.at("boost"), *o.boost);
    }
}

inline void to_json(json& j, const ChatBoostUpdated& o) {
    j = json::object();
    {
        json _sub; to_json(_sub, *o.chat); j["chat"] = std::move(_sub);
    }
    {
        json _sub; to_json(_sub, *o.boost); j["boost"] = std::move(_sub);
    }
}

inline void from_json(const json& j, ChatBoostRemoved& o) {
    if (j.contains("chat") && !j.at("chat").is_null()) {
        o.chat = std::make_shared<Chat>();
        from_json(j.at("chat"), *o.chat);
    }
    o.boost_id = j.contains("boost_id") && !j.at("boost_id").is_null()
        ? j.at("boost_id").get<std::string>() : "";
    o.remove_date = j.contains("remove_date") && !j.at("remove_date").is_null()
        ? j.at("remove_date").get<int64_t>() : 0;
    if (j.contains("source") && !j.at("source").is_null()) {
        from_json(j.at("source"), o.source);
    }
}

inline void to_json(json& j, const ChatBoostRemoved& o) {
    j = json::object();
    {
        json _sub; to_json(_sub, *o.chat); j["chat"] = std::move(_sub);
    }
    j["boost_id"] = o.boost_id;
    j["remove_date"] = o.remove_date;
    {
        json _sub;
        to_json(_sub, o.source);
        j["source"] = std::move(_sub);
    }
}

inline void from_json(const json& j, ChatOwnerLeft& o) {
    if (j.contains("new_owner") && !j.at("new_owner").is_null()) {
        o.new_owner = std::make_shared<User>();
        from_json(j.at("new_owner"), *o.new_owner);
    }
}

inline void to_json(json& j, const ChatOwnerLeft& o) {
    j = json::object();
    if (o.new_owner) {
        json _sub; to_json(_sub, *o.new_owner); j["new_owner"] = std::move(_sub);
    }
}

inline void from_json(const json& j, ChatOwnerChanged& o) {
    if (j.contains("new_owner") && !j.at("new_owner").is_null()) {
        o.new_owner = std::make_shared<User>();
        from_json(j.at("new_owner"), *o.new_owner);
    }
}

inline void to_json(json& j, const ChatOwnerChanged& o) {
    j = json::object();
    {
        json _sub; to_json(_sub, *o.new_owner); j["new_owner"] = std::move(_sub);
    }
}

inline void from_json(const json& j, UserChatBoosts& o) {
    if (j.contains("boosts") && j.at("boosts").is_array()) {
        for (const auto& _item : j.at("boosts")) {
            {
                auto _elem = std::make_shared<ChatBoost>();
                from_json(_item, *_elem);
                o.boosts.push_back(std::move(_elem));
            }
        }
    }
}

inline void to_json(json& j, const UserChatBoosts& o) {
    j = json::object();
    {
        json _arr = json::array();
        for (const auto& _item : o.boosts) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["boosts"] = std::move(_arr);
    }
}

inline void from_json(const json& j, BusinessBotRights& o) {
    if (j.contains("can_reply") && !j.at("can_reply").is_null())
        o.can_reply = j.at("can_reply").get<bool>();
    if (j.contains("can_read_messages") && !j.at("can_read_messages").is_null())
        o.can_read_messages = j.at("can_read_messages").get<bool>();
    if (j.contains("can_delete_sent_messages") && !j.at("can_delete_sent_messages").is_null())
        o.can_delete_sent_messages = j.at("can_delete_sent_messages").get<bool>();
    if (j.contains("can_delete_all_messages") && !j.at("can_delete_all_messages").is_null())
        o.can_delete_all_messages = j.at("can_delete_all_messages").get<bool>();
    if (j.contains("can_edit_name") && !j.at("can_edit_name").is_null())
        o.can_edit_name = j.at("can_edit_name").get<bool>();
    if (j.contains("can_edit_bio") && !j.at("can_edit_bio").is_null())
        o.can_edit_bio = j.at("can_edit_bio").get<bool>();
    if (j.contains("can_edit_profile_photo") && !j.at("can_edit_profile_photo").is_null())
        o.can_edit_profile_photo = j.at("can_edit_profile_photo").get<bool>();
    if (j.contains("can_edit_username") && !j.at("can_edit_username").is_null())
        o.can_edit_username = j.at("can_edit_username").get<bool>();
    if (j.contains("can_change_gift_settings") && !j.at("can_change_gift_settings").is_null())
        o.can_change_gift_settings = j.at("can_change_gift_settings").get<bool>();
    if (j.contains("can_view_gifts_and_stars") && !j.at("can_view_gifts_and_stars").is_null())
        o.can_view_gifts_and_stars = j.at("can_view_gifts_and_stars").get<bool>();
    if (j.contains("can_convert_gifts_to_stars") && !j.at("can_convert_gifts_to_stars").is_null())
        o.can_convert_gifts_to_stars = j.at("can_convert_gifts_to_stars").get<bool>();
    if (j.contains("can_transfer_and_upgrade_gifts") && !j.at("can_transfer_and_upgrade_gifts").is_null())
        o.can_transfer_and_upgrade_gifts = j.at("can_transfer_and_upgrade_gifts").get<bool>();
    if (j.contains("can_transfer_stars") && !j.at("can_transfer_stars").is_null())
        o.can_transfer_stars = j.at("can_transfer_stars").get<bool>();
    if (j.contains("can_manage_stories") && !j.at("can_manage_stories").is_null())
        o.can_manage_stories = j.at("can_manage_stories").get<bool>();
}

inline void to_json(json& j, const BusinessBotRights& o) {
    j = json::object();
    if (o.can_reply.has_value())
        j["can_reply"] = o.can_reply.value();
    if (o.can_read_messages.has_value())
        j["can_read_messages"] = o.can_read_messages.value();
    if (o.can_delete_sent_messages.has_value())
        j["can_delete_sent_messages"] = o.can_delete_sent_messages.value();
    if (o.can_delete_all_messages.has_value())
        j["can_delete_all_messages"] = o.can_delete_all_messages.value();
    if (o.can_edit_name.has_value())
        j["can_edit_name"] = o.can_edit_name.value();
    if (o.can_edit_bio.has_value())
        j["can_edit_bio"] = o.can_edit_bio.value();
    if (o.can_edit_profile_photo.has_value())
        j["can_edit_profile_photo"] = o.can_edit_profile_photo.value();
    if (o.can_edit_username.has_value())
        j["can_edit_username"] = o.can_edit_username.value();
    if (o.can_change_gift_settings.has_value())
        j["can_change_gift_settings"] = o.can_change_gift_settings.value();
    if (o.can_view_gifts_and_stars.has_value())
        j["can_view_gifts_and_stars"] = o.can_view_gifts_and_stars.value();
    if (o.can_convert_gifts_to_stars.has_value())
        j["can_convert_gifts_to_stars"] = o.can_convert_gifts_to_stars.value();
    if (o.can_transfer_and_upgrade_gifts.has_value())
        j["can_transfer_and_upgrade_gifts"] = o.can_transfer_and_upgrade_gifts.value();
    if (o.can_transfer_stars.has_value())
        j["can_transfer_stars"] = o.can_transfer_stars.value();
    if (o.can_manage_stories.has_value())
        j["can_manage_stories"] = o.can_manage_stories.value();
}

inline void from_json(const json& j, BusinessConnection& o) {
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    if (j.contains("user") && !j.at("user").is_null()) {
        o.user = std::make_shared<User>();
        from_json(j.at("user"), *o.user);
    }
    o.user_chat_id = j.contains("user_chat_id") && !j.at("user_chat_id").is_null()
        ? j.at("user_chat_id").get<int64_t>() : 0;
    o.date = j.contains("date") && !j.at("date").is_null()
        ? j.at("date").get<int64_t>() : 0;
    if (j.contains("rights") && !j.at("rights").is_null()) {
        o.rights = std::make_shared<BusinessBotRights>();
        from_json(j.at("rights"), *o.rights);
    }
    o.is_enabled = j.contains("is_enabled") && !j.at("is_enabled").is_null()
        ? j.at("is_enabled").get<bool>() : false;
}

inline void to_json(json& j, const BusinessConnection& o) {
    j = json::object();
    j["id"] = o.id;
    {
        json _sub; to_json(_sub, *o.user); j["user"] = std::move(_sub);
    }
    j["user_chat_id"] = o.user_chat_id;
    j["date"] = o.date;
    if (o.rights) {
        json _sub; to_json(_sub, *o.rights); j["rights"] = std::move(_sub);
    }
    j["is_enabled"] = o.is_enabled;
}

inline void from_json(const json& j, BusinessMessagesDeleted& o) {
    o.business_connection_id = j.contains("business_connection_id") && !j.at("business_connection_id").is_null()
        ? j.at("business_connection_id").get<std::string>() : "";
    if (j.contains("chat") && !j.at("chat").is_null()) {
        o.chat = std::make_shared<Chat>();
        from_json(j.at("chat"), *o.chat);
    }
    if (j.contains("message_ids") && j.at("message_ids").is_array()) {
        for (const auto& _item : j.at("message_ids")) {
            o.message_ids.push_back(_item.get<int64_t>());
        }
    }
}

inline void to_json(json& j, const BusinessMessagesDeleted& o) {
    j = json::object();
    j["business_connection_id"] = o.business_connection_id;
    {
        json _sub; to_json(_sub, *o.chat); j["chat"] = std::move(_sub);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.message_ids) {
            _arr.push_back(_item);
        }
        j["message_ids"] = std::move(_arr);
    }
}

inline void from_json(const json& j, SentWebAppMessage& o) {
    if (j.contains("inline_message_id") && !j.at("inline_message_id").is_null())
        o.inline_message_id = j.at("inline_message_id").get<std::string>();
}

inline void to_json(json& j, const SentWebAppMessage& o) {
    j = json::object();
    if (o.inline_message_id.has_value())
        j["inline_message_id"] = o.inline_message_id.value();
}

inline void from_json(const json& j, SentGuestMessage& o) {
    o.inline_message_id = j.contains("inline_message_id") && !j.at("inline_message_id").is_null()
        ? j.at("inline_message_id").get<std::string>() : "";
}

inline void to_json(json& j, const SentGuestMessage& o) {
    j = json::object();
    j["inline_message_id"] = o.inline_message_id;
}

inline void from_json(const json& j, PreparedInlineMessage& o) {
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.expiration_date = j.contains("expiration_date") && !j.at("expiration_date").is_null()
        ? j.at("expiration_date").get<int64_t>() : 0;
}

inline void to_json(json& j, const PreparedInlineMessage& o) {
    j = json::object();
    j["id"] = o.id;
    j["expiration_date"] = o.expiration_date;
}

inline void from_json(const json& j, PreparedKeyboardButton& o) {
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
}

inline void to_json(json& j, const PreparedKeyboardButton& o) {
    j = json::object();
    j["id"] = o.id;
}

inline void from_json(const json& j, ResponseParameters& o) {
    if (j.contains("migrate_to_chat_id") && !j.at("migrate_to_chat_id").is_null())
        o.migrate_to_chat_id = j.at("migrate_to_chat_id").get<int64_t>();
    if (j.contains("retry_after") && !j.at("retry_after").is_null())
        o.retry_after = j.at("retry_after").get<int64_t>();
}

inline void to_json(json& j, const ResponseParameters& o) {
    j = json::object();
    if (o.migrate_to_chat_id.has_value())
        j["migrate_to_chat_id"] = o.migrate_to_chat_id.value();
    if (o.retry_after.has_value())
        j["retry_after"] = o.retry_after.value();
}

inline void from_json(const json& j, InputMedia& v) {
    std::string type = j.at("type").get<std::string>();
    if (type == "animation") {
        auto obj = std::make_shared<InputMediaAnimation>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "audio") {
        auto obj = std::make_shared<InputMediaAudio>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "document") {
        auto obj = std::make_shared<InputMediaDocument>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "live_photo") {
        auto obj = std::make_shared<InputMediaLivePhoto>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "photo") {
        auto obj = std::make_shared<InputMediaPhoto>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "video") {
        auto obj = std::make_shared<InputMediaVideo>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const InputMedia& v) {
    if (auto* p = std::get_if <std::shared_ptr<InputMediaAnimation>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputMediaAudio>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputMediaDocument>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputMediaLivePhoto>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputMediaPhoto>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputMediaVideo>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, InputMediaAnimation& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.media = j.contains("media") && !j.at("media").is_null()
        ? j.at("media").get<std::string>() : "";
    if (j.contains("thumbnail") && !j.at("thumbnail").is_null())
        o.thumbnail = j.at("thumbnail").get<std::string>();
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("show_caption_above_media") && !j.at("show_caption_above_media").is_null())
        o.show_caption_above_media = j.at("show_caption_above_media").get<bool>();
    if (j.contains("width") && !j.at("width").is_null())
        o.width = j.at("width").get<int64_t>();
    if (j.contains("height") && !j.at("height").is_null())
        o.height = j.at("height").get<int64_t>();
    if (j.contains("duration") && !j.at("duration").is_null())
        o.duration = j.at("duration").get<int64_t>();
    if (j.contains("has_spoiler") && !j.at("has_spoiler").is_null())
        o.has_spoiler = j.at("has_spoiler").get<bool>();
}

inline void to_json(json& j, const InputMediaAnimation& o) {
    j = json::object();
    j["type"] = o.type;
    j["media"] = o.media;
    if (o.thumbnail.has_value())
        j["thumbnail"] = o.thumbnail.value();
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.show_caption_above_media.has_value())
        j["show_caption_above_media"] = o.show_caption_above_media.value();
    if (o.width.has_value())
        j["width"] = o.width.value();
    if (o.height.has_value())
        j["height"] = o.height.value();
    if (o.duration.has_value())
        j["duration"] = o.duration.value();
    if (o.has_spoiler.has_value())
        j["has_spoiler"] = o.has_spoiler.value();
}

inline void from_json(const json& j, InputMediaAudio& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.media = j.contains("media") && !j.at("media").is_null()
        ? j.at("media").get<std::string>() : "";
    if (j.contains("thumbnail") && !j.at("thumbnail").is_null())
        o.thumbnail = j.at("thumbnail").get<std::string>();
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("duration") && !j.at("duration").is_null())
        o.duration = j.at("duration").get<int64_t>();
    if (j.contains("performer") && !j.at("performer").is_null())
        o.performer = j.at("performer").get<std::string>();
    if (j.contains("title") && !j.at("title").is_null())
        o.title = j.at("title").get<std::string>();
}

inline void to_json(json& j, const InputMediaAudio& o) {
    j = json::object();
    j["type"] = o.type;
    j["media"] = o.media;
    if (o.thumbnail.has_value())
        j["thumbnail"] = o.thumbnail.value();
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.duration.has_value())
        j["duration"] = o.duration.value();
    if (o.performer.has_value())
        j["performer"] = o.performer.value();
    if (o.title.has_value())
        j["title"] = o.title.value();
}

inline void from_json(const json& j, InputMediaDocument& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.media = j.contains("media") && !j.at("media").is_null()
        ? j.at("media").get<std::string>() : "";
    if (j.contains("thumbnail") && !j.at("thumbnail").is_null())
        o.thumbnail = j.at("thumbnail").get<std::string>();
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("disable_content_type_detection") && !j.at("disable_content_type_detection").is_null())
        o.disable_content_type_detection = j.at("disable_content_type_detection").get<bool>();
}

inline void to_json(json& j, const InputMediaDocument& o) {
    j = json::object();
    j["type"] = o.type;
    j["media"] = o.media;
    if (o.thumbnail.has_value())
        j["thumbnail"] = o.thumbnail.value();
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.disable_content_type_detection.has_value())
        j["disable_content_type_detection"] = o.disable_content_type_detection.value();
}

inline void from_json(const json& j, InputMediaLivePhoto& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.media = j.contains("media") && !j.at("media").is_null()
        ? j.at("media").get<std::string>() : "";
    o.photo = j.contains("photo") && !j.at("photo").is_null()
        ? j.at("photo").get<std::string>() : "";
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("show_caption_above_media") && !j.at("show_caption_above_media").is_null())
        o.show_caption_above_media = j.at("show_caption_above_media").get<bool>();
    if (j.contains("has_spoiler") && !j.at("has_spoiler").is_null())
        o.has_spoiler = j.at("has_spoiler").get<bool>();
}

inline void to_json(json& j, const InputMediaLivePhoto& o) {
    j = json::object();
    j["type"] = o.type;
    j["media"] = o.media;
    j["photo"] = o.photo;
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.show_caption_above_media.has_value())
        j["show_caption_above_media"] = o.show_caption_above_media.value();
    if (o.has_spoiler.has_value())
        j["has_spoiler"] = o.has_spoiler.value();
}

inline void from_json(const json& j, InputMediaLocation& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.latitude = j.contains("latitude") && !j.at("latitude").is_null()
        ? j.at("latitude").get<double>() : 0.0;
    o.longitude = j.contains("longitude") && !j.at("longitude").is_null()
        ? j.at("longitude").get<double>() : 0.0;
    if (j.contains("horizontal_accuracy") && !j.at("horizontal_accuracy").is_null())
        o.horizontal_accuracy = j.at("horizontal_accuracy").get<double>();
}

inline void to_json(json& j, const InputMediaLocation& o) {
    j = json::object();
    j["type"] = o.type;
    j["latitude"] = o.latitude;
    j["longitude"] = o.longitude;
    if (o.horizontal_accuracy.has_value())
        j["horizontal_accuracy"] = o.horizontal_accuracy.value();
}

inline void from_json(const json& j, InputMediaPhoto& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.media = j.contains("media") && !j.at("media").is_null()
        ? j.at("media").get<std::string>() : "";
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("show_caption_above_media") && !j.at("show_caption_above_media").is_null())
        o.show_caption_above_media = j.at("show_caption_above_media").get<bool>();
    if (j.contains("has_spoiler") && !j.at("has_spoiler").is_null())
        o.has_spoiler = j.at("has_spoiler").get<bool>();
}

inline void to_json(json& j, const InputMediaPhoto& o) {
    j = json::object();
    j["type"] = o.type;
    j["media"] = o.media;
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.show_caption_above_media.has_value())
        j["show_caption_above_media"] = o.show_caption_above_media.value();
    if (o.has_spoiler.has_value())
        j["has_spoiler"] = o.has_spoiler.value();
}

inline void from_json(const json& j, InputMediaSticker& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.media = j.contains("media") && !j.at("media").is_null()
        ? j.at("media").get<std::string>() : "";
    if (j.contains("emoji") && !j.at("emoji").is_null())
        o.emoji = j.at("emoji").get<std::string>();
}

inline void to_json(json& j, const InputMediaSticker& o) {
    j = json::object();
    j["type"] = o.type;
    j["media"] = o.media;
    if (o.emoji.has_value())
        j["emoji"] = o.emoji.value();
}

inline void from_json(const json& j, InputMediaVenue& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.latitude = j.contains("latitude") && !j.at("latitude").is_null()
        ? j.at("latitude").get<double>() : 0.0;
    o.longitude = j.contains("longitude") && !j.at("longitude").is_null()
        ? j.at("longitude").get<double>() : 0.0;
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    o.address = j.contains("address") && !j.at("address").is_null()
        ? j.at("address").get<std::string>() : "";
    if (j.contains("foursquare_id") && !j.at("foursquare_id").is_null())
        o.foursquare_id = j.at("foursquare_id").get<std::string>();
    if (j.contains("foursquare_type") && !j.at("foursquare_type").is_null())
        o.foursquare_type = j.at("foursquare_type").get<std::string>();
    if (j.contains("google_place_id") && !j.at("google_place_id").is_null())
        o.google_place_id = j.at("google_place_id").get<std::string>();
    if (j.contains("google_place_type") && !j.at("google_place_type").is_null())
        o.google_place_type = j.at("google_place_type").get<std::string>();
}

inline void to_json(json& j, const InputMediaVenue& o) {
    j = json::object();
    j["type"] = o.type;
    j["latitude"] = o.latitude;
    j["longitude"] = o.longitude;
    j["title"] = o.title;
    j["address"] = o.address;
    if (o.foursquare_id.has_value())
        j["foursquare_id"] = o.foursquare_id.value();
    if (o.foursquare_type.has_value())
        j["foursquare_type"] = o.foursquare_type.value();
    if (o.google_place_id.has_value())
        j["google_place_id"] = o.google_place_id.value();
    if (o.google_place_type.has_value())
        j["google_place_type"] = o.google_place_type.value();
}

inline void from_json(const json& j, InputMediaVideo& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.media = j.contains("media") && !j.at("media").is_null()
        ? j.at("media").get<std::string>() : "";
    if (j.contains("thumbnail") && !j.at("thumbnail").is_null())
        o.thumbnail = j.at("thumbnail").get<std::string>();
    if (j.contains("cover") && !j.at("cover").is_null())
        o.cover = j.at("cover").get<std::string>();
    if (j.contains("start_timestamp") && !j.at("start_timestamp").is_null())
        o.start_timestamp = j.at("start_timestamp").get<int64_t>();
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("show_caption_above_media") && !j.at("show_caption_above_media").is_null())
        o.show_caption_above_media = j.at("show_caption_above_media").get<bool>();
    if (j.contains("width") && !j.at("width").is_null())
        o.width = j.at("width").get<int64_t>();
    if (j.contains("height") && !j.at("height").is_null())
        o.height = j.at("height").get<int64_t>();
    if (j.contains("duration") && !j.at("duration").is_null())
        o.duration = j.at("duration").get<int64_t>();
    if (j.contains("supports_streaming") && !j.at("supports_streaming").is_null())
        o.supports_streaming = j.at("supports_streaming").get<bool>();
    if (j.contains("has_spoiler") && !j.at("has_spoiler").is_null())
        o.has_spoiler = j.at("has_spoiler").get<bool>();
}

inline void to_json(json& j, const InputMediaVideo& o) {
    j = json::object();
    j["type"] = o.type;
    j["media"] = o.media;
    if (o.thumbnail.has_value())
        j["thumbnail"] = o.thumbnail.value();
    if (o.cover.has_value())
        j["cover"] = o.cover.value();
    if (o.start_timestamp.has_value())
        j["start_timestamp"] = o.start_timestamp.value();
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.show_caption_above_media.has_value())
        j["show_caption_above_media"] = o.show_caption_above_media.value();
    if (o.width.has_value())
        j["width"] = o.width.value();
    if (o.height.has_value())
        j["height"] = o.height.value();
    if (o.duration.has_value())
        j["duration"] = o.duration.value();
    if (o.supports_streaming.has_value())
        j["supports_streaming"] = o.supports_streaming.value();
    if (o.has_spoiler.has_value())
        j["has_spoiler"] = o.has_spoiler.value();
}

inline void from_json(const json& j, InputPaidMedia& v) {
    std::string type = j.at("type").get<std::string>();
    if (type == "live_photo") {
        auto obj = std::make_shared<InputPaidMediaLivePhoto>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "photo") {
        auto obj = std::make_shared<InputPaidMediaPhoto>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "video") {
        auto obj = std::make_shared<InputPaidMediaVideo>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const InputPaidMedia& v) {
    if (auto* p = std::get_if <std::shared_ptr<InputPaidMediaLivePhoto>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputPaidMediaPhoto>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputPaidMediaVideo>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, InputPaidMediaLivePhoto& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.media = j.contains("media") && !j.at("media").is_null()
        ? j.at("media").get<std::string>() : "";
    o.photo = j.contains("photo") && !j.at("photo").is_null()
        ? j.at("photo").get<std::string>() : "";
}

inline void to_json(json& j, const InputPaidMediaLivePhoto& o) {
    j = json::object();
    j["type"] = o.type;
    j["media"] = o.media;
    j["photo"] = o.photo;
}

inline void from_json(const json& j, InputPaidMediaPhoto& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.media = j.contains("media") && !j.at("media").is_null()
        ? j.at("media").get<std::string>() : "";
}

inline void to_json(json& j, const InputPaidMediaPhoto& o) {
    j = json::object();
    j["type"] = o.type;
    j["media"] = o.media;
}

inline void from_json(const json& j, InputPaidMediaVideo& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.media = j.contains("media") && !j.at("media").is_null()
        ? j.at("media").get<std::string>() : "";
    if (j.contains("thumbnail") && !j.at("thumbnail").is_null())
        o.thumbnail = j.at("thumbnail").get<std::string>();
    if (j.contains("cover") && !j.at("cover").is_null())
        o.cover = j.at("cover").get<std::string>();
    if (j.contains("start_timestamp") && !j.at("start_timestamp").is_null())
        o.start_timestamp = j.at("start_timestamp").get<int64_t>();
    if (j.contains("width") && !j.at("width").is_null())
        o.width = j.at("width").get<int64_t>();
    if (j.contains("height") && !j.at("height").is_null())
        o.height = j.at("height").get<int64_t>();
    if (j.contains("duration") && !j.at("duration").is_null())
        o.duration = j.at("duration").get<int64_t>();
    if (j.contains("supports_streaming") && !j.at("supports_streaming").is_null())
        o.supports_streaming = j.at("supports_streaming").get<bool>();
}

inline void to_json(json& j, const InputPaidMediaVideo& o) {
    j = json::object();
    j["type"] = o.type;
    j["media"] = o.media;
    if (o.thumbnail.has_value())
        j["thumbnail"] = o.thumbnail.value();
    if (o.cover.has_value())
        j["cover"] = o.cover.value();
    if (o.start_timestamp.has_value())
        j["start_timestamp"] = o.start_timestamp.value();
    if (o.width.has_value())
        j["width"] = o.width.value();
    if (o.height.has_value())
        j["height"] = o.height.value();
    if (o.duration.has_value())
        j["duration"] = o.duration.value();
    if (o.supports_streaming.has_value())
        j["supports_streaming"] = o.supports_streaming.value();
}

inline void from_json(const json& j, InputProfilePhoto& v) {
    std::string type = j.at("type").get<std::string>();
    if (type == "static") {
        auto obj = std::make_shared<InputProfilePhotoStatic>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "animated") {
        auto obj = std::make_shared<InputProfilePhotoAnimated>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const InputProfilePhoto& v) {
    if (auto* p = std::get_if <std::shared_ptr<InputProfilePhotoStatic>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputProfilePhotoAnimated>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, InputProfilePhotoStatic& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.photo = j.contains("photo") && !j.at("photo").is_null()
        ? j.at("photo").get<std::string>() : "";
}

inline void to_json(json& j, const InputProfilePhotoStatic& o) {
    j = json::object();
    j["type"] = o.type;
    j["photo"] = o.photo;
}

inline void from_json(const json& j, InputProfilePhotoAnimated& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.animation = j.contains("animation") && !j.at("animation").is_null()
        ? j.at("animation").get<std::string>() : "";
    if (j.contains("main_frame_timestamp") && !j.at("main_frame_timestamp").is_null())
        o.main_frame_timestamp = j.at("main_frame_timestamp").get<double>();
}

inline void to_json(json& j, const InputProfilePhotoAnimated& o) {
    j = json::object();
    j["type"] = o.type;
    j["animation"] = o.animation;
    if (o.main_frame_timestamp.has_value())
        j["main_frame_timestamp"] = o.main_frame_timestamp.value();
}

inline void from_json(const json& j, InputStoryContent& v) {
    std::string type = j.at("type").get<std::string>();
    if (type == "photo") {
        auto obj = std::make_shared<InputStoryContentPhoto>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "video") {
        auto obj = std::make_shared<InputStoryContentVideo>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const InputStoryContent& v) {
    if (auto* p = std::get_if <std::shared_ptr<InputStoryContentPhoto>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputStoryContentVideo>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, InputStoryContentPhoto& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.photo = j.contains("photo") && !j.at("photo").is_null()
        ? j.at("photo").get<std::string>() : "";
}

inline void to_json(json& j, const InputStoryContentPhoto& o) {
    j = json::object();
    j["type"] = o.type;
    j["photo"] = o.photo;
}

inline void from_json(const json& j, InputStoryContentVideo& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.video = j.contains("video") && !j.at("video").is_null()
        ? j.at("video").get<std::string>() : "";
    if (j.contains("duration") && !j.at("duration").is_null())
        o.duration = j.at("duration").get<double>();
    if (j.contains("cover_frame_timestamp") && !j.at("cover_frame_timestamp").is_null())
        o.cover_frame_timestamp = j.at("cover_frame_timestamp").get<double>();
    if (j.contains("is_animation") && !j.at("is_animation").is_null())
        o.is_animation = j.at("is_animation").get<bool>();
}

inline void to_json(json& j, const InputStoryContentVideo& o) {
    j = json::object();
    j["type"] = o.type;
    j["video"] = o.video;
    if (o.duration.has_value())
        j["duration"] = o.duration.value();
    if (o.cover_frame_timestamp.has_value())
        j["cover_frame_timestamp"] = o.cover_frame_timestamp.value();
    if (o.is_animation.has_value())
        j["is_animation"] = o.is_animation.value();
}

inline void from_json(const json& j, Sticker& o) {
    o.file_id = j.contains("file_id") && !j.at("file_id").is_null()
        ? j.at("file_id").get<std::string>() : "";
    o.file_unique_id = j.contains("file_unique_id") && !j.at("file_unique_id").is_null()
        ? j.at("file_unique_id").get<std::string>() : "";
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.width = j.contains("width") && !j.at("width").is_null()
        ? j.at("width").get<int64_t>() : 0;
    o.height = j.contains("height") && !j.at("height").is_null()
        ? j.at("height").get<int64_t>() : 0;
    o.is_animated = j.contains("is_animated") && !j.at("is_animated").is_null()
        ? j.at("is_animated").get<bool>() : false;
    o.is_video = j.contains("is_video") && !j.at("is_video").is_null()
        ? j.at("is_video").get<bool>() : false;
    if (j.contains("thumbnail") && !j.at("thumbnail").is_null()) {
        o.thumbnail = std::make_shared<PhotoSize>();
        from_json(j.at("thumbnail"), *o.thumbnail);
    }
    if (j.contains("emoji") && !j.at("emoji").is_null())
        o.emoji = j.at("emoji").get<std::string>();
    if (j.contains("set_name") && !j.at("set_name").is_null())
        o.set_name = j.at("set_name").get<std::string>();
    if (j.contains("premium_animation") && !j.at("premium_animation").is_null()) {
        o.premium_animation = std::make_shared<File>();
        from_json(j.at("premium_animation"), *o.premium_animation);
    }
    if (j.contains("mask_position") && !j.at("mask_position").is_null()) {
        o.mask_position = std::make_shared<MaskPosition>();
        from_json(j.at("mask_position"), *o.mask_position);
    }
    if (j.contains("custom_emoji_id") && !j.at("custom_emoji_id").is_null())
        o.custom_emoji_id = j.at("custom_emoji_id").get<std::string>();
    if (j.contains("needs_repainting") && !j.at("needs_repainting").is_null())
        o.needs_repainting = j.at("needs_repainting").get<bool>();
    if (j.contains("file_size") && !j.at("file_size").is_null())
        o.file_size = j.at("file_size").get<int64_t>();
}

inline void to_json(json& j, const Sticker& o) {
    j = json::object();
    j["file_id"] = o.file_id;
    j["file_unique_id"] = o.file_unique_id;
    j["type"] = o.type;
    j["width"] = o.width;
    j["height"] = o.height;
    j["is_animated"] = o.is_animated;
    j["is_video"] = o.is_video;
    if (o.thumbnail) {
        json _sub; to_json(_sub, *o.thumbnail); j["thumbnail"] = std::move(_sub);
    }
    if (o.emoji.has_value())
        j["emoji"] = o.emoji.value();
    if (o.set_name.has_value())
        j["set_name"] = o.set_name.value();
    if (o.premium_animation) {
        json _sub; to_json(_sub, *o.premium_animation); j["premium_animation"] = std::move(_sub);
    }
    if (o.mask_position) {
        json _sub; to_json(_sub, *o.mask_position); j["mask_position"] = std::move(_sub);
    }
    if (o.custom_emoji_id.has_value())
        j["custom_emoji_id"] = o.custom_emoji_id.value();
    if (o.needs_repainting.has_value())
        j["needs_repainting"] = o.needs_repainting.value();
    if (o.file_size.has_value())
        j["file_size"] = o.file_size.value();
}

inline void from_json(const json& j, StickerSet& o) {
    o.name = j.contains("name") && !j.at("name").is_null()
        ? j.at("name").get<std::string>() : "";
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    o.sticker_type = j.contains("sticker_type") && !j.at("sticker_type").is_null()
        ? j.at("sticker_type").get<std::string>() : "";
    if (j.contains("stickers") && j.at("stickers").is_array()) {
        for (const auto& _item : j.at("stickers")) {
            {
                auto _elem = std::make_shared<Sticker>();
                from_json(_item, *_elem);
                o.stickers.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("thumbnail") && !j.at("thumbnail").is_null()) {
        o.thumbnail = std::make_shared<PhotoSize>();
        from_json(j.at("thumbnail"), *o.thumbnail);
    }
}

inline void to_json(json& j, const StickerSet& o) {
    j = json::object();
    j["name"] = o.name;
    j["title"] = o.title;
    j["sticker_type"] = o.sticker_type;
    {
        json _arr = json::array();
        for (const auto& _item : o.stickers) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["stickers"] = std::move(_arr);
    }
    if (o.thumbnail) {
        json _sub; to_json(_sub, *o.thumbnail); j["thumbnail"] = std::move(_sub);
    }
}

inline void from_json(const json& j, MaskPosition& o) {
    o.point = j.contains("point") && !j.at("point").is_null()
        ? j.at("point").get<std::string>() : "";
    o.x_shift = j.contains("x_shift") && !j.at("x_shift").is_null()
        ? j.at("x_shift").get<double>() : 0.0;
    o.y_shift = j.contains("y_shift") && !j.at("y_shift").is_null()
        ? j.at("y_shift").get<double>() : 0.0;
    o.scale = j.contains("scale") && !j.at("scale").is_null()
        ? j.at("scale").get<double>() : 0.0;
}

inline void to_json(json& j, const MaskPosition& o) {
    j = json::object();
    j["point"] = o.point;
    j["x_shift"] = o.x_shift;
    j["y_shift"] = o.y_shift;
    j["scale"] = o.scale;
}

inline void from_json(const json& j, InputSticker& o) {
    o.sticker = j.contains("sticker") && !j.at("sticker").is_null()
        ? j.at("sticker").get<std::string>() : "";
    o.format = j.contains("format") && !j.at("format").is_null()
        ? j.at("format").get<std::string>() : "";
    if (j.contains("emoji_list") && j.at("emoji_list").is_array()) {
        for (const auto& _item : j.at("emoji_list")) {
            o.emoji_list.push_back(_item.get<std::string>());
        }
    }
    if (j.contains("mask_position") && !j.at("mask_position").is_null()) {
        o.mask_position = std::make_shared<MaskPosition>();
        from_json(j.at("mask_position"), *o.mask_position);
    }
    if (j.contains("keywords") && j.at("keywords").is_array()) {
        for (const auto& _item : j.at("keywords")) {
            o.keywords.push_back(_item.get<std::string>());
        }
    }
}

inline void to_json(json& j, const InputSticker& o) {
    j = json::object();
    j["sticker"] = o.sticker;
    j["format"] = o.format;
    {
        json _arr = json::array();
        for (const auto& _item : o.emoji_list) {
            _arr.push_back(_item);
        }
        j["emoji_list"] = std::move(_arr);
    }
    if (o.mask_position) {
        json _sub; to_json(_sub, *o.mask_position); j["mask_position"] = std::move(_sub);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.keywords) {
            _arr.push_back(_item);
        }
        j["keywords"] = std::move(_arr);
    }
}

inline void from_json(const json& j, InlineQuery& o) {
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    if (j.contains("from") && !j.at("from").is_null()) {
        o.from = std::make_shared<User>();
        from_json(j.at("from"), *o.from);
    }
    o.query = j.contains("query") && !j.at("query").is_null()
        ? j.at("query").get<std::string>() : "";
    o.offset = j.contains("offset") && !j.at("offset").is_null()
        ? j.at("offset").get<std::string>() : "";
    if (j.contains("chat_type") && !j.at("chat_type").is_null())
        o.chat_type = j.at("chat_type").get<std::string>();
    if (j.contains("location") && !j.at("location").is_null()) {
        o.location = std::make_shared<Location>();
        from_json(j.at("location"), *o.location);
    }
}

inline void to_json(json& j, const InlineQuery& o) {
    j = json::object();
    j["id"] = o.id;
    {
        json _sub; to_json(_sub, *o.from); j["from"] = std::move(_sub);
    }
    j["query"] = o.query;
    j["offset"] = o.offset;
    if (o.chat_type.has_value())
        j["chat_type"] = o.chat_type.value();
    if (o.location) {
        json _sub; to_json(_sub, *o.location); j["location"] = std::move(_sub);
    }
}

inline void from_json(const json& j, InlineQueryResultsButton& o) {
    o.text = j.contains("text") && !j.at("text").is_null()
        ? j.at("text").get<std::string>() : "";
    if (j.contains("web_app") && !j.at("web_app").is_null()) {
        o.web_app = std::make_shared<WebAppInfo>();
        from_json(j.at("web_app"), *o.web_app);
    }
    if (j.contains("start_parameter") && !j.at("start_parameter").is_null())
        o.start_parameter = j.at("start_parameter").get<std::string>();
}

inline void to_json(json& j, const InlineQueryResultsButton& o) {
    j = json::object();
    j["text"] = o.text;
    if (o.web_app) {
        json _sub; to_json(_sub, *o.web_app); j["web_app"] = std::move(_sub);
    }
    if (o.start_parameter.has_value())
        j["start_parameter"] = o.start_parameter.value();
}

inline void from_json(const json& j, InlineQueryResult& v) {
    const std::string type = j.at("type").get<std::string>();
    const bool is_cached =
        j.contains("audio_file_id")    ||
        j.contains("document_file_id") ||
        j.contains("gif_file_id")      ||
        j.contains("mpeg4_file_id")    ||
        j.contains("photo_file_id")    ||
        j.contains("sticker_file_id")  ||
        j.contains("video_file_id")    ||
        j.contains("voice_file_id");

    if (is_cached) {
        if (type == "audio")     { auto o = std::make_shared<InlineQueryResultCachedAudio>();     from_json(j,*o); v=o; return; }
        if (type == "document")  { auto o = std::make_shared<InlineQueryResultCachedDocument>();  from_json(j,*o); v=o; return; }
        if (type == "gif")       { auto o = std::make_shared<InlineQueryResultCachedGif>();       from_json(j,*o); v=o; return; }
        if (type == "mpeg4_gif") { auto o = std::make_shared<InlineQueryResultCachedMpeg4Gif>(); from_json(j,*o); v=o; return; }
        if (type == "photo")     { auto o = std::make_shared<InlineQueryResultCachedPhoto>();     from_json(j,*o); v=o; return; }
        if (type == "sticker")   { auto o = std::make_shared<InlineQueryResultCachedSticker>();   from_json(j,*o); v=o; return; }
        if (type == "video")     { auto o = std::make_shared<InlineQueryResultCachedVideo>();     from_json(j,*o); v=o; return; }
        if (type == "voice")     { auto o = std::make_shared<InlineQueryResultCachedVoice>();     from_json(j,*o); v=o; return; }
    } else {
        if (type == "article")   { auto o = std::make_shared<InlineQueryResultArticle>();   from_json(j,*o); v=o; return; }
        if (type == "audio")     { auto o = std::make_shared<InlineQueryResultAudio>();     from_json(j,*o); v=o; return; }
        if (type == "contact")   { auto o = std::make_shared<InlineQueryResultContact>();   from_json(j,*o); v=o; return; }
        if (type == "game")      { auto o = std::make_shared<InlineQueryResultGame>();      from_json(j,*o); v=o; return; }
        if (type == "document")  { auto o = std::make_shared<InlineQueryResultDocument>();  from_json(j,*o); v=o; return; }
        if (type == "gif")       { auto o = std::make_shared<InlineQueryResultGif>();       from_json(j,*o); v=o; return; }
        if (type == "location")  { auto o = std::make_shared<InlineQueryResultLocation>();  from_json(j,*o); v=o; return; }
        if (type == "mpeg4_gif") { auto o = std::make_shared<InlineQueryResultMpeg4Gif>(); from_json(j,*o); v=o; return; }
        if (type == "photo")     { auto o = std::make_shared<InlineQueryResultPhoto>();     from_json(j,*o); v=o; return; }
        if (type == "venue")     { auto o = std::make_shared<InlineQueryResultVenue>();     from_json(j,*o); v=o; return; }
        if (type == "video")     { auto o = std::make_shared<InlineQueryResultVideo>();     from_json(j,*o); v=o; return; }
        if (type == "voice")     { auto o = std::make_shared<InlineQueryResultVoice>();     from_json(j,*o); v=o; return; }
    }
    throw std::runtime_error("Unknown InlineQueryResult type: " + type);
}

inline void to_json(json& j, const InlineQueryResult& v) {
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultCachedAudio>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultCachedDocument>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultCachedGif>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultCachedMpeg4Gif>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultCachedPhoto>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultCachedSticker>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultCachedVideo>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultCachedVoice>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultArticle>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultAudio>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultContact>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultGame>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultDocument>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultGif>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultLocation>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultMpeg4Gif>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultPhoto>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultVenue>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultVideo>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InlineQueryResultVoice>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, InlineQueryResultArticle& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    if (j.contains("input_message_content") && !j.at("input_message_content").is_null()) {
        from_json(j.at("input_message_content"), o.input_message_content);
    }
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
    if (j.contains("url") && !j.at("url").is_null())
        o.url = j.at("url").get<std::string>();
    if (j.contains("description") && !j.at("description").is_null())
        o.description = j.at("description").get<std::string>();
    if (j.contains("thumbnail_url") && !j.at("thumbnail_url").is_null())
        o.thumbnail_url = j.at("thumbnail_url").get<std::string>();
    if (j.contains("thumbnail_width") && !j.at("thumbnail_width").is_null())
        o.thumbnail_width = j.at("thumbnail_width").get<int64_t>();
    if (j.contains("thumbnail_height") && !j.at("thumbnail_height").is_null())
        o.thumbnail_height = j.at("thumbnail_height").get<int64_t>();
}

inline void to_json(json& j, const InlineQueryResultArticle& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["title"] = o.title;
    {
        json _sub;
        to_json(_sub, o.input_message_content);
        j["input_message_content"] = std::move(_sub);
    }
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
    if (o.url.has_value())
        j["url"] = o.url.value();
    if (o.description.has_value())
        j["description"] = o.description.value();
    if (o.thumbnail_url.has_value())
        j["thumbnail_url"] = o.thumbnail_url.value();
    if (o.thumbnail_width.has_value())
        j["thumbnail_width"] = o.thumbnail_width.value();
    if (o.thumbnail_height.has_value())
        j["thumbnail_height"] = o.thumbnail_height.value();
}

inline void from_json(const json& j, InlineQueryResultPhoto& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.photo_url = j.contains("photo_url") && !j.at("photo_url").is_null()
        ? j.at("photo_url").get<std::string>() : "";
    o.thumbnail_url = j.contains("thumbnail_url") && !j.at("thumbnail_url").is_null()
        ? j.at("thumbnail_url").get<std::string>() : "";
    if (j.contains("photo_width") && !j.at("photo_width").is_null())
        o.photo_width = j.at("photo_width").get<int64_t>();
    if (j.contains("photo_height") && !j.at("photo_height").is_null())
        o.photo_height = j.at("photo_height").get<int64_t>();
    if (j.contains("title") && !j.at("title").is_null())
        o.title = j.at("title").get<std::string>();
    if (j.contains("description") && !j.at("description").is_null())
        o.description = j.at("description").get<std::string>();
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("show_caption_above_media") && !j.at("show_caption_above_media").is_null())
        o.show_caption_above_media = j.at("show_caption_above_media").get<bool>();
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
    if (j.contains("input_message_content") && !j.at("input_message_content").is_null()) {
        InputMessageContent _tmp{};
        from_json(j.at("input_message_content"), _tmp);
        o.input_message_content = std::move(_tmp);
    }
}

inline void to_json(json& j, const InlineQueryResultPhoto& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["photo_url"] = o.photo_url;
    j["thumbnail_url"] = o.thumbnail_url;
    if (o.photo_width.has_value())
        j["photo_width"] = o.photo_width.value();
    if (o.photo_height.has_value())
        j["photo_height"] = o.photo_height.value();
    if (o.title.has_value())
        j["title"] = o.title.value();
    if (o.description.has_value())
        j["description"] = o.description.value();
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.show_caption_above_media.has_value())
        j["show_caption_above_media"] = o.show_caption_above_media.value();
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
    if (o.input_message_content.has_value()) {
        json _sub;
        to_json(_sub, o.input_message_content.value());
        j["input_message_content"] = std::move(_sub);
    }
}

inline void from_json(const json& j, InlineQueryResultGif& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.gif_url = j.contains("gif_url") && !j.at("gif_url").is_null()
        ? j.at("gif_url").get<std::string>() : "";
    if (j.contains("gif_width") && !j.at("gif_width").is_null())
        o.gif_width = j.at("gif_width").get<int64_t>();
    if (j.contains("gif_height") && !j.at("gif_height").is_null())
        o.gif_height = j.at("gif_height").get<int64_t>();
    if (j.contains("gif_duration") && !j.at("gif_duration").is_null())
        o.gif_duration = j.at("gif_duration").get<int64_t>();
    o.thumbnail_url = j.contains("thumbnail_url") && !j.at("thumbnail_url").is_null()
        ? j.at("thumbnail_url").get<std::string>() : "";
    if (j.contains("thumbnail_mime_type") && !j.at("thumbnail_mime_type").is_null())
        o.thumbnail_mime_type = j.at("thumbnail_mime_type").get<std::string>();
    if (j.contains("title") && !j.at("title").is_null())
        o.title = j.at("title").get<std::string>();
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("show_caption_above_media") && !j.at("show_caption_above_media").is_null())
        o.show_caption_above_media = j.at("show_caption_above_media").get<bool>();
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
    if (j.contains("input_message_content") && !j.at("input_message_content").is_null()) {
        InputMessageContent _tmp{};
        from_json(j.at("input_message_content"), _tmp);
        o.input_message_content = std::move(_tmp);
    }
}

inline void to_json(json& j, const InlineQueryResultGif& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["gif_url"] = o.gif_url;
    if (o.gif_width.has_value())
        j["gif_width"] = o.gif_width.value();
    if (o.gif_height.has_value())
        j["gif_height"] = o.gif_height.value();
    if (o.gif_duration.has_value())
        j["gif_duration"] = o.gif_duration.value();
    j["thumbnail_url"] = o.thumbnail_url;
    if (o.thumbnail_mime_type.has_value())
        j["thumbnail_mime_type"] = o.thumbnail_mime_type.value();
    if (o.title.has_value())
        j["title"] = o.title.value();
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.show_caption_above_media.has_value())
        j["show_caption_above_media"] = o.show_caption_above_media.value();
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
    if (o.input_message_content.has_value()) {
        json _sub;
        to_json(_sub, o.input_message_content.value());
        j["input_message_content"] = std::move(_sub);
    }
}

inline void from_json(const json& j, InlineQueryResultMpeg4Gif& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.mpeg4_url = j.contains("mpeg4_url") && !j.at("mpeg4_url").is_null()
        ? j.at("mpeg4_url").get<std::string>() : "";
    if (j.contains("mpeg4_width") && !j.at("mpeg4_width").is_null())
        o.mpeg4_width = j.at("mpeg4_width").get<int64_t>();
    if (j.contains("mpeg4_height") && !j.at("mpeg4_height").is_null())
        o.mpeg4_height = j.at("mpeg4_height").get<int64_t>();
    if (j.contains("mpeg4_duration") && !j.at("mpeg4_duration").is_null())
        o.mpeg4_duration = j.at("mpeg4_duration").get<int64_t>();
    o.thumbnail_url = j.contains("thumbnail_url") && !j.at("thumbnail_url").is_null()
        ? j.at("thumbnail_url").get<std::string>() : "";
    if (j.contains("thumbnail_mime_type") && !j.at("thumbnail_mime_type").is_null())
        o.thumbnail_mime_type = j.at("thumbnail_mime_type").get<std::string>();
    if (j.contains("title") && !j.at("title").is_null())
        o.title = j.at("title").get<std::string>();
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("show_caption_above_media") && !j.at("show_caption_above_media").is_null())
        o.show_caption_above_media = j.at("show_caption_above_media").get<bool>();
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
    if (j.contains("input_message_content") && !j.at("input_message_content").is_null()) {
        InputMessageContent _tmp{};
        from_json(j.at("input_message_content"), _tmp);
        o.input_message_content = std::move(_tmp);
    }
}

inline void to_json(json& j, const InlineQueryResultMpeg4Gif& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["mpeg4_url"] = o.mpeg4_url;
    if (o.mpeg4_width.has_value())
        j["mpeg4_width"] = o.mpeg4_width.value();
    if (o.mpeg4_height.has_value())
        j["mpeg4_height"] = o.mpeg4_height.value();
    if (o.mpeg4_duration.has_value())
        j["mpeg4_duration"] = o.mpeg4_duration.value();
    j["thumbnail_url"] = o.thumbnail_url;
    if (o.thumbnail_mime_type.has_value())
        j["thumbnail_mime_type"] = o.thumbnail_mime_type.value();
    if (o.title.has_value())
        j["title"] = o.title.value();
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.show_caption_above_media.has_value())
        j["show_caption_above_media"] = o.show_caption_above_media.value();
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
    if (o.input_message_content.has_value()) {
        json _sub;
        to_json(_sub, o.input_message_content.value());
        j["input_message_content"] = std::move(_sub);
    }
}

inline void from_json(const json& j, InlineQueryResultVideo& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.video_url = j.contains("video_url") && !j.at("video_url").is_null()
        ? j.at("video_url").get<std::string>() : "";
    o.mime_type = j.contains("mime_type") && !j.at("mime_type").is_null()
        ? j.at("mime_type").get<std::string>() : "";
    o.thumbnail_url = j.contains("thumbnail_url") && !j.at("thumbnail_url").is_null()
        ? j.at("thumbnail_url").get<std::string>() : "";
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("show_caption_above_media") && !j.at("show_caption_above_media").is_null())
        o.show_caption_above_media = j.at("show_caption_above_media").get<bool>();
    if (j.contains("video_width") && !j.at("video_width").is_null())
        o.video_width = j.at("video_width").get<int64_t>();
    if (j.contains("video_height") && !j.at("video_height").is_null())
        o.video_height = j.at("video_height").get<int64_t>();
    if (j.contains("video_duration") && !j.at("video_duration").is_null())
        o.video_duration = j.at("video_duration").get<int64_t>();
    if (j.contains("description") && !j.at("description").is_null())
        o.description = j.at("description").get<std::string>();
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
    if (j.contains("input_message_content") && !j.at("input_message_content").is_null()) {
        InputMessageContent _tmp{};
        from_json(j.at("input_message_content"), _tmp);
        o.input_message_content = std::move(_tmp);
    }
}

inline void to_json(json& j, const InlineQueryResultVideo& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["video_url"] = o.video_url;
    j["mime_type"] = o.mime_type;
    j["thumbnail_url"] = o.thumbnail_url;
    j["title"] = o.title;
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.show_caption_above_media.has_value())
        j["show_caption_above_media"] = o.show_caption_above_media.value();
    if (o.video_width.has_value())
        j["video_width"] = o.video_width.value();
    if (o.video_height.has_value())
        j["video_height"] = o.video_height.value();
    if (o.video_duration.has_value())
        j["video_duration"] = o.video_duration.value();
    if (o.description.has_value())
        j["description"] = o.description.value();
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
    if (o.input_message_content.has_value()) {
        json _sub;
        to_json(_sub, o.input_message_content.value());
        j["input_message_content"] = std::move(_sub);
    }
}

inline void from_json(const json& j, InlineQueryResultAudio& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.audio_url = j.contains("audio_url") && !j.at("audio_url").is_null()
        ? j.at("audio_url").get<std::string>() : "";
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("performer") && !j.at("performer").is_null())
        o.performer = j.at("performer").get<std::string>();
    if (j.contains("audio_duration") && !j.at("audio_duration").is_null())
        o.audio_duration = j.at("audio_duration").get<int64_t>();
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
    if (j.contains("input_message_content") && !j.at("input_message_content").is_null()) {
        InputMessageContent _tmp{};
        from_json(j.at("input_message_content"), _tmp);
        o.input_message_content = std::move(_tmp);
    }
}

inline void to_json(json& j, const InlineQueryResultAudio& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["audio_url"] = o.audio_url;
    j["title"] = o.title;
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.performer.has_value())
        j["performer"] = o.performer.value();
    if (o.audio_duration.has_value())
        j["audio_duration"] = o.audio_duration.value();
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
    if (o.input_message_content.has_value()) {
        json _sub;
        to_json(_sub, o.input_message_content.value());
        j["input_message_content"] = std::move(_sub);
    }
}

inline void from_json(const json& j, InlineQueryResultVoice& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.voice_url = j.contains("voice_url") && !j.at("voice_url").is_null()
        ? j.at("voice_url").get<std::string>() : "";
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("voice_duration") && !j.at("voice_duration").is_null())
        o.voice_duration = j.at("voice_duration").get<int64_t>();
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
    if (j.contains("input_message_content") && !j.at("input_message_content").is_null()) {
        InputMessageContent _tmp{};
        from_json(j.at("input_message_content"), _tmp);
        o.input_message_content = std::move(_tmp);
    }
}

inline void to_json(json& j, const InlineQueryResultVoice& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["voice_url"] = o.voice_url;
    j["title"] = o.title;
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.voice_duration.has_value())
        j["voice_duration"] = o.voice_duration.value();
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
    if (o.input_message_content.has_value()) {
        json _sub;
        to_json(_sub, o.input_message_content.value());
        j["input_message_content"] = std::move(_sub);
    }
}

inline void from_json(const json& j, InlineQueryResultDocument& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    o.document_url = j.contains("document_url") && !j.at("document_url").is_null()
        ? j.at("document_url").get<std::string>() : "";
    o.mime_type = j.contains("mime_type") && !j.at("mime_type").is_null()
        ? j.at("mime_type").get<std::string>() : "";
    if (j.contains("description") && !j.at("description").is_null())
        o.description = j.at("description").get<std::string>();
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
    if (j.contains("input_message_content") && !j.at("input_message_content").is_null()) {
        InputMessageContent _tmp{};
        from_json(j.at("input_message_content"), _tmp);
        o.input_message_content = std::move(_tmp);
    }
    if (j.contains("thumbnail_url") && !j.at("thumbnail_url").is_null())
        o.thumbnail_url = j.at("thumbnail_url").get<std::string>();
    if (j.contains("thumbnail_width") && !j.at("thumbnail_width").is_null())
        o.thumbnail_width = j.at("thumbnail_width").get<int64_t>();
    if (j.contains("thumbnail_height") && !j.at("thumbnail_height").is_null())
        o.thumbnail_height = j.at("thumbnail_height").get<int64_t>();
}

inline void to_json(json& j, const InlineQueryResultDocument& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["title"] = o.title;
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    j["document_url"] = o.document_url;
    j["mime_type"] = o.mime_type;
    if (o.description.has_value())
        j["description"] = o.description.value();
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
    if (o.input_message_content.has_value()) {
        json _sub;
        to_json(_sub, o.input_message_content.value());
        j["input_message_content"] = std::move(_sub);
    }
    if (o.thumbnail_url.has_value())
        j["thumbnail_url"] = o.thumbnail_url.value();
    if (o.thumbnail_width.has_value())
        j["thumbnail_width"] = o.thumbnail_width.value();
    if (o.thumbnail_height.has_value())
        j["thumbnail_height"] = o.thumbnail_height.value();
}

inline void from_json(const json& j, InlineQueryResultLocation& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.latitude = j.contains("latitude") && !j.at("latitude").is_null()
        ? j.at("latitude").get<double>() : 0.0;
    o.longitude = j.contains("longitude") && !j.at("longitude").is_null()
        ? j.at("longitude").get<double>() : 0.0;
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    if (j.contains("horizontal_accuracy") && !j.at("horizontal_accuracy").is_null())
        o.horizontal_accuracy = j.at("horizontal_accuracy").get<double>();
    if (j.contains("live_period") && !j.at("live_period").is_null())
        o.live_period = j.at("live_period").get<int64_t>();
    if (j.contains("heading") && !j.at("heading").is_null())
        o.heading = j.at("heading").get<int64_t>();
    if (j.contains("proximity_alert_radius") && !j.at("proximity_alert_radius").is_null())
        o.proximity_alert_radius = j.at("proximity_alert_radius").get<int64_t>();
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
    if (j.contains("input_message_content") && !j.at("input_message_content").is_null()) {
        InputMessageContent _tmp{};
        from_json(j.at("input_message_content"), _tmp);
        o.input_message_content = std::move(_tmp);
    }
    if (j.contains("thumbnail_url") && !j.at("thumbnail_url").is_null())
        o.thumbnail_url = j.at("thumbnail_url").get<std::string>();
    if (j.contains("thumbnail_width") && !j.at("thumbnail_width").is_null())
        o.thumbnail_width = j.at("thumbnail_width").get<int64_t>();
    if (j.contains("thumbnail_height") && !j.at("thumbnail_height").is_null())
        o.thumbnail_height = j.at("thumbnail_height").get<int64_t>();
}

inline void to_json(json& j, const InlineQueryResultLocation& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["latitude"] = o.latitude;
    j["longitude"] = o.longitude;
    j["title"] = o.title;
    if (o.horizontal_accuracy.has_value())
        j["horizontal_accuracy"] = o.horizontal_accuracy.value();
    if (o.live_period.has_value())
        j["live_period"] = o.live_period.value();
    if (o.heading.has_value())
        j["heading"] = o.heading.value();
    if (o.proximity_alert_radius.has_value())
        j["proximity_alert_radius"] = o.proximity_alert_radius.value();
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
    if (o.input_message_content.has_value()) {
        json _sub;
        to_json(_sub, o.input_message_content.value());
        j["input_message_content"] = std::move(_sub);
    }
    if (o.thumbnail_url.has_value())
        j["thumbnail_url"] = o.thumbnail_url.value();
    if (o.thumbnail_width.has_value())
        j["thumbnail_width"] = o.thumbnail_width.value();
    if (o.thumbnail_height.has_value())
        j["thumbnail_height"] = o.thumbnail_height.value();
}

inline void from_json(const json& j, InlineQueryResultVenue& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.latitude = j.contains("latitude") && !j.at("latitude").is_null()
        ? j.at("latitude").get<double>() : 0.0;
    o.longitude = j.contains("longitude") && !j.at("longitude").is_null()
        ? j.at("longitude").get<double>() : 0.0;
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    o.address = j.contains("address") && !j.at("address").is_null()
        ? j.at("address").get<std::string>() : "";
    if (j.contains("foursquare_id") && !j.at("foursquare_id").is_null())
        o.foursquare_id = j.at("foursquare_id").get<std::string>();
    if (j.contains("foursquare_type") && !j.at("foursquare_type").is_null())
        o.foursquare_type = j.at("foursquare_type").get<std::string>();
    if (j.contains("google_place_id") && !j.at("google_place_id").is_null())
        o.google_place_id = j.at("google_place_id").get<std::string>();
    if (j.contains("google_place_type") && !j.at("google_place_type").is_null())
        o.google_place_type = j.at("google_place_type").get<std::string>();
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
    if (j.contains("input_message_content") && !j.at("input_message_content").is_null()) {
        InputMessageContent _tmp{};
        from_json(j.at("input_message_content"), _tmp);
        o.input_message_content = std::move(_tmp);
    }
    if (j.contains("thumbnail_url") && !j.at("thumbnail_url").is_null())
        o.thumbnail_url = j.at("thumbnail_url").get<std::string>();
    if (j.contains("thumbnail_width") && !j.at("thumbnail_width").is_null())
        o.thumbnail_width = j.at("thumbnail_width").get<int64_t>();
    if (j.contains("thumbnail_height") && !j.at("thumbnail_height").is_null())
        o.thumbnail_height = j.at("thumbnail_height").get<int64_t>();
}

inline void to_json(json& j, const InlineQueryResultVenue& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["latitude"] = o.latitude;
    j["longitude"] = o.longitude;
    j["title"] = o.title;
    j["address"] = o.address;
    if (o.foursquare_id.has_value())
        j["foursquare_id"] = o.foursquare_id.value();
    if (o.foursquare_type.has_value())
        j["foursquare_type"] = o.foursquare_type.value();
    if (o.google_place_id.has_value())
        j["google_place_id"] = o.google_place_id.value();
    if (o.google_place_type.has_value())
        j["google_place_type"] = o.google_place_type.value();
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
    if (o.input_message_content.has_value()) {
        json _sub;
        to_json(_sub, o.input_message_content.value());
        j["input_message_content"] = std::move(_sub);
    }
    if (o.thumbnail_url.has_value())
        j["thumbnail_url"] = o.thumbnail_url.value();
    if (o.thumbnail_width.has_value())
        j["thumbnail_width"] = o.thumbnail_width.value();
    if (o.thumbnail_height.has_value())
        j["thumbnail_height"] = o.thumbnail_height.value();
}

inline void from_json(const json& j, InlineQueryResultContact& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.phone_number = j.contains("phone_number") && !j.at("phone_number").is_null()
        ? j.at("phone_number").get<std::string>() : "";
    o.first_name = j.contains("first_name") && !j.at("first_name").is_null()
        ? j.at("first_name").get<std::string>() : "";
    if (j.contains("last_name") && !j.at("last_name").is_null())
        o.last_name = j.at("last_name").get<std::string>();
    if (j.contains("vcard") && !j.at("vcard").is_null())
        o.vcard = j.at("vcard").get<std::string>();
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
    if (j.contains("input_message_content") && !j.at("input_message_content").is_null()) {
        InputMessageContent _tmp{};
        from_json(j.at("input_message_content"), _tmp);
        o.input_message_content = std::move(_tmp);
    }
    if (j.contains("thumbnail_url") && !j.at("thumbnail_url").is_null())
        o.thumbnail_url = j.at("thumbnail_url").get<std::string>();
    if (j.contains("thumbnail_width") && !j.at("thumbnail_width").is_null())
        o.thumbnail_width = j.at("thumbnail_width").get<int64_t>();
    if (j.contains("thumbnail_height") && !j.at("thumbnail_height").is_null())
        o.thumbnail_height = j.at("thumbnail_height").get<int64_t>();
}

inline void to_json(json& j, const InlineQueryResultContact& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["phone_number"] = o.phone_number;
    j["first_name"] = o.first_name;
    if (o.last_name.has_value())
        j["last_name"] = o.last_name.value();
    if (o.vcard.has_value())
        j["vcard"] = o.vcard.value();
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
    if (o.input_message_content.has_value()) {
        json _sub;
        to_json(_sub, o.input_message_content.value());
        j["input_message_content"] = std::move(_sub);
    }
    if (o.thumbnail_url.has_value())
        j["thumbnail_url"] = o.thumbnail_url.value();
    if (o.thumbnail_width.has_value())
        j["thumbnail_width"] = o.thumbnail_width.value();
    if (o.thumbnail_height.has_value())
        j["thumbnail_height"] = o.thumbnail_height.value();
}

inline void from_json(const json& j, InlineQueryResultGame& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.game_short_name = j.contains("game_short_name") && !j.at("game_short_name").is_null()
        ? j.at("game_short_name").get<std::string>() : "";
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
}

inline void to_json(json& j, const InlineQueryResultGame& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["game_short_name"] = o.game_short_name;
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
}

inline void from_json(const json& j, InlineQueryResultCachedPhoto& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.photo_file_id = j.contains("photo_file_id") && !j.at("photo_file_id").is_null()
        ? j.at("photo_file_id").get<std::string>() : "";
    if (j.contains("title") && !j.at("title").is_null())
        o.title = j.at("title").get<std::string>();
    if (j.contains("description") && !j.at("description").is_null())
        o.description = j.at("description").get<std::string>();
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("show_caption_above_media") && !j.at("show_caption_above_media").is_null())
        o.show_caption_above_media = j.at("show_caption_above_media").get<bool>();
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
    if (j.contains("input_message_content") && !j.at("input_message_content").is_null()) {
        InputMessageContent _tmp{};
        from_json(j.at("input_message_content"), _tmp);
        o.input_message_content = std::move(_tmp);
    }
}

inline void to_json(json& j, const InlineQueryResultCachedPhoto& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["photo_file_id"] = o.photo_file_id;
    if (o.title.has_value())
        j["title"] = o.title.value();
    if (o.description.has_value())
        j["description"] = o.description.value();
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.show_caption_above_media.has_value())
        j["show_caption_above_media"] = o.show_caption_above_media.value();
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
    if (o.input_message_content.has_value()) {
        json _sub;
        to_json(_sub, o.input_message_content.value());
        j["input_message_content"] = std::move(_sub);
    }
}

inline void from_json(const json& j, InlineQueryResultCachedGif& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.gif_file_id = j.contains("gif_file_id") && !j.at("gif_file_id").is_null()
        ? j.at("gif_file_id").get<std::string>() : "";
    if (j.contains("title") && !j.at("title").is_null())
        o.title = j.at("title").get<std::string>();
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("show_caption_above_media") && !j.at("show_caption_above_media").is_null())
        o.show_caption_above_media = j.at("show_caption_above_media").get<bool>();
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
    if (j.contains("input_message_content") && !j.at("input_message_content").is_null()) {
        InputMessageContent _tmp{};
        from_json(j.at("input_message_content"), _tmp);
        o.input_message_content = std::move(_tmp);
    }
}

inline void to_json(json& j, const InlineQueryResultCachedGif& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["gif_file_id"] = o.gif_file_id;
    if (o.title.has_value())
        j["title"] = o.title.value();
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.show_caption_above_media.has_value())
        j["show_caption_above_media"] = o.show_caption_above_media.value();
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
    if (o.input_message_content.has_value()) {
        json _sub;
        to_json(_sub, o.input_message_content.value());
        j["input_message_content"] = std::move(_sub);
    }
}

inline void from_json(const json& j, InlineQueryResultCachedMpeg4Gif& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.mpeg4_file_id = j.contains("mpeg4_file_id") && !j.at("mpeg4_file_id").is_null()
        ? j.at("mpeg4_file_id").get<std::string>() : "";
    if (j.contains("title") && !j.at("title").is_null())
        o.title = j.at("title").get<std::string>();
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("show_caption_above_media") && !j.at("show_caption_above_media").is_null())
        o.show_caption_above_media = j.at("show_caption_above_media").get<bool>();
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
    if (j.contains("input_message_content") && !j.at("input_message_content").is_null()) {
        InputMessageContent _tmp{};
        from_json(j.at("input_message_content"), _tmp);
        o.input_message_content = std::move(_tmp);
    }
}

inline void to_json(json& j, const InlineQueryResultCachedMpeg4Gif& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["mpeg4_file_id"] = o.mpeg4_file_id;
    if (o.title.has_value())
        j["title"] = o.title.value();
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.show_caption_above_media.has_value())
        j["show_caption_above_media"] = o.show_caption_above_media.value();
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
    if (o.input_message_content.has_value()) {
        json _sub;
        to_json(_sub, o.input_message_content.value());
        j["input_message_content"] = std::move(_sub);
    }
}

inline void from_json(const json& j, InlineQueryResultCachedSticker& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.sticker_file_id = j.contains("sticker_file_id") && !j.at("sticker_file_id").is_null()
        ? j.at("sticker_file_id").get<std::string>() : "";
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
    if (j.contains("input_message_content") && !j.at("input_message_content").is_null()) {
        InputMessageContent _tmp{};
        from_json(j.at("input_message_content"), _tmp);
        o.input_message_content = std::move(_tmp);
    }
}

inline void to_json(json& j, const InlineQueryResultCachedSticker& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["sticker_file_id"] = o.sticker_file_id;
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
    if (o.input_message_content.has_value()) {
        json _sub;
        to_json(_sub, o.input_message_content.value());
        j["input_message_content"] = std::move(_sub);
    }
}

inline void from_json(const json& j, InlineQueryResultCachedDocument& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    o.document_file_id = j.contains("document_file_id") && !j.at("document_file_id").is_null()
        ? j.at("document_file_id").get<std::string>() : "";
    if (j.contains("description") && !j.at("description").is_null())
        o.description = j.at("description").get<std::string>();
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
    if (j.contains("input_message_content") && !j.at("input_message_content").is_null()) {
        InputMessageContent _tmp{};
        from_json(j.at("input_message_content"), _tmp);
        o.input_message_content = std::move(_tmp);
    }
}

inline void to_json(json& j, const InlineQueryResultCachedDocument& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["title"] = o.title;
    j["document_file_id"] = o.document_file_id;
    if (o.description.has_value())
        j["description"] = o.description.value();
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
    if (o.input_message_content.has_value()) {
        json _sub;
        to_json(_sub, o.input_message_content.value());
        j["input_message_content"] = std::move(_sub);
    }
}

inline void from_json(const json& j, InlineQueryResultCachedVideo& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.video_file_id = j.contains("video_file_id") && !j.at("video_file_id").is_null()
        ? j.at("video_file_id").get<std::string>() : "";
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    if (j.contains("description") && !j.at("description").is_null())
        o.description = j.at("description").get<std::string>();
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("show_caption_above_media") && !j.at("show_caption_above_media").is_null())
        o.show_caption_above_media = j.at("show_caption_above_media").get<bool>();
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
    if (j.contains("input_message_content") && !j.at("input_message_content").is_null()) {
        InputMessageContent _tmp{};
        from_json(j.at("input_message_content"), _tmp);
        o.input_message_content = std::move(_tmp);
    }
}

inline void to_json(json& j, const InlineQueryResultCachedVideo& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["video_file_id"] = o.video_file_id;
    j["title"] = o.title;
    if (o.description.has_value())
        j["description"] = o.description.value();
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.show_caption_above_media.has_value())
        j["show_caption_above_media"] = o.show_caption_above_media.value();
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
    if (o.input_message_content.has_value()) {
        json _sub;
        to_json(_sub, o.input_message_content.value());
        j["input_message_content"] = std::move(_sub);
    }
}

inline void from_json(const json& j, InlineQueryResultCachedVoice& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.voice_file_id = j.contains("voice_file_id") && !j.at("voice_file_id").is_null()
        ? j.at("voice_file_id").get<std::string>() : "";
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
    if (j.contains("input_message_content") && !j.at("input_message_content").is_null()) {
        InputMessageContent _tmp{};
        from_json(j.at("input_message_content"), _tmp);
        o.input_message_content = std::move(_tmp);
    }
}

inline void to_json(json& j, const InlineQueryResultCachedVoice& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["voice_file_id"] = o.voice_file_id;
    j["title"] = o.title;
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
    if (o.input_message_content.has_value()) {
        json _sub;
        to_json(_sub, o.input_message_content.value());
        j["input_message_content"] = std::move(_sub);
    }
}

inline void from_json(const json& j, InlineQueryResultCachedAudio& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.audio_file_id = j.contains("audio_file_id") && !j.at("audio_file_id").is_null()
        ? j.at("audio_file_id").get<std::string>() : "";
    if (j.contains("caption") && !j.at("caption").is_null())
        o.caption = j.at("caption").get<std::string>();
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("caption_entities") && j.at("caption_entities").is_array()) {
        for (const auto& _item : j.at("caption_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.caption_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("reply_markup") && !j.at("reply_markup").is_null()) {
        o.reply_markup = std::make_shared<InlineKeyboardMarkup>();
        from_json(j.at("reply_markup"), *o.reply_markup);
    }
    if (j.contains("input_message_content") && !j.at("input_message_content").is_null()) {
        InputMessageContent _tmp{};
        from_json(j.at("input_message_content"), _tmp);
        o.input_message_content = std::move(_tmp);
    }
}

inline void to_json(json& j, const InlineQueryResultCachedAudio& o) {
    j = json::object();
    j["type"] = o.type;
    j["id"] = o.id;
    j["audio_file_id"] = o.audio_file_id;
    if (o.caption.has_value())
        j["caption"] = o.caption.value();
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.caption_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["caption_entities"] = std::move(_arr);
    }
    if (o.reply_markup) {
        json _sub; to_json(_sub, *o.reply_markup); j["reply_markup"] = std::move(_sub);
    }
    if (o.input_message_content.has_value()) {
        json _sub;
        to_json(_sub, o.input_message_content.value());
        j["input_message_content"] = std::move(_sub);
    }
}

inline void from_json(const json& j, InputMessageContent& v) {
    if (j.contains("message_text")) {
        auto obj = std::make_shared<InputTextMessageContent>();
        from_json(j, *obj); v = obj; return;
    }
    if (j.contains("phone_number")) {
        auto obj = std::make_shared<InputContactMessageContent>();
        from_json(j, *obj); v = obj; return;
    }
    if (j.contains("prices")) {
        auto obj = std::make_shared<InputInvoiceMessageContent>();
        from_json(j, *obj); v = obj; return;
    }
    if (j.contains("latitude") && j.contains("title")) {
        auto obj = std::make_shared<InputVenueMessageContent>();
        from_json(j, *obj); v = obj; return;
    }
    if (j.contains("latitude")) {
        auto obj = std::make_shared<InputLocationMessageContent>();
        from_json(j, *obj); v = obj; return;
    }
    throw std::runtime_error("Unknown InputMessageContent fields");
}

inline void to_json(json& j, const InputMessageContent& v) {
    if (auto* p = std::get_if <std::shared_ptr<InputTextMessageContent>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputLocationMessageContent>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputVenueMessageContent>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputContactMessageContent>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<InputInvoiceMessageContent>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, InputTextMessageContent& o) {
    o.message_text = j.contains("message_text") && !j.at("message_text").is_null()
        ? j.at("message_text").get<std::string>() : "";
    if (j.contains("parse_mode") && !j.at("parse_mode").is_null())
        o.parse_mode = j.at("parse_mode").get<std::string>();
    if (j.contains("entities") && j.at("entities").is_array()) {
        for (const auto& _item : j.at("entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("link_preview_options") && !j.at("link_preview_options").is_null()) {
        o.link_preview_options = std::make_shared<LinkPreviewOptions>();
        from_json(j.at("link_preview_options"), *o.link_preview_options);
    }
}

inline void to_json(json& j, const InputTextMessageContent& o) {
    j = json::object();
    j["message_text"] = o.message_text;
    if (o.parse_mode.has_value())
        j["parse_mode"] = o.parse_mode.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["entities"] = std::move(_arr);
    }
    if (o.link_preview_options) {
        json _sub; to_json(_sub, *o.link_preview_options); j["link_preview_options"] = std::move(_sub);
    }
}

inline void from_json(const json& j, InputLocationMessageContent& o) {
    o.latitude = j.contains("latitude") && !j.at("latitude").is_null()
        ? j.at("latitude").get<double>() : 0.0;
    o.longitude = j.contains("longitude") && !j.at("longitude").is_null()
        ? j.at("longitude").get<double>() : 0.0;
    if (j.contains("horizontal_accuracy") && !j.at("horizontal_accuracy").is_null())
        o.horizontal_accuracy = j.at("horizontal_accuracy").get<double>();
    if (j.contains("live_period") && !j.at("live_period").is_null())
        o.live_period = j.at("live_period").get<int64_t>();
    if (j.contains("heading") && !j.at("heading").is_null())
        o.heading = j.at("heading").get<int64_t>();
    if (j.contains("proximity_alert_radius") && !j.at("proximity_alert_radius").is_null())
        o.proximity_alert_radius = j.at("proximity_alert_radius").get<int64_t>();
}

inline void to_json(json& j, const InputLocationMessageContent& o) {
    j = json::object();
    j["latitude"] = o.latitude;
    j["longitude"] = o.longitude;
    if (o.horizontal_accuracy.has_value())
        j["horizontal_accuracy"] = o.horizontal_accuracy.value();
    if (o.live_period.has_value())
        j["live_period"] = o.live_period.value();
    if (o.heading.has_value())
        j["heading"] = o.heading.value();
    if (o.proximity_alert_radius.has_value())
        j["proximity_alert_radius"] = o.proximity_alert_radius.value();
}

inline void from_json(const json& j, InputVenueMessageContent& o) {
    o.latitude = j.contains("latitude") && !j.at("latitude").is_null()
        ? j.at("latitude").get<double>() : 0.0;
    o.longitude = j.contains("longitude") && !j.at("longitude").is_null()
        ? j.at("longitude").get<double>() : 0.0;
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    o.address = j.contains("address") && !j.at("address").is_null()
        ? j.at("address").get<std::string>() : "";
    if (j.contains("foursquare_id") && !j.at("foursquare_id").is_null())
        o.foursquare_id = j.at("foursquare_id").get<std::string>();
    if (j.contains("foursquare_type") && !j.at("foursquare_type").is_null())
        o.foursquare_type = j.at("foursquare_type").get<std::string>();
    if (j.contains("google_place_id") && !j.at("google_place_id").is_null())
        o.google_place_id = j.at("google_place_id").get<std::string>();
    if (j.contains("google_place_type") && !j.at("google_place_type").is_null())
        o.google_place_type = j.at("google_place_type").get<std::string>();
}

inline void to_json(json& j, const InputVenueMessageContent& o) {
    j = json::object();
    j["latitude"] = o.latitude;
    j["longitude"] = o.longitude;
    j["title"] = o.title;
    j["address"] = o.address;
    if (o.foursquare_id.has_value())
        j["foursquare_id"] = o.foursquare_id.value();
    if (o.foursquare_type.has_value())
        j["foursquare_type"] = o.foursquare_type.value();
    if (o.google_place_id.has_value())
        j["google_place_id"] = o.google_place_id.value();
    if (o.google_place_type.has_value())
        j["google_place_type"] = o.google_place_type.value();
}

inline void from_json(const json& j, InputContactMessageContent& o) {
    o.phone_number = j.contains("phone_number") && !j.at("phone_number").is_null()
        ? j.at("phone_number").get<std::string>() : "";
    o.first_name = j.contains("first_name") && !j.at("first_name").is_null()
        ? j.at("first_name").get<std::string>() : "";
    if (j.contains("last_name") && !j.at("last_name").is_null())
        o.last_name = j.at("last_name").get<std::string>();
    if (j.contains("vcard") && !j.at("vcard").is_null())
        o.vcard = j.at("vcard").get<std::string>();
}

inline void to_json(json& j, const InputContactMessageContent& o) {
    j = json::object();
    j["phone_number"] = o.phone_number;
    j["first_name"] = o.first_name;
    if (o.last_name.has_value())
        j["last_name"] = o.last_name.value();
    if (o.vcard.has_value())
        j["vcard"] = o.vcard.value();
}

inline void from_json(const json& j, InputInvoiceMessageContent& o) {
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    o.description = j.contains("description") && !j.at("description").is_null()
        ? j.at("description").get<std::string>() : "";
    o.invoice_payload = j.contains("payload") && !j.at("payload").is_null()
        ? j.at("payload").get<std::string>() : "";
    if (j.contains("provider_token") && !j.at("provider_token").is_null())
        o.provider_token = j.at("provider_token").get<std::string>();
    o.currency = j.contains("currency") && !j.at("currency").is_null()
        ? j.at("currency").get<std::string>() : "";
    if (j.contains("prices") && j.at("prices").is_array()) {
        for (const auto& _item : j.at("prices")) {
            {
                auto _elem = std::make_shared<LabeledPrice>();
                from_json(_item, *_elem);
                o.prices.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("max_tip_amount") && !j.at("max_tip_amount").is_null())
        o.max_tip_amount = j.at("max_tip_amount").get<int64_t>();
    if (j.contains("suggested_tip_amounts") && j.at("suggested_tip_amounts").is_array()) {
        for (const auto& _item : j.at("suggested_tip_amounts")) {
            o.suggested_tip_amounts.push_back(_item.get<int64_t>());
        }
    }
    if (j.contains("provider_data") && !j.at("provider_data").is_null())
        o.provider_data = j.at("provider_data").get<std::string>();
    if (j.contains("photo_url") && !j.at("photo_url").is_null())
        o.photo_url = j.at("photo_url").get<std::string>();
    if (j.contains("photo_size") && !j.at("photo_size").is_null())
        o.photo_size = j.at("photo_size").get<int64_t>();
    if (j.contains("photo_width") && !j.at("photo_width").is_null())
        o.photo_width = j.at("photo_width").get<int64_t>();
    if (j.contains("photo_height") && !j.at("photo_height").is_null())
        o.photo_height = j.at("photo_height").get<int64_t>();
    if (j.contains("need_name") && !j.at("need_name").is_null())
        o.need_name = j.at("need_name").get<bool>();
    if (j.contains("need_phone_number") && !j.at("need_phone_number").is_null())
        o.need_phone_number = j.at("need_phone_number").get<bool>();
    if (j.contains("need_email") && !j.at("need_email").is_null())
        o.need_email = j.at("need_email").get<bool>();
    if (j.contains("need_shipping_address") && !j.at("need_shipping_address").is_null())
        o.need_shipping_address = j.at("need_shipping_address").get<bool>();
    if (j.contains("send_phone_number_to_provider") && !j.at("send_phone_number_to_provider").is_null())
        o.send_phone_number_to_provider = j.at("send_phone_number_to_provider").get<bool>();
    if (j.contains("send_email_to_provider") && !j.at("send_email_to_provider").is_null())
        o.send_email_to_provider = j.at("send_email_to_provider").get<bool>();
    if (j.contains("is_flexible") && !j.at("is_flexible").is_null())
        o.is_flexible = j.at("is_flexible").get<bool>();
}

inline void to_json(json& j, const InputInvoiceMessageContent& o) {
    j = json::object();
    j["title"] = o.title;
    j["description"] = o.description;
    j["payload"] = o.invoice_payload;
    if (o.provider_token.has_value())
        j["provider_token"] = o.provider_token.value();
    j["currency"] = o.currency;
    {
        json _arr = json::array();
        for (const auto& _item : o.prices) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["prices"] = std::move(_arr);
    }
    if (o.max_tip_amount.has_value())
        j["max_tip_amount"] = o.max_tip_amount.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.suggested_tip_amounts) {
            _arr.push_back(_item);
        }
        j["suggested_tip_amounts"] = std::move(_arr);
    }
    if (o.provider_data.has_value())
        j["provider_data"] = o.provider_data.value();
    if (o.photo_url.has_value())
        j["photo_url"] = o.photo_url.value();
    if (o.photo_size.has_value())
        j["photo_size"] = o.photo_size.value();
    if (o.photo_width.has_value())
        j["photo_width"] = o.photo_width.value();
    if (o.photo_height.has_value())
        j["photo_height"] = o.photo_height.value();
    if (o.need_name.has_value())
        j["need_name"] = o.need_name.value();
    if (o.need_phone_number.has_value())
        j["need_phone_number"] = o.need_phone_number.value();
    if (o.need_email.has_value())
        j["need_email"] = o.need_email.value();
    if (o.need_shipping_address.has_value())
        j["need_shipping_address"] = o.need_shipping_address.value();
    if (o.send_phone_number_to_provider.has_value())
        j["send_phone_number_to_provider"] = o.send_phone_number_to_provider.value();
    if (o.send_email_to_provider.has_value())
        j["send_email_to_provider"] = o.send_email_to_provider.value();
    if (o.is_flexible.has_value())
        j["is_flexible"] = o.is_flexible.value();
}

inline void from_json(const json& j, ChosenInlineResult& o) {
    o.result_id = j.contains("result_id") && !j.at("result_id").is_null()
        ? j.at("result_id").get<std::string>() : "";
    if (j.contains("from") && !j.at("from").is_null()) {
        o.from = std::make_shared<User>();
        from_json(j.at("from"), *o.from);
    }
    if (j.contains("location") && !j.at("location").is_null()) {
        o.location = std::make_shared<Location>();
        from_json(j.at("location"), *o.location);
    }
    if (j.contains("inline_message_id") && !j.at("inline_message_id").is_null())
        o.inline_message_id = j.at("inline_message_id").get<std::string>();
    o.query = j.contains("query") && !j.at("query").is_null()
        ? j.at("query").get<std::string>() : "";
}

inline void to_json(json& j, const ChosenInlineResult& o) {
    j = json::object();
    j["result_id"] = o.result_id;
    {
        json _sub; to_json(_sub, *o.from); j["from"] = std::move(_sub);
    }
    if (o.location) {
        json _sub; to_json(_sub, *o.location); j["location"] = std::move(_sub);
    }
    if (o.inline_message_id.has_value())
        j["inline_message_id"] = o.inline_message_id.value();
    j["query"] = o.query;
}

inline void from_json(const json& j, LabeledPrice& o) {
    o.label = j.contains("label") && !j.at("label").is_null()
        ? j.at("label").get<std::string>() : "";
    o.amount = j.contains("amount") && !j.at("amount").is_null()
        ? j.at("amount").get<int64_t>() : 0;
}

inline void to_json(json& j, const LabeledPrice& o) {
    j = json::object();
    j["label"] = o.label;
    j["amount"] = o.amount;
}

inline void from_json(const json& j, Invoice& o) {
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    o.description = j.contains("description") && !j.at("description").is_null()
        ? j.at("description").get<std::string>() : "";
    o.start_parameter = j.contains("start_parameter") && !j.at("start_parameter").is_null()
        ? j.at("start_parameter").get<std::string>() : "";
    o.currency = j.contains("currency") && !j.at("currency").is_null()
        ? j.at("currency").get<std::string>() : "";
    o.total_amount = j.contains("total_amount") && !j.at("total_amount").is_null()
        ? j.at("total_amount").get<int64_t>() : 0;
}

inline void to_json(json& j, const Invoice& o) {
    j = json::object();
    j["title"] = o.title;
    j["description"] = o.description;
    j["start_parameter"] = o.start_parameter;
    j["currency"] = o.currency;
    j["total_amount"] = o.total_amount;
}

inline void from_json(const json& j, ShippingAddress& o) {
    o.country_code = j.contains("country_code") && !j.at("country_code").is_null()
        ? j.at("country_code").get<std::string>() : "";
    o.state = j.contains("state") && !j.at("state").is_null()
        ? j.at("state").get<std::string>() : "";
    o.city = j.contains("city") && !j.at("city").is_null()
        ? j.at("city").get<std::string>() : "";
    o.street_line1 = j.contains("street_line1") && !j.at("street_line1").is_null()
        ? j.at("street_line1").get<std::string>() : "";
    o.street_line2 = j.contains("street_line2") && !j.at("street_line2").is_null()
        ? j.at("street_line2").get<std::string>() : "";
    o.post_code = j.contains("post_code") && !j.at("post_code").is_null()
        ? j.at("post_code").get<std::string>() : "";
}

inline void to_json(json& j, const ShippingAddress& o) {
    j = json::object();
    j["country_code"] = o.country_code;
    j["state"] = o.state;
    j["city"] = o.city;
    j["street_line1"] = o.street_line1;
    j["street_line2"] = o.street_line2;
    j["post_code"] = o.post_code;
}

inline void from_json(const json& j, OrderInfo& o) {
    if (j.contains("name") && !j.at("name").is_null())
        o.name = j.at("name").get<std::string>();
    if (j.contains("phone_number") && !j.at("phone_number").is_null())
        o.phone_number = j.at("phone_number").get<std::string>();
    if (j.contains("email") && !j.at("email").is_null())
        o.email = j.at("email").get<std::string>();
    if (j.contains("shipping_address") && !j.at("shipping_address").is_null()) {
        o.shipping_address = std::make_shared<ShippingAddress>();
        from_json(j.at("shipping_address"), *o.shipping_address);
    }
}

inline void to_json(json& j, const OrderInfo& o) {
    j = json::object();
    if (o.name.has_value())
        j["name"] = o.name.value();
    if (o.phone_number.has_value())
        j["phone_number"] = o.phone_number.value();
    if (o.email.has_value())
        j["email"] = o.email.value();
    if (o.shipping_address) {
        json _sub; to_json(_sub, *o.shipping_address); j["shipping_address"] = std::move(_sub);
    }
}

inline void from_json(const json& j, ShippingOption& o) {
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    if (j.contains("prices") && j.at("prices").is_array()) {
        for (const auto& _item : j.at("prices")) {
            {
                auto _elem = std::make_shared<LabeledPrice>();
                from_json(_item, *_elem);
                o.prices.push_back(std::move(_elem));
            }
        }
    }
}

inline void to_json(json& j, const ShippingOption& o) {
    j = json::object();
    j["id"] = o.id;
    j["title"] = o.title;
    {
        json _arr = json::array();
        for (const auto& _item : o.prices) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["prices"] = std::move(_arr);
    }
}

inline void from_json(const json& j, SuccessfulPayment& o) {
    o.currency = j.contains("currency") && !j.at("currency").is_null()
        ? j.at("currency").get<std::string>() : "";
    o.total_amount = j.contains("total_amount") && !j.at("total_amount").is_null()
        ? j.at("total_amount").get<int64_t>() : 0;
    o.invoice_payload = j.contains("invoice_payload") && !j.at("invoice_payload").is_null()
        ? j.at("invoice_payload").get<std::string>() : "";
    if (j.contains("subscription_expiration_date") && !j.at("subscription_expiration_date").is_null())
        o.subscription_expiration_date = j.at("subscription_expiration_date").get<int64_t>();
    if (j.contains("is_recurring") && !j.at("is_recurring").is_null())
        o.is_recurring = j.at("is_recurring").get<bool>();
    if (j.contains("is_first_recurring") && !j.at("is_first_recurring").is_null())
        o.is_first_recurring = j.at("is_first_recurring").get<bool>();
    if (j.contains("shipping_option_id") && !j.at("shipping_option_id").is_null())
        o.shipping_option_id = j.at("shipping_option_id").get<std::string>();
    if (j.contains("order_info") && !j.at("order_info").is_null()) {
        o.order_info = std::make_shared<OrderInfo>();
        from_json(j.at("order_info"), *o.order_info);
    }
    o.telegram_payment_charge_id = j.contains("telegram_payment_charge_id") && !j.at("telegram_payment_charge_id").is_null()
        ? j.at("telegram_payment_charge_id").get<std::string>() : "";
    o.provider_payment_charge_id = j.contains("provider_payment_charge_id") && !j.at("provider_payment_charge_id").is_null()
        ? j.at("provider_payment_charge_id").get<std::string>() : "";
}

inline void to_json(json& j, const SuccessfulPayment& o) {
    j = json::object();
    j["currency"] = o.currency;
    j["total_amount"] = o.total_amount;
    j["invoice_payload"] = o.invoice_payload;
    if (o.subscription_expiration_date.has_value())
        j["subscription_expiration_date"] = o.subscription_expiration_date.value();
    if (o.is_recurring.has_value())
        j["is_recurring"] = o.is_recurring.value();
    if (o.is_first_recurring.has_value())
        j["is_first_recurring"] = o.is_first_recurring.value();
    if (o.shipping_option_id.has_value())
        j["shipping_option_id"] = o.shipping_option_id.value();
    if (o.order_info) {
        json _sub; to_json(_sub, *o.order_info); j["order_info"] = std::move(_sub);
    }
    j["telegram_payment_charge_id"] = o.telegram_payment_charge_id;
    j["provider_payment_charge_id"] = o.provider_payment_charge_id;
}

inline void from_json(const json& j, RefundedPayment& o) {
    o.currency = j.contains("currency") && !j.at("currency").is_null()
        ? j.at("currency").get<std::string>() : "";
    o.total_amount = j.contains("total_amount") && !j.at("total_amount").is_null()
        ? j.at("total_amount").get<int64_t>() : 0;
    o.invoice_payload = j.contains("invoice_payload") && !j.at("invoice_payload").is_null()
        ? j.at("invoice_payload").get<std::string>() : "";
    o.telegram_payment_charge_id = j.contains("telegram_payment_charge_id") && !j.at("telegram_payment_charge_id").is_null()
        ? j.at("telegram_payment_charge_id").get<std::string>() : "";
    if (j.contains("provider_payment_charge_id") && !j.at("provider_payment_charge_id").is_null())
        o.provider_payment_charge_id = j.at("provider_payment_charge_id").get<std::string>();
}

inline void to_json(json& j, const RefundedPayment& o) {
    j = json::object();
    j["currency"] = o.currency;
    j["total_amount"] = o.total_amount;
    j["invoice_payload"] = o.invoice_payload;
    j["telegram_payment_charge_id"] = o.telegram_payment_charge_id;
    if (o.provider_payment_charge_id.has_value())
        j["provider_payment_charge_id"] = o.provider_payment_charge_id.value();
}

inline void from_json(const json& j, ShippingQuery& o) {
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    if (j.contains("from") && !j.at("from").is_null()) {
        o.from = std::make_shared<User>();
        from_json(j.at("from"), *o.from);
    }
    o.invoice_payload = j.contains("invoice_payload") && !j.at("invoice_payload").is_null()
        ? j.at("invoice_payload").get<std::string>() : "";
    if (j.contains("shipping_address") && !j.at("shipping_address").is_null()) {
        o.shipping_address = std::make_shared<ShippingAddress>();
        from_json(j.at("shipping_address"), *o.shipping_address);
    }
}

inline void to_json(json& j, const ShippingQuery& o) {
    j = json::object();
    j["id"] = o.id;
    {
        json _sub; to_json(_sub, *o.from); j["from"] = std::move(_sub);
    }
    j["invoice_payload"] = o.invoice_payload;
    {
        json _sub; to_json(_sub, *o.shipping_address); j["shipping_address"] = std::move(_sub);
    }
}

inline void from_json(const json& j, PreCheckoutQuery& o) {
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    if (j.contains("from") && !j.at("from").is_null()) {
        o.from = std::make_shared<User>();
        from_json(j.at("from"), *o.from);
    }
    o.currency = j.contains("currency") && !j.at("currency").is_null()
        ? j.at("currency").get<std::string>() : "";
    o.total_amount = j.contains("total_amount") && !j.at("total_amount").is_null()
        ? j.at("total_amount").get<int64_t>() : 0;
    o.invoice_payload = j.contains("invoice_payload") && !j.at("invoice_payload").is_null()
        ? j.at("invoice_payload").get<std::string>() : "";
    if (j.contains("shipping_option_id") && !j.at("shipping_option_id").is_null())
        o.shipping_option_id = j.at("shipping_option_id").get<std::string>();
    if (j.contains("order_info") && !j.at("order_info").is_null()) {
        o.order_info = std::make_shared<OrderInfo>();
        from_json(j.at("order_info"), *o.order_info);
    }
}

inline void to_json(json& j, const PreCheckoutQuery& o) {
    j = json::object();
    j["id"] = o.id;
    {
        json _sub; to_json(_sub, *o.from); j["from"] = std::move(_sub);
    }
    j["currency"] = o.currency;
    j["total_amount"] = o.total_amount;
    j["invoice_payload"] = o.invoice_payload;
    if (o.shipping_option_id.has_value())
        j["shipping_option_id"] = o.shipping_option_id.value();
    if (o.order_info) {
        json _sub; to_json(_sub, *o.order_info); j["order_info"] = std::move(_sub);
    }
}

inline void from_json(const json& j, PaidMediaPurchased& o) {
    if (j.contains("from") && !j.at("from").is_null()) {
        o.from = std::make_shared<User>();
        from_json(j.at("from"), *o.from);
    }
    o.paid_media_payload = j.contains("paid_media_payload") && !j.at("paid_media_payload").is_null()
        ? j.at("paid_media_payload").get<std::string>() : "";
}

inline void to_json(json& j, const PaidMediaPurchased& o) {
    j = json::object();
    {
        json _sub; to_json(_sub, *o.from); j["from"] = std::move(_sub);
    }
    j["paid_media_payload"] = o.paid_media_payload;
}

inline void from_json(const json& j, RevenueWithdrawalState& v) {
    std::string type = j.at("type").get<std::string>();
    if (type == "pending") {
        auto obj = std::make_shared<RevenueWithdrawalStatePending>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "succeeded") {
        auto obj = std::make_shared<RevenueWithdrawalStateSucceeded>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "failed") {
        auto obj = std::make_shared<RevenueWithdrawalStateFailed>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const RevenueWithdrawalState& v) {
    if (auto* p = std::get_if <std::shared_ptr<RevenueWithdrawalStatePending>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<RevenueWithdrawalStateSucceeded>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<RevenueWithdrawalStateFailed>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, RevenueWithdrawalStatePending& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
}

inline void to_json(json& j, const RevenueWithdrawalStatePending& o) {
    j = json::object();
    j["type"] = o.type;
}

inline void from_json(const json& j, RevenueWithdrawalStateSucceeded& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.date = j.contains("date") && !j.at("date").is_null()
        ? j.at("date").get<int64_t>() : 0;
    o.url = j.contains("url") && !j.at("url").is_null()
        ? j.at("url").get<std::string>() : "";
}

inline void to_json(json& j, const RevenueWithdrawalStateSucceeded& o) {
    j = json::object();
    j["type"] = o.type;
    j["date"] = o.date;
    j["url"] = o.url;
}

inline void from_json(const json& j, RevenueWithdrawalStateFailed& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
}

inline void to_json(json& j, const RevenueWithdrawalStateFailed& o) {
    j = json::object();
    j["type"] = o.type;
}

inline void from_json(const json& j, AffiliateInfo& o) {
    if (j.contains("affiliate_user") && !j.at("affiliate_user").is_null()) {
        o.affiliate_user = std::make_shared<User>();
        from_json(j.at("affiliate_user"), *o.affiliate_user);
    }
    if (j.contains("affiliate_chat") && !j.at("affiliate_chat").is_null()) {
        o.affiliate_chat = std::make_shared<Chat>();
        from_json(j.at("affiliate_chat"), *o.affiliate_chat);
    }
    o.commission_per_mille = j.contains("commission_per_mille") && !j.at("commission_per_mille").is_null()
        ? j.at("commission_per_mille").get<int64_t>() : 0;
    o.amount = j.contains("amount") && !j.at("amount").is_null()
        ? j.at("amount").get<int64_t>() : 0;
    if (j.contains("nanostar_amount") && !j.at("nanostar_amount").is_null())
        o.nanostar_amount = j.at("nanostar_amount").get<int64_t>();
}

inline void to_json(json& j, const AffiliateInfo& o) {
    j = json::object();
    if (o.affiliate_user) {
        json _sub; to_json(_sub, *o.affiliate_user); j["affiliate_user"] = std::move(_sub);
    }
    if (o.affiliate_chat) {
        json _sub; to_json(_sub, *o.affiliate_chat); j["affiliate_chat"] = std::move(_sub);
    }
    j["commission_per_mille"] = o.commission_per_mille;
    j["amount"] = o.amount;
    if (o.nanostar_amount.has_value())
        j["nanostar_amount"] = o.nanostar_amount.value();
}

inline void from_json(const json& j, TransactionPartner& v) {
    std::string type = j.at("type").get<std::string>();
    if (type == "user") {
        auto obj = std::make_shared<TransactionPartnerUser>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "chat") {
        auto obj = std::make_shared<TransactionPartnerChat>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "affiliate_program") {
        auto obj = std::make_shared<TransactionPartnerAffiliateProgram>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "fragment") {
        auto obj = std::make_shared<TransactionPartnerFragment>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "telegram_ads") {
        auto obj = std::make_shared<TransactionPartnerTelegramAds>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "telegram_api") {
        auto obj = std::make_shared<TransactionPartnerTelegramApi>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "other") {
        auto obj = std::make_shared<TransactionPartnerOther>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const TransactionPartner& v) {
    if (auto* p = std::get_if <std::shared_ptr<TransactionPartnerUser>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<TransactionPartnerChat>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<TransactionPartnerAffiliateProgram>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<TransactionPartnerFragment>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<TransactionPartnerTelegramAds>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<TransactionPartnerTelegramApi>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<TransactionPartnerOther>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, TransactionPartnerUser& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.transaction_type = j.contains("transaction_type") && !j.at("transaction_type").is_null()
        ? j.at("transaction_type").get<std::string>() : "";
    if (j.contains("user") && !j.at("user").is_null()) {
        o.user = std::make_shared<User>();
        from_json(j.at("user"), *o.user);
    }
    if (j.contains("affiliate") && !j.at("affiliate").is_null()) {
        o.affiliate = std::make_shared<AffiliateInfo>();
        from_json(j.at("affiliate"), *o.affiliate);
    }
    if (j.contains("invoice_payload") && !j.at("invoice_payload").is_null())
        o.invoice_payload = j.at("invoice_payload").get<std::string>();
    if (j.contains("subscription_period") && !j.at("subscription_period").is_null())
        o.subscription_period = j.at("subscription_period").get<int64_t>();
    if (j.contains("paid_media") && j.at("paid_media").is_array()) {
        for (const auto& _item : j.at("paid_media")) {
            {
                PaidMedia _elem{};
                from_json(_item, _elem);
                o.paid_media.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("paid_media_payload") && !j.at("paid_media_payload").is_null())
        o.paid_media_payload = j.at("paid_media_payload").get<std::string>();
    if (j.contains("gift") && !j.at("gift").is_null()) {
        o.gift = std::make_shared<Gift>();
        from_json(j.at("gift"), *o.gift);
    }
    if (j.contains("premium_subscription_duration") && !j.at("premium_subscription_duration").is_null())
        o.premium_subscription_duration = j.at("premium_subscription_duration").get<int64_t>();
}

inline void to_json(json& j, const TransactionPartnerUser& o) {
    j = json::object();
    j["type"] = o.type;
    j["transaction_type"] = o.transaction_type;
    {
        json _sub; to_json(_sub, *o.user); j["user"] = std::move(_sub);
    }
    if (o.affiliate) {
        json _sub; to_json(_sub, *o.affiliate); j["affiliate"] = std::move(_sub);
    }
    if (o.invoice_payload.has_value())
        j["invoice_payload"] = o.invoice_payload.value();
    if (o.subscription_period.has_value())
        j["subscription_period"] = o.subscription_period.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.paid_media) {
            {
                json _e; to_json(_e, _item); _arr.push_back(std::move(_e));
            }
        }
        j["paid_media"] = std::move(_arr);
    }
    if (o.paid_media_payload.has_value())
        j["paid_media_payload"] = o.paid_media_payload.value();
    if (o.gift) {
        json _sub; to_json(_sub, *o.gift); j["gift"] = std::move(_sub);
    }
    if (o.premium_subscription_duration.has_value())
        j["premium_subscription_duration"] = o.premium_subscription_duration.value();
}

inline void from_json(const json& j, TransactionPartnerChat& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("chat") && !j.at("chat").is_null()) {
        o.chat = std::make_shared<Chat>();
        from_json(j.at("chat"), *o.chat);
    }
    if (j.contains("gift") && !j.at("gift").is_null()) {
        o.gift = std::make_shared<Gift>();
        from_json(j.at("gift"), *o.gift);
    }
}

inline void to_json(json& j, const TransactionPartnerChat& o) {
    j = json::object();
    j["type"] = o.type;
    {
        json _sub; to_json(_sub, *o.chat); j["chat"] = std::move(_sub);
    }
    if (o.gift) {
        json _sub; to_json(_sub, *o.gift); j["gift"] = std::move(_sub);
    }
}

inline void from_json(const json& j, TransactionPartnerAffiliateProgram& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("sponsor_user") && !j.at("sponsor_user").is_null()) {
        o.sponsor_user = std::make_shared<User>();
        from_json(j.at("sponsor_user"), *o.sponsor_user);
    }
    o.commission_per_mille = j.contains("commission_per_mille") && !j.at("commission_per_mille").is_null()
        ? j.at("commission_per_mille").get<int64_t>() : 0;
}

inline void to_json(json& j, const TransactionPartnerAffiliateProgram& o) {
    j = json::object();
    j["type"] = o.type;
    if (o.sponsor_user) {
        json _sub; to_json(_sub, *o.sponsor_user); j["sponsor_user"] = std::move(_sub);
    }
    j["commission_per_mille"] = o.commission_per_mille;
}

inline void from_json(const json& j, TransactionPartnerFragment& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("withdrawal_state") && !j.at("withdrawal_state").is_null()) {
        RevenueWithdrawalState _tmp{};
        from_json(j.at("withdrawal_state"), _tmp);
        o.withdrawal_state = std::move(_tmp);
    }
}

inline void to_json(json& j, const TransactionPartnerFragment& o) {
    j = json::object();
    j["type"] = o.type;
    if (o.withdrawal_state.has_value()) {
        json _sub;
        to_json(_sub, o.withdrawal_state.value());
        j["withdrawal_state"] = std::move(_sub);
    }
}

inline void from_json(const json& j, TransactionPartnerTelegramAds& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
}

inline void to_json(json& j, const TransactionPartnerTelegramAds& o) {
    j = json::object();
    j["type"] = o.type;
}

inline void from_json(const json& j, TransactionPartnerTelegramApi& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.request_count = j.contains("request_count") && !j.at("request_count").is_null()
        ? j.at("request_count").get<int64_t>() : 0;
}

inline void to_json(json& j, const TransactionPartnerTelegramApi& o) {
    j = json::object();
    j["type"] = o.type;
    j["request_count"] = o.request_count;
}

inline void from_json(const json& j, TransactionPartnerOther& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
}

inline void to_json(json& j, const TransactionPartnerOther& o) {
    j = json::object();
    j["type"] = o.type;
}

inline void from_json(const json& j, StarTransaction& o) {
    o.id = j.contains("id") && !j.at("id").is_null()
        ? j.at("id").get<std::string>() : "";
    o.amount = j.contains("amount") && !j.at("amount").is_null()
        ? j.at("amount").get<int64_t>() : 0;
    if (j.contains("nanostar_amount") && !j.at("nanostar_amount").is_null())
        o.nanostar_amount = j.at("nanostar_amount").get<int64_t>();
    o.date = j.contains("date") && !j.at("date").is_null()
        ? j.at("date").get<int64_t>() : 0;
    if (j.contains("source") && !j.at("source").is_null()) {
        TransactionPartner _tmp{};
        from_json(j.at("source"), _tmp);
        o.source = std::move(_tmp);
    }
    if (j.contains("receiver") && !j.at("receiver").is_null()) {
        TransactionPartner _tmp{};
        from_json(j.at("receiver"), _tmp);
        o.receiver = std::move(_tmp);
    }
}

inline void to_json(json& j, const StarTransaction& o) {
    j = json::object();
    j["id"] = o.id;
    j["amount"] = o.amount;
    if (o.nanostar_amount.has_value())
        j["nanostar_amount"] = o.nanostar_amount.value();
    j["date"] = o.date;
    if (o.source.has_value()) {
        json _sub;
        to_json(_sub, o.source.value());
        j["source"] = std::move(_sub);
    }
    if (o.receiver.has_value()) {
        json _sub;
        to_json(_sub, o.receiver.value());
        j["receiver"] = std::move(_sub);
    }
}

inline void from_json(const json& j, StarTransactions& o) {
    if (j.contains("transactions") && j.at("transactions").is_array()) {
        for (const auto& _item : j.at("transactions")) {
            {
                auto _elem = std::make_shared<StarTransaction>();
                from_json(_item, *_elem);
                o.transactions.push_back(std::move(_elem));
            }
        }
    }
}

inline void to_json(json& j, const StarTransactions& o) {
    j = json::object();
    {
        json _arr = json::array();
        for (const auto& _item : o.transactions) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["transactions"] = std::move(_arr);
    }
}

inline void from_json(const json& j, PassportData& o) {
    if (j.contains("data") && j.at("data").is_array()) {
        for (const auto& _item : j.at("data")) {
            {
                auto _elem = std::make_shared<EncryptedPassportElement>();
                from_json(_item, *_elem);
                o.data.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("credentials") && !j.at("credentials").is_null()) {
        o.credentials = std::make_shared<EncryptedCredentials>();
        from_json(j.at("credentials"), *o.credentials);
    }
}

inline void to_json(json& j, const PassportData& o) {
    j = json::object();
    {
        json _arr = json::array();
        for (const auto& _item : o.data) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["data"] = std::move(_arr);
    }
    {
        json _sub; to_json(_sub, *o.credentials); j["credentials"] = std::move(_sub);
    }
}

inline void from_json(const json& j, PassportFile& o) {
    o.file_id = j.contains("file_id") && !j.at("file_id").is_null()
        ? j.at("file_id").get<std::string>() : "";
    o.file_unique_id = j.contains("file_unique_id") && !j.at("file_unique_id").is_null()
        ? j.at("file_unique_id").get<std::string>() : "";
    o.file_size = j.contains("file_size") && !j.at("file_size").is_null()
        ? j.at("file_size").get<int64_t>() : 0;
    o.file_date = j.contains("file_date") && !j.at("file_date").is_null()
        ? j.at("file_date").get<int64_t>() : 0;
}

inline void to_json(json& j, const PassportFile& o) {
    j = json::object();
    j["file_id"] = o.file_id;
    j["file_unique_id"] = o.file_unique_id;
    j["file_size"] = o.file_size;
    j["file_date"] = o.file_date;
}

inline void from_json(const json& j, EncryptedPassportElement& o) {
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("data") && !j.at("data").is_null())
        o.data = j.at("data").get<std::string>();
    if (j.contains("phone_number") && !j.at("phone_number").is_null())
        o.phone_number = j.at("phone_number").get<std::string>();
    if (j.contains("email") && !j.at("email").is_null())
        o.email = j.at("email").get<std::string>();
    if (j.contains("files") && j.at("files").is_array()) {
        for (const auto& _item : j.at("files")) {
            {
                auto _elem = std::make_shared<PassportFile>();
                from_json(_item, *_elem);
                o.files.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("front_side") && !j.at("front_side").is_null()) {
        o.front_side = std::make_shared<PassportFile>();
        from_json(j.at("front_side"), *o.front_side);
    }
    if (j.contains("reverse_side") && !j.at("reverse_side").is_null()) {
        o.reverse_side = std::make_shared<PassportFile>();
        from_json(j.at("reverse_side"), *o.reverse_side);
    }
    if (j.contains("selfie") && !j.at("selfie").is_null()) {
        o.selfie = std::make_shared<PassportFile>();
        from_json(j.at("selfie"), *o.selfie);
    }
    if (j.contains("translation") && j.at("translation").is_array()) {
        for (const auto& _item : j.at("translation")) {
            {
                auto _elem = std::make_shared<PassportFile>();
                from_json(_item, *_elem);
                o.translation.push_back(std::move(_elem));
            }
        }
    }
    o.hash = j.contains("hash") && !j.at("hash").is_null()
        ? j.at("hash").get<std::string>() : "";
}

inline void to_json(json& j, const EncryptedPassportElement& o) {
    j = json::object();
    j["type"] = o.type;
    if (o.data.has_value())
        j["data"] = o.data.value();
    if (o.phone_number.has_value())
        j["phone_number"] = o.phone_number.value();
    if (o.email.has_value())
        j["email"] = o.email.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.files) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["files"] = std::move(_arr);
    }
    if (o.front_side) {
        json _sub; to_json(_sub, *o.front_side); j["front_side"] = std::move(_sub);
    }
    if (o.reverse_side) {
        json _sub; to_json(_sub, *o.reverse_side); j["reverse_side"] = std::move(_sub);
    }
    if (o.selfie) {
        json _sub; to_json(_sub, *o.selfie); j["selfie"] = std::move(_sub);
    }
    {
        json _arr = json::array();
        for (const auto& _item : o.translation) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["translation"] = std::move(_arr);
    }
    j["hash"] = o.hash;
}

inline void from_json(const json& j, EncryptedCredentials& o) {
    o.data = j.contains("data") && !j.at("data").is_null()
        ? j.at("data").get<std::string>() : "";
    o.hash = j.contains("hash") && !j.at("hash").is_null()
        ? j.at("hash").get<std::string>() : "";
    o.secret = j.contains("secret") && !j.at("secret").is_null()
        ? j.at("secret").get<std::string>() : "";
}

inline void to_json(json& j, const EncryptedCredentials& o) {
    j = json::object();
    j["data"] = o.data;
    j["hash"] = o.hash;
    j["secret"] = o.secret;
}

inline void from_json(const json& j, PassportElementError& v) {
    std::string type = j.at("type").get<std::string>();
    if (type == "passport_element_error_data_field") {
        auto obj = std::make_shared<PassportElementErrorDataField>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "passport_element_error_front_side") {
        auto obj = std::make_shared<PassportElementErrorFrontSide>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "passport_element_error_reverse_side") {
        auto obj = std::make_shared<PassportElementErrorReverseSide>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "passport_element_error_selfie") {
        auto obj = std::make_shared<PassportElementErrorSelfie>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "passport_element_error_file") {
        auto obj = std::make_shared<PassportElementErrorFile>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "passport_element_error_files") {
        auto obj = std::make_shared<PassportElementErrorFiles>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "passport_element_error_translation_file") {
        auto obj = std::make_shared<PassportElementErrorTranslationFile>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "passport_element_error_translation_files") {
        auto obj = std::make_shared<PassportElementErrorTranslationFiles>();
        from_json(j, *obj);
        v = obj; return;
    }
    if (type == "passport_element_error_unspecified") {
        auto obj = std::make_shared<PassportElementErrorUnspecified>();
        from_json(j, *obj);
        v = obj; return;
    }
    throw std::runtime_error("Unknown variant type: " + type);
}

inline void to_json(json& j, const PassportElementError& v) {
    if (auto* p = std::get_if <std::shared_ptr<PassportElementErrorDataField>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<PassportElementErrorFrontSide>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<PassportElementErrorReverseSide>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<PassportElementErrorSelfie>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<PassportElementErrorFile>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<PassportElementErrorFiles>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<PassportElementErrorTranslationFile>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<PassportElementErrorTranslationFiles>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
    if (auto* p = std::get_if <std::shared_ptr<PassportElementErrorUnspecified>>(&v)) {
        if (*p) to_json(j, **p);
        return;
    }
}

inline void from_json(const json& j, PassportElementErrorDataField& o) {
    o.source = j.contains("source") && !j.at("source").is_null()
        ? j.at("source").get<std::string>() : "";
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.field_name = j.contains("field_name") && !j.at("field_name").is_null()
        ? j.at("field_name").get<std::string>() : "";
    o.data_hash = j.contains("data_hash") && !j.at("data_hash").is_null()
        ? j.at("data_hash").get<std::string>() : "";
    o.message = j.contains("message") && !j.at("message").is_null()
        ? j.at("message").get<std::string>() : "";
}

inline void to_json(json& j, const PassportElementErrorDataField& o) {
    j = json::object();
    j["source"] = o.source;
    j["type"] = o.type;
    j["field_name"] = o.field_name;
    j["data_hash"] = o.data_hash;
    j["message"] = o.message;
}

inline void from_json(const json& j, PassportElementErrorFrontSide& o) {
    o.source = j.contains("source") && !j.at("source").is_null()
        ? j.at("source").get<std::string>() : "";
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.file_hash = j.contains("file_hash") && !j.at("file_hash").is_null()
        ? j.at("file_hash").get<std::string>() : "";
    o.message = j.contains("message") && !j.at("message").is_null()
        ? j.at("message").get<std::string>() : "";
}

inline void to_json(json& j, const PassportElementErrorFrontSide& o) {
    j = json::object();
    j["source"] = o.source;
    j["type"] = o.type;
    j["file_hash"] = o.file_hash;
    j["message"] = o.message;
}

inline void from_json(const json& j, PassportElementErrorReverseSide& o) {
    o.source = j.contains("source") && !j.at("source").is_null()
        ? j.at("source").get<std::string>() : "";
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.file_hash = j.contains("file_hash") && !j.at("file_hash").is_null()
        ? j.at("file_hash").get<std::string>() : "";
    o.message = j.contains("message") && !j.at("message").is_null()
        ? j.at("message").get<std::string>() : "";
}

inline void to_json(json& j, const PassportElementErrorReverseSide& o) {
    j = json::object();
    j["source"] = o.source;
    j["type"] = o.type;
    j["file_hash"] = o.file_hash;
    j["message"] = o.message;
}

inline void from_json(const json& j, PassportElementErrorSelfie& o) {
    o.source = j.contains("source") && !j.at("source").is_null()
        ? j.at("source").get<std::string>() : "";
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.file_hash = j.contains("file_hash") && !j.at("file_hash").is_null()
        ? j.at("file_hash").get<std::string>() : "";
    o.message = j.contains("message") && !j.at("message").is_null()
        ? j.at("message").get<std::string>() : "";
}

inline void to_json(json& j, const PassportElementErrorSelfie& o) {
    j = json::object();
    j["source"] = o.source;
    j["type"] = o.type;
    j["file_hash"] = o.file_hash;
    j["message"] = o.message;
}

inline void from_json(const json& j, PassportElementErrorFile& o) {
    o.source = j.contains("source") && !j.at("source").is_null()
        ? j.at("source").get<std::string>() : "";
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.file_hash = j.contains("file_hash") && !j.at("file_hash").is_null()
        ? j.at("file_hash").get<std::string>() : "";
    o.message = j.contains("message") && !j.at("message").is_null()
        ? j.at("message").get<std::string>() : "";
}

inline void to_json(json& j, const PassportElementErrorFile& o) {
    j = json::object();
    j["source"] = o.source;
    j["type"] = o.type;
    j["file_hash"] = o.file_hash;
    j["message"] = o.message;
}

inline void from_json(const json& j, PassportElementErrorFiles& o) {
    o.source = j.contains("source") && !j.at("source").is_null()
        ? j.at("source").get<std::string>() : "";
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("file_hashes") && j.at("file_hashes").is_array()) {
        for (const auto& _item : j.at("file_hashes")) {
            o.file_hashes.push_back(_item.get<std::string>());
        }
    }
    o.message = j.contains("message") && !j.at("message").is_null()
        ? j.at("message").get<std::string>() : "";
}

inline void to_json(json& j, const PassportElementErrorFiles& o) {
    j = json::object();
    j["source"] = o.source;
    j["type"] = o.type;
    {
        json _arr = json::array();
        for (const auto& _item : o.file_hashes) {
            _arr.push_back(_item);
        }
        j["file_hashes"] = std::move(_arr);
    }
    j["message"] = o.message;
}

inline void from_json(const json& j, PassportElementErrorTranslationFile& o) {
    o.source = j.contains("source") && !j.at("source").is_null()
        ? j.at("source").get<std::string>() : "";
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.file_hash = j.contains("file_hash") && !j.at("file_hash").is_null()
        ? j.at("file_hash").get<std::string>() : "";
    o.message = j.contains("message") && !j.at("message").is_null()
        ? j.at("message").get<std::string>() : "";
}

inline void to_json(json& j, const PassportElementErrorTranslationFile& o) {
    j = json::object();
    j["source"] = o.source;
    j["type"] = o.type;
    j["file_hash"] = o.file_hash;
    j["message"] = o.message;
}

inline void from_json(const json& j, PassportElementErrorTranslationFiles& o) {
    o.source = j.contains("source") && !j.at("source").is_null()
        ? j.at("source").get<std::string>() : "";
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    if (j.contains("file_hashes") && j.at("file_hashes").is_array()) {
        for (const auto& _item : j.at("file_hashes")) {
            o.file_hashes.push_back(_item.get<std::string>());
        }
    }
    o.message = j.contains("message") && !j.at("message").is_null()
        ? j.at("message").get<std::string>() : "";
}

inline void to_json(json& j, const PassportElementErrorTranslationFiles& o) {
    j = json::object();
    j["source"] = o.source;
    j["type"] = o.type;
    {
        json _arr = json::array();
        for (const auto& _item : o.file_hashes) {
            _arr.push_back(_item);
        }
        j["file_hashes"] = std::move(_arr);
    }
    j["message"] = o.message;
}

inline void from_json(const json& j, PassportElementErrorUnspecified& o) {
    o.source = j.contains("source") && !j.at("source").is_null()
        ? j.at("source").get<std::string>() : "";
    o.type = j.contains("type") && !j.at("type").is_null()
        ? j.at("type").get<std::string>() : "";
    o.element_hash = j.contains("element_hash") && !j.at("element_hash").is_null()
        ? j.at("element_hash").get<std::string>() : "";
    o.message = j.contains("message") && !j.at("message").is_null()
        ? j.at("message").get<std::string>() : "";
}

inline void to_json(json& j, const PassportElementErrorUnspecified& o) {
    j = json::object();
    j["source"] = o.source;
    j["type"] = o.type;
    j["element_hash"] = o.element_hash;
    j["message"] = o.message;
}

inline void from_json(const json& j, Game& o) {
    o.title = j.contains("title") && !j.at("title").is_null()
        ? j.at("title").get<std::string>() : "";
    o.description = j.contains("description") && !j.at("description").is_null()
        ? j.at("description").get<std::string>() : "";
    if (j.contains("photo") && j.at("photo").is_array()) {
        for (const auto& _item : j.at("photo")) {
            {
                auto _elem = std::make_shared<PhotoSize>();
                from_json(_item, *_elem);
                o.photo.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("text") && !j.at("text").is_null())
        o.text = j.at("text").get<std::string>();
    if (j.contains("text_entities") && j.at("text_entities").is_array()) {
        for (const auto& _item : j.at("text_entities")) {
            {
                auto _elem = std::make_shared<MessageEntity>();
                from_json(_item, *_elem);
                o.text_entities.push_back(std::move(_elem));
            }
        }
    }
    if (j.contains("animation") && !j.at("animation").is_null()) {
        o.animation = std::make_shared<Animation>();
        from_json(j.at("animation"), *o.animation);
    }
}

inline void to_json(json& j, const Game& o) {
    j = json::object();
    j["title"] = o.title;
    j["description"] = o.description;
    {
        json _arr = json::array();
        for (const auto& _item : o.photo) {
            {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["photo"] = std::move(_arr);
    }
    if (o.text.has_value())
        j["text"] = o.text.value();
    {
        json _arr = json::array();
        for (const auto& _item : o.text_entities) {
            if (_item) {
                json _e; to_json(_e, *_item); _arr.push_back(std::move(_e));
            }
        }
        j["text_entities"] = std::move(_arr);
    }
    if (o.animation) {
        json _sub; to_json(_sub, *o.animation); j["animation"] = std::move(_sub);
    }
}

inline void from_json(const json& j, CallbackGame& o) {
    (void)j; (void)o;
}

inline void to_json(json& j, const CallbackGame& o) {
    j = json::object();
    (void)o;
}

inline void from_json(const json& j, GameHighScore& o) {
    o.position = j.contains("position") && !j.at("position").is_null()
        ? j.at("position").get<int64_t>() : 0;
    if (j.contains("user") && !j.at("user").is_null()) {
        o.user = std::make_shared<User>();
        from_json(j.at("user"), *o.user);
    }
    o.score = j.contains("score") && !j.at("score").is_null()
        ? j.at("score").get<int64_t>() : 0;
}

inline void to_json(json& j, const GameHighScore& o) {
    j = json::object();
    j["position"] = o.position;
    {
        json _sub; to_json(_sub, *o.user); j["user"] = std::move(_sub);
    }
    j["score"] = o.score;
}

} // namespace corogram
