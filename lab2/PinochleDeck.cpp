using namespace std;
#include "PinochleDeck.h"
#include<iostream>

// constructor of Pinochle 
// push each of every possible valid card combination twice into the vector
PinochleDeck::PinochleDeck(){
    
    PinochleRank prank=PinochleRank::nine;
    while(prank!=PinochleRank::undefined){
        Suit suit=Suit::clubs;
        while(suit!=Suit::undefined){
            Card_T<PinochleRank, Suit> card(prank,suit);
           
            cardset.push_back(card);
            ++suit;
        }
        ++prank;
    }
    prank=PinochleRank::nine;
    while(prank!=PinochleRank::undefined){
        Suit suit=Suit::clubs;
        while(suit!=Suit::undefined){
            Card_T<PinochleRank, Suit> card(prank,suit);
           
            cardset.push_back(card);
            ++suit;
        }
        ++prank;
    }
}






ostream &operator<< (std::ostream& os, const PinochleRank& prank){
    switch (prank){
        case PinochleRank::nine: return os<<"9";
        case PinochleRank::jack: return os<<"J";
        case PinochleRank::queen: return os<<"Q";
        case PinochleRank::king: return os<<"K";
        case PinochleRank::ten: return os<<"10";
        case PinochleRank::ace: return os<<"A";
        default: return os<<"?";
    }
}

void operator++(PinochleRank &prank){
      switch (prank){
        case PinochleRank::nine: {prank=PinochleRank::jack; return;}
        case PinochleRank::jack: {prank=PinochleRank::queen; return;}
        case PinochleRank::queen: {prank=PinochleRank::king; return;}
        case PinochleRank::king:{prank=PinochleRank::ten; return;}
        case PinochleRank::ten: {prank=PinochleRank::ace; return;}
        default:{prank=PinochleRank::undefined; return;}
        
    }
}

unsigned int PinochleRank_to_val(PinochleRank& prank){
    switch (prank){
        case PinochleRank::nine: {return 1;}
        case PinochleRank::jack: {return 2;}
        case PinochleRank::queen: {return 3;}
        case PinochleRank::king:{return 4;}
        case PinochleRank::ten: {return 5;}
        case PinochleRank::ace: {return 6;}
        default:{ return 0;}

    }
}
bool operator<(PinochleRank& prank1, PinochleRank& prank2){
    return PinochleRank_to_val(prank1)< PinochleRank_to_val(prank2); }