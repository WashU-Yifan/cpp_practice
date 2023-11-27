
#include "Deck/PinochleDeck.h"
#include "Deck/HoldEmDeck.h"
#include "Deck/UnoDeck.h"

#include "Game/HoldEmGame.h"
#include "Game/PinochleGame.h"
#include "Game/GoFishGame.h"

#include <memory>
#include <cstring>
using namespace std;
const int SUCCESS = 0, INCORRECTARGUMENT = 1, GAMEFAIL = 2;
const int GAMENAME = 1, DECKNAME = 2;
const char* PINOCHLE = "Pinochle";
const char* HOLDEM = "HoldEm";
const char* GOFISH = "GoFish";
const char* UNO = "Uno";
const int GAMEOFFSET = 2, GOFISHGAMEOFFSET = 3;
const int PINOCHLEARGC = 6, HOLDEMARGCMIN = 4, HOLDEMARGCMAX = 11, GOFISHARGCMIN = 5, GOFISHARGCMAX = 8;

shared_ptr<Game> create(int argc, const char ** argv);
bool argumentCheck(int argc, const char ** argv);
void usage();
int main(int argc, const char** argv){

    if (!argumentCheck(argc, argv)) {
        usage();
        return INCORRECTARGUMENT;
    }
    auto game = create(argc, argv);
    if (!game) {
        cout << "create game failed" << endl;
        return GAMEFAIL;
    }
    try {
        return game->play();
    }
    catch (std::runtime_error  &e) {
        cout << e.what() << endl;
        return GAMEFAIL;
    }
}


shared_ptr<Game> create(int argc, const char ** argv) {
    shared_ptr<Game> game;
    if(!strcmp(argv[GAMENAME], PINOCHLE)) {
        game = make_shared<PinochleGame>(argc - GAMEOFFSET, argv + GAMEOFFSET);
    }
    else if (!strcmp(argv[GAMENAME], HOLDEM)) {
        game = make_shared<HoldEmGame>(argc - GAMEOFFSET, argv + GAMEOFFSET);
    }
    else if (!strcmp(argv[GAMENAME], GOFISH)) {
        try {
            if (!strcmp(argv[DECKNAME], PINOCHLE)) {
                game = make_shared<GoFishGame<PinochleRank, Suit, Pinochle> >(argc - GOFISHGAMEOFFSET, argv + GOFISHGAMEOFFSET);
            }
            else if (!strcmp(argv[DECKNAME], HOLDEM)) {
                game = make_shared<GoFishGame<HoldEmRank, Suit, HoldEm> >(argc - GOFISHGAMEOFFSET, argv + GOFISHGAMEOFFSET);
            }
            else if (!strcmp(argv[DECKNAME], UNO)) {
                game = make_shared<GoFishGame<UnoRank, Color, Uno> >(argc - GOFISHGAMEOFFSET, argv + GOFISHGAMEOFFSET);
            }
        }
        catch (std::invalid_argument& e) {
            cout << e.what() << endl;
        }
    }

    return game;
}

bool argumentCheck(int argc, const char ** argv) {
    if (argc < GAMEOFFSET) {
        return false;
    }
    if(!strcmp(argv[GAMENAME], PINOCHLE)) {
        return argc == PINOCHLEARGC;
    }
    else if (!strcmp(argv[GAMENAME],HOLDEM)) {
        return argc >= HOLDEMARGCMIN && argc <= HOLDEMARGCMAX;
    }
    else if (!strcmp(argv[GAMENAME],GOFISH)) {
        return argc >= GOFISHARGCMIN && argc <= GOFISHARGCMAX;
    }
    else {
        return false;
    }
}

void usage() {
    cout << "Usage: lab3 [Pinochle|HoldEm|GoFish] [player1 player2 player3 player4|[HoldEm|Pinochle|Uno player1 player2]]..." << endl;
    cout << "   - If Pinochle is chosen, you must provide 4 extra arguments." << endl;
    cout << "   - If HoldEm is chosen, you can provide between 2 and 9 extra arguments." << endl;
    cout << "   - If GoFish is chosen, you can provide a deck name and then followed by 2 to 5 extra arguments." << endl;
}