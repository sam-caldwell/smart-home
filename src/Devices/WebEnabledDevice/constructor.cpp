// WebEnabledDevice/constructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: This is the base class for all devices driven by HTTP API

#include <Devices/WebEnabledDevice/WebEnabledDevice.h>

// Constructor
WebEnabledDevice::WebEnabledDevice(Logger* log, const std::string& connstr)
    : Device(log), http(new HttpClient(connstr)) {
    log->info("WebEnabledDevice initialized with: " + connstr);
}
