#include "s5.h"

using namespace std;

int main(){
    point2D1 m;
    take(m);
    cout<<"m.x is "<<m.get_x()<<" and m.y is "<< m.get_y()<<endl;
    
    m.set_x(7).set_y(3);
    take(m);
    cout<<"m.x is "<<m.get_x()<<" and m.y is "<< m.get_y()<<endl;
    point2D1 n(m);
    take(n);
    cout<<"n.x is "<<n.get_x()<<" and n.y is "<< n.get_y()<<endl;

}
