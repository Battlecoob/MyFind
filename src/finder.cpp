#include "include/finder.hpp"

Finder::Finder(bool caseSensitiv, bool recursiveSearch, std::string path, std::vector<std::string> fileNames)
{
    _caseSensitiv = caseSensitiv;
    _recursiveSearch = recursiveSearch;
    _filePath = path;
    _fileNames = fileNames;
}
// Finder::Finder(std::vector<std::string> filenames)
// {
//     _fileNames = filenames; // ? weiss nicht, ob man einfach so einen vector string kopieren kann -> testen! ... gehoert mit .pushback
    
//     //arguments
//     _caseSensitiv = false;
//     _recursiveSearch = false;
// }

// void Finder::SetCaseSensitiviy(bool b)
// {
//     _caseSensitiv = b;
// }

// void Finder::SetRecursiveSearch(bool b)
// {
//     _recursiveSearch = b;
// }