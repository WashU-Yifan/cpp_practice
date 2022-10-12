#include "CardSet.h"
#include<iostream>
using std::ostream;
using std::size_t;
using std::cout;
using std::endl;
void CardSet::print(std::ostream& os,std::size_t size){
    size_t cnt=0;
    for(auto card:cardset){
        os<<card<<" ";
        if(++cnt==size){
            cnt=0;
            os<<endl;
        }
    }
}