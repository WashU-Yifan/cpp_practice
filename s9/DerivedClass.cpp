#include "DerivedClass.h"
#include <iostream>

using std::cout, std::endl;

DerivedClass::DerivedClass():derived("Derived") {
    cout << "DerivedClass:: DerivedClass()" << endl;
}

DerivedClass::~DerivedClass() {
    cout << "DerivedClass:: ~DerivedClass()" << endl;
}


void DerivedClass:: nonVirtual() {
    cout << "DerivedClass:: nonVirtual()" << endl;
}