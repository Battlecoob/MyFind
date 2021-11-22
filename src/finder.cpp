#include "include/finder.hpp"

Finder::Finder(bool caseSensitiv, bool recursiveSearch, std::string path, std::string fileName)
{
    _found = false;
    _pid = getpid();
    _filePath = path;
    _fileName = fileName;
    _caseSensitiv = caseSensitiv;
    _recursiveSearch = recursiveSearch;
}

const void Finder::PrintPath() 
{
    std::cout << "<" << _pid << ">: <" << _fileName << ">: <" << _filePath << ">"<< std::endl;
}

bool Finder::DeterminePath(std::string path)
{
    DIR *dirp;

    if((dirp = opendir(path.c_str())) == NULL)
        return false;
    
    struct dirent *direntp;
    std::string fileToSearch;

    while ((direntp = readdir(dirp)) != NULL && !_found)
    {
        if(strcmp(direntp->d_name, ".") != 0 && strcmp(direntp->d_name, "..") != 0)
        {
            std::string tmpPath = path + "/" + direntp->d_name;
            fileToSearch = direntp->d_name;
            
            if(SearchFile(direntp->d_name, tmpPath))
            {
                PrintPath();
                closedir(dirp);
                return true;
            }

            if(_recursiveSearch)
                DeterminePath(tmpPath);
        }
    }

    if(!_found)
        std::cout << _fileName << " couldn't be found." << std::endl;

    closedir(dirp);
    return false;
}

std::string Finder::ToLower(std::string input)
{
    for(auto it = input.begin(); it != input.end(); it++)
        *it = tolower(*it); 

    return input;
}

bool Finder::SearchFile(std::string fileToSearch, std:: string tmpPath)
{
    std::string tmpString = _fileName;

    if(_caseSensitiv)
    {
        fileToSearch = ToLower(fileToSearch);
        tmpString = ToLower(_fileName);
    }

    if(fileToSearch == tmpString)
    {
        _filePath = tmpPath;
        _found = true;
        return true;
    }

    return false;
}
