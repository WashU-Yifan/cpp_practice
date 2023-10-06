#pragma once
#include<iostream>
const int SUITNUM = 5;
const int CLUBBIT = 1, DIAMONDSBIT = 2, HEARTSBIT = 4, SPADESBIT = 8;
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