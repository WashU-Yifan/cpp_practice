#include "9.h"
#include<memory>
#define success 0;
size_t MyClass::NumObject;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using std::cout;
using std::endl;
using std::unique_ptr;
unique_ptr<MyClass> make_unique();
void call_fun(unique_ptr<MyClass>& upt);
int main(){
	//size_t MyClass::NumObject=0;
    	//MyClass O1,O2(O1);
	
	unique_ptr<Myclass> up1=make_unique();
	call_fun(upt);
	upt->fun();
    return success;
}
unique_ptr<MyClass> make_unique(){
	return unique_ptr<MyClass>(new MyClass());
}
void call_fun(unique_ptr<MyClass>& upt){
	upt->fun();
}
