// toLower.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>

#include <utils/StringUtils.h>

// Utility to convert a string to lowercase
std::string toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}
