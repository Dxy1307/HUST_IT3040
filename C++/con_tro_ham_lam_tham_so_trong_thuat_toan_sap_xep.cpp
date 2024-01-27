#include <iostream>
#include <algorithm>
using namespace std;

void printArray(int *arr, int length) {
    for(int i = 0; i < length; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

bool ascending(int left, int right) {
    return left > right;
}

bool descending(int left, int right) {
    return left < right;
}

bool evensFirst(int left, int right) {
    if(left % 2 == 0 && right % 2 == 1) return false;
    if(left % 2 != 0 && right % 2 == 0) return true;
    return ascending(left, right);
}

void selectionSort(int *arr, int length, bool (*comparionFunc) (int, int)) {
    for(int i = 0; i < length; i++) {
        int minIndex = i;
        for(int j = i + 1; j < length; j++) {
            if(comparionFunc(arr[minIndex], arr[j])) {
                minIndex = j;
            }
        }

        swap(arr[i], arr[minIndex]);
    }
}

int main() {
    int arr[] = {1, 4, 2, 3, 6, 5, 8, 9, 7};
    int length = sizeof(arr) / sizeof(int);
    
    cout << "Before sorted: ";
    printArray(arr, length);

    selectionSort(arr, length, ascending);

    cout << "After sorted: ";
    printArray(arr, length);

    return 0;
}