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
std::string trim(const std::string& str);

// Utility to convert a string to lowercase
std::string to_lower(const std::string& str);

#endif // STRING_UTILS_H
