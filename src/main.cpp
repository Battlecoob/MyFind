/*
* =======================================================================================================================================
*
* Program Description
*
* =======================================================================================================================================
*/

#include "include/myfind.hpp"

int main(int argc, char* argv[])
{
    MyFind myFind;

    if(myFind.ReadArguments(argc, argv))    // if all argument inputs are correct, do the actual file search
    {
        myFind.MyFork();                    // creates childprocceses for every file
        myFind.WaitForChildren();           // infinite loop, until child processes finish - so main func, doesn't continue
        myFind.KillTheUndead();             // shouldn't actually happen; kills all remaining processes, that didn't terminate correctly
    }

    return 0;
}