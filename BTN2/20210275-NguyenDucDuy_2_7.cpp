// Nguyễn Đức Duy - 20210275
#include <iostream>
using namespace std;

//# viết hàm arr_sum
/*****************
# NGUYEN DUC DUY 20210275 #
*****************/
template<typename T>
T arr_sum(T a[], int m, T b[], int n) {// tính tổng các phần tử trong mảng a và mảng b
    T c = 0;
    for(int i = 0; i < m; i++) {
        c += a[i];// cộng các phần tử trong mảng a
    }
    for(int i = 0; i < n; i++) {
        c += b[i];// cộng các phần tử trong mảng b
    }
    return c;
}

int main() {
    int val;
    cin >> val;// nhập giá trị val từ bán phím
    
    {
        int a[] = {3, 2, 0, val};
        int b[] = {5, 6, 1, 2, 7};
        cout << arr_sum(a, 4, b, 5) << endl;// tổng các phần tử trong 2 mảng số nguyên
    }
    {
        double a[] = {3.0, 2, 0, val * 1.0};
        double b[] = {5, 6.1, 1, 2.3, 7};
        cout << arr_sum(a, 4, b, 5) << endl;// tổng các phần tử trong 2 mảng số thực
    }

    return 0;
}
// Nguyễn Đức Duy - 20210275