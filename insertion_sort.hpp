#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include <iostream>
#include <vector>

using namespace std;

class InsertionSort {
    public:
        void sort(vector<unsigned short>& arr) {
            unsigned short n = static_cast<unsigned short>(arr.size());
            for(unsigned short i = 1; i < n; ++i) {
                unsigned short key = arr[i];
                short j = static_cast<short>(i - 1);
                while(j >= 0 && arr[j] > key) {
                    arr[j + 1] = arr[j];
                    j--;
                }
                arr[j+1] = key;
            }
        }

        void print(vector<unsigned short>& arr) {
            for(unsigned short i = 0; i < arr.size(); i++) {
                cout << arr[i] << "=>";
            }
            cout << endl;
        }
};

#endif