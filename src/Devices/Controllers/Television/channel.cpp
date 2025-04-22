// Television/channel.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description:  Television Http API device class

#include "Devices/Controllers/Television/Television.h"

void Television::channel(const std::string &v) {
    if (v=="fox") {
        std::cout << "I thought you were smarter.  By a different television.  This one prefers facts." << std::endl;
        return;
    }
    try {
        unsigned short n = atoi(v.c_str());

        if (n < 99) {
            channelState = n;
        } else {
            log->error("Channel out of range.");
            std::cout << "Channel out of range. ";
            return;
        }
    } catch (...) {
        log->error("Channel must be number 1-99");
        std::cout << "Channel must be number 1-99";
    }
};
