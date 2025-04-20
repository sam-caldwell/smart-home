// Security/constructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Security Http API device class

#include "Devices/Controllers/Security/Security.h"

Security::Security(Logger *log, const std::string &connstr)
    : WebEnabledDevice(log, connstr),
      state() {
    log->info("Security system is registered (" + connstr + ")");
    getDeviceState();
};
