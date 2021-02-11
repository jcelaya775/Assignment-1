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
        string getCurrentWord(); // pre: _currentWord; post: returns _currentWord
        string getCurrentState(); // pre: _currentState; post: returns _currentState
        vector<string> getWrongLetters(); // pre: _wrongLetters; post: returns _wrongLetteres
        vector<string> getWrongWords();   // pre: _wrongWords; post: rturns _wrongWords
        int attemptsLeft();               // pre: _attemptsLeft; post: returns _attemptsLeft
        bool makeGuess(string);           // pre: none; post: returns whether guess was correct and marks _currentState if applicable
};

#endif