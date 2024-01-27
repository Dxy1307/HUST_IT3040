// Nguyễn Đức Duy - 20210275
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int main() {
    int val1, val2;
    cin >> val1 >> val2;
    vector< vector<int> > a = {
        {1, 3, 7},
        {2, 3, 4, val1},
        {9, 8, 15},
        {10, val2},
    };

    //# sắp xếp các vector trong a theo tổng các phần tử giảm dần
    /*****************
    # NGUYEN DUC DUY 20210275 #
    *****************/
    sort(a.begin(), a.end(), [] (const vector<int> &p, const vector<int> &q) {
        return accumulate(p.begin(), p.end(), 0) > accumulate(q.begin(), q.end(), 0);
    });

    for (const auto &v : a) {
        for (int it : v) {
            cout << it << ' ';
        }
        cout << endl;
    }
    return 0;
}
// Nguyễn Đức Duy - 20210275