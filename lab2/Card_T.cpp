#pragma once
#include "Card_T.h"

using std::ostream;

template <typename R, typename S>
ostream& operator<< (ostream& os,const Card_T<R,S>& card){
    return os<<card.Crank<<card.Csuit;
}

//compare two cards by their ranks first
template< typename R,typename S>
bool Compare_Rank(const Card_T<R,S> &c1,  const Card_T<R,S> &c2){
    if(c1.Crank<c2.Crank) return true;
    else if (c2.Crank<c1.Crank ) return false;
    return c1.Csuit< c2.Csuit;
}

//compare two cards by their suits first
template<typename R, typename S>
bool Compare_Suit(const Card_T<R,S> &c1, const Card_T<R,S> &c2){
    if(c1.Csuit<c2.Csuit) return true;
    else if (c2.Csuit<c1.Csuit) return false;
    return c1.Crank< c2.Crank;
}