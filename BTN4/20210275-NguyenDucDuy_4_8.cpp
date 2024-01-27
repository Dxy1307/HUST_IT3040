// Nguyễn Đức Duy - 20210275
#include <iostream>
#include <map>

using namespace std;

template<class T>
// hàm thực hiện phép giao
map<T, double> fuzzy_set_union(const map<T, double> &a, const map<T, double> &b) {
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    map<T, double> c = a;// tạo map c giống map a
    for(const auto &e : b) {// lặp qua các phần tử trong map b
        if(c.count(e.first)) {// nếu key của phần tử e đã xuất hiện trong c
            c[e.first] = max(c[e.first], e.second);// cập nhật phần tử có value max
        } else {
            c.insert(e);// nếu chưa xuất hiện thì thêm vào c
        }
    }
    return c;// trả lại c
}

template<class T>
// hàm thực hiện phép hợp
map<T, double> fuzzy_set_intersection(const map<T, double> &a, const map<T, double> &b) {
    /*****************
    # NGUYEN DUC DUY - 20210275 #
    *****************/
    map<T, double> c;// tạo map c rỗng
    for(const auto &x : a) {// lặp qua các phần tử trong a
        const auto it = b.find(x.first);
        if(it != b.end()) {// nếu key của phần tử x cũng xuất hiện trong b
            c[x.first] = min(x.second, it -> second);// cập nhật value min
        }
    }
    return c;// trả lại c
}

template<class T>
void print_fuzzy_set(const std::map<T, double> &a) {
    cout << "{ ";
    for (const auto &x : a) {
        std::cout << "(" << x.first << ", " << x.second << ") ";
    }
    cout << "}";
    std::cout << std::endl;
}

int main() {
    std::map<int, double> a = {{1, 0.2}, {2, 0.5}, {3, 1}, {4, 0.6}, {5, 0.7}};
    std::map<int, double> b = {{1, 0.5}, {2, 0.4}, {4, 0.9}, {5, 0.4}, {6, 1}};
    std::cout << "A = "; print_fuzzy_set(a);
    std::cout << "B = "; print_fuzzy_set(b);
    std::map<int, double> c = fuzzy_set_union(a, b);
    std::map<int, double> d = fuzzy_set_intersection(a, b);
    std::cout << "Union: "; print_fuzzy_set(c);
    std::cout << "Intersection: "; print_fuzzy_set(d);
}
// Nguyễn Đức Duy - 20210275