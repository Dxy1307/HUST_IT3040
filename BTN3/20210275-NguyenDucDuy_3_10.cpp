// Nguyễn Đức Duy - 20210275
#include<bits/stdc++.h>
using namespace std;
#define MAX 16
int N, H;// xâu có độ dài N, khoảng cách Hamming là H
int x[MAX];// ma trận lưu trữ xâu kết quả
int S[MAX];// ma trận lưu trữ xâu mặc định

// Nhập dữ liệu
void input() {
    cin >> N >> H;
    for(int i = 0; i < N; i++) {
        S[i] = 0;
        x[i] = 0;
    }
}

// Tính khoảng cách hamming của 2 xâu
int hammingDistance(int x[], int S[]) {
    int count = 0;
    for(int i = 0; i < N; i++) {
        if(x[i] != S[i]) count++;
    }
    return count;
}

void solution() {
    for(int i = 0; i < N; i++) {
        cout << x[i];
    }
    cout << endl;
}

// Quay lui
void TRY(int k) {
    for(int i = 0; i <= 1; i++) {
        x[k] = i;
        // Khi xét đủ độ dài xâu
        if(k == N - 1) {
            // Nếu khoảng cách Hamming bằng vs khoảng cách Hamming H cho trước
            // thì in ra
            if(hammingDistance(x, S) == H) {
                solution();
            }
        } else {
            TRY(k + 1);
        }
    }
}

int main() {
    int T;// Số testcase
    cin >> T;
    while(T > 0) {
        input();
        TRY(0);
        cout << endl;
        T--;
    }
}
// Nguyễn Đức Duy - 20210275