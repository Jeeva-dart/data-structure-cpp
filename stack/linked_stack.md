#include <iostream>
#include <vector>
#include "stack/linked_stack.hpp"
using namespace std;

int main() {
    LStack<int> ls;
    ls.push(20);
    ls.push(60);
    ls.push(80);
    ls.push(40);
    ls.push(10);
    ls.printStack();
    ls.pop();
    ls.printStack();
    ls.pop();
    ls.printStack();

    return 0;
};