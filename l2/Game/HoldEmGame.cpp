#include "HoldEmGame.h"
 
using std::cout, std::endl, std::vector, std::string;


vector<string> HoldEmGame::holdEmRankName = {
    "xhigh",
    "pair",
    "twopair",
    "threeofakind",
    "straight",
    "flush",
    "fullhouse",
    "fourofakind",
    "straightflush",
    "undefined"
};

HoldEmGame::HoldEmGame(int argc, const char ** argv): 
    Game(argc, argv), 
    state(HoldEmState:: preflop),
    deck(HoldEm()),
    playersHands(argc, CardSet<HoldEmRank,Suit>()),
    sharedHands(CardSet<HoldEmRank,Suit>()) {
}

HoldEmGame::HoldEmHand::HoldEmHand(const CardSet<HoldEmRank, Suit>& cards, const std::string& name, HoldEmHandRank rank):
cardSet(cards), playerName(name), handRank(rank) {}

HoldEmHandRank HoldEmGame::holdEmHandEvaluation(const CardSet<HoldEmRank, Suit>& cardSet) {
    CardSet<HoldEmRank, Suit> deckCopy(cardSet);
    auto evalHands = *CardSet<HoldEmRank, Suit>::getDeck(deckCopy);
    for (auto& card : *CardSet<HoldEmRank, Suit>::getDeck(sharedHands)) {
        evalHands.push_back(card);
    }
    if (evalHands.size() < HOLDEMMIN) return HoldEmHandRank::undefined;
    vector<int> cardBitMap(HOLDEMRANKNUM,0);
    for (auto & card: evalHands) {
        cardBitMap[static_cast<int>(card.rank)] |= 1 << static_cast<int>(card.suit);
    }
    int sameRank[SUITNUM] = {0}, sameSuit[SUITNUM] = {0}, sameSuitStraight = 0, straigtNum = 1;
    bool straight = false;
    for (vector<int>::size_type i = 0; i < cardBitMap.size(); ++i) {
       
        if (i && cardBitMap[i] && cardBitMap[i - 1]) { //check straight
            ++straigtNum;
            if (cardBitMap[i] & cardBitMap[i - 1]) {//has same suit
                ++sameSuitStraight;
            }
            if(sameSuitStraight == STRAIGHTNUM) return HoldEmHandRank::straightflush;
            if (straigtNum == STRAIGHTNUM) straight = true;
        }
        else {
            sameSuitStraight = 1;
            straigtNum = 1;
        }

        int cardsSameRank = 0, tmp = cardBitMap[i];
        while(tmp){
            cardsSameRank++;
            tmp &= tmp - 1;
        }
        sameRank[cardsSameRank]++;

        if (cardBitMap[i] & CLUBBIT) sameSuit[static_cast<int>(Suit::clubs)]++;
        if (cardBitMap[i] & DIAMONDSBIT) sameSuit[static_cast<int>(Suit::diamonds)]++;
        if (cardBitMap[i] & HEARTSBIT) sameSuit[static_cast<int>(Suit::hearts)]++;
        if (cardBitMap[i] & SPADESBIT) sameSuit[static_cast<int>(Suit::spades)]++;
    }

    if (sameRank[FOUROFAKIND]) return HoldEmHandRank::fourofakind;
    if (sameRank[THREEOFAKIND] && sameRank[PAIR]) return HoldEmHandRank::fullhouse;

    for (int i = 0; i < SUITNUM; ++i) {
        if (sameSuit[i] == FLUSHNUM) return HoldEmHandRank::flush;
    }

    if (straight) return HoldEmHandRank::straight;
    if (sameRank[THREEOFAKIND]) return HoldEmHandRank::threeofakind;
    if (sameRank[PAIR] == PAIR) return HoldEmHandRank::twopair;
    if (sameRank[PAIR]) return HoldEmHandRank::pair;
    return HoldEmHandRank::xhigh; 

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
        auto deck = CardSet<HoldEmRank, Suit>::getDeck(playersHands[i]);
        sort(deck->begin(), deck->end(), rankCompare<HoldEmRank, Suit>);

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
        vector<HoldEmGame::HoldEmHand> playerRanks;
        for (long unsigned int i = 0; i < playersHands.size(); ++i) {
            auto sharedHandsCopy(sharedHands);
            playerRanks.push_back(HoldEmGame::HoldEmHand(playersHands[i], players[i], HoldEmHandRank::undefined));
            sharedHandsCopy >> playerRanks[i].cardSet >> playerRanks[i].cardSet >> playerRanks[i].cardSet;
            
            auto playerDeck = CardSet<HoldEmRank, Suit>::getDeck(playerRanks[i].cardSet);
            sort(playerDeck->begin(), playerDeck->end(), rankCompare<HoldEmRank, Suit>);

            playerRanks[i].handRank = holdEmHandEvaluation(playerRanks[i].cardSet);
        }
        sort(playerRanks.begin(), playerRanks.end());
        cout << "Current rank after flop:" << endl;
        for (long unsigned int i = playersHands.size() - 1; i < playersHands.size(); --i) {
            cout << "Player Name: " << playerRanks[i].playerName << ", cardSet: ";
            playerRanks[i].cardSet.print(cout, HOLDEMNUM);
            cout << "Rank: " << playerRanks[i].handRank << endl;
        }
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


ostream& operator<<(ostream& os, const HoldEmHandRank& holdEmHandRank) {
    os << HoldEmGame::holdEmRankName[static_cast<int>(holdEmHandRank)];
    return os;
}


bool operator<(const HoldEmGame::HoldEmHand& hand1, const HoldEmGame::HoldEmHand &hand2) {
    if (hand1.handRank != hand2.handRank) {
        return hand1.handRank < hand2.handRank;
    }
    auto handCopy1(hand1), handCopy2(hand2);
    vector< Card_T<HoldEmRank, Suit> > deck1 = *CardSet<HoldEmRank, Suit>::getDeck(handCopy1.cardSet),
    deck2 = *CardSet<HoldEmRank, Suit>::getDeck(handCopy2.cardSet);
    switch(hand1.handRank){
        case (HoldEmHandRank::xhigh)://comparison for straight and straightflush can be shared with the high/flush
        case (HoldEmHandRank::straight)://since they both compare the highest rank cards.
        case (HoldEmHandRank::straightflush):
        case (HoldEmHandRank::flush): return compareHigh(deck1, deck2);
        case (HoldEmHandRank::pair): return comparePair(deck1, deck2);          
        case (HoldEmHandRank::twopair): return compareTwoPair(deck1, deck2);
        case (HoldEmHandRank::threeofakind): return compareThree(deck1, deck2);
        case (HoldEmHandRank::fullhouse): return compareFull(deck1, deck2);
        case (HoldEmHandRank::fourofakind): return compareFour(deck1, deck2);
        default: return false;
    }
}



bool compareHigh(vector< Card_T<HoldEmRank, Suit> > deck1, vector< Card_T<HoldEmRank, Suit> > deck2) {
    for (vector<Card_T<HoldEmRank, Suit> >::size_type i = deck1.size(); i < deck1.size(); --i) {
        if (deck1[i].rank == deck2[i].rank) continue;
        return rankCompare<HoldEmRank, Suit>(deck1[i], deck2[i]);
    }
    return false;
}
bool comparePair(vector< Card_T<HoldEmRank, Suit> > deck1, vector< Card_T<HoldEmRank, Suit> > deck2) {
    auto rank1 = extract(deck1, PAIR), rank2 = extract(deck2, PAIR);
    if (rank1 == rank2) return compareHigh(deck1, deck2);
    return rank1 < rank2;
}


bool compareTwoPair(vector< Card_T<HoldEmRank, Suit> > deck1, vector< Card_T<HoldEmRank, Suit> > deck2) {
    auto rank1deck1 = extract(deck1, PAIR), rank1deck2 = extract(deck2, PAIR);
    auto rank2deck1 = extract(deck1, PAIR), rank2deck2 = extract(deck2, PAIR);
    if (rank1deck1 != rank1deck2) return rank1deck1 < rank1deck2;
    if (rank2deck1 != rank2deck2) return rank2deck1 < rank2deck2;
    return compareHigh(deck1, deck2);
}

bool compareThree(vector< Card_T<HoldEmRank, Suit> > deck1, vector< Card_T<HoldEmRank, Suit> > deck2) {
    auto rank1 = extract(deck1, THREEOFAKIND), rank2 = extract(deck2, THREEOFAKIND);
    if (rank1 == rank2) return compareHigh(deck1, deck2);
    return rank1 < rank2;
}

bool compareFull(vector< Card_T<HoldEmRank, Suit> > deck1, vector< Card_T<HoldEmRank, Suit> > deck2) {
    auto threeRank1 = extract(deck1, THREEOFAKIND), threeRank2 = extract(deck2, THREEOFAKIND);
    auto pairRank1 = extract(deck1, PAIR), pairRank2 = extract(deck2, PAIR);
    if (threeRank1 != threeRank2) return threeRank1 < threeRank2;
    if (pairRank1 != pairRank2) return pairRank1 < pairRank2;
    return false;
}

bool compareFour(vector< Card_T<HoldEmRank, Suit> > deck1, vector< Card_T<HoldEmRank, Suit> > deck2) {
    auto rank1 = extract(deck1, FOUROFAKIND), rank2 = extract(deck2, FOUROFAKIND);
    if (rank1 == rank2) return compareHigh(deck1, deck2);
    return rank1 < rank2;
}


//Iterate through the player's deck, find the [num] cards that has the same rank, 
//erase them from the deck, and then return the card's rank.
//It is caller's responsbility to make sure that the deck has [num] cards with same rank
HoldEmRank extract(vector< Card_T<HoldEmRank, Suit> >& deck, int num) {
    for (vector<Card_T<HoldEmRank, Suit> >::size_type i = deck.size() - num; i < deck.size(); --i) {
        bool sameRank = true;
        for (int j = num - 1; j > 0; --j) {
            if (deck[i].rank != deck[i + j].rank) sameRank = false;
        }
        if (!sameRank) continue;
        
        auto rank = deck[i].rank;
        for (int j = num - 1; j >= 0; --j) {
            deck.erase(deck.begin() + i + j);
        }
        return rank;
    }
    return HoldEmRank::undefined;
}


