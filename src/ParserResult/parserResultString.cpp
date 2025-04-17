// parserResultString.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: stringify ParserResult
// Dependencies: none

#include <ParserResult/ParserResult.h>


const char* string(ParserResult r) const {
    switch (value) {
        case emptyCommand:     return "emptyCommand";
        case exitCommand:      return "exitCommand";
        case badCommand:       return "badCommand";
        case helpCommand:      return "helpCommand";
        case missingArgument:  return "missingArgument";
        case invalidArgument:  return "invalidArgument";
        case error:            return "error";
        case ok:               return "ok";
        default:               return "unknown";
    }
}
