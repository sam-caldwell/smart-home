// Lights/turnOff.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Lights Http API device class

#include "Devices/Controllers/Lights/Lights.h"

void Lights::turnOff(const std::string &name) {
    if(exists(name)) {
        lights->at(name).off();
        log->info("Turned off light: " + name);
    }else{
        log->error("Light '" + name + "' does not exist.");
    }
}
