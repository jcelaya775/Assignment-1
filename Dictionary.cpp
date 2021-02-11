#include "Dictionary.h"

void Dictionary::readUserInp() {
    string word;

    do {
    cout << "Enter a word w/out spaces (type '/quit' to finish): ";
    cin >> word;
    if (word != "/quit")
        _words.push_back(word);
    } while (word != "/quit");
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
    int randIndex = rand() % _words.size();

    return _words[randIndex];
}
