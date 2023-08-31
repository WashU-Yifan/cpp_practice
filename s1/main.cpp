#include "s1.h"
#include <iostream>
using namespace :: std;

const int SUCCESS = 0;
int main(int argc, char ** argv) {

    MyStruct<> struct1(10), struct2(20);
    cout << struct1 << " " << struct2 << endl;
    swap(struct1, struct2);
    cout << struct1 << " " << struct2 << endl;
    return SUCCESS;
}