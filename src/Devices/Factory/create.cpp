// create.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of smart home DeviceFactory with endpoint-based construction

#include <Devices/Factory/DeviceFactory.h>

DevicePtr DeviceFactory::create(CommandType type, Logger* log, const std::string& endpoint) {

    switch (type) {

        case CommandType::Thermostat:
          return new Thermostat(log, endpoint);
        // Future:
        // case CommandType::Lights:
        //     return Lights(log, endpoint);

        default:
            log->error("Unsupported device type in DeviceFactory.");

        return nullptr;

    }

}
