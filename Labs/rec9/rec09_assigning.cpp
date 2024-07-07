#include <string>
#include <vector>
using namespace std;

class Base{};
class Derived:public Base{};

int main(){
    Base b;
    Derived d;

    Base* bp = nullptr;
    Derived* dp = nullptr;

    b = d; // Can assign base object to derived
    // d = b; // Cannot assign derived object to base

    bp = dp; // Base pointer can point to Derived pointer
    // dp = bp; // Derived Pointer cannot be assigned to Base Pointer

    bp = &d; // Base pointer can point to the adress of derived object
    // dp = &b; // Derived pointed cannot be pointed to the address of the base object
}