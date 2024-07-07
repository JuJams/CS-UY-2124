/*
hw 08 - More on Inheritanace
Nobles battle simulation - Implements Noble hierarchy and 
battle logic
*/
#include <string>
#include <vector>
#include <iostream>
#include "Noble.hpp"
#include "Protector.hpp"

using namespace std;

namespace WarriorCraft {
    
//Noble Class
//Noble Constructor
    Noble::Noble(const string& name, double strength): name(name),
strength(strength), aliveStatus(true) {}

    //getters and setters
    const string& Noble::getName() const {return name;}
    void Noble::setStrength(double strength) {this->strength = strength;}
    bool Noble::isDeadOrAlive() const {return aliveStatus;}
    double Noble::getStrength() const { return strength;}
    //Battle method
    void Noble::battle(Noble& other) {
        cout << name << " battles " << other.name << endl;
        //They both are dead
        if (!aliveStatus && !other.aliveStatus) {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        }
        //if one is dead
        else if (!aliveStatus) {
            other.battleCry();
            cout << "He's dead, " << other.name << endl;
        }
        else if (!other.aliveStatus) {
            battleCry();
            cout << "He's dead, " << name << endl;
        }
        //if both are alive
        else {
            battleCry();
            other.battleCry();
            double multiplier = other.strength / strength;
            battleHelper(multiplier);
            other.battleHelper(1 / multiplier);
            if (strength > other.strength) {
                cout << name << " defeats " << other.name << endl;
            }
            else if (strength < other.strength) {
                cout << other.name << " defeats " << name << endl;
            }
            else {
                cout << "Mutual Annihilation: " << name << " and " 
                << other.name << " die at each other's hands" << endl;
            }
        }

    }
//Noble battle helper
    void Noble::battleHelper(double multiplier) {
        if (multiplier >= 1) {
            strength = 0;
            aliveStatus = false;
        }
        else
            strength = strength * (1 - multiplier);
    }
//Noble output operator overloader
    ostream& operator<<(ostream& os, const Noble& noble) {
        return noble.printer(os);
        
    }

//Lord class

//Constructor
    Lord::Lord(const string& name): Noble(name) {}

//hires method
    bool Lord::hires(Protector& protector) {
        if (isDeadOrAlive() && protector.getLord() == nullptr) {
            setStrength(getStrength() + protector.getNewStrength());
            warriors.push_back(&protector);
            protector.setLord(this);
            
            return true;
        }
        else{
            cout<<getName()<<" failed to hire "<< protector.getName()<<endl;
            return false;
        }
    }

//Fires method
    bool Lord::fires(Protector& protector, bool runaway) {
        for (size_t i = 0; i < warriors.size(); ++i) {
            if (warriors[i] == &protector) {
                if (!runaway)
                    cout << protector.getName() 
                    << ", you don't work for me anymore ! -- " << getName() << endl;
                setStrength(getStrength() - protector.getNewStrength());
                protector.setLord(nullptr);
                for (size_t j = i; j < warriors.size() - 1; ++j) {
                    warriors[j] = warriors[j + 1];
                }
                warriors.pop_back();
                return true;
            }
        }
        cout << "Couldn't find " << protector.getName()
        << " in " << getName() << "'s army!" << endl;
        return false;
    }

//Battle cry method
    void Lord::battleCry() const {
        for (size_t i = 0; i < warriors.size(); ++i) {
            warriors[i]->battleCry();
        }
    }
//Printer method
ostream& Lord::printer(ostream& os) const {
   os << getName() << " has an army of size: " << warriors.size();
   for (size_t i = 0; i < warriors.size(); ++i) {
       os << "\n\t" << *warriors[i];
   }
   return os;
}

//Battle helper for Battle
    void Lord::battleHelper(double multiplier) {
        Noble::battleHelper(multiplier);
        for (size_t i = 0; i < warriors.size(); ++i) {
            if (multiplier >= 1){
                warriors[i]->setStrength(0);
            }
            else{
                warriors[i]->setStrength(warriors[i]->getNewStrength() *
                                         (1 - multiplier));
            }
        }
    }


 

//Person class
//person constructor
    PersonWithStrengthToFight::PersonWithStrengthToFight
 (const string& name, double strength): Noble(name, strength) {}

    void PersonWithStrengthToFight::battleCry() const {
        cout << "Ugh!" << endl;
    }

//person printer output method
    ostream& PersonWithStrengthToFight::printer(ostream& os) const {
        os << getName() << " has strength: " << getStrength();
        return os;
    }
}

