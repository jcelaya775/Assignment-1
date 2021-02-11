#include "Player.h"

Player::Player(string name) {
    _name = name;
}
bool Player::makeGuess(GameState& game, string guess) {
    return game.processGuess(guess);
}