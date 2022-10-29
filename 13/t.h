#pragma once
#include<type_traits>
template<typename T>
typename std::remove_reference<T>::type && my_move(T&& t);

#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
    #include "13.cpp"
  #endif
