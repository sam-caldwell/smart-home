// to_upper.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>

#include "utils/StringUtils.h"

// Utility to convert a string to uppercase
std::string to_upper(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::toupper(c); });
    return result;
}
