#pragma once

#include "Game.h"
#include "HoldEmDeck.h"
#include<vector>
#include<algorithm>
#include <queue>
#include<iostream>
#define Two 2
#define Three 3
#define Four 4
#define HoldEmHandSize 5
using std::vector;
enum class HoldEmState{
    preflop,
    flop,
    turn,
    river,
    undefined
};

enum class HoldEmHandRank{
    xhigh, 
    pair, 
    twopair, 
    threeofakind, 
    straight, 
    flush, 
    fullhouse,
    fourofakind,
    straightflush, 
    undefined
};

class HoldEmGame:public Game{
    private:
        HoldEmHandRank holdem_hand_evaluation(const CardSet<HoldEmRank,Suit>&);
        void printstatus();
        void Collect_hands();
        struct PlayerStatus{
            PlayerStatus(CardSet<HoldEmRank,Suit> _PHand,std::string &_PName,HoldEmHandRank _PRank):
                    PlayerHand(_PHand),PlayerName(_PName),PlayerRank(_PRank){};
            CardSet<HoldEmRank,Suit> PlayerHand;
            std::string PlayerName;
            HoldEmHandRank PlayerRank;

        };
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
        friend bool operator<(const HoldEmGame::PlayerStatus&,const HoldEmGame::PlayerStatus&);
        friend std::ostream& operator<<(std::ostream&,const PlayerStatus& );
        HoldEmGame(int argc, const char* argv[]);
        virtual int play() override;

};
bool operator<(const HoldEmGame::PlayerStatus&,const HoldEmGame::PlayerStatus&);

void operator++(HoldEmState& state);
std::ostream& operator<<(std::ostream&,const HoldEmHandRank&);
std::ostream& operator<<(std::ostream&,const HoldEmGame::PlayerStatus&);


bool check_straight(vector<Card_T<HoldEmRank, Suit> >* );
bool check_flush(vector<Card_T<HoldEmRank, Suit> >* );
HoldEmHandRank check_same_rank(std::vector<Card_T<HoldEmRank, Suit> >* );
std::pair<int,int>get_rank_num(std::vector<Card_T<HoldEmRank, Suit> >* );



bool straight_compare( vector<Card_T<HoldEmRank, Suit> >&,vector<Card_T<HoldEmRank, Suit> >&);
bool pair_compare(vector<Card_T<HoldEmRank, Suit> >&,vector<Card_T<HoldEmRank, Suit> >&);
bool two_pair_compare( vector<Card_T<HoldEmRank, Suit> >&,vector<Card_T<HoldEmRank, Suit> >&);
bool three_compare( vector<Card_T<HoldEmRank, Suit> >&,vector<Card_T<HoldEmRank, Suit> >&);
bool full_compare(vector<Card_T<HoldEmRank, Suit> >&,vector<Card_T<HoldEmRank, Suit> >&);
bool four_compare(vector<Card_T<HoldEmRank, Suit> >&,vector<Card_T<HoldEmRank, Suit> >&);
bool high_compare(vector<Card_T<HoldEmRank, Suit> >&,vector<Card_T<HoldEmRank, Suit> >&);
int extract_pair(vector<Card_T<HoldEmRank, Suit> >& v);
int extract_three(vector<Card_T<HoldEmRank, Suit> >& v);
int extract_four(vector<Card_T<HoldEmRank, Suit> >& v);