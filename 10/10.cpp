
#include "10.h"
#include<memory>

#define success 0;

using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using std::cout;
using std::endl;
using std::unique_ptr;
typedef unique_ptr<MyClass> upt;
int main(){
    upt up(new MyClass("hello"));
    upt up2(std::move(up));
    return success;
}