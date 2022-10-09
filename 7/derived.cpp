#include "derived.h"
#include<iostream>
using std::cout;
using std::endl;

  derived::derived(){
            cout<<"derived::derived()"<<endl;

        }
  derived::~derived(){
            cout<<"derived::~derived()"<<endl;     
       }
   void  derived::foo(){
        cout<<"derived::foo()"<<endl;     
    }
