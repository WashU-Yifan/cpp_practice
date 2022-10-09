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
    const string derived::*dp1=derived::sp();
    const string derived::*dp2=base::sp();
    const string base::*bp=base::sp();
    cout<<"derived fetched by ptr 1:  "<<d.*dp1<<endl;
    cout<<"derived fetched by ptr 2:  "<<d.*dp2<<endl;
    cout<<"base fetched by ptr 3:  "<<b.*bp<<endl;
    return success;
}
