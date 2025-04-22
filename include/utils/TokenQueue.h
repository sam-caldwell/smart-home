// File: TokenQueue/TokenQueue.h
// Author: Sam Caldwell
// Description: Generic FIFO token queue with atomic next() behavior.

#ifndef TOKEN_QUEUE_H
#define TOKEN_QUEUE_H

#include <queue>
#include <stdexcept>

template<typename T>
class TokenQueue {
public:
    // Push a token to the back
    void push(const T& token) {
        tokens.push(token);
    }

    // Check if empty
    bool empty() const {
        return tokens.empty();
    }

    // Number of tokens
    size_t size() const {
        return tokens.size();
    }

    // Get the front element and remove it
    T pop() {
        if (tokens.empty()) {
            throw std::underflow_error("TokenQueue::pop() called on empty queue.");
        }
        T front = tokens.front();
        tokens.pop();
        return front;
    }

    // Peek without removing
    const T& peek() const {
        if (tokens.empty()) {
            throw std::underflow_error("TokenQueue::peek() called on empty queue.");
        }
        return tokens.front();
    }

private:
    std::queue<T> tokens;
};

#endif // TOKEN_QUEUE_H
