// tokenize.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Convert our input string to space-delimited tokens.

#include "CommandParser/CommandParser.h"

TokenList CommandParser::tokenize(const std::string& input) {

    std::vector<std::string> tokens;

    std::istringstream stream(input);

    std::string token;

    while (stream >> token) {
        tokens.push_back(token);
    }

    return tokens;

}
