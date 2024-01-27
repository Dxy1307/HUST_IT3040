// Cấp phát động mảng 2 chiều bằng cách dùng con trỏ cấp 2
/*
Để cấp phát động cho mảng 2 chiều, ta cấp phát bộ nhớ của từng chiều theo
cú pháp của mảng một chiều. Tức là tạo m mảng 1 chiều, mỗi mảng có n phần tử

Để làm điều này ta dùng 1 con trỏ cấp 2, cấp phát cho nó m con trỏ cấp 1, mỗi con
trỏ cấp 1 ta lại cấp phát n phần tử.
*/

#include <stdio.h>
#include <stdlib.h>

void nhap(int **arr, int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("arr[%d][%d] = ", i, j);
            scanf("%d", &arr[i][j]);
        }
    }
}

void xuat(int **arr, int m, int n) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int m, n;
    printf("Nhap hang: ");
    scanf("%d", &m);
    printf("Nhap cot: ");
    scanf("%d", &n);

    int **arr;
    arr = (int **)malloc(m * sizeof(int));
    for(int i = 0; i < m; i++) {
        arr[i] = (int *)malloc(n * sizeof(int));
    }

    nhap(arr, m, n);
    xuat(arr, m, n);

    for(int i = 0; i < m; i++) {
        free(arr[i]);
    }
    free(arr);
}