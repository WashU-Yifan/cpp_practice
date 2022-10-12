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



 #ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "Card_T.cpp"
<<<<<<< HEAD
  #endif
=======
  #endif
>>>>>>> 749a9722c9bd07f9f1a0c74866de2d67cab77f01
