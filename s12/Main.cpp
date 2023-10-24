#include <iostream>
#include <memory>
using namespace std;
const int SUCCESS = 0;

typedef int i;
typedef const int ci;
typedef int* const cpi;
typedef const int* const cpci;
typedef int*  pi;
typedef const int* pci;


int main(int, const char **) {
    ci i1 = 0;
    i i2 = 1;
    cpci p1 = &i1;
    cpci p2 = &i2;
    cpi p4 = &i2;
    pci p5 = &i1, p6 = &i2;
    pi p8 = &i2;
    // auto ap1 =  p1;
    // auto ap2 =  p2;
    // auto ap4 =  p4;
    // auto ap5 =  p5;
    // auto ap6 =  p6;
    // auto ap8 =  p8;

    decltype(p1) dp1 = p1;
    decltype(p2) dp2 = p2;
    decltype(p4) dp4 = p4;
    decltype(p5) dp5 = p5;
    decltype(p6) dp6 = p6;
    decltype(p8) dp8 = p8;
    ++*dp1;
    ++*dp2;
    ++*dp4;
    ++*dp5;
    ++*dp6;
    ++*dp8;

    ++dp1;
    ++dp2;
    ++dp4;
    ++dp5;
    ++dp6;
    ++dp8;


    // ++*ap1;
    // ++*ap2;
    // ++*ap4;
    // ++*ap5;
    // ++*ap6;
    // ++*ap8;

    // ++ap1;
    // ++ap2;
    // ++ap4;
    // ++ap5;
    // ++ap6;
    // ++ap8;
    cout << i1 << i2 << endl;
    cout << "pointer p1" << p1 << "-> " << *p1 << endl;
    cout << "pointer p2" << p2 << "-> " << *p2 << endl;

    cout << "pointer p4" << p4 << "-> " << *p4 << endl;
    cout << "pointer p5" << p5 << "-> " << *p5 << endl;
    cout << "pointer p6" << p6 << "-> " << *p6 << endl;
   
    cout << "pointer p8" << p8 << "-> " << *p8 << endl;
    return SUCCESS;

}
