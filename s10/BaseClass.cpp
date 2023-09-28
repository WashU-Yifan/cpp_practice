#include "BaseClass.h"
#include <iostream>
using std::cout, std::endl;
BaseClass::BaseClass(): base("Base") {
    cout << "BaseClass::BaseClass" << endl;
}

BaseClass::~BaseClass() {
    cout << "BaseClass::~BaseClass()" << endl;
}

void BaseClass:: nonVirtual() {
    cout << "BaseClass:: nonVirtual()" << endl;
}