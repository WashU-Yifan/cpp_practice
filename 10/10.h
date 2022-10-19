
#include<string>
#include<iostream>
using std::cout;

class MyClass{
    std::string my_string;
    public:
        MyClass()=default;
        MyClass(const MyClass & copy):my_string(copy.my_string){
            cout<<"this address: "<<this<<endl;
            cout<<"copy address: "<<&copy<<endl;
        }
};