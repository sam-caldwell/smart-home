// HttpClient.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Simple HTTP client using libcurl
// Dependencies: libcurl

#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <string>
#include <vector>
#include <curl/curl.h>
#include <sstream>
#include <stdexcept>
#include "HttpClient/writeCallback.h"

class HttpClient {
public:
    explicit HttpClient(const std::string& baseUrl);
    ~HttpClient();

    std::string get(const std::string& endpoint);
    std::string post(const std::string& endpoint, const std::string& body,
                     const std::vector<std::string>& headers = {});

private:
    std::string baseUrl;
};

#endif // HTTP_CLIENT_H
