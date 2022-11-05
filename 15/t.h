#pragma once
#include<iostream>

template<typename T>
void fun(std::ostream&, const T&);

template<typename T, typename... Args>
void fun(std::ostream&, const T&, const Args&... );
#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
    #include "t.cpp"
  #endif
