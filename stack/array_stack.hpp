#ifndef ARRAY_STACK_H
#define ARRAY_STACK_H

#include <iostream>
#include <vector>
using namespace std;

template<typename T>
class AStack {
    private:
        vector<T> stack;
    public:
        explicit AStack() = default;
        void push(const T& input);
        T pop();
        bool isEmpty() const;
        T peek() const;
        void printStack() const;
};

#include "./array_stack.tpp"

#endif