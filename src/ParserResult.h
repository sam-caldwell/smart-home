// ParserResult.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Represents CommandParser outcomes
// Dependencies: none

#ifndef PARSER_RESULT_H
#define PARSER_RESULT_H

enum ParserResult {
  emptyCommand,
  exitCommand,
  badCommand,
  helpCommand,
  missingArgument,
  invalidArgument,
  error,
  ok
};

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

#endif //PARSER_RESULT_H