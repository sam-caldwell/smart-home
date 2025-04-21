// Lights/exists.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Lights Http API device class

#include "Devices/Controllers/Lights/Lights.h"

// return true if the named light exists.
bool Lights::exists(const std::string &name) {
    try {
        return lights->find(name) != lights->end();
    } catch (const std::out_of_range &e) {
        return false;
    }
}
