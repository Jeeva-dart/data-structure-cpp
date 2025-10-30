#include<iostream>
#include<iomanip>
#include<memory>
#include "Point.hpp"
using namespace std;

int main() {
    Point p1 {10, 20};
    Point p2 {20, 20};
    p2 = ++p1;
    p1++;
    cout << p1 << endl;
    cout << p2 << endl;
    return 0;
}
 