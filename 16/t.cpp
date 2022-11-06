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

    std::cout<<"\nint variables size is "<<i_count<<std::endl;
    std::cout<<"\nfloat variables size is "<<f_count<<std::endl;
    std::cout<<"\nother variables size is "<<ui-i_count-f_count<<std::endl;
    std::cout<<"\nArgument pack size is "<<ui<<std::endl;
}

template< typename T>
const T& bar( const T& t){
    ui+=sizeof(t);
    return t;
}

template< >
const int& bar( const int& i){
    ui+=sizeof(i);
    i_count+=sizeof(i);
    return i;
}
template<>
const float& bar( const float& f){
    ui+=sizeof(f);
    f_count+=sizeof(f);
    return f;
}

template <typename... Args> void fun (std::ostream& os, const std::string& s, const Args&...rest){
    os<<"\""<<s<<"\" ";
    fun(os,rest...);
}
template <typename... Args> void fun (std::ostream& os, const char * const c , const Args&... rest){
    os<<"["<<c<<" "<<reinterpret_cast<const void*>(c)<<"]";
    fun(os,rest...);
}
template <typename... Args> void fun (std::ostream& os, const my_class& c, const Args&... rest){
    os << "{" << c <<" "<< &c <<  "}";
    fun(os,rest...);
}


