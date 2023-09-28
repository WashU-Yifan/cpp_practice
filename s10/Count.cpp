#include "Count.h"
using std:: cout, std:: endl;

size_t Count::objectCount = 0;

Count:: Count(): id(Count::objectCount++) {
    cout << "Default Count(), id: " << id << ", address: " << this << endl; 
}

Count::Count(const Count& c): id(c.id) {
    Count::objectCount++;
    cout << "Copy Count(), id: " << id << ", address: " << this << endl; 
}

Count::~Count() {
    cout << "~Count(), id: " << id << ", address: " << this << endl; 
}

void Count:: print() {
    cout << "call print: id: " << id << ", address: " << this << endl; 
}