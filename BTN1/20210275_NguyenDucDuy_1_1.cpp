// Nguyễn Đức Duy - 20210275
#include <stdio.h>
int main(){
    int x, y, z;
    int* ptr;
    printf("Enter three integers: ");
    scanf("%d %d %d", &x, &y, &z);
    printf("\nThe three integers are:\n");
    ptr = &x;// gan dia chi cua bien x cho con tro ptr
    printf("x = %d\n", *ptr);
    
    /*****************
    # NGUYEN DUC DUY -20210275 #
    *****************/
    ptr = &y;// gan dia chi cua bien y cho con tro ptr
    printf("y = %d\n", *ptr);
    ptr = &z;// gan dia chi cua bien z cho con tro ptr
    printf("z = %d\n", *ptr);
    
    return 0;
}
// Nguyễn Đức Duy - 20210275