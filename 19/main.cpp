#include <iostream>

#include<algorithm>
#include<iterator>
#include<vector>
#include<set>
#include<list>

using namespace::std;
int main(int argc, const char* tmp[]) {
    set<string>s;


    

    copy(tmp,tmp+argc,inserter(s,s.begin()));
    copy(s.begin(),s.end(),ostream_iterator<decltype(*s.begin())>(cout," "));
    return 0;
}
