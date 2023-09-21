#include  "BaseClass.h"
#include "DerivedClass.h"
#include <memory>
using std::shared_ptr, std::make_shared;
const int SUCCESS = 0;
int main() {
    // BaseClass b;
    // DerivedClass d;
    // BaseClass &b1 = b, &b2 = d;
    // DerivedClass &d1 = d;
    // BaseClass *p1 = &b, *p2 = &d;
    // DerivedClass *p3 = &d;
    // p1->nonVirtual();
    // p2->nonVirtual();
    // p3->nonVirtual();
    // shared_ptr<BaseClass> sp1 = make_shared<BaseClass>();
    // shared_ptr<BaseClass> sp2 = make_shared<DerivedClass>();
    // shared_ptr<DerivedClass> sp3 = make_shared<DerivedClass>();

    // sp1->nonVirtual();
    // sp2->nonVirtual();
    // sp3->nonVirtual();
    

    BaseClass *p1 = new BaseClass(), *p2 = new DerivedClass();
    DerivedClass *p3 = new DerivedClass();
    p1->nonVirtual();
    p2->nonVirtual();
    p3->nonVirtual();
    delete p1;
    delete p2;
    delete p3;
    return SUCCESS;
}