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

    cout << endl;

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

    if (choice == "yes") {
        ;
        cout << "Enter your name: ";
        cin >> name;
     } else
        exit(0);

    GameState game(d);
    Player player(name);
    string guess;

    while (choice == "yes")
    {
        cout << "Current state:" << endl;
        game.displayState();

        cout << "Enter your guess (word or letter):";
        cin >> guess;

        player.makeGuess(guess);
    }

    return 0;
}