#include <iostream>

#include<algorithm>
#include<iterator>
#include<vector>
#include<set>
#include<list>

#include<cstring>
using namespace std;
bool foo(const char* c1, const char* c2){
    return strcmp(c1,c2)>0;
}

int main(int argc,  char* tmp[]) {
    set<char*,decltype(foo)*>s(foo);
    multiset<char *, decltype(foo)*>ms(foo);


    

    copy(tmp,tmp+argc,inserter(ms,ms.begin()));
    copy(ms.begin(),ms.end(),ostream_iterator<char*>(cout," "));
    return 0;
}
