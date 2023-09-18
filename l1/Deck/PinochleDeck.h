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

class Pinochle :public Deck<PinochleRank, Suit>{
       
    public:
        Pinochle();
};


std::ostream& operator<<(std::ostream& os, const PinochleRank& pRank);

PinochleRank& operator++(PinochleRank &prank);

