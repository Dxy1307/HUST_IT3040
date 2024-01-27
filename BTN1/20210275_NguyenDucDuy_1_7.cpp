// Nguyễn Đức Duy - 20210275
#include <stdio.h>
#include<stdlib.h>
int *a;
int n, tmp;

int main(){
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    
    //#Allocate memory
    a = (int*)malloc(n * sizeof(int));
    if(a == NULL) return 0;
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    for(int i = 0; i < n; i++)
        scanf("%d", a + i); 
    
    printf("The input array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    //#Sort array
    for(int i = 0; i < n; i++) {
        for(int j = i; j < n; j++) {
            if(*(a + i) > *(a + j)) {
                tmp = *(a + i);
                *(a + i) = *(a + j);
                *(a + j) = tmp;
            }
        }
    }
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    
    printf("The sorted array is: \n");
    for(int i = 0; i < n; i++)
        printf("%d ", *(a + i));
    printf("\n");
    
    free(a);
    return 0;
}
// Nguyễn Đức Duy - 20210275