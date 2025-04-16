// main.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Entry point for Smart Home Automation Controller
// Handles unhandled exceptions and delegates logic to CommandShell
// Dependencies: CommandShell.h

#include <string>
#include <iostream>
#include "include/utils/exit_codes.h"
#include "include/utils/getExecutableDir.h"
#include "include/Logger/Logger.h"
#include "include/CommandShell/CommandShell.h"

int main(int, char *argv[]) {
    Logger log(getExecutableDir(argv[0]) + "/log.txt");
    log.info("File logger initialized.");
    try {
        CommandShell cli(&log);
        return cli.Run(); // return an exit code
    } catch (const std::runtime_error &e) {
        log.fatal(e.what(), runtime_error);
    } catch (const std::exception &e) {
        log.fatal(e.what(), generic_error);
    } catch (...) {
        log.fatal("unknown error occurred ", unknown_error);
    }
}
