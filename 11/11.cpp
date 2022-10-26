#include "11.h"
#include<iostream>
using namespace std;
typedef int i;
typedef const int ci;
typedef int* const icp;
typedef const int* const cicp;
typedef int * ip;
typedef const int * cip;

int main(){
    ci i1=0;
    i  i2=1;
    cicp p1=&i1,  p2=&i2;
    /* int *const p3=&i1;*/
    icp p4=&i2;
    cip p5=&i1, p6=&i2;
    /*int *p7=&i1;*/
    ip p8=&i2;
    cout<< "i1: "<<i1;
    cout<<"i2: "<<i2;
    cout<<"p1: "<<p1<<", *p1: "<<*p1<<endl;
    cout<<"p2: "<<p2<<", *p2: "<<*p2<<endl;
    //cout<<"p3: "<<p3<<", *p3: "<<*p3<<endl;
    cout<<"p4: "<<p4<<", *p4: "<<*p4<<endl;
    cout<<"p5: "<<p5<<", *p5: "<<*p5<<endl;
    cout<<"p6: "<<p6<<", *p6: "<<*p6<<endl;
    //cout<<"p7: "<<p7<<", *p7: "<<*p7<<endl;
    cout<<"p8: "<<p8<<", *p8: "<<*p8<<endl;
    //++i1;
    ++i2;
    //++p1;
    //++p2;
    //++p4;
    ++p5;
    ++p6;
    ++p8;
    //++*p1;
    //++*p2;
    ++*p4;
    //++*p5;
    //++*p6;
    ++*p8;
    auto ai1=i1;
    auto ai2=i2;
    auto ap1=p1;
    auto ap2=p2;
    auto ap4=p4;
    auto ap5=p5;
    auto ap6=p6;
    auto ap8=p8;
    ++ai1;
    ++ai2;
    
    ++ap1;
    ++ap2;
    ++ap4;
    ++ap5;
    ++ap6;
    ++ap8;

    //++*ap1;
    //++*ap2;
    ++*ap4;
    //++*ap5;
    //++*ap6;
    ++*ap8;

    decltype(i1) di1=i1;
    decltype(i2) di2=i2;
    decltype(p1) dp1=p1;
    decltype(p2) dp2=p2;
    decltype(p4) dp4=p4;
    decltype(p5) dp5=p5;
    decltype(p6) dp6=p6;  
    decltype(p8) dp8=p8;
    //++di1;
    ++di2;

    //++dp1;
    //++dp2;
    //++dp4;
    ++dp5;
    ++dp6;
    ++dp8;

    //++*dp1;
    //++*dp2;
    ++*dp4;
    //++*dp5;
    //++*dp6;
    ++*dp8;

    return 0;

}