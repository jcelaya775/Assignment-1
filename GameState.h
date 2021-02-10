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
        bool _currentState; // true if game is done
        vector<string> _wrongLetters;
        vector<string> _wrongWords;
        int _attemptsLeft;

    public:
        GameState(){};
        GameState(Dictionary);
        string getCurrentWord();
        bool getCurrentState();
        void displayState();
        vector<string> getWrongLetters();
        vector<string> getWrongWords();
        int attemptsLeft();
        void processGuess(string);
};

#endif