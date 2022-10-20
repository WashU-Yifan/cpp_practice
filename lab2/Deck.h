#pragma once
#include<iostream>
#include<random>
#include"CardSet.h"
#include<algorithm>
//The base virtual class
// all decks should support/ overwrite the print function
template<typename R, typename S>
class Deck:public CardSet<R,S>{

public:
    void shuffle();
    void collect(CardSet<R,S>& set2);
};

 #ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
    #include"Deck.cpp"
  #endif
