
#include<iostream>
#include<memory>
#include "derived.h"
using std::cout;
using std:: endl;
using std::shared_ptr;
using std:: make_shared;
#define success 0
int main(){
    base b;
    derived d;
    const string derived::*dp1=&derived::s;
    const string derived::*dp2=&base::s;
    const string base::*bp=&base::s;
    cout<<"derived fetched by ptr 1"<<d.*dp1<<endl;
    cout<<"derived fetched by ptr 2"<<d.*dp2<<endl;
    cout<<"base fetched by ptr 3"<<d.*dp3<<endl;
    return success;
}
