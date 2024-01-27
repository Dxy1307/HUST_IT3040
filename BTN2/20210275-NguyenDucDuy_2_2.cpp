// Nguyễn Đức Duy - 20210275
#include <stdio.h>

void rotate(int &x, int &y, int &z) {
    /*****************
    # NGUYEN DUC DUY 20210275 #
    *****************/
    int t = x; // dùng biến trung gian t để hoán vị vòng tròn
    x = y;
    y = z;
    z = t;
}

int main() {
    int x, y, z;
    
    //# Nhập 3 số nguyên
    /*****************
    # NGUYEN DUC DUY 20210275 #
    *****************/
    scanf("%d %d %d", &x, &y, &z);
    
    printf("Before: %d, %d, %d\n", x, y, z);
    rotate(x, y, z);// hoán vị vòng tròn
    printf("After: %d, %d, %d\n", x, y, z);
    
    return 0;
}
// Nguyễn Đức Duy - 20210275