#include <list>
#include <vector>
#include <errno.h>
#include <dirent.h>
#include <iostream>

#ifndef FINDER_H
#define FINDER_H
#endif

class Finder
{
private:
    int _pid;
    bool _caseSensitiv, _recursiveSearch;
    std::string _filePath;
    std::vector<std::string> _fileNames;

public:
    Finder(bool caseSensitiv, bool recursiveSearch, std::string path, std::vector<std::string> fileNames);
    void SetPid(int pid) { _pid = pid; }

    const int GetPid() { return _pid; }
    const bool GetCaseSensitivity() { return _caseSensitiv; }
    const bool GetRecursiveSearch() { return _recursiveSearch; }

    std::string ToLower(std::string input);
    int Find(std::string FileName, const char* path);
    bool Search(std::list<std::string> Content, std::string FileName);
    //int Search(std::list<std::string> Content, std::string FileName);
    //int CaseSensitiveSearch(std::list<std::string> Content, std::string FileName);
};