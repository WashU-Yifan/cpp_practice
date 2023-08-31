#include "s1.h"
#include <iostream>
using std::ostream;

// Define the operator<< for MyStruct<int> (specific instantiation)
template <typename T>
ostream& operator<< (ostream& os, const MyStruct<T> &t){
    os << t.a;
    return os;
}

template ostream& operator<< (ostream& os, const MyStruct<int> & t);