// WebEnabledDevices/getState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: This is the base class for all devices driven by HTTP API

#include "Devices/WebEnabledDevices/WebEnabledDevices.h"

// HTTP GET to retrieve the device state
void WebEnabledDevices::getState() {
    try {
        std::string response = http->get("/api/v1/state");
        log->info("State response: " + response);
    } catch (const std::exception& e) {
        log->error("Get state failed: " + std::string(e.what()));
    }
}
