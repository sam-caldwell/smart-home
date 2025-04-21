// SimpleJson/parse.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of minimal JSON parser

#include "utils/SimpleJson/SimpleJson.h"
#include "utils/StringUtils.h"

void SimpleJson::parse(const std::string &jsonString) {
    const std::string json = trim(jsonString);
    const std::string trimmed = trim(json.substr(1, json.size() - 2)); // remove { and }

    std::stringstream ss(trimmed);
    std::string pair;
    while (std::getline(ss, pair, ',')) {
        size_t colon = pair.find(':');

        if (colon == std::string::npos)
            continue;

        std::string key = pair.substr(0, colon);

        std::string value = pair.substr(colon + 1);

        // Strip quotes and spaces
        key.erase(remove_if(key.begin(), key.end(), [](char c) { return c == '"' || isspace(c); }), key.end());

        value.erase(remove_if(value.begin(), value.end(), [](char c) { return c == '"' || isspace(c); }), value.end());

        data[key] = value;
    }
}
