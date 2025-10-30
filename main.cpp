#include <iostream>
#include <limits>
#include "doubly_circular_linked_list.hpp"
using namespace std;

int main() {
    DoublyCircularLinked dcll;
    dcll.insert(10);
    dcll.insert(20);
    dcll.insert(30);
    dcll.insert(40);
    dcll.insert(50);
    dcll.printList();
    return 0;
};