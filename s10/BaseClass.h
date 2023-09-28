#pragma once
#include <string>

class BaseClass {
    std::string base;
    public:
        static const std::string* getBase(const BaseClass& b) {return &b.base;}
        BaseClass();
        virtual ~BaseClass();
        void nonVirtual();
};