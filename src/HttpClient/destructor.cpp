// HttpClient/destructor.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of HttpClient using libcurl

#include <HttpClient/HttpClient.h>

HttpClient::~HttpClient() {
    curl_global_cleanup();
}
