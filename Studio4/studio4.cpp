#include "studio4.h"
using namespace std;
const int SUCCESS = 0;
const int days=7;
const int num_pressure=3;

int main(int argc, char * argv[]){
    const char* c1="Hello, ",*c2="World!";
    size_t (*p)(const char * );
    p=strlen;
    cout<<"\""<<c1<<"\""<< ", length: "<<p(c1)<<endl;
    cout<<"\""<<c2<<"\""<< ", length: "<<p(c2)<<endl;
    return SUCCESS;
}
