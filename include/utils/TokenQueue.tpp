template<typename T>
void TokenQueue<T>::push(const T &token) {
    tokens.push(token);
}

template<typename T>
bool TokenQueue<T>::empty() const {
    return tokens.empty();
}

template<typename T>
size_t TokenQueue<T>::size() const {
    return tokens.size();
}

template<typename T>
T TokenQueue<T>::pop() {
    if (tokens.empty()) {
        throw std::underflow_error("TokenQueue::pop() called on empty queue.");
    }
    T front = tokens.front();
    tokens.pop();
    return front;
}

template<typename T>
const T &TokenQueue<T>::peek() const {
    if (tokens.empty()) {
        throw std::underflow_error("TokenQueue::peek() called on empty queue.");
    }
    return tokens.front();
}
