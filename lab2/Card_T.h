#pragma once
#include<iostream>

// data structure of a card,
// have two member variables: rank and suit
template <typename R, typename S> 
class Card_T{
    public:
    R rank;
    S suit;
    Card_T(R rank_, S suit_){
        rank=rank_;
        suit=suit_;
    }
};
template <typename R, typename S>
std::ostream& operator<< (std::ostream& os,const Card_T<R,S>& card);

template<typename R, typename S>
bool Compare_Rank(const Card_T<R,S> &c1, const Card_T<R,S>& c2);
template<typename R, typename S>
bool Compare_Suit(const Card_T<R,S> &c1, const Card_T<R,S>& c2);

 #ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "Card_T.cpp"
  #endif
