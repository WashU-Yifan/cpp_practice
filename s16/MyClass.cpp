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


void print(std::ostream& os, const std::string& s) {
    os << "\""  << s  << "\"";
}

void print(std::ostream& os, const char* const c) {
    os << "["  << c  << reinterpret_cast<const void*>(c) << "] ";
}

void print(std::ostream& os, const MyClass& myClass) {
    os << "{"  << myClass << ", " << &myClass << "}";
}

void print (std::ostream&){}