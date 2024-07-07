// Task 1
// rec04.cpp
// Rec 04: Pointer Tutorial

#include <iostream>   
#include <vector>     
using namespace std;  

// Task 16 
struct Complex {
    double real;
    double img;
};

// Task 17 
class PlainOldClass {
public:
    PlainOldClass() : x(-72) {}
    int getX() const { return x; }
    void setX( int val )  { x = val; }
private:
    int x;
};

// Task 18 

class PlainOldClassV2 {
public:
    PlainOldClassV2() : x(-72) {}
    int getX() const { return x; }
    void setX( int x )  { this->x = x; }
private:
    int x;
};

// Task 28 
 class Colour {
    public:
    Colour(const string& name, unsigned r, unsigned g, unsigned b)
    : name(name), r(r), g(g), b(b) {}
    void display() const {
        cout << name << " (RBG: " << r << "," << g<< "," << b << ")";
        }
 private:
    string name;      
    unsigned r, g, b; 
 };


// Task 29 
class SpeakerSystem {
public:
    void vibrateSpeakerCones(unsigned signal) const {

        cout << "Playing: " << signal << "Hz sound..." << endl;
        cout << "Buzz, buzzy, buzzer, bzap!!!\n";
    }
};

class Amplifier {
public:
    void attachSpeakers(SpeakerSystem& spkrs)
    {
        if(attachedSpeakers) {
            cout << "already have speakers attached!\n";
        } else {
            attachedSpeakers = &spkrs;
        }
    }

    void detachSpeakers() { // should there be an "error" message if not attached?
        attachedSpeakers = nullptr;
    }

    void playMusic( ) const {
        if (attachedSpeakers) {
            attachedSpeakers -> vibrateSpeakerCones(440);
        } else {
            cout << "No speakers attached\n";
        }
    }
private:
    SpeakerSystem* attachedSpeakers = nullptr;
};


// Task 30 Person Definition
class Person {
public:
    Person(const string& name) : name(name), roomie(nullptr) {}

    void movesInWith(Person& newRoomate) {
        // Check if newRoomate is a Person object
        if (!roomie && !newRoomate.roomie && this != &newRoomate) { // to-do: add condition to check bf moving in 
            roomie = &newRoomate;        
            newRoomate.roomie = this;    
        } else {
            cout << "Invalid roommate! You can only move in with another Person." << endl;
        }
    }

    const string& getName() const {return name;}
    const string& getRoomiesName() const {
        return roomie->getName();
        
    }

private:
    Person* roomie;
    string name;
}; 


int main() {
    // Task 2
    cout << "Task 2"<<endl;
    int x;
    x = 10;
    cout << "x = " << x << endl;


    // Task 3 
    cout << "Task 3"<<endl;
    // Using the debugger and running. Initial x: -2017411116


    // Task 4
    cout << "Task 4"<<endl;
    // Step Over..moved to the next statement.

    // Task 5
    cout << "Task 5"<<endl;
    // Watch, x: 10

    // Task 6
    cout << "Task 6"<<endl;
    // Address of x: 0x000000016fdff3ac (Hexadecimal digits)

    // Task 7
    cout << "Task 7"<<endl;
    // Watch under &x: *$1: 10

    // Task 8
    cout << "Task 8"<<endl;
    int *p;
    p = &x;
    cout << "p = " << p << endl;
    
    // Task 9
    cout << "Task 9"<<endl;
    //p = 0x16b0cb3fc; //error: incompatible integer to pointer conversion

    // Task 10
    cout << "Task 10"<<endl;
    cout << "p = " << p << endl;
    //In variables local window, *p now is 10
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p contains " << *p << endl;


   // Task 11
    cout << "Task 11"<<endl;
    *p = -2763;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "x now contains " << x << endl;
    //Values of x,p, *p changed to -2763

    // Task 12
    cout << "Task 12"<<endl;
    int y(13);
    cout << "y contains " << y << endl;
    p = &y;
    cout << "p now points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    *p = 980;
    cout << "p points to where " << *p << " is stored\n";
    cout << "*p now contains " << *p << endl;
    cout << "y now contains " << y << endl;


    // Task 13
    cout << "Task 13"<<endl;
    int *q;
    q = p;
    cout << "q points to where " << *q << " is stored\n";
    cout << "*q contains " << *q << endl;
    //Values of p,q,y are same as y: 980


    // Task 14
    cout << "Task 14"<<endl;
    double d(33.44);
    double *pD(&d);
    *pD = *p;
    *pD = 73.2343;
    *p = *pD;
    *q = *p;
    //pD = p;
    //p = pD;


    // Task 15
    cout << "Task 15"<<endl; 
    int joe = 24;
    const int sal = 19;
    int *pI;
    pI = &joe;
    *pI = 234;
    //pI = &sal; //pI is initiliaized as an integer pointer, however, the address of Sal contains a
    *pI = 7623;

    const int *pcI;
    pcI = &joe;
    //*pcI = 234;  // Declared pcI as a pointer that points to a const int, and this line attempts to modify the content inside
    pcI = &sal;
    //*pcI = 7623; // Declared pcI as a pointer that points to a const int, and this line attempts to modify the content inside
    
    //int* const cpI; //declares a constant pointer cpI but doesn't initialize it to point to an integer, which is required for a constant pointer declaration.
    int *const cpI(&joe);
    //int* const cpI(&sal); // &sal contains a value of const int, however, in the initialization of the pointer is solely for an int value.
    //cpI = &joe; //cpI is a constant pointer, it cannot be reassigned to point to a different memory location.
    *cpI = 234;
    //cpI = &sal; // cpl is a pointer to a const int, this is trying to modify that int value
    *cpI = 7623;
    
    //const int* const cpcI; // This constant pointer points to a constant int, however it needs to be initialized.
    const int *const cpcI(&joe);
    //const int* const cpcI(&sal); // cannot redefine cpcI because it is a constant pointer, meaning it cannot change what it's pointing to.
    //cpcI = &joe;  //cannot redefine the integer value because cpcI points to a constant integer, it cannot be changed.
    //*cpcI = 234; // cpcI is constant pointer to a constant integer, which means you cannot modify the value it points to.
    //cpcI = &sal; //cannot redefine the integer value because cpcI points to a constant integer, it cannot be changed.
    //*cpcI = 7623; // cpcI is constant pointer to a constant integer, which means you cannot modify the value it points to.


    // Task 16
    cout << "Task 16"<<endl; 
    Complex c = {11.23, 45.67};
    Complex *pC(&c);
    //cout << "real: " << *pC.real << "\nimaginary: " << *pC.img << endl;
    //cout << "real: " << (*pC).real << "\nimaginary: " << (*pC).img << endl;
    cout << "real: " << pC->real << "\nimaginary: " << pC->img << endl;
    //pc-> real value under watch is 11.23
    
    
    // Task 17
    cout << "Task 17"<<endl;
    PlainOldClass poc; //Creates a PlainOldClass Object
    PlainOldClass *ppoc(&poc); //Creates a pointer which points to the PlainOldClass object's address.
    cout << ppoc->getX() << endl; // Displays the x value of ppoc through dereferencing
    ppoc->setX(2837); // Changes the value of x to 2837
    cout << ppoc->getX() << endl; // Displays the x value of ppoc through dereferencing
    
    // Task 18
    cout << "Task 18"<<endl;
    PlainOldClassV2 pocV2; //Creates a PlainOldClass Object
    PlainOldClassV2 *ppocV2(&pocV2); //Creates a pointer that points to the PlainOldClass object's address.
    cout << ppoc->getX() << endl; // Displays the x value of ppoc through dereferencing
    ppoc->setX(2837); // Changes the value of x to 2837
    cout << ppoc->getX() << endl;
    
    // Task 19
    cout << "Task 19"<<endl;
    int *pDyn = new int(3); // p points to an int initialized to 3 on the heap
    *pDyn = 17;
    cout << "The " << *pDyn //Shows *pDyn as 17
         << " is stored at address " << pDyn
         << " which is in the heap\n";
         
    
    // Task 20
    cout << "Task 20"<<endl;
    cout << pDyn << endl;
    delete pDyn;
    cout << pDyn << endl;
    cout << "The 17 might STILL be stored at address " << pDyn << " even though we deleted pDyn\n";
    cout << "But can we dereference pDyn?  We can try.  This might crash... " << *pDyn << ".  Still here?\n";
    
    // Task 21
    cout << "Task 21"<<endl;
    pDyn = nullptr;
    double *pDouble = nullptr;


    // Task 22
    cout << "Task 22"<<endl;
    //cout << "Can we dereference nullptr?  " << *pDyn << endl;
    //cout << "Can we dereference nullptr?  " << *pDouble << endl;
    
    // Task 23
    cout << "Task 23"<<endl;
    // This always points to 
    //the object instance being operated on within a member function.


    // Task 24
    cout << "Task 24"<<endl;
    double *pTest = new double(12);
    delete pTest;
    pTest = nullptr;
    delete pTest; // safe


    // Task 25
    cout << "Task 25"<<endl;
    short *pShrt = new short(5);
    delete pShrt;
    //delete pShrt; (Did not crash this time)


    // Task 26
    cout << "Task 26"<<endl;
    long jumper = 12238743;
    //delete jumper; (only with dynamic memory
    long *ptrTolong = &jumper;
    //delete ptrTolong;  // What happens here?
    Complex cmplx;
    //delete cmplx;      // What happens here?
    
    
    // Task 27
    cout << "Task 27"<<endl;
    vector<Complex*> complV; // can hold pointers to Complex objects
    Complex* tmpPCmplx;      // space for a Complex pointer
    for (size_t ndx = 0; ndx < 3; ++ndx) {
        tmpPCmplx = new Complex; // create a new Complex object on the heap
        tmpPCmplx->real = ndx;   // set real and img to be the
        tmpPCmplx->img  = ndx;   // value of the current ndx
        complV.push_back(tmpPCmplx); // store the ADDRESS of the object in a vector or pointer to Complex
    }      
    // display the objects using the pointers stored in the vector
    for (size_t ndx = 0; ndx < 3; ++ndx) {         
        cout << complV[ ndx ]->real << endl;         
        cout << complV[ ndx ]->img  << endl;      
    }      
    // release the heap space pointed at by the pointers in the vector      
    for (size_t ndx = 0; ndx < 3; ++ndx) {         
        delete complV[ndx];
    }      
    // clear the vector      
    complV.clear();


  
    // Task 28
    cout << "Task 28"<<endl;
    vector<Colour*> colours;
    string inputName;
    unsigned inputR, inputG, inputB;

    // fill vector with Colours from the file
    // this could be from an actual file but here we are using the keyboard instead of a file
    // (so we don't have to create an actual file)
    // Do you remember the keystroke combination to indicate "end of file" at the keyboard?
    // somehow the while's test has to fail - from keyboard input
    while (cin >> inputName >> inputR >> inputG >> inputB) {
    colours.push_back(new Colour(inputName, inputR, inputG, inputB));
    }

    // display all the Colours in the vector:
    for (size_t ndx = 0; ndx < colours.size(); ++ndx) {
         colours[ndx]->display();
         cout << endl;
    }

    // Task 29
    cout << "Task 29"<<endl;
    


    // Task 30
    cout << "Task 30"<<endl;
    // write code to model two people in this world
    Person joeBob("Joe Bob"), billyJane("Billy Jane");
    // now model these two becoming roommates
    joeBob.movesInWith(billyJane);
    // did this work out?
    cout << joeBob.getName() << " lives with " << joeBob.getRoomiesName() << endl;
    cout << billyJane.getName() << " lives with " << billyJane.getRoomiesName() << endl; 
} 
