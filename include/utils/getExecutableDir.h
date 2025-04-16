// getExecutableDir.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Entry point for Smart Home Automation Controller
// Handles unhandled exceptions and delegates logic to CommandShell
// Dependencies: filesystem

#ifndef GET_EXECUTABLE_DIR_H
#define GET_EXECUTABLE_DIR_H

#include <filesystem>
#include <string>

/**
 * @brief Get the directory where the binary was launched from, based on argv[0].
 */
std::string getExecutableDir(const char* argv0);

#endif //GET_EXECUTABLE_DIR_H
