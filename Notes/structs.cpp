/*
  structs.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Person {
    string name;
    int age;
};

//void printPerson(Person someone) {
void printPerson(const Person& someone) {
    cout << "Person: " << someone.name << ", " << someone.age << endl;
}

int main() {
    Person fred;

    //cout << fred << endl;
    cout << "Person: " << fred.name << ", " << fred.age << endl;

    string s; // Uses the string "default constructor"

    fred.name = "Fred";
    fred.age = 18;
    cout << "Person: " << fred.name << ", " << fred.age << endl;

    Person mary { "Mary", 19 };
    cout << "Person: " << mary.name << ", " << mary.age << endl;

    printPerson(mary);

    Person someone;
    someone = fred; // assignment operator

    Person someoneElse(fred); // copy constructor

    int x;

    //    yetAnotherPerson;

    vector<Person> people;

    //ifstream personStream("people.txt");
    ifstream personStream;
    personStream.open("people.txt");
    if (!personStream) {
        cout << "Failed to open people.txt\n";
        exit(1);
    }

    ///string aString;
    string name;
    int age;
    //while(personStream >> aString) {
    while(personStream >> name >> age) {
        // Person aPerson;
        // aPerson.name = name;
        // aPerson.age = age;
        //Person aPerson { name };
        Person aPerson { name, age };
        people.push_back(aPerson);
    }

    personStream.close();

    for(size_t index = 0; index < people.size(); ++index) {
        printPerson(people[index]);
    }

    for (const Person& aPerson : people) {
        printPerson(aPerson);
    }
    
}
