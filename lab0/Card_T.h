#pragma once
#include<iostream>

// data structure of a card,
// have two member variables: rank and suit
template <typename R, typename S> struct card_T{
    R rank;
    S suit;
    card_T(R rank_, S suit_){
        rank=rank_;
        suit=suit_;
    }
};
// template function has to be defined insid the header file
template <typename R, typename S>std::ostream& operator<< (std::ostream& os,const card_T<R,S>& card){
    return os<<card.rank<<card.suit;
}