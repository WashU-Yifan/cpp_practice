#include "12.h"

template<typename T>
my_struct<T>:: my_struct( T& t):i(t){}

template<>
my_struct<int>:: my_struct( int& t):i(t){}
