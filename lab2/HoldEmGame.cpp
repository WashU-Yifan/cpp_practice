#include "HoldEmGame.h"

#define CardPerLine 5
#define success 0

using std::cout;
using std::endl;
using std::runtime_error;
using std::cin;
using std::vector;
using std::sort;

HoldEmGame:: HoldEmGame(int argc, const char *argv[]):Game(argc,argv),
GameState(HoldEmState::preflop),PlayerHands(argc,CardSet<HoldEmRank,Suit>()){}

void HoldEmGame::deal(){
    switch(GameState){
        case(HoldEmState::preflop):{
            deal_preflop();
            break;
        }
        case (HoldEmState::flop):{
            deal_flop();
            break;
        }
        case (HoldEmState::turn):{
            deal_turn();
            break;
        }
        case (HoldEmState::river):{
            deal_river();
            break;
        }
        default:
            return;
    }
}


int HoldEmGame::play(){
    while(1){
        Deck.shuffle();
        reset();//reset the HoldEmGame::GameState
        deal();//2cards to each player
        printstatus();//print player's name & hands
        deal();//flop
        deal();//turn
        deal();//river
        vector<PlayerStatus> Players;
        for(int i=0;i<PlayerHands.size();++i){
            Players.push_back(PlayerStatus(PlayerHands[i],PlayerNames[i],HoldEmHandRank::undefined));
            CardSet<HoldEmRank,Suit> flopCopy(Shared);
            flopCopy>>Players[i].PlayerHand>>Players[i].PlayerHand>>Players[i].PlayerHand;
            Players[i].PlayerRank= holdem_hand_evaluation(Players[i].PlayerHand);
        }
        sort(Players.begin(),Players.end());
        for(auto iter=Players.end()-1;iter!=Players.begin()-1;--iter) print_player(*iter);
        Collect_hands();//collect player's cards
        if (end()) return success;

    }
}

//print every player's name and their current hand
void HoldEmGame::printstatus(){

     for(std::vector<CardSet<HoldEmRank,Suit> >::size_type i=0;i<PlayerHands.size();++i){
        cout<<"Player Name: "<<PlayerNames[i]<<"\nHands:"<<endl;
        PlayerHands[i].print(cout,CardPerLine);
    }
}

//take cards from players and the shared deck
void HoldEmGame::Collect_hands(){
    for(auto &hand:PlayerHands)Deck.collect(hand);
    Deck.collect(Shared);
}


//2 cards to each player's hand
void HoldEmGame::deal_preflop(){
    try{
     
        for(auto & playerhand:PlayerHands){
            Deck>>playerhand;
        }
    
        for(auto& playerhand:PlayerHands){
            Deck>>playerhand;
        }
        
        ++GameState;
    }
    catch(runtime_error &e){
        cout<< e.what()<<endl;

    }
}

//3 card to shared
void HoldEmGame::deal_flop(){
    try{
        Deck>>Shared>>Shared>>Shared;
        cout<<"BOARD(flop): ";
        Shared.print(cout,CardPerLine);
        ++GameState;
    }
    catch(runtime_error &e){
        cout<< e.what()<<endl;

    }
}

//1 card to shared
void HoldEmGame:: deal_turn(){
     try{
        Deck>>Shared;
        ++GameState;
        cout<<"BOARD(turn): ";
        Shared.print(cout,CardPerLine);
    }
    catch(runtime_error &e){
        cout<< e.what()<<endl;

    }
}



//1 card to shared deck
void HoldEmGame:: deal_river(){
     try{
        Deck>>Shared;
        ++GameState;
        cout<<"BOARD(river): ";
        Shared.print(cout,CardPerLine);
    }
    catch(runtime_error &e){
        cout<< e.what()<<endl;

    }
}


HoldEmHandRank HoldEmGame::holdem_hand_evaluation(const CardSet<HoldEmRank,Suit>& hand){
    HoldEmHandRank handRank=HoldEmHandRank::undefined;
    CardSet<HoldEmRank,Suit> copy(hand);
    sort(CardSet<HoldEmRank,Suit>::get_cards(copy)->begin(),CardSet<HoldEmRank,Suit>::get_cards(copy)->end(),Compare_Rank<HoldEmRank,Suit>);
    if(CardSet<HoldEmRank,Suit>::get_cards(copy)->size()!=HoldEmHandSize)
        return handRank;
    bool straight=check_straight(CardSet<HoldEmRank,Suit>::get_cards(copy));
    bool flush=check_flush(CardSet<HoldEmRank,Suit>::get_cards(copy));
    if(straight&&flush)
        handRank=HoldEmHandRank::straightflush;
    else if(straight)
        handRank=HoldEmHandRank::straight;
    else if(flush)
        handRank=HoldEmHandRank::flush;
    //the handrank can't be a straight or flush while being a four of a kind, full house,etc.
    if(handRank!=HoldEmHandRank::undefined)
        return handRank;
    return check_same_rank(CardSet<HoldEmRank,Suit>::get_cards(copy));
}



bool check_straight(std::vector<Card_T<HoldEmRank, Suit> >* hand ){
    //hand is already sorted in ascending order
    int previousRank=HoldEmRank_to_val((*hand)[0].rank);
    //edge case 2 3 4 5 A
    //if A is the last element in sorted array and 5 is the second last element, then the first three must be 2,3,4
    //then the cards form a valid straight.
    if((*hand)[HoldEmHandSize-1].rank==HoldEmRank::ace&&(*hand)[HoldEmHandSize-2].rank==HoldEmRank::five){
        return true;
    }
    for(int i=1;i<HoldEmHandSize;++i){
        int curRank=HoldEmRank_to_val((*hand)[i].rank);
        //If there is a gap between two cards' ranks, then the card can not form a straight
        if(curRank-previousRank>1) return false;
        else previousRank=curRank;
    }
    return true;
}


bool check_flush(std::vector<Card_T<HoldEmRank, Suit> >* hand){
    int previousSuit=Suit_to_val((*hand)[0].suit);
    for(int i=1;i<HoldEmHandSize;++i){
        //If any two cards' suits are different, there will not be a flush.
        if(Suit_to_val((*hand)[i].suit)==previousSuit) continue;
        return false;
    }
    return true;

}

HoldEmHandRank check_same_rank(std::vector<Card_T<HoldEmRank, Suit> >* hand ){
    HoldEmHandRank handRank=HoldEmHandRank::xhigh;
    std::pair<int,int> ranknum=get_rank_num(hand);
    if(ranknum.first==Four)
        handRank=HoldEmHandRank::fourofakind;
    else if(ranknum.first==Three){
        if(ranknum.second==Two)
            handRank=HoldEmHandRank::fullhouse;
        else
            handRank=HoldEmHandRank::threeofakind;
    }
    else if(ranknum.first==Two){
        if(ranknum.second==Two)
            handRank=HoldEmHandRank::twopair;
        else
            handRank=HoldEmHandRank::pair;
    }
    return handRank;
}

//return the number of cards with same rank in descending order.
//Will only return two cards that appear the most
std::pair<int,int>get_rank_num(std::vector<Card_T<HoldEmRank, Suit> >* hand){
    std::pair<int,int> ranknum={0,0};
    //declare a vector large enough to store every rank
    std::vector<int> rankbucket(HoldEmRank_to_val(HoldEmRank::ace)+1);
    std::priority_queue<int> sortranknum;
    for(auto card:*hand){
        ++rankbucket[HoldEmRank_to_val((card.rank))];
    }
    for(int rank:rankbucket)
        sortranknum.push(rank);
    ranknum.first=sortranknum.top();
    sortranknum.pop();
    ranknum.second=sortranknum.top();
    return ranknum;
}

void operator++(HoldEmState& state){
    switch (state){
        case(HoldEmState::preflop):{state=HoldEmState::flop;return;}
        case (HoldEmState::flop):{state=HoldEmState::turn;return;}   
        case (HoldEmState::turn):{state=HoldEmState::river;return;}
        case (HoldEmState::river):{state=HoldEmState::undefined;return;}
        default:{state=HoldEmState::undefined;;return;}
    }
}


void HoldEmGame::reset(){
    GameState=HoldEmState::preflop;
}

std::ostream& operator<<(std::ostream& os,const HoldEmHandRank& Hrank){
     switch (Hrank){
        case(HoldEmHandRank::xhigh):{os<<"xhigh";return os;}
        case (HoldEmHandRank::pair):{os<<"pair";return os;}
        case (HoldEmHandRank::twopair):{os<<"twopair";return os;}
        case (HoldEmHandRank::threeofakind):{os<<"threeofakind";return os;}
        case (HoldEmHandRank::straight):{os<<"straight";return os;}
        case (HoldEmHandRank::flush):{os<<"flush";return os;}
        case (HoldEmHandRank::fullhouse):{os<<"fullhouse";return os;}
        case (HoldEmHandRank::fourofakind):{os<<"fourofakind";return os;}
        case (HoldEmHandRank::straightflush):{os<<"straightflush";return os;}
        default:{os<<"undefined";return os;}
    }
}

bool operator<(const HoldEmGame::PlayerStatus& PS1,const HoldEmGame::PlayerStatus& PS2){
    if(PS1.PlayerRank < PS2.PlayerRank) return true;
    else if(PS2.PlayerRank < PS1.PlayerRank) return false;
    else{
        CardSet<HoldEmRank,Suit> copy1(PS1.PlayerHand),copy2(PS2.PlayerHand);
        sort(CardSet<HoldEmRank,Suit>::get_cards(copy1)->begin(),CardSet<HoldEmRank,Suit>::get_cards(copy1)->end(),Compare_Rank<HoldEmRank,Suit>);
        sort(CardSet<HoldEmRank,Suit>::get_cards(copy2)->begin(),CardSet<HoldEmRank,Suit>::get_cards(copy2)->end(),Compare_Rank<HoldEmRank,Suit>);
        switch(PS1.PlayerRank){
            case(HoldEmHandRank::xhigh):
            case (HoldEmHandRank::flush):{return high_compare(*CardSet<HoldEmRank,Suit>::get_cards(copy1),*CardSet<HoldEmRank,Suit>::get_cards(copy2));}
            case (HoldEmHandRank::pair):{return pair_compare(*CardSet<HoldEmRank,Suit>::get_cards(copy1),*CardSet<HoldEmRank,Suit>::get_cards(copy2));}
            case (HoldEmHandRank::twopair):{return two_pair_compare(*CardSet<HoldEmRank,Suit>::get_cards(copy1),*CardSet<HoldEmRank,Suit>::get_cards(copy2));}
            case (HoldEmHandRank::threeofakind):{return three_compare(*CardSet<HoldEmRank,Suit>::get_cards(copy1),*CardSet<HoldEmRank,Suit>::get_cards(copy2));}
            case (HoldEmHandRank::fullhouse):{return full_compare(*CardSet<HoldEmRank,Suit>::get_cards(copy1),*CardSet<HoldEmRank,Suit>::get_cards(copy2));}
            case (HoldEmHandRank::fourofakind):{return four_compare(*CardSet<HoldEmRank,Suit>::get_cards(copy1),*CardSet<HoldEmRank,Suit>::get_cards(copy2));}
            case (HoldEmHandRank::straight):
            case (HoldEmHandRank::straightflush):{return straight_compare(*CardSet<HoldEmRank,Suit>::get_cards(copy1),*CardSet<HoldEmRank,Suit>::get_cards(copy2));}
            default:{return false;}
        }
    }
}


unsigned int Hand_rank_to_val(const HoldEmHandRank& Hrank){
    switch (Hrank){
        case(HoldEmHandRank::xhigh):{return 1;}
        case (HoldEmHandRank::pair):{return 2;}
        case (HoldEmHandRank::twopair):{return 3;}
        case (HoldEmHandRank::threeofakind):{return 4;}
        case (HoldEmHandRank::straight):{return 5;}
        case (HoldEmHandRank::flush):{return 6;}
        case (HoldEmHandRank::fullhouse):{return 7;}
        case (HoldEmHandRank::fourofakind):{return 8;}
        case (HoldEmHandRank::straightflush):{return 9;}
        default:{return 0;}
    }
}
bool operator<(HoldEmHandRank& r1, HoldEmHandRank&r2){
    return Hand_rank_to_val(r1)<Hand_rank_to_val(r2);
}




//v1 and v2 are already sorted
bool straight_compare( vector<Card_T<HoldEmRank, Suit> >& v1,vector<Card_T<HoldEmRank, Suit> >& v2){
    Card_T<HoldEmRank, Suit> c1=(*v1.begin()).rank==HoldEmRank::two?*(v1.end()-2):*(v1.end()-1);
    Card_T<HoldEmRank, Suit> c2=(*v2.begin()).rank==HoldEmRank::two?*(v2.end()-2):*(v2.end()-1);
    return Compare_Rank <HoldEmRank,Suit>(c1,c2);
}
bool pair_compare(vector<Card_T<HoldEmRank, Suit> >& v1,vector<Card_T<HoldEmRank, Suit> >&v2){
    int v1_pair=extract_pair(v1),v2_pair=extract_pair(v2);
    if(v1_pair<v2_pair)return true;
    else if(v2_pair<v1_pair) return false;
    else{
        for(int i=2;i>=0;--i) {
            if( v1[i].rank < v2[i].rank) return true;
            else if( v2[i].rank < v1[i].rank) return false;
        }

    }
    return false;
}

int extract_pair(vector<Card_T<HoldEmRank, Suit> >& v){
    int rankval=0;
    for(int i=1;i<v.size();++i){
        if(v[i].rank==v[i-1].rank) {
            rankval= HoldEmRank_to_val( v[i].rank);
            v.erase(v.begin()+i);
            v.erase(v.begin()+i-1);
            return rankval;
        }
    }
    return rankval;
}
bool two_pair_compare( vector<Card_T<HoldEmRank, Suit> >&v1,vector<Card_T<HoldEmRank, Suit> >&v2){
    int v1_pair1=extract_pair(v1),v2_pair1=extract_pair(v2);//smaller pair
    int v1_pair2=extract_pair(v1),v2_pair2=extract_pair(v2);//larger pair
    if(v1_pair2<v2_pair2) return true;
    else if(v2_pair2<v1_pair2) return false;
    else {
        if(v1_pair1<v2_pair1)return true;
        else if(v2_pair1<v1_pair1) return false;
        else{
            if( (*v1.begin()).rank < (*v2.begin()).rank) return true;
            else if( (*v2.begin()).rank < (*v1.begin()).rank) return false;
        }
    }
    return false;
}

bool three_compare( vector<Card_T<HoldEmRank, Suit> >&v1,vector<Card_T<HoldEmRank, Suit> >&v2){
    int v1_three=extract_three(v1),v2_three=extract_three(v2);
    if(v1_three<v2_three) return true;
    else if(v2_three<v1_three) return false;
    else return false;
}

int extract_three(vector<Card_T<HoldEmRank, Suit> >& v){
    int rankval=0;
    for(int i=2;i<v.size();++i){
        if(v[i].rank==v[i-1].rank&&v[i].rank==v[i-2].rank) {
            rankval= HoldEmRank_to_val( v[i].rank);
            v.erase(v.begin()+i);
            v.erase(v.begin()+i-1);
            v.erase(v.begin()+i-2);
            return rankval;
        }
    }
    return rankval;
}


bool full_compare(vector<Card_T<HoldEmRank, Suit> >&v1,vector<Card_T<HoldEmRank, Suit> >&v2){
    int v1_three=extract_three(v1),v2_three=extract_three(v2);
    if(v1_three<v2_three) return true;
    else if(v2_three<v1_three) return false;
    return false;
}

//compare the player hand if they both hold four of a kind
bool four_compare(vector<Card_T<HoldEmRank, Suit> >&v1,vector<Card_T<HoldEmRank, Suit> >&v2){
    int v1_four= extract_four(v1),v2_four= extract_four(v2);
    if(v1_four<v2_four) return true;
    else if(v2_four<v1_four) return false;
    return false;
}

//extract four cards with same rank and return the rank value
int extract_four(vector<Card_T<HoldEmRank, Suit> >& v){
    int rankval= v[0].rank==v[1].rank?HoldEmRank_to_val( v[0].rank):HoldEmRank_to_val( v[1].rank);
    v.erase(v.begin()+1);//remove second
    v.erase(v.begin()+1);//remove third
    v.erase(v.begin()+1);//remove fourth
    if(v[0].rank==v[1].rank) v.erase(v.begin());//remove first
    else v.erase(v.begin()+1);//remove last
    return rankval;
}


bool high_compare(vector<Card_T<HoldEmRank, Suit> >&v1,vector<Card_T<HoldEmRank, Suit> >&v2){
    for(int i=4;i>=0;--i) {
        if( v1[i].rank < v2[i].rank) return true;
        else if( v2[i].rank < v1[i].rank) return false;
    }
    return false;
}
ostream& operator<<(ostream& os,HoldEmGame::PlayerStatus& player){
    os<<"Player Name: "<<player.PlayerName<<endl;
    os<<"Player's card set:"<<endl;
    player.PlayerHand.print(os,HoldEmHandSize);
    os<<"Rank: "<<player.PlayerRank<<endl;
    return os;

}