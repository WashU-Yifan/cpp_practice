#include <iostream>
#pragma once
using std::ostream;

template <typename T>
void print (ostream& , const T&);

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
#include "MyTem.cpp"
#endif