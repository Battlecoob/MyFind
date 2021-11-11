#include <iostream>
#include <vector>

#ifndef FINDER_H
#define FINDER_H
#endif

class finder
{
private:
    int _pid;
    bool _caseSensitiv, _recursiveSearch;
    std::vector<std::string> _filePath;
    std::vector<std::string> _fileNames;

public:
    finder(int pid, bool caseSensitiv, bool recursiveSearch, std::vector<std::string> filenames);

    // main searchfunc
    // .toLowerCase() for case insesitivity
    // recursive prob. doesn't need a stand alone func
};

