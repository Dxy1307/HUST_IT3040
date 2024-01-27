// Nguyễn Đức Duy - 20210275
#include <stdio.h>
#include <math.h>

float get_hypotenuse(float x, float y) {
    /*****************
    # NGUYEN DUC DUY 20210275 #
    *****************/
    return sqrt(x*x + y*y);// công thức tính độ dài cạnh huyền
}

int main(){
    float x, y;
    scanf("%f%f", &x, &y);// Nhập x, y
    
    float z = get_hypotenuse(x, y);// z là độ dài cạnh huyền
    printf("z = %.2f\n", z);
    
    return 0;
}
// Nguyễn Đức Duy - 20210275