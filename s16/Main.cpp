#include "MyClass.h"
#include "MyTem.h"
#define SUCCESS 0
using std:: cout, std::endl, std::string;

namespace p{
void print (ostream& os, const MyClass & m) {
    os << m << " from non-template funciton";
}
};

int main(int, char**) {
    string s = "string 1", s2 = "string 2";
    cout << sizeof(s) << endl;
    const char * c = "const char 1", *c2 = "const char 2";
    cout << sizeof(*c) << endl;
    MyClass m("MyClass 1"), m2("MyClass 2");
    cout << sizeof(m) << endl;
    int i = 10;
    float f = 3.14;
    prePrint(cout, s, c, m, i, f, s2, c2, m2);

    return SUCCESS;
}