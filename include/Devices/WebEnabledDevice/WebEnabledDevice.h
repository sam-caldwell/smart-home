// WebEnabledDevice.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: This is the base class for all devices driven by HTTP API
// Changes: Initial version created for smart home automation project

#ifndef WEB_ENABLED_DEVICE_H
#define WEB_ENABLED_DEVICE_H

#include "Logger/Logger.h"
#include "Devices/Device/Device.h"
#include "HttpClient/HttpClient.h"

class WebEnabledDevice: public Device {
public:
    WebEnabledDevice(Logger *log, const std::string &connstr);
    ~WebEnabledDevice() override;
protected:
    void getHealth() override;
    const std::string getRemoteState() override;
    const bool setRemoteState(const std::string &body) override;
private:
    HttpClient *http;

    const std::vector<std::string> headers = {
        "Content-Type: application/json",
    };
};

#endif //WEB_ENABLED_DEVICE_H
