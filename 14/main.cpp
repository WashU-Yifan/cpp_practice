#include"14.h"
#include "t.h"
using std::cout;
#define SUCCESS 0

namespace my_namespace {
    void fun(ostream &os, const my_class &m) {
        os << "from reggular fun: " << m;
    }
}
void fun(ostream &os, const my_class &m) {
        os << "from reggular fun: " << m;
    }

int main(){
    my_class m1("m1"),m2("m2");
    my_namespace::fun(cout,m1);
    fun(cout,m1);
    fun(cout,m2);
    cout<<"result of comparing m1<m2: ";
    fun (cout,(m1<m2));

    return SUCCESS;
}