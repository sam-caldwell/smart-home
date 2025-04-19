# Smart Home Automation Control System

A lightweight, extensible smart home automation platform driven by a command-line interface. No unnecessary GUIs—just efficient, scriptable control over your smart devices using REST APIs.

---

## Features

- **Command-Line Interface**  
  Who needs another web UI? Take full control directly from the terminal.

- **HTTP API Integration**  
  Leverages `libcurl` to interface with smart devices via REST endpoints.

- **Easily Extensible**  
  Add new devices by subclassing—minimal boilerplate required.

- **Speech-to-Command Ready**  
  Designed with future integration paths for voice control systems.

---

## Build Instructions

> Builds the CLI and launches Docker-based mock devices.

```bash
make clean build
```

## Run the Application
```bash
make run
```

## Dependencies
* C++20-compatible compiler (clang++, g++)
* libcurl (preinstalled on macOS via Xcode)
* Docker (for running mock device APIs)
* CMake 3.27+
