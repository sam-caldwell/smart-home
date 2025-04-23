// File: Tokens/Tokens.cpp
// Author: Sam Caldwell
// Description: Implementation for the concrete TokenQueue class

#include "utils/Tokens.h"

void Tokens::push(const Token &token) {
    data.push(token);
}

bool Tokens::empty() const {
    return data.empty();
}

size_t Tokens::size() const {
    return data.size();
}

std::string Tokens::pop() {
    if (data.empty()) {
        throw std::underflow_error("Tokens::pop() called on empty queue.");
    }
    std::string front = data.front();
    data.pop();
    return front;
}

const std::string &Tokens::peek() const {
    if (data.empty()) {
        throw std::underflow_error("Tokens::peek() called on empty queue.");
    }
    return data.front();
}
