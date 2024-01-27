// Nguyễn Đức Duy - 20210275
#include<stdio.h>
#include<iostream>
using namespace std;

int lucas(int n) {
    
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    
    if(n <= 1) return 2 - n; // L0 = 2; L1 = 1
    return lucas(n - 1) + lucas(n - 2); // L(n) = L(n - 1) + L(n - 2)
}

int main() {
    cout << lucas(10);
}
// Nguyễn Đức Duy - 20210275