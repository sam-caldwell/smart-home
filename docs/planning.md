# 🏠 Smart Home Automation Control System

---

## 📄 Project Overview

This C++ project simulates a **centralized command-line interface** for controlling multiple smart home devices via mocked REST APIs, including:

- Smart Thermostat
- Smart Television
- Smart Vacuum Robot
- Smart Lights
- Smart Security System

### 🧱 Architecture Overview

```
                          +----------------+
                          | Command Parser |
                          +-------+--------+
                                  |
                          +-------v--------+
                          | Device Manager |
                          +---+---+---+----+
                              |   |   | 
       +----------------------+   |   +---------------------+
       |                          |                         |
+------v-------+          +-------v-------+         +-------v--------+
| SmartDevice  |<---------| DerivedDevice |<--------| Thermostat     |
| (Base Class) |          +---------------+         +----------------+
| - id         |                                       + More derived
| - url        |                                         classes: TV,
| - health()   |                                         Vacuum, etc.
| - sendState()|    
+--------------+    
```

---

## 🧪 Test Plan

| Command / Input               | Expected Result                         |
|------------------------------|------------------------------------------|
| `thermostat set temp 70`     | Sends POST; updates device state        |
| `security arm`               | Arms system; reflected in `/state`      |
| `lights office on`           | Updates lights via POST request         |
| `vacuum schedule 1800`       | Vacuum mock receives scheduled command  |

Each mock service logs all state changes and health checks.

---

## 🖥️ Device Mock Services (Flask, Python3)
Because we do not have the actual hardware, we create the following simple services
in Python Flask to provide HTTP APIs to simulate the hardware.  These will be run as 
docker containers using `make mockery`.

| Device        | Port | Mock File            |
|---------------|------|----------------------|
| Thermostat    | 8000 | `mockThermostat.py`  |
| Television    | 8001 | `mockTelevision.py`  |
| Vacuum Robot  | 8002 | `mockVacuum.py`      |
| Lights        | 8003 | `mockLights.py`      |
| Security      | 8004 | `mockSecurity.py`    |

Run them with:

```bash
make mockery
```
Once `make mockery` completes, `docker ps` should show...
```text
 samcaldwell@mbp project % docker ps
CONTAINER ID   IMAGE                  COMMAND                  CREATED       STATUS       PORTS                      NAMES
6578e19c9fa3   mockvacuum:local       "python3 mockVacuum.…"   6 hours ago   Up 6 hours   127.0.0.1:8005->8000/tcp   mockvacuum
27825e99c51a   mockthermostat:local   "python3 mockThermos…"   6 hours ago   Up 6 hours   127.0.0.1:8004->8000/tcp   mockthermostat
1c18ed4021d8   mocktelevision:local   "python3 mockTelevis…"   6 hours ago   Up 6 hours   127.0.0.1:8003->8000/tcp   mocktelevision
beca67088293   mocksecurity:local     "python3 mockSecurit…"   6 hours ago   Up 6 hours   127.0.0.1:8002->8000/tcp   mocksecurity
49ecc9a6f709   mocklights:local       "python3 mockLights.…"   6 hours ago   Up 6 hours   127.0.0.1:8001->8000/tcp   mocklights
```
...with an HTTP endpoint available on http://127.0.0.1:800x for each mocked device.

---

## 🧠 OO Class Design

### Base Class: `SmartDevice`

```cpp
class SmartDevice {
protected:
    std::string id;
    std::string endpoint;

public:
    SmartDevice(const std::string& id, const std::string& url);
    virtual void sendState(const std::string& command) = 0;
    virtual void healthCheck() = 0;
    virtual ~SmartDevice() = default;
};
```

### Example Derived: `Thermostat`

```cpp
class Thermostat : public SmartDevice {
private:
    int dayTemp;
    int nightTemp;

public:
    Thermostat(const std::string& id, const std::string& url);
    void setTemperature(int temp);
    void sendState(const std::string& command) override;
    void healthCheck() override;
};
```

---

## 🧪 Logger Template Example

```cpp
template <typename T>
class Logger {
public:
    static void logEvent(const T& message) {
        std::cout << "[LOG]: " << message << std::endl;
    }
};
```

## HttpClient
We implement a simple Http client using `libcurl`:
```cpp
#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <string>

class HttpClient {
private:
    std::string url;

public:
    HttpClient(const std::string& endpoint);
    std::string get();
    std::string post(const std::string& body);
};

#endif // HTTP_CLIENT_H
```

## main() function
```cpp
#include <iostream>
#include "exit_codes.h"
#include "Logger.h"
#include "CommandShell.h"

int main() {
    Logger log("app.log");
    try {
        CommandShell cli(&log);

        if (int result = cli.Run() == success) {
            return 0;
        } else {
            return log.error("Error while executing command", result);
        }
    } catch (const std::exception& ex) {
        log << "exception detail: " << ex.what();
        return log.fatal("unhandled exception: ", generic_error);

    } catch (...) {
        return log.fatal("unknown error occurred ",unknown_error);
    }
}
```

---

## 📂 File Structure
This is an approximate file structure we will use (planned) though implementation may differ:
```
/project-root
│
├── src/
│   ├── main.cpp
│   ├── SmartDevice.h / .cpp
│   ├── Thermostat.h / .cpp
│   ├── Lights.h / .cpp
│   ├── Vacuum.h / .cpp
│   ├── Television.h / .cpp
│   ├── SecuritySystem.h / .cpp
│   ├── DeviceManager.h / .cpp
│   └── HttpClient.h / .cpp
│
├── mocks/
│   ├── mockThermostat.py
│   ├── mockTelevision.py
│   ├── mockVacuum.py
│   ├── mockLights.py
│   └── mockSecurity.py
│
├── Makefile
└── README.md
```

---

## 🚀 Compile Instructions

1. Execute `make build` to compile.
2. The program will be compiled, linked and stored as `build/program`
3. The program can be executed as `./build/program`.

---

## ✅ Requirements Checklist

- [x] Object-Oriented Design (done)
- [x] Polymorphism & Inheritance (done)
- [x] Templates (Logger) 
- [x] File I/O (see logger)
- [x] Pointer usage (planned)
- [x] Exception Handling (planned)
- [x] Modular Header/CPP split 
- [x] Device mocking via Flask
- [x] `make mockery` Flask launcher (works in current iteration)
- [x] Clean CLI interface

---

> *“If you could go ahead and finish this README… that’d be great.”* – Bill Lumbergh
