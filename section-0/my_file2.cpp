#include "PPP.h"
#include <iostream>

// import std;
using namespace std;

int main() {
    PPP p;
    p.print();
    std::cout << "Exit code: " << EXIT_SUCCESS << std::endl;
    return 0;
}

/* every C++ program must have at least 1 main() function */

// my_file1.cpp → [compile] → my_file1.o (contains print() implementation)
// my_file2.cpp → [compile] → my_file2.o (contains main())
//                 ↓
//          [link both together]
//                 ↓
//             my_program (executable)