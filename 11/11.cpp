#include "11.h"
#include<iostream>
using namespace std;

int main(){
    const int i1=0;
    int  i2=1;
    const int*const p1=&i1, *const p2=&i2;
    /* int *const p3=&i1;*/int * const p4=&i2;
    const int *p5=&i1, *p6=&i2;
    /*int *p7=&i1;*/int *p8=&i2;
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
    return 0;

}