#include "12.cpp"
template<typename T=int>
struct my_struct{
    int i;
    my_struct(int _i):i(_i){}
//    my_struct(const my_struct&)=delete;
   //my_struct& operator=(const my_struct&)=delete;
//    ~my_struct()=delete;
};
#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
    #include"12.cpp"
  #endif
