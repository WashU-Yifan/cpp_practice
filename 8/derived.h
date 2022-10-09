#include "base.h"

class derived: public base{
    public:
        derived();
        std::string s;
        virtual  void foo();
         virtual ~derived();

};
