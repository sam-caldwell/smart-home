// Television/volume.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Television Http API device class

#include "Devices/Controllers/Television/Television.h"

void Television::volume(const std::string &v) {
    try {
        unsigned short n = atoi(v.c_str());
        if (n < 99) {
            volumeState = n;
        } else {
            log->error("Volume out of range.");
            std::cout << "Volume out of range. ";
            return;
        }
    } catch (...) {
        log->error("Volume must be number 1-99");
        std::cout << "Volume must be number 1-99";
    }
};
