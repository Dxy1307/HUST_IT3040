// Nguyễn Đức Duy - 20210275
#include <stdio.h>

void print(int n) {
    printf("n=%d\n", n);// in ra màn hình n
}

int mul3plus1(int n) {
    return n * 3 + 1;// trả lại giá trị n nhân 3 cộng 1
}

int div2(int n) {
    return n / 2;// trả lại giá trị n chia 2
}

// khai báo các tham số cho các con trỏ hàm odd, even và output
void simulate(int n, int (*odd)(int), int (*even)(int), void (*output)(int)) {
                     /************# NGUYEN DUC DUY 20210275 #************/
    (*output)(n);
    if (n == 1) return;// nếu n = 1 thì kết thúc
    if (n % 2 == 0) {
        n = (*even)(n);// nếu n là số chẵn thì gán n bằng giá trị hàm even trả về
    } else {
        n = (*odd)(n);// nếu n là số lẻ thì gán n bằng giá trị hàn odd trả về
    }
    simulate(n, odd, even, output);// gọi lại hàm simulate với n mới
}

int main() {
    int (*odd)(int) = NULL;
    int (*even)(int) = NULL;

    /*****************
    # NGUYEN DUC DUY 20210275 #
    *****************/
    
    odd = mul3plus1;// odd trỏ đến hàm mul3plus1
    even = div2;// even trỏ đến hàm div2

    int n;
    scanf("%d", &n);// nhập n
    simulate(n, odd, even, print);// gọi hàm simulate

    return 0;
}
// Nguyễn Đức Duy - 20210275