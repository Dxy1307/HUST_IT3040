// Nguyễn Đức Duy - 20210275
#include <iostream>
using namespace std;

// Đệ quy
int binom(int n, int k) {
    if (k > n) return 0;
    if (k == 0) return 1;// C(n, 0) = 1
    return binom(n-1, k) + binom(n-1, k-1);// C(n, k) = C(n-1, k) + C(n-1, k-1)
}

int c[1000][1000];// mảng lưu trữ các C(n, k)
int binom2(int n, int k){
    //# Khử đệ quy
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    for(int i = 0; i <= n; i++) {
        c[i][0] = 1;// C(n, 0) = 1
        for(int j = 1; j <= i; j++) {
            c[i][j] = c[i-1][j] + c[i-1][j-1];// C(n, k) = C(n-1, k) + C(n-1, k-1)
        }
    }
    return c[n][k];
}

int main() {
    int m;
    cin >> m;
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom(n, k));
        printf("\n");
    }
    for (int n = 1; n <= m; ++n){
        for (int k = 0; k <= n; ++k)
            printf("%d ", binom2(n, k));
        printf("\n");
    }
    return 0;
}
// Nguyễn Đức Duy - 20210275