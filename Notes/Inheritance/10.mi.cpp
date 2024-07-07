/*
  Multiple inheritance
*/

#include <iostream>
#include <vector>
using namespace std;

class Flier { // Mix-in
public:
    virtual void fly() = 0;
};
    
class Animal {
public:
    virtual void display() { cout << "Animal\n"; }
};

class Cat : public Animal { 
public:
    void purr() { cout << "purrrrr... ";  }
};

//class Bat : public Animal { 
class Bat : public Animal, public Flier { 
public:
    void fly() { cout << "Flap...flap ";  }
};

class Insect : public Animal, public Flier {
public:
    void fly() { cout << "Bzzzz. ";  }
};

class Plane {
public:
    void fly() { cout << "vrooommmm! ";  }
};

// ==========================================

class Person {
private:
    string name;
};

class Student : public Person {
public:
    virtual void display() const { cout << "Student\n"; }
// private:
//     string name;
};

class Instructor : public Person {
public:
    virtual void display() const { cout << "Instructor\n"; }
// private:
//     string name;
};

class TA : public Student, public Instructor {
public:
    void display() const { 
        Student::display();
        Instructor::display();
    }
};

int main() {
    Bat battie;
    battie.display();
    battie.fly();
    Plane sopwithCamel;
    Insect lady;

    cout << "==========\n";
    vector<Flier*> vf;
    vf.push_back(&battie);
    // vf.push_back(&sopwithCamel);
    vf.push_back(&lady);
    for (Flier* flier : vf) {
        flier->fly();
    }

    TA rohit;
    rohit.display();  // ambiguous
    //rohit.Student::display();  

}



