#include "Foo.h"
#include <typeinfo>
#include <type_traits>
#include <memory>
using namespace std;
const int SUCCESS = 0;

unique_ptr<Foo> fun(unique_ptr<Foo> f) {
    f->print();
    return f;
}

template <typename T>
typename remove_reference<T>::type && myMove(T&& t) {
    return static_cast<typename remove_reference<T>::type  &&> (t);
}


int main(int, const char **) {
    unique_ptr<Foo> uptr(std::make_unique<Foo>("f1")), uptr2 = myMove(uptr);
    unique_ptr<Foo> uptr3(std::make_unique<Foo>("f1"));
    cout << " " << typeid(std::remove_reference<decltype(*uptr2)>::type).name() << endl;
     cout << " " << typeid(std::remove_reference<decltype(*uptr3)>::type).name() << endl;
    uptr = fun(myMove(uptr2));
    return SUCCESS;

}
