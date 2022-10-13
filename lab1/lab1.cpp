

#include "HoldEmGame.h"
#include "PinochleGame.h"
#include<memory>
#include <iostream>
#include <cstdint>
#include <cstring>
using namespace std;
#define SUCCESS 0
#define invalid_command 1
#define start_index 2//player's name start at index 2
#define game_index 1//argv[1] speficies which game to run
#define pino_count 4
#define holdem_count_min 2
#define holdem_count_max 9
using std::shared_ptr;
using std::make_shared;
enum class GameType{
    Pinochle,
    HoldEm,
    undefined    
};
void process_input(int &argc, const char **&argv);
shared_ptr<Game> create(int arc, const char * argv[]);
GameType check_game(const char* game);
void user_message();


int main(int argc, const char *argv[]){
    shared_ptr<Game> game=create(argc,argv);
    if(game.get()==nullptr){user_message();return invalid_command;}
    game->play();
    return SUCCESS;
}



void process_input(int &argc, const char **&argv){
    argc-=start_index;
    argv+=start_index;
}

shared_ptr<Game> create(int argc, const char * argv[]){
    shared_ptr<Game> Game_ptr;
    GameType gametype=check_game(argv[game_index]);
    cout<<"game type: "<<argv[game_index]<<endl;
    process_input(argc,argv);
    cout<<"argc: "<<argc<<endl;
    cout<<"argv: "<<argv[0]<<argv[1]<<argv[2]<<argv[3]<<endl;
    switch(gametype){
        case(GameType::Pinochle): {
            if(argc==pino_count){
                cout<<"pino game++++++++++"<<endl;
                Game_ptr=make_shared<PinochleGame>(argc,argv);
            }
            
            break;
        }
        case (GameType::HoldEm):{
            if(argc>=holdem_count_min&& argc<=holdem_count_max){
                cout<<"Holdem game ++++++++++++"<<endl;
                Game_ptr=make_shared<HoldEmGame>(argc,argv);
            }
            break;
        }
        default:{
            Game_ptr=nullptr;
        }
    }

    return Game_ptr;
}

GameType check_game(const char* game ){
    if (game=="Pinochle") return GameType::Pinochle;
    else if (game=="HoldEm") return GameType::HoldEm;
    else return GameType::undefined;
}



void user_message(){
    cout<<"usage: ./lab1 Pinochle p1 p2 p3 p4\n"<<
    "or \nusage: ./lab1 HoldEm p1 p2 [p3...p9]"<<endl;
}