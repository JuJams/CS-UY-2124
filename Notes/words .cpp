/*
  words.cpp
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;

struct Word {
    //int offset;
    vector<int> offsets;
    string token;
};

// Have we seen it, if so where?
size_t findToken(const string& token, const vector<Word>& words) {
    for (size_t index = 0; index < words.size(); ++index) {
        if (words[index].token == token) {
            return index;
        }
    }
    return words.size();
}

int main() {

    ifstream textStream("jabberwocky");
    if (!textStream) {
	cerr << "failed to open jabberwocky\n";
	exit(1);
    }

    // Get the information about the tokens

    vector<Word> words;
    int offset = 0;

    // fill the vector from the stream

    //   for each token in the file
    //       Have we seen it?
    //       If so, then just add the new offset
    //       Otherwise, make a new Word and add it
}
