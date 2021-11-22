#include "include/myfind.hpp"

MyFind::MyFind()
{
    _counterI = 0;
    _counterR = 0;
    _filePath = "";
    _programName = "";
    _caseSensitiv = false;
    _recursiveSearch = false;
}

void MyFind::printUsage()
{
    std::cout << "Usage: " << _programName << " [-R] [-i] searchpath filename1 [filename2] ...[filenameN]" << std::endl;
}

Finder MyFind::createFinder(std::string fileName)
{
    Finder finder(_caseSensitiv, _recursiveSearch, _filePath, fileName);
    return finder;
}

void MyFind::MyFork()
{
    for (int c = 0; c < (int)_fileNames.size(); c++)
    {
        pid_t tmpPid = fork();
        Finder finder = createFinder(_fileNames[c]);

        switch (tmpPid)
        {
            case -1:    // error
                std::cerr << "Child proccess couldn't be started." << std::endl;
                exit(EXIT_FAILURE);
            case 0:     // childprocess
                if(finder.DeterminePath(finder.GetPath()))
                    exit(EXIT_SUCCESS);
                else
                {
                    if(!finder.GetFound())
                        std::cout << finder.GetFileName() << " couldn't be found." << std::endl;
                    
                    exit(EXIT_FAILURE);
                }
            default:    //parent
                // std::cout << "Child with PID: " << tmpPid << " for " << _fileNames[c] << " created." << std::endl;
                _childProcesses.push_back(tmpPid);
                break;
        }
    }
}

void MyFind::KillTheUndead()
{
    pid_t childPid;
    while((childPid = waitpid(-1, NULL, WNOHANG))) // -1 -> waits for all child p.
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
                _counterR++;
                _recursiveSearch = true;
                break;
            case 'i':
                _counterI++;
                _caseSensitiv = true;
                break;
            case '?':
                printUsage();
                return false;
            default: //impossible
                assert(0); // 0 -> logisch falsch
                break;
        }
    }

    // -R and -i should only be used once
    if(_counterR > 1 || _counterI > 1)
    {
        std::cerr << _programName << " error: Too many arguments." << std::endl;
        printUsage();
        return false;
    }

    // program needs 3 arguments: program, path, file
    if((argc - (_counterI + _counterR)) < 3)
    {
        printUsage();
        return false;
    }

    // use absolute path
    char c[PATH_MAX];
    char *p = realpath(argv[optind], c); //turns the path into an absolute path
    if(p)
        _filePath = p;
    else
    {
        perror("Filepath");
        printUsage();
        return false;
    }
    
    optind++;

    for (int c = optind; c < argc; c++)
        _fileNames.push_back(argv[c]);
    
    return true;
}