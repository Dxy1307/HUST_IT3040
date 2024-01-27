#include <iostream>
#include <math.h>
using namespace std;

typedef struct {
    double real;
    double img;
} SP;

SP setSP (double real, double img) {
    SP temp;
    temp.real = real;
    temp.img = img;
    return temp;
}

void display(SP C) {
    cout << C.real << "i " << C.img;
}

SP operator + (SP C1, SP C2) {
    SP temp;
    temp.real = C1.real + C2.real;
    temp.img = C1.img + C2.img;
    return temp;
}

SP operator - (SP C1, SP C2) {
    SP temp;
    temp.real = C1.real - C2.real;
    temp.img = C1.img - C2.img;
    return temp;
}

int main() {
    SP C1, C2, C3, C4;

    C1 = setSP(1.1, 2.0);
    C2 = setSP(-3.0, 4.0);
    cout << "\nSo phuc thu nhat: "; display(C1);
    cout << "\nSo phuc thu hai: "; display(C2);

    C3 = C1 + C2;
    C4 = C1 - C2;
    cout << "\nTong hai so phuc nay: "; display(C3);
    cout << "\nHieu hai so phuc nay: "; display(C4);

    return 0;
}