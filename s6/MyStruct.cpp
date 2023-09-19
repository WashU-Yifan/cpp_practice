
#include "MyStruct.h"
#include <iostream>
using namespace std;
// MyStruct:: MyStruct(): a(0), b(0){
//     cout << "Default Constructor : " << this << endl;
//     cout << "   " << a << ", " << b << endl;
// }

MyStruct:: MyStruct(const MyStruct& m2): a(m2.a), b(m2.b) {

    cout << "Copy Constructor : " << this << endl;
    cout << "   " << a << ", " << b << endl;
}

MyStruct&  MyStruct::setA(int val) {
    a = val;
    return *this;
}
MyStruct&  MyStruct::setB(int val) {
    b = val;
    return *this;
}

