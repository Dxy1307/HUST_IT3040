// Đối với biến: auto xác định kiểu của biến được khởi tạo một cách tự động từ giá trị khởi tạo của biến
// Đối với hàm auto tự động xác định kiểu trả về của hàm dựa vào câu lệnh return
// Đối với kiểu tham số auto tự động xác định kiểu của tham số dựa vào giá trị được truyền

#include <iostream>
using namespace std;

auto maxval(auto x, auto y) {
    return (x > y) ? x : y;
}

auto divide(double x, double y) {
    return x / y;
}

int main() {
    auto x {divide(9, 5)};
    cout << x << endl;
    return 0;    
}