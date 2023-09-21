#pragma once
#include "Game.h"
#include "../Deck/HoldEmDeck.h"
#include "../Deck/CardSet.h"
#include <vector>
#include <iostream>

// A simple Texas HoldEm game that support 2 - 9 players.
// deal cards to each

enum class HoldEmState {
    preflop,
    flop,
    turn,
    river,
    undefined
};

class HoldEmGame : public Game {
        void dealPreFlop();
        void dealFlop();
        void dealTurn();
        void dealRiver();
    protected:
        HoldEmState state;
        HoldEm deck;
        std::vector<CardSet<HoldEmRank, Suit> > playersHands;
        CardSet<HoldEmRank, Suit> sharedHands;
        virtual void deal();
        virtual void printPlayers();
        virtual void printShared();
        virtual void collectHands();
    public:
        HoldEmGame(int, const char **);
        virtual int play();
};