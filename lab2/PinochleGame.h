#pragma once

#include<vector>

#include<unordered_set>
#include <iomanip>

#include "Game.h"
#include"PinochleDeck.h"
#define thousands 8
#define hundreds 4
#define longest_meld_name 17
#define largest_meld_point 4

enum class PinochleMelds{
    dix=0,
    offsuitmarriage=1,
    fortyjacks=2,
    pinochle=3,
    insuitmarriage=4,
    sixtyqueens=5,
    eightykings=6,
    hundredaces=7,
    insuitrun=8,
    doublepinochle=9,
    fourhundredjacks=10,
    sixhundredqueens=11,
    eighthundredkings=12,
    thousandaces=13,
    insuitdoublerun=14

};

class PinochleGame:public Game{

    protected:
        PinochleDeck SharedDeck;
        std::vector<CardSet<PinochleRank,Suit> > PlayerHands;
        virtual void deal();//distribute the card among players
    public:
        static std::vector<unsigned int>PinochlePoints;
        static std::vector<std::string>PinochleNames;
        PinochleGame(int argc, const char* argv[]);
        virtual int play() override;
    private:
        void print_status();
        void print_melds( std::vector<CardSet<PinochleRank,Suit> >::size_type,const std::vector<PinochleMelds>&);
        void suit_independent_evaluation(const CardSet<PinochleRank,Suit>&,std::vector<PinochleMelds>&);
};


std::ostream& operator<<(std::ostream&, const PinochleMelds&);
//convert PinochleMelds into corresponding index in Pinochlepoints and in PinochleNames

int to_PinochlePoints_index(const PinochleMelds& PM);

//helper functions to check combinations 
void check_TH(std::vector<Card_T<PinochleRank,Suit> >*,std::vector<PinochleMelds>&);
void add_eight(std::vector<PinochleMelds>& ,PinochleRank);
void add_four(std::vector<PinochleMelds>& ,PinochleRank);
void check_Pino(std::vector<Card_T<PinochleRank,Suit> >*,std::vector<PinochleMelds>&);
