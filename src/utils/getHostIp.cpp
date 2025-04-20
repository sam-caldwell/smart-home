// File: utils/getHostIp.cpp

#include "utils/getHostIp.h"

const std::string getHostIp() {
    const char* myIpEnv = std::getenv("HOST_IP");
    if (!myIpEnv) {
        throw std::runtime_error("Environment variable 'HOST_IP' is not set.");
    }
    return std::string(myIpEnv);
}
