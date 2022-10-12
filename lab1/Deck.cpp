#include "Deck.h"
template<typename R, typename S>
void Deck<R,S>::shuffle(){
    std::random_device rd;
    std::mt19937 rn(rd());
    std::shuffle(CardSet<R,S>::cardset.begin(),CardSet<R,S>::cardset.end(),rn);
}
