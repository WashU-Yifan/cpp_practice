#include "BaseClass.h"
class DerivedClass: public BaseClass {
    public:
        DerivedClass();
        virtual ~DerivedClass();
        virtual void nonVirtual();

};