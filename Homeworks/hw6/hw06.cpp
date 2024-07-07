/*
  hw06.cpp
*/

//15.5
//-0.5 Should not use STL functions like isdigit()
//-0.5 BigUnsigned(string) does not handle leading zeros properly
//-2 Only op<, op==, op<< should be friends
//-1 op== should also check that lengths are equal
//-0.5 Used int instead of size_t for index values



#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Put your class and all function definitions here.
class BigUnsigned {
    friend ostream& operator<<(ostream& os, const BigUnsigned& dig );
public:
    // Constructors

    // string constructor
    BigUnsigned(const string& str) {

        size_t index = 0;

        while (index < str.length() && !isdigit(str[index])) {
            index++;
        }

        if (index == str.length()) {
            integers.push_back(0);
            return;
        }

        while (index < str.length() && str[index] == '0') {
            index++;
        }

        for (size_t index = 0; index < str.length(); index++) {
            if (isdigit(str[index])) {
                integers.push_back(str[index] - '0');
            } 
            else {
                break;
                }
        }

        if (integers.empty()) {
            integers.push_back(0);
        }

        size_t n = integers.size();

        bool swapped;
        for (size_t j = 0; j < n / 2; j++) {
            swapped = false;
            int temp = integers[j];
            integers[j] = integers[n-j-1];
            integers[n-j-1] = temp; 
            }
        }
    //int constructor
    BigUnsigned(int num = 0) {
        if (num == 0) {
            integers.push_back(0);
            return;
        }
        while (num != 0) {
            integers.push_back(num % 10);
            num /= 10;
        }
    }
    //member functions operator overloads

    //operator for +=
    BigUnsigned& operator+=(const BigUnsigned& other) {
        int car = 0;
        size_t maxLength = std::max(integers.size(), other.integers.size());

        for (size_t index = 0; index < maxLength || car; ++index) {
            if (index == integers.size()){
                integers.push_back(0);
            }
            integers[index] += car + (index < other.integers.size() ? other.integers[index] : 0);

            car = integers[index] >= 10;

            if (car){

                integers[index] -= 10;

            }
        }
        return *this;
    }

    //operator for ++
    BigUnsigned& operator++() {

        int car = 1;
        for (size_t index = 0; index < integers.size(); ++index) {
            integers[index] += car;
            car = integers[index] / 10;
            integers[index] %= 10;
        }
        if (car > 0) {
            integers.push_back(car);
        }
        return *this;
    }

    BigUnsigned operator++(int) {
        BigUnsigned temp;
        temp.integers = integers;
        ++(*this);
        return temp;
    }
    //operator for bool
    explicit operator  bool() const {
        return !(integers.empty() || (integers[0]==0 && integers.size()==1));
    }

    //operator overload prototyples for non - member functions
    friend bool operator<=(const BigUnsigned& lhs, const BigUnsigned& rhs);

    friend bool operator>(const BigUnsigned& lhs, const BigUnsigned& rhs);

    friend bool operator>=(const BigUnsigned& lhs, const BigUnsigned& rhs);

    friend BigUnsigned operator+(const BigUnsigned& num1, 
    const BigUnsigned& num2);

    friend bool operator==(const BigUnsigned& lhs, const BigUnsigned& rhs);

    friend bool operator!=(const BigUnsigned& lhs, const BigUnsigned& rhs);

    friend bool operator<(const BigUnsigned& lhs, const BigUnsigned& rhs);
    
    //Class variables
    private:
        vector<int> integers;

};

int main() {
    BigUnsigned zero;
    BigUnsigned one(1);

    cout << "zero: " << zero << endl;
    cout << "one: " << one << endl;

    BigUnsigned val = 1;
    cout << "val: " << val << endl;
    cout << "++val: " << ++val << endl;
    cout << "val: " << val << endl;
    cout << "val++: " << val++ << endl;
    cout << "val: " << val << endl;
    
    cout << "(one + zero): " << (one + zero) << endl;
    cout << "(one + one): " <<  (one + one) << endl;

    cout << boolalpha;
    cout << "one < one: " << (one < one) << endl;
    cout << "zero < one: " << (zero < one) << endl;

    BigUnsigned a = 123;
    BigUnsigned b = 1234;
    BigUnsigned c = 124;
    BigUnsigned d = 12345;

    cout << "a: " << a << ", b: " << b 
         << ", c: " << c << ", d: " << d << endl;
    cout << "a + d: " << (a + d) << endl;
    cout << "d + d: " << (d + d) << endl;
    cout << "a < d: " << (a < d) << endl;
    cout << "d < a: " << (d < a) << endl;
    cout << "zero == zero: " << (zero == zero) << endl
         << "zero == one: " << (zero == one) << endl
         << "a == a: " << (a == a) << endl
         << "a == d: " << (a == d) << endl
         << "d == a: " << (d == a) << endl;

    // cout << "(zero == 0): " << (zero == 0) << endl
    //      << "(one == 0): " << (one == 0) << endl
    //      << "(1 == one): " << (1 == one) << endl;

    // +=
    cout << "b: " << b << ", c: " << c << endl;
    cout << "(c += b): " << (c += b) << endl;
    cout << "b: " << b << ", c: " << c << endl;


    BigUnsigned x = a;
    cout << "x: " << x << ", a: " << a << endl
         << "x == a: " << (x == a) << endl
         << "a == x: " << (a == x) << endl
         << "a < x: " << (a < x) << endl
         << "a > x: " << (a > x) << endl;
    
    cout << "x > a: " << (x > a) << endl
         << "x >= a: " << (x >= a) << endl
         << "x <= a: " << (x <= a) << endl
         << "x != a: " << (x != a) << endl;
         
    
    BigUnsigned big("987654321");
    BigUnsigned big2("  ");
    BigUnsigned big3("felix");
    BigUnsigned big4("00987654321");

    cout << "big: " << big << endl
         << "big2: " << big2 << endl
         << "big3: " << big3 << endl
         << "big4: " << big4 << endl;

    BigUnsigned big5(98765);
    BigUnsigned big6(2457);
    cout << "big5: " << big5  << ", big6: " <<  big6 << endl;
    cout << "(big5 + big6): " << (big5 + big6) << endl;
    cout << "(big6 + big5): " << (big6 + big5) << endl;


    cout << zero << " is " << (zero ? "true" : "false") << endl;
    cout << one << " is " << (one ? "true" : "false") << endl;
    cout << big4 << " is " << (big4 ? "true" : "false") << endl;
}

//operator overload functions

//operator for <<
ostream& operator<<(ostream& os, const BigUnsigned& dig ){
        for (size_t r = dig.integers.size(); r>0;r--) {
            os << dig.integers[r-1];
        }
        return os;
    }

//operator for ==
bool operator==(const BigUnsigned& lhs, const BigUnsigned& rhs) {
    return lhs.integers == rhs.integers;
    }

//operator !=
bool operator!=(const BigUnsigned& lhs, const BigUnsigned& rhs) {
    return !(lhs == rhs);
    }

//operator for + 
BigUnsigned operator+(const BigUnsigned& rhs, const BigUnsigned& lhs) {
    BigUnsigned result(rhs);
    result+=lhs;
    return result;
}


//operator <
bool operator<(const BigUnsigned& lhs, const BigUnsigned& rhs) {
    if (lhs.integers.size() != rhs.integers.size()){
        return lhs.integers.size() < rhs.integers.size();
    }
        
    for (int index = lhs.integers.size() - 1; index >= 0; --index) {
        if (lhs.integers[index] != rhs.integers[index]){

            return lhs.integers[index] < rhs.integers[index];
        }
        }
        return false; 
    }

//operator for >
bool operator>(const BigUnsigned& lhs, const BigUnsigned& rhs) {
    return rhs < lhs;
    }

//operator >=
bool operator>=(const BigUnsigned& lhs, const BigUnsigned& rhs) {
    return !(lhs < rhs);
    }
//operator for <=
bool operator<=(const BigUnsigned& lhs, const BigUnsigned& rhs) {
    return !(rhs < lhs);
    }

