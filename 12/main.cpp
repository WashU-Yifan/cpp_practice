#include "12.h"

#include<iostream>

using std::cout;
using std::endl;
#define SUCCESS 0
int main(){
    int i1=1,i2=2;
    my_struct<> s1(i1);
    my_struct<>s2(i2);
    cout<<"s1: "<<s1.i<<", s2: "<<s2.i<<endl;
    std::swap(s1,s2);
    cout<<"s1: "<<s1.i<<", s2: "<<s2.i<<endl;
    return SUCCESS;
}
