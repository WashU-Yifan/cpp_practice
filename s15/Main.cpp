#include "MyClass.h"
#define SUCCESS 0
using std:: cout, std::endl, std::string;

namespace p{
void print (ostream& os, const MyClass & m) {
    os << m << " from non-template funciton";
}
};

int main(int, char**) {
    string s = "string 1";
    const char * c = "const char 1";
    MyClass m("MyClass 1");
    int i = 10;
    float f = 3.14;
    prePrint(cout, s, c, m, i, f);
//     MyClass myclass("string 1"), myclass2("string 2");
//     print(cout, myclass);
//     p::print(cout, myclass2);
//    // cout << myclass << " " << myclass2 << endl;
//     cout << (myclass < myclass2) << endl;
    return SUCCESS;
}