#pragma once

#include <iostream>
using std::ostream;

template <typename T = int>
class MyStruct {
    T a;

public:
    MyStruct(T _a) : a(_a) {}

    // MyStruct(const MyStruct &) = delete;
    //MyStruct operator= (const MyStruct &) = delete;
    //~MyStruct() = delete;


    template <typename F>
    friend ostream& operator<< (ostream& os, const MyStruct<F> &t);
};


template <typename T>
ostream& operator<< (ostream& os, const MyStruct<T> &t);

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE /* test whether guard symbol is defined */
#include "s1.cpp"
#endif
