// Devices/Controller/Lights.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Lights Http API device class

#ifndef LIGHTS_DEVICE_H
#define LIGHTS_DEVICE_H
#include <sstream>
#include <unordered_map>
#include "utils/OnOff.h"
#include "utils/StringUtils.h"
#include "utils/SimpleJson/SimpleJson.h"
#include "Logger/Logger.h"
#include "ParserResult/ParserResult.h"
#include "Devices/WebEnabledDevice/WebEnabledDevice.h"

class Lights: public WebEnabledDevice {
public:
    explicit Lights(Logger* log, const std::string& connstr);
    ~Lights() override;
    ParserResult sendCommand(std::vector<std::string> &args) override;
private:
    bool exists(const std::string &room);
    void turnOn(const std::string &room);
    void turnOff(const std::string &room);

    ParserResult getDeviceState();
    ParserResult updateDeviceState();

    using LightMap = std::unordered_map<std::string, OnOff>;

    LightMap *lights;
};

#endif //LIGHTS_DEVICE_H
