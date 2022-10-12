#include "9.h"
#include<memory>
#define success 0;
size_t MyClass::NumObject;
using std::shared_ptr;
using std::make_shared;

int main(){
	//size_t MyClass::NumObject=0;
    	//MyClass O1,O2(O1);
	shared_ptr<MyClass> sp1=make_shared<MyClass>(),sp2=make_shared<MyClass>(*sp1);
	std::cout<<sp1.get()<<sp2.get()<<std::endl;	
    return success;
}
