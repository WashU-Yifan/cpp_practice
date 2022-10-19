
#include "10.h"
#include<memory>

#define success 0;

using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using std::cout;
using std::endl;
using std::unique_ptr;

int main(){
    MyClass obj("hello"),obj2(obj);
    return success;
}