/*
  bounds checking
  CS2124
*/

#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void someFunc() {
    vector<int> v;

    v.push_back(6);

    // What happens here?
    // v[17] = 42;
    // cout << v[17] << endl;
    v.at(17) = 42;
    cout << v.at(17) << endl;
}

void foo() {
    someFunc();
}

int main() {

    try {
	foo();
    }
    catch(int ex) {
	cout << "Caught: " << ex << endl;
    }
    // catch(out_of_range ex) {
    // 	cout << "Caught an out_of_range exception\n";
    // }
    catch(...) {
	cout << "So long and thanks for all the fish.\n";
    }

    cout << "Still running\n";

}
