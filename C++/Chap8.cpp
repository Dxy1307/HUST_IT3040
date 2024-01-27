#include <stdio.h>
#include <iostream>
#include <assert.h>
using namespace std;

double division(int a, int b) {
    if(b == 0) {
        throw "Division by zero";
    }
    return a / b;
}

int main() {
    int x = 50;
    int y = 3;
    double z = 0;

    try {
        z = division(x, y);
        cout << z << endl;
    } catch(const char*msg) {
        cerr << msg << endl;
    }

    return 0;
}