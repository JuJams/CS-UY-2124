/*
  3.Bits
  - What is the recursion involved in splitting a non-negative integer
    "apart" into its digits?
  - What about into its bits?
 */

#include <iostream>
using namespace std;

void printDigits(int n) {
    if (n < 10) cout << n;
    else {
        printDigits(n/10);
        cout << n % 10 << ' ';
    }
}

void printDigitsReverse(int n) {
}

void printBits(int n) {
}

int countBits(int n) {
    if (n < 2) return n;
    // int count = countBits(n/2);
    // count += n % 2;
    // return count;
    return (n % 2) + countBits(n/2);
    //cout << n % 2;
}

int main() {
    cout << "printDigits(314159);   ";
    printDigits(314159);
    cout << endl;
    cout << "printDigitsR1(314159); ";
    printDigitsReverse(314159);
    cout << endl;

    cout << "printBits(5): ";
    printBits(5);
    cout << endl;

    cout << "countBits(5): " << countBits(5) << endl;

    cout << "printBits(16): ";
    printBits(16);
    cout << endl;

    cout << "countBits(16): " << countBits(16) << endl;    

}
