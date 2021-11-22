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
    MyFind myFind;
    
    // wenn argumente eingegeben wurden, starte das programm
    if(myFind.ReadArguments(argc, argv))
    {
        myFind.MyFork();
        myFind.WaitForChildren(); // infinite loop, until child processes finish
        myFind.KillTheUndead();
    }
    else
        std::cout << "An error occurred during the input." << std::endl;

    return 0;
}