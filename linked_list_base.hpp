#ifndef LINKED_LIST_BASE_H
#define LINKED_LIST_BASE_H

#include <variant>
using namespace std;

using VariantData = variant<int, unsigned int, float, char>;

struct DNode
{
    VariantData data;
    DNode* next = nullptr;
    DNode* prev = nullptr;
};

class LinkedListBase {
    public:
        virtual void insert(const VariantData& input) = 0;
        virtual void print(const VariantData& input) = 0;
        virtual void printList() = 0;
        virtual void shift() = 0;
        virtual VariantData pop() = 0;
        virtual DNode* searchIndex(unsigned short index) const = 0;
        virtual DNode* searchNode(const VariantData& find) = 0;
        virtual bool remove(const VariantData& value) = 0;
        virtual void reverse() = 0;
        virtual void swapping(DNode*& a, DNode*& b) const = 0;
};

#endif