#include<bits/stdc++.h>
using namespace std;

int PART(int m, int n) {
    if(m == 0 || n == 0) return 1;
    else if(m < n) return PART(m, m);
    else return PART(m, n - 1) + PART(m - n, n);
}

int main() {
    cout << PART(5, 3) << endl;
    return 0;
}