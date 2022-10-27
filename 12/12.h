struct my_struct{
    int i;
    my_struct(int _i):i(_i){}
    //my_struct(const my_struct&)=delete;
    //my_struct& operator=(const my_struct&)=delete;
//    ~my_struct()=delete;
};
