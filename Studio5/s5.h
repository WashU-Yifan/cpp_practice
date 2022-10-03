#include<iostream>

class point2D1{
    public:
        point2D():x(0),y(0){}
        int x()const{return x;}
        int y()const{ return y;}
        point2D1& set_x(int _x){x=_x; return *this;}
        point2D1& set_y(int _y){y=_y; return *this;}

    private:
        int x,y;

};
