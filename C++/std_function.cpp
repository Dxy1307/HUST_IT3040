#include <iostream>
#include <functional>
using namespace std;

int add(int a, int b) {
    return a + b;
}

int main() {
    std::function<int(int, int)> func = add;
    int result = func(3, 5);
    cout << result << endl;
}