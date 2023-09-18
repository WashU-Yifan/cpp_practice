#pragma once
#include <vector>
#include <iostream>
const int CONTINUEGAME = 0;
const int ENDGAME = 1;

class Game {
    protected:
        std::vector<std::string> players;
        int continueGame();
        virtual void printPlayers() = 0;
        virtual void collectHands() = 0;
    public:
        Game(int, const char**);
        virtual int play() = 0;
};