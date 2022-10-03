#include "s5.h"

using namespace std;

int main(){
    point2D1 p1;
    cout<<"access on nonconst: "<<p1.get_x()<<endl;
    cout<<"mutate then access on nonconst: "<<p1.set_x(1).get_x()<<endl;
   const point2D1 p2;
    cout<<"access on nonconst: "<<p2.get_x()<<endl;
    //cout<<"mutate then access on const: "<<p2.set_x(1).x()<<endl;
}
