#pragma once
#include<iostream>
template<typename>class my_struct;
template<typename T>
std::ostream& operator<<(std::ostream&,const my_struct<T>&);

template<typename T=int> class my_struct{

    friend std::ostream& operator<< (std::ostream&,const my_struct<T>&);
    T i;
public:
    my_struct( T&);

//    my_struct(const my_struct&)=delete;
   //my_struct& operator=(const my_struct&)=delete;
//    ~my_struct()=delete;
};


#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
    #include "12.cpp"
  #endif
