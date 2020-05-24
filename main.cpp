#include <iostream>
#include "Game.h"

using namespace std;
int main() {
    WarGame::Game Game;
    cout << "The winner is:\n" << Game.play() << endl;
    return 0;
}

