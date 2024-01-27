#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <cstring>
#include <math.h>
#include <stack>
using namespace std;

// Đệ quy tuyến tính
bool isPalindrome(const string &s) { // chuỗi đầu cuối như nhau
    if(s.length() < 2) {
        return true;
    } else {
        if(s[0] != s[s.length() - 1]) {
            return false;
        }
        string middle = s.substr(1, s.length() - 2);
        return isPalindrome(middle);
    }
}

// Đệ quy nhị phân
void move(int n, char A, char B, char C) {// tháp hà nội
    if(n == 1) {
        cout << A << " ==> " << C << '\n';
    } else {
        move(n - 1, A, C, B);
        cout << A << " ==> " << C << '\n';
        move(n - 1, B, A, C);
    }
}

// Đệ quy phi tuyến
int A(int n) {
    if(n == 0) return 1;
    else {
        int temp = 0;
        for(int i = 0; i < n; i++) {
            temp += (n - i) * (n - i) * A(i);
        }
        return temp;
    }
}

// Đệ quy tương hỗ
long Y(int n);
long X(int n) {
    if(n == 0) return 1;
    else return X(n - 1) + Y(n - 1);
}
long Y(int n) {
    if(n == 0) return 1;
    else return X(n - 1) * Y(n - 1);
}

// Đệ quy có nhớ
int mem[1000];
int fibo(int n) {
    if(n <= 2) return 1;
    if(mem[n] != -1) return mem[n];
    int res = fibo(n - 1) + fibo(n - 2);
    mem[n] = res;
    return res;
}

// Đệ quy quay lui - bài toán n Queens
const int NMAX = 20;
int a[NMAX], n;

void print_sol() {
    for(int i = 1; i <= n; i++) {
        cout << a[i] << (i == n ? '\n' : ' ');
    }
}

bool isCandidate(int j, int k) {
    for(int i = 1; i < k; i++) {
        if(j == a[i] || (fabs(j - a[i]) == (k - i))) {
            return false;
        }
    }
    return true;
}

void TRY(int k) {
    for(int i = 1; i <= n; i++) {
        if(isCandidate(i, k)) {
            a[k] = i;
            if(k == n) print_sol();
            else TRY(k + 1);
        }
    }
}

// Khử đệ quy bằng vòng lặp
int fact(int n) { // khử đệ quy hàm tính giai thừa
    int k = 0;
    int F = 1;
    while(k < n) {
        F = ++k * F;
    }
    return F;
}

int S(int n) { // S(n) = 1 - 3 + 5 - .... + (-1)^(n+1)(2n - 1)
    int k = 1;
    int sum = 1;
    while(k < n) {
        k++;
        if(k % 2 == 1) sum += 2*k - 1;
        else sum -= 2*k - 1;
    }
    return sum;
}

// Khử đệ quy đuôi
int USCLN(int m, int n) {
    if(n == 0) return m;
    else USCLN(n, m % n);
}
// X là (m, n)
// P(X) là USCLN(m, n)
// B(X) là n == 0
// D(X) là return m
// A(X) là lệnh rỗng
// f(X) là f(m, n) = (n, m mod n)

int USCLNN(int m, int n) {
    int temp;
    while(n != 0) { // !B(X)
        temp = m;
        m = n;// X = f(X)
        n = temp % n;// X = f(X)
    }
    return m;// D(X)
}

// Khử đệ quy tuyến tính bằng stack
void binary(int m) {// chuyển từ cơ số thập phân sang nhị phân
    if(m > 0) {
        binary(m / 2);
        cout << m % 2;
    }
}
// X là m
// P(X) là binary(m)
// A(X), D(X) là lệnh rỗng
// B(X) là lệnh cout << m % 2
// C(X) là m <= 0
// f(X) là f(m) = m / 2

void binaryN(int m) {
    stack<int> stk;
    while(m > 0) {// !C(X)
        //A(X) empty
        stk.push(m);// push(S, X)
        m = m / 2;// X = f(X)
    }
    // D(X) empty
    while(!stk.empty())  {
        int u = stk.top();
        stk.pop();
        cout << u % 2;// B(X)
    }
}

// Khử đệ quy nhị phân bằng stack
void move(char A, char C) {
    cout << A << " -> " << C << endl;
}
void THN(int n, char A, char B, char C) {
    if(n > 0) {
        THN(n - 1, A, C, B);
        move(A, C);
        THN(n - 1, B, A, C);
    }
}
// biến X là bộ (n, A, B, C)
// C(X) là n <= 0
// D(X), A(X) rỗng
// B(X) = B(n, A, B, C) là move (A, C)
// f(X) = f(n, A, B, C) = (n-1, A, C, B)
// g(X) = g(n, A, B, C) = (n-1, B, A, C) 

struct state {
    int n, k;
    char A, B, C;
    state(int _n, char _A, char _B, char _C, int _k):
        n(_n), A(_A), B(_B), C(_C), k(_k) {}
};
void iter_THn(int n, char A, char B, char C) {
    stack<state> stk;
    stk.push(state(n, A, B, C, 1));
    int k = 0;
    while(k != 1) {
        while(n > 0) {
            stk.push(state(n, A, B, C, 2));
            n--;
            swap(B, C);
        }
        // move(A, C);
        state s = stk.top();
        stk.pop();
        tie(n, A, B, C, k) = make_tuple(s. n, s.A, s.B, s.C, s.k);
        if(k != 1) {
            move(A, C);
            n--;
            swap(A, B);
        }
    }
}
// int power(int x, int exp) {
//     if(exp == 0) {
//         return 1;
//     } else {
//         if(exp % 2 == 1) {
//             return x * power(x, exp - 1);
//         } else {
//             int y = power(x, exp / 2);
//             return y * y;
//         }
//     }
// }

// int mystery(int n) {
//     if(n < 10) {
//         return n;
//     } else {
//         int a = n / 10;
//         int b = n % 10;
//         return mystery(a + b);
//     }
// }

int main() {
    binaryN(15);
}