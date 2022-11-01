#include "t.h"
using std::ostream;
template<typename T>
void fun(ostream& os, const T& t){
    os<<"from template: "<<t;
}