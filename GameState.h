#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <string>
#include <vector>
using namespace std;
class GameState {
    private:
        string _currentWord;
        string _currentGuess;
        int _numWrongLetters;
        vector<string> _wrongGuesses;
        int _attemptsLeft;

    public:
        GameState(){};
        
};

#endif