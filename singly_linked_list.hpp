#ifndef SINGLY_LINKED_LIST_H
#define SINGLY_LINKED_LIST_H
#include <iostream>
#include <variant>
#include <vector>

using namespace std;

using VariantData = variant<int, float, string>;
struct Node
{
    VariantData data;
    Node* next = nullptr;
};

class SinglyLinkedList {
    private:
        Node* head = nullptr;
        Node* tail = nullptr;
        size_t size = 0;
    public:
        SinglyLinkedList() = default;
        
        ~SinglyLinkedList() {
            Node* current = head;
            while(current) {
                Node* next = current->next;
                delete current;
                current = next;
            }
            size = 0;
            head = tail = nullptr;
        }
        
        void insert(VariantData data) {
            Node* node = new Node;
            node->data = data;
            node->next = nullptr;
            if(head == nullptr) {
                head = node;
                tail = node;
            }
            if(tail != nullptr) {
                tail->next = node;
                tail = node;
            }
            size++;
        }
        void print() const {
            Node* current = head;
            while (current) {
                std::visit([](auto&& val) {
                    std::cout << val << " ";
                }, current->data);
                current = current->next;
            }
            std::cout << "\nTotal: " << size << ": size => " << sizeof(Node) << endl;
        }
        bool isEmpty() const {
            return head == nullptr;
        }
        void insertAtHead(VariantData value) {
            Node* node = new Node;
            node->data = value;
            node->next = head;
            head = node;
            size++;
        }
        void pop() {
            Node* curr = head;
            head = head->next;
            delete curr;
            size--;
        }
        short search(VariantData value) {
            Node* current = head;
            short i = 0;
            while(current) {
                if(current->data == value) {
                    return i;
                }
                current = current->next;
                i++;
            }
            return -1;
        }
        Node* posAt(const short pos) {
            Node* current = head;
            short i = 0;
            while(current) {
                if(i == pos) {
                    return current;
                }
                current = current->next;
                i++;
            }
            return nullptr;
        }
        bool insertAt(short pos, VariantData value) {
            if(pos >= static_cast<short>(size)) {
                throw out_of_range("overflow error!");
            }
            Node* element = posAt(pos-1);
            if(element != nullptr) {
                Node* newNode = new Node{ value, element->next };
                element->next = newNode;
                ++size;
                return true;
            } else {
                throw invalid_argument("position not found!");
            }
            return false;
        }
        bool deleteAt(short pos) {
            if(pos >= static_cast<short>(size)) {
                throw out_of_range("Position overflow");
            }
            Node* element = posAt(pos-1);
            if(element != nullptr) {
                Node* deleteNode = element->next;
                element->next = deleteNode->next;
                delete deleteNode;
                --size;
                return true;
            }
            return false;
        }
        void reverse() {
            Node* current = head;
            Node* prev = nullptr;
            Node* next = nullptr;
            while(current) {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
            }
            tail = head;
            head = prev;
        }
        std::vector<VariantData> toArray() {
            std::vector<VariantData> arr;
            arr.reserve(size);
            Node* current = head;
            while(current) {
                arr.push_back(current->data);
                current = current->next;
            }
            return arr;
        }
};

#endif