#ifndef RANDOM_LINKED_LIST_GENERATOR_H
#define RANDOM_LINKED_LIST_GENERATOR_H

#include <iostream>
#include <type_traits>
#include <random>
#include "linked_list_base.hpp"
using namespace std;

class RandomLinkedListGenerator {
    private:
        unsigned int size;
        LinkedListBase& list;
    public:
        RandomLinkedListGenerator(const unsigned int listSize, LinkedListBase& linkedList) : size {listSize}, list {linkedList} {};
        void generateRandom(unsigned int max = 100) {
            random_device rd;
            mt19937 gen(rd());
            uniform_int_distribution<unsigned int> dist(1u, max);
            for(unsigned int i = 0; i < size; i++) {
                unsigned int number = dist(gen);
                list.insert(number);
            }
        }

        void printList() {
            list.printList();
        }
};

#endif