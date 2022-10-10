#include<string>
class base{
     std::string s;
    public:
    static const std::string base::*sp(){
        return &base::s;
    }
    base();
    void foo();
     virtual ~base();
};
