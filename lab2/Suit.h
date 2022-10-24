#pragma once
#include<iostream>
const int suit_num=4;

// Suits of a card 
// for now there is only one enum class for Suit
enum class Suit{
    clubs,
    diamonds,
    
    hearts,
    spades,
    undefined
};

std::ostream& operator<<(std::ostream& os,const Suit& suit);
void operator++(Suit& suit);

unsigned int Suit_to_val(Suit);
bool operator<(const Suit&,const Suit&);