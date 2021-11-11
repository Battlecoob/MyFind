#include "include/finder.h"

finder::finder(int pid, bool caseSensitiv, bool recursiveSearch, std::vector<std::string> filenames)
{
    _pid = pid;
    _caseSensitiv = caseSensitiv;
    _recursiveSearch = recursiveSearch;
    //_fileNames = filenames; // ? weiss nicht, ob man einfach so einen vector string kopieren kann -> testen! ... gehoert mit .pushback
}

finder::~finder()
{
}

