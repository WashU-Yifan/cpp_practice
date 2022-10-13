#include "HoldEmGame.h"
#define CardPerLine 5
#define success 0

using std::cout;
using std::endl;
using std::runtime_error;
using std::cin;

typedef std::vector<int>::size_type size;
HoldEmGame:: HoldEmGame(int argc, const char *argv[]):Game(argc,argv),
GameState(HoldEmState::preflop),PlayerHands(argc,HoldEmDeck()){}

void HoldEmGame::deal(){
    switch(GameState){
        case(HoldEmState::preflop):{
            deal_preflop();
            break;
        }
        case (HoldEmState::flop):{
            deal_flop();
            break;
        }
        case (HoldEmState::turn):{
            deal_turn();
            break;
        }
        case (HoldEmState::river):{
            deal_river();
            break;
        }
        default:
            return;
    }
}


int HoldEmGame::play(){
    while(1){
        Deck.shuffle();
        reset();//reset the HoldEmGame::GameState
        deal();//2cards to each player
        printstatus();//print player's name & hands
        deal();//flop
        deal();//turn
        deal();//river
        Collect_hands();//collect player's cards
        if (end()) return success;

    }
}

void HoldEmGame::printstatus(){
     for(size i=0;i<PlayerHands.size();++i){
        cout<<"Player Name: "<<PlayerNames[i]<<"\n Hands:"<<endl;
        PlayerHands[i].print(cout,CardPerLine);
    }
}

void HoldEmGame::Collect_hands(){
    for(auto &hand:PlayerHands)Deck.collect(hand);
}
//2 cards to each player's hand
void HoldEmGame::deal_preflop(){
    try{
        for(CardSet playerhand:PlayerHands){
            Deck>>playerhand;
        }
        for(CardSet playerhand:PlayerHands){
            Deck>>playerhand;
        }
        ++GameState;
    }
    catch(runtime_error &e){
        cout<< e.what()<<endl;

    }
}

//3 card to shared
void HoldEmGame::deal_flop(){
    try{
        Deck>>Shared>>Shared>>Shared;
        cout<<"BOARD(flop): ";
        Shared.print(cout,CardPerLine);
        ++GameState;
    }
    catch(runtime_error &e){
        cout<< e.what()<<endl;

    }
}

//1 card to shared
void HoldEmGame:: deal_turn(){
     try{
        Deck>>Shared;
        ++GameState;
        cout<<"BOARD(turn): ";
        Shared.print(cout,CardPerLine);
    }
    catch(runtime_error &e){
        cout<< e.what()<<endl;

    }
}

//1 card to shared b
void HoldEmGame:: deal_river(){
     try{
        Deck>>Shared;
        ++GameState;
        cout<<"BOARD(river): ";
        Shared.print(cout,CardPerLine);
    }
    catch(runtime_error &e){
        cout<< e.what()<<endl;

    }
}

void operator++(HoldEmState& state){
    switch (state){
        case(HoldEmState::preflop):{state=HoldEmState::flop;return;}
        case (HoldEmState::flop):{state=HoldEmState::turn;return;}   
        case (HoldEmState::turn):{state=HoldEmState::river;return;}
        case (HoldEmState::river):{state=HoldEmState::undefined;return;}
        default:{state=HoldEmState::undefined;;return;}
    }
}


void HoldEmGame::reset(){
    GameState=HoldEmState::preflop;
}