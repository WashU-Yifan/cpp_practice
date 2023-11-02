#include "MyClass.h"


ostream& operator<< (ostream& os, const MyClass& myClass) {
    os << myClass.s;
    return os;
}

// bool MyClass::operator< (const MyClass& myClass) const {
//     return this->s < myClass.s;
// }

bool operator< (const MyClass& myClass1, const MyClass& myClass2) {
    return myClass1.s < myClass2.s;
}

MyClass::MyClass(const string& st): s(st) {}
