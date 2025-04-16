// DeviceMap.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Typedef for mapping CommandType to device instances
// Dependencies: CommandType, Devices, <memory>, <unordered_map>

#ifndef DEVICE_MAP_H
#define DEVICE_MAP_H

#include <memory>
#include <unordered_map>
#include "CommandType/CommandType.h"
#include "Devices/Base/Devices.h"

// Alias for mapping commands to smart device instances
using DeviceMap = std::unordered_map<CommandType, DevicePtr>;

#endif //DEVICE_MAP_H
