#include<iostream>

class point2D1{
    private:
        int x,y;
    public:
        point2D1():x(0),y(0){
            std::cout<<"calling default constructor"<<std::endl;
            std::cout<<"address"<< this<<std::endl;
            std::cout<<"variables value:"<<x<<y<<std::endl;
        }
        point2D1(const point2D1& p2):x(p2.x),y(p2.y){
            std::cout<<"calling copy constructor"<<std::endl;
            std::cout<<"address"<< this<<std::endl;
            std::cout<<"variables value:"<<x<<y<<std::endl;}
        int get_x()const{return x;}
        int get_y()const{ return y;}
        point2D1& set_x(int _x){x=_x; return *this;}
        point2D1& set_y(int _y){y=_y; return *this;}



};
point2D1 take(point2D1 p1){return p1;}