/* A C++ Program in the spirit of the classic example from page 6
   of Kernighan and Ritchie's The C Programming Language, 2nd. Ed. */

#include <iostream> // for cout ostream and endl manipulator

using namespace std; // optional, could say std::cout and std::endl below instead

const int SUCCESS = 0; // by convention, where non-zero results are error codes

int main (int, char**) { // argc and argv not used, but their types are specified

    cout << "hello, world!" << endl; // procedural: has an effect

    return SUCCESS; // functional: returns a success/failure code
}
