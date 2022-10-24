#pragma once
#include<vector>
#include<iostream>

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
unsigned int PinochleRank_to_val(PinochleRank&);
bool operator<(PinochleRank&, PinochleRank&);
void operator++(PinochleRank &prank);

class PinochleDeck :public Deck<PinochleRank,Suit>{
    std::vector< Card_T<PinochleRank,Suit> > deck;
    public:
        PinochleDeck();
     
};