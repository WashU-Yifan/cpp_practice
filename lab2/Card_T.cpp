#include "Card_T.h"
#include "PinochleDeck.h"
#include "HoldEmDeck.h"
using namespace std;
template <PinochleRank, typename S>
PinochleRank Card_T<PinochleRank,S>::get_rank(){return this->rank;}

template <HoldEmRank, typename S>
HoldEmRank Card_T<HoldEmRank,S>::get_rank(){return this->rank;}

template <typename R, Suit>
Suit Card_T<R,Suit>::get_suit(){return this->suit;}

template <typename R, typename S>
ostream& operator<< (ostream& os,const Card_T<R,S>& card){
    return os<<card.rank<<card.suit;
}

//compare two cards by their ranks first
template<typename R, typename S>
bool Compare_Rank(const Card_T<R,S> &c1, const Card_T<R,S> &c2){
    if(c1.get_rank()< c2.get_rank()) return true;
    else if (c2.get_rank() < c1.get_rank()) return false;
    return c1.get_suit() < c2.get_suit();
}

//compare two cards by their suits first
template<typename R, typename S>
bool Compare_Suit(const Card_T<R,S> &c1, const Card_T<R,S> &c2){
    if(c1.get_suit() < c2.get_suit()) return true;
    else if (c2.get_suit() < c1.get_suit()) return false;
    return c1.get_rank() < c2.get_rank();
}