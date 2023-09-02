#include "Card_T.h"
using namespace std;


template <typename R, typename S> 
ostream& operator<< (ostream& os,const card_T<R,S>& card){
    return os << card.rank << card.suit;
}
