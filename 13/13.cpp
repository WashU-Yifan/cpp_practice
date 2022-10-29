
#include "13.h"
#include<memory>

#define success 0;

using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using std::cout;
using std::endl;
using std::unique_ptr;
typedef unique_ptr<MyClass> upt;

upt fun(upt up);
int main(){
    upt up(new MyClass("hello"));
    upt up2(std::move(up));
    //fun (up2);
    up=fun(std::move(up2));
    up->foo();
    return success;
}

void MyClass::foo(){
         cout<<"foo"<<endl;
            cout<<"this address: "<<this<<endl;
            cout<<"string member: "<<my_string<<endl;
}

upt fun(upt up){
    //up->foo();
    return up;
}
