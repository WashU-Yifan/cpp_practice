#include "Deck.h"
template<typename R, typename S>
void Deck<R,S>::shuffle(){
    std::random_device rd;
    std::mt19937 rn(rd());
    std::shuffle(CardSet<R,S>::cardset.begin(),CardSet<R,S>::cardset.end(),rn);
}

template<typename R, typename S>
void Deck<R,S>::collect(CardSet<R,S>& set2){
    try{
        while(!set2.is_empty()) set2>>*this;
    }
    catch(runtime_error &e){
	    std:: cout<<e.what()<<std::endl;
    }
}
