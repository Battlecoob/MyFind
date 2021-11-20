#include <vector>
#include <iostream>
#include <list>

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
    void SetPid(int pid);
    void SetFilePath(std::vector<std::string> path);

    const int GetPid() { return _pid; }
    const bool GetCaseSensitivity() { return _caseSensitiv; }
    const bool GetRecursiveSearch() { return _recursiveSearch; }

    std::string ToLower(std::string input);
    int Find(std::string FileName, const char* path);
    int Search(std::list<std::string> Content, std::string FileName);
    int CaseSensitiveSearch(std::list<std::string> Content, std::string FileName);
};