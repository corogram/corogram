#pragma once
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include <drogon/drogon.h>

#include <corogram/network/RequestMiddleware.hpp>
#include <corogram/Types.hpp>

namespace corogram
{

    using Bytes = std::vector<uint8_t>;

    struct DownloadResult
    {
        Bytes data;
        std::string mime_type;
        std::string filename;
    };

    class INetwork
    {
    public:
        virtual ~INetwork() = default;

        // Returns the middleware manager for this network instance.
        // Implementations should store the manager and return a reference to it.
        virtual RequestMiddlewareManager &middleware() = 0;

        /**
         * @brief Sends a JSON body request to the given API path.
         *
         * @param path   Telegram Bot API endpoint path (e.g. "/sendMessage")
         * @param body   Serialized JSON string
         * @return Raw JSON response string
         */
        virtual drogon::Task<std::string> sendRequest(
            const std::string &path,
            const std::string &body) = 0;

        /**
         * @brief Uploads files via multipart/form-data.
         *
         * URL-sourced InputFiles are downloaded first, then attached to the
         * multipart request alongside the JSON payload fields.
         *
         * @param path         Telegram Bot API endpoint path
         * @param json_payload Serialized JSON string of non-file parameters
         * @param uploads      List of files to attach
         * @return Raw JSON response string
         */
        virtual drogon::Task<std::string> uploadFiles(
            const std::string &path,
            const std::string &json_payload,
            const std::vector<UploadEntry> &uploads) = 0;

        /**
         * @brief Downloads a file from the given URL.
         *
         * @param url Full URL of the file to download
         * @return DownloadResult containing raw bytes, MIME type, and filename
         */
        virtual drogon::Task<DownloadResult> downloadFile(
            const std::string &url) = 0;
    };

} // namespace corogram