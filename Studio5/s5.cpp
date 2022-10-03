#include "s5.h"

using namespace std;

int main(){
    point2D1 m;
    cout<<"m.x is "<<m.get_x()<<" and m.y is "<< m.get_y()<<endl;
    m.set_x(7).set_y(3);
    cout<<"m.x is "<<m.get_x()<<" and m.y is "<< m.get_y()<<endl;
    point2D1 n(m);
    cout<<"n.x is "<<n.get_x()<<" and n.y is "<< n.get_y()<<endl;

}
