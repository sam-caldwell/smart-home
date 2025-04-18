// getExecutableDir.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Entry point for Smart Home Automation Controller
// Handles unhandled exceptions and delegates logic to CommandShell
// Dependencies: filesystem

#include "utils/getExecutableDir.h"

std::string getExecutableDir(const char* argv0) {

    std::filesystem::path absPath = std::filesystem::absolute(argv0);

    return absPath.parent_path().string();

}
