#include "Card_T.h"
using namespace std;
// Definition of the Card_T classes, just a constructor and a 
// simple operator overloading

template <typename R, typename S> 
Card_T<R, S>:: Card_T(R _rank, S _suit): rank(_rank), suit(_suit){}

template <typename R, typename S> 
ostream& operator<< (ostream& os,const Card_T<R,S>& card){
    return os << card.rank << card.suit;
}
