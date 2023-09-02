#pragma once
#include<vector>

#include<iostream>
#include "Card_T.h"
#include "Deck.h"
#include "Suit.h"
// ranks in Pinochle


enum class PinochleRank{
    nine,
    jack,
    queen,
    king,
    ten,
    ace,
    undefined
};

class Pinochle :public Deck{
        const static int cardInRow = 8;
        std::vector< card_T<PinochleRank, Suit> > deck;
    public:
        Pinochle();
        virtual void print(std::ostream& os) override;
};


std::ostream& operator<<(std::ostream& os, const PinochleRank& pRank);

PinochleRank& operator++(PinochleRank &prank);

