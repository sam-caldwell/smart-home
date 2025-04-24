// SimpleJson.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Minimal JSON parser for known (FLAT) structure
// Changes: Initial version created for smart home automation project

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
#include "utils/OnOff.h"

class SimpleJson {
public:

    using DataMap = std::unordered_map<std::string, std::string>;

    explicit SimpleJson() = default;
    explicit SimpleJson(const std::string &json);
    explicit SimpleJson(const std::unordered_map<std::string, OnOff> &map);

    inline void set(const std::string& key, const std::string &value) { data[key] = value; };
    inline void set(const std::string& key, const int &value) { data[key] = std::to_string(value); };
    inline void set(const std::string& key, const bool &value) { data[key] = std::to_string(value); };
    inline void set(const std::string& key, const OnOff &value) { data[key] = value.string(); };

    // return the string representation of the internal key-value state (map)
    const std::string stringify();

    // parse json string for the value of a given key as a string
    [[nodiscard]] std::string getString(const std::string &key) const;

    // parse json string for the value of a given key as int
    [[nodiscard]] int getInt(const std::string &key) const;

    // return the parsed map state
    [[nodiscard]] DataMap getMap() const {return data;}

private:
    // the parsed json string state as a key-value map
    DataMap data;

    void parse(const std::string &json);
};

#endif // SIMPLE_JSON_PARSER_H
