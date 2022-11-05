#include"15.h"
#include "t.h"
using std::cout;
#define SUCCESS 0

namespace my_namespace {
    void fun(ostream &os, const my_class &m) {
        os << "from reggular fun: " << m;
    }
}
void fun(ostream &os, const my_class &m) {
        os  << m;
    }

int main(){
    my_class m("Class");
    std::string s("string");
    const char* c="char *";
    int i=1;
    float f=1.2;
    fun(cout,m);
    fun(cout,s);
    fun(cout,c);
    fun(cout,i);
    fun(cout,f);

    return SUCCESS;
}