#include <bits/stdc++.h>
using namespace std;
#define ii pair<int, int>

int cnt[1000][1000] = {};
queue<ii> q;
int a, b, c;

void push_and_count(int x, int y, int cur_steps) {
    if(x < 0 || y < 0 || x > a || y > b) return;
    if(!cnt[x][y]) {
        q.push({x, y});
        cnt[x][y] = ++cur_steps;
    }
}

void water_jug() {
    int x, y;
    q.push({a, b});
    cnt[a][b] = 1;
    while(!q.empty()) {
        ii u = q.front();
        q.pop();
        x = u.first;
        y = u.second;
        if(x == c || y == c) {
            cout << cnt[x][y];
            return;
        }
        push_and_count(x, 0, cnt[x][y]);
        push_and_count(0, y, cnt[x][y]);
        push_and_count(x, b, cnt[x][y]);
        push_and_count(a, y, cnt[x][y]);

        push_and_count(a, x + y - a, cnt[x][y]);
        push_and_count(x + y, 0, cnt[x][y]);
        push_and_count(x + y - b, b, cnt[x][y]);
        push_and_count(0, x + y, cnt[x][y]);
    }
}

int main() {
    a = 6;
    b = 8;
    c = 4;
    water_jug();
    return 0;
}