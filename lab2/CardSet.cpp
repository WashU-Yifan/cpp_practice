#include "CardSet.h"
#include<iostream>
#include<stdexcept>
using std::ostream;
using std::size_t;
using std::cout;
using std::endl;


template<typename R, typename S>
std::vector<Card_T<R,S>>* CardSet<R,S>::get_cards(CardSet<R,S>& c){
    return &c.cardset;
}


template<typename R, typename S>
CardSet<R,S>::CardSet(const CardSet<R,S>& copy):
rank(copy.rank),suit(copy.suit),cardset(copy.cardset){
    //vector's copy contructor does deep copy by default, no need to explicitly copy the vector.
}

//print the card set in ascending order without modifying the original object
template <typename R, typename S>
void CardSet<R,S>::print(std::ostream& os,std::size_t size) const{

    CardSet<R,S> copy(*this);
    sort(copy.cardset.begin(),copy.cardset.end(), Compare_Rank<R,S>);
    size_t cnt=0;
    for(auto &card:copy.cardset){
        os<<card<<" ";
        if(++cnt==size){
            cnt=0;
            os<<endl;
        }
    }
    if(cnt) os<<endl;
}


template<typename R,typename S>
CardSet<R,S>& CardSet<R,S>::operator>>(CardSet<R,S>& set2){
    if(is_empty()){
        throw std::runtime_error("current cardset is empty");
    }
    else{
        set2.cardset.push_back(*(this->cardset.end()-1));
        this->cardset.pop_back();
    }
    return *this;
}