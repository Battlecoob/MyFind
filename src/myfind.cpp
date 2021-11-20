#include "include/myfind.hpp"

MyFind::MyFind(/* args */)
{
    _programName = "";
    _caseSensitiv = false;
    _recursiveSearch = false;
}

void MyFind::fork() 
{
    // not implemented
}

void MyFind::waitForChildren()
{
    // not implemented
}

void MyFind::printUsage()
{
    std::cout << "Usage: " << _programName << " [-R] [-i] searchpath filename1 [filename2] ...[filenameN]" << std::endl;
}

void MyFind::printOutput()
{
    // not implemented
}

void MyFind::KillTheUndead()
{
    // not implemented
}

bool MyFind::ReadArguments(int argc, char*argv[])
{
    int input = 0;
    bool err = false;
    _programName = argv[0]; // ./myfind

    while((input = getopt(argc, argv, "iR")) != EOF)
    //  ehemaliger error: "iR:" ... ':' -> R hat einen Parameter und ist kein switch
    {
        switch(input)
        {
            case 'R':
                CounterR++;
                _recursiveSearch = true;
                break;
            case 'i':
                CounterI++;
                _caseSensitiv = true;
                break;
            case '?':
                std::cerr << _programName << " error: Unknown option." << std::endl;
                printUsage();
                err = true;
                break;
            default: //impossible
                assert(0); // 0 -> logisch falsch
                break;
        }
    }

    return true;
}