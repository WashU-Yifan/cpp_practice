#include <iostream>

#include<algorithm>

#include<vector>
#include<deque>
#include<list>
#include"17.h"
using namespace::std;
int main() {
    int int_arr[]={1,2,3,4,5,6};
    cout<<"sizeof the array "<<sizeof(int_arr)<<endl;
    cout<<"sizeof the type in array "<<sizeof(*int_arr)<<endl;

    int* arr_end=int_arr+sizeof(int_arr)/sizeof(*int_arr);
    int * iter=int_arr;
    foo(iter,arr_end);
    deque<int>dq;
    vector<int>v;
    list<int>l;
    for(iter=int_arr;iter!=arr_end;++iter){
        dq.emplace_back(*iter);
        v.emplace_back(*iter);
        l.emplace_back(*iter);
    }
    decltype(v)::iterator vi=v.begin()+1;
    foo(v.begin(),vi);
    foo(vi,v.end());
    vi=(v.end()-v.begin())/2+v.begin();
    foo(v.begin(),vi);
    foo(vi,v.end());
    cout<<v[0];
    cout<<dq[0];
  //  cout<<l[0];
    return 0;
}
