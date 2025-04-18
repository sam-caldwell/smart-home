// ParserResult.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Represents CommandParser outcomes
// Dependencies: none

#ifndef PARSER_RESULT_H
#define PARSER_RESULT_H

#include <string>

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

const std::string to_string(ParserResult r);

#endif //PARSER_RESULT_H
