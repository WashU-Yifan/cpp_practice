#include"15.h"
#include "t.h"
using std::cout;
#define SUCCESS 0



int main(){
    my_class m("Class");
    std::string s("string");
    const char* c="char *";
    int i=1;
    float f=1.2;
    mult_fun(cout,m,s,c,i,f);
    /*
    fun(cout,s);
    fun(cout,c);
    fun(cout,i);
    fun(cout,f);
*/
    return SUCCESS;
}