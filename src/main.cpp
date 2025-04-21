// main.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Entry point for Smart Home Automation Controller
// Handles unhandled exceptions and delegates logic to CommandShell
// Dependencies: CommandShell.h

#include <string>
#include <iostream>
#include "constants/exit_codes.h"
#include "utils/getExecutableDir.h"
#include "Logger/Logger.h"
#include "CommandShell/CommandShell.h"

int main(int, char *argv[]) {
    std::cout << "Starting..." << std::endl;
    Logger log(getExecutableDir(argv[0]) + "/smart-home.log");
    log.info("File logger initialized.");
    try {
        log.info("Starting shell");
        CommandShell cli(&log);
        log.info("Command shell initialized. Launching...");
        return cli.Run(); // return an exit code
    } catch (const std::runtime_error &e) {
        std::cout << e.what() << std::endl;
        log.fatal(e.what(), runtime_error);
    } catch (const std::exception &e) {
        std::cout << "an unhandled error occurred.  Check the logs." << std::endl;
        log.fatal(e.what(), generic_error);
        return generic_error;
    } catch (...) {
        std::cout << "an unknown error occurred.  Check the logs." << std::endl;
        log.fatal("unknown error occurred ", unknown_error);
        return unknown_error;
    }
}
