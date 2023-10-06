#include "HoldEmDeck.h"
#include<iostream>

using std::ostream;


// constructor of HoldEm
// push each of every possible valid card combination into the vector
HoldEm::HoldEm(){
    HoldEmRank tRank = HoldEmRank::two;
    while(tRank != HoldEmRank::undefined) {
        Suit suit=Suit::clubs;
        while(suit != Suit::undefined) {
            Card_T<HoldEmRank, Suit> card(tRank, suit);
           
            deck.push_back(card);
            ++suit;
        }
        ++tRank;
    }
    shuffle();
}



//print corresponding value of the Texas HoldEmRank
ostream& operator<< (ostream& os, const HoldEmRank& tRank) {
    switch (tRank){
        case HoldEmRank::two: return os << "2";
        case HoldEmRank::three: return os << "3";
        case HoldEmRank::four: return os << "4";
        case HoldEmRank::five: return os << "5";
        case HoldEmRank::six: return os << "6";
        case HoldEmRank::seven: return os << "7";
        case HoldEmRank::eight: return os << "8";
        case HoldEmRank::nine: return os << "9";
        case HoldEmRank::ten: return os << "10";
        case HoldEmRank::jack: return os << "J";
        case HoldEmRank::queen: return os << "Q";
        case HoldEmRank::king: return os << "K";
        case HoldEmRank::ace: return os << "A";
        default: return os << "?";
    }
}


HoldEmRank& operator++(HoldEmRank &tRank){
    switch (tRank){
        case HoldEmRank::two:{ 
            tRank = HoldEmRank::three; 
            break;
        }
        case HoldEmRank::three: { 
            tRank = HoldEmRank::four;
            break;
        }
        case HoldEmRank::four: { 
            tRank = HoldEmRank::five; 
            break;
        }
        case HoldEmRank::five: { 
            tRank = HoldEmRank::six; 
            break;
        }
        case HoldEmRank::six:{ 
            tRank = HoldEmRank::seven; 
            break;
        }
        case HoldEmRank::seven: { 
            tRank = HoldEmRank::eight; 
            break;
        }
        case HoldEmRank::eight: { 
            tRank = HoldEmRank::nine; 
            break;
        }
        case HoldEmRank::nine: { 
            tRank = HoldEmRank::ten; 
            break;
        }
        case HoldEmRank::ten: { 
            tRank = HoldEmRank::jack; 
            break;
        }
        case HoldEmRank::jack: { 
            tRank = HoldEmRank::queen; 
            break;
        }
        case HoldEmRank::queen: { 
            tRank = HoldEmRank::king; 
            break;
        }
        case HoldEmRank::king:{ 
            tRank = HoldEmRank::ace; 
            break;
        }
        default:{ 
            tRank = HoldEmRank::undefined;
        }
    }
    return tRank;
}
