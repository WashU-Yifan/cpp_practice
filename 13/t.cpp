template<typename T>
typename remove_reference<T>::type && my_move(T&& t){
    return static_cast<typename remove_reference<T>::type&&> (t);
}