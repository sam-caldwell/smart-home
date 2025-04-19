// SimpleJsonParser/getString.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of minimal JSON parser

#include "SimpleJsonParser.h"

std::string SimpleJsonParser::getString(const std::string &key) const {

    auto it = data.find(key);

    if (it == data.end())
      throw std::runtime_error("Key not found: " + key);

    return it->second;

}
