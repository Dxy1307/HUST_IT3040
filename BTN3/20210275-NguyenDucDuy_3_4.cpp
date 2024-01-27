// Nguyễn Đức Duy - 20210275
#include <bits/stdc++.h>
using namespace std;
int a[1000], n;
int mem[1000]; //# mảng ghi nhớ lời giải các bài toán con đã được giải

void init(){
    memset(mem, -1, sizeof(mem));
}

//# Quy hoạch động, 
//# Hàm lis(i) trả về độ dài dãy con tăng dài nhất kết thúc bởi a[i]
int lis(int i) {
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    if(mem[i] != -1) {
        return mem[i];
    }
    int res = 1;
    for(int j = 0; j < i; j++) {
        if(a[j] < a[i]) {
            res = max(res, 1 + lis(j));
        }
    }
    mem[i] = res;
    return res;
}

//# Truy vết lời giải
// Nguyễn Đức Duy - 20210275
void trace(int i){
    for(int j = 0; j < i; j++){
        if (a[j] < a[i] && mem[i] == 1 + mem[j]){
            trace(j);
            break;
        }
    }
    cout << a[i] << " ";
}

int main(){
    init();// khởi tạo mảng ghi nhớ lời giải và mặc định các giá trị bằng -1
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
    int res = 1, pos = 0;
    // Tìm độ dài dãy con tăng nhất lưu vào res, kết thúc tại a[pos]
    for(int i = 1; i < n; i++){
        if (res < lis(i)){
            res = lis(i);
            pos = i;
        }
    }
    cout << res << endl;
    trace(pos);
    return 0;
}
// Nguyễn Đức Duy - 20210275