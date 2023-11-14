#include <set>

#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <list>
#include <iterator>
#define SUCCESS 0
using std:: cout, std::endl, std::string;
using namespace std;

bool myCompare(const string& s1, const string& s2) {
    return s1 > s2;
}
int main(int argc, char** argv) {
    char **start= argv, **end = argv + argc;
    std::ostream_iterator<string> os(cout, " ");
    // set<char*, decltype(myCompare)*> s(myCompare);
    // multiset<char*, decltype(myCompare)*> ms(myCompare);
    // copy(start, end, inserter(s, s.begin()));
    // copy(start, end, inserter(ms, ms.begin()));


    multiset<string> ms;
    copy(start, end, inserter(ms, ms.begin()));
    string key = "1";
    std::cout << "key = " << key << "; equal range = ";
    const auto [lb, ub] = ms.equal_range(key);
    copy(lb, ub, os);

    //ms.erase(lb);
    ms.erase(lb, ub);
    // copy(s.begin(), s.end(), os);
     copy(ms.begin(), ms.end(), os);
    return SUCCESS;
}