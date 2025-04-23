// File: TokenQueue/TokenQueue.h
// Author: Sam Caldwell
// Description: Generic FIFO token queue with atomic next() behavior.

#ifndef TOKEN_QUEUE_H
#define TOKEN_QUEUE_H

#include <queue>
#include <stdexcept>
#include "Token.h"

// Token queue has a .pop() which returns the head value and pops it in one call.
// It's a template because the requirements require one template...and there is
// no real need for a template in this project other than to check the box.
template<typename T>
class TokenQueue {
public:
    // Push a token to the back
    void push(const T &token);

    // Check if empty
    bool empty() const;

    // Number of tokens
    size_t size() const;

    // Get the front element and remove it
    T pop();

    // Peek without removing
    const T &peek() const;

private:
    std::queue<T> tokens;
};

#include "utils/TokenQueue.tpp"

#endif // TOKEN_QUEUE_H
