/*
  hw07_single.cpp
  Cyclic Association and Separate Compilation
 */

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class Noble;

class Warrior{

    //Output Operator prototype
        
    friend ostream& operator<<(ostream& os, const Warrior& warrior);


    public:

        // Warior Constructor
        Warrior(const string& name, int isStrength);
        // Getters and Setters
        const string& getName() const;
        int getStrength() const;
        bool isHired() const;

        void changeHiredStatus();
        void setNoble(Noble* nob);
        void setStrength(int isStrength);
        
        Noble* getNoble() const;   
        bool runaway();

    private:
    
        string name;
        float strength;
        bool status;
        Noble* theLord;
    
}; 
class Noble{
    //Output Operator prototype 
        friend ostream& operator<<(ostream& os, const Noble& noble);

    public:
    // Noble constructor
        Noble(const string& name);
      // getters and setters
        int getStrength() const;
        const string& getName() const;
        size_t getArmySize() const;
        void kill();
        bool hire(Warrior& warrior);
        bool fire(Warrior& warrior);
        void updateStrength(int winnerStrength, int loseStrength);
        bool getStatus() const ;
        bool leave(Warrior& warrior);
        void setStrength(int winnerStrength, int loseStrength); 
        void battle(Noble& enemy);

           
    private: 
        string name;
        vector<Warrior*> warriors;
        bool life;
    };
    


int main() {
    Noble art("King Arthur");
    Noble lance("Lancelot du Lac");
    Noble jim("Jim");
    Noble linus("Linus Torvalds");
    Noble billie("Bill Gates");

    Warrior cheetah("Tarzan", 4);
    Warrior sky("Leia", 6);
    Warrior wizard("Merlin", 9);
    Warrior jaffa("Teal'c", 9);
    Warrior theGovernator("Conan", 12);
    Warrior nimoy("Spock", 15);
    Warrior lawless("Xena", 20);
    Warrior mrGreen("Hulk", 8);
    Warrior dylan("Hercules", 3);

    jim.hire(nimoy);
    lance.hire(theGovernator);
    art.hire(jaffa);
    art.hire(cheetah);
    art.hire(wizard);
    art.hire(sky);
    lance.hire(dylan);
    linus.hire(lawless);
    billie.hire(mrGreen);
    art.hire(nimoy);

    cout << "================ Initial Status ===============" << endl;
    cout << art << endl
     << lance << endl
     << jim << endl
     << linus << endl
     << billie << endl;
    cout << "===============================================\n\n";

    art.fire(cheetah);
    wizard.runaway();
    cout << endl << art << endl;

    art.battle(lance);
    jim.battle(lance);
    linus.battle(billie);
    billie.battle(lance);

    cout << "\n================ Final Status ===============" << endl;
    cout << art << endl
     << lance << endl
     << jim << endl
     << linus << endl
     << billie << endl;

    // Tarzan and Merlin should be unemployed
    cout << "Tarzan's Hire Status: " << boolalpha 
     << cheetah.isHired() << endl;
    cout << "Merlin's Hire Status: " << boolalpha 
     << wizard.isHired() << endl;
    cout << "===============================================\n\n";
}



//Warrior functions
//constructor
// To initialize a Warrior with a name and strength
// Parameters: Name of the warrior, initial strength
// Return type: None
Warrior::Warrior(const string& name, int isStrength): name(name){
    strength = isStrength;
    status = false;
            }
//getters and setters
// To get the name of the warrior
// Parameters: None
// Return type: const string& (reference to the warrior's name)
const string& Warrior::getName() const {
    return name;
}

// To change the hired status of the warrior
// Parameters: None
// Return type: void
void Warrior::changeHiredStatus(){
    status = !status;
}

// To set the noble for the warrior
// Parameters: Pointer to the noble
// Return type: void
void Warrior::setNoble(Noble* nob) {
    theLord = nob; 
}

// to get the noble of the warrior
// Parameters: None
// Return type: Noble* (pointer to the noble)
Noble* Warrior::getNoble() const { 
    return theLord;    
}    

// To get the strength of the warrior
// Parameters: None
// Return type: int (strength value)
int Warrior::getStrength() const{
    return strength;
}

// To set the strength of the warrior
// Parameters: New strength value
// Return type: void
void Warrior::setStrength(int isStrength){
    strength = isStrength;
}

// To check if the warrior is hired
// Parameters: None
// Return type: bool (true if hired, false otherwise)
bool Warrior::isHired() const{
    return status;
}

// To allow the warrior to leave the noble's army
// Parameters: None
// Return type: bool (true if successfully left, false otherwise)
bool Warrior::runaway(){
    if (strength == 0){
    cout << name << " is already dead!" << endl;
        return false;
    }
    else if(!status){
        cout << name << " isn't hired!" << endl;
        return false;
    }
    else{
        string nobleName = theLord->getName();
        if (theLord->leave(*this)){
            cout << name << " flees in terror, abandoning his lord, "
            << nobleName << endl;
            changeHiredStatus();
            return true;
        }
            return false;
        }
    }


//The following are Noble methods function definitions


// The constructor
// To initialize a Noble with a name
// Parameters: Name of the noble
// Return type: None

Noble::Noble(const string& name) : name(name), life(true){}

// To calculate the total strength of the noble's army
// Parameters: None
// Return type: int (total strength)

int Noble::getStrength() const {
    int total_strength = 0;
    for (Warrior* const ptr : warriors) {
        total_strength += ptr->getStrength();
    }
    return total_strength;
}

// To get the name of the noble
// Parameters: None
// Return type: const string& (reference to the noble's name)

const string& Noble::getName() const{
    return name;
}



// To check if the noble is alive
// Parameters: None
// Return type: bool (true if alive, false otherwise)
bool Noble::getStatus() const { 
    return life;  
}

//To kill the noble and update the strength of all warriors
// Parameters: None
// Return type: void

void Noble::kill() {
    life = false;
    updateStrength(1, 1);
}

// To get the size of the noble's army
// Parameters: None
// Return type: size_t (size of the army)
size_t Noble::getArmySize() const { 
    return warriors.size(); 
} 
// To update the strength of warriors after a battle
// Parameters: Strength of the winning noble, strength of the losing noble
// Return type: void
void Noble::updateStrength(int winnerStrength, int loseStrength) {
    for (Warrior* const& ptr : warriors) {
        int newStrength = ptr->getStrength() * (winnerStrength - 
        loseStrength) /winnerStrength    ;  
        ptr->setStrength(newStrength);
        }
    }

// To hire a warrior into the noble's army
// Parameters: Reference to the warrior to hire
// Return type: bool (true if successfully hired, false otherwise)

bool Noble::hire(Warrior& warrior) {
    if (warrior.isHired()) {
        cout<< name << " failed to hire "<< 
        warrior.getName() <<endl ;  
        return false;           
    }
    else if(!life){
        cout<< name << " failed to hire "<< 
        warrior.getName() <<endl ;  
        return false;  
    }
    warrior.changeHiredStatus();
    warrior.setNoble(this);
    warriors.push_back(&warrior);
    return true;
}

// To fire a warrior from the noble's army
// Parameters: Reference
bool Noble::fire(Warrior& warrior) {
    if (!life) {
        cout << "Noble " << name 
        << " is already dead!" << endl;
        return false;  
    }
    if (leave(warrior)) {
        cout << warrior.getName()<<", you don't work for me anymore ! --" 
        << name << "." << endl;
        warrior.changeHiredStatus();
        return true;
    }
    return false;  
}

// To leave a warrior from the noble's army vector
//Made a leave method to reduce redundant code, leave can be used for runaway as well
bool Noble::leave(Warrior& warrior) {
    for (size_t i = 0; i < warriors.size(); i++) {
        if (warriors[i]->getName() == warrior.getName()) {

            warrior.setNoble(nullptr);
            warriors[i] = warriors.back();  
            warriors.pop_back();
            return (true);

        }
    }
    cout << warrior.getName() << " is not hired by " << name << "!" << endl;
    return (false);  
}
// To set the strength of warriors after a battle
void Noble::setStrength(int winnerStrength, int loseStrength) {
    for (Warrior* ptr : warriors) {
        int newStrength = ptr->getStrength() * (winnerStrength-loseStrength) 
        /winnerStrength;  

        ptr->setStrength(newStrength);
    }
}

        

       
// To know the winner and loser of the battle and update strength
void Noble::battle(Noble& enemy) {
    cout << name << " battles " << enemy.name << endl;
    if (!life && !enemy.life) { // both dead
        cout << "Oh, NO! They're both dead! Yuck!" << endl;
    }
    else if (life && !enemy.life) { 
        cout << "He's dead, " << name << endl;
    }
    else if (!life && enemy.life) {
        cout << "He's dead, " << enemy.name << endl;
    }
    else {  
        int strength1 = getStrength();
        int strength2 = enemy.getStrength();
        if (strength1 > strength2) { 
       
            setStrength(strength1, strength2);
            enemy.kill();
            cout << name << " defeats " << enemy.name << endl;
        }
        else if (strength1 == strength2) {
            kill();
            enemy.kill();
            cout << "Mutual Annihilation: " << name << " and "
            << enemy.name << " die at each other's hands" << endl;
        } 
        else {  
            enemy.setStrength(strength2, strength1);
            kill();
            cout << enemy.name << " defeats " << name << endl;
        }
    }

} 
// Warrior Output Operator
ostream& operator<<(ostream& os, const Warrior& warrior) {
    os << "  " << warrior.name << ": " << warrior.strength;
    return os;
}

// Noble Output Operator
ostream& operator<<(ostream& os, const Noble& noble) {
    os << noble.name << " has an army of " << 
    noble.warriors.size() ;
    for (Warrior* warrior : noble.warriors) {
        if (warrior) {
            os<<endl<< "\t" <<*warrior;
        }
    }
    return os;
}
