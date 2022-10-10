#include<string>
#include<iostream>
#include<memory>
#include "derived.h"
using std::string;
using std::cout;
using std:: endl;
using std::shared_ptr;
using std:: make_shared;
#define success 0
int main(){
    base b;
    derived d;
    void (base::*bfp)();
    bfp=&base::foo;
    void (derived::*dfp1)();
    dfp1=&base::foo;
    auto dfp2=&derived::foo;
    cout<<"base foo evoked by base ptr:  "<<(b.*bfp)()<<endl;
    cout<<"derived foo evoked by derived pointing to base:  "<<(d.*dfp1)()<<endl;
    cout<<"derived foo evoked by derived pointing to derived: "<<(d.*dfp2)()<<endl;
    return success;
}
