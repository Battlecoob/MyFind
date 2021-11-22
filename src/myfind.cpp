#include "include/myfind.hpp"

MyFind::MyFind(/* args */)
{
    CounterI = 0;
    CounterR = 0;
    _programName = "";
    _caseSensitiv = false;
    _recursiveSearch = false;
}

void MyFind::MyFork()
{
    for (int c = 0; c < (int)_fileNames.size(); c++)
    {
        pid_t tmpPid = fork();
        Finder finder = createFinder(tmpPid, _fileNames[c]);

        switch (tmpPid)
        {
            case -1: // fehler passiert
                std::cerr << "Child konnte nicht gestartet werden." << std::endl;
                exit(EXIT_FAILURE);
            case 0:
                if(finder.Find(finder.GetPath()))
                    exit(EXIT_SUCCESS);
                else
                    exit(EXIT_FAILURE);
            default:
                // std::cout << "Child with PID: " << tmpPid << " for " << _fileNames[c] << " created." << std::endl;
                _childProcesses.push_back(tmpPid); // tmpPid
                break;
        }
    }
}

void MyFind::printUsage()
{
    std::cout << "Usage: " << _programName << " [-R] [-i] searchpath filename1 [filename2] ...[filenameN]" << std::endl;
}

void MyFind::KillTheUndead()
{
    pid_t childPid;
    while((childPid = waitpid(-1, NULL, WNOHANG))) // warning if 1 parantheses less
    {
        if((childPid == -1) && (errno != EINTR))
            break;
    }
}

void MyFind::WaitForChildren()
{
    while (_childProcesses.size() > 0) // as long as child processes exist
    {
        int status;
        pid_t wpid = wait(&status);
        for (int c = 0; c < (int)_childProcesses.size(); c++)
        {
            if(_childProcesses[c] == wpid)
            {
                // c cannot be parsed because it's an int. Workaround: Get first element of Vector  and erase the c'd element
                _childProcesses.erase(_childProcesses.begin() + c);
                break;
            }
        }
        
    }
    
}

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
        return false;
    }

    // use absolute path
    char c[PATH_MAX];
    char *p = realpath(argv[optind], c);
    if(p)
        _filePath = p;
    else
    {
        perror("realpath(): ");
        return false;
    }
    
    optind++;

    for (int c = optind; c < argc; c++)
        _fileNames.push_back(argv[c]);
    
    return true;
}