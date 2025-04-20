// WebEnabledDevice/setRemoteState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: This is the base class for all devices driven by HTTP API

#include "Devices/WebEnabledDevice/WebEnabledDevice.h"

// HTTP POST to set/update device state
const bool WebEnabledDevice::setRemoteState(const std::string& body) {
    try {
        std::string response = http->post("/api/v1/state", body, headers);
        log->info("Set state ok. response: " + response);
        return true;
    } catch (const std::exception& e) {
        log->error("Set state failed. response: " + std::string(e.what()));
        return false;
    }
}
