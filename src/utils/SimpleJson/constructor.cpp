// SimpleJson/constructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of minimal JSON parser

#include "utils/SimpleJson/SimpleJson.h"

SimpleJson::SimpleJson(const std::string &json) {
    parse(json);
}

SimpleJson::SimpleJson(const std::unordered_map<std::string, OnOff> &map) {
    data.clear();
    for (const auto &[key, value] : map) {
        data[key] = value.string(); // Convert OnOff to string ("on"/"off")
    }
}
