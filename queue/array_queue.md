#include <iostream>
#include <vector>
#include "queue/array_queue.hpp"
using namespace std;

int main() {
    AQueue<int> queue;
    queue.push(30);
    queue.push(80);
    queue.push(40);
    queue.push(10);
    cout << queue.peek() << endl;
    queue.printQueue();
    return 0;
};