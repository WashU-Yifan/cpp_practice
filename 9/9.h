#include<iostream>
class MyClass{
    public:
        static size_t NumObject;
        size_t ObjectID;
        MyClass():ObjectID(NumObject++){
            std::cout<<"Default constructor called OBJECTID: "<<ObjectID<<" ADDRESS: "<<this<<std::endl;
        }
        MyClass(const  MyClass& copy):ObjectID(copy.ObjectID){
            ++NumObject;
             std::cout<<"Copy constructor called OBJECTID: "<<ObjectID<<" ADDRESS: "<<this<<std::endl;
        }
        ~MyClass(){
             std::cout<<"Destructor called OBJECTID: "<<ObjectID<<" ADDRESS: "<<this<<std::endl;
        }
        void fun(){
            std::cout<<"Fun() called OBJECTID: "<<ObjectID<<" ADDRESS: "<<this<<std::endl;
        }
};
