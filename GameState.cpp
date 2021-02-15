#include "GameState.h"

GameState::GameState(string word) {
    _currentWord = word;
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
bool GameState::makeGuess(string guess) {
    bool guessResult = false;

    if (guess.length() == _currentWord.length()) {  // if guessed the entire word
        if (_currentWord.find(guess) == 0) {// fill in word
            _currentState = _currentWord;
            guessResult = true;
        } else // guessed wrong word
            _wrongWords.push_back(guess);
    } 
    else if (guess.length() == 1) { // if guessed a letter
        if (_currentWord.find(guess) != _currentWord.npos) { // if guessed letter(s) correctly 
            for (int i = 0; i < _currentWord.length(); i++) { // mark letter(s)
                if (guess == _currentWord.substr(i, 1))
                    _currentState[i] = _currentWord[i];
            }
        
            guessResult = true;
        } else // guessed wrong letter
            _wrongLetters.push_back(guess); 
    }

    _attemptsLeft--;

    return guessResult;
}