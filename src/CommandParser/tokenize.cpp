// tokenize.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Convert our input string to space-delimited tokens.

#include "CommandParser/CommandParser.h"

Tokens CommandParser::tokenize(const RawCommandLine& input) {

    Tokens tokens;

    std::istringstream stream(input);

    Token current_token;

    // split tokens by whitespace and store them FIFO
    while (stream >> current_token) {
        tokens.push(current_token);
    }

    return tokens;

}
