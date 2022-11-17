#include <iostream>

#include<algorithm>
#include<iterator>
#include<vector>
#include<set>
#include<list>

using namespace::std;
int main(int argc, const char* tmp[]) {
    set<string>s;


    

    copy(tmp,tmp+sizeof(tmp)/sizeof(*tmp),inserter(s,s.end()));
    copy(s.begin(),s.end(),ostream_iterator<decltype(*s.begin())>(cout," "));
    return 0;
}
