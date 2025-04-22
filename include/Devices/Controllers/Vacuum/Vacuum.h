// Security.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Security Http API device class

#ifndef VACUUM_H
#define VACUUM_H
#include <sstream>
#include "utils/OnOff.h"
#include "utils/StringUtils.h"
#include "utils/SimpleJson/SimpleJson.h"
#include "Logger/Logger.h"
#include "ParserResult/ParserResult.h"
#include "Devices/WebEnabledDevice/WebEnabledDevice.h"

class Vacuum : public WebEnabledDevice {
public:
    explicit Vacuum(Logger *log, const std::string &connstr);

    ~Vacuum() override {
        /*noop*/
    };

    ParserResult sendCommand(std::vector<std::string> &args) override;

private:
    inline void start(const std::string &time) { runState.on(); };
    inline void stop(const std::string &time) { runState.off(); };

    ParserResult getDeviceState();

    ParserResult updateDeviceState();

    OnOff runState; //Arm|disarm state
};

#endif //VACUUM_H
