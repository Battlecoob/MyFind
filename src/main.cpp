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
    
    // wenn argumente eingegeben wurden, starte das programm
    if(myFind.ReadArguments(argc, argv))
    {
        Finder finder = myFind.createFinder();
        finder.SetPid(fork());
        switch(finder.GetPid())
        {
            case -1:
                std::cout << "Child konnte nicht gestartet werden." << std::endl;
                exit(EXIT_FAILURE);
                break;
            case 0:
                // suchfunktion
                break;
            default:
                std::cout << "Child with PID: " << finder.GetPid() << "created." << std::endl;
                // parent();
                break;
        }
    }

    return 0;
}