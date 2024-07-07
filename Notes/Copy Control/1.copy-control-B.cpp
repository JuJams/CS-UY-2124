/*
  Copy Control (start)
  CS2124
 */

#include <iostream>
using namespace std;

// Thing class has just one field, a pointer an an int on the heap
class Thing {
    friend ostream& operator<<(ostream& os, const Thing& rhs);
public:
    //Thing(int x) { p = new int(x); }
    Thing(int x, const string& s) : s(s) { p = new int(x); }
    void setValue(int val) { *p = val; }
    int getValue() const { return *p; }
    //void cleanUp() { delete p; }
    

    //
    //  Copy Control / BIG 3
    //
    ~Thing() { // No changes needed
        delete p;
        p = nullptr; // optional
    } // Destructor

    //Thing(Thing rhs) {
    // Thing(const Thing& rhs) { // copy constructor
    Thing(const Thing& rhs) : s(rhs.s) { // copy constructor
        p = new int( *rhs.p  );
        //s = rhs.s;
    }

    //aThing = yetAnother; // assignment
    //aThing.operator=(yetAnother)
    //Thing operator=(const Thing& rhs) {
    Thing& operator=(const Thing& rhs) {
        // 0. check for self-assignment
        if ( this != &rhs ) { // test for NOT doing self-assignment
            // 1. deal with potentioal memory leak
            delete p;
            
            // 2. Allocate and copy
            p = new int( *rhs.p  );
            s = rhs.s;
        }
        // 3. return yourself
        return *this;
    }

private:
    int* p;
    string s;
};


// ==== CLient Code ========

void doNothing(Thing another) {}

void simpleFunc() {
    Thing aThing(17, "moe");
    cout << aThing << endl;
    //delete aThing;
    //delete aThing.p;
    //aThing.cleanUp();
    doNothing(aThing);

    Thing yetAnother(28, "curly");
    aThing = yetAnother; // assignment
    //operator=(aThing, yetAnother) // WILL NOT COMPILE
    //aThing.operator=(yetAnother)
    

    Thing moreThings(aThing);
    Thing moreThingsV2  = aThing;
}


int main() {
    simpleFunc();
}

ostream& operator<<(ostream& os, const Thing& rhs) { 
    os << *rhs.p;
    return os;
}
