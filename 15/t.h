#pragma once
#include<iostream>

template<typename T>
void fun(std::ostream&, const T&);
#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
    #include "t.cpp"
  #endif
