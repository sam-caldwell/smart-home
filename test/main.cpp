// test/main.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Program for end-to-end testing

#include <string>
#include <iostream>
#include "constants/exit_codes.h"
#include "utils/getExecutableDir.h"
#include "Logger/Logger.h"

int main(int, char *argv[]) {
    Logger log(getExecutableDir(argv[0]) + "/test.log");
    log.info("File logger initialized.");
    try {
      log.error("tests not implemented");
    } catch (const std::runtime_error &e) {
        log.fatal(e.what(), runtime_error);
    } catch (const std::exception &e) {
        log.fatal(e.what(), generic_error);
    } catch (...) {
        log.fatal("unknown error occurred ", unknown_error);
    }
}
