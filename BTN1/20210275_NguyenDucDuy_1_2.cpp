// Nguyễn Đức Duy - 20210275
#include <stdio.h>
int main(){
    int a[7]= {13, -355, 235, 47, 67, 943, 1222};
    printf("\n Nguyen Duc Duy - 20210275 \n");
    printf("address of first five elements in memory.\n");
    for (int i = 0; i < 5; i++)  printf("\t\ta[%d] ",i);
    printf("\n");
    
    /*****************
    # NGUYEN DUC DUY 20210275 #
    *****************/

    for (int i = 1;i <= 5; i++) printf("\t   %p", &a[i]);
    printf("\n");
    return 0;
}
// Nguyễn Đức Duy - 20210275