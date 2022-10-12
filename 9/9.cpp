#include "9.h"
#include<memory>
#define success 0;
size_t MyClass::NumObject;
using std::shared_ptr;
using std::make_shared;
using std::weak_ptr;
using std::cout;
using std::endl;
int main(){
	//size_t MyClass::NumObject=0;
    	//MyClass O1,O2(O1);
	
	shared_ptr<MyClass> sp1=make_shared<MyClass>(),sp2=make_shared<MyClass>(*sp1);
	
	weak_ptr<MyClass> wp1(sp1);
	cout<<"assigning sp1=sp2"<<endl;
		sp1=sp2;
	cout<<"assignment done"<<endl;
	shared_ptr<MyClass> sp3=wp1.lock();
	if(sp3==nullptr){
		cout<<"weak ptr wp1 is no longer pointing to a valid object"<<endl;
	}
	else{
		cout<<sp1.use_count()<<endl
			;
		sp3->fun();
		sp3.reset();
		cout<<sp1.use_count()<<endl;
	}
    return success;
}
