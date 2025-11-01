#include <iostream>
#include <vector>
#include "stack/array_stack.hpp"
using namespace std;

int main() {
    AStack<int> stack;
    stack.push(20);
    stack.push(40);
    stack.push(60);
    stack.push(80);
    stack.push(90);
    stack.printStack();
    cout << stack.peek() << endl;
    cout << "Is empty" << stack.isEmpty() << endl;
    return 0;
};