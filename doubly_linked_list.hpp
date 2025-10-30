#ifndef DOUBLY_LINKED_LIST_H
#define DOUBLY_LINKED_LIST_H

#include <iostream>
#include "linked_list_base.hpp"

using namespace std;

class DoublyLinkedList : public LinkedListBase {
    private:
        DNode* head = nullptr;
        DNode* tail = nullptr;
        unsigned int size = 0;
    
    public:
        DoublyLinkedList() = default;
        ~DoublyLinkedList();
        void insert(const VariantData& input) override;
        void print(const VariantData& input)override;
        void printList() override;
        void shift() override;
        VariantData pop() override;
        DNode* searchIndex(unsigned short index) const override;
        DNode* searchNode(const VariantData& find) override;
        bool remove(const VariantData& value) override;
        void reverse() override;
        void swapping(DNode*& a, DNode*& b) const override;
};

#endif