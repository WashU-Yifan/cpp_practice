/* A C++ Program in the spirit of the classic example from page 6
   of Kernighan and Ritchie's The C Programming Language, 2nd. Ed. */

#include <iostream> // for cout ostream and endl manipulator
#include<fstream>
using namespace std; // optional, could say std::cout and std::endl below instead

const int SUCCESS = 0; // by convention, where non-zero results are error codes
const int argc_number=2;
const int FAIL_wrong_arg_number=1;
const int FAIL_invalid_file=2;
int main (int argc, char** argv) { // argc and argv not used, but their types are specified
    if(argc!=argc_number){
        cout<<"usage: "<<argv[0]<<" <arg1> [<argv2>....]"<<endl;
        
        return FAIL_wrong_arg_number;
    }
    ofstream out (argv[1]);
    if(out.is_open()){
        out<<"hello, world!" << endl;
    }
    else{
        return FAIL_invalid_file;
    }
 

    return SUCCESS; // functional: returns a success/failure code
}