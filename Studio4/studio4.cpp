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
    float f=0.0;
    cout<<"f is :"<<f<<endl;
    cout<<"sin(cos(f)) is:" <<sin(cos(f))<<endl;
    function<float(float)> sn =[](auto i){return sin(i);};
    function<float(float)> cs =[](auto i){return cos(i);};
    cout<<sn(cs(i))<<endl;
    auto compose_result=compose(sn,cs);
    cout<<compose_result(i)<<endl;
    cout<<bind(compose_result,i)<<endl;
    return SUCCESS;
}
