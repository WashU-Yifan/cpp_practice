#pragma once
#include <vector>
#include <iostream>
#include <set>
#include "../Deck/HoldEmDeck.h"
#include "../Deck/PinochleDeck.h"
#include "../Deck/UnoDeck.h"

using std::ostream;
const int BOOK = 4;
const int PLAYERTHRESHOLD = 2;
const int TWOPLAYERHAND = 7;
const int MOREPLAYERHAND = 5;

template 
<typename R = HoldEmRank, typename S =  Suit, typename Deck = HoldEm>
class GoFishGame: public Game {

    static_assert(std::is_base_of<CardSet<R, S>, Deck>::value, 
        "The Deck is not a template specialization of CardSet<R, S>");


    public:
        GoFishGame(int, const char **);
        virtual ~GoFishGame()= default;
        virtual int play();
    protected:
       
        virtual void printPlayers();
        virtual void collectHands();
        Deck deck;
        std::vector< CardSet<R, S> > playersHand, playersBook;

        virtual void deal();
    private:
        bool requestCard(int);
        bool collectBooks(int);
        bool turn(int);
        bool deckCheck();
        bool terminationCheck();
        R requestRank();
        void printPlayer(int);
        std::set<int> evictedPlayers;
};

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
    #include "GoFishGame.cpp"
#endif