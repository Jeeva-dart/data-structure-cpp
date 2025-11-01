#ifndef ARRAY_QUEUE_H
#define ARRAY_QUEUE_H

#include <iostream>
#include <vector>

using namespace std;

template<typename T>
class AQueue {
    private:
        vector<T> queue;
        unsigned int size = 0;
    public:
        AQueue() = default;
        void push(const T& input);
        void pop();
        bool isEmpty();
        void printQueue() const;
        T peek() const;
};

#include "array_queue.tpp"

#endif