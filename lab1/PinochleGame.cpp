#include "PinochleGame.h"
#define CardPerLine 6
#define success 0
using std::cout;
using std::endl;
using std::runtime_error;
typedef std::vector<CardSet<PinochleRank,Suit> >::size_type size;

PinochleGame::PinochleGame(int argc, const char* argv[]):Game(argc,argv),PlayerHands(argc,PinochleDeck()){}

void PinochleGame::deal(){
    while(!Deck.is_empty()){
        for(auto playerdeck:PlayerHands){
            try{
                Deck>>playerdeck>>playerdeck>>playerdeck;
            }
            catch(runtime_error &e){
                cout<<e.what()<<"Deck is empty"<<endl;
                return;
            }
        }
    }
    
}

/*
    1 shuffle the deck
    2 distribute the card
    3 print player's name and their cards
    4 collect player's card
    5 continue to 1 or stop
*/
int PinochleGame::play(){
    while(1){
        Deck.shuffle();
        deal();
        printstatus();
       if (end()) return success;
    }
}

//helper function that print player's naem and their cards
void PinochleGame::printstatus(){
    for(size i=0;i<PlayerHands.size();++i){
        cout<<"Player Name: "<<PlayerNames[i]<<"\n Hands:"<<endl;
        PlayerHands[i].print(cout,CardPerLine);
        Deck.collect(PlayerHands[i]);
    }
}