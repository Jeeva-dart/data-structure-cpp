#ifndef BASICS_ARRAY_H
#define BASICS_ARRAY_H
#include <iostream>
#include <stdexcept>

using namespace std;

template<typename T>
class SimpleArray {
    private:
        size_t size;
        T* store;
        size_t capacity;
    public:
        SimpleArray();
        ~SimpleArray();
        void push(const T& value);
        size_t length() const { return this->size; }
        T& operator[](size_t index) {
            if(index >= size) {
                throw out_of_range("out of bounds");
            }
            return store[index];
        }
        T pop() {
            if (size == 0) {
                throw out_of_range("pop from empty array");
            }
            --size;
            T val = store[size];
            // Do not call delete on store[size] because elements come from new T[],
            // and individual elements must not be deleted; the array is freed in the destructor.
            return val;
        }
        size_t find(T value) {
            for(size_t i = 0; i < size; i++) {
                if(store[i] == value) {
                    return i;
                }
            }
            return -1;
        }
        T* operator*() {
            return store;
        }
        friend ostream& operator<<(ostream& stream, const SimpleArray<T>& arr) {
            for(size_t i = 0; i < arr.size; i++) {
                stream << '[' << arr.store[i] << ']';
                if(i < arr.size - 1) {
                    stream << " => ";
                }
            }
            stream << endl;
            return stream;
        }
};

template<typename T>
SimpleArray<T>::SimpleArray() : size(0), store(nullptr), capacity(1) {
    store = new T[capacity];
    cout << "New heap memory allocated => " << store << endl;
}

template<typename T>
SimpleArray<T>::~SimpleArray() {
    delete[] store;
}

template<typename T>
void SimpleArray<T>::push(const T& value) {
    if(size == capacity) {
        capacity *= 2;
        T* newArray = new T[capacity];
        for(size_t i = 0; i < size; i++) {
            newArray[i] = store[i];
        }
        delete[] store;
        store = newArray;
    }
    store[size++] = value;
}
#endif