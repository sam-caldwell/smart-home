// File: stringify.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: get port number from environment variables.
// Changes: Initial version created for smart home automation project
#include "utils/SimpleJson/SimpleJson.h"

const std::string SimpleJson::stringify() {
    std::ostringstream oss;
    oss << "{";

    bool first = true;
    for (const auto& [key, value] : data) {
        if (!first) oss << ",";
        oss << "\"" << key << "\":\"" << value << "\"";
        first = false;
    }

    oss << "}";
    return oss.str();
}
