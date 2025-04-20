
#include "utils/getPort.h"

const std::string getPort(const std::string &name) {
    try {
        const std::string envVarName = "PORT_" + to_upper(name);
        const char* value = std::getenv(envVarName.c_str());
        if (!value) {
            throw std::runtime_error("Environment variable not set: " + envVarName);
        }
        return std::string(value);
    } catch (...) {
        throw std::runtime_error("getPort error loading: " + name);
    }
}
