#pragma once
#include "Game.h"
#include "../Deck/HoldEmDeck.h"
#include "../Deck/CardSet.h"
#include <vector>
#include <iostream>


// A simple Texas HoldEm game that support 2 - 9 players.
// deal cards to each
using std::vector;
const int HOLDEMMIN = 5, STRAIGHTNUM = 5, FLUSHNUM = 5, FOUROFAKIND = 4, THREEOFAKIND = 3, PAIR = 2;
enum class HoldEmState {
    preflop,
    flop,
    turn,
    river,
    undefined
};

enum class HoldEmHandRank {
    xhigh,
    pair, 
    twopair, 
    threeofakind, 
    straight, 
    flush, 
    fullhouse, 
    fourofakind, 
    straightflush, 
    undefined
};

class HoldEmGame : public Game {
        void dealPreFlop();
        void dealFlop();
        void dealTurn();
        void dealRiver();
        HoldEmHandRank holdEmHandEvaluation(const CardSet<HoldEmRank, Suit>&);
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
        static std::vector<std::string> holdEmRankName;
        HoldEmGame(int, const char **);
        virtual int play();

        struct HoldEmHand {
            CardSet<HoldEmRank, Suit> cardSet;
            std::string playerName;
            HoldEmHandRank handRank;

            HoldEmHand(const CardSet<HoldEmRank, Suit>&, const std::string&, HoldEmHandRank);
        };
};

bool operator<(const HoldEmGame::HoldEmHand&, const HoldEmGame::HoldEmHand&);
std::ostream& operator<<(std::ostream&, const HoldEmHandRank&);

//Helper functions for comparison if two decks have same HoldEmHandRank.
bool compareHigh(vector< Card_T<HoldEmRank, Suit> > deck1, vector< Card_T<HoldEmRank, Suit> > deck2);
bool comparePair(vector< Card_T<HoldEmRank, Suit> > deck1, vector< Card_T<HoldEmRank, Suit> > deck2);
bool compareTwoPair(vector< Card_T<HoldEmRank, Suit> > deck1, vector< Card_T<HoldEmRank, Suit> > deck2);
bool compareThree(vector< Card_T<HoldEmRank, Suit> > deck1, vector< Card_T<HoldEmRank, Suit> > deck2);
bool compareFull(vector< Card_T<HoldEmRank, Suit> > deck1, vector< Card_T<HoldEmRank, Suit> > deck2);
bool compareFour(vector< Card_T<HoldEmRank, Suit> > deck1, vector< Card_T<HoldEmRank, Suit> > deck2);
HoldEmRank extract(vector< Card_T<HoldEmRank, Suit> >&, int);
