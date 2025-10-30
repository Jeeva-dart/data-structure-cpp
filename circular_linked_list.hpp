#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <iostream>
#include <variant>

using namespace std;

using VariantData = variant<int, char, short>;
struct CNode {
    VariantData data;
    CNode* next;
};

class CircularLinkedList {
    private:
        unsigned short size = 0;
        CNode* head = nullptr;
        CNode* tail = nullptr;
        unsigned short capacity = 0;
        bool fifo = true;
    public:
        CircularLinkedList() = default;
        ~CircularLinkedList();
        explicit CircularLinkedList(const unsigned short length) : capacity {length} {};
        explicit CircularLinkedList(const unsigned short length, const bool first_in_first_out) : capacity {length}, fifo {first_in_first_out} {};
        void pop();
        void insert(const VariantData& input);
        void printList() const;
        void print(const CNode* node) const;
};

#endif