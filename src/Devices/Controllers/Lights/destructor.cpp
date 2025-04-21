// Lights/destructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Lights Http API device class

#include "Devices/Controllers/Lights/Lights.h"

Lights::~Lights() {
    delete lights;
    lights = nullptr;
};
