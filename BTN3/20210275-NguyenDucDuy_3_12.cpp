// Nguyễn Đức Duy - 20210275
#include<bits/stdc++.h>
using namespace std;
#define MAX 100
int n, k;// Số đỉnh là n, số cạnh đi qua là k
int m;// số cạnh của đồ thị là m
vector<vector<int> > vt;// Chuyển từ lưu trữ các cạnh sang lưu trữ danh sách kề
int x[MAX];// lưu trữ thứ tự đi qua các đỉnh
bool visited[MAX];// lưu trữ đỉnh nào được đi qua
int res;// số lượng đường đi độ dài k

void input(){
    cin >> n >> k;
    cin >> m;
    vt.resize(n+1);
    for(int i=0; i<m; i++){
        int tmp1, tmp2;
        cin >> tmp1 >> tmp2;// nhập các cạnh của đồ thị

        vt[tmp1-1].push_back(tmp2-1); // đỉnh tmp2 kề với đỉnh tmp1
        vt[tmp2-1].push_back(tmp1-1); // đỉnh tmp1 kề với đỉnh tmp2
    }

    for(int i=0; i<n; i++){
        visited[i] = false;// mặc định các đỉnh chưa được thăm
    }
    res = 0;
}

bool check(int a, int i){
    if(a == 0) return true;// Lần đầu luôn đúng
    if(visited[i]) return false;// nếu i đã thăm thì thôi

    // Kiểm tra xem đỉnh trước đấy có kề với đỉnh i không
    for(int j=0; j<vt[x[a-1]].size(); j++){
        if(i == vt[x[a-1]][j]) return true;
    }

    return false;
}

// Tăng số lượng đường đi lên 1
void solution(){
    res++;
}

// Quay lui
void TRY(int a){
    for(int i=0; i<n; i++){
        // Kiểm tra lần thứ a đi qua i có hợp lệ không
        if(check(a, i)){
            visited[i] = true;
            x[a] = i;

            if(a == k) solution();
            else TRY(a+1);

            visited[i] = false;
        }
    }
}

int main(){
    input();
    TRY(0);
    cout << res / 2;// số lượng đường đi đơn độ dài k
}
// Nguyễn Đức Duy - 20210275