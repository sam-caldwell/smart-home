// Television/constructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Television Http API device class

#include "Devices/Controllers/Television/Television.h"

Television::Television(Logger *log, const std::string &connstr)
    : WebEnabledDevice(log, connstr),
      volumeState(0),
      channelState(1) {

    log->info("Television system is registered (" + connstr + ")");

    getDeviceState();

};
