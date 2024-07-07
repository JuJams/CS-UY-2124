/*
hw 08 - More on Inheritanace
Nobles battle simulation
Implemets protector hierarchy 
*/
#include <string>
#include <vector>
#include <iostream>
#include "Noble.hpp"
#include "Protector.hpp"
using namespace std;

namespace WarriorCraft {

//Protector constructor
    Protector::Protector(const string& name, double strength):
name(name), strength(strength), alive(true), lord(nullptr) {}

//getters and setters
    void Protector::setStrength(double strength) {
        this->strength = strength;
    }
    Lord* const Protector::getLord() const {
        return lord;
    }
    void Protector::setLord(Lord* lord) {
        this->lord = lord;
    }
    const string& Protector::getName() const {
        return name;
    }
    double Protector::getNewStrength() const {
        return strength;
    }
//runaway method
    bool Protector::runaway() {
        if (lord != nullptr) {
            cout << name << " flees in terror, abandoning his lord, " <<
            lord->getName() << endl;
            lord->fires(*this,true);
            lord = nullptr;
            return true;
        }
        return false;
    }

//output operator
    ostream& operator<<(ostream& os, const Protector& protector) {
        os << protector.name << " has strength " << protector.strength;
        return os;
    }

//constructor
    Wizard::Wizard(const string& name, double strength):
    Protector(name, strength) {}

 
    void Wizard::battleCry() const {
        cout << "POOF" << endl;
    }

//constructor
    Warrior::Warrior(const string& name, double strength):
Protector(name, strength) {}

//constructor
    Archer::Archer(const string& name, double strength):
Warrior(name, strength) {}
    void Archer::battleCry() const {
        cout << "TWANG! " << getName() 
        << " says: Take that in the name of my lord, " << 
        getLord()->getName() << endl;
    }

//constructor
    Swordsman::Swordsman(const string& name,
                         double strength): Warrior(name, strength) {}
    void Swordsman::battleCry() const {
        cout << "CLANG! " << getName() 
        << " says: Take that in the name of my lord, " << getLord()->getName() << endl;
    }
}


