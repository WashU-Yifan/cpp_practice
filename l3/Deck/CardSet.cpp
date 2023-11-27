
#include "CardSet.h"
#include <algorithm>

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
void CardSet<R, S>::sort() {
    std::sort(deck.begin(), deck.end(), [](const Card_T<R,S>& card1, const Card_T<R,S>& card2) {
        return card1.rank < card2.rank;
    });
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

template
<typename R, typename S>
CardSet<R, S>::CardSet(const CardSet<R,S>& cardSet) {
    for (auto card : cardSet.deck) {
        deck.push_back(card);
    }
}

template
<typename R, typename S>
void CardSet<R, S>::collect(CardSet<R, S>& cardSet) {
    //collect the parameter's card element into the caller container
    std::move(cardSet.getDeckBegin(), cardSet.getDeckEnd(), std::back_inserter(deck));
    cardSet.deck.clear();
}

template
<typename R, typename S>
void CardSet<R, S>::collectIf(CardSet<R, S>& cardSet, std::function<bool(card_type&)> predicate) {
    //collect cards that meet a certain criteria,
    std::copy_if(cardSet.getDeckBegin(), cardSet.getDeckEnd(), std::back_inserter(deck), predicate);
    auto iter = std::remove_if(cardSet.getDeckBegin(), cardSet.getDeckEnd(), predicate);
    cardSet.deck.erase(iter, cardSet.getDeckEnd());

}


template
<typename R, typename S>
bool CardSet<R, S>::request(CardSet<R, S>& cardSet, R rank) {
    auto iter = std::find_if(cardSet.getDeckBegin(), cardSet.getDeckEnd(), [rank](const Card_T<R,S>& card){return card.rank == rank;});
    if (iter == cardSet.getDeckEnd()) {
        return false;
    }
    deck.push_back(*iter);
    cardSet.deck.erase(iter);
    return true;
}