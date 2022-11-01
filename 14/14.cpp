 #include"14.h"

 ostream & operator<<(ostream& os,const my_class& c){
    os<<c.s;
    return os;
 }

bool my_class::operator<(cosnt my_class&m)const {
    return this.s<m.s;
}