#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <iostream>
#include <string>
#include <vector>
#include "Dictionary.h"
using namespace std;
class GameState {
    private:
        string _currentWord;
        string _currentState; // current state of the word
        vector<string> _wrongLetters; // list of wrong letter guesses
        vector<string> _wrongWords; // list of wrong word guesses
        int _attemptsLeft;

    public:
        GameState(){};
        GameState(Dictionary);
        string getCurrentWord();
        string getCurrentState();
        vector<string> getWrongLetters();
        vector<string> getWrongWords();
        int attemptsLeft();
        bool processGuess(string);
};

#endif