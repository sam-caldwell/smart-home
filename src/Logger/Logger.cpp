// Logger.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of the standard (non-templated) Logger class.

#include "Logger/Logger.h"

Logger::Logger(std::ostream& output) : stream(&output), ownsStream(false) {}

Logger::Logger(const std::string& filename) {
    std::ofstream* fileStream = new std::ofstream(filename, std::ios::app);
    if (!fileStream->is_open()) {
        delete fileStream;
        throw std::runtime_error("Logger failed to open file: " + filename);
    }
    stream = fileStream;
    ownsStream = true;
}

Logger::~Logger() {
    if (ownsStream && stream) {
        static_cast<std::ofstream*>(stream)->close();
        delete stream;
    }
}

