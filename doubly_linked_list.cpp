#include "doubly_linked_list.hpp"
#include "custom_exceptions.hpp"

DoublyLinkedList::~DoublyLinkedList() {
    for(unsigned int i = size; i > 0; i-- ) {
        pop();
    }
};

void DoublyLinkedList::insert(const VariantData& input) {
    DNode* node = new DNode;
    node->data = input;
    if(head == nullptr) {
        head = tail = node;
    } else {
        node->prev = tail;
        tail->next = node;
        tail = node;
    }
    ++size;
};

void DoublyLinkedList::print(const VariantData& input) {
    visit([](auto&& val) {
        cout << '[' << val << "] => ";
    }, input);
};

void DoublyLinkedList::printList() {
    DNode* curr = head;
    while(curr) {
        print(curr->data);
        curr = curr->next;
    }
    cout << endl;
};

void DoublyLinkedList::shift() {
    if(head == nullptr) throw no_element_list("there is no element in list");
    if(head->next != nullptr) {
        DNode* curr = head;
        head = curr->next;
        delete curr;
    } else {
        head = tail = nullptr;
    }
    --size;
};

VariantData DoublyLinkedList::pop() {
    if (tail == nullptr) throw no_element_list("there is no element in list");

    DNode* curr = tail;
    VariantData data = curr->data;
    if (tail->prev != nullptr) {
        tail = tail->prev;
        tail->next = nullptr;
    } else {
        head = tail = nullptr;
    }
    delete curr;
    --size;
    return data;
};

DNode* DoublyLinkedList::searchIndex(unsigned short index) const {
    DNode* curr = head;
    unsigned short i = 0;
    while(curr) {
        if(i == index) {
            return curr;
        }
        curr = curr->next;
        i++;
    }
    return nullptr;
}

DNode* DoublyLinkedList::searchNode(const VariantData& find) {
    DNode* curr = head;
    while(curr) {
        if(curr->data == find) {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

bool DoublyLinkedList::remove(const VariantData& value) {
    if(head == nullptr) return false;
    DNode* curr = searchNode(value);
    if(curr == head && curr == tail) {
        head = tail = nullptr;
        return true;
    }
    if(curr) {
        DNode* prev = curr->prev;
        DNode* next = curr->next;
        if(prev != nullptr) {
            prev->next = next;
        } else {
            next->prev = nullptr;
            head = next;
        }
        
        if(next != nullptr) {
            next->prev = prev;
        }
        delete curr;
        return true;
    }
    return false;
}

void DoublyLinkedList::reverse() {
    DNode* curr = head;
    while(curr) {
        swap(curr->next, curr->prev);
        curr = curr->prev;
    }
    swap(head, tail);
}

void DoublyLinkedList::swapping(DNode*& a, DNode*& b) const {
    DNode* temp = move(a);
    a = move(b);
    b = move(temp);
}