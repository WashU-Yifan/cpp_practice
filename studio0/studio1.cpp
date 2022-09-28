#include "studio1.h"
using namespace std;
const int SUCCESS = 0;
const int days=7;
const int num_pressure=3;
void operator++ (Weekday &day,int){
    
    switch (day){
        case Weekday::Monday:{
            day=Weekday::Tuesday;
            break;
        }
        case Weekday::Tuesday:{
            day= Weekday::Wednesday;
             break;
        }
        case Weekday::Wednesday:{
            day=Weekday::Thursday;
             break;
        }
        case Weekday::Thursday:{
            day= Weekday::Friday;
             break;
        }
        case Weekday::Friday:{
            day=Weekday::Saturday;
             break;
        }   
        case Weekday::Saturday:{
            day=Weekday::Sunday;
             break;
        }
        default:{
            day= Weekday::Monday;
             break;
        }
    }
}

void operator-- (Weekday &day,int){
    
    switch (day){
        case Weekday::Monday:{ day=Weekday::Sunday;break;}
        case Weekday::Tuesday:{day= Weekday::Monday;break;}
        case Weekday::Wednesday:{ day=Weekday::Tuesday; break;}
        case Weekday::Thursday:{  day= Weekday::Wednesday;break;}
        case Weekday::Friday:{day=Weekday::Thursday;break; }   
        case Weekday::Saturday:{day= Weekday::Friday; break;}
        default:{day=Weekday::Saturday;break;}
    }
}

ostream &operator<< (ostream &os, const Weekday &day){
    switch (day){
        case Weekday::Monday:{
            os<<"MON ";
            return os;
        }
        case Weekday::Tuesday:{
            os<<"TUE ";
            return os;
        }
        case Weekday::Wednesday:{
            os<<"WED ";
            return os;
        }
        case Weekday::Thursday:{
            os<<"THU ";
            return os;
        }
        case Weekday::Friday:{
            os<<"FRI ";
            return os;
        }   
        case Weekday::Saturday:{
            os<<"SAT ";
            return os;
        }
        default:{
            os<<"SUN ";
            return os;
        }
    }

}


ostream &operator<< (ostream &os, const Pressure &p){
    switch (p){
        case Pressure::lo:{os<<"LOW ";return os;}
        case Pressure::med:{os<<"MEDIUM ";return os;}

        case Pressure::hi:{os<<"HIGH ";return os;}
        default:{os<<"POP ";return os;} 
    }

}

void operator++ (Pressure &p){
    switch (p){
        case Pressure::lo:{p=Pressure::med;return ;}
        case Pressure::med:{p=Pressure::hi;return ;}

        case Pressure::hi:{p=Pressure::pop;return ;}
        default: return;
    }
}
int main(int argc, char * argv[]){
    Pressure p= Pressure::lo;
    for(int i=0;i<num_pressure;++i){
        cout<<p;
        ++p;
    }
    return SUCCESS;
}