#include "t.h"
template<typename T>
typename std::remove_reference<T>::type && my_move(T&& t){
    return static_cast<typename std::remove_reference<T>::type&&> (t);
}