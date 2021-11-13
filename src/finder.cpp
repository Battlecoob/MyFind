#include "include/finder.h"

finder::finder(std::vector<std::string> filenames)
{
    _fileNames = filenames; // ? weiss nicht, ob man einfach so einen vector string kopieren kann -> testen! ... gehoert mit .pushback
    
    //arguments
    _caseSensitiv = false;
    _recursiveSearch = false;
}

void finder::SetCaseSensitiviy(bool b)
{
    _caseSensitiv = b;
}

void finder::SetRecursiveSearch(bool b)
{
    _recursiveSearch = b;
}