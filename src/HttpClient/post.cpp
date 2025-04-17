// HttpClient/post.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of HttpClient using libcurl

#include <HttpClient/HttpClient.h>

std::string HttpClient::post(const std::string& endpoint, const std::string& body,
                             const std::vector<std::string>& headers) {
    CURL* curl = curl_easy_init();
    if (!curl) throw std::runtime_error("Failed to initialize CURL");

    std::string response;
    std::string url = baseUrl + endpoint;

    struct curl_slist* headerList = nullptr;
    for (const auto& h : headers) {
        headerList = curl_slist_append(headerList, h.c_str());
    }

    curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
    curl_easy_setopt(curl, CURLOPT_POST, 1L);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.c_str());
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);
    if (headerList) curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headerList);

    CURLcode res = curl_easy_perform(curl);
    if (res != CURLE_OK)
        throw std::runtime_error("POST request failed: " + std::string(curl_easy_strerror(res)));

    if (headerList) curl_slist_free_all(headerList);
    curl_easy_cleanup(curl);
    return response;
}
