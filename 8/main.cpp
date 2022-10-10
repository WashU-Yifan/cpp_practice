#include<string>
#include<iostream>
#include<memory>
#include "derived.h"
#include<functional>
using std::string;
using std::cout;
using std:: endl;
using std::shared_ptr;
using std:: make_shared;
using std::function;
using std::mem_fn;
#define success 0
using fun=void(base::*)();
int main(){
    base b;
    derived d;
    function<void(base&)>basefoo=&base::foo;
    function<void(base&)>dfoo1=&derived::foo;
    function<void(derived&)>dfoo2=&derived::foo; 
    cout<<"base foo evoked by base :  "<<endl;
    basefoo(b);
    cout<<"base foo evoked by derived :  "<<endl;
    dfoo1(d);
    cout<<"derived foo evoked by derived : "<<endl;
    dfoo2(d);

    auto bf=mem_fn(&base::foo);
    auto df=mem_fn(&derived::foo);
    cout<<"base foo evoked by base :  "<<endl;
    bf(b);
    cout<<"base foo evoked by derived :  "<<endl;
    bf(d);
    cout<<"derived foo evoked by derived : "<<endl;
    df(d);
    /*
    void (base::*bfp)();
    bfp=&base::foo;
    void (derived::*dfp1)();
    dfp1=&base::foo;
    void (derived::*dfp2)();
    dfp2=&derived::foo;
    cout<<"base foo evoked by base ptr:  "<<endl;
    //(b.*bfp)();
    cout<<"derived foo evoked by derived pointing to base:  "<<endl;
    //(d.*dfp1)();
    cout<<"derived foo evoked by derived pointing to derived: "<<endl;
    //(d.*dfp2)();
    */
    return success;
}
