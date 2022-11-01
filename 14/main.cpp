#include"14.h"
#include "t.h"
using std::cout;
#define SUCCESS 0

int main(){
    my_class m1("m1"),m2("m2");
    cout<<m1<<" "<<m2;
    fun(cout,m1);
    fun(cout,m2);
    cout<<"result of comparing m1<m2: ";
    fun (cout,(m1<m2));

    return SUCCESS;
}