
template<typename T=int>
struct my_struct{
    T i;
    my_struct( T&);
//    my_struct(const my_struct&)=delete;
   //my_struct& operator=(const my_struct&)=delete;
//    ~my_struct()=delete;
};
#ifdef TEMPLATE_HEADERS_INCLUDE_SOURCE
    #include "12.cpp"
  #endif
