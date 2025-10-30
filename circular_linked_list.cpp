#include "circular_linked_list.hpp"

CircularLinkedList::~CircularLinkedList() {
    CNode* curr = head;
    do {
        CNode* tmp = curr;
        curr = curr->next;
        delete tmp;
    } while(curr != head);
    head = tail = nullptr;
}

void CircularLinkedList::pop() {
    if(head == nullptr) {
        cout << "List is empty" << endl;
        return;
    };
    if(head->next == head) {
        delete head;
        head = nullptr;
        --size;
        return;
    }
    CNode* curr = head;
    while(curr->next != tail) {
        curr = curr->next;
    }
    delete tail;
    tail = curr;
    tail->next = head;
    --size;
}

void CircularLinkedList::insert(const VariantData& input) {
    CNode* node = new CNode;
    node->data = input;
    node->next = node;

    if(capacity !=  0 && size == capacity) {
        CNode* curr = head;
        head = curr->next;
        delete curr;
        --size;
    } 

    if(head == nullptr) {
        head = tail = node;
    } else {
        node->next = head;
        tail->next = node;
        tail = node;
    }
    ++size;
}

void CircularLinkedList::printList() const {
    if (!head) {
        cout << "List is empty.\n";
        return;
    }

    CNode* curr = head;
    do {
        this->print(curr);
        curr = curr->next;
    } while(curr != head);
    cout << endl;
}

void CircularLinkedList::print(const CNode* node) const {
    visit([](auto&& val) {
            cout << '[' << val << "] => ";
    }, node->data);
}