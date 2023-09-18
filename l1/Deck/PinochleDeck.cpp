using namespace std;
#include "PinochleDeck.h"
#include<iostream>

// constructor of Pinochle 
// push each of every possible valid card combination twice into the vector
Pinochle::Pinochle() {
    
    PinochleRank pRank = PinochleRank::nine;
    while(pRank != PinochleRank::undefined) {
        Suit suit = Suit::clubs;
        while(suit != Suit::undefined){   
            Card_T<PinochleRank, Suit> card(pRank, suit);
            deck.push_back(card);
            deck.push_back(card);
            ++suit;
        }
        ++pRank;
    }
    shuffle();
}






ostream &operator<< (std::ostream& os, const PinochleRank& pRank){
    switch (pRank) {
        case PinochleRank::nine: return os << "9";
        case PinochleRank::jack: return os << "J";
        case PinochleRank::queen: return os << "Q";
        case PinochleRank::king: return os << "K";
        case PinochleRank::ten: return os << "10";
        case PinochleRank::ace: return os << "A";
        default: return os << "?";
    }
}

PinochleRank& operator++(PinochleRank &pRank){
      switch (pRank){
        case PinochleRank::nine: {
            pRank = PinochleRank::jack; 
            break;
        }
        case PinochleRank::jack: {
            pRank = PinochleRank::queen;   
            break;
        }
        case PinochleRank::queen: {
            pRank = PinochleRank::king; 
            break;
        }
        case PinochleRank::king: {
            pRank = PinochleRank::ten; 
            break;
        }
        case PinochleRank::ten: {
            pRank = PinochleRank::ace;   
            break;
        }
        default: {
            pRank = PinochleRank::undefined;   
            break;
        }
    }
    return pRank;
}