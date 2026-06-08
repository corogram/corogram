/**
 * @file    Enums.hpp
 * @brief   Telegram Bot API 10.0 — auto-generated enum definitions
 *
 * Generated via schema — DO NOT EDIT MANUALLY.
 */
#pragma once
#include <cstdint>
#include <optional>
#include <string_view>

namespace corogram::enums {

    /**
     * This object represents the scope to which bot commands are applied.
     * 
     * Source: https://core.telegram.org/bots/api#botcommandscope
     */
    // ── BotCommandScopeType ───────────────────────────────────────
    enum class BotCommandScopeType : uint8_t {
        Default,  ///< Default
        AllPrivateChats,  ///< AllPrivateChats
        AllGroupChats,  ///< AllGroupChats
        AllChatAdministrators,  ///< AllChatAdministrators
        Chat,  ///< Chat
        ChatAdministrators,  ///< ChatAdministrators
        ChatMember,  ///< ChatMember
    };

    inline std::string_view to_string(BotCommandScopeType v) noexcept {
        switch (v) {
        case BotCommandScopeType::Default: return "default";
        case BotCommandScopeType::AllPrivateChats: return "all_private_chats";
        case BotCommandScopeType::AllGroupChats: return "all_group_chats";
        case BotCommandScopeType::AllChatAdministrators: return "all_chat_administrators";
        case BotCommandScopeType::Chat: return "chat";
        case BotCommandScopeType::ChatAdministrators: return "chat_administrators";
        case BotCommandScopeType::ChatMember: return "chat_member";
        }
        return "";
    }

    inline std::optional<BotCommandScopeType> BotCommandScopeType_from_string(std::string_view s) noexcept {
        if (s == "default") return BotCommandScopeType::Default;
        if (s == "all_private_chats") return BotCommandScopeType::AllPrivateChats;
        if (s == "all_group_chats") return BotCommandScopeType::AllGroupChats;
        if (s == "all_chat_administrators") return BotCommandScopeType::AllChatAdministrators;
        if (s == "chat") return BotCommandScopeType::Chat;
        if (s == "chat_administrators") return BotCommandScopeType::ChatAdministrators;
        if (s == "chat_member") return BotCommandScopeType::ChatMember;
        return std::nullopt;
    }

    /**
     * This object represents a button style (inline- or reply-keyboard).
     * 
     * Sources:
     *   * https://core.telegram.org/bots/api#inlinekeyboardbutton
     *   * https://core.telegram.org/bots/api#keyboardbutton
     */
    // ── ButtonStyle ───────────────────────────────────────────────
    enum class ButtonStyle : uint8_t {
        Danger,  ///< Danger
        Success,  ///< Success
        Primary,  ///< Primary
    };

    inline std::string_view to_string(ButtonStyle v) noexcept {
        switch (v) {
        case ButtonStyle::Danger: return "danger";
        case ButtonStyle::Success: return "success";
        case ButtonStyle::Primary: return "primary";
        }
        return "";
    }

    inline std::optional<ButtonStyle> ButtonStyle_from_string(std::string_view s) noexcept {
        if (s == "danger") return ButtonStyle::Danger;
        if (s == "success") return ButtonStyle::Success;
        if (s == "primary") return ButtonStyle::Primary;
        return std::nullopt;
    }

    /**
     * This object represents bot actions.
     * 
     * Choose one, depending on what the user is about to receive:
     * 
     * - typing for text messages,
     * - upload_photo for photos,
     * - record_video or upload_video for videos,
     * - record_voice or upload_voice for voice notes,
     * - upload_document for general files,
     * - choose_sticker for stickers,
     * - find_location for location data,
     * - record_video_note or upload_video_note for video notes.
     * 
     * Source: https://core.telegram.org/bots/api#sendchataction
     */
    // ── ChatAction ────────────────────────────────────────────────
    enum class ChatAction : uint8_t {
        Typing,  ///< Typing
        UploadPhoto,  ///< UploadPhoto
        RecordVideo,  ///< RecordVideo
        UploadVideo,  ///< UploadVideo
        RecordVoice,  ///< RecordVoice
        UploadVoice,  ///< UploadVoice
        UploadDocument,  ///< UploadDocument
        ChooseSticker,  ///< ChooseSticker
        FindLocation,  ///< FindLocation
        RecordVideoNote,  ///< RecordVideoNote
        UploadVideoNote,  ///< UploadVideoNote
    };

    inline std::string_view to_string(ChatAction v) noexcept {
        switch (v) {
        case ChatAction::Typing: return "typing";
        case ChatAction::UploadPhoto: return "upload_photo";
        case ChatAction::RecordVideo: return "record_video";
        case ChatAction::UploadVideo: return "upload_video";
        case ChatAction::RecordVoice: return "record_voice";
        case ChatAction::UploadVoice: return "upload_voice";
        case ChatAction::UploadDocument: return "upload_document";
        case ChatAction::ChooseSticker: return "choose_sticker";
        case ChatAction::FindLocation: return "find_location";
        case ChatAction::RecordVideoNote: return "record_video_note";
        case ChatAction::UploadVideoNote: return "upload_video_note";
        }
        return "";
    }

    inline std::optional<ChatAction> ChatAction_from_string(std::string_view s) noexcept {
        if (s == "typing") return ChatAction::Typing;
        if (s == "upload_photo") return ChatAction::UploadPhoto;
        if (s == "record_video") return ChatAction::RecordVideo;
        if (s == "upload_video") return ChatAction::UploadVideo;
        if (s == "record_voice") return ChatAction::RecordVoice;
        if (s == "upload_voice") return ChatAction::UploadVoice;
        if (s == "upload_document") return ChatAction::UploadDocument;
        if (s == "choose_sticker") return ChatAction::ChooseSticker;
        if (s == "find_location") return ChatAction::FindLocation;
        if (s == "record_video_note") return ChatAction::RecordVideoNote;
        if (s == "upload_video_note") return ChatAction::UploadVideoNote;
        return std::nullopt;
    }

    /**
     * This object represents a type of chat boost source.
     * 
     * Source: https://core.telegram.org/bots/api#chatboostsource
     */
    // ── ChatBoostSourceType ───────────────────────────────────────
    enum class ChatBoostSourceType : uint8_t {
        Premium,  ///< Premium
        GiftCode,  ///< GiftCode
        Giveaway,  ///< Giveaway
    };

    inline std::string_view to_string(ChatBoostSourceType v) noexcept {
        switch (v) {
        case ChatBoostSourceType::Premium: return "premium";
        case ChatBoostSourceType::GiftCode: return "gift_code";
        case ChatBoostSourceType::Giveaway: return "giveaway";
        }
        return "";
    }

    inline std::optional<ChatBoostSourceType> ChatBoostSourceType_from_string(std::string_view s) noexcept {
        if (s == "premium") return ChatBoostSourceType::Premium;
        if (s == "gift_code") return ChatBoostSourceType::GiftCode;
        if (s == "giveaway") return ChatBoostSourceType::Giveaway;
        return std::nullopt;
    }

    /**
     * This object represents chat member status.
     * 
     * Source: https://core.telegram.org/bots/api#chatmember
     */
    // ── ChatMemberStatus ──────────────────────────────────────────
    enum class ChatMemberStatus : uint8_t {
        Owner,  ///< Owner
        Administrator,  ///< Administrator
        Member,  ///< Member
        Restricted,  ///< Restricted
        Left,  ///< Left
        Banned,  ///< Banned
    };

    inline std::string_view to_string(ChatMemberStatus v) noexcept {
        switch (v) {
        case ChatMemberStatus::Owner: return "creator";
        case ChatMemberStatus::Administrator: return "administrator";
        case ChatMemberStatus::Member: return "member";
        case ChatMemberStatus::Restricted: return "restricted";
        case ChatMemberStatus::Left: return "left";
        case ChatMemberStatus::Banned: return "kicked";
        }
        return "";
    }

    inline std::optional<ChatMemberStatus> ChatMemberStatus_from_string(std::string_view s) noexcept {
        if (s == "creator") return ChatMemberStatus::Owner;
        if (s == "administrator") return ChatMemberStatus::Administrator;
        if (s == "member") return ChatMemberStatus::Member;
        if (s == "restricted") return ChatMemberStatus::Restricted;
        if (s == "left") return ChatMemberStatus::Left;
        if (s == "kicked") return ChatMemberStatus::Banned;
        return std::nullopt;
    }

    /**
     * This object represents a chat type
     * 
     * Source: https://core.telegram.org/bots/api#chat
     */
    // ── ChatType ──────────────────────────────────────────────────
    enum class ChatType : uint8_t {
        Private,  ///< Private
        Group,  ///< Group
        Supergroup,  ///< Supergroup
        Channel,  ///< Channel
        Sender,  ///< Sender
    };

    inline std::string_view to_string(ChatType v) noexcept {
        switch (v) {
        case ChatType::Private: return "private";
        case ChatType::Group: return "group";
        case ChatType::Supergroup: return "supergroup";
        case ChatType::Channel: return "channel";
        case ChatType::Sender: return "sender";
        }
        return "";
    }

    inline std::optional<ChatType> ChatType_from_string(std::string_view s) noexcept {
        if (s == "private") return ChatType::Private;
        if (s == "group") return ChatType::Group;
        if (s == "supergroup") return ChatType::Supergroup;
        if (s == "channel") return ChatType::Channel;
        if (s == "sender") return ChatType::Sender;
        return std::nullopt;
    }

    /**
     * This object represents a type of content in message
     */
    // ── ContentType ───────────────────────────────────────────────
    enum class ContentType : uint8_t {
        Unknown,  ///< Unknown
        Any,  ///< Any
        GuestQueryId,  ///< GuestQueryId
        GuestBotCallerUser,  ///< GuestBotCallerUser
        GuestBotCallerChat,  ///< GuestBotCallerChat
        Text,  ///< Text
        Animation,  ///< Animation
        Audio,  ///< Audio
        Document,  ///< Document
        LivePhoto,  ///< LivePhoto
        PaidMedia,  ///< PaidMedia
        Photo,  ///< Photo
        Sticker,  ///< Sticker
        Story,  ///< Story
        Video,  ///< Video
        VideoNote,  ///< VideoNote
        Voice,  ///< Voice
        Checklist,  ///< Checklist
        Contact,  ///< Contact
        Dice,  ///< Dice
        Game,  ///< Game
        Poll,  ///< Poll
        Venue,  ///< Venue
        Location,  ///< Location
        NewChatMembers,  ///< NewChatMembers
        LeftChatMember,  ///< LeftChatMember
        ChatOwnerLeft,  ///< ChatOwnerLeft
        ChatOwnerChanged,  ///< ChatOwnerChanged
        NewChatTitle,  ///< NewChatTitle
        NewChatPhoto,  ///< NewChatPhoto
        DeleteChatPhoto,  ///< DeleteChatPhoto
        GroupChatCreated,  ///< GroupChatCreated
        SupergroupChatCreated,  ///< SupergroupChatCreated
        ChannelChatCreated,  ///< ChannelChatCreated
        MessageAutoDeleteTimerChanged,  ///< MessageAutoDeleteTimerChanged
        MigrateToChatId,  ///< MigrateToChatId
        MigrateFromChatId,  ///< MigrateFromChatId
        PinnedMessage,  ///< PinnedMessage
        Invoice,  ///< Invoice
        SuccessfulPayment,  ///< SuccessfulPayment
        RefundedPayment,  ///< RefundedPayment
        UsersShared,  ///< UsersShared
        ChatShared,  ///< ChatShared
        Gift,  ///< Gift
        UniqueGift,  ///< UniqueGift
        GiftUpgradeSent,  ///< GiftUpgradeSent
        ConnectedWebsite,  ///< ConnectedWebsite
        WriteAccessAllowed,  ///< WriteAccessAllowed
        PassportData,  ///< PassportData
        ProximityAlertTriggered,  ///< ProximityAlertTriggered
        BoostAdded,  ///< BoostAdded
        ChatBackgroundSet,  ///< ChatBackgroundSet
        ChecklistTasksDone,  ///< ChecklistTasksDone
        ChecklistTasksAdded,  ///< ChecklistTasksAdded
        DirectMessagePriceChanged,  ///< DirectMessagePriceChanged
        ForumTopicCreated,  ///< ForumTopicCreated
        ForumTopicEdited,  ///< ForumTopicEdited
        ForumTopicClosed,  ///< ForumTopicClosed
        ForumTopicReopened,  ///< ForumTopicReopened
        GeneralForumTopicHidden,  ///< GeneralForumTopicHidden
        GeneralForumTopicUnhidden,  ///< GeneralForumTopicUnhidden
        GiveawayCreated,  ///< GiveawayCreated
        Giveaway,  ///< Giveaway
        GiveawayWinners,  ///< GiveawayWinners
        GiveawayCompleted,  ///< GiveawayCompleted
        ManagedBotCreated,  ///< ManagedBotCreated
        PaidMessagePriceChanged,  ///< PaidMessagePriceChanged
        PollOptionAdded,  ///< PollOptionAdded
        PollOptionDeleted,  ///< PollOptionDeleted
        SuggestedPostApproved,  ///< SuggestedPostApproved
        SuggestedPostApprovalFailed,  ///< SuggestedPostApprovalFailed
        SuggestedPostDeclined,  ///< SuggestedPostDeclined
        SuggestedPostPaid,  ///< SuggestedPostPaid
        SuggestedPostRefunded,  ///< SuggestedPostRefunded
        VideoChatScheduled,  ///< VideoChatScheduled
        VideoChatStarted,  ///< VideoChatStarted
        VideoChatEnded,  ///< VideoChatEnded
        VideoChatParticipantsInvited,  ///< VideoChatParticipantsInvited
        WebAppData,  ///< WebAppData
    };

    inline std::string_view to_string(ContentType v) noexcept {
        switch (v) {
        case ContentType::Unknown: return "unknown";
        case ContentType::Any: return "any";
        case ContentType::GuestQueryId: return "guest_query_id";
        case ContentType::GuestBotCallerUser: return "guest_bot_caller_user";
        case ContentType::GuestBotCallerChat: return "guest_bot_caller_chat";
        case ContentType::Text: return "text";
        case ContentType::Animation: return "animation";
        case ContentType::Audio: return "audio";
        case ContentType::Document: return "document";
        case ContentType::LivePhoto: return "live_photo";
        case ContentType::PaidMedia: return "paid_media";
        case ContentType::Photo: return "photo";
        case ContentType::Sticker: return "sticker";
        case ContentType::Story: return "story";
        case ContentType::Video: return "video";
        case ContentType::VideoNote: return "video_note";
        case ContentType::Voice: return "voice";
        case ContentType::Checklist: return "checklist";
        case ContentType::Contact: return "contact";
        case ContentType::Dice: return "dice";
        case ContentType::Game: return "game";
        case ContentType::Poll: return "poll";
        case ContentType::Venue: return "venue";
        case ContentType::Location: return "location";
        case ContentType::NewChatMembers: return "new_chat_members";
        case ContentType::LeftChatMember: return "left_chat_member";
        case ContentType::ChatOwnerLeft: return "chat_owner_left";
        case ContentType::ChatOwnerChanged: return "chat_owner_changed";
        case ContentType::NewChatTitle: return "new_chat_title";
        case ContentType::NewChatPhoto: return "new_chat_photo";
        case ContentType::DeleteChatPhoto: return "delete_chat_photo";
        case ContentType::GroupChatCreated: return "group_chat_created";
        case ContentType::SupergroupChatCreated: return "supergroup_chat_created";
        case ContentType::ChannelChatCreated: return "channel_chat_created";
        case ContentType::MessageAutoDeleteTimerChanged: return "message_auto_delete_timer_changed";
        case ContentType::MigrateToChatId: return "migrate_to_chat_id";
        case ContentType::MigrateFromChatId: return "migrate_from_chat_id";
        case ContentType::PinnedMessage: return "pinned_message";
        case ContentType::Invoice: return "invoice";
        case ContentType::SuccessfulPayment: return "successful_payment";
        case ContentType::RefundedPayment: return "refunded_payment";
        case ContentType::UsersShared: return "users_shared";
        case ContentType::ChatShared: return "chat_shared";
        case ContentType::Gift: return "gift";
        case ContentType::UniqueGift: return "unique_gift";
        case ContentType::GiftUpgradeSent: return "gift_upgrade_sent";
        case ContentType::ConnectedWebsite: return "connected_website";
        case ContentType::WriteAccessAllowed: return "write_access_allowed";
        case ContentType::PassportData: return "passport_data";
        case ContentType::ProximityAlertTriggered: return "proximity_alert_triggered";
        case ContentType::BoostAdded: return "boost_added";
        case ContentType::ChatBackgroundSet: return "chat_background_set";
        case ContentType::ChecklistTasksDone: return "checklist_tasks_done";
        case ContentType::ChecklistTasksAdded: return "checklist_tasks_added";
        case ContentType::DirectMessagePriceChanged: return "direct_message_price_changed";
        case ContentType::ForumTopicCreated: return "forum_topic_created";
        case ContentType::ForumTopicEdited: return "forum_topic_edited";
        case ContentType::ForumTopicClosed: return "forum_topic_closed";
        case ContentType::ForumTopicReopened: return "forum_topic_reopened";
        case ContentType::GeneralForumTopicHidden: return "general_forum_topic_hidden";
        case ContentType::GeneralForumTopicUnhidden: return "general_forum_topic_unhidden";
        case ContentType::GiveawayCreated: return "giveaway_created";
        case ContentType::Giveaway: return "giveaway";
        case ContentType::GiveawayWinners: return "giveaway_winners";
        case ContentType::GiveawayCompleted: return "giveaway_completed";
        case ContentType::ManagedBotCreated: return "managed_bot_created";
        case ContentType::PaidMessagePriceChanged: return "paid_message_price_changed";
        case ContentType::PollOptionAdded: return "poll_option_added";
        case ContentType::PollOptionDeleted: return "poll_option_deleted";
        case ContentType::SuggestedPostApproved: return "suggested_post_approved";
        case ContentType::SuggestedPostApprovalFailed: return "suggested_post_approval_failed";
        case ContentType::SuggestedPostDeclined: return "suggested_post_declined";
        case ContentType::SuggestedPostPaid: return "suggested_post_paid";
        case ContentType::SuggestedPostRefunded: return "suggested_post_refunded";
        case ContentType::VideoChatScheduled: return "video_chat_scheduled";
        case ContentType::VideoChatStarted: return "video_chat_started";
        case ContentType::VideoChatEnded: return "video_chat_ended";
        case ContentType::VideoChatParticipantsInvited: return "video_chat_participants_invited";
        case ContentType::WebAppData: return "web_app_data";
        }
        return "";
    }

    inline std::optional<ContentType> ContentType_from_string(std::string_view s) noexcept {
        if (s == "unknown") return ContentType::Unknown;
        if (s == "any") return ContentType::Any;
        if (s == "guest_query_id") return ContentType::GuestQueryId;
        if (s == "guest_bot_caller_user") return ContentType::GuestBotCallerUser;
        if (s == "guest_bot_caller_chat") return ContentType::GuestBotCallerChat;
        if (s == "text") return ContentType::Text;
        if (s == "animation") return ContentType::Animation;
        if (s == "audio") return ContentType::Audio;
        if (s == "document") return ContentType::Document;
        if (s == "live_photo") return ContentType::LivePhoto;
        if (s == "paid_media") return ContentType::PaidMedia;
        if (s == "photo") return ContentType::Photo;
        if (s == "sticker") return ContentType::Sticker;
        if (s == "story") return ContentType::Story;
        if (s == "video") return ContentType::Video;
        if (s == "video_note") return ContentType::VideoNote;
        if (s == "voice") return ContentType::Voice;
        if (s == "checklist") return ContentType::Checklist;
        if (s == "contact") return ContentType::Contact;
        if (s == "dice") return ContentType::Dice;
        if (s == "game") return ContentType::Game;
        if (s == "poll") return ContentType::Poll;
        if (s == "venue") return ContentType::Venue;
        if (s == "location") return ContentType::Location;
        if (s == "new_chat_members") return ContentType::NewChatMembers;
        if (s == "left_chat_member") return ContentType::LeftChatMember;
        if (s == "chat_owner_left") return ContentType::ChatOwnerLeft;
        if (s == "chat_owner_changed") return ContentType::ChatOwnerChanged;
        if (s == "new_chat_title") return ContentType::NewChatTitle;
        if (s == "new_chat_photo") return ContentType::NewChatPhoto;
        if (s == "delete_chat_photo") return ContentType::DeleteChatPhoto;
        if (s == "group_chat_created") return ContentType::GroupChatCreated;
        if (s == "supergroup_chat_created") return ContentType::SupergroupChatCreated;
        if (s == "channel_chat_created") return ContentType::ChannelChatCreated;
        if (s == "message_auto_delete_timer_changed") return ContentType::MessageAutoDeleteTimerChanged;
        if (s == "migrate_to_chat_id") return ContentType::MigrateToChatId;
        if (s == "migrate_from_chat_id") return ContentType::MigrateFromChatId;
        if (s == "pinned_message") return ContentType::PinnedMessage;
        if (s == "invoice") return ContentType::Invoice;
        if (s == "successful_payment") return ContentType::SuccessfulPayment;
        if (s == "refunded_payment") return ContentType::RefundedPayment;
        if (s == "users_shared") return ContentType::UsersShared;
        if (s == "chat_shared") return ContentType::ChatShared;
        if (s == "gift") return ContentType::Gift;
        if (s == "unique_gift") return ContentType::UniqueGift;
        if (s == "gift_upgrade_sent") return ContentType::GiftUpgradeSent;
        if (s == "connected_website") return ContentType::ConnectedWebsite;
        if (s == "write_access_allowed") return ContentType::WriteAccessAllowed;
        if (s == "passport_data") return ContentType::PassportData;
        if (s == "proximity_alert_triggered") return ContentType::ProximityAlertTriggered;
        if (s == "boost_added") return ContentType::BoostAdded;
        if (s == "chat_background_set") return ContentType::ChatBackgroundSet;
        if (s == "checklist_tasks_done") return ContentType::ChecklistTasksDone;
        if (s == "checklist_tasks_added") return ContentType::ChecklistTasksAdded;
        if (s == "direct_message_price_changed") return ContentType::DirectMessagePriceChanged;
        if (s == "forum_topic_created") return ContentType::ForumTopicCreated;
        if (s == "forum_topic_edited") return ContentType::ForumTopicEdited;
        if (s == "forum_topic_closed") return ContentType::ForumTopicClosed;
        if (s == "forum_topic_reopened") return ContentType::ForumTopicReopened;
        if (s == "general_forum_topic_hidden") return ContentType::GeneralForumTopicHidden;
        if (s == "general_forum_topic_unhidden") return ContentType::GeneralForumTopicUnhidden;
        if (s == "giveaway_created") return ContentType::GiveawayCreated;
        if (s == "giveaway") return ContentType::Giveaway;
        if (s == "giveaway_winners") return ContentType::GiveawayWinners;
        if (s == "giveaway_completed") return ContentType::GiveawayCompleted;
        if (s == "managed_bot_created") return ContentType::ManagedBotCreated;
        if (s == "paid_message_price_changed") return ContentType::PaidMessagePriceChanged;
        if (s == "poll_option_added") return ContentType::PollOptionAdded;
        if (s == "poll_option_deleted") return ContentType::PollOptionDeleted;
        if (s == "suggested_post_approved") return ContentType::SuggestedPostApproved;
        if (s == "suggested_post_approval_failed") return ContentType::SuggestedPostApprovalFailed;
        if (s == "suggested_post_declined") return ContentType::SuggestedPostDeclined;
        if (s == "suggested_post_paid") return ContentType::SuggestedPostPaid;
        if (s == "suggested_post_refunded") return ContentType::SuggestedPostRefunded;
        if (s == "video_chat_scheduled") return ContentType::VideoChatScheduled;
        if (s == "video_chat_started") return ContentType::VideoChatStarted;
        if (s == "video_chat_ended") return ContentType::VideoChatEnded;
        if (s == "video_chat_participants_invited") return ContentType::VideoChatParticipantsInvited;
        if (s == "web_app_data") return ContentType::WebAppData;
        return std::nullopt;
    }

    /**
     * Currencies supported by Telegram Bot API
     * 
     * Source: https://core.telegram.org/bots/payments#supported-currencies
     */
    // ── Currency ──────────────────────────────────────────────────
    enum class Currency : uint8_t {
        AED,  ///< AED
        AFN,  ///< AFN
        ALL,  ///< ALL
        AMD,  ///< AMD
        ARS,  ///< ARS
        AUD,  ///< AUD
        AZN,  ///< AZN
        BAM,  ///< BAM
        BDT,  ///< BDT
        BGN,  ///< BGN
        BND,  ///< BND
        BOB,  ///< BOB
        BRL,  ///< BRL
        BYN,  ///< BYN
        CAD,  ///< CAD
        CHF,  ///< CHF
        CLP,  ///< CLP
        CNY,  ///< CNY
        COP,  ///< COP
        CRC,  ///< CRC
        CZK,  ///< CZK
        DKK,  ///< DKK
        DOP,  ///< DOP
        DZD,  ///< DZD
        EGP,  ///< EGP
        ETB,  ///< ETB
        EUR,  ///< EUR
        GBP,  ///< GBP
        GEL,  ///< GEL
        GTQ,  ///< GTQ
        HKD,  ///< HKD
        HNL,  ///< HNL
        HRK,  ///< HRK
        HUF,  ///< HUF
        IDR,  ///< IDR
        ILS,  ///< ILS
        INR,  ///< INR
        ISK,  ///< ISK
        JMD,  ///< JMD
        JPY,  ///< JPY
        KES,  ///< KES
        KGS,  ///< KGS
        KRW,  ///< KRW
        KZT,  ///< KZT
        LBP,  ///< LBP
        LKR,  ///< LKR
        MAD,  ///< MAD
        MDL,  ///< MDL
        MNT,  ///< MNT
        MUR,  ///< MUR
        MVR,  ///< MVR
        MXN,  ///< MXN
        MYR,  ///< MYR
        MZN,  ///< MZN
        NGN,  ///< NGN
        NIO,  ///< NIO
        NOK,  ///< NOK
        NPR,  ///< NPR
        NZD,  ///< NZD
        PAB,  ///< PAB
        PEN,  ///< PEN
        PHP,  ///< PHP
        PKR,  ///< PKR
        PLN,  ///< PLN
        PYG,  ///< PYG
        QAR,  ///< QAR
        RON,  ///< RON
        RSD,  ///< RSD
        RUB,  ///< RUB
        SAR,  ///< SAR
        SEK,  ///< SEK
        SGD,  ///< SGD
        THB,  ///< THB
        TJS,  ///< TJS
        TRY,  ///< TRY
        TTD,  ///< TTD
        TWD,  ///< TWD
        TZS,  ///< TZS
        UAH,  ///< UAH
        UGX,  ///< UGX
        USD,  ///< USD
        UYU,  ///< UYU
        UZS,  ///< UZS
        VND,  ///< VND
        YER,  ///< YER
        ZAR,  ///< ZAR
    };

    inline std::string_view to_string(Currency v) noexcept {
        switch (v) {
        case Currency::AED: return "AED";
        case Currency::AFN: return "AFN";
        case Currency::ALL: return "ALL";
        case Currency::AMD: return "AMD";
        case Currency::ARS: return "ARS";
        case Currency::AUD: return "AUD";
        case Currency::AZN: return "AZN";
        case Currency::BAM: return "BAM";
        case Currency::BDT: return "BDT";
        case Currency::BGN: return "BGN";
        case Currency::BND: return "BND";
        case Currency::BOB: return "BOB";
        case Currency::BRL: return "BRL";
        case Currency::BYN: return "BYN";
        case Currency::CAD: return "CAD";
        case Currency::CHF: return "CHF";
        case Currency::CLP: return "CLP";
        case Currency::CNY: return "CNY";
        case Currency::COP: return "COP";
        case Currency::CRC: return "CRC";
        case Currency::CZK: return "CZK";
        case Currency::DKK: return "DKK";
        case Currency::DOP: return "DOP";
        case Currency::DZD: return "DZD";
        case Currency::EGP: return "EGP";
        case Currency::ETB: return "ETB";
        case Currency::EUR: return "EUR";
        case Currency::GBP: return "GBP";
        case Currency::GEL: return "GEL";
        case Currency::GTQ: return "GTQ";
        case Currency::HKD: return "HKD";
        case Currency::HNL: return "HNL";
        case Currency::HRK: return "HRK";
        case Currency::HUF: return "HUF";
        case Currency::IDR: return "IDR";
        case Currency::ILS: return "ILS";
        case Currency::INR: return "INR";
        case Currency::ISK: return "ISK";
        case Currency::JMD: return "JMD";
        case Currency::JPY: return "JPY";
        case Currency::KES: return "KES";
        case Currency::KGS: return "KGS";
        case Currency::KRW: return "KRW";
        case Currency::KZT: return "KZT";
        case Currency::LBP: return "LBP";
        case Currency::LKR: return "LKR";
        case Currency::MAD: return "MAD";
        case Currency::MDL: return "MDL";
        case Currency::MNT: return "MNT";
        case Currency::MUR: return "MUR";
        case Currency::MVR: return "MVR";
        case Currency::MXN: return "MXN";
        case Currency::MYR: return "MYR";
        case Currency::MZN: return "MZN";
        case Currency::NGN: return "NGN";
        case Currency::NIO: return "NIO";
        case Currency::NOK: return "NOK";
        case Currency::NPR: return "NPR";
        case Currency::NZD: return "NZD";
        case Currency::PAB: return "PAB";
        case Currency::PEN: return "PEN";
        case Currency::PHP: return "PHP";
        case Currency::PKR: return "PKR";
        case Currency::PLN: return "PLN";
        case Currency::PYG: return "PYG";
        case Currency::QAR: return "QAR";
        case Currency::RON: return "RON";
        case Currency::RSD: return "RSD";
        case Currency::RUB: return "RUB";
        case Currency::SAR: return "SAR";
        case Currency::SEK: return "SEK";
        case Currency::SGD: return "SGD";
        case Currency::THB: return "THB";
        case Currency::TJS: return "TJS";
        case Currency::TRY: return "TRY";
        case Currency::TTD: return "TTD";
        case Currency::TWD: return "TWD";
        case Currency::TZS: return "TZS";
        case Currency::UAH: return "UAH";
        case Currency::UGX: return "UGX";
        case Currency::USD: return "USD";
        case Currency::UYU: return "UYU";
        case Currency::UZS: return "UZS";
        case Currency::VND: return "VND";
        case Currency::YER: return "YER";
        case Currency::ZAR: return "ZAR";
        }
        return "";
    }

    inline std::optional<Currency> Currency_from_string(std::string_view s) noexcept {
        if (s == "AED") return Currency::AED;
        if (s == "AFN") return Currency::AFN;
        if (s == "ALL") return Currency::ALL;
        if (s == "AMD") return Currency::AMD;
        if (s == "ARS") return Currency::ARS;
        if (s == "AUD") return Currency::AUD;
        if (s == "AZN") return Currency::AZN;
        if (s == "BAM") return Currency::BAM;
        if (s == "BDT") return Currency::BDT;
        if (s == "BGN") return Currency::BGN;
        if (s == "BND") return Currency::BND;
        if (s == "BOB") return Currency::BOB;
        if (s == "BRL") return Currency::BRL;
        if (s == "BYN") return Currency::BYN;
        if (s == "CAD") return Currency::CAD;
        if (s == "CHF") return Currency::CHF;
        if (s == "CLP") return Currency::CLP;
        if (s == "CNY") return Currency::CNY;
        if (s == "COP") return Currency::COP;
        if (s == "CRC") return Currency::CRC;
        if (s == "CZK") return Currency::CZK;
        if (s == "DKK") return Currency::DKK;
        if (s == "DOP") return Currency::DOP;
        if (s == "DZD") return Currency::DZD;
        if (s == "EGP") return Currency::EGP;
        if (s == "ETB") return Currency::ETB;
        if (s == "EUR") return Currency::EUR;
        if (s == "GBP") return Currency::GBP;
        if (s == "GEL") return Currency::GEL;
        if (s == "GTQ") return Currency::GTQ;
        if (s == "HKD") return Currency::HKD;
        if (s == "HNL") return Currency::HNL;
        if (s == "HRK") return Currency::HRK;
        if (s == "HUF") return Currency::HUF;
        if (s == "IDR") return Currency::IDR;
        if (s == "ILS") return Currency::ILS;
        if (s == "INR") return Currency::INR;
        if (s == "ISK") return Currency::ISK;
        if (s == "JMD") return Currency::JMD;
        if (s == "JPY") return Currency::JPY;
        if (s == "KES") return Currency::KES;
        if (s == "KGS") return Currency::KGS;
        if (s == "KRW") return Currency::KRW;
        if (s == "KZT") return Currency::KZT;
        if (s == "LBP") return Currency::LBP;
        if (s == "LKR") return Currency::LKR;
        if (s == "MAD") return Currency::MAD;
        if (s == "MDL") return Currency::MDL;
        if (s == "MNT") return Currency::MNT;
        if (s == "MUR") return Currency::MUR;
        if (s == "MVR") return Currency::MVR;
        if (s == "MXN") return Currency::MXN;
        if (s == "MYR") return Currency::MYR;
        if (s == "MZN") return Currency::MZN;
        if (s == "NGN") return Currency::NGN;
        if (s == "NIO") return Currency::NIO;
        if (s == "NOK") return Currency::NOK;
        if (s == "NPR") return Currency::NPR;
        if (s == "NZD") return Currency::NZD;
        if (s == "PAB") return Currency::PAB;
        if (s == "PEN") return Currency::PEN;
        if (s == "PHP") return Currency::PHP;
        if (s == "PKR") return Currency::PKR;
        if (s == "PLN") return Currency::PLN;
        if (s == "PYG") return Currency::PYG;
        if (s == "QAR") return Currency::QAR;
        if (s == "RON") return Currency::RON;
        if (s == "RSD") return Currency::RSD;
        if (s == "RUB") return Currency::RUB;
        if (s == "SAR") return Currency::SAR;
        if (s == "SEK") return Currency::SEK;
        if (s == "SGD") return Currency::SGD;
        if (s == "THB") return Currency::THB;
        if (s == "TJS") return Currency::TJS;
        if (s == "TRY") return Currency::TRY;
        if (s == "TTD") return Currency::TTD;
        if (s == "TWD") return Currency::TWD;
        if (s == "TZS") return Currency::TZS;
        if (s == "UAH") return Currency::UAH;
        if (s == "UGX") return Currency::UGX;
        if (s == "USD") return Currency::USD;
        if (s == "UYU") return Currency::UYU;
        if (s == "UZS") return Currency::UZS;
        if (s == "VND") return Currency::VND;
        if (s == "YER") return Currency::YER;
        if (s == "ZAR") return Currency::ZAR;
        return std::nullopt;
    }

    /**
     * Emoji on which the dice throw animation is based
     * 
     * Source: https://core.telegram.org/bots/api#dice
     */
    // ── DiceEmoji ─────────────────────────────────────────────────
    enum class DiceEmoji : uint8_t {
        Dice,  ///< Dice
        Dart,  ///< Dart
        Basketball,  ///< Basketball
        Football,  ///< Football
        SlotMachine,  ///< SlotMachine
        Bowling,  ///< Bowling
    };

    inline std::string_view to_string(DiceEmoji v) noexcept {
        switch (v) {
        case DiceEmoji::Dice: return "🎲";
        case DiceEmoji::Dart: return "🎯";
        case DiceEmoji::Basketball: return "🏀";
        case DiceEmoji::Football: return "⚽";
        case DiceEmoji::SlotMachine: return "🎰";
        case DiceEmoji::Bowling: return "🎳";
        }
        return "";
    }

    inline std::optional<DiceEmoji> DiceEmoji_from_string(std::string_view s) noexcept {
        if (s == "🎲") return DiceEmoji::Dice;
        if (s == "🎯") return DiceEmoji::Dart;
        if (s == "🏀") return DiceEmoji::Basketball;
        if (s == "⚽") return DiceEmoji::Football;
        if (s == "🎰") return DiceEmoji::SlotMachine;
        if (s == "🎳") return DiceEmoji::Bowling;
        return std::nullopt;
    }

    /**
     * This object represents type of encrypted passport element.
     * 
     * Source: https://core.telegram.org/bots/api#encryptedpassportelement
     */
    // ── EncryptedPassportElement ──────────────────────────────────
    enum class EncryptedPassportElement : uint8_t {
        PersonalDetails,  ///< PersonalDetails
        Passport,  ///< Passport
        DriverLicense,  ///< DriverLicense
        IdentityCard,  ///< IdentityCard
        InternalPassport,  ///< InternalPassport
        Address,  ///< Address
        UtilityBill,  ///< UtilityBill
        BankStatement,  ///< BankStatement
        RentalAgreement,  ///< RentalAgreement
        PassportRegistration,  ///< PassportRegistration
        TemporaryRegistration,  ///< TemporaryRegistration
        PhoneNumber,  ///< PhoneNumber
        Email,  ///< Email
    };

    inline std::string_view to_string(EncryptedPassportElement v) noexcept {
        switch (v) {
        case EncryptedPassportElement::PersonalDetails: return "personal_details";
        case EncryptedPassportElement::Passport: return "passport";
        case EncryptedPassportElement::DriverLicense: return "driver_license";
        case EncryptedPassportElement::IdentityCard: return "identity_card";
        case EncryptedPassportElement::InternalPassport: return "internal_passport";
        case EncryptedPassportElement::Address: return "address";
        case EncryptedPassportElement::UtilityBill: return "utility_bill";
        case EncryptedPassportElement::BankStatement: return "bank_statement";
        case EncryptedPassportElement::RentalAgreement: return "rental_agreement";
        case EncryptedPassportElement::PassportRegistration: return "passport_registration";
        case EncryptedPassportElement::TemporaryRegistration: return "temporary_registration";
        case EncryptedPassportElement::PhoneNumber: return "phone_number";
        case EncryptedPassportElement::Email: return "email";
        }
        return "";
    }

    inline std::optional<EncryptedPassportElement> EncryptedPassportElement_from_string(std::string_view s) noexcept {
        if (s == "personal_details") return EncryptedPassportElement::PersonalDetails;
        if (s == "passport") return EncryptedPassportElement::Passport;
        if (s == "driver_license") return EncryptedPassportElement::DriverLicense;
        if (s == "identity_card") return EncryptedPassportElement::IdentityCard;
        if (s == "internal_passport") return EncryptedPassportElement::InternalPassport;
        if (s == "address") return EncryptedPassportElement::Address;
        if (s == "utility_bill") return EncryptedPassportElement::UtilityBill;
        if (s == "bank_statement") return EncryptedPassportElement::BankStatement;
        if (s == "rental_agreement") return EncryptedPassportElement::RentalAgreement;
        if (s == "passport_registration") return EncryptedPassportElement::PassportRegistration;
        if (s == "temporary_registration") return EncryptedPassportElement::TemporaryRegistration;
        if (s == "phone_number") return EncryptedPassportElement::PhoneNumber;
        if (s == "email") return EncryptedPassportElement::Email;
        return std::nullopt;
    }

    /**
     * Type of inline query result
     * 
     * Source: https://core.telegram.org/bots/api#inlinequeryresult
     */
    // ── InlineQueryResultType ─────────────────────────────────────
    enum class InlineQueryResultType : uint8_t {
        Audio,  ///< Audio
        Document,  ///< Document
        Gif,  ///< Gif
        Mpeg4Gif,  ///< Mpeg4Gif
        Photo,  ///< Photo
        Sticker,  ///< Sticker
        Video,  ///< Video
        Voice,  ///< Voice
        Article,  ///< Article
        Contact,  ///< Contact
        Game,  ///< Game
        Location,  ///< Location
        Venue,  ///< Venue
    };

    inline std::string_view to_string(InlineQueryResultType v) noexcept {
        switch (v) {
        case InlineQueryResultType::Audio: return "audio";
        case InlineQueryResultType::Document: return "document";
        case InlineQueryResultType::Gif: return "gif";
        case InlineQueryResultType::Mpeg4Gif: return "mpeg4_gif";
        case InlineQueryResultType::Photo: return "photo";
        case InlineQueryResultType::Sticker: return "sticker";
        case InlineQueryResultType::Video: return "video";
        case InlineQueryResultType::Voice: return "voice";
        case InlineQueryResultType::Article: return "article";
        case InlineQueryResultType::Contact: return "contact";
        case InlineQueryResultType::Game: return "game";
        case InlineQueryResultType::Location: return "location";
        case InlineQueryResultType::Venue: return "venue";
        }
        return "";
    }

    inline std::optional<InlineQueryResultType> InlineQueryResultType_from_string(std::string_view s) noexcept {
        if (s == "audio") return InlineQueryResultType::Audio;
        if (s == "document") return InlineQueryResultType::Document;
        if (s == "gif") return InlineQueryResultType::Gif;
        if (s == "mpeg4_gif") return InlineQueryResultType::Mpeg4Gif;
        if (s == "photo") return InlineQueryResultType::Photo;
        if (s == "sticker") return InlineQueryResultType::Sticker;
        if (s == "video") return InlineQueryResultType::Video;
        if (s == "voice") return InlineQueryResultType::Voice;
        if (s == "article") return InlineQueryResultType::Article;
        if (s == "contact") return InlineQueryResultType::Contact;
        if (s == "game") return InlineQueryResultType::Game;
        if (s == "location") return InlineQueryResultType::Location;
        if (s == "venue") return InlineQueryResultType::Venue;
        return std::nullopt;
    }

    /**
     * This object represents input media type
     * 
     * Source: https://core.telegram.org/bots/api#inputmedia
     */
    // ── InputMediaType ────────────────────────────────────────────
    enum class InputMediaType : uint8_t {
        Animation,  ///< Animation
        Audio,  ///< Audio
        Document,  ///< Document
        Photo,  ///< Photo
        Video,  ///< Video
    };

    inline std::string_view to_string(InputMediaType v) noexcept {
        switch (v) {
        case InputMediaType::Animation: return "animation";
        case InputMediaType::Audio: return "audio";
        case InputMediaType::Document: return "document";
        case InputMediaType::Photo: return "photo";
        case InputMediaType::Video: return "video";
        }
        return "";
    }

    inline std::optional<InputMediaType> InputMediaType_from_string(std::string_view s) noexcept {
        if (s == "animation") return InputMediaType::Animation;
        if (s == "audio") return InputMediaType::Audio;
        if (s == "document") return InputMediaType::Document;
        if (s == "photo") return InputMediaType::Photo;
        if (s == "video") return InputMediaType::Video;
        return std::nullopt;
    }

    /**
     * This object represents the type of a media in a paid message.
     * 
     * Source: https://core.telegram.org/bots/api#inputpaidmedia
     */
    // ── InputPaidMediaType ────────────────────────────────────────
    enum class InputPaidMediaType : uint8_t {
        Photo,  ///< Photo
        Video,  ///< Video
    };

    inline std::string_view to_string(InputPaidMediaType v) noexcept {
        switch (v) {
        case InputPaidMediaType::Photo: return "photo";
        case InputPaidMediaType::Video: return "video";
        }
        return "";
    }

    inline std::optional<InputPaidMediaType> InputPaidMediaType_from_string(std::string_view s) noexcept {
        if (s == "photo") return InputPaidMediaType::Photo;
        if (s == "video") return InputPaidMediaType::Video;
        return std::nullopt;
    }

    /**
     * This object represents input profile photo type
     * 
     * Source: https://core.telegram.org/bots/api#inputprofilephoto
     */
    // ── InputProfilePhotoType ─────────────────────────────────────
    enum class InputProfilePhotoType : uint8_t {
        Static,  ///< Static
        Animated,  ///< Animated
    };

    inline std::string_view to_string(InputProfilePhotoType v) noexcept {
        switch (v) {
        case InputProfilePhotoType::Static: return "static";
        case InputProfilePhotoType::Animated: return "animated";
        }
        return "";
    }

    inline std::optional<InputProfilePhotoType> InputProfilePhotoType_from_string(std::string_view s) noexcept {
        if (s == "static") return InputProfilePhotoType::Static;
        if (s == "animated") return InputProfilePhotoType::Animated;
        return std::nullopt;
    }

    /**
     * This object represents input story content photo type.
     * 
     * Source: https://core.telegram.org/bots/api#inputstorycontentphoto
     */
    // ── InputStoryContentType ─────────────────────────────────────
    enum class InputStoryContentType : uint8_t {
        Photo,  ///< Photo
        Video,  ///< Video
    };

    inline std::string_view to_string(InputStoryContentType v) noexcept {
        switch (v) {
        case InputStoryContentType::Photo: return "photo";
        case InputStoryContentType::Video: return "video";
        }
        return "";
    }

    inline std::optional<InputStoryContentType> InputStoryContentType_from_string(std::string_view s) noexcept {
        if (s == "photo") return InputStoryContentType::Photo;
        if (s == "video") return InputStoryContentType::Video;
        return std::nullopt;
    }

    /**
     * This object represents type of a poll, which is allowed to be created and sent when the corresponding button is pressed.
     * 
     * Source: https://core.telegram.org/bots/api#keyboardbuttonpolltype
     */
    // ── KeyboardButtonPollTypeType ────────────────────────────────
    enum class KeyboardButtonPollTypeType : uint8_t {
        Quiz,  ///< Quiz
        Regular,  ///< Regular
    };

    inline std::string_view to_string(KeyboardButtonPollTypeType v) noexcept {
        switch (v) {
        case KeyboardButtonPollTypeType::Quiz: return "quiz";
        case KeyboardButtonPollTypeType::Regular: return "regular";
        }
        return "";
    }

    inline std::optional<KeyboardButtonPollTypeType> KeyboardButtonPollTypeType_from_string(std::string_view s) noexcept {
        if (s == "quiz") return KeyboardButtonPollTypeType::Quiz;
        if (s == "regular") return KeyboardButtonPollTypeType::Regular;
        return std::nullopt;
    }

    /**
     * The part of the face relative to which the mask should be placed.
     * 
     * Source: https://core.telegram.org/bots/api#maskposition
     */
    // ── MaskPositionPoint ─────────────────────────────────────────
    enum class MaskPositionPoint : uint8_t {
        Forehead,  ///< Forehead
        Eyes,  ///< Eyes
        Mouth,  ///< Mouth
        Chin,  ///< Chin
    };

    inline std::string_view to_string(MaskPositionPoint v) noexcept {
        switch (v) {
        case MaskPositionPoint::Forehead: return "forehead";
        case MaskPositionPoint::Eyes: return "eyes";
        case MaskPositionPoint::Mouth: return "mouth";
        case MaskPositionPoint::Chin: return "chin";
        }
        return "";
    }

    inline std::optional<MaskPositionPoint> MaskPositionPoint_from_string(std::string_view s) noexcept {
        if (s == "forehead") return MaskPositionPoint::Forehead;
        if (s == "eyes") return MaskPositionPoint::Eyes;
        if (s == "mouth") return MaskPositionPoint::Mouth;
        if (s == "chin") return MaskPositionPoint::Chin;
        return std::nullopt;
    }

    /**
     * This object represents an type of Menu button
     * 
     * Source: https://core.telegram.org/bots/api#menubuttondefault
     */
    // ── MenuButtonType ────────────────────────────────────────────
    enum class MenuButtonType : uint8_t {
        Default,  ///< Default
        Commands,  ///< Commands
        WebApp,  ///< WebApp
    };

    inline std::string_view to_string(MenuButtonType v) noexcept {
        switch (v) {
        case MenuButtonType::Default: return "default";
        case MenuButtonType::Commands: return "commands";
        case MenuButtonType::WebApp: return "web_app";
        }
        return "";
    }

    inline std::optional<MenuButtonType> MenuButtonType_from_string(std::string_view s) noexcept {
        if (s == "default") return MenuButtonType::Default;
        if (s == "commands") return MenuButtonType::Commands;
        if (s == "web_app") return MenuButtonType::WebApp;
        return std::nullopt;
    }

    /**
     * This object represents type of message entity
     * 
     * Source: https://core.telegram.org/bots/api#messageentity
     */
    // ── MessageEntityType ─────────────────────────────────────────
    enum class MessageEntityType : uint8_t {
        Mention,  ///< Mention
        Hashtag,  ///< Hashtag
        Cashtag,  ///< Cashtag
        BotCommand,  ///< BotCommand
        Url,  ///< Url
        Email,  ///< Email
        PhoneNumber,  ///< PhoneNumber
        Bold,  ///< Bold
        Italic,  ///< Italic
        Underline,  ///< Underline
        Strikethrough,  ///< Strikethrough
        Spoiler,  ///< Spoiler
        Blockquote,  ///< Blockquote
        ExpandableBlockquote,  ///< ExpandableBlockquote
        Code,  ///< Code
        Pre,  ///< Pre
        TextLink,  ///< TextLink
        TextMention,  ///< TextMention
        CustomEmoji,  ///< CustomEmoji
        DateTime,  ///< DateTime
    };

    inline std::string_view to_string(MessageEntityType v) noexcept {
        switch (v) {
        case MessageEntityType::Mention: return "mention";
        case MessageEntityType::Hashtag: return "hashtag";
        case MessageEntityType::Cashtag: return "cashtag";
        case MessageEntityType::BotCommand: return "bot_command";
        case MessageEntityType::Url: return "url";
        case MessageEntityType::Email: return "email";
        case MessageEntityType::PhoneNumber: return "phone_number";
        case MessageEntityType::Bold: return "bold";
        case MessageEntityType::Italic: return "italic";
        case MessageEntityType::Underline: return "underline";
        case MessageEntityType::Strikethrough: return "strikethrough";
        case MessageEntityType::Spoiler: return "spoiler";
        case MessageEntityType::Blockquote: return "blockquote";
        case MessageEntityType::ExpandableBlockquote: return "expandable_blockquote";
        case MessageEntityType::Code: return "code";
        case MessageEntityType::Pre: return "pre";
        case MessageEntityType::TextLink: return "text_link";
        case MessageEntityType::TextMention: return "text_mention";
        case MessageEntityType::CustomEmoji: return "custom_emoji";
        case MessageEntityType::DateTime: return "date_time";
        }
        return "";
    }

    inline std::optional<MessageEntityType> MessageEntityType_from_string(std::string_view s) noexcept {
        if (s == "mention") return MessageEntityType::Mention;
        if (s == "hashtag") return MessageEntityType::Hashtag;
        if (s == "cashtag") return MessageEntityType::Cashtag;
        if (s == "bot_command") return MessageEntityType::BotCommand;
        if (s == "url") return MessageEntityType::Url;
        if (s == "email") return MessageEntityType::Email;
        if (s == "phone_number") return MessageEntityType::PhoneNumber;
        if (s == "bold") return MessageEntityType::Bold;
        if (s == "italic") return MessageEntityType::Italic;
        if (s == "underline") return MessageEntityType::Underline;
        if (s == "strikethrough") return MessageEntityType::Strikethrough;
        if (s == "spoiler") return MessageEntityType::Spoiler;
        if (s == "blockquote") return MessageEntityType::Blockquote;
        if (s == "expandable_blockquote") return MessageEntityType::ExpandableBlockquote;
        if (s == "code") return MessageEntityType::Code;
        if (s == "pre") return MessageEntityType::Pre;
        if (s == "text_link") return MessageEntityType::TextLink;
        if (s == "text_mention") return MessageEntityType::TextMention;
        if (s == "custom_emoji") return MessageEntityType::CustomEmoji;
        if (s == "date_time") return MessageEntityType::DateTime;
        return std::nullopt;
    }

    /**
     * This object represents origin of a message.
     * 
     * Source: https://core.telegram.org/bots/api#messageorigin
     */
    // ── MessageOriginType ─────────────────────────────────────────
    enum class MessageOriginType : uint8_t {
        User,  ///< User
        HiddenUser,  ///< HiddenUser
        Chat,  ///< Chat
        Channel,  ///< Channel
    };

    inline std::string_view to_string(MessageOriginType v) noexcept {
        switch (v) {
        case MessageOriginType::User: return "user";
        case MessageOriginType::HiddenUser: return "hidden_user";
        case MessageOriginType::Chat: return "chat";
        case MessageOriginType::Channel: return "channel";
        }
        return "";
    }

    inline std::optional<MessageOriginType> MessageOriginType_from_string(std::string_view s) noexcept {
        if (s == "user") return MessageOriginType::User;
        if (s == "hidden_user") return MessageOriginType::HiddenUser;
        if (s == "chat") return MessageOriginType::Chat;
        if (s == "channel") return MessageOriginType::Channel;
        return std::nullopt;
    }

    /**
     * This object represents owned gift type
     * 
     * Source: https://core.telegram.org/bots/api#ownedgift
     */
    // ── OwnedGiftType ─────────────────────────────────────────────
    enum class OwnedGiftType : uint8_t {
        Regular,  ///< Regular
        Unique,  ///< Unique
    };

    inline std::string_view to_string(OwnedGiftType v) noexcept {
        switch (v) {
        case OwnedGiftType::Regular: return "regular";
        case OwnedGiftType::Unique: return "unique";
        }
        return "";
    }

    inline std::optional<OwnedGiftType> OwnedGiftType_from_string(std::string_view s) noexcept {
        if (s == "regular") return OwnedGiftType::Regular;
        if (s == "unique") return OwnedGiftType::Unique;
        return std::nullopt;
    }

    /**
     * This object represents the type of a media in a paid message.
     * 
     * Source: https://core.telegram.org/bots/api#paidmedia
     */
    // ── PaidMediaType ─────────────────────────────────────────────
    enum class PaidMediaType : uint8_t {
        Photo,  ///< Photo
        Preview,  ///< Preview
        Video,  ///< Video
    };

    inline std::string_view to_string(PaidMediaType v) noexcept {
        switch (v) {
        case PaidMediaType::Photo: return "photo";
        case PaidMediaType::Preview: return "preview";
        case PaidMediaType::Video: return "video";
        }
        return "";
    }

    inline std::optional<PaidMediaType> PaidMediaType_from_string(std::string_view s) noexcept {
        if (s == "photo") return PaidMediaType::Photo;
        if (s == "preview") return PaidMediaType::Preview;
        if (s == "video") return PaidMediaType::Video;
        return std::nullopt;
    }

    /**
     * Formatting options
     * 
     * Source: https://core.telegram.org/bots/api#formatting-options
     */
    // ── ParseMode ─────────────────────────────────────────────────
    enum class ParseMode : uint8_t {
        MarkdownV2,  ///< MarkdownV2
        Markdown,  ///< Markdown
        HTML,  ///< HTML
    };

    inline std::string_view to_string(ParseMode v) noexcept {
        switch (v) {
        case ParseMode::MarkdownV2: return "MarkdownV2";
        case ParseMode::Markdown: return "Markdown";
        case ParseMode::HTML: return "HTML";
        }
        return "";
    }

    inline std::optional<ParseMode> ParseMode_from_string(std::string_view s) noexcept {
        if (s == "MarkdownV2") return ParseMode::MarkdownV2;
        if (s == "Markdown") return ParseMode::Markdown;
        if (s == "HTML") return ParseMode::HTML;
        return std::nullopt;
    }

    /**
     * This object represents a passport element error type.
     * 
     * Source: https://core.telegram.org/bots/api#passportelementerror
     */
    // ── PassportElementErrorType ──────────────────────────────────
    enum class PassportElementErrorType : uint8_t {
        DataField,  ///< DataField
        FrontSide,  ///< FrontSide
        ReverseSide,  ///< ReverseSide
        Selfie,  ///< Selfie
        File,  ///< File
        Files,  ///< Files
        TranslationFile,  ///< TranslationFile
        TranslationFiles,  ///< TranslationFiles
        Unspecified,  ///< Unspecified
    };

    inline std::string_view to_string(PassportElementErrorType v) noexcept {
        switch (v) {
        case PassportElementErrorType::DataField: return "data";
        case PassportElementErrorType::FrontSide: return "front_side";
        case PassportElementErrorType::ReverseSide: return "reverse_side";
        case PassportElementErrorType::Selfie: return "selfie";
        case PassportElementErrorType::File: return "file";
        case PassportElementErrorType::Files: return "files";
        case PassportElementErrorType::TranslationFile: return "translation_file";
        case PassportElementErrorType::TranslationFiles: return "translation_files";
        case PassportElementErrorType::Unspecified: return "unspecified";
        }
        return "";
    }

    inline std::optional<PassportElementErrorType> PassportElementErrorType_from_string(std::string_view s) noexcept {
        if (s == "data") return PassportElementErrorType::DataField;
        if (s == "front_side") return PassportElementErrorType::FrontSide;
        if (s == "reverse_side") return PassportElementErrorType::ReverseSide;
        if (s == "selfie") return PassportElementErrorType::Selfie;
        if (s == "file") return PassportElementErrorType::File;
        if (s == "files") return PassportElementErrorType::Files;
        if (s == "translation_file") return PassportElementErrorType::TranslationFile;
        if (s == "translation_files") return PassportElementErrorType::TranslationFiles;
        if (s == "unspecified") return PassportElementErrorType::Unspecified;
        return std::nullopt;
    }

    /**
     * This object represents poll type
     * 
     * Source: https://core.telegram.org/bots/api#poll
     */
    // ── PollType ──────────────────────────────────────────────────
    enum class PollType : uint8_t {
        Regular,  ///< Regular
        Quiz,  ///< Quiz
    };

    inline std::string_view to_string(PollType v) noexcept {
        switch (v) {
        case PollType::Regular: return "regular";
        case PollType::Quiz: return "quiz";
        }
        return "";
    }

    inline std::optional<PollType> PollType_from_string(std::string_view s) noexcept {
        if (s == "regular") return PollType::Regular;
        if (s == "quiz") return PollType::Quiz;
        return std::nullopt;
    }

    /**
     * This object represents reaction type.
     * 
     * Source: https://core.telegram.org/bots/api#reactiontype
     */
    // ── ReactionTypeType ──────────────────────────────────────────
    enum class ReactionTypeType : uint8_t {
        Emoji,  ///< Emoji
        CustomEmoji,  ///< CustomEmoji
        Paid,  ///< Paid
    };

    inline std::string_view to_string(ReactionTypeType v) noexcept {
        switch (v) {
        case ReactionTypeType::Emoji: return "emoji";
        case ReactionTypeType::CustomEmoji: return "custom_emoji";
        case ReactionTypeType::Paid: return "paid";
        }
        return "";
    }

    inline std::optional<ReactionTypeType> ReactionTypeType_from_string(std::string_view s) noexcept {
        if (s == "emoji") return ReactionTypeType::Emoji;
        if (s == "custom_emoji") return ReactionTypeType::CustomEmoji;
        if (s == "paid") return ReactionTypeType::Paid;
        return std::nullopt;
    }

    /**
     * This object represents a revenue withdrawal state type
     * 
     * Source: https://core.telegram.org/bots/api#revenuewithdrawalstate
     */
    // ── RevenueWithdrawalStateType ────────────────────────────────
    enum class RevenueWithdrawalStateType : uint8_t {
        Failed,  ///< Failed
        Pending,  ///< Pending
        Succeeded,  ///< Succeeded
    };

    inline std::string_view to_string(RevenueWithdrawalStateType v) noexcept {
        switch (v) {
        case RevenueWithdrawalStateType::Failed: return "failed";
        case RevenueWithdrawalStateType::Pending: return "pending";
        case RevenueWithdrawalStateType::Succeeded: return "succeeded";
        }
        return "";
    }

    inline std::optional<RevenueWithdrawalStateType> RevenueWithdrawalStateType_from_string(std::string_view s) noexcept {
        if (s == "failed") return RevenueWithdrawalStateType::Failed;
        if (s == "pending") return RevenueWithdrawalStateType::Pending;
        if (s == "succeeded") return RevenueWithdrawalStateType::Succeeded;
        return std::nullopt;
    }

    /**
     * Format of the sticker
     * 
     * Source: https://core.telegram.org/bots/api#createnewstickerset
     */
    // ── StickerFormat ─────────────────────────────────────────────
    enum class StickerFormat : uint8_t {
        Static,  ///< Static
        Animated,  ///< Animated
        Video,  ///< Video
    };

    inline std::string_view to_string(StickerFormat v) noexcept {
        switch (v) {
        case StickerFormat::Static: return "static";
        case StickerFormat::Animated: return "animated";
        case StickerFormat::Video: return "video";
        }
        return "";
    }

    inline std::optional<StickerFormat> StickerFormat_from_string(std::string_view s) noexcept {
        if (s == "static") return StickerFormat::Static;
        if (s == "animated") return StickerFormat::Animated;
        if (s == "video") return StickerFormat::Video;
        return std::nullopt;
    }

    /**
     * The part of the face relative to which the mask should be placed.
     * 
     * Source: https://core.telegram.org/bots/api#maskposition
     */
    // ── StickerType ───────────────────────────────────────────────
    enum class StickerType : uint8_t {
        Regular,  ///< Regular
        Mask,  ///< Mask
        CustomEmoji,  ///< CustomEmoji
    };

    inline std::string_view to_string(StickerType v) noexcept {
        switch (v) {
        case StickerType::Regular: return "regular";
        case StickerType::Mask: return "mask";
        case StickerType::CustomEmoji: return "custom_emoji";
        }
        return "";
    }

    inline std::optional<StickerType> StickerType_from_string(std::string_view s) noexcept {
        if (s == "regular") return StickerType::Regular;
        if (s == "mask") return StickerType::Mask;
        if (s == "custom_emoji") return StickerType::CustomEmoji;
        return std::nullopt;
    }

    /**
     * This object represents input profile photo type
     * 
     * Source: https://core.telegram.org/bots/api#storyareatype
     */
    // ── StoryAreaTypeType ─────────────────────────────────────────
    enum class StoryAreaTypeType : uint8_t {
        Location,  ///< Location
        SuggestedReaction,  ///< SuggestedReaction
        Link,  ///< Link
        Weather,  ///< Weather
        UniqueGift,  ///< UniqueGift
    };

    inline std::string_view to_string(StoryAreaTypeType v) noexcept {
        switch (v) {
        case StoryAreaTypeType::Location: return "location";
        case StoryAreaTypeType::SuggestedReaction: return "suggested_reaction";
        case StoryAreaTypeType::Link: return "link";
        case StoryAreaTypeType::Weather: return "weather";
        case StoryAreaTypeType::UniqueGift: return "unique_gift";
        }
        return "";
    }

    inline std::optional<StoryAreaTypeType> StoryAreaTypeType_from_string(std::string_view s) noexcept {
        if (s == "location") return StoryAreaTypeType::Location;
        if (s == "suggested_reaction") return StoryAreaTypeType::SuggestedReaction;
        if (s == "link") return StoryAreaTypeType::Link;
        if (s == "weather") return StoryAreaTypeType::Weather;
        if (s == "unique_gift") return StoryAreaTypeType::UniqueGift;
        return std::nullopt;
    }

    /**
     * Color of the topic icon in RGB format.
     * 
     * Source: https://github.com/telegramdesktop/tdesktop/blob/991fe491c5ae62705d77aa8fdd44a79caf639c45/Telegram/SourceFiles/data/data_forum_topic.cpp#L51-L56
     */
    // ── TopicIconColor ────────────────────────────────────────────
    enum class TopicIconColor : uint32_t {
        Blue = 0x6FB9F0,  ///< Blue
        Yellow = 0xFFD67E,  ///< Yellow
        Violet = 0xCB86DB,  ///< Violet
        Green = 0x8EEE98,  ///< Green
        Rose = 0xFF93B2,  ///< Rose
        Red = 0xFB6F5F,  ///< Red
    };

    inline uint32_t to_int(TopicIconColor v) noexcept {
        return static_cast<uint32_t>(v);
    }

    /**
     * This object represents a type of transaction partner.
     * 
     * Source: https://core.telegram.org/bots/api#transactionpartner
     */
    // ── TransactionPartnerType ────────────────────────────────────
    enum class TransactionPartnerType : uint8_t {
        Fragment,  ///< Fragment
        Other,  ///< Other
        User,  ///< User
        TelegramAds,  ///< TelegramAds
        TelegramApi,  ///< TelegramApi
        AffiliateProgram,  ///< AffiliateProgram
        Chat,  ///< Chat
    };

    inline std::string_view to_string(TransactionPartnerType v) noexcept {
        switch (v) {
        case TransactionPartnerType::Fragment: return "fragment";
        case TransactionPartnerType::Other: return "other";
        case TransactionPartnerType::User: return "user";
        case TransactionPartnerType::TelegramAds: return "telegram_ads";
        case TransactionPartnerType::TelegramApi: return "telegram_api";
        case TransactionPartnerType::AffiliateProgram: return "affiliate_program";
        case TransactionPartnerType::Chat: return "chat";
        }
        return "";
    }

    inline std::optional<TransactionPartnerType> TransactionPartnerType_from_string(std::string_view s) noexcept {
        if (s == "fragment") return TransactionPartnerType::Fragment;
        if (s == "other") return TransactionPartnerType::Other;
        if (s == "user") return TransactionPartnerType::User;
        if (s == "telegram_ads") return TransactionPartnerType::TelegramAds;
        if (s == "telegram_api") return TransactionPartnerType::TelegramApi;
        if (s == "affiliate_program") return TransactionPartnerType::AffiliateProgram;
        if (s == "chat") return TransactionPartnerType::Chat;
        return std::nullopt;
    }

    /**
     * This object represents type of the transaction that were made by partner user.
     * 
     * Source: https://core.telegram.org/bots/api#transactionpartneruser
     */
    // ── TransactionPartnerUserTransactionTypeEnum ─────────────────
    enum class TransactionPartnerUserTransactionTypeEnum : uint8_t {
        InvoicePayment,  ///< InvoicePayment
        PaidMediaPayment,  ///< PaidMediaPayment
        GiftPurchase,  ///< GiftPurchase
        PremiumPurchase,  ///< PremiumPurchase
        BusinessAccountTransfer,  ///< BusinessAccountTransfer
    };

    inline std::string_view to_string(TransactionPartnerUserTransactionTypeEnum v) noexcept {
        switch (v) {
        case TransactionPartnerUserTransactionTypeEnum::InvoicePayment: return "invoice_payment";
        case TransactionPartnerUserTransactionTypeEnum::PaidMediaPayment: return "paid_media_payment";
        case TransactionPartnerUserTransactionTypeEnum::GiftPurchase: return "gift_purchase";
        case TransactionPartnerUserTransactionTypeEnum::PremiumPurchase: return "premium_purchase";
        case TransactionPartnerUserTransactionTypeEnum::BusinessAccountTransfer: return "business_account_transfer";
        }
        return "";
    }

    inline std::optional<TransactionPartnerUserTransactionTypeEnum> TransactionPartnerUserTransactionTypeEnum_from_string(std::string_view s) noexcept {
        if (s == "invoice_payment") return TransactionPartnerUserTransactionTypeEnum::InvoicePayment;
        if (s == "paid_media_payment") return TransactionPartnerUserTransactionTypeEnum::PaidMediaPayment;
        if (s == "gift_purchase") return TransactionPartnerUserTransactionTypeEnum::GiftPurchase;
        if (s == "premium_purchase") return TransactionPartnerUserTransactionTypeEnum::PremiumPurchase;
        if (s == "business_account_transfer") return TransactionPartnerUserTransactionTypeEnum::BusinessAccountTransfer;
        return std::nullopt;
    }

    /**
     * This object represents the complete list of allowed update types
     * 
     * Source: https://core.telegram.org/bots/api#update
     */
    // ── UpdateType ────────────────────────────────────────────────
    enum class UpdateType : uint8_t {
        Message,  ///< Message
        EditedMessage,  ///< EditedMessage
        ChannelPost,  ///< ChannelPost
        EditedChannelPost,  ///< EditedChannelPost
        BusinessConnection,  ///< BusinessConnection
        BusinessMessage,  ///< BusinessMessage
        EditedBusinessMessage,  ///< EditedBusinessMessage
        DeletedBusinessMessages,  ///< DeletedBusinessMessages
        GuestMessage,  ///< GuestMessage
        MessageReaction,  ///< MessageReaction
        MessageReactionCount,  ///< MessageReactionCount
        InlineQuery,  ///< InlineQuery
        ChosenInlineResult,  ///< ChosenInlineResult
        CallbackQuery,  ///< CallbackQuery
        ShippingQuery,  ///< ShippingQuery
        PreCheckoutQuery,  ///< PreCheckoutQuery
        PurchasedPaidMedia,  ///< PurchasedPaidMedia
        Poll,  ///< Poll
        PollAnswer,  ///< PollAnswer
        MyChatMember,  ///< MyChatMember
        ChatMember,  ///< ChatMember
        ChatJoinRequest,  ///< ChatJoinRequest
        ChatBoost,  ///< ChatBoost
        RemovedChatBoost,  ///< RemovedChatBoost
        ManagedBot,  ///< ManagedBot
    };

    inline std::string_view to_string(UpdateType v) noexcept {
        switch (v) {
        case UpdateType::Message: return "message";
        case UpdateType::EditedMessage: return "edited_message";
        case UpdateType::ChannelPost: return "channel_post";
        case UpdateType::EditedChannelPost: return "edited_channel_post";
        case UpdateType::BusinessConnection: return "business_connection";
        case UpdateType::BusinessMessage: return "business_message";
        case UpdateType::EditedBusinessMessage: return "edited_business_message";
        case UpdateType::DeletedBusinessMessages: return "deleted_business_messages";
        case UpdateType::GuestMessage: return "guest_message";
        case UpdateType::MessageReaction: return "message_reaction";
        case UpdateType::MessageReactionCount: return "message_reaction_count";
        case UpdateType::InlineQuery: return "inline_query";
        case UpdateType::ChosenInlineResult: return "chosen_inline_result";
        case UpdateType::CallbackQuery: return "callback_query";
        case UpdateType::ShippingQuery: return "shipping_query";
        case UpdateType::PreCheckoutQuery: return "pre_checkout_query";
        case UpdateType::PurchasedPaidMedia: return "purchased_paid_media";
        case UpdateType::Poll: return "poll";
        case UpdateType::PollAnswer: return "poll_answer";
        case UpdateType::MyChatMember: return "my_chat_member";
        case UpdateType::ChatMember: return "chat_member";
        case UpdateType::ChatJoinRequest: return "chat_join_request";
        case UpdateType::ChatBoost: return "chat_boost";
        case UpdateType::RemovedChatBoost: return "removed_chat_boost";
        case UpdateType::ManagedBot: return "managed_bot";
        }
        return "";
    }

    inline std::optional<UpdateType> UpdateType_from_string(std::string_view s) noexcept {
        if (s == "message") return UpdateType::Message;
        if (s == "edited_message") return UpdateType::EditedMessage;
        if (s == "channel_post") return UpdateType::ChannelPost;
        if (s == "edited_channel_post") return UpdateType::EditedChannelPost;
        if (s == "business_connection") return UpdateType::BusinessConnection;
        if (s == "business_message") return UpdateType::BusinessMessage;
        if (s == "edited_business_message") return UpdateType::EditedBusinessMessage;
        if (s == "deleted_business_messages") return UpdateType::DeletedBusinessMessages;
        if (s == "guest_message") return UpdateType::GuestMessage;
        if (s == "message_reaction") return UpdateType::MessageReaction;
        if (s == "message_reaction_count") return UpdateType::MessageReactionCount;
        if (s == "inline_query") return UpdateType::InlineQuery;
        if (s == "chosen_inline_result") return UpdateType::ChosenInlineResult;
        if (s == "callback_query") return UpdateType::CallbackQuery;
        if (s == "shipping_query") return UpdateType::ShippingQuery;
        if (s == "pre_checkout_query") return UpdateType::PreCheckoutQuery;
        if (s == "purchased_paid_media") return UpdateType::PurchasedPaidMedia;
        if (s == "poll") return UpdateType::Poll;
        if (s == "poll_answer") return UpdateType::PollAnswer;
        if (s == "my_chat_member") return UpdateType::MyChatMember;
        if (s == "chat_member") return UpdateType::ChatMember;
        if (s == "chat_join_request") return UpdateType::ChatJoinRequest;
        if (s == "chat_boost") return UpdateType::ChatBoost;
        if (s == "removed_chat_boost") return UpdateType::RemovedChatBoost;
        if (s == "managed_bot") return UpdateType::ManagedBot;
        return std::nullopt;
    }

} // namespace corogram::enums
