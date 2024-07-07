/*
  oop2.cpp
  CS2124
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// class Date {
//     friend ostream& operator<<(ostream& os, const Date& rhs);
// public:
//     Date(int m, int d, int y) : month(m), day(d), year(y) {}
// private:
//     int month, day, year;
// };

class Person {
    friend ostream& operator<<(ostream& os, const Person& rhs);
public:
    class Date {
        friend ostream& operator<<(ostream& os, const Date& rhs);
    public:
        Date(int m, int d, int y) : month(m), day(d), year(y) {}
    private:
        int month, day, year;
    };



    //Person(const string& name) : name(name) { }
    //Person(const string& name) : name(name), bday() { }
    Person(const string& name, int m, int d, int y)
        : name(name), bday(m, d, y) { }
private:    
    string name;
    Date bday;
};

int main() {
    //Person john("John");
    Person john("John", 2, 5, 2024);
    cout << john << endl;


    //Date someDate(1,1,1970);
    Person::Date someDate(1,1,1970);
}

ostream& operator<<(ostream& os, const Person& rhs) {
    //os << "Person: " << rhs.name; //  << ", dob: " << rhs.bday;
    os << "Person: " << rhs.name << ", dob: " << rhs.bday;
    return os;
}

//ostream& operator<<(ostream& os, const Date& rhs) {
ostream& operator<<(ostream& os, const Person::Date& rhs) {
    os << rhs.month << '/' << rhs.day << '/' << rhs.year;
    return os;
}

