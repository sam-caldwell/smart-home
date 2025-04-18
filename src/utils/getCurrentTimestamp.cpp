// getCurrentTimestamp.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: provides a timestamp string
// Changes: Initial version created for smart home automation project

#include "utils/getCurrentTimestamp.h"

std::string getCurrentTimestamp() {
    std::ostringstream oss;
    std::time_t t = std::time(nullptr);
    std::tm localTime = *std::localtime(&t);
    oss << "[" << std::put_time(&localTime, "%Y-%m-%d %H:%M:%S") << "]";
    return oss.str();
}
