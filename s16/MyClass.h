#pragma once
#include <iostream>

using std::string, std::ostream;

class MyClass {
    string s;
    public:
    MyClass(const string &);
    // bool operator< (const MyClass&) const;
    friend bool operator< (const MyClass&, const MyClass&);
    friend ostream& operator<< (ostream&, const MyClass&);
};


bool operator< (const MyClass&, const MyClass&);

ostream& operator<< (ostream&, const MyClass&);

void print (std::ostream&, const std::string&);

void print(std::ostream& os, const char* const);
void print(std::ostream& os, const MyClass&);
void print (std::ostream&);