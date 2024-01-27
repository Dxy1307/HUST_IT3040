// Nguyễn Đức Duy - 20210275
#include <iostream>
#include <cmath>
#include <iomanip>
#include <utility>
using namespace std;
using Point = pair<double, double>;

double area(Point a, Point b, Point c) {
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    return  fabs((c.first - a.first) * (b.second - a.second) - 
            (b.first - a.first) * (c.second - a.second)) / 2;
}

int main() {
    cout << setprecision(2) << fixed;
    cout << area({1, 2}, {2.5, 10}, {15, -5.25}) << endl;
    return 0;
}
// Nguyễn Đức Duy - 20210275