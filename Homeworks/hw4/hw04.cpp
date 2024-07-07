/*
 hw04.cpp
 Association: Noble - Warrior
 Test code for hw04 included
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Your Noble and Warrior classes should go here.

//Warrior class definition
class Warrior{
     friend ostream& operator<<(ostream& os, const Warrior& warrior); 

public:
     // Warrior Constructor
     // Parameters: name of the warrior, strength
     // Return type: None
     Warrior(string const& warName, double strength):warName(warName), 
     strength(strength), hired(false){}

     // Gets warrior job status
     // Parameters: None
     // Return type: bool

     bool getStatus() const {return hired;} 
     // Sets job to true
     // Parameters: None
     // Return type: void
     void setStatus(){ 
          if (!hired){
               hired = true;
          }
     }
     // Sets job to false
     // Parameters: None
     // Return type: void
     void changeStatus(){ 
          if (hired){
               hired = false;
          }
     }
     // Gets warrior name
     // Parameters: None
     // Return type: const string&
     const string& getName(){return warName;} 
     // Gets strength of warrior
     // Parameters: None
     // Return type: double
     double getStrength() const{return strength;} 
     // Updates strength of warrior
     // Parameters: new strength
     // Return type: void
     void setStrength(double newStrength) {strength = newStrength;} 

private:
     double strength;
     string warName;
     bool hired;
};

// Noble class definition
class Noble{
     friend ostream& operator<<(ostream& os, const Noble& noble); 

public:
    // Noble Constructor
    // Parameters: name of the noble
    // Return type: None  
     Noble(const string& nobName):nobName(nobName),status(true),armyStrength(0){} 
    // Attempts to hire warriors
    // Parameters: warrior to hire
    // Return type: bool
     bool HireWarior(Warrior& warrior) {  
          Warrior* warPtr = &warrior;
          // if warrior is unemployed
          if (!warrior.getStatus() && status){ 
               // adds to army and adds strength to army strength
               army.emplace_back(warPtr); 
               armyStrength += warPtr->getStrength();
               warPtr->setStatus();
               return true;
          }
          else{
               // fails to hire warrior
               cout << nobName << " has failed to hire " 
                    << warrior.getName() << endl; 
               return false;
          }
     }

     // Fires a warrior
     // Parameters: warrior to fire
     // Return type: bool
     bool FireWarrior(Warrior& warrior) {
          if (!status){
               // if noble is dead, fails to fire
               cout << nobName << " failed to fire " 
                    << warrior.getName() << endl; 
               return false;
          }
          bool exist = false;
          // checks if warrior works for Noble
          for (size_t i=0; i< army.size() ; i++){   
               if (warrior.getName() == army[i]->getName()){
               exist = true;
               }
          }
          // if warrior works for noble
          if (exist){ 
               bool fired = false;
               for (size_t i = 0; i < army.size(); i++){
                    if (!fired){
                         if (army[i] == &warrior){}
                         cout << "You don't work for me anymore " 
                              << warrior.getName() 
                         << "! -- " << nobName << ". "<< endl;
                         warrior.changeStatus(); 
                         fired = true;
                    }
                    else{
                         army[i-1] = army[i]; 
                    }
                    armyStrength -= warrior.getStrength(); 
                    army.pop_back();
               }
               return fired;
          }
          else { 
               cout << nobName << " failed to fire "
                     << warrior.getName() << endl;
               return false;
          }
     }

     // Kills nobles and army
     // Parameters: None
     // Return type: void
     void kill(){status = false; armyChanges(1,1);} 
     // Updates army and warrior strength after battle
     // Parameters: strength of winning army, strength of losing army
     // Return type: void
     void armyChanges(double winArmy, double loseArmy){
          int newArmyStrength = 0;
          for (Warrior*& warrior : army){ 
               int newWarStrength=warrior->getStrength()*(winArmy-loseArmy)/winArmy;
               warrior->setStrength(newWarStrength);
               newArmyStrength += newWarStrength; 
          }
          armyStrength = newArmyStrength;
     }

     // Conducts a battle between two nobles
     // Parameters: Noble to battle against
     // Return type: void
     void battle(Noble& noble2){
          cout << nobName << " battles " 
               << noble2.nobName << endl;
          if (!status && !noble2.status){ 
               cout << "Oh, NO!  They're both dead!  Yuck!" 
                    << endl;
          }
          else if (!status && noble2.status){ 
               cout << "He's dead " << noble2.nobName 
                    << endl;
          }
          else if (status && !noble2.status){ 
               cout << "He's dead " << nobName 
                    << endl;
          }
          else {
               if (armyStrength == noble2.armyStrength){ 
                    kill();
                    noble2.kill();
                    cout << "Mutual Annihilation " << nobName << " and " 
                         <<noble2.nobName<< " die at each other's hands"
                         << endl;
               }
               else if (armyStrength > noble2.armyStrength) { 
                    armyChanges(armyStrength, noble2.armyStrength);
                    noble2.kill();
                    cout << nobName <<" defeats "
                         << noble2.nobName << endl;
               }
               else { 
                    armyChanges(noble2.armyStrength, armyStrength);
                    kill();
                    cout << noble2.nobName << " defeats " << nobName 
                         << endl;
               }
          }
     }

private:
     string nobName;
     vector <Warrior*> army;
     bool status;
     double armyStrength;
};

int main() {

     Noble art("King Arthur");
     Noble lance("Lancelot du Lac");
     Noble jim("Jim");
     Noble linus("Linus Torvalds");
     Noble billie("Bill Gates");

     Warrior cheetah("Tarzan", 10);
     Warrior wizard("Merlin", 15);
     Warrior theGovernator("Conan", 12);
     Warrior nimoy("Spock", 15);
     Warrior lawless("Xena", 20);
     Warrior mrGreen("Hulk", 8);
     Warrior dylan("Hercules", 3);

     jim.HireWarior(nimoy);
     lance.HireWarior(theGovernator);
     art.HireWarior(wizard);
     lance.HireWarior(dylan);
     linus.HireWarior(lawless);
     billie.HireWarior(mrGreen);
     art.HireWarior(cheetah);
     art.HireWarior(nimoy);

     cout << "==========\n\n"
          << "Status before all battles, etc.\n";
     cout << jim << endl;
     cout << lance << endl;
     cout << art << endl;
     cout << linus << endl;
     cout << billie << endl;
     cout << "==========\n\n";

     art.FireWarrior(cheetah);
     cout << art << endl;

     lance.FireWarrior(nimoy);
     cout << lance << endl;
     cout << "==========\n\n";

     art.battle(lance);
     jim.battle(lance);
     linus.battle(billie);
     billie.battle(lance);

     cout << "==========\n\n"
          << "Status after all battles, etc.\n";
     cout << jim << endl;
     cout << lance << endl;
     cout << art << endl;
     cout << linus << endl;
     cout << billie << endl;
     cout << "==========\n";
}

// overloading Warrior output operator
ostream& operator<<(ostream& os,const Warrior& warrior){ 
     os << warrior.warName << ": " << warrior.strength;
     return os;
}

// overloading Noble output operator
ostream& operator<<(ostream& os, const Noble& noble){ 
     os << noble.nobName << " has an army of " 
     << noble.army.size() << endl;
     for (size_t i = 0; i <noble.army.size(); i++){
          os << "\t" << *noble.army[i] << endl;
    }
     return os;
}
