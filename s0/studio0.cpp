/* A C++ Program in the spirit of the classic example from page 6
   of Kernighan and Ritchie's The C Programming Language, 2nd. Ed. */

#include <iostream> // for cout ostream and endl manipulator
#include <fstream>
using namespace std; // optional, could say std::cout and std::endl below instead

const int SUCCESS = 0; // by convention, where non-zero results are error codes
const int FAIL = 1;
const int FAILOPEN = 3;
const int ARGNUM = 2;
int main (int argc, char** argv) { // argc and argv not used, but their types are specified

    if (argc < ARGNUM) {
        cout << "usage: studio0 <arg1> [<arg2> ...]" << endl;
        return FAIL;
    }
    for (int i = 1; i < argc; ++i) {
        ofstream ofs;
        ofs.open(argv[i], ios_base::out);
        if (ofs.fail()) return FAILOPEN;
        ofs << "hello, world!" << endl;
        ofs.close();
    }
     // procedural: has an effect

    return SUCCESS; // functional: returns a success/failure code
}