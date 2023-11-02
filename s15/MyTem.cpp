#include "MyTem.h"
static unsigned int sizeSum = 0;
template <typename T>
void print (ostream& os, const T& t) {
    os << t;
}


template <typename T, typename... Args>
void print (ostream& os, const T& t, const Args&... args) {
    os << t << " ";
    print(os, args...);
}


template <typename... Args>
void prePrint(ostream& os, const Args&... args) {
    os << "variadic size is " << sizeof...(args);
    print(os, addSize(args)...);
    os << " Byte size is " << sizeSum << std::endl;
}

template <typename T>
const T& addSize(const T& t) {
    sizeSum += sizeof(t);
    return t;
}