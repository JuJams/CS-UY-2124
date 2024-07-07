/*
  rec01_start.cpp
  spring 2024
*/

#include <string>
#include <fstream>
#include <iostream>
#include <vector>
using namespace std;
//
// Function prototypes for tasks 15-17
//

// Task 15. Function to display a vector of ints
void Vector(const vector<int>& lst);


// Task 16. Function to modify the vector, using indices
void VectorDoubles( vector<int>& lst);


// Task 17. Function to modify the vector, using a ranged for
void VectorDoublesRanged(vector<int>& lst);



//
// main


    int main() { // Yes, it has to have an int for the return type
        //

        //

        // Task 1. Printing hello ...  No use of "using namespace"
        std::cout<<"Hello world!"<<endl;

        // Task 2  Printing hello ...  Using "using namespace"
        cout <<"Hello world!"<<endl;
        cout <<endl;

        //
        // Types and variables
        //

        // Task 3  Displaying uninitialized variable
        int x;
        int y = 17;
        int z = 2000000017;
        double pie = 3.14159;

        // Task 4 Use the sizeof function to see the size in bytes of
        //        different types on your machine.
        cout <<sizeof(x)<< endl;
        cout <<sizeof(y)<< endl;
        cout <<sizeof(z)<< endl;
        cout <<sizeof(pie)<< endl;

        cout <<endl;
        // Task 5  Attempt to assign the wrong type of thing to a variable
        //int b = "felix";
        //It is a compile time error

        //
        // Conditions


        // Task 6  Testing for a range
        if (y>= 10 && y <= 20) {
            cout << "Yes! y is in between 10 and 20"<< endl;
        }
        cout <<endl;

        //
        // Loops and files
        //

        // Task 7  Looping, printing values 10 to 20 inclusive

        // First with a for loop
        for (int val =10; val <= 20; ++val) {
            cout <<val<<endl;
        }
        cout <<endl;
        // Then with a while loop
        int val = 10;
        while (val <= 20) {
            cout << val << endl;
            ++val;
        }
        cout << endl;
        // Finally with a do-while loop
        val = 10;
        do {
            cout << val << endl;
            val++;
        } while (val <= 20);
        cout << endl;

        // Task 8  Looping to successfully open a file, asking user for the name

//        bool value = 1;
        string filename;
        ifstream ifs;
        do {
            cout<<"Enter the file name"<<endl;
            cin>>filename;
            ifs.open(filename);
//            if (ifs)
//               value = 0;
        } while (!ifs);




        // Task 9  Looping, reading file word by "word".
        ifstream file;
        file.open("text.txt");
        string word;
        if (!file) {
            cerr << "Failed to open text.txt";

        }
        while (file>>word){
            cout<<word<<endl;
        }
        file.close();
        cout << endl;


        // Task 10 Open a file of integers, read it in, and display the sum.
        ifstream intfile;
        intfile.open("integers.txt");
        if (!intfile) {
            cerr<< "Error opening integers.txt" << endl;
        }
        int sum = 0;
        int num;
        while (intfile >> num) {
            sum += num;
        }
        intfile.close();
        cout << "Sum of integers is "<<sum<<endl;
        cout<<endl;

        // Task 11 Open and read a file of integers and words. Display the sum.
        ifstream mixedfile;
        mixedfile.open("mixed.txt");
        if (!mixedfile) {
            cerr<< "Error opening mixed.txt" << endl;
        }
        int sum2 = 0;
        int num2;
        while (mixedfile >> num2) {
            sum2 += num2;
        }
        mixedfile.close();
        cout << "Sum of integers is "<<sum<<endl;
        cout<<endl;


        //
        // Vectors
        //

        // Task 12 Filling with a vector of ints
        vector<int> evens;
        for (int i = 10; i <= 100; i += 2) {
            evens.push_back(i);

        }

        cout << endl;
        // Task 13 Displaying the vector THREE times
        //         a) using the indices,
        for (size_t i = 0; i < evens.size(); ++i) {
            cout<< evens[i] << endl;
        }

        cout << endl;
        //         b) using a "ranged for"
        for (int i:evens){
            cout << i<<endl;
        }
        cout <<endl;
        //         c) using indices again but backwards
        for (size_t i = evens.size(); i > 0; --i) {
            cout << evens[i -1] << endl;
        }
        cout<<endl;


        // Task 14. Initialize a vector with the primes less than 20.
        vector<int> v{2,3,5,7,11,13,17,19};
        for (int prime : v) {
            cout<<prime<<" ";
        }

        //
        // Function calls
        //

        // Task 15  Function to print a vector
        Vector(v);

        // Task 16  Function to double the values in a vector

        VectorDoubles(v);
        // Task 17  Function to double the values in a vector, using a ranged for

        VectorDoublesRanged(v);
    }

//
// Function definitions for tasks 15-17
//

// Task 15. Function to display a vector of ints

void Vector(const vector<int>& lst){
    for(int i : lst){
        cout<<i<<" ";
    }
    cout<<endl;
}

// Task 16. Function to modify the vector, using indices

void VectorDoubles(vector<int>& lst){
    for(size_t i = 0;i<=lst.size();i++){
        i*=2;
    }
    for(int i : lst){
        cout<<i<<" ";
    }
    cout<<endl;

}

// Task 17. Function to modify the vector, using a ranged for
void VectorDoublesRanged(vector<int>& lst){
    for(int& i : lst){
        i*=2;
    }
    for(int i : lst){
        cout<<i<<" ";
    }
    cout<<endl;
}

