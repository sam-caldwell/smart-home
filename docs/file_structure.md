/Users/samcaldwell/git/cpp/smart-home
├── CMakeLists.txt
├── Dockerfile
├── LICENSE.txt
├── Makefile
├── README.md
├── cmake
│   ├── Builder.cmake
│   ├── GenerateFileTree.cmake
│   ├── GetHostIP.cmake
│   ├── Mockery.cmake
│   ├── PrintHostIP.cmake
│   ├── Tester.cmake
│   ├── ZipSubmission.cmake
│   ├── include_directories.cmake
│   ├── linkCurl.cmake
│   ├── targetMain.cmake
│   └── targetTest.cmake
├── docs
│   ├── file_structure.md
│   └── planning.md
├── include
│   ├── CommandParser
│   │   └── CommandParser.h
│   ├── CommandShell
│   │   └── CommandShell.h
│   ├── CommandType
│   │   └── CommandType.h
│   ├── Devices
│   │   ├── Controllers
│   │   │   ├── Lights
│   │   │   │   └── Lights.h
│   │   │   ├── Security
│   │   │   │   └── Security.h
│   │   │   ├── Television
│   │   │   │   └── Television.h
│   │   │   ├── Thermostat
│   │   │   │   ├── Thermostat.h
│   │   │   │   └── ThermostatMode.h
│   │   │   └── Vacuum
│   │   │       └── Vacuum.h
│   │   ├── Device
│   │   │   └── Device.h
│   │   ├── Factory
│   │   │   └── DeviceFactory.h
│   │   └── WebEnabledDevice
│   │       └── WebEnabledDevice.h
│   ├── Help
│   │   └── Help.h
│   ├── HttpClient
│   │   └── HttpClient.h
│   ├── Logger
│   │   └── Logger.h
│   ├── ParserResult
│   │   └── ParserResult.h
│   ├── constants
│   │   └── exit_codes.h
│   └── utils
│       ├── ConnectionString.h
│       ├── OnOff.h
│       ├── RawCommandLine.h
│       ├── SimpleJson
│       │   └── SimpleJson.h
│       ├── StringUtils.h
│       ├── Tokens.h
│       ├── getCurrentTimestamp.h
│       ├── getExecutableDir.h
│       ├── getHostIp.h
│       └── getPort.h
├── mocks
│   ├── Dockerfile
│   ├── mockLights.py
│   ├── mockSecurity.py
│   ├── mockTelevision.py
│   ├── mockThermostat.py
│   ├── mockVacuum.py
│   └── requirements.txt
├── scripts
│   ├── check_vtable.py
│   └── graph_includes.py
└── src
    ├── CommandParser
    │   ├── constructor.cpp
    │   ├── destructor.cpp
    │   ├── invoke_device.cpp
    │   ├── parse.cpp
    │   └── tokenize.cpp
    ├── CommandShell
    │   ├── Run.cpp
    │   ├── constructor.cpp
    │   ├── destructor.cpp
    │   └── displayWelcome.cpp
    ├── CommandType
    │   ├── identifyCommand.cpp
    │   └── to_string.cpp
    ├── Devices
    │   ├── Controllers
    │   │   ├── Lights
    │   │   │   ├── constructor.cpp
    │   │   │   ├── destructor.cpp
    │   │   │   ├── exists.cpp
    │   │   │   ├── getDeviceState.cpp
    │   │   │   ├── sendCommand.cpp
    │   │   │   ├── turnOff.cpp
    │   │   │   ├── turnOn.cpp
    │   │   │   └── updateDeviceState.cpp
    │   │   ├── Security
    │   │   │   ├── constructor.cpp
    │   │   │   ├── getDeviceState.cpp
    │   │   │   ├── sendCommand.cpp
    │   │   │   └── updateDeviceState.cpp
    │   │   ├── Television
    │   │   │   ├── channel.cpp
    │   │   │   ├── constructor.cpp
    │   │   │   ├── getDeviceState.cpp
    │   │   │   ├── sendCommand.cpp
    │   │   │   ├── updateDeviceState.cpp
    │   │   │   └── volume.cpp
    │   │   ├── Thermostat
    │   │   │   ├── ThermostatMode.cpp
    │   │   │   ├── constructor.cpp
    │   │   │   ├── cool.cpp
    │   │   │   ├── fanOff.cpp
    │   │   │   ├── fanOn.cpp
    │   │   │   ├── getDeviceState.cpp
    │   │   │   ├── getTemp.cpp
    │   │   │   ├── heat.cpp
    │   │   │   ├── sendCommand.cpp
    │   │   │   ├── setTemp.cpp
    │   │   │   └── updateDeviceState.cpp
    │   │   └── Vacuum
    │   │       ├── constructor.cpp
    │   │       ├── getDeviceState.cpp
    │   │       ├── sendCommand.cpp
    │   │       └── updateDeviceState.cpp
    │   ├── Device
    │   │   ├── constructor.cpp
    │   │   ├── getHealth.cpp
    │   │   ├── getRemoteState.cpp
    │   │   ├── sendCommand.cpp
    │   │   └── setRemoteState.cpp
    │   ├── Factory
    │   │   └── create.cpp
    │   └── WebEnabledDevice
    │       ├── constructor.cpp
    │       ├── destructor.cpp
    │       ├── getHealth.cpp
    │       ├── getRemoteState.cpp
    │       └── setRemoteState.cpp
    ├── Help
    │   ├── getSmartRemark.cpp
    │   └── showHelp.cpp
    ├── HttpClient
    │   ├── constructor.cpp
    │   ├── destructor.cpp
    │   ├── get.cpp
    │   └── post.cpp
    ├── Logger
    │   ├── constructor.cpp
    │   ├── destructor.cpp
    │   ├── error.cpp
    │   ├── fatal.cpp
    │   └── info.cpp
    ├── ParserResult
    │   └── to_string.cpp
    ├── main.cpp
    └── utils
        ├── OnOff.cpp
        ├── SimpleJson
        │   ├── constructor.cpp
        │   ├── getInt.cpp
        │   ├── getString.cpp
        │   ├── parse.cpp
        │   └── stringify.cpp
        ├── Tokens.cpp
        ├── getCurrentTimestamp.cpp
        ├── getExecutableDir.cpp
        ├── getHostIp.cpp
        ├── getPort.cpp
        ├── to_lower.cpp
        ├── to_upper.cpp
        └── trim.cpp

46 directories, 136 files
