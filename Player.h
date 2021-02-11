#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
#include "GameState.h"
using namespace std;

class Player {
    private:
        string _name;
        int _numWins, _numLosses;

    public:
        Player() {
            _numWins = 0;
            _numLosses = 0;
        };
        Player(string);
        void incWins() { _numWins++; };
        void incLosses() { _numLosses++; };
        int getWins() { return _numWins; };
        int getLosses() { return _numLosses; };
        bool makeGuess(GameState&, string); // pre: current state; post: add guessed word to the list
};

#endif