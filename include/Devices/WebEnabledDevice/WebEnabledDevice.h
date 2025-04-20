// WebEnabledDevice.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: This is the base class for all devices driven by HTTP API

#ifndef WEB_ENABLED_DEVICE_H
#define WEB_ENABLED_DEVICE_H

#include "Logger/Logger.h"
#include "Devices/Device/Device.h"
#include "HttpClient/HttpClient.h"

class WebEnabledDevice: public Device {
public:
    WebEnabledDevice(Logger *log, const std::string &connstr);
    ~WebEnabledDevice();
protected:
    void getHealth();
    const std::string getRemoteState() override;
    void setRemoteState(const std::string &body);
private:
    HttpClient *http;

    const std::vector<std::string> headers = {
        "Content-Type: application/json",
    };
};

#endif //WEB_ENABLED_DEVICE_H
