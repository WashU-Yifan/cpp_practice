#include "base.h"
#include<iostream>
using std::cout;
using std::endl;
base::base():s("base"){
        std::cout<<"base::base()"<<std::endl;
    }
base::~base(){
        std::cout<<"base::~base()"<<endl;
    }
void base::foo(){
    cout<<"base::foo()"<<endl;
}