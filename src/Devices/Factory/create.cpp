// create.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of smart home DeviceFactory with endpoint-based construction

#include "Devices/Factory/DeviceFactory.h"
#include "Devices/Controllers/Lights/Lights.h"
#include "Devices/Controllers/Television/Television.h"
#include "Devices/Controllers/Security/Security.h"
#include "Devices/Controllers/Thermostat/Thermostat.h"
#include "Devices/Controllers/Vacuum/Vacuum.h"

DevicePtr DeviceFactory::create(CommandType type, Logger* log, const std::string& endpoint) {

    switch (type) {
        case CommandType::Lights:
            return new class Lights(log, endpoint);
        case CommandType::Television:
            return new class Television(log, endpoint);
        case CommandType::Thermostat:
          return new class Thermostat(log, endpoint);
        case CommandType::Security:
          return new class Security(log, endpoint);
        case CommandType::Vacuum:
            return new class Vacuum(log, endpoint);
        default:
            log->error("Unsupported device type in DeviceFactory.");

        return nullptr;

    }

}
