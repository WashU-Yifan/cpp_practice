#pragma once
#include<iostream>

//Card template struct
//have two member variables: rank and suit
template <typename R, typename S> struct card_T {
    R rank;
    S suit;
    card_T(R _rank, S _suit): rank(_rank), suit(_suit){}
};


template <typename R, typename S>
std::ostream& operator<< (std::ostream& os,const card_T<R,S>& card); 

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
    #include "Card_T.cpp"
#endif