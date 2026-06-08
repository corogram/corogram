// include/fsm/StorageKey.hpp
#pragma once
#include <string>
#include <cstdint>

namespace corogram::fsm {

    struct StorageKey {
        int64_t bot_id;
        int64_t chat_id;
        int64_t user_id;

        std::string state_key() const {
            return "fsm:" + std::to_string(bot_id)
                + ":" + std::to_string(chat_id)
                + ":" + std::to_string(user_id)
                + ":state";
        }

        std::string data_key() const {
            return "fsm:" + std::to_string(bot_id)
                + ":" + std::to_string(chat_id)
                + ":" + std::to_string(user_id)
                + ":data";
        }
    };

} // namespace corogram::fsm