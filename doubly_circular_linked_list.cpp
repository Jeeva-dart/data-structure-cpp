#include "doubly_circular_linked_list.hpp"

using VariantData = variant<int, short, char>;

DoublyCircularLinked::~DoublyCircularLinked() {
    DCNode* curr = head;
    do {
        DCNode* temp = curr;
        curr = curr->next;
        delete temp;
    } while(curr != head);
    head = tail = nullptr;
    size = 0;
}

void DoublyCircularLinked::print(const DCNode* node) const {
    visit([](auto&& val) {
        cout << '[' << val << "] <=> ";
    }, node->data);
}

void DoublyCircularLinked::insert(const VariantData data) {
    DCNode* node = new DCNode;
    node->data = data;
    node->prev = node;
    
    if(head == nullptr) {
        node->next = node;
        head = tail = node;
    } else {
        node->next = head;
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
    ++size;
}

void DoublyCircularLinked::printList() const {
    DCNode* curr = head;
    do {
        print(curr);
        curr = curr->next;
    } while(curr != head);
}