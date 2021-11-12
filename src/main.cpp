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

// temp weil ich das Makefile nicht verstehe
#include "include/finder.h"

using std::cout; using std::endl;
using std::string;



void PrintUsage(string ProgrammName)
{
    cout << "Usage: " << ProgrammName << " [-R] [-i] searchpath filename1 [filename2] ...[filenameN]" << endl;
}

// int main(int argc, string argv[])
int main(int argc, char* argv[])
{
    std::cout << "Test" << std::endl;
    /*
    std::cout << "start..." << std::endl;
    int c;
    std::string FileName, ProgramName;
    unsigned short RArgumentCounter, iArgumentCounter;

    ProgramName = argv[0];
    std::cout << ProgramName << std::endl;
    */
    return 0;
}