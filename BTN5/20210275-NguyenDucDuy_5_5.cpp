// Nguyễn Đức Duy - 20210275
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    bool found = false;
    while(n--){
        int a;
        cin >> a;
        // if ((a % 4 == 0 && a % 100 != 0) || (a % 400 == 0))
        //     found = true;
        if(a % 400 == 0) {
            found = true;
        } else if(a % 100 == 0) {
            
        } else if(a % 4 == 0) {
            found = true;
        }
    }
    if (found) cout << "Yes";
    else cout << "No";
}
// Nguyễn Đức Duy - 20210275