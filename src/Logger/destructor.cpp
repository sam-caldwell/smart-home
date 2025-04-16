// Logger/destructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of the standard (non-templated) Logger class.

#include "Logger/Logger.h"

Logger::~Logger() {
    if (ownsStream && stream) {
        static_cast<std::ofstream*>(stream)->close();
        delete stream;
    }
}

