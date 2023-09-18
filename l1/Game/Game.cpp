#include "Game.h"
using std:: cout;
using std:: endl;
Game:: Game(int numPlayer, const char **players) {
    for (int i = 0; i < numPlayer; ++i) {
        this->players.push_back(players[i]);
    }
}

int Game:: continueGame() {
    std:: string input;
    cout << "Continue Game? [yes/no]" << endl;
    std:: cin >> input;
    if(input == "yes") {
        return CONTINUEGAME;
    }
    return ENDGAME;
}

