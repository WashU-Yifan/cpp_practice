#include "MyTem.h"

template <typename T>
void print (ostream& os, const T& t) {
    os << t << " from template print funciton";
}
