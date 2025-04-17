// HttpClient/constructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of HttpClient using libcurl

#include <HttpClient/HttpClient.h>

HttpClient::HttpClient(const std::string& baseUrl) : baseUrl(baseUrl) {
    curl_global_init(CURL_GLOBAL_DEFAULT);
}
