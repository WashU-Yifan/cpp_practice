#include "base.h"

class derived: public base{
    std::string s;
    public:
        derived();
        static const std::string derived::*sp(){
            return &derived::s;
        }
        virtual  void foo();
         virtual ~derived();

};
