#ifndef DOUBLY_CIRCULAR_LINKED_LIST_H
#define DOUBLY_CIRCULAR_LINKED_LIST_H

#include <iostream>
#include <variant>
using namespace std;
using VariantData = variant<int, short, char>;

struct DCNode {
    VariantData data;
    DCNode* prev = nullptr;
    DCNode* next = nullptr;
};

class DoublyCircularLinked {
    private:
        unsigned int size = 0;
        DCNode* head = nullptr;
        DCNode* tail = nullptr;
    
    public:
        DoublyCircularLinked() = default;
        ~DoublyCircularLinked();
        void print(const DCNode* node) const;
        void printList() const;
        void insert(const VariantData data);
};

#endif