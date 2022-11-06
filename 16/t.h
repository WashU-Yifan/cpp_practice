#pragma once
#include "nt.h"
#include<iostream>
static unsigned int ui=0;
static unsigned int i_count=0,f_count=0;

template<typename T>
void fun(std::ostream&, const T&);

template<typename T, typename... Args>
void fun(std::ostream&, const T&, const Args&... );

template< typename... Args>
void mult_fun(std::ostream&, const Args&... );

template< typename T>
const T& bar( const T& );
template< >
const int& bar( const int& );
template<>
const float& bar( const float& );
template <typename... Args> void fun (std::ostream& , const std::string& , const Args&...);
template <typename... Args> void fun (std::ostream& , const char * const , const Args&...);
template <typename... Args> void fun (std::ostream& , const my_class& , const Args&...);
#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
    #include "t.cpp"
  #endif
