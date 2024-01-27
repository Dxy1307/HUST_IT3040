// Nguyễn Đức Duy - 20210275
#include<stdio.h>
#include<stdlib.h>

int counteven(int* arr, int size){
    int count = 0;
    
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    for(int i = 0; i < size; i++) {
        if(*(arr + i) % 2 == 0) count++;// Nếu giá trị của phần tử trỏ bởi con trỏ arr là chẵn thì cộng count thêm 1
    }
    return count;    
}

int main()
{
    int size ;
    scanf("%d", &size);
    int *arr;
    arr = (int*)malloc(sizeof(int)*size);
    for(int i =0 ; i< size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("%d", counteven(arr, size));
}

// Nguyễn Đức Duy - 20210275