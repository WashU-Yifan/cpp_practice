#include "Foo.h"

#include <memory>
using namespace std;
const int SUCCESS = 0;

unique_ptr<Foo> fun(unique_ptr<Foo> f) {
    f->print();
    return f;
}
int main(int, const char **) {
    unique_ptr<Foo> uptr(new Foo("f1")), uptr2 = move(uptr);

    
    uptr = fun(move(uptr2));
    return SUCCESS;

}
