#pragma once
#include <iostream>

class Count {
    public:
        static size_t objectCount;
        size_t id;
        void print();
        Count();
        Count(const Count&);
        ~Count();
};

