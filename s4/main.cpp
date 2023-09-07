#include "studio4.h"
#include<iostream>
#include <set>
#include <algorithm>
#include <iterator>
using namespace std;
const int SUCCESS = 0;
const int days=7;
const int num_pressure=3;

int main(int argc, char * argv[]){
    set<Weekday> s1, s3({Weekday:: Monday,Weekday:: Tuesday});
    set<Pressure> s2;
    Pressure p = Pressure::lo;
    Weekday w = Weekday::Monday;
    do {
        s2.insert(p);
        ++p;
    }
    while(p < Pressure::pop);

    do {
        s1.insert(w++);
        
    }
     while(w < Weekday::Sunday);
    // for (auto i : s1) {
    //     cout << i << " ";
    // }
    // cout<< endl;
    // for (auto i : s2) {
    //     cout << i << " ";
    // }
    set<Weekday> s4;
    //set_intersection(s1.begin(), s1.end(), s3.begin(), s3.end(),inserter(s4, s4.end()));
    set_union(s1.begin(), s1.end(), s3.begin(), s3.end(),inserter(s4, s4.end()));
    for (auto i : s4) {
        cout << i << " ";
    }
    return SUCCESS;
}