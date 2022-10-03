#include<iostream>

class point2D1{
    private:
        int x,y;
    public:
        point2D1():x(0),y(0){}
        point2D1(const point2D1& p2):x(p2.get_x()),y(p2.get_y()){}
        int get_x()const{return x;}
        int get_y()const{ return y;}
        point2D1& set_x(int _x){x=_x; return *this;}
        point2D1& set_y(int _y){y=_y; return *this;}



};
