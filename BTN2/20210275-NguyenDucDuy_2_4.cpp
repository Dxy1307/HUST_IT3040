// Nguyễn Đức Duy - 20210275
#include <stdio.h>

int cube(int x) {
    //# trả về lập phương của x
    /*****************
    # NGUYEN DUC DUY 20210275 #
    *****************/
    return x * x * x;
}

//# viết hàm tính lập phương của một số kiểu double
/*****************
# NGUYEN DUC DUY 20210275 #
*****************/
double cube(double x) {
    return x * x * x;
}

int main() {
    int n;
    double f;
    scanf("%d %lf", &n, &f);
    
    printf("Int: %d\n", cube(n));// in ra giá trị lập phương của số nguyên
    printf("Double: %.2lf\n", cube(f));// in ra giá trị lập phương của số thực
    
    return 0;
}
// Nguyễn Đức Duy - 20210275