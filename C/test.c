#include <stdio.h>
#include <math.h>

double func(double x) {
    return pow(x, 4) + 2 * pow(x, 3) + 1;
}

double forwardDifference(double x, double h) {
    return (func(x + h) - func(x)) / h;
}

int main() {
    double x = 2.0;
    double h = 0.01;

    double derivative = forwardDifference(x, h);

    printf("Dao ham tai diem x = %.2f la: %.6f\n", x, derivative);

    return 0;
}
