// Nguyễn Đức Duy - 20210275
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
// hàm in ra màn hình
void print_vector(const vector<int> &a) {
    for (int v : a) cout << v << ' ';
    cout << endl;
}

// Hàm xóa các phần tử chẵn
void delete_even(vector<int> &a) {
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    a.erase(remove_if(a.begin(), a.end(), [] (int x) { return x % 2 == 0;}), a.end());
}

// Sắp xếp giảm dần
void sort_decrease(vector<int> &a) {
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    sort(a.rbegin(), a.rend());
}

// Trộn 2 vector
vector<int> merge_vectors(const vector<int> &a, const vector<int> &b) {
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    vector<int> c;
    merge(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c), greater<int>());
    return c;
}

int main() {
    // vector a có m phần tử, vector b có n phần tử
    int m, n, u;
    std::vector<int> a, b;
    
    std::cin >> m >> n;
    for(int i = 0; i < m; i++){
        std:: cin >> u;
        a.push_back(u);// nhập các phần tử trong a
    }
    for(int i = 0; i < n; i++){
        std:: cin >> u;
        b.push_back(u);// nhập các phần tử trong b
    }

    delete_even(a);
    cout << "Odd elements of a: ";
    print_vector(a);

    delete_even(b);
    cout << "Odd elements of b: ";
    print_vector(b);

    sort_decrease(a);
    cout << "Decreasingly sorted a: ";
    print_vector(a);

    sort_decrease(b);
    cout << "Decreasingly sorted b: ";
    print_vector(b);

    vector<int> c = merge_vectors(a, b);
    cout << "Decreasingly sorted c: ";
    print_vector(c);

    return 0;
}
// Nguyễn Đức Duy - 20210275