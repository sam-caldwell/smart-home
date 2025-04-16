// WebEnabledDevices.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: This is the base class for all devices driven by HTTP API

#ifndef WEB_ENABLED_DEVICES_H
#define WEB_ENABLED_DEVICES_H

#include "Logger/Logger.h"
#include "Devices/Base/Devices.h"
#include "HttpClient/HttpClient.h"

class WebEnabledDevices: public Devices {
public:
    WebEnabledDevices(Logger *log, const std::string &connstr);
    ~WebEnabledDevices();
    virtual ParserResult sendCommand(std::vector<std::string> &args);
protected:
    void getHealth();
    void getState();
    void setState(const std::string &body);
private:
    HttpClient *http;

    const std::vector<std::string> headers = {
        "Content-Type: application/json",
    };
};

#endif //WEB_ENABLED_DEVICES_H
