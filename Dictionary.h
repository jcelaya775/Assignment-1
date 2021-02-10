#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Dictionary {
    private:
        vector<string> _words;

    public:
        void readUserInp(); // populates the container via the console
        void readFile(string); //populates the container via a file
        string randomWord();   // accesses a random word from the container
        void print();
};

#endif