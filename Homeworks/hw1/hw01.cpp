#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

//Create function prototypes

char CharDecoder(const char& character, int offset );

void LineDecoder(string& line, int offset);




int main() {
    ifstream ifs("/Users/sanjuchowdary/Desktop/OOP/CS2124/HW/encrypted.txt");
    if (!ifs) {
        cout<<"Encrypted text file is not found";
        exit(0);
    }
    int offset;
    ifs>>offset;
    string temporary;
    getline(ifs,temporary);
    vector<string> each_line;

    while (getline(ifs,temporary)){
        LineDecoder(temporary,offset);
        each_line.push_back(temporary);
    }

    for (size_t i = each_line.size(); i>0; --i) {
        cout<< each_line[i-1] << endl;
    }

}


char CharDecoder(const char& character, int offset){
    char return_char = character;
    if ((character - offset >= 65 && character<=90)){
        return_char = character - offset;
        return(return_char);
    }
    else if(character>= 65 && character<=90){
        return_char = character - offset + 26;
        return(return_char);
    }
    else{
        return(return_char);
    }

}
//Use ranged for loop to iterate over the line string
void LineDecoder(string& line, int offset){
    for(char& text_char : line){
        text_char = CharDecoder(text_char,offset);
    }
}


