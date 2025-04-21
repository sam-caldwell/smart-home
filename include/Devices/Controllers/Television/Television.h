// Television.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Television Http API device class

#ifndef TELEVISION_DEVICE_H
#define TELEVISION_DEVICE_H
#include <sstream>
#include "utils/OnOff.h"
#include "utils/StringUtils.h"
#include "utils/SimpleJson/SimpleJson.h"
#include "Logger/Logger.h"
#include "ParserResult/ParserResult.h"
#include "Devices/WebEnabledDevice/WebEnabledDevice.h"

class Television : public WebEnabledDevice {
public:
    explicit Television(Logger *log, const std::string &connstr);

    ~Television() override {
    };

    ParserResult sendCommand(std::vector<std::string> &args) override;

private:
    inline void on() { powerState.on(); }
    inline void disarm() { powerState.off(); }
    inline void volume(const unsigned short v) { volumeState = v; };
    inline void channel(const unsigned short v) { channelState = v; };

    ParserResult getDeviceState();

    ParserResult updateDeviceState();

    OnOff powerState;
    unsigned short volumeState;
    unsigned short channelState;
};

#endif //TELEVISION_DEVICE_H
