// Cấp phát động mảng 1 chiều
#include <stdio.h>
#include <stdlib.h>

void nhap(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", (arr + i));
    }
}

void xuat(int *arr, int n) {
    for(int i = 0; i < n; i++) {
        printf("arr[%d] = %d\n", i, *(arr + i));
    }
}

int main() {
    int n;
    printf("Nhap n = ");
    scanf("%d", &n);
    
    int *arr;
    arr = (int*)malloc(n * sizeof(int));

    nhap(arr, n);
    printf("\nMang vua nhap la:\n");
    xuat(arr, n);

    free(arr);
}