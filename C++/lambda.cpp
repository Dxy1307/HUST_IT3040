#include <iostream>
using namespace std;

// void studio_doing(int n) {
//     n = n + 10;
//     cout << n << " ";
// }

void for_each(int *arr, int n, void (*func) (int)) {
    for(int i = 0; i < n; i++) {
        func(*(arr + i));
    }
}

int main() {
    // int arr[] = {1, 2, 3, 4, 5};
    // int n = 5;
    // for_each(arr, n, [] (int a) {
    //     a += 10;
    //     cout << a << " ";
    // });
    // return 0;

    // auto y = [] (int first, int second) {
    //     return first + second;
    // };

    // auto x = [] (int i) -> int {
    //     return i;
    // };

    // cout << x(2) << endl;
    // cout << x(3) << endl;
    // cout << y(1, 2) << endl;

    int m = 0; 
    int n = 0;
    auto func = [&, n] (int a) mutable {
        m = ++n + a;
        cout << m << " " << n << " " << a << endl;
    };
    func(4);
    cout << m << " " << n << endl;
}