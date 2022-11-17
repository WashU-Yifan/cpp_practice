#include <iostream>
#ifndef S17_17_H
#define S17_17_H

#endif //S17_17_H
template<typename T> void  foo(T t1,T t2){
    while(t1!=t2){
        std::cout<<*t1<<" ";
        t1++;
    }
    std::cout<<std::endl;
};