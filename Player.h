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
        GameState _game;

    public:
        Player(){};
        Player(string);
        void makeGuess(string); // pre: current state; post: add guessed word to the list
        bool gameStatus(); // returns whether the player has won the current game
};

#endif