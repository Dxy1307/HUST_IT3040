// Khuôn mẫu hàm là một cái khuôn dùng để tạo ra nhiều hàm có định nghĩa giống nhau. Và có thể được tái sử dụng nhiều lần nếu chúng ta muốn.
// Khi hàm khuôn mẫu được gọi, compiler sẽ tạo ra một bản sao của hàm đó, và thay thế kiểu dữ liệu tương ứng của các tham số khuôn mẫu

#include <iostream>
#include <math.h>
using namespace std;

// typedef struct {
//     double real;
//     double img;
// } SP;

// SP setSP (double real, double img) {
//     SP temp;
//     temp.real = real;
//     temp.img = img;
//     return temp;
// }

// void display(SP C) {
//     cout << C.real << "i " << C.img;
// }

// template <typename T>
// SP operator + (SP a, T b) {
//     SP temp;
//     temp.real = a.real + b;
//     temp.img = a.img;
//     return temp;
// }

// int main() {
//     SP a;
//     a = setSP(1.0, 2.0);
//     SP b;
//     b = a + 2.5;
//     cout << "So phuc b la: "; display(b);
// }

// Example
template <typename T1, typename T2>
T2 maxval(T1 x, T2 y) {
    return (x > y) ? x : y;
}

int main() {
    int i = maxval(3, 7);
    cout << i << endl;
    double d = maxval(6.34, 18.524);
    cout << d << endl;
    int ch = maxval('a', 6);
    cout << ch << endl;
    double a = maxval(6, 5.4);
    cout << a << endl;
    return 0;
}