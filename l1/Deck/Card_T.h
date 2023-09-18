#pragma once
#include<iostream>

//Card template struct
//have two member variables: rank and suit
template 
<typename R, typename S> 
struct Card_T {
    R rank;
    S suit;
    Card_T(R _rank, S _suit): rank(_rank), suit(_suit){}
};


template <typename R, typename S>
std::ostream& operator<< (std::ostream& os,const Card_T<R,S>& card); 

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
    #include "Card_T.cpp"
#endif