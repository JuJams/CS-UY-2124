/*
  marries.cpp
  CS2124
 */

#include <iostream>
#include <string>
using namespace std;

class Person {
    friend ostream& operator<<(ostream& os, const Person& rhs);
public:
    Person(const string& name) : name(name), spouse(nullptr) {}

    //john.marries(mary);
    //void marries(Person& betrothed)
    bool marries(Person& betrothed)
    {
        if (spouse == nullptr && betrothed.spouse == nullptr) {
            spouse = &betrothed;
            betrothed.spouse = this;
            return true;
        }
        return false;
    } 
private:
    string name;
    Person* spouse;
}; // Person

int main()
{
    Person john("John");
    Person mary("Mary");
    cout << john << endl
         << mary << endl;
    john.marries(mary);
    cout << john << endl
         << mary << endl;


    int x = 17;
    cout << &x << endl; // address-of

    int* p = &x;
    cout << p << " " << &x << endl; // address-of operator

    cout << *p << " " << x << endl; // dereference operator

    *p = 42;

    cout << sizeof(x) << " " << sizeof(p) << endl;


    Person sally("Sally");
    sally.marries(john);
    cout << john << endl
         << mary << endl
         << sally << endl;

} // main

ostream& operator<<(ostream& os, const Person& rhs)
{
    os << "Name: " << rhs.name << ", ";
    if (rhs.spouse != nullptr) {
        //os << "Married to " << *rhs.spouse.name;
        //os << "Married to " << (*rhs.spouse).name;
        os << "Married to " << rhs.spouse->name;
    } else {
        os << "Single";
    }
    return os;
} // operator<<
