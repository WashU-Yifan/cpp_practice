#include<string>
#include<iostream>
using std::string;
using std::ostream;

class my_class{
    std::string s;
    friend  ostream & operator<<(ostream&,const my_class&);
    friend bool operator<(const my_class& ,const my_class&) ;
    public:
        my_class(const std::string& _s):s(_s){}
        bool operator<(const my_class&)const ;
        
};

 ostream & operator<<(ostream&,const my_class&);
 bool operator<(const my_class& ,const my_class&) ;