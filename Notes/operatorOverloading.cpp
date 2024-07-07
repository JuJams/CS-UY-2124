/*
  Arithmetic Operator Overloading
  InClass Base
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Complex {
    // op<< as a friend
    friend ostream& operator<<(ostream& os, const Complex& rhs) {
        os << rhs.real;
        if (rhs.imag >= 0) os << '+';
        os << rhs.imag << 'i';
        //os << showpos << rhs.imag << 'i' << noshowpos;
        return os;
    }

    friend bool operator==(const Complex& lhs, const Complex& rhs);

public:
    // Complex() : real(0), imag(0) {}
    // Complex(double real) : real(real), imag(0) {}
    // Complex(double real, double imag) : real(real), imag(imag) {}
    Complex(double real = 0, double imag = 0) : real(real), imag(imag) {}

    //c1 == c2
    //c1.operator==(c2)
    // bool operator==(const Complex& rhs) const {
    //     return real == rhs.real && imag == rhs.imag;
    // }

    // c1 += c2;
    // c1.operator+=(c2);
    Complex& operator+=(const Complex& rhs) {
        real += rhs.real;
        imag += rhs.imag;
        return *this;
    }

    //++c1;
    // c1.operator++();
    Complex& operator++() {
        ++real;
        return *this;
    }

    // c1++;
    // c1.operator++(0);
    //Complex& operator++(int) {
    Complex operator++(int dummy) {
        Complex original(*this);
        ++real;
        return original;
    }

    // Conversion operator
    //operator bool() const {
    explicit operator bool() const {
        // if (real == 0 && imag == 0) {
        //     return false;
        // }
        // return true;
        return real != 0 || imag != 0;
    }


private:
    double real, imag;
};


// c1 == c2
// operator==(c1, c2)
bool operator==(const Complex& lhs, const Complex& rhs)  {
    return lhs.real == rhs.real && lhs.imag == rhs.imag;
}



// c1 != c2
// operator!=(c1, c2);
bool operator!=(const Complex& lhs, const Complex& rhs) {
    return !(lhs == rhs);
}

// c2 + c3
// operator+(c2, c3)
Complex operator+(const Complex& lhs, const Complex& rhs) {
    // Complex result;
    // result += lhs;
    Complex result(lhs);
    result += rhs;
    return result;
}


// Test code
int main() {
    Complex c1;         // 0+0i
    Complex c2(17);     // 17+0i
    Complex c3(3, -5);  // 3-5i
    cout << "c1: " << c1 << endl
         << "c2: " << c2 << endl
         << "c3: " << c3 << endl;

    // Testing equality and inequality operators
    // cout << "c1 ";
    // if (c1 == c2) cout << "==";
    // else cout << "!=";
    // cout << " c2\n"; 

    // The above four lines in one line:
    cout << "c1 " << (c1 == c2 ? "==" : "!=") << " c2\n"; 

    //c1 == c2
    //c1.operator==(c2)
    //operator==(c1, c2)

    cout << "c1 " << (c1 == c1 ? "==" : "!=") << " c1\n"; 

    cout << "c1 " << (c1 != c2 ? "!=" : "==") << " c2\n"; 
    cout << "c1 " << (c1 != c1 ? "!=" : "==") << " c1\n"; 

    // c1 != c2
    //    c1.operator!=(c2);
    //    operator!=(c1, c2);

    Complex one(1);
    cout << "one " << (one == 1 ? "==" : "!=") << " 1\n"; 

    // one == 1
    // one.operator==(1)
    // one == Complex(1)
    // one.operator==(Complex(1))

    cout << "1 " << (1 == one ? "==" : "!=") << " one\n"; 
    //1 == one
    // 1.operator==(one);
    // operator==(1, one)

    // Testing "combination operator" op+=
    c1 += c2;
    //c1.operator+=(c2);

    // Testing op+
    c1 = c2 + c3;
    //c2 + c3
    //    c2.operator+(c3)
    //operator+(c2, c3)

    // Testing pre-increment
    //cout << ++c1 << ' ' << c1 << endl;

    cout << ++c1 << ' ';
    cout << c1 << endl;
    //++c1;
    // c1.operator++();
    // operator++(c1);

    // Testing post-increment
    cout << c1++ << ' ' << c1 << endl;
    // c1++;
    // c1.operator++(0);
    

    Complex zero(0);
    cout << "zero is " << (zero ? "true" : "false") << endl;
    cout << "one is " << (one ? "true" : "false") << endl;

}
