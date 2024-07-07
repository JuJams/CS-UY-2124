/*
  1.inheritance.cpp

  Code reuse, principle of substitutability, polymorphism
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Pet {
public:
    //void eat() { cout << "eating" << endl; }
    virtual void eat() { cout << "eating" << endl; }
};

class Cat : public Pet {
public:
    //void eat() { cout << "Cat eating" << endl; }
    void eat() {
        cout << "Cat ";
        Pet::eat();
    }
};

class Slug : public Pet { };

class Roach : public Pet { };

//void someFunc(Pet aPet) {
void someFunc(Pet& aPet) {
    cout << "someFunc: ";
    aPet.eat();
}

int main() {
    Pet peeve;
    peeve.eat();
    someFunc(peeve);

    Cat felix;
    felix.eat();    // Code reuse
    someFunc(felix);  // Principle of Substitutability -- Barbara Liskov

}
