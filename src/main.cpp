/*
* =======================================================================================================================================
*
*
*                                                   Programm Description
*
*
* =======================================================================================================================================
*/

#include <iostream>
#include <assert.h>
#include <unistd.h> // for getopt();
#include <vector>
// temp weil ich das Makefile nicht verstehe
#include "include/myfind.hpp"

using std::cout; using std::endl;
using std::string; using std::cerr;

int main(int argc, char* argv[])
{
    std::cout << "Starting MyFind..." << std::endl;
    // obj. instanzieren
    MyFind myFind;

    myFind.ReadArguments(argc, argv);
    // wenn argumente eingegeben wurden, starte das programm
    return 0;
}