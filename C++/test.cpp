#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <string.h>
using namespace std;

struct Time {
    int h;
    int m;
    int s;
};

long ConvertTimeToGiay(Time T) {
    return (long)(T.h * 3600 + T.m * 60 + T.s);
}

int H(int n) {
    if(n < 5) return n;
    else return H(n - 4) + H(n - 3) - H(n - 2) + H(n - 1);
}

long Tong(int n) {
    long t = 0;
    for(int i = 1; i <= n; i++) {
        t += H(i);
    }
    return t;
}

// Khử đệ quy
long TongN(int n) {
    int i, h1 = 1, h2 = 2, h3 = 3, h4 = 4, h;
    long t = 10;
    if(n == 1) return 1;
    else if(n == 2) return 3;
    else if(n == 3) return 6;
    else if(n == 4) return 10;
    else {
        for(int i = 5; i <= n; i++) {
            h = h1 + h2 - h3 + h4;
            t += h;
            h1 = h2; h2 = h3; h3 = h4; h4 = h;
        }
    }
    return t;
}

int F(int *x) {
    *x += 1;
    return *x;
}

float tong(float *m1, float *m2, int n) {
    float ta, tb, sum = 0.0;
    int i = n;
    ta = m1[i]; tb = m2[i];
    for(i = n - 1; i >= 0; i--) {
        sum += ta + tb;
        ta = m1[i]; tb = m2[i];
    }
    sum += ta + tb;
    return sum;
}

void my_func(float val, float *a, int n) {
    int i = 0, found = 0;
    while((!found) && (i < n)) {
        float testval = log(val)/log(2);
        if(a[i] == testval) found = 1;
        else i++;
    }
}

void ktra(int *a, int *b, int c) {
    *((*a+1 == 1) ? b : a) = *a ? *b : c;
}

void foo(int *a, int b, int &c) {
    a += 5;
    b += 6;
    c += 7;
}

inline int vd(int x, int y) {
    static int a = 10;
    return (x > a || y) ? x - a + y++ : x + y;
}

int x = 0;
void myFunc() {
    int x = 5;
}

void hoanv(int *px, int *py) {
    int *z;
    z = px;
    px = py;
    py = z;
}

void myprint(int a) {
    cout << a << " ";
}

void myprint(int a, int b) {
    cout << a << " " << b;
}

int main() {
    myprint(5);
    return 0;
}