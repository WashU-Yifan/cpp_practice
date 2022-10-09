
#include<iostream>
#include<memory>
#include "derived.h"
using std::cout;
using std:: endl;
using std::shared_ptr;
using std:: make_shared;
#define success 0
int main(){
    /*
    base b;
    derived d;
    base &br1=b;
    base &br2=d;
    derived& dr1=d;
    */
    base *bp1=new base();
    base*bp2=new derived();
    derived *dp=new derived();
 /*   cout<< "base object function call"<<endl;
    b.foo();
    cout<< "derived object function call"<<endl;
    d.foo();
    cout<< "base reference base function call"<<endl;
    br1.foo();
    cout<< "base reference derived function call"<<endl;
    br2.foo();
    cout<< "derived reference function call"<<endl;
    dr1.foo();
 
    shared_ptr<base> sb1=make_shared<base>();
    shared_ptr<base> sb2=make_shared<derived>();
    shared_ptr<base> sd=make_shared<derived>();
    */
    cout<< "base pointer function call"<<endl;
    bp1->foo();
	cout<< "base points to derived function call"<<endl;
	bp2->foo();
	cout<< "derived  pointer function call"<<endl;
	dp->foo();


    return success;
}
