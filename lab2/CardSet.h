#pragma once 
#include "Card_T.h"

#include<vector>
template<typename R, typename S> class CardSet{
    public:
        CardSet()=default;
        CardSet(const CardSet<R,S>& );

        static std::vector< Card_T<R,S> >* get_cards(CardSet<R,S>&);
        CardSet<R,S>& operator>>(CardSet<R,S>& set2);
        inline bool is_empty(){return cardset.empty();}
        void print(std::ostream& os,std::size_t size) const;
    protected:
        R rank;
        S suit;
        std::vector< Card_T<R,S> > cardset;

};


#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include"CardSet.cpp"
#endif
