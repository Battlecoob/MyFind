#include <assert.h>
#include <limits.h> // PATH_MAX
#include "finder.hpp"

#ifndef MYFIND_H
#define MYFIND_H
#endif

class MyFind
{
private:
    std::string _filePath;
    int _counterR, _counterI;
    std::string _programName;
    std::vector<pid_t> _childProcesses;
    std::vector<std::string> _fileNames;
    bool _caseSensitiv, _recursiveSearch;

    void printUsage();
    Finder createFinder(std::string fileName);

public:
    MyFind();

    void SetCaseSensitiviy(bool b) { _caseSensitiv = b; }
    void SetRecursiveSearch(bool b) { _recursiveSearch = b; }

    const bool GetCaseSensitivity() { return _caseSensitiv; }
    const bool GetRecursiveSearch() { return _recursiveSearch; }
    
    void MyFork();
    void KillTheUndead();
    void WaitForChildren();
    bool ReadArguments(int argc, char* argv[]);
};
