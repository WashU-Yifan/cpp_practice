#include <iostream>

namespace enumerations {
enum class Weekday{
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
    
};

enum class Pressure{
    lo,
    med,
    hi,
    pop
};

std::ostream &operator<< (std::ostream &os, const Weekday &day);
Weekday operator++ (Weekday &day,int);
Weekday operator-- (Weekday &day,int);


std::ostream &operator<< (std::ostream &os, const Pressure &p);
Pressure& operator++ (Pressure &p);
}