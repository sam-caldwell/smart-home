// Logger/fatal.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of the standard (non-templated) Logger class.

#include <Logger/Logger.h>

void Logger::fatal(const std::string& msg, int exit_code) {
    (*stream) << getCurrentTimestamp() << " [FATAL] " << msg << std::endl;
    std::exit(exit_code);
}
