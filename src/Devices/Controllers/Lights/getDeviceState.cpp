// Lights/getDeviceState.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Lights Http API device class

#include "Devices/Controllers/Lights/Lights.h"

ParserResult Lights::getDeviceState(){
    log->info("Lights::getDeviceState()");
    try {
        const std::string json = getRemoteState();
        log->info("state: " + json);

        SimpleJson parser(json);

        lights->clear();

        for (const auto &[room, stateStr] : parser.getMap()) {
            log->info("Room: " + room + ", State: " + stateStr);
            try {
                (*lights)[room] = OnOff(stateStr);
            } catch (const std::exception &e) {
                log->error("Invalid state for room '" + room + "': " + e.what());
                return ParserResult::invalidArgument;
            }
        }

    } catch (const std::exception &e) {
        log->error("Lights::getDeviceState failed: " + std::string(e.what()));
        std::cout << "Error: Cannot talk to Lights device." << std::endl;
        return ParserResult::error;
    }

    return ParserResult::ok;
}
