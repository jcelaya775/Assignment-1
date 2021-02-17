#include <iostream>
#include <string>
#include "Dictionary.h"
#include "Player.h"
#include "GameState.h"

using namespace std;

int main() {
    Dictionary d;
    int option; // input choice

    cout << "Choose option -> Read words from a file (1) - Enter words manually (2): ";
    cin >> option;

    while (option != 1 && option != 2) {
        cout << "Invalid input. Try again: ";
        cin >> option;
    }

    if (option == 1) {
        string filename;
        cout << "Enter filename: ";
        cin >> filename;
        d.readFile(filename);
    } else if (option == 2) {
        d.readUserInp();
    }

    Player player;
    string choice;
    cout << "Do you want to play (yes/no): ";
    cin >> choice;
    cout << endl;

    while (choice == "yes")
    {
        bool won = false;
        string guess;
        string currentWord = d.randomWord();
        GameState game(currentWord);

        while (game.attemptsLeft() > 0 && !won) {
            cout << "Current state: " << game.getCurrentState() << "\n\n";
            cout << game.attemptsLeft() << " guesses left." << "\n\n";

            cout << "Enter your guess (word or letter): ";
            cin >> guess;
            cout << endl;

            bool guessResult = game.makeGuess(guess);

            if (guessResult == true)
                cout << "You have made a correct guess!" << endl;
            else if (guess.length() != 1 && guess.length() != game.getCurrentWord().length()) // if guess is incorrect length
                cout << "You must guess either the entire word or a letter of the word. You have exhausted an attempt." << endl;
            else
                cout << "Your guess was incorrect." << endl;

            if (guess == currentWord)
                won = true;

            cout << "\n\n";
        }

        if (won) {
            cout << "Congratulations! You have guessed the word: '" << game.getCurrentWord() << "' correctly!" << endl;
            player.incWins();
        }
        else {
            cout << "You have run out of guesses. The word was '" << game.getCurrentWord() << "'." << endl;
            player.incLosses();
        }


        cout << "\n\nDo you want to play again (yes/no): ";
        cin >> choice;
        cout << "\n\n";
    }

    cout << "Thank you for playing! You have " << player.getWins() << " wins and " << player.getLosses() << " losses." << endl;

    return 0;
}
