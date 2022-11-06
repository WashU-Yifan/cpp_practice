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


template< typename... Args>
void mult_fun(std::ostream& os, const Args&... rest){
    os<<sizeof...(rest)<<std::endl;

    fun(os,bar(rest)...);
    std::cout<<"Argument pack size is "<<ui<<std::endl;
}

template< typename T>
const T& bar( const T& t){
    ui+=sizeof(t);
    return t;
}

template <> void fun (std::ostream& os, const std::string& s){
    os<<"\""<<s<<" \"";
}
template <typename... Args> void fun (std::ostream& os, const std::string& s, const Args&...rest){
    os<<"\""<<s<<" \"";
    fun(os,rest...);
}

