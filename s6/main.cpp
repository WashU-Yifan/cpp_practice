#include "MyStruct.h"
#include <iostream>
using namespace std;

MyStruct fun (MyStruct ms) {
    return ms;
}
int main() {
    //MyStruct ms1;
   // const MyStruct ms2;

    MyStruct m; // default construction
    fun(m);
    cout << "m.x is " << m.getA() << " and m.y is " << m.getA() << endl;

    m.setA(7).setB(3); // chained use of mutator functions
    fun(m);
    cout << "m.x is " << m.getA() << " and m.y is " << m.getA() << endl;

    MyStruct n(m); // copy construction
    fun(n);
    cout << "n.x is " << n.getA() << " and n.y is " << n.getA() << endl;
    return 0;
}