#include <iostream>
#include <math.h>
using namespace std;

struct SP {
    double real;
    double img;
};

SP setSP(double real, double img) {
    SP tmp;
    tmp.real = real;
    tmp.img = img;
    return tmp;
}
SP addSP(SP C1, SP C2) {
    SP tmp;
    tmp.real = C1.real + C2.real;
    tmp.img = C1.img + C2.img;
    return tmp;
}
SP subSP(SP C1, SP C2) {
    SP tmp;
    tmp.real = C1.real - C2.real;
    tmp.img = C1.img - C2.img;
    return tmp;
}

void display(SP C) {
    cout << C.real << "i " << C.img;
}

int main(void) {
    SP C1, C2, C3, C4;

    C1 = setSP(1.0, 2.0);
    C2 = setSP(-3.0, 4.0);
    cout << "\nSo phuc thu nhat: "; display(C1);
    cout << "\nSo phuc thu hai: "; display(C2);

    C3 = addSP(C1, C2);
    C4 = subSP(C1, C2);
    cout << "\nTong hai so phuc nay: "; display(C3);
    cout << "\nHieu hai so phuc nay: "; display(C4);

    return 0;
}