#include <stdio.h>
#include <stdlib.h>

void nhap(int ***arr, int m, int n, int t) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < t; k++) {
                printf("arr[%d][%d][%d] = ", i, j, k);
                scanf("%d", &arr[i][j][k]);
            }
        }
    }
}

void xuat(int ***arr, int m, int n, int t) {
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            for(int k = 0; k < t; k++) {
                printf("%d\t", arr[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }
}

int main() {
    int m, n, t;
    printf("Nhap m: ");
    scanf("%d", &m);
    printf("Nhap n: ");
    scanf("%d", &n);
    printf("Nhap t: ");
    scanf("%d", &t);

    int ***arr;
    arr = (int ***)malloc(m * sizeof(int));
    for(int i = 0; i < m; i++) {
        arr[i] = (int **)malloc(n * sizeof(int));
        for(int j = 0; j < n; j++) {
            arr[i][j] = (int *)malloc(t * sizeof(int));
        }
    }

    nhap(arr, m, n, t);
    printf("\n");
    xuat(arr, m, n, t);

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            free(arr[i][j]);
        }
        free(arr[i]);
    }
    free(arr);
}