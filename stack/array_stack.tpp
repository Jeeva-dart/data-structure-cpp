#pragma once

template<typename T>
void AStack<T>::push(const T& input) {
    this->stack.push_back(input);
}

template<typename T>
void AStack<T>::printStack() const {
    size_t i = stack.size();
    do {
        --i;
        cout << '|' << stack[i] << "|\n";
    } while(i != 0);
    cout << "----" << endl;
}

template<typename T>
T AStack<T>::pop() {
    if(isEmpty()) throw out_of_range();
    T value = this->stack.back();
    this->stack.pop_back();
    return value;
}

template<typename T>
bool AStack<T>::isEmpty() const {
    return stack.size() == 0;
}

template<typename T>
T AStack<T>::peek() const {
    return stack.back();
}
