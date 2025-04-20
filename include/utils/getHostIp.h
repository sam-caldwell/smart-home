// File: utils/getHostIp.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Utility function to retrieve HOST_IP from environment

#ifndef GET_HOST_IP_H
#define GET_HOST_IP_H

#include <cstdlib>   // std::getenv
#include <stdexcept> // std::runtime_error
#include <string>

const std::string getHostIp();

#endif // GET_HOST_IP_H
