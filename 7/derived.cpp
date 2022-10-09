#include "derived.h"
#include<iostream>
using std::cout;
using std::endl;
class derived{
    public:
        derived(){
            cout<<"derived::derived()"<<endl;

        }
        ~derived(){
            cout<<"derived::~derived"<<endl;     
       }
};
