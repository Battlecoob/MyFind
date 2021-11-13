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
    finder(std::vector<std::string> filenames);
    void SetPid(int pid);
    void SetCaseSensitiviy(bool b);
    void SetRecursiveSearch(bool b);
    void SetFilePath(std::vector<std::string> path);
    void SetFileName(std::vector<std::string> file);

    const int GetPid() { return _pid; }
    const bool GetCaseSensitivity() { return _caseSensitiv; }
    const bool GetRecursiveSearch() { return _recursiveSearch; }
    // main searchfunc
    // .toLowerCase() for case insesitivity
    // recursive prob. doesn't need a stand alone func
};

