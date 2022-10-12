
#include "PinochleDeck.h"
#include "HoldEmDeck.h"
using namespace std;
const int SUCCESS=0;
int main(int , char**){

    Pinochle p,p2;
    HoldEm T=HoldEm();
    p.collect(p2);
    p2.print(cout,4);
    cout<<" print method1  done"<<endl;
    
    T.print(cout,4);
    cout<<" print method2  done"<<endl;
    return SUCCESS;
}
