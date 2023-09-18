#include "Deck.h"
#include <random>
#include <algorithm>

template
<typename R, typename S>
void Deck<R, S>::shuffle() {
    std::random_device rd;
    std::mt19937 rn(rd());
    std::shuffle(CardSet<R, S>::deck.begin(), CardSet<R, S>::deck.end(), rn);
}

template
<typename R, typename S>
void Deck<R, S>::collect(CardSet<R, S>& cardSet) {
    while(!cardSet.isEmpty()) {
        cardSet >> *this;
    }
}