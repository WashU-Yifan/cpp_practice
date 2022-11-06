#include"16.h"
#include "t.h"
#include "nt.h"
using std::cout;
#define SUCCESS 0



int main(){
    my_class m("Class");
    std::string s("string");
    const char* c="char *";
    int i=1;
    float f=1.2;
    string s2="string 2";
    const char* c2= "char * c2";
    my_class m2("Class 2");
    mult_fun(cout,m,s,c,i,f,s2,c2,m2);
    /*
    fun(cout,s);
    fun(cout,c);
    fun(cout,i);
    fun(cout,f);
*/
    return SUCCESS;
}