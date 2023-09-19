class MyStruct{
    public:
    int a,b;
    MyStruct();
    public:
        
        MyStruct(const MyStruct&);
        inline int getA() const {return a;};
        inline int getB() const {return b;};
        MyStruct&  setA(int val);
        MyStruct&  setB(int val);
}; 