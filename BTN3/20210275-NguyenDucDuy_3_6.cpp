// Nguyễn Đức Duy - 20210275
#include <iostream>
using namespace std;

int gcd(int a, int b){
    if (b == 0) return a;// Nếu b = 0 thì trả lại a
    return gcd(b, a % b);// nếu không thì đệ quy với b và số dư của a cho b
}

int gcd2(int a, int b){
    
    //# Khử đệ quy
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    while(b) {// Nếu b khác 0
        a %= b; // thì a bằng số dư của a cho b
        swap(a, b);// đổi chỗ a và b
    }
    return a;
}

int main() {
    int a, b;
    cin >> a >> b;
    cout << gcd(a, b) << endl << gcd2(a, b);
    return 0;
}
// Nguyễn Đức Duy - 20210275