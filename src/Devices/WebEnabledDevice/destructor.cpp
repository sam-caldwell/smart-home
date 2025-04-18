// WebEnabledDevice/destructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: This is the base class for all devices driven by HTTP API

#include <Devices/WebEnabledDevice/WebEnabledDevice.h>

// Destructor
WebEnabledDevice::~WebEnabledDevice() {
    delete http;
    http = nullptr;
}
