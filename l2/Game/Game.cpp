#include "Game.h"
using std:: cout;
using std:: endl;

// Simple definition of the game class, leverage the user prompt
// action to the base class level for better code reuse/readability

Game::Game(int numPlayer, const char **players) {
    for (int i = 0; i < numPlayer; ++i) {
        this->players.push_back(players[i]);
    }
}

int Game::continueGame() {
    std:: string input;
    cout << "Continue Game? [yes/no]" << endl;
    std:: cin >> input;
    if(input == "yes") {
        return CONTINUEGAME;
    }
    return ENDGAME;
}

