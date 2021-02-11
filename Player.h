#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <string>
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
        void incWins() { _numWins++; };     // pre: _numWins; post: incremenet _numWins
        void incLosses() { _numLosses++; }; // pre: _numLosses; post: increments _numLosses
        int getWins() { return _numWins; }; // pre: _numWins; post: returns _numWins
        int getLosses() { return _numLosses; }; // pre: _numLosses; post: returns numLosses
};

#endif