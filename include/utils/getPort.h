// File: utils/getPort.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Utility function to retrieve port by environment variable

#ifndef GET_PORT_H
#define GET_PORT_H

#include <cstdlib>
#include <stdexcept>
#include <string>
#include "utils/StringUtils.h"

const std::string getPort(const std::string &name);

#endif // GET_PORT_H
