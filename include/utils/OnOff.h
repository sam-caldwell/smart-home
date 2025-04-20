// File: utils/OnOff.h
// Author: Sam Caldwell <scaldwell@asymmetric-effort.com>
// Description: Strongly-typed On/Off wrapper with methods

#ifndef ON_OFF_H
#define ON_OFF_H

#include <algorithm>
#include <stdexcept>
#include <string>
#include "utils/StringUtils.h"

class OnOff {
public:
    // Constructors
    OnOff() : state(false) { /*noop*/ }
    explicit OnOff(const std::string& value) { set(value);}

    // Set state from string
    void set(const std::string& value) {
        const std::string lowerValue = to_lower(value);
        if (lowerValue == vOn)
            state = true;
        else if (lowerValue == vOff)
            state = false;
        else
            throw std::invalid_argument("OnOff expects 'on' or 'off'");
    }

    // Get state as string
    [[nodiscard]] std::string string() const {  return state ? vOn : vOff;}

    // Get state as bool
    [[nodiscard]] bool boolean() const { return state; }

    // Toggle state
    void toggle() { state = !state; }

    void on() {
        state=true;
    }

    void off() {
        state=false;
    }

private:
    bool state{};

    static const std::string vOn;
    static const std::string vOff;
};



#endif // ON_OFF_H
