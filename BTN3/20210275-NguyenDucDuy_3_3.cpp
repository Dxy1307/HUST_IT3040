// Nguyễn Đức Duy - 20210275
#include <bits/stdc++.h>
using namespace std;
#define MAX 100  

int n, c[MAX][MAX]; //# số thành phố và ma trận chi phí
int cmin = INT_MAX; //# chi phí đi lại nhỏ nhất giữa hai thành phố khác nhau
int best = INT_MAX; //# tổng chi phí nhỏ nhất cần tìm, ban đầu đặt bằng giá trị vô cùng lớn INT_MAX = 2^31-1
int curr; //# tổng chi phí tới thời điểm hiện tại
int mark[MAX]; //# đánh dấu những thành phố đã đi
int x[MAX]; //# lưu giữ các thành phố đã đi

//# Đọc dữ liệu vào
void input(){
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j){
            cin >> c[i][j];
            if (c[i][j] > 0) cmin = min(cmin, c[i][j]);// tìm cmin
        }
}

//# Thuật toán quay lui
void TRY(int k){
    for(int i = 2; i <= n; i++){
        /*****************
        # NGUYEN DUC DUY - 20210275 #
        *****************/
        // Nếu thành phố i chưa đi
        if(!mark[i]) {
            x[k] = i;// lưu thành phố thứ k là i
            mark[i] = 1;// thành phố i đã đi
            curr += c[x[k-1]][i];// cập nhật chi phí
            if(k == n) best = min(best, curr + c[i][1]);// Nếu đã đi hết các thành phố
                                                        // thì cập nhật chi phí tốt nhất
            else if(curr + cmin * (n - k + 1) < best) TRY(k + 1);// Kiểm tra xem chi phí nhỏ nhất đã tối ưu
                                                                 // chưa, nếu không thì quay lui
            mark[i] = 0;// cập nhật thành phố i chưa đi
            curr -= c[x[k-1]][i];// cập nhật chi phí
        }
    }
}

int main() {
    input();
    x[1] = 1;
    TRY(2);
    cout << best;
    return 0;
}
// Nguyễn Đức Duy - 20210275