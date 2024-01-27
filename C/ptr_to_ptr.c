#include<stdio.h>
#define rows 3
#define cols 3

int main() {
    int arr[rows][cols] = {{7, 8, 9}, {10, 13, 15}, {2, 7, 8}};
    for(int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
        {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    printf("\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            *(*(arr + i) + j) += 10;
            printf("%d\t", *(*(arr + i) + j));
        }
        printf("\n");
    }
}

// In ra một ma trận vuông và cộng mỗi phần tử của ma trận với 10