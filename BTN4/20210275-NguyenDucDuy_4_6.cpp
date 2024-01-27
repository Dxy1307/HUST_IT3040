// Nguyễn Đức Duy - 20210275
#include<iostream>
#include<queue>
#include<conio.h>
#include<vector>
#include<list>
using namespace std;

void bfs(vector< list<int> > adj) {
    queue<int> Q;
    vector<bool> visited(adj.size());
    Q.push(1); // Bắt đầu từ đỉnh số 1
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    visited[1] = true;// đỉnh 1 đã thăm
    while(!Q.empty()) {// nếu queue còn
        int u = Q.front();// lấy ra phần tử đầu tiên trong Q
        Q.pop();// bỏ phần tử đó khỏi Q
        cout << u << endl;// in ra màn hình
        for(int v : adj[u]) {// lặp qua các đỉnh có thể thăm từ u
            if(!visited[v]) {// nếu chưa thăm
                visited[v] = true;// thì thăm
                Q.push(v);// thêm vào Q
            }
        }
    }
    cout << endl;
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
    bfs(adj);
}
// Nguyễn Đức Duy - 20210275