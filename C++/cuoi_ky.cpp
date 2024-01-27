#include <iostream>
#include <math.h>
using namespace std;

int S(int n) {
    if(n <= 4) return 2 * n;
    else return S(n-4) - S(n-2) + 2 * S(n-1);
}

int Tong(int n) {
    int sum = 0;
    for(int i = 1; i <= n; i++) {
        sum += S(i);
    }
    return sum;
}

int TongN(int n) {
    int sum = 20;
    int h1 = 2, h2 = 4, h3 = 6, h4 = 8, h;
    if(n == 1) return 2;
    else if(n == 2) return 6;
    else if(n == 3) return 12;
    else if(n == 4) return 20;
    else {
        for(int i = 5; i <= n; i++) {
            h = h1 - h3 + 2 * h4;
            sum += h;
            h1 = h2; h2 = h3; h3 = h4; h4 = h;
        }
    }
    return sum;
}

int search(int M[], int k, int n) {
    int pos = -1;
    for(int i = 0; i < n; i++) {
        if(!(i % 2) && M[i] == 4 * k * k && !(n % 2)) {
            pos = i;
            break;
        }
        else if(i % 2 && M[i] == k * k/16 && n % 2) {
            pos = i;
            break;
        }
    }
    return pos;
}

int searchN(int M[], int k, int n) {
    int temp1 = (k * k) << 2;
    int temp2 = (k * k)>> 4;

    int i;
    
    if(n % 2 == 0) {
        for(i = 0; i < n; i += 2) {
            if(M[i] == temp1)
                return i;
        }
    } else {
        for(i = 1; i < n; i += 2) {
            if(M[i] == temp2) 
                return i;
        }
    }

    return -1;
}

int main() {
    int M[] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    cout << search(M, 2, 10) << endl;
    cout << searchN(M, 2, 10) << endl;
}