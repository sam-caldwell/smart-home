// Thermostat.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Thermostat Http API device class

#ifndef THERMOSTAT_H
#define THERMOSTAT_H
#include <sstream>
#include "utils/OnOff.h"
#include "utils/StringUtils.h"
#include "utils/SimpleJson/SimpleJson.h"
#include "Logger/Logger.h"
#include "ParserResult/ParserResult.h"
#include "Devices/Controllers/Thermostat/ThermostatMode.h"
#include "Devices/WebEnabledDevice/WebEnabledDevice.h"

class Thermostat: public WebEnabledDevice {
public:
    explicit Thermostat(Logger* log, const std::string& connstr);

    ParserResult sendCommand(std::vector<std::string> &args) override;
private:
    void setTemp(const std::string &temp);
    unsigned short getTemp() const;
    void fanOn();
    void fanOff();
    void heat();
    void cool();

    ParserResult getDeviceState();
    ParserResult updateDeviceState();

    OnOff fanState;
    unsigned short temperature;
    ThermostatMode modeState;
};

#endif //THERMOSTAT_H
