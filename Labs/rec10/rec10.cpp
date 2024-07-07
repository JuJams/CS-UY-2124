/*
    rec10.cpp
    More on Inheritance and Polymorphism
*/

#include <iostream>
#include <vector>
using namespace std;

// Base class Instrument
class Instrument{
    friend ostream& operator<<(ostream& os, const Instrument& instr);
    public:
        virtual void makeSound() const = 0;
        virtual void play() const =0 ;
        virtual void display() const = 0;

};

void Instrument::makeSound() const{
    cout<<"Making a sound...";
}

// Derived Brass class from Instrument
class Brass: public Instrument{
    public:
        // Brass constrcutor taking mouthpiece size
        Brass(unsigned mouthpiece_size):mouthpiece(mouthpiece_size){}
        // To print out the mouthpiece size using the virtual makeSound() method
        void makeSound() const{
            Instrument::makeSound();
            cout<<" blow on a mouthpiece of size "<< mouthpiece<< endl;

        }
    protected:
        // Can be accessed by derived classes
        unsigned getMouthpiece() const{ return mouthpiece;}
    private:
        unsigned mouthpiece;
};

// Derived String class from Instrument
class String: public Instrument{
    public:
        // String constructor taking pitch
        String(unsigned pitch): pitch(pitch){}
        // To print out the pitch using the virtual makeSound() method
        void makeSound() const{
            Instrument:: makeSound();
            cout<<" bow a string with pitch "<< pitch<<endl;
        }
    protected:
        // Can be accessed by derived classes
        unsigned getPitch() const{ return pitch;}
    private:
        unsigned pitch;
};

// Derived Percussion class from Instrument
class Percussion: public Instrument{
    public:
        // To print out the message using the virtual makeSound() method
        void makeSound() const{
            Instrument::makeSound();
            cout<< " hit me!"<<endl;
        }
};

// Derived class from Brass 
class Trumpet : public Brass {
    public:
        // Using the constructor from the parent class Brass
        using Brass::Brass;
        // To printout what the instrument plays
        void play() const{
            cout << "Toot";
        }
        // To printout the instrument name after playing
        void display() const {
            cout<< "Trumpet: " << getMouthpiece()<<"\t";
        }
        
};

// Derived class from Brass 
class Trombone : public Brass {
    public:
        // Using the constructor from the parent class Brass
        using Brass::Brass;
        // To printout what the instrument plays
        void play() const{
            cout << "Blat";
        }
        // To printout the instrument name after playing
        void display() const {
            cout<< "Trombone: " << getMouthpiece()<<"\t";
        }
};

// Deived class from String
class Violin : public String {
    public:
        // Constructor from parent class String
        using String::String;
        // To printout what the instrument plays
        void play() const{
            cout << "Screech";
        }
        // To print out the instrument name after playing
        void display() const {
            cout<< "Violin: " << getPitch()<<"\t";
        }
};

// Derived class from String
class Cello : public String {
    public:
        // Constructor from parent class String
        using String::String;
        // To printout what the instrument plays
        void play() const{
            cout << "Squawk";
        }
        // To print out the instrument name after playing
        void display() const {
            cout<< "Cello: " << getPitch()<<"\t";
        }
};

// Derived class from Percussion
class Drum : public Percussion{
    public:
        // Constructor from parent class Percussion
        using Percussion::Percussion;
        // To print out what the instrument plays
        void play() const{
            cout << "Boom";
        }
        // To print out the instrument name after playing
        void display() const {
            cout<< "Drum" <<"\t";
        }
};

// Derived class from Percussion
class Cymbal: public Percussion{
    public:
        // Constructor from parent class Percussion
        using Percussion::Percussion;
        // To print out what the instrument plays
        void play() const{
            cout << "Crash";
        }
        // To print out the instrument name after playing
        void display() const {
            cout<< "Cymbal"<<"\t";
        }
};


// MILL class represents a musical instrument lending library.
// It stores Instruments in a vector of pointers and allows borrowing/returning them
class MILL{
    public:
     friend ostream& operator<<(ostream& os, const MILL& mill);
        // To recieve or add instruments to the inventory
        void receiveInstr(Instrument& instrument){
            instrument.makeSound();
            for (size_t i = 0; i< inventory.size();i++){
                if (!inventory[i]){
                    inventory[i] = &instrument;
                    return;
                }
            }
            inventory.push_back(&instrument);
        }

        // Lending out instruments from inventory
        Instrument* loanOut(){
            for (size_t i = 0; i<inventory.size(); i++){
                if (inventory[i] != nullptr){
                    Instrument* instPtr = inventory[i];
                    inventory[i] = nullptr;
                    return instPtr;
                }
            }
            return nullptr;
        }

        // To tets play all instruments in the inventory
        void dailyTestPlay() const{
            for (size_t i =0; i<inventory.size();i++){
                if (inventory[i]){
                    inventory[i]->makeSound();
                }
            }
        }


    private:
        vector<Instrument*> inventory;
};

// 
// Musician class as provided to the students. Requires an Instrument class.
// 

class Musician {
public:
    Musician(const string& name) : instr(nullptr), name(name) {}

    // acceptInstr takes in an instrument for the Musician to later play.
    //  "loses" any instrument that it used to have.
    void acceptInstr(Instrument* instPtr) { instr = instPtr; }

    // giveBackInstr: gives the instrument that the Musicial was holding "back"
    Instrument* giveBackInstr() { 
        Instrument* result(instr); 
        instr = nullptr;
        return result;
    }

    // testPlay: testing out my instrument
    void testPlay() const {
        if (instr) instr->makeSound(); 
        else cerr << name << " has no instr\n";
    }

    // play: play the instrument

    //   Not making it const so that Instrument::play method does not
    //   need to be const. Allows the instrument to be modifed in the
    //   process of being played.
    void play() {
        if (instr) instr->play();
        // Don't do anything if we don't have an instrument.
    }
private:
    Instrument* instr;
    string name;
};

// Orch class represents an orchestra containing musicians
// Allows adding musicians and having all musicians play together
class Orch{
public:
    // To add a musician to the orchestra's collection
    void addPlayer(Musician& aMusician) { 
        musicians.push_back(&aMusician); 
        }
    // To let all the musicians in the orchestra play their instruments 
    // together by looping through 
    // musician pointers and calling play on each of them
    void play() const {
        for (Musician* musiptr : musicians) {
            musiptr->play();
        }
        cout << endl;
    }
private:
    vector<Musician*> musicians;
};

int main() {

    //
    // PART ONE
    //
    cout << "P A R T  O N E\n";

    cout << "Define some instruments ---------------------------------------\n";
    Drum drum;
    Cello cello(673);
    Cymbal cymbal;
    Trombone tbone(4);
    Trumpet trpt(12) ;
    Violin violin(567) ;
  
    cout << "Define the MILL -----------------------------------------------\n";
    MILL mill;
    cout << "The MILL before adding instruments:\n" << mill << "\n\n";

    cout << "Put the instruments into the MILL -----------------------------\n";
    mill.receiveInstr(trpt);
    mill.receiveInstr(violin);
    mill.receiveInstr(tbone);
    mill.receiveInstr(drum);
    mill.receiveInstr(cello);
    mill.receiveInstr(cymbal);
    cout << "\nThe MILL after adding some instruments:\n" << mill << "\n\n";
  
    cout << "Daily test ----------------------------------------------------\n"
	 << "dailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;
  
    cout << "Define some Musicians------------------------------------------\n";
    Musician harpo("Harpo");
    Musician groucho("Groucho");
  	
    cout << "TESTING: groucho.acceptInstr(mill.loanOut());---------------\n";
    groucho.testPlay();	 // Groucho doesn't have an instrument yet.

    groucho.acceptInstr(mill.loanOut());
    groucho.testPlay();

    cout << "\ndailyTestPlay()" << endl;
    mill.dailyTestPlay();
    cout << endl;
  
    groucho.testPlay();	
    mill.receiveInstr(*groucho.giveBackInstr());
    harpo.acceptInstr(mill.loanOut());
    groucho.acceptInstr(mill.loanOut());
    groucho.testPlay();
    harpo.testPlay();

    cout << "\ndailyTestPlay()" << endl;
    mill.dailyTestPlay();

    cout << "\nThe MILL after giving out some instruments:\n";
    cout << mill << "\n\n";

    cout << "TESTING: mill.receiveInstr(*groucho.giveBackInstr()); ------\n";
    mill.receiveInstr(*groucho.giveBackInstr());

    cout << "TESTING: mill.receiveInstr(*harpo.giveBackInstr()); ------\n";
    mill.receiveInstr(*harpo.giveBackInstr());
    cout << endl;

    cout << "dailyTestPlay()" << endl;
        mill.dailyTestPlay();
  
    cout << "\nThe MILL at the end of Part One:\n";
    cout << mill << endl;

    //
    
    
    // PART TWO
    //
    cout << "\nP A R T  T W O\n";
    
    Musician bob("Bob");
    Musician sue("Sue");
    Musician mary("Mary");
    Musician ralph("Ralph");
    Musician jody("Judy");
    Musician morgan("Morgan");

    Orch orch;

    // THE SCENARIO

    //Bob joins the orchestra without an instrument.
    orch.addPlayer(bob);

    //The orchestra performs
    cout << "orch performs\n";
    orch.play();

    //Sue gets an instrument from the MIL2 and joins the orchestra.
    sue.acceptInstr(mill.loanOut());
    orch.addPlayer(sue);

    //Ralph gets an instrument from the MIL2.
    ralph.acceptInstr(mill.loanOut());

    //Mary gets an instrument from the MIL2 and joins the orchestra.
    mary.acceptInstr(mill.loanOut());
    orch.addPlayer(mary);

    //Ralph returns his instrument to the MIL2.
    mill.receiveInstr(*ralph.giveBackInstr());

    //Jody gets an instrument from the MIL2 and joins the orchestra.
    jody.acceptInstr(mill.loanOut());
    orch.addPlayer(jody);

    // morgan gets an instrument from the MIL2
    morgan.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Ralph joins the orchestra.
    orch.addPlayer(ralph);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();
	
    // bob gets an instrument from the MIL2
    bob.acceptInstr(mill.loanOut());

    // ralph gets an instrument from the MIL2
    ralph.acceptInstr(mill.loanOut());

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    //Morgan joins the orchestra.
    orch.addPlayer(morgan);

    //The orchestra performs.
    cout << "orch performs\n";
    orch.play();

    cout << endl << mill << endl;
    
}

// Instrument output operator
ostream& operator<<(ostream& os, const Instrument& instr){
    instr.display();
    return os;
}

// MILL output operator
ostream& operator<<(ostream& os, const MILL& mill){
    os<< "The MILL has the following instruments: ";
    bool isEmpty = true;         
    if (mill.inventory.size()!=0){
         
        for(size_t i = 0; i < mill.inventory.size(); i++){
            if (mill.inventory[i]){
                cout<<endl<<"\t";
                mill.inventory[i]->display();
                isEmpty = false;
            }   
        }   
    }
    else if (mill.inventory.size()==0) {
        os << "None" << endl;
        
    }
     
    if (isEmpty) cout << "None" << endl;
    return os;
}