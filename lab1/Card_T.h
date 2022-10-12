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
 #ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "Card_T.cpp"
  #endif
