// Logger/error.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of the standard (non-templated) Logger class.

#include "Logger/Logger.h"

void Logger::error(const std::string& msg) {
    (*stream) << getCurrentTimestamp() << " [ERROR] " << msg << std::endl;
}
