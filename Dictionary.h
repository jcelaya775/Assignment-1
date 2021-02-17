#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <fstream>
#include <ctime>
#include <string>
#include <vector>
using namespace std;

class Dictionary {
    private:
        vector<string> _words;

    public:
        void add(string);      // pre: _words; post: a string is pushed to _words
        void readFile(string); // pre: _words is empty; post: populates the container via a file
        string randomWord();   // pre: none; post: returns a random word from the container
};

#endif