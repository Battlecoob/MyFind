#include "include/myfind.hpp"

MyFind::MyFind(/* args */)
{
    CounterI = 0;
    CounterR = 0;
    _programName = "";
    _caseSensitiv = false;
    _recursiveSearch = false;
}

bool MyFind::MyFork()
{
    for (int c = 0; c < (int)_fileNames.size(); c++)
    {
        pid_t tmpPid = fork();
        Finder finder = createFinder(tmpPid, _fileNames[c]);
        // pid error handling
            // case 0 -> starte suche
        switch (tmpPid)
        {
            case -1: // fehler passiert
                std::cout << "Child konnte nicht gestartet werden." << std::endl;
                exit(EXIT_FAILURE);
                break;
            case 0:
                std::cout << "TmpPid: " << tmpPid << " Pid: " << finder.GetPid() << std::endl;
                finder.Find();
                break;
            default:
                std::cout << "Child with PID: " << finder.GetPid() << " created." << std::endl;
                break;
        }
    }
    

/*
    int status = 0;
    pid_t tmpPid, wpid;
    const char* tmp_path = _filePath.c_str();
    // Finder finder(_caseSensitiv, _recursiveSearch, _filePath, _fileNames);

    for(int i=0; i < _fileNames.size(); i++)
    {
        //std::cout<<i<<std::endl;    
        tmpPid = fork();
        // switch
        if (tmpPid == 0)
        {
            int cid = (int)getpid();
            finder.Find(_fileNames[i], tmp_path, cid);
            break;
        }
    }
*/
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
Finder MyFind::createFinder(pid_t pid, std::string fileName)
{
    Finder finder(pid, _caseSensitiv, _recursiveSearch, _filePath, fileName);
    return finder;
}

// return false fehlt noch
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
    
    // TEST: soll ausserhalb von der methode aufgerufen werden
    //myFork();
    
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