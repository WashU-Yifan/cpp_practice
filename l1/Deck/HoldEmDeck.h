
#pragma once
#include<vector>
#include<iostream>
#include"Card_T.h"
#include "Deck.h"
#include "Suit.h"
// rank in Texas Hold em



enum class HoldEmRank {
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

std::ostream &operator<< (std::ostream& os, const HoldEmRank& Trank);

HoldEmRank& operator++(HoldEmRank &Trank);

class HoldEm :public Deck<HoldEmRank,Suit>{

    public:
        HoldEm();
       
};