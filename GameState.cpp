#include "GameState.h"

GameState::GameState(Dictionary d) {
    _currentWord = d.randomWord();
    _attemptsLeft = _currentWord.length();
    _currentState = "";
    // initialize _currentState with blanks
    for (int i = 0; i < _currentWord.length(); i++) {
        _currentState += "_";
    }
}
string GameState::getCurrentWord() {
    return _currentWord;
}
string GameState::getCurrentState() {
    return _currentState;
}
vector<string> GameState::getWrongLetters() {
    return _wrongLetters;
}
vector<string> GameState::getWrongWords() {
    return _wrongWords;
}
int GameState::attemptsLeft() {
    return _attemptsLeft;
}
bool GameState::processGuess(string guess) {
    bool guessResult = false;

    if (guess.length() == _currentWord.length()) {  // if guessed the word
        if (_currentWord.find(guess) == 0) {// guessed the word correctly
            _currentState = _currentWord;
            guessResult = true;
        } else // guesed wrong word
            _wrongWords.push_back(guess);

    /* TO DO: Remember to mark duplicate letters if applicable */
    } else if (guess.length() == 1) { // guessed a letter
        if (_currentWord.find(guess) != _currentWord.npos) { // if guessed a letter correctly
            for (int i = 0; i < _currentWord.length(); i++) {
                if (guess == _currentWord.substr(i, 1))
                    _currentState[i] = _currentWord[i];
            }
        
            guessResult = true;
        } else
            _wrongLetters.push_back(guess); // guessed wrong letter
    }

    _attemptsLeft--;

    return guessResult;
}