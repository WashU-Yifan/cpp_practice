#include "GoFishGame.h"
#include <algorithm>
#include <map>
using std::cout, std::endl;

template
<typename R, typename S, typename Deck>
GoFishGame<R, S, Deck>::GoFishGame(int numPlayers, const char** playerNames): Game(numPlayers, playerNames) {
    //Go Fish works with any deck that has at least 4 of each type of card. Before we use an arbitrary deck, we must check that is is valid. The body of the constructor should check that there are at least 4 cards of each rank in the deck, and if not it should throw an exception.
    throw std::invalid_argument("Invalid deck: should use the specialized version");
}

//Full specialization of the GofishGame/
template<>
GoFishGame<HoldEmRank, Suit, HoldEm>::GoFishGame(int numPlayers, const char** playerNames):
    Game(numPlayers, playerNames), 
    deck(HoldEm()), 
    playersHand(numPlayers),
    playersBook(numPlayers) {
    //Go Fish works with any deck that has at least 4 of each type of card. Before we use an arbitrary deck, we must check that is is valid. The body of the constructor should check that there are at least 4 cards of each rank in the deck, and if not it should throw an exception.
    if (!deckCheck()) {
        throw std::invalid_argument("Invalid deck: less than 4 cards of each rank");
    }
}

template<>
GoFishGame<PinochleRank, Suit, Pinochle>::GoFishGame(int numPlayers, const char** playerNames):  
    Game(numPlayers, playerNames), 
    deck(Pinochle()), 
    playersHand(numPlayers),
    playersBook(numPlayers)  {
    //Go Fish works with any deck that has at least 4 of each type of card. Before we use an arbitrary deck, we must check that is is valid. The body of the constructor should check that there are at least 4 cards of each rank in the deck, and if not it should throw an exception.
    if (!deckCheck()) {
        throw std::invalid_argument("Invalid deck: less than 4 cards of each rank");
    }
}

template<>
GoFishGame<UnoRank, Color, Uno>::GoFishGame(int numPlayers, const char** playerNames): 
    Game(numPlayers, playerNames), 
    deck(Uno()), 
    playersHand(numPlayers),
    playersBook(numPlayers) {
    //Go Fish works with any deck that has at least 4 of each type of card. Before we use an arbitrary deck, we must check that is is valid. The body of the constructor should check that there are at least 4 cards of each rank in the deck, and if not it should throw an exception.
    if (!deckCheck()) {
        throw std::invalid_argument("Invalid deck: less than 4 cards of each rank");
    }
}



template
<typename R, typename S, typename Deck>
bool GoFishGame<R, S, Deck>::collectBooks(int player) {
    for (auto iter = playersHand[player].getDeckBegin(); iter != playersHand[player].getDeckEnd(); ++iter) {
        R targetRank = (*iter).rank;
        std::function<bool(Card_T<R, S>&)> predicate = [targetRank](Card_T<R, S>& card) {
            return card.rank == targetRank;
        };
        if (count_if(playersHand[player].getDeckBegin(), playersHand[player].getDeckEnd(), predicate) == BOOK) {
            playersBook[player].collectIf(playersHand[player], predicate);
            return true;
        }
    }
    return false;
}

template
<typename R, typename S, typename Deck>
void GoFishGame<R, S, Deck>::printPlayers() {
    for (long unsigned int i = 0; i < playersHand.size(); ++i) {
        if(evictedPlayers.find(i) != evictedPlayers.end()) continue;
        printPlayer(i);
    }
}

template
<typename R, typename S, typename Deck>
void GoFishGame<R, S, Deck>:: printPlayer(int i) {
    cout << "Player " << i << "'s hand:" << endl;
    playersHand[i].print(std::cout, BOOK);
    cout << "Player " << i << " has made " << (playersBook[i].isEmpty()? 0 : playersBook[i].getDeckSize() / BOOK) << " books: " << endl;
    playersBook[i].print(std::cout, BOOK);
    cout << endl;
}

template
<typename R, typename S, typename Deck>
bool GoFishGame<R, S, Deck>::turn(int player) {
    if(evictedPlayers.find(player) != evictedPlayers.end()) return false;
    playersHand[player].sort();
    printPlayer(player);
    return requestCard(player);
}



template
<typename R, typename S, typename Deck>
bool GoFishGame<R, S, Deck>::requestCard(int i) {
    long unsigned int player = 0;
    do{ 
        cout << "Give a player's number: ";
        std::cin >> player;
        if(player >= playersBook.size()) {
            cout << "The player you requested from is no longer in game" << endl;
            continue;
        }
        else if(evictedPlayers.find(player) != evictedPlayers.end()) {
            cout << "The player you requested from is no longer in game" << endl;
            continue;
        }
        else if(player == static_cast<long unsigned int>(i)) {
            cout << "Should not request from yourself." << endl;
            continue;
        }
        break;
    } while(1);
    R rank = requestRank();
    
    if (playersHand[i].request(playersHand[player], rank)) {
        cout << "request success" << endl;
        while(collectBooks(i));
        return true;
    }
    else {
        cout << "Go Fish!" << endl;
        if(deck.isEmpty()) {
            deck.collect(playersHand[i]);
            cout << "The player " << i << " is removed from the game" << endl;
            evictedPlayers.insert(i);
            return false;
        }
        else {
            auto card = *(--deck.getDeckEnd());
            deck >> playersHand[i];
            return card.rank == rank;
        }
    }
}

template
<typename R, typename S, typename Deck>
void GoFishGame<R, S, Deck>::deal() {
    long unsigned int handSize = playersHand.size() == PLAYERTHRESHOLD ? TWOPLAYERHAND : MOREPLAYERHAND;
    for (long unsigned int i = 0; i < handSize; ++i) {
        for (long unsigned int j = 0; j < playersHand.size(); ++j) {
            deck >> playersHand[j];
        }
    }
}


template
<typename R, typename S, typename Deck>
int GoFishGame<R, S, Deck>:: play() {

    while(true){
        deal();
        cout << "New Game initiated. Deal complete." << endl;
        while(!terminationCheck()) {
            cout << "Game is not terminated." << endl;
            for (long unsigned int i = 0; i < playersHand.size(); ++i) {
                if (terminationCheck()) break;
                cout << "Player "  << i <<  "'s turn." << endl; 
                if(evictedPlayers.find(i) != evictedPlayers.end()) continue;
                while(turn(i)) {
                    collectBooks(i);
                    if (terminationCheck()) break;
                }
                collectBooks(i);
                playersHand[i].sort();
                printPlayer(i);
            }
            printPlayers();
            cout << "------- ROUND FINISHED --------" << endl;
        }
        int maxBooks = 0, maxBooksPlayer = 0;
        for (long unsigned int i = 0; i < playersHand.size(); ++i) {
            if (playersBook[i].getDeckSize() > maxBooks) {
                maxBooksPlayer = i;
                maxBooks = playersBook[i].getDeckSize();
            }
        }

        cout << "Player " << maxBooksPlayer << " has won the Game" << endl;
        printPlayer(maxBooksPlayer);
        int gameStatus = continueGame();
        if (gameStatus == CONTINUEGAME) {
            continue;
        }
        else {
            return gameStatus;
        }
    }

}

// The game is over when all cards have moved from the deck and 
// the players' hands into the players' collections of books, or 
// when there is one or zero players left in the game. Once the game 
// has finished, it should say which player (or players) has made the most books.
template
<typename R, typename S, typename Deck>
bool GoFishGame<R, S, Deck>::terminationCheck() {
    if (evictedPlayers.size() >= playersHand.size() - 1) {
        return true;
    }
    for (long unsigned int i = 0; i < playersHand.size(); ++i) {
        if (playersHand[i].getDeckSize()) return false;
    }
    return deck.isEmpty();
}

template
<typename R, typename S, typename Deck>
bool GoFishGame<R, S, Deck>::deckCheck() {
    std::map<R, int> rankCounter;
    for (auto iter = deck.getDeckBegin(); iter != deck.getDeckEnd(); ++iter) {
        rankCounter[(*iter).rank]++;
    }
    return !count_if(rankCounter.begin(), rankCounter.end(), 
        [](const std::pair<R, int>& p){return p.second < FOUROFAKIND;});
}

template
<typename R, typename S, typename Deck>
void  GoFishGame<R, S, Deck>::collectHands() {
    for (long unsigned int i = 0; i < playersHand.size(); ++i) {
        deck.collect(playersHand[i]);
        deck.collect(playersBook[i]);
    }
}


template<>
HoldEmRank GoFishGame<HoldEmRank, Suit, HoldEm>::requestRank() {
    static std::map<std::string, HoldEmRank> rankMap = {
        {"two", HoldEmRank::two},
        {"three", HoldEmRank::three},
        {"four", HoldEmRank::four},
        {"five", HoldEmRank::five},
        {"six", HoldEmRank::six},
        {"seven", HoldEmRank::seven},
        {"eight", HoldEmRank::eight},
        {"nine", HoldEmRank::nine},
        {"ten", HoldEmRank::ten},
        {"jack", HoldEmRank::jack},
        {"queen", HoldEmRank::queen},
        {"king", HoldEmRank::king},
        {"ace", HoldEmRank::ace}
    };
    string rank;
    do {
        cout << "Give a card rank from [two] to [ace]: ";
        std:: cin >> rank;
    }while (rankMap.find(rank) == rankMap.end());
    return rankMap[rank];
}

template<>
PinochleRank GoFishGame<PinochleRank, Suit, Pinochle>::requestRank() {
    static std::map<std::string, PinochleRank> rankMap = {
        {"nine", PinochleRank::nine},
        {"jack", PinochleRank::jack},
        {"queen", PinochleRank::queen},
        {"king", PinochleRank::king},
        {"ten", PinochleRank::ten},
        {"ace", PinochleRank::ace}
    };
    string rank;
    do {
        cout << "Give a card rank from [nine] to [ace]: ";
        std:: cin >> rank;
    }while (rankMap.find(rank) == rankMap.end());
    return rankMap[rank];
}

template<>
UnoRank GoFishGame<UnoRank, Color, Uno>::requestRank() {
    static std::map<std::string, UnoRank> rankMap = {
        {"zero", UnoRank::zero},
        {"one", UnoRank::one},
        {"two", UnoRank::two},
        {"three", UnoRank::three},
        {"four", UnoRank::four},
        {"five", UnoRank::five},
        {"six", UnoRank::six},
        {"seven", UnoRank::seven},
        {"eight", UnoRank::eight},
        {"nine", UnoRank::nine},
        {"skip", UnoRank::skip},
        {"reverse", UnoRank::reverse},
        {"drawtwo", UnoRank::drawtwo},
        {"drawfour", UnoRank::drawfour},
        {"wild", UnoRank::wild},
        {"blank", UnoRank::blank}
    };
    string rank;
    do {
        cout << "Give a card rank from [zero] to [blank]: ";
        std:: cin >> rank;
    }while (rankMap.find(rank) == rankMap.end());
    return rankMap[rank];
}