// Thermostat.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Thermostat Http API device class

#ifndef THERMOSTAT_H
#define THERMOSTAT_H

#include "WebEnabledDevices.h"
#include "Logger.h"
#include "ParserResult.h"
#include "ThermostatMode.h"
#include <memory>
#include <sstream>

class Thermostat: public WebEnabledDevices {
public:
    explicit Thermostat(Logger* log, const std::string& connstr);

    ParserResult sendCommand(std::vector<std::string> &args);
private:
    void setTemp(std::string &temp);
    unsigned short getTemp() const;
    void fanOn();
    void fanOff();
    void heat();
    void cool();

    ParserResult getDeviceState();
    ParserResult updateDeviceState();

    bool fanState;
    unsigned short temperature;
    ThermostatMode modeState;
};

#endif //THERMOSTAT_H
