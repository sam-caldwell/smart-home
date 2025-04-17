// HttpClient/get.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of HttpClient using libcurl

#include <HttpClient/HttpClient.h>

std::string HttpClient::get(const std::string& endpoint) {
    CURL* curl = curl_easy_init();
    if (!curl) throw std::runtime_error("Failed to initialize CURL");

    std::string response;
    std::string url = baseUrl + endpoint;

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK)
        throw std::runtime_error("GET request failed: " + std::string(curl_easy_strerror(res)));

    curl_easy_cleanup(curl);
    return response;
}
