#include <iostream>

#include<algorithm>
#include<iterator>
#include<vector>
#include<set>
#include<list>

using namespace::std;
int main(int argc,  char* tmp[]) {
    set<char*>s;


    

    copy(tmp,tmp+argc,inserter(s,s.begin()));
    copy(s.begin(),s.end(),ostream_iterator<char *>(cout," "));
    return 0;
}
