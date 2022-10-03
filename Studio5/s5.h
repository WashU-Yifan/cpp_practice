#include<iostream>

class point2D1{
        point2D():x(0),y(0){}
    private:
        int x,y;

};
class point2D2{
      point2D():x(0),y(0){}
    protected:
        int x,y;
  
};
class point2D3{
    public:
        int x,y;
        point2D():x(0),y(0){}
};