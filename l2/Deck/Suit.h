#pragma once
#include<iostream>
const int suitNum = 4;

// Suits of a card 
// for now there is only one enum class for Suit
enum class Suit {
    clubs,
    diamonds,
    hearts,
    spades,
    undefined
};

std::ostream& operator<<(std::ostream& os, const Suit& suit);
Suit& operator++(Suit& suit);