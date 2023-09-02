#pragma once
#include<iostream>
//The base virtual class
// all decks should support/ overwrite the print function
class Deck{

    virtual void print(std::ostream& os) = 0;//pure virtual function
};