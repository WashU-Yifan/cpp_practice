#include "BaseClass.h"
#include <string>
class DerivedClass: public BaseClass {
    std::string derived;
    public:
        static const std::string* getDerived(const DerivedClass& d) {return &d.derived;}
        DerivedClass();
        virtual ~DerivedClass();
        void nonVirtual();

};