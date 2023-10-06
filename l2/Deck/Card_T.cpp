
using std::ostream, std::endl;
// Definition of the Card_T classes, just a constructor and a 
// simple operator overloading

template <typename R, typename S> 
Card_T<R, S>:: Card_T(R _rank, S _suit): rank(_rank), suit(_suit){}

template <typename R, typename S> 
ostream& operator<< (ostream& os,const Card_T<R,S>& card){
    return os << card.rank << card.suit;
}

template <typename R, typename S>
bool rankCompare(const Card_T<R,S>& card1, const Card_T<R,S>& card2) {
    if (card1.rank == card2.rank) {
        return card1.suit < card2.suit;
    }
    return card1.rank < card2.rank;
}

template <typename R, typename S>
bool suitCompare(const Card_T<R,S>& card1, const Card_T<R,S>& card2) {
    if (card1.suit == card2.suit) {
        return card1.rank < card2.rank;
    }
    return card1.suit < card2.suit;
}


template <typename R, typename S>
bool operator==(const Card_T<R,S>& card1, const Card_T<R,S>& card2) {
    return card1.rank == card2.rank && card1.suit == card2.suit;
}