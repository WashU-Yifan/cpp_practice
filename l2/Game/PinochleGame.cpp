#include "PinochleGame.h"
#include <algorithm>
using std::sort, std:: cout, std::vector, std::string, std::runtime_error;


vector<unsigned int> PinochleGame::pinochlePoint = {10, 20, 40, 40, 40, 60, 80, 100, 150, 300, 400, 600, 800, 1000, 1500};
vector<string> PinochleGame::pinochleName = {
    "dix",
    "offsuitmarriage",
    "fortyjacks",
    "pinochle",
    "insuitmarriage",
    "sixtyqueens",
    "eightykings",
    "hundredaces",
    "insuitrun",
    "doublepinochle",
    "fourhundredjacks",
    "sixhundredqueens",
    "eighthundredkings",
    "thousandaces",
    "insuitdoublerun"
};

PinochleGame::PinochleGame(int argc, const char ** argv): 
    Game(argc, argv), 
    deck(Pinochle()),
    playersHands(argc, CardSet<PinochleRank,Suit>()) {
        
}

//deal 3 cards to each player until the end
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
        //Has levitate the sorting process from the suitIndependentEvaluation function
        //Since printing the players's hand with rank would give a better intuition if 
        //the score checking function fails
        auto deck = CardSet<PinochleRank, Suit>::getDeck(playersHands[i]);
        sort(deck->begin(), deck->end(), rankCompare<PinochleRank, Suit>);

        cout << players[i] << endl;

        playersHands[i].print(cout, PINOCHLENUM);
        finalizeScore(playersHands[i]);
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

/*
*finalize the score for each player, and then print out their scores
*/
void PinochleGame::finalizeScore(const CardSet<PinochleRank, Suit>& cardSet) {
    vector<PinochleMelds> melds;
    suitIndependentEvaluation(cardSet, melds);
    for (auto& meld : melds) {
        cout << meld << endl;
    }
}

void PinochleGame::suitIndependentEvaluation(const CardSet<PinochleRank, Suit>& cardSet, vector<PinochleMelds>& melds) {
    CardSet<PinochleRank, Suit> copy(cardSet);
    vector<Card_T<PinochleRank, Suit> > * copyDeck = CardSet<PinochleRank, Suit>::getDeck(copy);
    int aCount = 0, kCount = 0, qCount = 0, jCount = 0;
    int aBitMap = 0, kBitMap = 0, qBitMap = 0, jBitMap = 0;
    int jDiamond = 0, qSapdes = 0;
    for (auto& card : *copyDeck) {
        if (card.rank == PinochleRank::ace) {
            countCard(card.suit, aCount, aBitMap);
        }
        else if (card.rank == PinochleRank::king) {
            countCard(card.suit, kCount, kBitMap);
        }
        else if (card.rank == PinochleRank::queen) {
            countCard(card.suit, qCount, qBitMap);
            qSapdes += card.suit == Suit::spades;
        }
        else if (card.rank == PinochleRank::jack) {
            countCard(card.suit, jCount, jBitMap);
            jDiamond += card.suit == Suit::diamonds;
        }
    }

    if(aCount == PINOCHLE_FULLRANK) melds.push_back(PinochleMelds::thousandaces);
    else if (aBitMap == PINOCHLE_FOURSUITSMAP) melds.push_back(PinochleMelds::hundredaces);
    
    if(kCount == PINOCHLE_FULLRANK) melds.push_back(PinochleMelds::eighthundredkings);
    else if (kBitMap == PINOCHLE_FOURSUITSMAP) melds.push_back(PinochleMelds::eightykings);
    
    if(qCount == PINOCHLE_FULLRANK) melds.push_back(PinochleMelds::sixhundredqueens);
    else if (qBitMap == PINOCHLE_FOURSUITSMAP) melds.push_back(PinochleMelds::sixtyqueens);
    
    if(jCount == PINOCHLE_FULLRANK) melds.push_back(PinochleMelds::fourhundredjacks);
    else if (jBitMap == PINOCHLE_FOURSUITSMAP) melds.push_back(PinochleMelds::fortyjacks);
    
    if (jDiamond == qSapdes && jDiamond == PINOCHLE_DOUBLE) melds.push_back(PinochleMelds::doublepinochle);
    else if(jDiamond && qSapdes) melds.push_back(PinochleMelds::pinochle);
}


void countCard(const Suit& suit, int& count, int& map){
    ++count;
    map |= 1 << static_cast<int>(suit);
}

std::ostream& operator<<(std::ostream& os, const PinochleMelds& pinochleMelds) {
    os << PinochleGame::pinochleName[static_cast<int>(pinochleMelds)] <<
         " " << PinochleGame::pinochlePoint[static_cast<int>(pinochleMelds)];
    return os;
}

