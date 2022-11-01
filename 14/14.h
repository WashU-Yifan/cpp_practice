#include<string>
#include<iostream>
using std::string;
using std::ostream;

class my_class{
    std::string s;
    friend  ostream & operator<<(ostream&,const my_class&);
    public:
        my_class(const std::string& _s):s(_s){}
       
        
};

 ostream & operator<<(ostream&,const my_class&);