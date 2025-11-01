#pragma once

template<typename T>
LStack<T>::~LStack() {
    while(!isEmpty()) {
        pop();
    }
}

template<typename T>
void LStack<T>::push(const T& input) {
    LNode<T>* node = new LNode<T>;
    node->data = input;
    node->prev = top;
    top = node;
    ++size;
}

template<typename T>
void LStack<T>::pop() {
    if(top == nullptr) return;
    LNode<T>* curr = top->prev;
    delete top;
    top = curr;
    --size;
}

template<typename T>
bool LStack<T>::isEmpty() const {
    return size == 0;
}

template<typename T>
void LStack<T>::printStack() const {
    LNode<T>* curr = top;
    while(curr) {
        cout << '[' << curr->data << "] => ";
        curr = curr->prev;
    }
    cout << endl;
}