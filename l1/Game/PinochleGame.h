#pragma once
#include "Game.h"
#include "../Deck/PinochleDeck.h"
#include "../Deck/CardSet.h"
#include <vector>
#include <iostream>

class PinochleGame : public Game {
    protected:
        Pinochle deck;
        std::vector<CardSet<PinochleRank, Suit> > playersHands;

        virtual void deal();
        virtual void printPlayers();
        virtual void collectHands();
    public:
        PinochleGame(int, const char **);
        virtual int play();
};