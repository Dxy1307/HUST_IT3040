// Nguyễn Đức Duy - 20210275

#include <stdio.h>

int main() {

    int x, y, z;

    int *ptr;

    scanf("%d %d %d", &x, &y, &z);// Nhập 3 số nguyên x, y, z

    printf("Here are the values of x, y, and z:\n");

    printf("%d %d %d\n", x, y, z);



    /*****************

    # NGUYEN DUC DUY - 20210275 #

    *****************/
    ptr = &x;// gán địa chỉ của x cho con trỏ ptr
    *ptr += 100;// tăng giá trị của biến trỏ bởi ptr lên 100
    
    ptr = &y;// gán địa chỉ của y cho con trỏ ptr
    *ptr += 100;// tăng giá trị của biến trỏ bởi ptr lên 100
    
    ptr = &z;// gán địa chỉ của z cho con trỏ ptr
    *ptr += 100;// tăng giá trị của biến trỏ bởi ptr lên 100

    printf("Once again, here are the values of x, y, and z:\n");

    printf("%d %d %d\n", x, y, z);

    return 0;

}  
// Nguyễn Đức Duy - 20210275