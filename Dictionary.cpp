#include "Dictionary.h"

void Dictionary::add(string word) {
    _words.push_back(word);
}
void Dictionary::readFile(string filename) {
    ifstream infile(filename);
    if (!infile) {
        cout << "error opening file..." << endl;
        exit(-1);
    }
    else {
        while (!infile.eof()) {
            string word;
            infile >> word;
            _words.push_back(word);
        }
    }
}
string Dictionary::randomWord() {
    srand(time(0));
    int randIndex = rand() % _words.size();

    return _words[randIndex];
}
