// WebEnabledDevice/getHealth.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: This is the base class for all devices driven by HTTP API

#include <Devices/WebEnabledDevice/WebEnabledDevice.h>

// HTTP GET to check the device API health
void WebEnabledDevice::getHealth() {
    try {
        std::string response = http->get("/api/v1/health");
        log->info("Health check response: " + response);
    } catch (const std::exception& e) {
        log->error("Health check failed: " + std::string(e.what()));
    }
}
