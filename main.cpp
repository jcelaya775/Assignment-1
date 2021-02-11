#include <iostream>
#include <string>
#include "Dictionary.h"
#include "Player.h"
#include "GameState.h"

using namespace std;

int main() {
    Dictionary d;
    int option;

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

    string name;
    string choice;
    cout << "Do you want to play (yes/no): ";
    cin >> choice;
    cout << endl;

    // if (choice == "yes") {
    //     ;
    //     cout << "Enter your name: ";
    //     cin >> name;
    //  } else
    //     exit(0);

    GameState game(d);
    Player player;

    while (choice == "yes")
    {
        bool won = false;
        string guess;
        GameState game(d);

        while (game.attemptsLeft() > 0 && game.getCurrentState() != game.getCurrentWord()) {
            cout << "Current state: " << game.getCurrentState() << "\n\n";
            cout << game.attemptsLeft() << " guesses left."
                 << "\n\n";

            cout << "Enter your guess (word or letter): ";
            cin >> guess;
            cout << endl;

            bool guessResult = player.makeGuess(game, guess);

            if (guessResult == true)
                cout << "You have made a correct guess!" << endl;   
            else
                cout << "Your guess was incorrect." << endl;

            if (game.getCurrentState() == game.getCurrentWord()) // if game was won
                won = true;

            cout << "\n\n";
        }

        if (won) {
            cout << "Congratulations! You have guessed the word: '" << game.getCurrentWord() << "' correctly!" << endl;
            ;
            player.incWins();
        }
        else {
            cout << "You have run out of guesses. Better luck next time." << endl;
            ;
            player.incLosses();
        } 
            

        cout << "\n\nDo you want to play again (yes/no): ";
        cin >> choice;
        cout << "\n\n";
    }

    cout << "Thank you for playing! You have " << player.getWins() << " wins and " << player.getLosses() << " losses.";

    return 0;
}