// writeCallback.cpp
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of HttpClient using libcurl

#include "writeCallback.h"

static size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}
