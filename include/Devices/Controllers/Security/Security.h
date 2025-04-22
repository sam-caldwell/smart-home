// Security.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Security Http API device class

#ifndef SECURITY_DEVICE_H
#define SECURITY_DEVICE_H
#include "utils/ConnectionString.h"
#include "utils/Tokens.h"
#include <sstream>
#include "utils/OnOff.h"
#include "utils/StringUtils.h"
#include "utils/SimpleJson/SimpleJson.h"
#include "Logger/Logger.h"
#include "ParserResult/ParserResult.h"
#include "Devices/WebEnabledDevice/WebEnabledDevice.h"

class Security: public WebEnabledDevice {
public:
    explicit Security(Logger* log, const ConnectionString& connstr);
    ~Security() override {};
    ParserResult sendCommand(Tokens &args) override;
private:
    inline void arm(){armedState.on();}
    inline void disarm(){armedState.off();}

    ParserResult getDeviceState();
    ParserResult updateDeviceState();

    OnOff armedState; //Arm|disarm state
};

#endif //SECURITY_DEVICE_H
