// Nguyễn Đức Duy - 20210275
#include<iostream>
#include<stack>
#include<conio.h>
#include<vector>
#include<list>
using namespace std;

void dfs(vector< list<int> > adj) {
    stack<int> S;
    vector<bool> visited(adj.size());
    S.push(1); // Bắt đầu từ đỉnh số 1
    
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    while(!S.empty()) {// nếu stack còn
        int u = S.top();// lấy phần tử ở đỉnh stack
        if(!visited[u]) {// nếu chưa thăm
            visited[u] = true;// thì thăm
            cout << u << endl;
        }
        if(!adj[u].empty()) {// nếu từ u chưa thăm hết các điểm có thể thăm từ u
            int v = adj[u].front();// lấy phần tử đầu tiên còn có thể thăm từ u
            adj[u].pop_front();// xóa khỏi list u
            if(!visited[v]) {// nếu chưa thăm
                S.push(v);// thêm vào stack
            }
        } else {// khi đã hết đỉnh có thể thăm từ u
            S.pop();// xóa u khỏi stack
        }
    }
}

int main() {
    int n = 7;
    vector< list<int> > adj;
    adj.resize(n + 1);
    adj[1].push_back(2);
    adj[2].push_back(4);
    adj[1].push_back(3);
    adj[3].push_back(4);
    adj[3].push_back(5);
    adj[5].push_back(2);
    adj[2].push_back(7);
    adj[6].push_back(7);
    dfs(adj);
}
// Nguyễn Đức Duy - 20210275