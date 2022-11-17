#include <iostream>

#include<algorithm>
#include<iterator>
#include<vector>
#include<set>
#include<list>
#include<span>
#include"17.h"
using namespace::std;
int main(int argc, const char* argv[]) {
    set<string>s;

    cout<<argv[0];
    const char * tmp[3]={"123","123","1223"};

    copy(tmp,tmp+sizeof(tmp)/sizeof(*tmp),inserter(s,s.end()));
    copy(s.begin(),s.end(),ostream_iterator<decltype(*s.begin())>(cout," "));
    return 0;
}
