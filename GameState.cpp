#include "GameState.h"

GameState::GameState(Dictionary d) {
    _currentWord = d.randomWord();
    _attemptsLeft = _currentWord.length();
    _currentState = false;
}
string GameState::getCurrentWord() {
    return _currentWord;
}
bool GameState::getCurrentState() {
    return _currentState;
}
void GameState::displayState() {
    for (int i = 0; i < _currentWord.length(); i++) {
        //if (/* letter guessed */)
        cout << _currentWord[i];
        // else
        cout <<  "_";
    }
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
void GameState::processGuess(string guess) {
    int n = _currentWord.length() - guess.length();
    for (int i = 0; i < n; i++) {
        if (guess.length() == _currentWord.length() &&_currentWord.find(guess) != -1) {
            _currentState = true;
        } else {
            // mark correct letters
        }
    }
}