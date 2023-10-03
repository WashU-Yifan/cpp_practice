#include "Foo.h"
using namespace std;

Foo:: Foo(const Foo& f2): fooString(f2.fooString) {
    cout << "Copy construct, fooString : " << fooString << ", address: " << this << endl;
}


Foo::Foo(const string& s): fooString(s) {
    cout << "Constructor, fooString : " << fooString << ", address: " << this << endl;
}

Foo& Foo::operator=(const Foo& f2) {
    cout << "Copy Assign Operator, fooString : " << fooString << ", address: " << this << endl;
    cout << "       Other Object, fooString : " << f2.fooString << ", address: " << &f2 << endl;
    fooString = f2.fooString;
    return *this;
}

void Foo::print(){
    cout << "Print: " << fooString << ", address: " << this << endl;
}

Foo::~Foo() {
    cout << "Destructor, fooString : " << fooString << ", address: " << this << endl;
}