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

#endif //PARSER_RESULT_H
