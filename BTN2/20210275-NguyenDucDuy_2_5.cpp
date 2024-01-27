// Nguyễn Đức Duy - 20210275
#include <iostream>
#include <ostream>
#include <math.h>
#include <iomanip> 

using namespace std;

struct Complex {
    double real;
    double imag;
};

Complex operator + (Complex a, Complex b) {
    /*****************
    # NGUYEN DUC DUY 20210275 #
    *****************/
    Complex temp;
    temp.real = a.real + b.real;
    temp.imag = a.imag + b.imag;
    return temp;
}

Complex operator - (Complex a, Complex b) { 
    /*****************
    # NGUYEN DUC DUY 20210275 #
    *****************/
    Complex temp;
    temp.real = a.real - b.real;
    temp.imag = a.imag - b.imag;
    return temp;
}

Complex operator * (Complex a, Complex b) {
    /*****************
    # NGUYEN DUC DUY 20210275 #
    *****************/
    Complex temp;
    temp.real = a.real*b.real - a.imag*b.imag;
    temp.imag = a.real*b.imag + b.real*a.imag;
    return temp;
}

Complex operator / (Complex a, Complex b) {
    /*****************
    # NGUYEN DUC DUY 20210275 #
    *****************/
    b.imag = -b.imag;
    Complex times = operator * (a, b);
    Complex temp;
    double divisor = b.real*b.real + b.imag*b.imag;
    temp.real = times.real / divisor;
    temp.imag = times.imag / divisor;
    return temp;
}

ostream& operator << (ostream& out, const Complex &a) {
    out << '(' << std::setprecision(2) << a.real << (a.imag >= 0 ? '+' : '-') << std::setprecision(2) << fabs(a.imag) << 'i' << ')';
    return out;
}

int main() {
    double real_a, real_b, img_a, img_b;
    cin >> real_a >> img_a;// nhập giá trị số phức thứ 1
    cin >> real_b >> img_b;// nhập giá trị số phức thứ 2
    
    Complex a{real_a, img_a};// khởi tạo số phức 1
    Complex b{real_b, img_b};// khởi tạo số phức 2
    
    cout << a << " + " << b << " = " << a + b << endl;// cộng 2 số phức
    cout << a << " - " << b << " = " << a - b << endl;// trừ 2 số phức
    cout << a << " * " << b << " = " << a * b << endl;// nhân 2 số phức
    cout << a << " / " << b << " = " << a / b << endl;// chia 2 số phức
    
    return 0;
}
// Nguyễn Đức Duy - 20210275