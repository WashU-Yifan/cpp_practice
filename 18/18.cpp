#include <iostream>
#include<string>
#include<algorithm>
#include<iterator>
#include <numeric>
#include<unordered_set>
using namespace::std;
int main() {
    int int_arr[]={1,2,3,4,4,8,8,1};
    cout<<"sizeof the array "<<sizeof(int_arr)<<endl;
    cout<<"sizeof the type in array "<<sizeof(*int_arr)<<endl;

    int* arr_end=int_arr+sizeof(int_arr)/sizeof(*int_arr);
    int * iter=int_arr;
    sort(int_arr,arr_end);

    while((iter=adjacent_find(iter,arr_end))!=arr_end){
        int *next=iter;
        cout<< *iter<<" ";
        while(adjacent_find(++next,arr_end)==next){
            cout<<*next<<" ";
        }
        cout<<*next<<endl;
        iter=next;
    }
    sort(int_arr,arr_end,greater<int>());
    ostream_iterator<int> int_it(cout," ");
    copy(int_arr,arr_end,int_it);
    //median
    size_t size=sizeof(int_arr)/sizeof(*int_arr);
    float median=*(int_arr+size/2)+*(int_arr+(size-1)/2);
    cout<<"median is "<<median/2<<endl;
    //mean
    float sum=accumulate(int_arr,arr_end,sum);
    cout<<"mean is "<<sum/(sizeof(int_arr)/sizeof(*int_arr))<<endl;
    //mode
    iter=int_arr;
    int max_count=0,max_val=*int_arr;
    int cnt=0;
    while(iter!=arr_end){
        cnt=count(iter,arr_end,*iter);
        if(max_count<cnt){
            max_count=cnt;
            max_val=*iter;
        }
        iter+=cnt;
    }
    cout<<"most frequent element is "<<max_val<<endl;
    return 0;
}
