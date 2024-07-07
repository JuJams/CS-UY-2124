/*
 hw03.cpp
 Data hiding, encapsulation, delegation, 
 overloading the output operator Battle Simulation
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// To assign a weapon for a warrior
class Warrior {
    
    class Weapon{

        // Overloading output operator for weapon
        friend ostream& operator<<(ostream& os, const Warrior::Weapon& theWeapon);
        public:
            // Constructor for weapon
            Weapon(const string& theName, int theStrength): nameOfWeapon(theName), 
            strengthOfWeapon(theStrength){}
            int getStrength() const{
                return strengthOfWeapon;
            }
            void setStrength(int SetS){
                strengthOfWeapon = SetS;
            }
        private:
            string nameOfWeapon;
            int strengthOfWeapon;

    };

    // Overloading output operator for warrior and weapon
    friend ostream& operator<<(ostream& os, const Warrior& theWarrior);
    friend ostream& operator<<(ostream& os, const Warrior::Weapon& theWeapon);
    string name;
    Weapon weapon;

    
    
    public:
        // Constructor for warrior
        Warrior(const string& theName, const string& theWeapon, int theStrength):
         name(theName), weapon(theWeapon,theStrength){}
        string getName() const{
            return name;
        }
        int getStrength() const{
            return weapon.getStrength();
        }
        void setStrength(int theStrength){
            weapon.setStrength(theStrength);
        }
};

// Function Prototypes
bool warrior_check(const vector<Warrior>& warriors, const string& name);
int warrior_find(const vector<Warrior>& warriors, const string& name);
void battle(vector<Warrior>& warriors, int warrior_1, int warrior_2);
void warrior_create(vector<Warrior>& warriors, const string& name, const string&weap,int strength);
void display_warrior(const vector<Warrior>& warriors);
void battle_run(ifstream& ifs, vector<Warrior>& warriors);



int main() {
    vector<Warrior> warriors;
    ifstream ifs("warriors.txt");

    if (!ifs){
        cerr<<"Error:Unable to open warriors.txt\n";
        return 1;
    }
    battle_run(ifs,warriors);
    ifs.close();
    return 0;
}

// To see if the warrior already exists in the warrior of vectors
// Parameters: vector of Warrior struct, name of the warrior
// Return type: bool
bool warrior_check(const vector<Warrior>& warriors, const string& name){
    for(const Warrior& warrior:warriors){
        if(warrior.getName()==name){
            cerr<<"Error: Warrior with name '"<<name<<"' already exists\n";
            return true;
        }
    }
    return false;
}

// To find the index of the warrior's name in the vector
// Parameters: vector of Warrior struct, name of the warrior to find
// Return type: int - index of the warrior
int warrior_find(const vector<Warrior>& warriors,const string& name){
    for (int people = 0;people<warriors.size();++people){
        if (warriors[people].getName()==name){
            return people;
        }
    }
    cerr<<"Error: Warrior with name '"<< name<< "' not found\n";
    return -1;
}

// To start a battle
// Parameters: vector of Warrior struct, index of warriors
// Return Type: void
void battle(vector<Warrior>& warriors,int warrior_1,int warrior_2){
    if(warriors[warrior_1].getStrength()==0 && warriors[warrior_2].getStrength()==0){
        cout<<"Oh, NO! They're both dead! Yuck!\n";
    } else if(warriors[warrior_1].getStrength()==0){
        cout<<"He's dead, "<<warriors[warrior_2].getName()<<endl;
    } else if(warriors[warrior_2].getStrength()==0){
        cout<<"He's dead, "<<warriors[warrior_1].getName()<<endl;
    } else{
        if(warriors[warrior_1].getStrength()> warriors[warrior_2].getStrength()){
            warriors[warrior_1].setStrength(warriors[warrior_1].getStrength()-
            warriors[warrior_2].getStrength());
            warriors[warrior_2].setStrength(0);
            cout<<warriors[warrior_1].getName()<<" defeats "<<warriors[warrior_2].getName()<<endl;
        } else if(warriors[warrior_2].getStrength()>warriors[warrior_1].getStrength()){
            warriors[warrior_2].setStrength(warriors[warrior_2].getStrength()- 
            warriors[warrior_1].getStrength());
            warriors[warrior_1].setStrength(0);
            cout<<warriors[warrior_2].getName()<<" defeats "<<warriors[warrior_1].getName()<<endl;
        } else{
            warriors[warrior_1].setStrength(0);
            warriors[warrior_2].setStrength(0);
            cout<<"Mutual Annihilation: "<<warriors[warrior_1].getName()<<" and "
            <<warriors[warrior_2].getName()<<" die at each other's hands\n";
        }
    }
}


// To add a new warrior to the vector of warriors
// Parameters: vector of Warrior struct, name of the new warrior,
//             name of the weapon, strength of the weapon
// Return type: void
void warrior_create(vector<Warrior>& warriors,const string& name,const string& weap,int strength) {
    if (!warrior_check(warriors,name)) {
        warriors.push_back({name,weap,strength});
    }
}

// To display the levels of all warriors in the vector
// Parameters: vector of Warrior struct
// Return type: void
void display_warrior(const vector<Warrior>& warriors) {
    cout << "There are: "<<warriors.size()<<" warriors\n";
    for(const Warrior& warrior:warriors){
        cout << warrior;
    }
}

// To go through the text file
// Parameters: file name, vector of Warrior struct
// Return type: void
void battle_run(ifstream& ifs,vector<Warrior>& warriors){
    string check;
    while(ifs>>check){
        if(check == "Warrior"){
            string name,weap;
            int strength;
            ifs>>name>>weap>>strength;
            warrior_create(warriors,name,weap,strength);
        } else if(check == "Battle"){
            string warrior1,warrior2;
            ifs>>warrior1>>warrior2;
            int first = warrior_find(warriors,warrior1);
            int second = warrior_find(warriors,warrior2);
            if (first != -1 && second != -1){
                cout<<warriors[first].getName()<<" battles "<<warriors[second].getName()<<endl;
                battle(warriors,first,second);
            } else {
                cerr << "Error: One or both warriors do not exist for battle\n";
            }
        } else if (check == "Status"){
            display_warrior(warriors);
        } else{
            cerr<<"Error: Invalid command '"<<check<<"'\n";
            break;
        }
    }
}

// Overloading output operator for showing warrior information
ostream& operator<<(ostream& os, const Warrior& theWarrior){
    os << "Warrior: " << theWarrior.name << ", " << theWarrior.weapon;
    return os;
}

// Overloading output operator for showing weapon information
ostream& operator<<(ostream& os, const Warrior::Weapon& theWeapon) {
    os << "weapon: " << theWeapon.nameOfWeapon << ", " << theWeapon.strengthOfWeapon 
    << endl;
    return os;
}