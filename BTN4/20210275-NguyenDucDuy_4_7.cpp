// Nguyễn Đức Duy - 20210275
#include <iostream>
#include <set>

using namespace std;

template<class T>
// hàm thực hiện phép hợp
set<T> set_union(const set<T> &a, const set<T> &b) {
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    set<T> c = a;// tạo set c giống set a
    c.insert(b.begin(), b.end());// thêm toàn bộ phần tử trong set b vào set c
                                 // set không cho các phần tử trùng nhau 
    return c;// trả lại set c
}

template<class T>
// hàm thực hiện phép giao
set<T> set_intersection(const set<T> &a, const set<T> &b) {
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    set<T> c;// tạo set c rỗng
    for(const T &x : a) {// lặp qua các phần tử trong set a
        if(b.find(x) != b.end()) {// nếu x tồn tại trong b
            c.insert(x);// thêm x vào set c
        }
    }
    return c;// trả lại set c
}

template<class T>
void print_set(const set<T> &a) {
    for (const T &x : a) {
        cout << x << ' ';
    }
    cout << endl;
}

int main() {
    set<int> a = {1, 2, 3, 5, 7};
    set<int> b = {2, 4, 5, 6, 9};
    set<int> c = set_union(a, b);
    set<int> d = set_intersection(a, b);
    
    cout << "Union: "; print_set(c);
    cout << "Intersection: "; print_set(d);

    return 0;
}
// Nguyễn Đức Duy - 20210275