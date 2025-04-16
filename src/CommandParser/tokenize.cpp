// tokenize.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Convert our input string to space-delimited tokens.

#include "CommandParser/tokenize.h"

static std::vector<std::string> tokenize(const std::string& input) {

    std::vector<std::string> tokens;

    std::istringstream stream(input);

    std::string token;

    while (stream >> token) {
        tokens.push_back(token);
    }

    return tokens;

}
