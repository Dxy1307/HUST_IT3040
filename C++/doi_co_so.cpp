#include<bits/stdc++.h>
using namespace std;

void base_change(int n, int b) {
    char digits[20] = "0123456789ABCDEF";
    stack<int> stk;
    do {
        stk.push(n % b);
        n = n / b;
    } while(n);

    while(!stk.empty()) {
        int u = stk.top();
        stk.pop();
        cout << digits[u];
    }
}

int main() {
    base_change(3553, 8);
}