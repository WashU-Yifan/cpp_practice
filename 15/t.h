#pragma once
#include<iostream>
static unsigned int ui=0;
template<typename T>
void fun(std::ostream&, const T&);

template<typename T, typename... Args>
void fun(std::ostream&, const T&, const Args&... );

template< typename... Args>
void mult_fun(std::ostream&, const Args&... );

template< typename T>
const T& bar( const T& );
#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
    #include "t.cpp"
  #endif
