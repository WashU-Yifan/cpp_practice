#include "t.h"
using std::ostream;
template<typename T>
void fun(ostream& os, const T& t){
    os<<t<<" ";
}

template<typename T, typename... Args>
void fun(std::ostream& os, const T& t, const Args&... rest){
    os<<t<<" ";
    fun(os,rest...);
}