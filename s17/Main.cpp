#include "MyClass.h"
#include "MyTem.h"
#include <deque>
#include <vector>
#include <list>
#define SUCCESS 0
using std:: cout, std::endl, std::string;
using namespace std;
namespace p{
void print (ostream& os, const MyClass & m) {
    os << m << " from non-template funciton";
}
};
// // In your main function, declare a deque of int, a vector of int, and a list of int, 
// and then write another for loop that iterates a pointer through the array and calls
//  emplace_back on each of those container variables with the value of each element of the array.

// // Then, call your function template with the iterators returned by calls to each 
// containter's begin() and end() member functions, to print out their contents as well. 
// Compile and run your program, and as the answer to this exercise please show the output the program produced.


int main(int, char**) {
    int arr[5] = {1, 2, 3, 4, 5};
    deque<int> d;
    vector<int> v;
    list<int> l;
    printArr(arr, arr + sizeof(arr)/sizeof(*arr));
    for (long unsigned int i = 0; i < sizeof(arr)/sizeof(*arr); ++i) {
        l.emplace_back(*(arr + i));
        v.emplace_back(*(arr + i));
        d.emplace_back(*(arr + i));
    }
    // printArr(l.begin(), l.end());
    cout << v[0] << endl;
    cout << d[0] << endl;
    //cout << l[0] << endl;
    // printArr(d.begin(), d.end());
    return SUCCESS;
}