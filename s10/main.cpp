#include  "BaseClass.h"
#include "DerivedClass.h"
#include "Count.h"
#include <memory>
#include <iostream>
#include <functional>
using std::function, std::mem_fn;
using std::shared_ptr, std::make_shared;
using std::string;
using std::cout, std::endl;
using namespace std;
const int SUCCESS = 0;

unique_ptr<Count> upt () {
    unique_ptr<Count> p = unique_ptr<Count>(new Count());
    return p;
}

void invoke(unique_ptr<Count>& upt) {
    upt->print();
}
int main() {

    unique_ptr<Count> uptr = upt();
    invoke(uptr);
    uptr->print();
    return SUCCESS;
}