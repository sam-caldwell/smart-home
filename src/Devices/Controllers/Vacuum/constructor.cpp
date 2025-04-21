// Vacuum/constructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Vacuum Http API device class

#include "Devices/Controllers/Vacuum/Vacuum.h"

Vacuum::Vacuum(Logger *log, const std::string &connstr)
    : WebEnabledDevice(log, connstr),
      runState() {

    log->info("Vacuum system is registered (" + connstr + ")");

    getDeviceState();

};
