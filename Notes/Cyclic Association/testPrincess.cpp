/*
    testPrincess.cpp
    Cyclic Association
*/

#include <iostream>
#include <string>
using namespace std;

// Forward Class Declaration
class FrogPrince; 

class Princess {
    friend ostream& operator<<(ostream& os, const Princess& princess);
    // friend ostream& operator<<(ostream& os, const Princess& princess) {
    //     os << "Princess: " << princess.name << ", ";
    //     if (princess.spouse) {
    //         cout << "Married: " << princess.spouse->getName();
    //     }
    //     else {
    //         cout << "Single";
    //     }
    //     return os;
    // }
public:
    //Princess(const string& name) : name(name), spouse(nullptr) {}
    // Princess(const string& name) : name(name) {
    //     spouse = nullptr;
    // }
    Princess(const string& name);

    // void marries(FrogPrince& betrothed) {
    //     spouse = &betrothed;
    //     //betrothed.spouse = this;
    //     betrothed.setSpouse(this);
    // }
    void marries(FrogPrince& betrothed);
    //    const string& getName() const { return name; }
    const string& getName() const;
    
private:
    string name;
    FrogPrince* spouse;
    //    FrogPrince spouse;
};

class FrogPrince {
    friend ostream& operator<<(ostream& os, const FrogPrince& frog);
public:
    FrogPrince(const string& name);
    void setSpouse(Princess* betrothed);
    const string& getName() const;
private:
    string name;
    Princess* spouse;
};

// void Princess::marries(FrogPrince& betrothed) {
//     spouse = &betrothed;
//     //betrothed.spouse = this;
//     betrothed.setSpouse(this);
// }


int main() {
    Princess snowy("Snow White");
    cout << snowy << endl;
    FrogPrince froggy("Froggy");
    cout << froggy << endl;
    snowy.marries(froggy);
    cout << snowy << endl
         << froggy << endl;
}

//
// Princess Code
//
Princess::Princess(const string& name) : name(name), spouse(nullptr) {}

ostream& operator<<(ostream& os, const Princess& princess) {
    os << "Princess: " << princess.name << ", ";
    if (princess.spouse) {
        cout << "Married to: " << princess.spouse->getName();
    }
    else {
        cout << "Single";
    }
    return os;
}

const string& Princess::getName() const { return name; }

void Princess::marries(FrogPrince& betrothed) {
    spouse = &betrothed;
    //betrothed.spouse = this;
    betrothed.setSpouse(this);
}

//
// Frog Prince Code
//
ostream& operator<<(ostream& os, const FrogPrince& frog) {
    os << "Frog Prince: " << frog.name << ", ";
    if (frog.spouse) {
        cout << "Married to: " << frog.spouse->getName();
    }
    else {
        cout << "Single";
    }
    return os;
}

FrogPrince::FrogPrince(const string& name) : name(name), spouse(nullptr) {}

void FrogPrince::setSpouse(Princess* betrothed) {
    spouse = betrothed;
}

const string& FrogPrince::getName() const { return name; }

/*
Each class has a pointer to the "other" class for spouse
To marry:
Princess gets pointer to FrogPrince
FrogPrince gets direct Princess reference
This makes them point to each other, forming the relationship
The pointers allow the two objects to access each other's state 
    and form a circular reference or "relationship".
*/
