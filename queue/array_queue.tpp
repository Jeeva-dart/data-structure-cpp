#pragma once

template<typename T>
void AQueue<T>::push(const T& input) {
    queue.push_back(input);
    ++size;
}

template<typename T>
void AQueue<T>::pop() {
    if(isEmpty()) return;
    queue.pop();
    --size;
}

template<typename T>
bool AQueue<T>::isEmpty() {
    return size == 0;
}

template<typename T>
void AQueue<T>::printQueue() const {
    for(int i = queue.size() - 1; i >= 0; i--) {
        cout << '|' << queue[i] << '|';
    }
    cout << endl;
}

template<typename T>
T AQueue<T>::peek() const {
    return queue.front();
}