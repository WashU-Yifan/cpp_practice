
#include<string>
#include<iostream>
using std::cout;
using std::string;
class MyClass{
    std::string my_string;
    public:
        MyClass()=default;
        MyClass(const MyClass & copy):my_string(copy.my_string){
            cout<<"copy constrctor"<<endl;
            cout<<"this address: "<<this<<endl;
            cout<<"copy address: "<<&copy<<endl;
            cout<<"string member: "<<my_string<<endl;
        }
        MyClass(const string& s):my_string(s){
            cout<<"constructor"<<endl;
            cout<<"this address: "<<this<<endl;
            cout<<"string member: "<<my_string<<endl;
        }
        ~MyClass(){
            cout<<"destructor"<<endl;
            cout<<"this address: "<<this<<endl;
            cout<<"string member: "<<my_string<<endl;
        }
};