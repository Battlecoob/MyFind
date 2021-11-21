#include "include/myfind.hpp"

MyFind::MyFind(/* args */)
{
    _programName = "";
    _caseSensitiv = false;
    _recursiveSearch = false;
    CounterI = 0;
    CounterR = 0;
}

void MyFind::myFork()
{
    int status = 0;
    pid_t pid, wpid;
    const char* path = _filePath.c_str();
    Finder finder(_caseSensitiv, _recursiveSearch, _filePath, _fileNames);

    for(int i=0; i < _fileNames.size(); i++)
    {
        //std::cout<<i<<std::endl;    
        pid = fork();
        // switch
        if (pid == 0)
        {
            int cid = (int)getpid();
            finder.Find(_fileNames[i],path,cid);
            break;
        }
        else {
        
        }
    }
    while ((wpid = wait(&status)) > 0);
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

// NOT IN USE
Finder MyFind::createFinder()
{
    Finder finder(_caseSensitiv, _recursiveSearch, _filePath, _fileNames);
    return finder;
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
        _fileNames.push_back(argv[c]);
    
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
        
    // TEST: soll ausserhalb von der methode aufgerufen werden
    myFork();
    
    return true;
}