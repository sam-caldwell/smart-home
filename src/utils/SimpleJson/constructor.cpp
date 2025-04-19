// SimpleJson/constructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of minimal JSON parser

#include "utils/SimpleJson/SimpleJson.h"

SimpleJson::SimpleJson(const std::string &json) {
    parse(json);
}
