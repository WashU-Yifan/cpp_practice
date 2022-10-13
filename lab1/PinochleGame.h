#pragma once
#include"CardSet.h"
#include<vector>
#include "Game.h"
#include"PinochleDeck.h"
class PinochleGame:public Game{

    protected:
        PinochleDeck Deck;
        std::vector<CardSet<PinochleRank,Suit> > PlayerHands;
        virtual void deal();//distribute the card among players
    public:
        PinochleGame(int argc, const char* argv[]);
        virtual int play() override;
    private:
        void printstatus();
};