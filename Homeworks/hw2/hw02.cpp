/*
 hw02.cpp
 Functions, structs, vectors and file I/O
 Battle Simulation
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

struct Warrior {
    string name;
    int strength;
};

//Function Prototypes
bool warrior_check(const vector<Warrior>& warriors, const string& name);
int warrior_find(const vector<Warrior>& warriors, const string& name);
void battle(vector<Warrior>& warriors, int warrior_1, int warrior_2);
void warrior_create(vector<Warrior>& warriors, const string& name, int strength);
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

// To if the warrior already exists in the warrior of vectors
// Parameters: vector of Warrior struct, name of the warrior
// Return type: bool
bool warrior_check(const vector<Warrior>& warriors, const string& name){
    for(const Warrior& warrior:warriors){
        if(warrior.name==name){
            cerr<<"Error: Warrior with name '"<<name<<"' already exists\n";
            return true;
        }
    }
    return false;
}

//To find the index of the warrior's name in the vector
//Parameters: vector of Warrior struct, name of the warrior to find
//Return type: int - index of the warrior
int warrior_find(const vector<Warrior>& warriors,const string& name){
    for (size_t people = 0;people<warriors.size();++people){
        if (warriors[people].name==name){
            return people;
        }
    }
    cerr<<"Error: Warrior with name '"<< name<< "' not found\n";
    return -1;
}

//To start a battle
//Parameters: vector of Warrior struct, index of warriors
//Return Type: void
void battle(vector<Warrior>& warriors,int warrior_1,int warrior_2){
    if(warriors[warrior_1].strength==0 && warriors[warrior_2].strength==0){
        cout<<"Oh, NO! They're both dead! Yuck!\n";
    } else if(warriors[warrior_1].strength==0){
        cout<<"He's dead, "<<warriors[warrior_2].name<<endl;
    } else if(warriors[warrior_2].strength==0){
        cout<<"He's dead, "<<warriors[warrior_1].name<<endl;
    } else{
        if(warriors[warrior_1].strength > warriors[warrior_2].strength){
            warriors[warrior_1].strength -= warriors[warrior_2].strength;
            warriors[warrior_2].strength = 0;
            cout<<warriors[warrior_1].name<<" defeats "<<warriors[warrior_2].name<<endl;
        } else if(warriors[warrior_2].strength>warriors[warrior_1].strength){
            warriors[warrior_2].strength -= warriors[warrior_1].strength;
            warriors[warrior_1].strength = 0;
            cout<<warriors[warrior_2].name<<" defeats "<<warriors[warrior_1].name<<endl;
        } else{
            warriors[warrior_1].strength = 0;
            warriors[warrior_2].strength = 0;
            cout<<"Mutual Annihilation: "<<warriors[warrior_1].name<<" and "<<warriors[warrior_2].name<<" die at each other's hands\n";
        }
    }
}


// To add a new warrior to the vector of warriors
// Parameters: vector of Warrior struct, name of the new warrior, strength
// Return type: void
void warrior_create(vector<Warrior>& warriors,const string& name,int strength) {
    if (!warrior_check(warriors, name)) {
        warriors.push_back({name, strength});
    }
}

// To display the levels of all warriors in the vector
// Parameters: vector of Warrior struct
// Return type: void
void display_warrior(const vector<Warrior>& warriors) {
    cout << "There are: "<<warriors.size()<<" warriors\n";
    for(const Warrior& warrior:warriors){
        cout<<"Warrior: "<<warrior.name<<", strength: "<<warrior.strength<<endl;
    }
}

// To go through the text file
// Parameters: file name, vector of Warrior struct
// Return type: void
void battle_run(ifstream& ifs,vector<Warrior>& warriors){
    string check;
    while(ifs>>check){
        if(check == "Warrior"){
            string name;
            int strength;
            ifs>>name>>strength;
            warrior_create(warriors,name,strength);
        } else if(check == "Battle"){
            string warrior1,warrior2;
            ifs>>warrior1>>warrior2;
            int first = warrior_find(warriors,warrior1);
            int second = warrior_find(warriors,warrior2);
            if (first != -1 && second != -1){
                cout<<warriors[first].name<<" battles "<<warriors[second].name<<endl;
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
