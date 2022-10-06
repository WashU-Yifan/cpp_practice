using std::cout;
#include"6.h"
const int num_days=7;
const int num_pressure=4;
const int SUCCESS = 0;
int main(int argc, char * argv[]){
    
    
    Pressure p= Pressure::lo;
    Weekday w=Weekday::Monday;

   // for(Weekday w:set1)cout<<w<<endl;
    //for(Weekday w:set2)cout<<w<<endl;
    /*
    cout<<"lo<hi:"<<(p<p2)<<endl;
    cout<<"Wednesday<Monday:"<<(w2<w1)<<endl;
    /*
    cout<<"Initial: "<<p<<endl;
    cout<<"cout ++p: "<<++p<<endl;
    */
    for(int i=0;i<num_pressure;++i){
        cout<<p;
        ++p;
    }
    for(int i=0;i<num_days;++i){
        cout<<w;
        ++p;
    }
    return SUCCESS;
}
