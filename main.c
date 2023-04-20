#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    char *prompt = "(KShell)😄 ";
    char *lineptr;
    /*copy of variable that stores the string read by getline*/
    char *lineptr_cpy; 
    size_t n = 0;
    __ssize_t num_count;
    
    
    /*Add void variable to silence the compiler.
    This is done because we have not used function parameters.*/
    (void)argc, (void)argv;


    while(1) 
    /*The loops means it will continue to execute indefinitely 
    until the program is terminated externally*/
    {
        printf("%s", prompt);
        num_count = getline(&lineptr, &n, stdin);
        /*Variable num_count holds return value for getline*/
        if (num_count == -1)
        /*The EOF encountered when user presses (ctrl + d)
        which returns a value of (-1)*/
        {
            printf("Exiting 😞....\n");
            return(-1);
        }

        printf("%s \n",lineptr);

        
    }
    /*allocate memory to the copy of string read*/
    lineptr_cpy = malloc(sizeof(char) * num_count);
    if (lineptr_cpy == NULL)
    {
        perror("Error in memory allocation");
        return(-1);
    }

    /*make a copy of lineptr*/
    strcpy(lineptr_cpy, lineptr);
    
    free(lineptr);
    return(0);
}