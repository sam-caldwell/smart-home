// File: utils/Tokens.h
// Author: Sam Caldwell
// Description: Concrete FIFO queue for std::string with atomic next() behavior.

#ifndef TOKENS_H
#define TOKENS_H

#include <queue>
#include <string>



class Tokens {
public:
	using Token = std::string;
    // Push a token to the back
    void push(const std::string &token);

    // Check if empty
    bool empty() const;

    // Number of tokens
    size_t size() const;

    // Get and remove the front element
    std::string pop();

    // Peek without removing
    const std::string &peek() const;

private:
    std::queue<std::string> data;
};

#endif // TOKENS_H
