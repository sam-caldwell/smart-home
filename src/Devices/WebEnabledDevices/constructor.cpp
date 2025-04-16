// WebEnabledDevices/constructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: This is the base class for all devices driven by HTTP API

#include "Devices/WebEnabledDevices/WebEnabledDevices.h"

// Constructor
WebEnabledDevices::WebEnabledDevices(Logger* log, const std::string& connstr)
    : Devices(log), http(new HttpClient(connstr)) {
    log->info("WebEnabledDevice initialized with: " + connstr);
}
