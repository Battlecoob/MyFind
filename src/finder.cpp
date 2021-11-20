#include "include/finder.hpp"

Finder::Finder(bool caseSensitiv, bool recursiveSearch, std::string path, std::vector<std::string> fileNames)
{
    _caseSensitiv = caseSensitiv;
    _recursiveSearch = recursiveSearch;
    _filePath = path;
    _fileNames = fileNames;
}

std::string Finder::ToLower(std::string input)
{
    for(auto it = input.begin(); it != input.end(); it++)
        *it = tolower(*it); 

    return input;
}

bool Finder::Search(std::list<std::string> Content, std::string FileName)
{
    if(_caseSensitiv) std::string LowerCaseFileName = ToLower(FileName);

    for(auto it = Content.begin(); it != Content.end(); it++) 
    {
        std::string current = *it;
        if(_caseSensitiv) current = ToLower(current);
        if(current.compare(FileName) == 0)
        {
            std::cout << "found file " << FileName << std::endl;;
            break;
        }
    }
}

int Finder::Find(std::string FileName, const char* path)
{
    std::list<std::string> content;
    bool recursive = false;
    struct dirent *direntp;
    DIR *dirp;
    if((dirp = opendir(path)) == NULL) {
        perror("Failed to open");
    }

    while ((direntp = readdir(dirp)) != NULL)
    {
        content.push_back(direntp->d_name);
    }


    /*
    for(auto it = content.begin(); it != content.end(); it++) {
        std::string current = *it;
        std::cout<<current<<std::endl;
    }
    */

    content.remove(".");
    content.remove("..");

    if (recursive) {
    DIR *recpDir;
        for(auto it = content.begin(); it != content.end(); it++) {
            std::string current = *it;
            const char* sub_path = current.c_str();
            if((recpDir = opendir(sub_path)) == NULL) {

            }
            else {
                Find(FileName, sub_path);
            }   
        }
    }

    Search(content,FileName);

    return 0;
}

/*
int Finder::Search(std::list<std::string> Content, std::string FileName)
{
    for(auto it = Content.begin(); it != Content.end(); it++) 
    {
        std::string current = *it;
        if(current.compare(FileName) == 0)
        {
            std::cout << "found file " << FileName << std::endl;;
            break;
        }
    }

    return 0;
}

int Finder::CaseSensitiveSearch(std::list<std::string> Content, std::string FileName)
{
    std::string lowercaseFilename = ToLower(FileName);

    for(auto it = Content.begin(); it != Content.end(); it++)
    {
        std::string current = *it;
        current = ToLower(current);
        if(current.compare(lowercaseFilename) == 0)
        {
            std::cout<<"found insensitive file "<<FileName<<std::endl;;
            break;
        }
    }
    
    return 0;
}
*/