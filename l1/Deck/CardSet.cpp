
#include "CardSet.h"

template
<typename R, typename S>
void CardSet<R, S>::print(std::ostream& os, size_t size) {
    int i = 0;
    for (auto & card : deck) {
        os << card << " ";
        if(!((++i) % size)) {
            os << endl;
        }
    }
    if (i % size) os << endl;
}

template
<typename R, typename S>
CardSet<R, S>& CardSet<R, S>::operator>>(CardSet<R,S>& set) {
    if (isEmpty()) {
        throw std::runtime_error("Card Set empty");
    }
    else {
        auto card = deck.back();
        set.deck.push_back(card);
        deck.pop_back(); 
    }
    return *this;
}