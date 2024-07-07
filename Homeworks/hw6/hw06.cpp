/*
  bigUnsigned_begin.cpp
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Put your class and all function definitions here.
class BigUnsigned;
class BigUnsigned{
     // Friend member operators
     friend ostream& operator<<(ostream& os, const BigUnsigned& dig);
     friend bool operator<(const BigUnsigned& rhs, const BigUnsigned& lhs);
     friend bool operator==(const BigUnsigned& rhs, const BigUnsigned& lhs);
     friend bool operator!=(const BigUnsigned& rhs, const BigUnsigned& lhs);
     friend bool operator>(const BigUnsigned& rhs, const BigUnsigned& lhs);
     friend bool operator>=(const BigUnsigned& rhs, const BigUnsigned& lhs);
     friend bool operator<=(const BigUnsigned& rhs, const BigUnsigned& lhs);
     public:
          BigUnsigned(){
               digits.push_back(0);
          }
          BigUnsigned(const string& str){
               
          for(size_t i = 0; i < str.size(); i++){
                    if(str[i] == 48){
                         continue;
                    }
                    else{
                         size_t index = i;
                         while(index < str.size()){
                              if( index == i && !(str[index] >= '0')&&!(str[index]<='9')){
                                   digits.push_back(0);
                                   index++;
                                   
                              }
                              if((str[index] >= '0')&&(str[index]<='9')){
                                   int temp = str[index] - 48;
                                   digits.push_back(temp);
                                   index++;
                                   
                              }
                              
                         }
                         return;
                         
                    }         
               }
               
          }
          BigUnsigned(int num){
               if (num == 0){
                    digits.push_back(0);
                    return;
               }
               while (num != 0) {
                    digits.push_back(num % 10);
                    num /= 10;
               }


          }
          // Member operators (++, +=)
          // Pre incerement ++ operator.. should be passed by reference and does not a take a parameter
          BigUnsigned& operator++(){
               int carry = 1;
               for(size_t i = 0; i < digits.size(); ++i){
                    digits[i] += carry;
                    carry = digits[i] / 10;
                    digits[i] %= 10;
               }
               if (carry > 0){
                    digits.push_back(carry);
               }
               return *this;
          }
          // Post increment ++ operator..should be passed by value and takes a dummy
          BigUnsigned operator++(int){
               BigUnsigned temp;
               temp.digits = digits;
               ++(*this);
               return temp;
          }
          // += operator should be passed by constant reference and the return type should be a reference
          BigUnsigned& operator+=(const BigUnsigned& other) {
               int car = 0;
               size_t maxLength = std::max(digits.size(), other.digits.size());
               for (size_t index = 0; index < maxLength || car; ++index) {
                    if (index == digits.size()){
                         digits.push_back(0);
               }
               digits[index] += car + (index < other.digits.size() ? other.digits[index] : 0);
               car = digits[index] >= 10;
               if (car){
                    digits[index] -= 10;
               }
          }
          return *this;         
          }
          explicit operator bool() const{
               return !(digits.empty() || (digits[0] == 0 && digits.size() == 1));
          }     
     private:
          vector<int> digits;
};
// Non-member functions
// + operator should be passed by const reference and the return type is BigUnsigned (return by value)
BigUnsigned operator+(const BigUnsigned& rhs, const BigUnsigned& lhs);



int main() {
    BigUnsigned zero;
    BigUnsigned one("209209019");
    BigUnsigned big("987654321");
    cout << "zero: " << zero << endl;
    cout << "one: " << one << endl;
    cout << big << endl;

    
     
    /*BigUnsigned val = 1;
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

    cout << "(zero == 0): " << (zero == 0) << endl
         << "(one == 0): " << (one == 0) << endl
         << "(1 == one): " << (1 == one) << endl;
 
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
    cout << "big5: " << big5  << ", big6: " <<  big6 << endl
         << "(big5 + big6): " << (big5 + big6) << endl
         << "(big6 + big5): " << (big6 + big5) << endl;

 
    cout << zero << " is " << (zero ? "true" : "false") << endl;
    cout << (10 < 20 ? "10 is smaller" : " 10 is bigger")
    cout << one << " is " << (one ? "true" : "false") << endl;
    cout << big4 << " is " << (big4 ? "true" : "false") << endl;
    */
}

// Friend Overloading Operators


ostream& operator<<(ostream& os, const BigUnsigned& dig ){
        for (size_t r = dig.digits.size(); r>0;r--) {
            os << dig.digits[r-1];
        }
        return os;
    }

bool operator<(const BigUnsigned& lhs, const BigUnsigned& rhs) {
     if (lhs.digits.size() != rhs.digits.size()){
          return lhs.digits.size() < rhs.digits.size();
     }
     else{  
          for (int i=0; i<lhs.digits.size(); i++) {
               if (lhs.digits[i] != rhs.digits[i]){
                    return lhs.digits[i] < rhs.digits[i];
               }
          }
          return false;
     } 
}

bool operator==(const BigUnsigned& rhs, const BigUnsigned& lhs){
     if (lhs.digits.size() != rhs.digits.size()){
          return false;
     }
     for (size_t i = 0; i < lhs.digits.size(); i++){
          if (lhs.digits[i] != rhs.digits[i]){
               return false;
          }
     }
     return true;
}

bool operator!=(const BigUnsigned& rhs, const BigUnsigned& lhs){
     return !(lhs==rhs);
}
bool operator>(const BigUnsigned& rhs, const BigUnsigned& lhs){
     return rhs < lhs;
}
bool operator>=(const BigUnsigned& rhs, const BigUnsigned& lhs){
     return !(rhs < lhs);
}
bool operator<=(const BigUnsigned& rhs, const BigUnsigned& lhs){
     return !(lhs < rhs);
}


// Non-member overloading operators
BigUnsigned operator+(const BigUnsigned& rhs, const BigUnsigned& lhs){
     // Make a copy of rhs
     BigUnsigned result(rhs);
     result += lhs;
     return result;
}