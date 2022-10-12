#include "Suit.h"

std::ostream& operator<<(std::ostream& os,const Suit& suit){
    switch (suit){
        case Suit::clubs: return os<<"C";
        case Suit::diamonds: return os<<"D";
        case Suit:: hearts: return os<<"H";
        case Suit:: spades: return os<<"S";
         default: return os<<"?";
    }
}
void operator++(Suit& suit){
    switch (suit){
        case Suit::clubs: {suit=Suit::diamonds;break;}
        case Suit::diamonds: {suit=Suit::hearts;break;}
        case Suit:: hearts: {suit=Suit::spades;break;}
        case Suit:: spades: {suit=Suit::undefined;break;}
         default: return;
    }
}