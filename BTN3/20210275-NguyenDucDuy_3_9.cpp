// Nguyễn Đức Duy - 20210275
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int n, k1, k2;// lịch làm việc trong n ngày, làm liên tục tối thiểu k1 ngày
              // tối đa k2 ngày
int x[MAX];// ma trận nhị phân tương ứng ngày i đi làm hoặc không
int count1 = 0;// đếm số ngày làm liên tiếp sau 1 ngày nghỉ

// Nhập dữ liệu
void inputData() {
    cin >> n >> k1 >> k2;
}

// Kiểm tra xem ngày thứ a được phép làm gì
bool check(int a, int i) {
    if(a == 1) return true;// nếu là ngày đầu tiên thì làm gì cũng được
    else {
        // Nếu ngày a được nghỉ
        if(i == 0) {
            // Ngày trước đó không được nghỉ 
            if(x[a - 1] == 0) return false;
            else {
                // Số ngày đi làm liên tiếp phải tối thiểu
                if(count1 < k1) return false;
            }
        // Nếu ngày a đi làm
        } else {
            // nếu ngày trước đó được nghỉ
            if(x[a - 1] == 0) {
                // Từ ngày a đến ngày n phải đủ tối thiểu số buổi
                if(n - a + 1 < k1) return false;
            // Nếu ngày trước đó đi làm
            } else {
                // Số ngày đi làm liên tiếp không vượt quá tối đa
                if(count1 >= k2) return false;
            }
        }
        return true;
    }
}

// In ra màn hình kết quả
void solution() {
    for(int i = 1; i <= n; i++) {
        cout << x[i];
    }
    cout << endl;
}

// Quay lui
void TRY(int a) {
    for(int i = 0; i <= 1; i++) {
        if(check(a, i)) {
            x[a] = i;
            int preCount1 = count1;
            // Nếu ngày a đi làm
            if(i == 1) {
                // và ngày trước đấy đi làm
                if(x[a - 1] == 1) count1++;// tăng bộ đếm số ngày đi làm liên tiếp
                else count1 = 1;// còn không thì bộ đếm = 1
            // nếu ngày a nghỉ
            } else {
                count1 = 0;// bộ đếm = 0
            }

            if(a == n) solution();
            else TRY(a + 1);

            count1 = preCount1;
        }
    }
}

int main() {
    inputData();
    TRY(1);
    return 0;
}
// Nguyễn Đức Duy - 20210275