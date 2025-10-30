#include "utils.h"
namespace Utils {
    void printArray(short arr[], short size) {
        cout << '[';
        for(int i = 0; i < size; i++) {
            cout << arr[i] << (i == (size - 1) ? "]" : "] => [");
        }
        cout << endl;
    }
}