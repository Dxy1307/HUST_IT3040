// Nguyễn Đức Duy - 20210275
#include<stdio.h>
#include<stdlib.h>

void reversearray(int arr[], int size){
    int l = 0, r = size - 1, tmp;
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    while(l < r) {
        tmp = arr[l];
        arr[l] = arr[r];
        arr[r] = tmp;
        l++;
        r--;
    }
}
void ptr_reversearray(int *arr, int size){
    int l = 0, r = size - 1, tmp;
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    while(l < r) {
        tmp = *(arr + l);
        *(arr + l) = *(arr + r);
        *(arr + r) = tmp;
        l++;
        r--;
    }
}

int main()
{
    int size;
    scanf("%d", &size);
    int *arr;
    arr = (int*)malloc(sizeof(int)*size);
    for(int i=0;i<size;i++)
    {
        scanf("%d", &arr[i]);
    }
    ptr_reversearray(arr, size);
    for(int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
}

// Nguyễn Đức Duy - 20210275