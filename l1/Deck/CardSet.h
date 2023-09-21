#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>
#include "Card_T.h"

// The base class of all cardset, now have only one direct 
// derived class called deck

const int PINOCHLENUM = 4;
const int HOLDEMNUM = 5;
template
<typename R, typename S>
class CardSet{
    public:
        void print(std::ostream& os, size_t);

        CardSet<R,S>& operator>>(CardSet<R,S>&);

        inline bool isEmpty() {return deck.empty();}
    protected:
        std::vector< Card_T<R, S> > deck;
};

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
    #include "CardSet.cpp"
#endif