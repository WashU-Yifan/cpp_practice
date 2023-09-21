#include "Enum.h"
#include<iostream>
#include <set>
#include <algorithm>
#include <iterator>
using std ::cout, std::endl, enumerations:: Pressure, enumerations:: Weekday;

const int SUCCESS = 0;
const int days=7;
const int num_pressure=3;

int main(int , const char **){
    Pressure p = Pressure::lo;
    Weekday w = Weekday::Monday;
   
    for (int i = 0; i <= num_pressure; ++i) {
        cout << p << " ";
        ++p;
    }
    cout << endl;
    for (int i = 0; i <= days; ++i) {
        cout << w++ << " ";
    }
    cout << endl;
    return SUCCESS;
}