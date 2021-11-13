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
#include "include/finder.h"

using std::cout; using std::endl;
using std::string; using std::cerr;

void PrintUsage(string ProgrammName)
{
    cout << "Usage: " << ProgrammName << " [-R] [-i] searchpath filename1 [filename2] ...[filenameN]" << endl;
}

// int main(int argc, string argv[])
int main(int argc, char* argv[])
{
    std::cout << "Starting MyFind..." << std::endl;

    int c;
    std::string FileName = "", ProgramName = "";
    unsigned short RArgumentCounter = 0, iArgumentCounter = 0;
    
    //testing
    std::vector<string> TestTmp;
    TestTmp.push_back("test.cpp");
    finder Finder(TestTmp);
    ProgramName = argv[0]; // full path! Selber Fehler, dass ich das Programm nicht ueber die command line ausueben kan

    while((c = getopt(argc, argv, "Ri:")) != EOF) 
    {
        switch (c)
        {
            case '?': // unknown
                // fprintf( stderr, "%s error: Unknown option.\n", programm_name );
                cerr << ProgramName << " error: Unknown option" << endl;
                PrintUsage(ProgramName); // should contain a string...if not .toString()
                break;
            case 'R':
                RArgumentCounter++;
                Finder.SetRecursiveSearch(true);
                break;
            case 'i':
                iArgumentCounter++;
                Finder.SetCaseSensitiviy(true);
                break;
            default: // impossible
                assert(0);
        }
    }

    // check for counters || Error handling
    if (( RArgumentCounter > 1 ) || ( iArgumentCounter > 1 )) 
    {
        cerr << ProgramName << " Fehler: Optionen wurden mehrfach verwendet." << endl;
        exit(1);
    }

    if ( optind < argc ) 
    {
        printf("ARGV Elemente ohne Optionen: ");
        while ( optind < argc ) 
        {
            cout << argv[optind++] << endl;
        }
        printf("\n");
    } 
    else if ( optind >= argc ) 
    {
        cerr << "Fehler: Es wurden Optionen, die Argumente erwarten, ohne Argumente befuellt." << endl;
        exit(EXIT_FAILURE);
    }
    
    return 0;
}