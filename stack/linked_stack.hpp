#ifndef LINKED_STACK_H
#define LINKED_STACK_H

#include <iostream>

using namespace std;

template<typename T>
struct LNode {
    T data;
    LNode* prev = nullptr;
};

template<typename T>
class LStack {
    private:
        LNode<T>* top = nullptr;
        unsigned short size = 0;
    public:
        LStack() = default;
        ~LStack();
        void push(const T& data);
        void pop();
        bool isEmpty() const;
        void printStack() const;
};

#include "./linked_stack.tpp"

#endif