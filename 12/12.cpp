#include "12.h"

template<typename T>
my_struct<T>:: my_struct( T& t):i(t){}


template<typename T>
std::ostream& operator<<(std::ostream& os,const my_struct<T>& s){
    os<<s.i;//<<std::endl;
    return os;
}
