#pragma once
#include <vector>
#include <iostream>
#include <stdexcept>
#include <functional>
#include "Card_T.h"

// The base class of all cardset, now have only one direct 
// derived class called deck

const int PINOCHLENUM = 4;
const int HOLDEMNUM = 5;
template
<typename R, typename S>
class CardSet{
    
    public:
        typedef Card_T<R, S> card_type;
        typedef typename std::vector< Card_T<R, S> >::iterator iter; 

        CardSet() = default;
        CardSet(const CardSet<R, S>&); 

        void collect(CardSet<R, S>&);
        void collectIf(CardSet<R, S>&, std::function<bool(card_type&)>);
        bool request(CardSet<R, S>&, R);
        void print(std::ostream& os, size_t);
        void sort();
        CardSet<R,S>& operator>>(CardSet<R,S>&);


        inline iter getDeckBegin() {return deck.begin();}
        inline iter getDeckEnd() {return deck.end();}
        inline bool isEmpty() {return deck.empty();}
        inline int getDeckSize() {return deck.size();}
    protected:
        std::vector<card_type> deck;
};

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
    #include "CardSet.cpp"
#endif