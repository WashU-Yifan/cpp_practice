 #include"15.h"

 ostream & operator<<(ostream& os,const my_class& c){
    os<<c.s;
    return os;
 }
/*
bool my_class::operator<(const my_class&m)const {
    return this->s<m.s;
}
*/
 bool operator<(const my_class& m1,const my_class& m2) {
     return m1.s<m2.s;
 }