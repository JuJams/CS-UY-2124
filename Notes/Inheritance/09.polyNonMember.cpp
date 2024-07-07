/*
  09.polyNonMember.cpp
*/

#include <iostream>
using namespace std;

class Base {
public:
    //virtual void display(ostream& os) {
    virtual void display(ostream& os) const {
        //cout << "Base";
        os << "Base";
    }
 };

ostream& operator<<(ostream& os, const Base& rhs) {
    //os << "Base";
    rhs.display(os);
    return os;
}

class Derived : public Base {
public:
    //virtual void display(ostream& os) const {
    void display(ostream& os) const override {
        os << "Derived";
    }
};

// ostream& operator<<(ostream& os, const Derived& rhs) {
//     os << "Derived"; 
//     return os;
// }

// =============================

void func(const Base& base) {
    cout << base << endl;
    //operator<<(cout, base);
}

int main() {
    Derived der;
    cout << der << endl;
    //operator<<(cout, der);
    func(der);
}
