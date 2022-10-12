#include "9.h"
#include<memory>
#define success 0;
size_t MyClass::NumObject;
int main(){
	//size_t MyClass::NumObject=0;
    	//MyClass O1,O2(O1);
	shared_ptr<MyClass> sp1=make_shared(),sp2=make_shared(&sp1);
	
    return success;
}
