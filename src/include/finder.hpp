#include <list>
#include <vector>
#include <errno.h>
#include <dirent.h>
#include <iostream>
#include <unistd.h>
#include <string.h>

#ifndef FINDER_H
#define FINDER_H
#endif

class Finder
{
private:
    pid_t _pid;
    std::string _fileName;
    std::string _filePath;
    bool _caseSensitiv, _recursiveSearch, _found;

public:
    Finder(pid_t pid, bool caseSensitiv, bool recursiveSearch, std::string path, std::string fileName);
    
    void SetPid(int pid) { _pid = pid; }

    const int GetPid() { return _pid; }
    const std::string GetPath() { return _filePath; }
    const bool GetCaseSensitivity() { return _caseSensitiv; }
    const bool GetRecursiveSearch() { return _recursiveSearch; }

    const void PrintPath();
    bool Find(std::string path);
    std::string ToLower(std::string input);
    bool Search(std::string fileToSearch, std::string tmpPath);
};