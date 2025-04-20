// SimpleJson.h
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

class SimpleJson {
public:
    explicit SimpleJson() = default;

    explicit SimpleJson(const std::string &json);

    inline void set(std::string key, std::string value) { data[key] = value; };
    inline void set(std::string key, int value) { data[key] = std::to_string(value); };
    inline void set(std::string key, bool value) { data[key] = std::to_string(value); };

    // return the string representation of the internal key-value state (map)
    const std::string stringify();

    // parse json string for the value of a given key as a string
    [[nodiscard]] std::string getString(const std::string &key) const;

    // parse json string for the value of a given key as int
    [[nodiscard]] int getInt(const std::string &key) const;

private:
    // the parsed json string state as a key-value map
    std::unordered_map<std::string, std::string> data;

    void parse(const std::string &json);
};

#endif // SIMPLE_JSON_PARSER_H
