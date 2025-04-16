// Logger.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Stream-based logger (not templated) for console or file output.
// Dependencies: <iostream>, <fstream>, <string>

#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include "getCurrentTimestamp.h"

class Logger {
private:
    std::ostream* stream;
    bool ownsStream;

public:
    Logger(std::ostream& output);                // For std::cout, std::cerr, etc.
    Logger(const std::string& filename);         // For file-based logging
    ~Logger();                                   // Cleanup if we opened the file

    void info(const std::string& msg);
    void error(const std::string& msg);
    void fatal(const std::string& msg, int exit_code);

    // Disallow copy
    Logger(const Logger&) = delete;
    Logger& operator=(const Logger&) = delete;
};

#endif // LOGGER_H
