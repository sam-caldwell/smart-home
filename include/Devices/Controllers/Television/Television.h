// Television.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Television Http API device class

#ifndef TELEVISION_DEVICE_H
#define TELEVISION_DEVICE_H
#include "utils/ConnectionString.h"
#include "utils/Tokens.h"
#include <sstream>
#include "utils/OnOff.h"
#include "utils/StringUtils.h"
#include "utils/SimpleJson/SimpleJson.h"
#include "Logger/Logger.h"
#include "ParserResult/ParserResult.h"
#include "Devices/WebEnabledDevice/WebEnabledDevice.h"

class Television : public WebEnabledDevice {
public:
    explicit Television(Logger *log, const ConnectionString &connstr);

    ~Television() override {
        /*noop*/
    };

    ParserResult sendCommand(Tokens &args) override;

private:
    inline void on() { powerState.on(); }
    inline void off() { powerState.off(); }

    void volume(const std::string &v);

    void channel(const std::string &v);

    ParserResult getDeviceState();

    ParserResult updateDeviceState();

    OnOff powerState;
    unsigned short channelState;
    unsigned short volumeState;
};

#endif //TELEVISION_DEVICE_H
