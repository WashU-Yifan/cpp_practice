#include "HoldEmDeck.h"
#include<iostream>

using namespace std;


// constructor of Pinochle 
// push each of every possible valid card combination twice into the vector
HoldEmDeck::HoldEmDeck(){
     HoldEmRank Trank=HoldEmRank::two;
    while(Trank!=HoldEmRank::undefined){
        Suit suit=Suit::clubs;
        while(suit!=Suit::undefined){
            Card_T<HoldEmRank, Suit> card(Trank,suit);
           
            cardset.push_back(card);
            ++suit;
        }
        ++Trank;
    }
}




//print corresponding value of the Texas HoldEmRank
ostream &operator<< (ostream& os, const HoldEmRank& Trank){
    switch (Trank){
        case HoldEmRank::two: return os<<"2";
        case HoldEmRank::three: return os<<"3";
        case HoldEmRank::four: return os<<"4";
        case HoldEmRank::five: return os<<"5";
        case HoldEmRank::six: return os<<"6";
        case HoldEmRank::seven: return os<<"7";
        case HoldEmRank::eight: return os<<"8";
        case HoldEmRank::nine: return os<<"9";
        case HoldEmRank::ten: return os<<"10";
        case HoldEmRank::jack: return os<<"J";
        case HoldEmRank::queen: return os<<"Q";
        case HoldEmRank::king: return os<<"K";
        case HoldEmRank::ace: return os<<"A";
        default :return os<<"?";
    }
}


void operator++( HoldEmRank &Trank){
    switch (Trank){
        case HoldEmRank::two:{ Trank=HoldEmRank::three; break;}
        case HoldEmRank::three: { Trank=HoldEmRank::four; break;}
        case HoldEmRank::four: { Trank=HoldEmRank::five; break;}
        case HoldEmRank::five: { Trank=HoldEmRank::six; break;}
        case HoldEmRank::six:{ Trank=HoldEmRank::seven; break;}
        case HoldEmRank::seven: { Trank=HoldEmRank::eight; break;}
        case HoldEmRank::eight: { Trank=HoldEmRank::nine; break;}
        case HoldEmRank::nine: { Trank=HoldEmRank::ten; break;}
        case HoldEmRank::ten: { Trank=HoldEmRank::jack; break;}
        case HoldEmRank::jack: { Trank=HoldEmRank::queen; break;}
        case HoldEmRank::queen: { Trank=HoldEmRank::king; break;}
        case HoldEmRank::king:{ Trank=HoldEmRank::ace; break;}
        default:{ Trank=HoldEmRank::undefined; }
        
    }
}
