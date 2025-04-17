// WebEnabledDevices/destructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: This is the base class for all devices driven by HTTP API

#include <Devices/WebEnabledDevices/WebEnabledDevices.h>

// Destructor
WebEnabledDevices::~WebEnabledDevices() {
    delete http;
    http = nullptr;
    log->info("WebEnabledDevice destroyed.");
}
