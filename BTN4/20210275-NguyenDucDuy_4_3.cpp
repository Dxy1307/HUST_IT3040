// Nguyễn Đức Duy - 20210275
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
using Vector = tuple<double, double, double>;

Vector cross_product(Vector a, Vector b) {
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    return Vector(
        get<1>(a) * get<2>(b) - get<2>(a) * get<1>(b),
        get<2>(a) * get<0>(b) - get<0>(a) * get<2>(b),
        get<0>(a) * get<1>(b) - get<1>(a) * get<0>(b)
    );
}

int main() {
    cout << setprecision(2) << fixed;
    Vector a {1.2, 4, -0.5};
    Vector b {1.5, -2, 2.5};
    Vector c = cross_product(a, b);
    cout << get<0>(c) << ' ' << get<1>(c) << ' ' << get<2>(c) << endl;
    return 0;
}
// Nguyễn Đức Duy - 20210275