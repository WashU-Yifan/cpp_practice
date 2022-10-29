#include "13.h"
#include "t.h"
#include<memory>

#define success 0;

using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using std::cout;
using std::endl;
using std::unique_ptr;
using std::make_unique;
typedef unique_ptr<MyClass> upt;

upt fun(upt up);
int main(){
    upt up=make_unique<MyClass>("hello");

    std::remove_reference<decltype(*up)>::type v;
    cout << typeid(v).name() << endl;
    upt up2(my_move(up));
    up=fun(my_move(up2));
    up->foo();
    return success;
}

upt fun(upt up){
    //up->foo();
    return up;
}
