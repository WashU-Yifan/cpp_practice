#include "Card_T.h"
using namespace std;


template <typename R, typename S> 
ostream& operator<< (ostream& os,const Card_T<R,S>& card){
    return os<<card.rank<<card.suit;
}

//compare two cards by their ranks first
template<typename R, typename S>
bool Compare_Rank(const Card_T<R,S> &c1, const Card_T<R,S>& c2){
    if(c1.rank<c2.rank) return true;
    else if (c2.rank<c1.rank) return false;
    return c1.suit<c2.suit;
}

//compare two cards by their suits first
template<typename R, typename S>
bool Compare_Suit(const Card_T<R,S> &c1, const Card_T<R,S>& c2){
    if(c1.suit<c2.suit) return true;
    else if (c2.suit<c1.suit) return false;
    return c1.rank<c2.rank;
}