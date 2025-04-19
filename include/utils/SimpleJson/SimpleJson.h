// SimpleJsonParser.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Minimal JSON parser for known (FLAT) structure
// Dependencies: None

/*
 * WARNING:
 *     Don't use this.  It's for a very limited use case
 *     where you have a flat object. You have been warned.
 *                               --Sam Caldwell 9/23/2015
 */

#ifndef SIMPLE_JSON_PARSER_H
#define SIMPLE_JSON_PARSER_H

#include <algorithm>
#include <sstream>
#include <stdexcept>
#include <string>
#include <unordered_map>

class SimpleJsonParser {
public:
    explicit SimpleJsonParser(const std::string &json);

    std::string getString(const std::string &key) const;
    int getInt(const std::string &key) const;

private:
    std::unordered_map<std::string, std::string> data;

    void parse(const std::string &json);
};

#endif // SIMPLE_JSON_PARSER_H
