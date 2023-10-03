#pragma once
#include <iostream>

class Foo{
    std::string fooString;

    public:
        Foo() = default;
        Foo(const std::string &);
        Foo(const Foo&);


        Foo& operator=(const Foo&);
        virtual void print();
        virtual ~Foo();
};