#include "12.h"

#include<iostream>

using std::cout;
using std::endl;
#define SUCCESS 0
int main(){
    int i1=1,i2=2;
<<<<<<< HEAD
//    my_struct<bool> s3(false);
=======

>>>>>>> 2069f497b3da1401b26be7d520e957bb39230805
    my_struct<> s1(i1);
    my_struct<>s2(i2);
    cout<<"s1: "<<s1.i<<", s2: "<<s2.i<<endl;
    std::swap(s1,s2);
    cout<<"s1: "<<s1.i<<", s2: "<<s2.i<<endl;
    return SUCCESS;
}
