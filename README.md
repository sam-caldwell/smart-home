# 🏠 Smart Home Automation Control System
=========================================

A simple smart home automation system.

## Features:

1. It is a CLI because who needs yet another web interface?
2. It uses `libcurl` to call external APIs to control devices.
3. It is extensible. You can add more devices.
4. Technically this should mean the path to speech-to-command should be easier.

## Usage

### To build:

```shell
make clean build
```

(Note: this will also start the docker containers for
the mock API endpoints to simulate devices....needs work.)

### To Run

```shell
make run
```
