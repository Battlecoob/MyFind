/*
* =======================================================================================================================================
*
* Program Description
*
*
*This Programm is used to perform parallel file searching in a Linux filesystem.
*
*When starting the user has to provide arguments for the programm in the command line.
*These arguments consist of two optional switches -R and -i which determine if the searches should be performed recursive and/or case-insensitive.
*Other arguments are an absolute or relative path to start the search and at least one filename to search for.
*If there is an error the user will get a short message on how to correctly use the programm
*
*If all arguments are correct the programm starts with creating an object of the MyFind class.
*This object handles the flow of the programm and the parallelization
*In the MyFork function the programm forks into different processes for each filename.
*
*Every process then creates an object of the Finder class which performs the actual file search with the given arguments.
*If the search was succesfull the user gets the process id, the filename and the path to the found file as output.
*
*The parent process of the MyFind object then waits for all child processes to finish (WaitForChildren function)
*If any errors happened the programm terminates all runnung zombie processes (KillTheUndead function)
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