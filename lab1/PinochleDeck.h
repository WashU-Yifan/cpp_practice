#pragma once
#include<vector>

#include<iostream>
#include"Card_T.h"
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

std::ostream &operator<< (std::ostream& os, const PinochleRank& prank);

void operator++(PinochleRank &prank);

class PinochleDeck :public Deck<PinochleRank,Suit>{
    std::vector< Card_T<PinochleRank,Suit> > deck;
    public:
        PinochleDeck();
     
};