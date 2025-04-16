// writeCallback.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Implementation of HttpClient using libcurl

#ifndef WRITECALLBACK_H
#define WRITECALLBACK_H

static size_t writeCallback(
    void* contents,
    size_t size,
    size_t nmemb,
    std::string* output);

#endif //WRITECALLBACK_H
