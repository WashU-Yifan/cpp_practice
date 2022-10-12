#include "CardSet.h"
#include<iostream>
#include<stdexcept>
using std::ostream;
using std::size_t;
using std::cout;
using std::endl;

template <typename R, typename S>
void CardSet<R,S>::print(std::ostream& os,std::size_t size){
    size_t cnt=0;
    for(auto card:this->cardset){
        os<<card<<" ";
        if(++cnt==size){
            cnt=0;
            os<<endl;
        }
    }
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