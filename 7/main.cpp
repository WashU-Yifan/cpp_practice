
#include "derived.h"
using std::cout;
using std:: endl;
#define success 0
int main(){
    base b;
    derived d;
    base &br1=b;
    base &br2=d;
    derived& dr1=d;
    cout<< "base object function call"<<endl;
    b.foo();
    cout<< "derived object function call"<<endl;
    d.foo();
    cout<< "base reference base function call"<<endl;
    br1->foo();
    cout<< "base reference derived function call"<<endl;
    br2->foo();
    cout<< "derived reference function call"<<endl;
    dr1->foo();
    return success;
}
