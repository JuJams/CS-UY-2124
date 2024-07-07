/*
  loadStooges.cpp

  Here we are loading a vector of instances of Person
  Modify it to load a vector of pointers to Person instancess
  
*/

#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

class Person {
    friend ostream& operator<<(ostream& os, const Person& someone);
public:
    Person(const string& name, int age) : name(name), age(age) {}
    const string& getName() const { return name; }
private:
    string name;
    int age;
}; // Person

int main()
{
    ifstream ifs("stooges.txt");
    if (!ifs) {
	cerr << "Failed to open stooges.txt\n";
	exit(1);
    }

    //    vector<Person> stooges;
    vector<Person*> stooges;
    
    string name;
    int age;
    while (ifs >> name >> age) {
	Person aPerson(name, age);
	//stooges.push_back(aPerson);
	stooges.push_back(&aPerson);
    }

    //for (Person* per : stooges) {
    for (const Person* per : stooges) {
        cout << per << ' ';
	cout << *per << endl;
    }

    // vector<int> vi { 1, 2, 3, 4, 5, 8 };
    // for (int& val : vi) {

    // }

} // main

ostream& operator<<(ostream& os, const Person& someone)
{
    os << "Person: " << someone.name << ", " << someone.age;
    return os;
} // operator<<
