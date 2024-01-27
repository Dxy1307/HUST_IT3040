// Nguyễn Đức Duy - 20210275
#include<bits/stdc++.h>
using namespace std;
#define MAX 10000
int n, r;// kích thước ma trận nxn, số người đưa ra yêu cầu là r
int price[MAX][MAX];// ma trận chi phí
int x[MAX];
bool visited[MAX];
vector<int> vt;
int min_price;
int sum_price;
int start, destination, numberOfPoint;

void input(){
    cin >> n >> r;
    for(int i=0; i<n; i++)
        for(int j=0; j<n; j++){
            cin >> price[i][j];
        }
}

bool check(int a, int i){
    if(visited[vt[i]]) return false;
    if(price[x[a-1]][vt[i]] == 0) return false;
    return true;
}

void solution(){
    if(price[x[numberOfPoint-2]][destination] == 0) return;
    min_price = min(min_price, sum_price + price[x[numberOfPoint-2]][destination]);
}

void TRY(int a){
    for(int i=1; i<numberOfPoint-1; i++){
        if(check(a, i)){
            visited[vt[i]] = true;
            sum_price += price[x[a-1]][vt[i]];

            x[a] = vt[i];
            if(a == numberOfPoint-2) solution();
            else TRY(a+1);

            visited[vt[i]] = false;
            sum_price -= price[x[a-1]][vt[i]];
        }
    }
}

int main(){
    string str;
    input(); getline(cin,str);

    while(r > 0){
        min_price = INT_MAX;
        sum_price = 0;

        getline(cin, str);

        while (!str.empty()){
            stringstream convert(str.substr(0, str.find(" ")));
            int tmp = 0;
            convert >> tmp;
            vt.push_back(tmp - 1);

            if (str.find(" ") > str.size()){
                break;
            } else {
                str.erase(0, str.find(" ") + 1); // Cập nhật chuỗi
            }
        }

        // Khởi tạo các dữ liệu 
        start = vt[0]; // điểm bắt đầu
        destination = vt[vt.size()-1]; // điểm đích
        numberOfPoint = vt.size(); // số điểm phải đi qua
        x[0] = start; x[numberOfPoint-1] = destination;
        for(int i=0; i<n; i++)
            visited[i] = false;

        TRY(1);

        // in kết quả
        if(min_price == INT_MAX) cout << "0" << endl;
        else cout << min_price << endl;

        // Xóa vector và chuyển sang yêu cầu người tiếp theo
        vt.erase(vt.begin(), vt.end());
        r--;
    }
}
// Nguyễn Đức Duy - 20210275