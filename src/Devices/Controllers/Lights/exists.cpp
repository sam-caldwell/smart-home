// Lights/exists.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Lights Http API device class

#include "Devices/Controllers/Lights/Lights.h"

// return true if the named light exists.
bool Lights::exists(const std::string &name) {
    return lights->find(name) != lights->end();
}
