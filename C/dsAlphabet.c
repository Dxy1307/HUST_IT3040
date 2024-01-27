#include<stdio.h>
#include<string.h>
#define MAXHS 50
#define MAXLEN 30

int main() {
    int cnt = 0, n = 2;
    char ds[MAXHS][MAXLEN];
    char *ptr[MAXHS], *tmp;
    while (cnt < n)
    {
        printf("Enter the name of student %d: ", cnt + 1);
        gets(ds[cnt]);
        if(strlen(ds[cnt]) == 0) break;
        ptr[cnt] = ds[cnt];
        ++cnt;
    }
    for(int i = 0; i < n - 1; i++)
        for(int j = i + 1; j < n; j++)
            if(strcmp(ptr[i], ptr[j]) > 0) {
                tmp = ptr[i];
                ptr[i] = ptr[j];
                ptr[j] = tmp;
            }
    
    for(int i = 0; i < n; i++) {
        printf("\n %d : %s", i + 1, ptr[i]);
    }
    return 0;
}

// nhập vào tên học sinh và in ra danh sách theo ABC