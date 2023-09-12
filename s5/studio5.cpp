
#include <iostream>
#include <set>
#include <cstring>
#include <iterator>
#include <cmath>
#include <functional>
#include "Compose_T.h"
using namespace std;
const int SUCCESS = 0;
const int FAIL = 1;

int main(int argc, char * argv[]){ 
    // const char *s1 = "Hello", *s2 = "World!";
    // size_t (* f) (const char*) = std:: strlen;
    // cout << "\"" << s1 << "\"" << s2 << "\"" << endl;
    // cout << s1 << "length: " << (f(s1))<< endl;
    // cout << s2 << "length: " << (f(s2)) << endl;

    float f = 0.0;
    // //cout << f << ": " << sin(cos(f)) << endl;

    function<float(float)> sn =
	 	 [](auto i) { return sin(i); }, cs = [](auto i) { return cos(i); }; 
  
    auto com = compose(sn, cs);
    auto bd = bind(com, f);
    cout << f << ": " << bd() << endl;
    return SUCCESS;
}