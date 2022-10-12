
#include "PinochleDeck.h"
#include "HoldEmDeck.h"
using namespace std;
const int SUCCESS=0;
int main(int , char**){

    Pinochle p,p2;
    HoldEm T=HoldEm();
    try{
        while(1){
            p>>p2;

        }

    }
    catch(runtime_error & e){
        cout<<e.what()<<endl;
        
    }
    p2.print(cout,4);
    cout<<" print method1  done"<<endl;
    
    T.print(cout,4);
    cout<<" print method2  done"<<endl;
    return SUCCESS;
}
