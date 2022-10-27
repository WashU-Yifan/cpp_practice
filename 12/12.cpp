#include"12.h"
#include<iostream>

using std::cout;
using std::endl;
#define SUCCESS 0
int main(){
    my_struct<> s1(1),s2(2);
    cout<<"s1: "<<s1.i<<", s2: "<<s2.i<<endl;
    std::swap(s1,s2);
    cout<<"s1: "<<s1.i<<", s2: "<<s2.i<<endl;
    return SUCCESS;
}
