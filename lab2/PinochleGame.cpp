#include "PinochleGame.h"
#define CardPerLine 6
#define success 0
using std::cout;
using std::endl;
using std::runtime_error;
using std::vector;


PinochleGame::PinochleGame(int argc, const char* argv[]):Game(argc,argv),PlayerHands(argc,CardSet<PinochleRank,Suit>()){}

//distribute 3 cards to each player and repeat until there is no cards in Deck.
void PinochleGame::deal(){
    while(!SharedDeck.is_empty()){
        for(auto &playerdeck:PlayerHands){
            try{
                SharedDeck>>playerdeck>>playerdeck>>playerdeck;
            }
            catch(runtime_error &e){
                cout<<e.what()<<"SharedDeck is empty"<<endl;
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

        SharedDeck.shuffle();
        deal();
        print_status();
        for(auto & hands:PlayerHands)
            SharedDeck.collect(hands);
       if (end()) return success;
    }
}

void PinochleGame::print_melds(const std::vector<PinochleMelds>& melds){
    cout<<"Melds:"<<endl;

    for (PinochleMelds meld:melds){
        cout<<std::left<<meld<<std::right<<endl;
    }

}

//helper function that print player's name and their cards
void PinochleGame::print_status(){
    vector<PinochleMelds>melds;
    for(std::vector<CardSet<PinochleRank,Suit> >::size_type i=0;i<PlayerHands.size();++i){
        cout<<"Player Name: "<<PlayerNames[i]<<"\nHands:"<<endl;
        PlayerHands[i].print(cout,CardPerLine);
        suit_independent_evaluation(PlayerHands[i],melds);
        //sort the melds in descending order
        sort(melds.begin(),melds.end(),[](PinochleMelds& a, PinochleMelds& b){return a>b;});
        print_melds(melds);
        melds.clear();
    }
}



void PinochleGame::suit_independent_evaluation(const CardSet<PinochleRank,Suit>& card,
std::vector<PinochleMelds>& MeldsV){
    CardSet<PinochleRank,Suit> copy(card);
    //sort the player's hands by the rank first
    sort(CardSet<PinochleRank,Suit>::get_cards(copy)->begin(),CardSet<PinochleRank,Suit>::get_cards(copy)->end(),
         Compare_Rank<PinochleRank,Suit>);

    check_same_rank(CardSet<PinochleRank,Suit>::get_cards(copy),MeldsV);
    check_Pino(CardSet<PinochleRank,Suit>::get_cards(copy),MeldsV);
}   

//this function is responsible for checking 8 cards with same Rank and 4 cards with 
//same Rank but different Suit.
void check_same_rank(std::vector<Card_T<PinochleRank,Suit> >* hands,
std::vector<PinochleMelds>& MeldsV){

    int cur_cnt=0;
    PinochleRank cur_rank=PinochleRank::nine;
    std::unordered_set<Suit> suit;
    for(auto &card: *hands){
        if(card.Crank!=cur_rank){//if we have iterated through one specific rank
            //either 8 cards with same rank
            if(cur_cnt==thousands)add_eight(MeldsV,cur_rank);
            //or 4 cards with same ranks but different suit
            else if(suit.size()==hundreds)add_four(MeldsV,cur_rank);
            cur_cnt=0;
            suit.clear();
            cur_rank=card.Crank;
        }
        else{
            cur_cnt++;
            suit.insert(card.Csuit);
        }
    }
    if(cur_cnt==thousands) add_eight(MeldsV,cur_rank);
    else if(suit.size()==hundreds) add_four(MeldsV,cur_rank);
    
}
//add to the melds when there are 8 cards with same rank
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
//or 4 cards with same ranks but different suit
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
    int j_count=0,q_count=0;//j_count records number of J diamonds, q_count records number of Q spades
    for(auto & card:*cards){
        if(card.Crank==PinochleRank::jack&&card.Csuit==Suit::diamonds)++j_count;
        else if(card.Crank==PinochleRank::queen&&card.Csuit==Suit::spades)++q_count;
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
    os<<std::setw(longest_meld_name)<<PinochleGame::PinochleNames[index]
    <<": "<<std::setw(largest_meld_point)<<PinochleGame::PinochlePoints[index];
    return os;
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