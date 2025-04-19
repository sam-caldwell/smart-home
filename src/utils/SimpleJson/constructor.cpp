// SimpleJsonParser/constructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of minimal JSON parser

#include "SimpleJsonParser.h"

SimpleJsonParser::SimpleJsonParser(const std::string &json) {
    parse(json);
}
