// parserResultString.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: stringify ParserResult
// Dependencies: none

#include <ParserResult/ParserResult.h>

inline const char* parserResultString(ParserResult r) {
    switch (r) {
        case ParserResult::emptyCommand: return "emptyCommand";
        case ParserResult::exitCommand: return "exitCommand";
        case ParserResult::badCommand: return "badCommand";
        case ParserResult::missingArgument: return "missingArgument";
        case ParserResult::ok: return "ok";
        default: return "unknown";
    }
}
