// Nguyễn Đức Duy - 20210275
#include <stdio.h>

//# Viết hàm get_value
/*****************
# NGUYEN DUC DUY 20210275 #
*****************/
int get_value(int x, int a = 2, int b = 1, int c = 0) {
    return a*x*x + b*x + c;
}

int main(){
    int x;
    scanf("%d", &x);// Nhập x
    
    int a = 2; //# giá trị mặc định của a
    int b = 1; //# giá trị mặc định của b
    int c = 0; //# giá trị mặc định của c
    
    //# Nhập 3 số nguyên a, b, c từ bàn phím
    /*****************
    # NGUYEN DUC DUY 20210275 #
    *****************/
    scanf("%d %d %d", &a, &b, &c);
    
    printf("a=2, b=1, c=0: %d\n", get_value(x));// trả lại kết quả với giá trị a, b, c mặc định
    printf("a=%d, b=1, c=0: %d\n", a, get_value(x, a)); // trả lại kết quả với a nhập từ bàn phím
    printf("a=%d, b=%d, c=0: %d\n", a, b, get_value(x, a, b));// trả lại kết quả với a, b nhập từ bàn phím
    printf("a=%d, b=%d, c=%d: %d\n", a, b, c, get_value(x, a, b, c));// trả lại kết quả với a, b, c nhập từ
                                                                     // bàn phím
    
    return 0;
}
// Nguyễn Đức Duy - 20210275