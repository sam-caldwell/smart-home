// Logger.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of the standard (non-templated) Logger class.

#include "Logger.h"
#include <cstdlib>

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


void Logger::info(const std::string& msg) {
    (*stream) << getCurrentTimestamp() << " [INFO] " << msg << std::endl;
}

void Logger::error(const std::string& msg) {
    (*stream) << getCurrentTimestamp() << " [ERROR] " << msg << std::endl;
}

void Logger::fatal(const std::string& msg, int exit_code) {
    (*stream) << getCurrentTimestamp() << " [FATAL] " << msg << std::endl;
    std::exit(exit_code);
}
