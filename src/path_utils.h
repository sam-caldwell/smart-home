// path_utils.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Entry point for Smart Home Automation Controller
// Handles unhandled exceptions and delegates logic to CommandShell
// Dependencies: filesystem

#ifndef PATH_UTILS_H
#define PATH_UTILS_H

#include <filesystem>
#include <string>

/**
 * @brief Get the directory where the binary was launched from, based on argv[0].
 */
inline std::string getExecutableDir(const char* argv0) {
    std::filesystem::path absPath = std::filesystem::absolute(argv0);
    return absPath.parent_path().string();
}

#endif //PATH_UTILS_H