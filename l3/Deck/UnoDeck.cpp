#include "UnoDeck.h"

std::ostream& operator<<(std::ostream& os, UnoRank rank) {
    static const char* rankNames[] = {"zero", "one", "two", "three", "four", 
                                    "five", "six", "seven", "eight", "nine", 
                                    "skip", "reverse", "drawtwo", "drawfour",
                                    "wild", "blank", "undefined"};
    return os << rankNames[static_cast<int>(rank)];
}

std::ostream& operator<<(std::ostream& os, Color color) {
    static const char* colorNames[] = {"red", "blue", "green", "yellow", "black", "undefined"};
    return os << colorNames[static_cast<int>(color)];
}

UnoRank& operator++(UnoRank& rank) {
    rank = (rank == UnoRank::undefined) ? rank : static_cast<UnoRank>(static_cast<int>(rank) + 1);
    return rank;
}

UnoRank operator++(UnoRank& rank, int) {
    UnoRank temp = rank;
    ++rank;
    return temp;
}

Color& operator++(Color& color) {
    color = (color == Color::undefined) ? color : static_cast<Color>(static_cast<int>(color) + 1);
    return color;
}

Color operator++(Color& color, int) {
    Color temp = color;
    ++color;
    return temp;
}


Uno::Uno(){
    Color color = Color::red;
    UnoRank rank = UnoRank::zero;
    //one red, one blue, one green, and one yellow card of rank zero;
    for (Color colorTemp = color; colorTemp != Color::undefined; ++colorTemp) {
        this->deck.push_back(Card_T(rank, colorTemp));
    }
    ++rank;
    //two red, two blue, two green, and two yellow cards of each rank one through drawtwo
    for (; rank <= UnoRank::drawtwo; ++rank) {
        for (Color colorTemp = color; colorTemp != Color::undefined; ++colorTemp) {
            this->deck.push_back(Card_T(rank, colorTemp));
            this->deck.push_back(Card_T(rank, colorTemp));
        }
    }
    color = Color::black;
    //four black cards of each rank drawfour through blank
    for (; rank < UnoRank::undefined; ++rank) {
        this->deck.push_back(Card_T(rank, color));
        this->deck.push_back(Card_T(rank, color));
        this->deck.push_back(Card_T(rank, color));
        this->deck.push_back(Card_T(rank, color));
    }
}


