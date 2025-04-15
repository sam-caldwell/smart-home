// StringUtils.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Simple utilities to deal with string stuff.
// Dependencies:string, algorithm, cctype
// Changes: Initial version created for smart home automation project

#ifndef STRING_UTILS_H
#define STRING_UTILS_H

#include <string>
#include <algorithm>
#include <cctype>

// Utility to trim whitespace from both ends
inline std::string trim(const std::string& str) {
    auto start = str.begin();
    while (start != str.end() && std::isspace(*start)) start++;

    auto end = str.end();
    do {
        --end;
    } while (std::distance(start, end) > 0 && std::isspace(*end));

    return std::string(start, end + 1);
}

// Utility to convert a string to lowercase
inline std::string toLower(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return result;
}

#endif // STRING_UTILS_H
