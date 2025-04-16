// WebEnabledDevices.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: This is the base class for all devices driven by HTTP API

#include "WebEnabledDevices.h"

// Constructor
WebEnabledDevices::WebEnabledDevices(Logger* log, const std::string& connstr)
    : Devices(log), http(new HttpClient(connstr)) {
  log->info("WebEnabledDevice initialized with: " + connstr);
}

// Destructor
WebEnabledDevices::~WebEnabledDevices() {
  delete http;
  http = nullptr;
  log->info("WebEnabledDevice destroyed.");
}

// HTTP GET to check the device API health
void WebEnabledDevices::getHealth() {
  try {
    std::string response = http->get("/api/v1/health");
    log->info("Health check response: " + response);
  } catch (const std::exception& e) {
    log->error("Health check failed: " + std::string(e.what()));
  }
}

// HTTP GET to retrieve the device state
void WebEnabledDevices::getState() {
  try {
    std::string response = http->get("/api/v1/state");
    log->info("State response: " + response);
  } catch (const std::exception& e) {
    log->error("Get state failed: " + std::string(e.what()));
  }
}

// HTTP POST to set/update device state
void WebEnabledDevices::setState(const std::string& body) {
  try {
    std::string response = http->post("/api/v1/state", body, headers);
    log->info("Set state response: " + response);
  } catch (const std::exception& e) {
    log->error("Set state failed: " + std::string(e.what()));
  }
}
