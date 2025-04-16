// writeCallback.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of HttpClient using libcurl

#ifndef WRITECALLBACK_H
#define WRITECALLBACK_H

#include <cstddef>
#include <string>

inline static size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    size_t totalSize = size * nmemb;
    output->append((char*)contents, totalSize);
    return totalSize;
}

#endif //WRITECALLBACK_H
