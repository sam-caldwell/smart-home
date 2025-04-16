// Logger/info.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of the standard (non-templated) Logger class.

#include "Logger/Logger.h"

void Logger::info(const std::string& msg) {
    (*stream) << getCurrentTimestamp() << " [INFO] " << msg << std::endl;
}
