#include <list>
#include <vector>
#include <assert.h>
#include <iostream>
#include <unistd.h> // getopt();
#include "finder.hpp"

#ifndef MYFIND_H
#define MYFIND_H
#endif

class MyFind
{
private:
    // selbe var wie finder - code duplication...
    std::string _filePath;
    int CounterR, CounterI;
    std::string _programName;
    std::vector<std::string> _fileNames;
    bool _caseSensitiv, _recursiveSearch;

    void printUsage();
    void printOutput();
    void waitForChildren();

public:
    MyFind(/* args */);

    void SetCaseSensitiviy(bool b) { _caseSensitiv = b; }
    void SetRecursiveSearch(bool b) { _recursiveSearch = b; }

    const bool GetCaseSensitivity() { return _caseSensitiv; }
    const bool GetRecursiveSearch() { return _recursiveSearch; }
    
    bool MyFork();
    void KillTheUndead();
    Finder createFinder(pid_t pid, std::string fileName);
    bool ReadArguments(int argc, char* argv[]);
};
