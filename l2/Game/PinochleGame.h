#pragma once
#include "Game.h"
#include "../Deck/PinochleDeck.h"
#include "../Deck/CardSet.h"
#include <vector>
#include <iostream>

const int PINOCHLE_FULLRANK = 8; //when we have 8 cards of same rank
const int PINOCHLE_FOURSUITSMAP = 17; // when we have 4 suits, 0xf
const int PINOCHLE_DOUBLE = 2;
enum class PinochleMelds {
    dix,
    offsuitmarriage, 
    fortyjacks, 
    pinochle, 
    insuitmarriage, 
    sixtyqueens, 
    eightykings, 
    hundredaces, 
    insuitrun, 
    doublepinochle, 
    fourhundredjacks, 
    sixhundredqueens, 
    eighthundredkings, 
    thousandaces, 
    insuitdoublerun
};

class PinochleGame : public Game {
    protected:
        Pinochle deck;
        std::vector<CardSet<PinochleRank, Suit> > playersHands;

        virtual void deal();
        virtual void printPlayers();
        virtual void collectHands();
        virtual void finalizeScore(const CardSet<PinochleRank, Suit>&);
    public:
        static std::vector<unsigned int> pinochlePoint;
        static std::vector<string> pinochleName;

        PinochleGame(int, const char **);
        virtual int play();
        int suitIndependentEvaluation(const CardSet<PinochleRank, Suit>, vector<PinochleMelds>&);
};

void countCard(const Suit&, int&, int&);
std::ostream& operator<<(std::ostream&, const PinochleMelds&);