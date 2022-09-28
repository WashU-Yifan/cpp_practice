/* A C++ Program in the spirit of the classic example from page 6
   of Kernighan and Ritchie's The C Programming Language, 2nd. Ed. */

#include <iostream> // for cout ostream and endl manipulator
#include<fstream>
#include<vector>
#include<string>
using namespace std; // optional, could say std::cout and std::endl below instead

int main (int , char** ) { // argc and argv not used, but their types are specified
    vector<string>v;
    vector<string>:: iterator iter=v.begin();
    *iter++;
    (*iter)++;
    *iter.empty();
    iter->empty();
    ++*iter;
    iter++->empty();
    int sum=0;

    for(int i=0;i<=10;++i){
        sum+=i;
    }
    cout<<i<<" "<<sum<<endl;
    return 0; // functional: returns a success/failure code
}