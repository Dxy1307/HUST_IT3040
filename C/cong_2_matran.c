// Cộng 2 ma trận được cấp phát động
#include <stdio.h>
#include <stdlib.h>

void nhap(int **arr, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            scanf("%d", &arr[i][j]);
        }
    }
}

void xuat(int **arr, int rows, int cols) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols;
    printf("Nhap hang: ");
    scanf("%d", &rows);
    printf("Nhap cot: ");
    scanf("%d", &cols);

    // Cấp phát cho ma trận A
    int **A = (int **)malloc(rows * sizeof(int));
    for(int i = 0; i < rows; i++) {
        A[i] = (int *)malloc(cols * sizeof(int));
    }

    // Cấp phát cho ma trận B
    int **B = (int **)malloc(rows * sizeof(int));
    for(int i = 0; i < rows; i++) {
        B[i] = (int *)malloc(cols * sizeof(int));
    }

    // Cấp phát cho ma trận đích
    int **result = (int **) malloc(rows * sizeof(int));
    for(int i = 0; i < rows; i++) {
        result[i] = (int *) malloc(cols * sizeof(int));
    }

    printf("Nhap ma tran A: \n");
    nhap(A, rows, cols);
    printf("Nhap ma tran B: \n");
    nhap(B, rows, cols);

    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }

    printf("Tong hai ma tran la: \n");
    xuat(result, rows, cols);
    for(int i = 0; i < rows; i++) {
        free(A[i]);
        free(B[i]);
        free(result[i]);
    }
    free(A);
    free(B);
    free(result);
    return 0;
}