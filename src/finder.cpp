#include "include/finder.hpp"

Finder::Finder(pid_t pid, bool caseSensitiv, bool recursiveSearch, std::string path, std::string fileName)
{
    _pid = pid;
    _caseSensitiv = caseSensitiv;
    _recursiveSearch = recursiveSearch;
    _filePath = path;
    _fileName = fileName;
}

std::string Finder::ToLower(std::string input)
{
    for(auto it = input.begin(); it != input.end(); it++)
        *it = tolower(*it); 

    return input;
}

bool Finder::Search(std::list<std::string> Content, std::string FileName)
{
    if(_caseSensitiv) FileName = ToLower(FileName);

    for(auto it = Content.begin(); it != Content.end(); it++) 
    {
        std::string current = *it;
        if(_caseSensitiv) 
            current = ToLower(current);
        if(current.compare(FileName) == 0)
            return true;

    }
    return false;
}

// int Finder::Find(std::string FileName, const char* path, int id)
// bool?
int Finder::Find() // anderer methoden name! extrem verwirrend find / search
{
    DIR *dirp;
    struct dirent *direntp;
    std::list<std::string> content;
    
    // Vorlage!
    if((dirp = opendir(_filePath.c_str())) == NULL)
        perror("Failed to open");

    while ((direntp = readdir(dirp)) != NULL)
        content.push_back(direntp->d_name);

    /*
    for(auto it = content.begin(); it != content.end(); it++) {
        std::string current = *it;
        std::cout<<current<<std::endl;
    }
    */

    content.remove(".");
    content.remove("..");

    if (_recursiveSearch)
    {
        DIR *recpDir;
        for(auto it = content.begin(); it != content.end(); it++) 
        {
            std::string current = *it;
            const char* subPath = current.c_str();
            if((recpDir = opendir(subPath)) != NULL) 
                Find();
        }
    }

    if(Search(content, _fileName))
    {
        Print();
        exit(EXIT_SUCCESS);
    }

    return 1;
}

const void Finder::Print() 
{
    std::cout << _pid << " : " << _fileName << " : " << _filePath << std::endl;
}