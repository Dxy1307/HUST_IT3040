#include <algorithm>
#include <set>
#include <iostream>
#include <string.h>
using namespace std;

class Student {
    public:
        Student(string name, int sNum, double gpa);
        string getName() const;
        int getSNum() const;
        double getGPA() const;
    private:
        string name_;
        int sNum_;
        double gpa_;
};

Student::Student(string name, int sNum, double gpa) :
    name_(name), sNum_(sNum), gpa_(gpa) {}
string Student::getName() const { return name_; }
int Student::getSNum() const { return sNum_; }
double Student::getGPA() const {return gpa_; }

bool operator== (const Student &s1, const Student &s2) {
    return (s1.getSNum() == s2.getSNum()) &&
           (s1.getName() == s2.getName()) &&
           (s1.getGPA() == s2.getGPA());
}

bool operator< (const Student &s1, const Student &s2) {
    return s1.getSNum() < s2.getSNum();
}

ostream& operator<< (ostream& os, const Student &s) {
    os << s.getName() << " " << s.getSNum() << " " << s.getGPA();
    return os;
}

int main() {
    Student *pJohn = new Student("John Smith", 666, 3.7);
    Student *pMary = new Student("Mary Jones", 345, 3.4);
    Student *pPeter = new Student("Peter Piper", 345, 3.1);

    set<Student> s;
    s.insert(*pJohn);
    s.insert(*pMary);
    s.insert(*pPeter);

    for(auto iter = s.begin(); iter != s.end(); iter++) {
        cout << iter << endl;
    }
    if(s.find(*pPeter) != s.end())
        cout << "Found it with set's find()!" << endl;
    if(find(s.begin(), s.end(), *pPeter) != s.end())
        cout << "Found it with STL algorithm find()" << endl;
}