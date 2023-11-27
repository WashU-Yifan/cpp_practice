#include "Deck.h"
#include <random>
#include <algorithm>

// Definition of the Deck class, all derived class of deck
// can evoke shuffle itself to randomly shuffle the cards, 
// and collect to collect other cards from another deck


template
<typename R, typename S>
void Deck<R, S>::shuffle() {
    std::random_device rd;
    std::mt19937 rn(rd());
    std::shuffle(CardSet<R, S>::deck.begin(), CardSet<R, S>::deck.end(), rn);
}

