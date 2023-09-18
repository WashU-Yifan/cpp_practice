#include "PinochleGame.h"
 
using std:: cout;
using std:: endl;

PinochleGame::PinochleGame(int argc, const char ** argv): 
    Game(argc, argv), 
    deck(Pinochle()),
    playersHands(argc, CardSet<PinochleRank,Suit>()) {
        
}

void PinochleGame::deal() {
    long unsigned int index = 0;
    while(!deck.isEmpty()) {
        try {
            deck >> playersHands[index] >>  playersHands[index] >> playersHands[index];
        }
        catch(runtime_error &e){
            cout << e.what() << "Deck is empty" << endl;
            return;
        }
        index = (index + 1) % playersHands.size();
    }
}

void PinochleGame:: printPlayers() {
    for (long unsigned int i = 0; i < playersHands.size(); ++i) {
        cout << players[i] << endl;
        playersHands[i].print(cout, PINOCHLENUM);
    }
}

void PinochleGame:: collectHands() {
    for (long unsigned int i = 0; i < playersHands.size(); ++i) {
        deck.collect(playersHands[i]);
    }
}

int PinochleGame::play() {
    while(true){
        deck.shuffle();
        deal();
        printPlayers();
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
