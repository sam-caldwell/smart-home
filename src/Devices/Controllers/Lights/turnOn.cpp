// Lights/turnOn.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Lights Http API device class

#include "Devices/Controllers/Lights/Lights.h"

void Lights::turnOn(const std::string &name) {
    if(exists(name)) {
        lights->at(name).on();
        log->info("Turned on light: " + name);
    }else{
        log->error("Light '" + name + "' does not exist.");
    }
}
