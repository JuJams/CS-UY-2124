/*
    hw05.cpp
    Dynamic array
    */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;
//19
//-1 Insufficient functional decomposition of main(); each command should have its own function

// Forward Declarations
class Warrior;
class Noble;

// Warrior class definition
class Warrior {
    friend ostream& operator<<(ostream& os, 
        const Warrior& warrior);

public:
    // Warrior Constructor
    // Parameters: name of the warrior, strength
    // Return type: None
    Warrior(const string& warName, double strength) : 
        warName(warName), strength(strength), hired(false) {}

    // Gets warrior job status
    // Parameters: None
    // Return type: bool
    bool getStatus() const { 
        return hired; 
        }

    // Sets job to true
    // Parameters: None
    // Return type: void
    void setStatus() {
        if (!hired) {
            hired = true;
        }
    }

    // Sets job to false
    // Parameters: None
    // Return type: void
    void changeStatus() {
        if (hired) {
            hired = false;
        }
    }

    // Gets warrior name
    // Parameters: None
    // Return type: const string&
    const string& getName() const { 
        return warName; 
        }

    // Gets strength of warrior
    // Parameters: None
    // Return type: double
    double getStrength() const { 
        return strength; 
        }

    // Updates strength of warrior
    // Parameters: new strength
    // Return type: void
    void setStrength(double newStrength) { 
        strength = newStrength; 
        }

private:
    double strength;
    string warName;
    bool hired;
};

// Noble class definition
class Noble {
    friend ostream& operator<<(ostream& os, const Noble& noble);
public:
    Noble(const string& nobName) : 
    nobName(nobName), status(true), armyStrength(0) {}

    bool HireWarrior(Warrior& warrior){
        if (!warrior.getStatus() && status) {
            army.push_back(&warrior);
            armyStrength += warrior.getStrength();
            warrior.setStatus();
            return true;
        } else {
            cout << nobName << " has failed to hire " 
            << warrior.getName() << endl;
            return false;
        }
    }
    bool FireWarrior(Warrior* warrior){
        if (!warrior->getStatus()) {
            cout << nobName << " failed to fire "
             << warrior->getName() << endl;
            return false;
        }
        bool exist = false;
        for (size_t i = 0; i < army.size(); i++) {
            if (warrior->getName()== army[i]->getName()) {
                exist = true;
                break;
            }   
        }
        if (!exist) {
            cout << nobName << " failed to fire " 
            << warrior->getName() << endl;
            return false;
        } 
        else {
            bool fired = false;
            for (size_t i = 0; i < army.size(); i++) {
                if (!fired) {
                    if (army[i]->getName() == warrior->getName()) {
                        cout << warrior->getName() << 
                        ", You don't work for me anymore ! -- "
                        << nobName << ". " << endl;
                        warrior->changeStatus();
                        fired = true;
                    }
                } 
                else {
                    army[i - 1] = army[i];
                }
            }
            armyStrength -= warrior->getStrength();
            army.pop_back();
            return fired;
        }
    }

    void kill(){
        status = false;
        armyChanges(1, 1);
    }

    void armyChanges(double winArmy, double loseArmy){
        int newArmyStrength = 0;
        for (Warrior*& warrior : army) {
            int newWarStrength = warrior->getStrength() * 
            (winArmy - loseArmy) / winArmy;
            warrior->setStrength(newWarStrength);
            newArmyStrength += newWarStrength;
        }
        armyStrength = newArmyStrength;
    }

    void battle(Noble& noble2){
        cout << nobName << " battles " << noble2.nobName << endl;
        if (!status && !noble2.status) {
            cout << "Oh, NO! They're both dead! Yuck!" << endl;
        } 
        else if (!status && noble2.status) {
            cout << "He's dead " << noble2.nobName << endl;
        } 
        else if (status && !noble2.status) {
            cout << "He's dead " << nobName << endl;
        } 
        else {
            if (armyStrength == noble2.armyStrength) {
                kill();
                noble2.kill();
                cout << "Mutual Annihilation " << nobName << " and " 
                << noble2.nobName << " die at each other's hands" 
                << endl;
            } 
            else if (armyStrength > noble2.armyStrength) {
                armyChanges(armyStrength, noble2.armyStrength);
                noble2.kill();
                cout << nobName << " defeats " << noble2.nobName 
                << endl;
            } 
            else {
                armyChanges(noble2.armyStrength, armyStrength);
                kill();
                cout << noble2.nobName << " defeats " << nobName 
                << endl;
            }
        }
    }

    const string& getName() const { return nobName; }
private:
    string nobName;
    vector<Warrior*> army;
    bool status;
    double armyStrength;
};

// Function prototypes
void status(const vector<Noble*>& nobles,const vector<Warrior*>& warriors);
size_t find_noble(const string& name,const vector<Noble*>& rhs);
size_t find_warrior(const string& name,const vector<Warrior*>& rhs);
bool hireWarrior(const string& nobName,const string& warName,
                 const vector<Noble*>& nobles,const vector<Warrior*>& warriors);
bool fireWarrior(const string& nobName,const string& warName,
                 const vector<Noble*>& nobles,const vector<Warrior*>& warriors);


// Main Function
int main() {
    ifstream ifs;
    ifs.open("nobleWarriors.txt");
    if (!ifs) {
        cerr << "Failed to open file.";
        exit(1);
    }

    string command, nobName, warName;
    int strength;
    vector<Warrior*> warriors;
    vector<Noble*> nobles;

    while (ifs >> command) {
        if (command == "Noble") {
            ifs >> nobName;
            if (find_noble(nobName, nobles) < nobles.size()) {
                cout << nobName << " already exists." << endl;
            } else {
                nobles.push_back(new Noble(nobName));
            }
        } else if (command == "Warrior") {
            ifs >> warName >> strength;
            if (find_warrior(warName, warriors) < warriors.size()) {
                cout << warName << " already exists." << endl;
            } else {
                warriors.push_back(new Warrior(warName, strength));
            }
        } else if (command == "Hire") {
            ifs >> nobName >> warName;
            hireWarrior(nobName, warName, nobles, warriors);
        } else if (command == "Status") {
            status(nobles, warriors);
        } else if (command == "Fire") {
            ifs >> nobName >> warName;
            fireWarrior(nobName, warName, nobles, warriors);
        } else if (command == "Battle") {
            ifs >> nobName >> warName;
            size_t nob1 = find_noble(nobName, nobles);
            size_t nob2 = find_noble(warName, nobles);

            if (nob1 == nobles.size()) {
                cout << nobName << " doesn't exist." << endl;
            } else if (nob2 == nobles.size()) {
                cout << warName << " doesn't exist." << endl;
            } else {
                nobles[nob1]->battle(*nobles[nob2]);
            }
        } else {
            // Clearing memory
            for (const Noble* nob : nobles) {
                delete nob;
            }
            for (const Warrior* war : warriors) {
                delete war;
            }
            nobles.clear();
            warriors.clear();
        }
    }
    ifs.close();
    return 0;
}

// Function Definitions
void status(const vector<Noble*>& nobles, 
            const vector<Warrior*>& warriors) {
    cout << "Status\n" << "======\n" << "Nobles:\n";
    if (nobles.empty()) {
        cout << "NONE" << endl;
    } else {
        for (const Noble* nob : nobles) {
            cout << *nob << endl;
        }
    }

    cout << "\nUnemployed Warriors:\n";
    int unemployNum = 0;
    for (const Warrior* war : warriors) {
        if (!war->getStatus()) {
            cout << "\t" << *war << endl;
        } else {
            unemployNum++;
        }
    }
    if (unemployNum == warriors.size()) {
        cout << "NONE" << endl;
    }
}

size_t find_noble(const string& name, 
                const vector<Noble*>& rhs) {
    for (size_t i = 0; i < rhs.size(); ++i) {
        if (name == rhs[i]->getName()) return i;
    }
    return rhs.size();
}

size_t find_warrior(const string& name, 
                    const vector<Warrior*>& rhs) {
    for (size_t i = 0; i < rhs.size(); ++i) {
        if (name == rhs[i]->getName()) return i;
    }
    return rhs.size();
}

bool hireWarrior(const string& nobName, 
                const string& warName,const vector<Noble*>& nobles, 
                const vector<Warrior*>& warriors) {
    size_t nob1 = find_noble(nobName, nobles);
    size_t war1 = find_warrior(warName, warriors);
    if (nob1 == nobles.size()) {
        if (war1 == warriors.size()) {
            cout << nobName << " and " << warName 
            << " both do not exist.\n";
            return false;
        } else {
            cout << "Attempting to hire using unknown noble: "
             << nobName << endl;
            return false;
        }
    } else if (war1 == warriors.size()) {
        cout << "Attempting to hire using unknown warrior: " 
        << warName << endl;
        return false;
    } else {
        nobles[nob1]->HireWarrior(*warriors[war1]);
        return true;
    }
}

bool fireWarrior(const string& nobName, const string& warName,
                const vector<Noble*>& nobles, 
                const vector<Warrior*>& warriors) {
    size_t nob1 = find_noble(nobName, nobles);
    size_t war1 = find_warrior(warName, warriors);
    if (nob1 == nobles.size()) {
        if (war1 == warriors.size()) {
            cout << nobName << " and " << warName 
                << " both do not exist.\n";
            return false;
        } else {
            cout << "Attempting to fire using unknown noble: " 
                << nobName << endl;
            return false;
        }
    } else if (war1 == warriors.size()) {
        cout << "Attempting to fire using unknown warrior: "
             << warName << endl;
        return false;
    } else {
        Warrior* warPtr = warriors[war1];
        nobles[nob1]->FireWarrior(warPtr);
        return true;
    }
}

ostream& operator<<(ostream& os, const Warrior& warrior) {
    os << warrior.getName() << ": " << warrior.getStrength();
    return os;
}

ostream& operator<<(ostream& os, const Noble& noble) {
    os << noble.getName() << " has an army of " << noble.army.size();
    for (size_t i = 0; i < noble.army.size(); ++i) {
        os << "\n\t" << *noble.army[i];
    }
    return os;
}

