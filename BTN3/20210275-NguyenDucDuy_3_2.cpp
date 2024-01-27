// Nguyễn Đức Duy - 20210275
#include <iostream>
using namespace std;

int n;
int X[100], Y[100]; //# Lưu tọa độ các bước di chuyển của quân mã
int mark[100][100]; //# Đánh dấu vị trí các ô mà quân mã đã di chuyển qua

//# Mảng hx, hy mô tả 8 vị trí quân mã có thể di chuyển kể từ vị trí hiện tại
const int hx[] = {1, 1, 2, 2, -1, -1, -2, -2};
const int hy[] = {2, -2, 1, -1, 2, -2, 1, -1};

//# In ra dãy các di chuyển tìm được
void print_sol(){
    for (int j = 1; j <= n * n; ++j)
        printf("(%d %d)\n", X[j], Y[j]);
    exit(0);
}

//# Thuật toán quay lui
void TRY(int k){
    for(int i = 0; i < 8; i++){
        int xx = X[k-1] + hx[i];// tọa độ x có thể tại lần thứ k
        int yy = Y[k-1] + hy[i];// tọa độ y có thể tại lần thứ k
        /*****************
        # NGUYEN DUC DUY - 20210275 #
        *****************/
        // Nếu tọa độ xx, yy thỏa mãn các điều kiện
        if((!mark[xx][yy]) && (1 <= xx) && (xx <= n) && (1 <= yy) && (yy <= n)) {
            X[k] = xx;// ô thứ k có tọa độ
            Y[k] = yy;// (xx, yy)
            mark[xx][yy] = 1;// tọa độ(xx, yy) đã đi qua
            if(k == n * n) print_sol();// Nếu đã đi qua tất cả các ô thì in ra
            else TRY(k + 1);// không thì quay lui
            mark[xx][yy] = 0;// cập nhật tọa độ(xx, yy) chưa đi qua
        }
    }
}

int main(){
    cin >> n;
    mark[1][1] = 1;
    X[1] = Y[1] = 1;
    TRY(2);
    return 0;
}
// Nguyễn Đức Duy - 20210275