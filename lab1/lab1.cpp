

#include "HoldEmGame.h"
#include "PinochleGame.h"
#include<memory>
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
const char** process_input(int &argc, const char *argv[]);
shared_ptr<Game> create(int arc, const char * argv[]);
GameType check_game(const char* game);
void user_message();


int main(int argc, const char *argv[]){
    shared_ptr<Game> game=create(argc,argv);
    if(game.get()==nullptr){user_message();return invalid_command;}
    game->play();
    return SUCCESS;
}




const char ** process_input(int &argc, const char *argv[]){
    argc-=start_index;
    const char *name[sizeof(argv)-start_index];
    memcpy(name,argv,sizeof (name));
    return name;
}

shared_ptr<Game> create(int argc, const char * argv[]){
    shared_ptr<Game> Game_ptr;
    GameType gametype=check_game(argv[game_index]);
    const char **names=process_input(argc,argv);
    switch(gametype){
        case(GameType::Pinochle): {
            if(argc==pino_count)
                Game_ptr=make_shared<PinochleGame>(argc,names);
            
            break;
        }
        case (GameType::HoldEm):{
            if(argc>=holdem_count_min&& argc<=holdem_count_max)
                Game_ptr=make_shared<HoldEmGame>(argc,names);
            break;
        }
        default:
            Game_ptr=nullptr;
    }

    return Game_ptr;
}

GameType check_game(const char* game ){
    if (game=="Pinochle") return GameType::Pinochle;
    if (game=="HoldEm") return GameType::HoldEm;
    return GameType::undefined;
}



void user_message(){
    cout<<"usage: ./lab1 Pinochle p1 p2 p3 p4\n";
    cout<<"or \nusage: ./lab1 HoldEm p1 p2 [p3...p9]"<<endl;
}