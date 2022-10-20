#pragma once
#include"CardSet.h"
#include "Game.h"
#include "HoldEmDeck.h"
#include<vector>
enum class HoldEmState{
    preflop,
    flop,
    turn,
    river,
    undefined
};
void operator++(HoldEmState& state);
class HoldEmGame:public Game{
    protected:
        HoldEmState GameState;
        HoldEmDeck Deck;
        std::vector<CardSet<HoldEmRank,Suit> > PlayerHands;
        CardSet<HoldEmRank,Suit> Shared;

        virtual void deal();
        void deal_preflop();
        void deal_flop();
        void deal_turn();
        void deal_river();
        void reset();
    public:
        HoldEmGame(int argc, const char* argv[]);
        virtual int play() override;
    private:
        void printstatus();
        void Collect_hands();
};