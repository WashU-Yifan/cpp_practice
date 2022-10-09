#include "base.h"

class derived: protected base{
    public:
        derived();
        virtual  void foo();
         virtual ~derived();

};
