// tokenize.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Convert our input string to space-delimited tokens.

#include "CommandParser/CommandParser.h"

Tokens CommandParser::tokenize(const RawCommandLine& input) {

    Tokens tokens;

    // create a stream from our commandline input and make sure it's all lower-case (case insensitive)
    std::istringstream stream(to_lower(input));

    Token current_token;

    // split tokens by whitespace and store them FIFO
    while (stream >> current_token) {
        tokens.push(current_token);
    }

    return tokens;

}
