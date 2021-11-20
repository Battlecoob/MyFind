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
                // throw exception
                break;
            default: //impossible
                assert(0); // 0 -> logisch falsch
                break;
        }
    }

    if(CounterR > 1 || CounterI > 1) // wird auch aufgerufen wenn case '?': ... lul
    {
        std::cerr << _programName << " error: Too many arguments." << std::endl;
        printUsage();
        //throw exception
    }

    _filePath = argv[optind];
    optind++;

    for (int c = optind; c < argc; c++)
        _fileNames.push_back(argv[optind]);
    
    //  Test ob alle Argumente richtig eingelesen und bearbeitet werden
    /*
    std::cout << "Case Sens: " << _caseSensitiv << std::endl;
    std::cout << "Recursive: " << _recursiveSearch << std::endl;
    std::cout << "Path: " << _filePath << std::endl;
    for (int i = 0; i < _fileNames.size(); i++)
    {
        std::cout << "File: " << _fileNames[i] << std::endl;
    }
    */
    
    return true;
}