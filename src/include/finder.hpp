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
    pid_t _pid;
    bool _caseSensitiv, _recursiveSearch;
    std::string _filePath;
    std::string _fileName;

public:
    Finder(pid_t pid, bool caseSensitiv, bool recursiveSearch, std::string path, std::string fileName);
    
    void SetPid(int pid) { _pid = pid; }

    const int GetPid() { return _pid; }
    const bool GetCaseSensitivity() { return _caseSensitiv; }
    const bool GetRecursiveSearch() { return _recursiveSearch; }

    std::string ToLower(std::string input);
    int Find();
    const void Print();
    int Find(std::string FileName, const char* path, int id);
    bool Search(std::list<std::string> Content, std::string FileName);
    //int Search(std::list<std::string> Content, std::string FileName);
    //int CaseSensitiveSearch(std::list<std::string> Content, std::string FileName);
};