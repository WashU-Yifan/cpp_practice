
#pragma once
#include<vector>
#include<iostream>

#include "Deck.h"
#include "Suit.h"
// rank in Texas Hold em
enum class HoldEmRank{
    two,
    three,
    four,
    five,
    six,
    seven,
    eight,
    nine,
    ten,
    jack,
    queen,
    king,
    ace,
    undefined
};

std::ostream &operator<< (std::ostream&, const HoldEmRank&);

unsigned int HoldEmRank_to_val(HoldEmRank);
bool operator<( const HoldEmRank&, const HoldEmRank&);
void operator++( HoldEmRank &);

class HoldEmDeck :public Deck<HoldEmRank,Suit>{
    std::vector< Card_T<HoldEmRank,Suit> > deck;
    public:
        HoldEmDeck();
     
};