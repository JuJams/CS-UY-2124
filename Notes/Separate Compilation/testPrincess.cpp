/*
    testPrincess.cpp
    Cyclic Association
    InClass Base
*/

#include "Princess.h"
#include "Princess.h"
#include "FrogPrince.h"
#include <iostream>
#include <string>
#include <string>
using namespace std;
using namespace Fantasy;

int main() {
    Princess snowy("Snow White");
    FrogPrince froggy("Froggy");
    cout << snowy << endl
         << froggy << endl;
    snowy.marries(froggy);
    cout << snowy << endl
         << froggy << endl;
}


