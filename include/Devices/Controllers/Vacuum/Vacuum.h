// Security.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Security Http API device class
// Changes: Initial version created for smart home automation project

#ifndef VACUUM_H
#define VACUUM_H
#include "utils/ConnectionString.h"
#include "utils/Tokens.h"
#include <sstream>
#include "utils/OnOff.h"
#include "utils/StringUtils.h"
#include "utils/SimpleJson/SimpleJson.h"
#include "Logger/Logger.h"
#include "ParserResult/ParserResult.h"
#include "Devices/WebEnabledDevice/WebEnabledDevice.h"

class Vacuum : public WebEnabledDevice {
public:
    explicit Vacuum(Logger *log, const ConnectionString &connstr);

    ~Vacuum() override {
        /*noop*/
    };

    ParserResult sendCommand(Tokens &tokens) override;

private:
    inline void start() { runState.on(); };
    inline void stop() { runState.off(); };

    ParserResult getDeviceState();

    ParserResult updateDeviceState();

    OnOff runState; //Arm|disarm state
};

#endif //VACUUM_H
