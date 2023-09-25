#include  "BaseClass.h"
#include "DerivedClass.h"
#include <memory>
#include <iostream>
#include <functional>
using std::function, std::mem_fn;
using std::shared_ptr, std::make_shared;
using std::string;
using std::cout, std::endl;
const int SUCCESS = 0;
int main() {
    BaseClass b;
    DerivedClass d;
    auto p1 = mem_fn(&BaseClass::nonVirtual);
    auto p2 = mem_fn(&BaseClass::nonVirtual);
    auto p3 = mem_fn(&DerivedClass::nonVirtual);

    p1(b);
    p2(d);
    p3(d);
    // function<void (BaseClass&)> p1 = &BaseClass::nonVirtual;
    // function<void (DerivedClass&)> p2 = &BaseClass::nonVirtual;
    // function<void (DerivedClass&)> p3 = &DerivedClass::nonVirtual;
   
    // void (BaseClass::*p1)() = &BaseClass::nonVirtual;
    // void (DerivedClass::*p2)() = &BaseClass::nonVirtual;
    // void (DerivedClass::*p3)() = &DerivedClass::nonVirtual;
    // const string * sp1 = DerivedClass::getDerived(d);
    // const string * sp2 = BaseClass::getBase(d);
    // const string * sp3 = BaseClass::getBase(b);
    // cout << *sp1 << endl;
    // cout << *sp2 << endl;
    // cout << *sp3 << endl;
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
    

    // BaseClass *p1 = new BaseClass(), *p2 = new DerivedClass();
    // DerivedClass *p3 = new DerivedClass();
    // p1->nonVirtual();
    // p2->nonVirtual();
    // p3->nonVirtual();
    // delete p1;
    // delete p2;
    // delete p3;
    return SUCCESS;
}