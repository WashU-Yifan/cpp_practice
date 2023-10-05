#include "HoldEmGame.h"
 
using std:: cout;
using std:: endl;

HoldEmGame::HoldEmGame(int argc, const char ** argv): 
    Game(argc, argv), 
    state(HoldEmState:: preflop),
    deck(HoldEm()),
    playersHands(argc, CardSet<HoldEmRank,Suit>()),
    sharedHands(CardSet<HoldEmRank,Suit>()) {
}

void HoldEmGame::deal() {
    switch (state) {
        case HoldEmState:: preflop:
            dealPreFlop();
            break;
        case HoldEmState:: flop:
            dealFlop();
            break;
        case HoldEmState:: turn:
            dealTurn();
            break;
        case HoldEmState:: river:
            dealRiver();
            break;
        default: 
            return;
    }
}

void HoldEmGame:: printPlayers() {
    for (long unsigned int i = 0; i < playersHands.size(); ++i) {
        cout << players[i] << endl;
        playersHands[i].print(cout, HOLDEMNUM);
    }
}

void HoldEmGame:: collectHands() {
    for (long unsigned int i = 0; i < playersHands.size(); ++i) {
        deck.collect(playersHands[i]);
    }
    deck.collect(sharedHands);
}

int HoldEmGame::play() {
    while(true){
        deck.shuffle();
        state = HoldEmState:: preflop;
        deal(); //preflop
        printPlayers();

        deal();//flop
        deal();//turn    
        deal();//river
 

        collectHands();
        int gameStatus = continueGame();
        if (gameStatus == CONTINUEGAME) {
            continue;
        }
        else {
            return gameStatus;
        }
    }
}


void HoldEmGame::dealPreFlop() {
    for (long unsigned int i = 0; i < playersHands.size(); ++i) {
        deck >> playersHands[i];
    }
    for (long unsigned int i = 0; i < playersHands.size(); ++i) {
        deck >> playersHands[i];
    }
    state = HoldEmState::flop;
}

void HoldEmGame::dealFlop() {
    deck >> sharedHands >> sharedHands >> sharedHands;
    printShared();
    state = HoldEmState::turn;
}

void HoldEmGame::dealTurn() {
    deck >> sharedHands;
    printShared();
    state = HoldEmState::river;
}

void HoldEmGame::dealRiver() {
    deck >> sharedHands;
    printShared();
    state = HoldEmState::undefined;
}

void HoldEmGame::printShared() {
    switch (state) {
        case HoldEmState:: flop:
            cout << "BOARD (flop):";
            sharedHands.print(cout, HOLDEMNUM);
            break;
        case HoldEmState:: turn:
            cout << "BOARD (turn):";
            sharedHands.print(cout, HOLDEMNUM);
            break;
        case HoldEmState:: river:
            cout << "BOARD (river):";
            sharedHands.print(cout, HOLDEMNUM);
            break;
        default: 
            return;
    }
}