// include/utils/Utf8Sanitize.hpp
#pragma once
#include <string>

namespace corogram
{

    inline std::string sanitize_utf8(const std::string &input)
    {
        std::string result;
        result.reserve(input.size());

        size_t i = 0;
        while (i < input.size())
        {
            unsigned char c = static_cast<unsigned char>(input[i]);

            // 1 byte (ASCII)
            if (c < 0x80)
            {
                result += input[i++];
            }
            // 2 byte sequence
            else if ((c & 0xE0) == 0xC0 && i + 1 < input.size() &&
                     (static_cast<unsigned char>(input[i + 1]) & 0xC0) == 0x80)
            {
                result += input[i++];
                result += input[i++];
            }
            // 3 byte sequence
            else if ((c & 0xF0) == 0xE0 && i + 2 < input.size() &&
                     (static_cast<unsigned char>(input[i + 1]) & 0xC0) == 0x80 &&
                     (static_cast<unsigned char>(input[i + 2]) & 0xC0) == 0x80)
            {
                result += input[i++];
                result += input[i++];
                result += input[i++];
            }
            // 4 byte sequence
            else if ((c & 0xF8) == 0xF0 && i + 3 < input.size() &&
                     (static_cast<unsigned char>(input[i + 1]) & 0xC0) == 0x80 &&
                     (static_cast<unsigned char>(input[i + 2]) & 0xC0) == 0x80 &&
                     (static_cast<unsigned char>(input[i + 3]) & 0xC0) == 0x80)
            {
                result += input[i++];
                result += input[i++];
                result += input[i++];
                result += input[i++];
            }
            // Invalid byte — skip
            else
            {
                i++;
            }
        }
        return result;
    }

} // namespace corogram