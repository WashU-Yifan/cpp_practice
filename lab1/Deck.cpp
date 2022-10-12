#include "Deck.h"
template<typename R, typename S>
void Deck<R,S>::shuffle(){
<<<<<<< HEAD
    std::random_device rd;
    std::mt19937 rn(rd);
    std::shuffle(CardSet<R,S>::cardset.begin(),CardSet<R,S>::cardset.end(),rn);
=======
    std::random_device rd();
    std::mt19937 rn(rd);
    std::shuffle(cardset.begin(),cardset.end(),rn);
>>>>>>> ec542e07ab5b3e423adc233d3ee8dee0c32685e9
}
