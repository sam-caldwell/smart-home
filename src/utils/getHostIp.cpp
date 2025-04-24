// File: utils/getHostIp.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: get port number from environment variables.
// Changes: Initial version created for smart home automation project

#include "utils/getHostIp.h"

const std::string getHostIp() {
    const char* myIpEnv = std::getenv("HOST_IP");
    if (!myIpEnv) {
        throw std::runtime_error("Environment variable 'HOST_IP' is not set.");
    }
    return std::string(myIpEnv);
}
