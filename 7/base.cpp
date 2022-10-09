#include "base.h"
#include<iostream>
using std::cout;
using std::endl;
class base{
    public:
    base(){
        std::cout<<"base::base()"<<std::endl;
    }
    ~base(){
        std::cout<<"base::~base()"<<endl;
    }
};