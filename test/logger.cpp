// test/logger.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Unit test for the Logger class (console and file-based)
// Dependencies: Logger.h, standard I/O

#include "../src/Logger.h"
#include <iostream>

int main() {
    std::cout << "==== Testing Logger (Console) ====" << std::endl;

    Logger consoleLogger(std::cout);
    consoleLogger.log("Console logger initialized.");
    consoleLogger.error("This is a test error message.");
    // Commented to avoid premature exit:
    // consoleLogger.fatal("Testing fatal exit.", 1);

    std::cout << "==== Testing Logger (File: test_log.txt) ====" << std::endl;

    try {
        Logger fileLogger("build/test_log.txt");
        fileLogger.log("File logger initialized.");
        fileLogger.error("Simulated error to file.");
        // Uncomment to test fatal:
        // fileLogger.fatal("Fatal logged to file", 2);
    } catch (const std::exception& e) {
        std::cerr << "Logger failed: " << e.what() << std::endl;
        return 1;
    }

    std::cout << "==== Logger tests complete. Check test_log.txt ====" << std::endl;
    return 0;
}
