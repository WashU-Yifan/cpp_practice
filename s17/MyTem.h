#include <iostream>
#include "MyClass.h"
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

template <typename T>
void printArr(T, T);

template < typename... Args>
void print (ostream& , const std::string&, const Args&...);

template < typename... Args>
void print (ostream& , const char* const , const Args&...);

template < typename... Args>
void print (ostream& , const MyClass&, const Args&...);
template <>
const int& addSize(const int&);
template <>
const float& addSize(const float&);


#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "MyTem.cpp"
#endif