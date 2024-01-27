// Nguyễn Đức Duy - 20210275
#include<bits/stdc++.h>
using namespace std;

long long n;
vector<long long> vt;
vector<long long> L; // mảng trái lưu trữ giá trị bên trái gần nhất nhỏ hơn giá trị đang xét
vector<long long> R; // mảng phải lưu trữ giá trị bên phải gần nhất nhỏ hơn giá trị đang xét

void inputData(){
    cin >> n;
    vt.push_back(-1); // Đặt lính canh ở 2 đầu mảng
    for(long long i=0; i<n; i++){
        long long tmp;
        cin >> tmp;
        vt.push_back(tmp);
    }
    vt.push_back(-1); // Đặt lính canh ở 2 đầu mảng
}

void solve(){
    while(true){
        inputData();
        if(n==0) return;

        // Xử lý
        stack<long long> st; // stack để thực hiện thuật toán ghi ra các giá trị L, R
        L.resize(n+2);
        R.resize(n+2);
        for(long long i=1; i<=n+1; i++){
            while(!st.empty() && vt[i] < vt[st.top()]){
                L[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        for(long long i=n; i>=0; i--){
            while(!st.empty() && vt[i] < vt[st.top()]){
                R[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }

        long long maxh = 0;
        for(long long i=1; i<=n; i++){
            long long h = (L[i] - R[i] -1)*vt[i];
            if(h > maxh) maxh = h;
        }

        cout << maxh << endl; break;

        // xóa mảng trước khi bắt đầu vòng lặp mới
        vt.erase(vt.begin(),vt.end());
        L.erase(L.begin(),L.end());
        R.erase(R.begin(),R.end());
    }
}

int main(){
    solve();
    return 0;
}
// Nguyễn Đức Duy - 20210275