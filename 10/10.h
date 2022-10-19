
#include<string>
#include<iostream>
using std::cout;
using std::string;
using std::endl;
class MyClass{
    std::string my_string;
    public:
        virtual void foo();
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
        MyClass& operator=(const MyClass& copy){
            cout<<"copy assignment"<<endl;
            cout<<"this address: "<<this<<endl;
            cout<<"this string member: "<<my_string<<endl;
            cout<<"copy address: "<<&copy<<endl;
            cout<<"copy string member: "<<copy.my_string<<endl;
            this->my_string=copy.my_string;
            return *this;
        }


        virtual ~MyClass(){
            cout<<"destructor"<<endl;
            cout<<"this address: "<<this<<endl;
            cout<<"string member: "<<my_string<<endl;
        }
};
