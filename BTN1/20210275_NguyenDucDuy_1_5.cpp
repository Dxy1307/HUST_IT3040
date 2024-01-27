// Nguyễn Đức Duy - 20210275
#include<stdio.h>
#include<stdlib.h>
double* maximum(double* a, int size){

    double *max;

    max = a;

    if (a==NULL) return NULL;
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    for(double *p = a + 1; p < a + size; p++) {
        if(*p > *max) {// Nếu giá trị phần tử trỏ bởi p lớn hơn giá trị trỏ bởi max
            max = p;// max trỏ tới phần tử mà p đang trỏ tới
        }
    }
    return max;
}

int main()
{
    int size;
    scanf("%d", &size);
    double *arr;
    arr = (double*)malloc(sizeof(double)*size);
    for(int i=0;i<size;i++)
    {
        scanf("%lf", &arr[i]);
    }
    printf("%lf", *maximum(arr, size));
}

// Nguyễn Đức Duy - 20210275