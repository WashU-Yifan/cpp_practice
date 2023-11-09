#include <deque>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iostream>
#include <list>
#include <iterator>
#define SUCCESS 0
using std:: cout, std::endl, std::string;
using std:: vector;

int main(int, char**) {
    int arr[] = {-2, 19, 80, -47, 80, 80, -2, 19, 19};
    int *start= arr, *end = arr + sizeof(arr) / sizeof(*arr);
    std::ostream_iterator<int> os(cout, " ");
    //std::copy(start, end, os);
    vector<int> v;
    std::back_insert_iterator<vector<int> > viterator(v);
    std::copy(start, end, viterator);
    std::sort(v.begin(), v.end(), std:: greater<int>());
    // auto vstart = v.begin(), vend = v.begin();
    // while (vend != v.end()) {
    //     vend = std::adjacent_find(vstart, v.end());
    //     vstart = vend;
    //     while(*vend == *vstart) {
    //         cout << *vend << " ";
    //         ++vend;
    //     }
    //     cout << endl;
    //     vstart = vend;
    // }

    int sum = std::accumulate(v.begin(), v.end(), 0);
    float mean = (float)sum / v.size();
    int median = *(v.begin() + v.size() / 2);
    auto iter = v.begin();
    int mod = v[0], freq = 1;
    while (iter != v.end()) {
        int count = std::count(iter, v.end(), *iter);
        if (count > freq) {
            freq = count;
            mod = *iter;
        }
        iter += count;
    }
    cout << "Mean is " << mean << endl;
    cout << "Median is " << median << endl;
    cout << "Most frequent number " << mod << endl;
    std::copy(v.begin(), v.end(), os);
    return SUCCESS;
}