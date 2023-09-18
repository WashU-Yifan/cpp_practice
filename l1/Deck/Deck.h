#pragma once
#include<iostream>
#include "CardSet.h"
//The base virtual class
// all decks should support/ overwrite the print function
template<typename R, typename S>
class Deck: public CardSet<R,S>{

    public:
    void shuffle();
    void collect(CardSet<R, S>&);
};

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
    #include "Deck.cpp"
#endif