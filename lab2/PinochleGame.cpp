#include "PinochleGame.h"
#define CardPerLine 6
#define success 0
using std::cout;
using std::endl;
using std::runtime_error;



PinochleGame::PinochleGame(int argc, const char* argv[]):Game(argc,argv),PlayerHands(argc,CardSet<PinochleRank,Suit>()){}

//distribute 3 cards to each player and repeat until there is no cards in Deck.
void PinochleGame::deal(){
    while(!Deck.is_empty()){
        for(auto &playerdeck:PlayerHands){
            try{
                Deck>>playerdeck>>playerdeck>>playerdeck;
            }
            catch(runtime_error &e){
                cout<<e.what()<<"Deck is empty"<<endl;
                return;
            }
        }
    }
    
}

/*
    1 shuffle the deck
    2 distribute the card
    3 print player's name and their cards
    4 collect player's card
    5 continue to 1 or stop
*/
int PinochleGame::play(){
    while(1){
        Deck.shuffle();
        deal();
        printstatus();
       if (end()) return success;
    }
}

//helper function that print player's naem and their cards
void PinochleGame::printstatus(){
 
    for(std::vector<CardSet<PinochleRank,Suit> >::size_type i=0;i<PlayerHands.size();++i){
        cout<<"Player Name: "<<PlayerNames[i]<<"\nHands:"<<endl;
        PlayerHands[i].print(cout,CardPerLine);
        Deck.collect(PlayerHands[i]);
    }
}



void PinochleGame::suit_idependent_evaluation(const CardSet<PinochleRank,Suit>& card,
std::vector<PinochleMelds>& MeldsV){
    CardSet<PinochleRank,Suit> copy(card);
    //sort the player's hands by the rank first
    sort(copy.get_cards()->begin(),copy.get_cards()->end(),Compare_Rank<PinochleRank,Suit>);
    check_TH(copy.get_cards(),MeldsV);
    check_Pino(copy.get_cards(),MeldsV);
}   

//this function is responsible for checking 8 cards with same Rank and 4 cards with 
//same Rank but different Suit.
void check_TH(std::vector<Card_T<PinochleRank,Suit> >* hands, 
std::vector<PinochleMelds>& MeldsV){

    int cur_cnt=0;
    PinochleRank cur_rank=PinochleRank::nine;
    std::unordered_set<Suit> suit;
    for(auto &card: *hands){
        if(card.rank!=cur_rank){//if we have iterate through one specific rank
            if(cur_cnt==thousands)add_eight(MeldsV,cur_rank);
            else if(suit.size()==hundreds)add_four(MeldsV,cur_rank);    
            cur_cnt=0;
            suit.clear();
            ++cur_rank;
        }
        else{
            cur_cnt++;
            suit.insert(card.suit);
        }
    }
    if(cur_cnt==thousands) add_eight(MeldsV,cur_rank);
    else if(suit.size()==hundreds) add_four(MeldsV,cur_rank);
    
}

void add_eight(std::vector<PinochleMelds>& Mields,PinochleRank prank){
     switch (prank){
        case PinochleRank::nine: return;
        case PinochleRank::jack:{Mields.push_back(PinochleMelds::fourhundredjacks); return;}
        case PinochleRank::queen:{Mields.push_back(PinochleMelds::sixhundredqueens); return;}
        case PinochleRank::king:{Mields.push_back(PinochleMelds::eighthundredkings); return;}
        case PinochleRank::ten:return;
        case PinochleRank::ace:{Mields.push_back(PinochleMelds::thousandaces); return;}
        default: return;
    }
}
void add_four(std::vector<PinochleMelds>& Mields ,PinochleRank prank){
    switch (prank){
        case PinochleRank::nine: return;
        case PinochleRank::jack:{Mields.push_back(PinochleMelds::fortyjacks); return;}
        case PinochleRank::queen:{Mields.push_back(PinochleMelds::sixtyqueens); return;}
        case PinochleRank::king:{Mields.push_back(PinochleMelds::eightykings); return;}
        case PinochleRank::ten:return;
        case PinochleRank::ace:{Mields.push_back(PinochleMelds::hundredaces); return;}
        default: return;
    }

}


//This function helps check Pinocle or Double Pinocle
void check_Pino(std::vector<Card_T<PinochleRank,Suit> >*cards ,std::vector<PinochleMelds>& Mields){
    int j_count=0,q_count=0;
    for(auto & card:*cards){
        if(card.rank==PinochleRank::jack&&card.suit==Suit::diamonds)++j_count;
        else if(card.rank==PinochleRank::queen&&card.suit==Suit::spades)++q_count;
    }
    if(j_count==q_count&&j_count==2) Mields.push_back(PinochleMelds::doublepinochle);
    else if(j_count>=1&&q_count>=1) Mields.push_back(PinochleMelds::pinochle);
}









//corresponding points for each PinochleMelds label
std::vector<unsigned int> PinochleGame::PinochlePoints={
    10,20,40,40,40,60,60,80,100,150,300,400,600,800,1000,1500};

std::vector<std::string> PinochleGame::PinochleNames={
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
    "insuitdoublerun"};

std::ostream& operator<<(std::ostream& os, const PinochleMelds& PM){
    int index=to_PinochlePoints_index(PM);
    os<<PinochleGame::PinochleNames[index]<<PinochleGame::PinochlePoints[index];

}





int to_PinochlePoints_index(const PinochleMelds& PM){
    
    switch (PM){
        case PinochleMelds::dix: return 0;
        case PinochleMelds::offsuitmarriage:return 1;
        case PinochleMelds::fortyjacks:return 2;
        case PinochleMelds::pinochle:return 3;
        case PinochleMelds::insuitmarriage:return 4;
        case PinochleMelds::sixtyqueens:return 5; 
        case PinochleMelds::eightykings:return 6; 
        case PinochleMelds::hundredaces:return 7; 
        case PinochleMelds::insuitrun:return 8; 
        case PinochleMelds::doublepinochle:return 9; 
        case PinochleMelds::fourhundredjacks:return 10; 
        case PinochleMelds::sixhundredqueens:return 11; 
        case PinochleMelds::eighthundredkings:return 12; 
        case PinochleMelds::thousandaces:return 13; 
        case PinochleMelds::insuitdoublerun:return 14;
        default: return -1;
    }
}