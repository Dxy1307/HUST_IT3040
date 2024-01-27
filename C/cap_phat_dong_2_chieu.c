// Cấp phát động mảng 2 chiều
#include <stdio.h>
#include <stdlib.h>

void nhap(int *arr, int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", (arr + n*i + j));
        }
    }
}

void xuat(int *arr, int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d\t", *(arr + n*i + j));
        }
        printf("\n");
    }
}

int main() {
    int m, n;
    printf("Nhap so hang: ");
    scanf("%d", &m);
    printf("Nhap so cot: ");
    scanf("%d", &n);

    int *arr;
    arr = (int*)malloc(m * n * sizeof(int));

    nhap(arr, m, n);
    xuat(arr, m, n);
    free(arr);
}