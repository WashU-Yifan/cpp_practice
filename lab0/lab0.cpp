
#include "PinochleDeck.h"
#include "HoldEmDeck.h"
using namespace std;
const int SUCCESS=0;
int main(int , char**){

    Pinochle p=Pinochle();
    HoldEm T=HoldEm();

    p.print(cout);
    cout<<" print method1  done"<<endl;
    
    T.print(cout);
    cout<<" print method2  done"<<endl;
    return SUCCESS;
}