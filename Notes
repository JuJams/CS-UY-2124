/*
  Defining functions and using parameter passing
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

void addOne(int someInt) { // pass by value
    ++someInt;  // Same effect as: someInt += 1;
}

int addOneV2(int someInt) { // pass by value
    ++someInt;  // Same effect as: someInt += 1;
    return someInt;
}

void addOneV3(int& someInt); // function prototype

//void printVec(vector<int> v) { // pass by value
//void printVec(vector<int>& v) { // pass by reference
void printVec(const vector<int>& v) { // pass by constant reference
    for (int val : v) {
        cout << val << ' ';
    }
    cout << endl;

}

//int foo() {
int& foo() { // DON'T return a local by reference
    int x = 17;
    return x;
}

int main() {

    int x = 17;

    addOne(x);
    cout << x << endl;

    x = addOneV2(x);
    cout << x << endl;

    addOneV3(x);
    cout << x << endl;

    vector<int> vi { 1, 1, 2, 3, 5, 8 };

    for (int val : vi) {
        cout << val << ' ';
    }
    cout << endl;

    printVec(vi);

    //for (int val : vi) {
    for (int& val : vi) {
        val *= 2;
    }

    vector<string> vs { "Now", "is", "the", "time" };
    for (const string& val : vs) {
        cout << val << ' ';
    }
    cout << endl;

    cout << foo() << endl;

}

void addOneV3(int& someInt) { // pass by reference
    ++someInt;  // Same effect as: someInt += 1;
}

