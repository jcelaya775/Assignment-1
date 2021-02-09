#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

class Player {
    private:
        string _name;
        int _numWins, _numLosses;

    public:
        Player(){};
        Player(string);
};

#endif