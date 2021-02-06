#include <iostream>
#include <string>
#include "Dictionary.h"

using namespace std;

int main() {
    Dictionary d;
    d.readUserInp();

    for (int i = 0; i<10; i++) 
        cout << d.randomWord() << endl;

    return 0;
}