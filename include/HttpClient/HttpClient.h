// HttpClient.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Simple HTTP client using libcurl
// Dependencies: libcurl
// Changes: Initial version created for smart home automation project

#ifndef HTTP_CLIENT_H
#define HTTP_CLIENT_H

#include <string>
#include <vector>
#include <curl/curl.h>
#include <sstream>
#include <stdexcept>

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

inline static size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

#endif // HTTP_CLIENT_H
