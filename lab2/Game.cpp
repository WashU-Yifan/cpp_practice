#include "Game.h"
#include<iostream>
using std::cout;
using std::endl;
using std::cin;


//Argc and argv are preprocessed to contain only players' names.
Game::Game(int argc,const char *argv[]):PlayerNames(argv,argv+argc){}


//prompt the user to end or continue
bool Game::end(){
    std::string stop;
    cout<<"Do you want to end this Pinpchle Game? (Yes/NO)"<<endl;
    cin>>stop;
    if(stop=="yes") return true;
    return false;
}