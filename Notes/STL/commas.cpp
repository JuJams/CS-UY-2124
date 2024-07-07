/*
  commas.cpp
  Yes, there is a comma operator
  But it does not mean the same thing as in Python
 */

#include <utility>
#include <iostream>
#include <string>
using namespace std;

//pair<int, bool> foo() {
auto foo() { // c++14
    return make_pair(42, true);
}

int main() {
    int a = 17, b = 42;
    cout << a << ' ' << b << endl;
    a, b = b, a;

    cout << a << ' ' << b << endl;

    a, (b = b), a;

    int tmp = a;
    a = b;
    b = tmp;

    swap(a, b);

    //pair<int, bool> something = foo();
    auto something = foo();
    cout << something.first << ' ' << something.second << endl;

    // "structured unbinding"
    auto [x, y] = foo();  // c++17
    cout << x << ' ' << y << endl;
}
