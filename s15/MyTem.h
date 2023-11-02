#include <iostream>

#pragma once
using std::ostream;

template <typename T>
void print (ostream& , const T&);

template <typename T, typename... Args>
void print (ostream& , const T&, const Args&...);

template <typename... Args>
void prePrint(ostream& , const Args&...);

template <typename T>
const T& addSize(const T&);
#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "MyTem.cpp"
#endif