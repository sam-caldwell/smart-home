// SimpleJson/getInt.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of minimal JSON parser

#include "utils/SimpleJson/SimpleJson.h"

int SimpleJson::getInt(const std::string &key) const {

    auto it = data.find(key);

    if (it == data.end())
        throw std::runtime_error("Key not found: " + key);

    return std::stoi(it->second);
}
