#pragma once
#include <vector>
#include <iostream>
#include "Card_T.h"
#include "Deck.h"
using std::ostream;

enum class Color {
    red, 
    blue,
    green,
    yellow,
    black,
    undefined
};

enum class UnoRank {
    zero, 
    one, 
    two, 
    three, 
    four, 
    five, 
    six, 
    seven, 
    eight, 
    nine, 
    skip, 
    reverse, 
    drawtwo, 
    drawfour, 
    wild, 
    blank, 
    undefined
};

class Uno: public Deck<UnoRank,Color> {
    public:
        Uno();

};



ostream& operator<< (ostream&, UnoRank);
ostream& operator<< (ostream&, Color);

UnoRank& operator++(UnoRank&);
UnoRank operator++(UnoRank&, int);

Color& operator++(Color&);
Color operator++(Color&, int);