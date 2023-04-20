#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_INPUT_LENGTH 1024

char **split_str(char *str)
{
    char *token, **words = malloc(50 * sizeof(char*));
    int count = 0;

    if (!str)
    {
        printf("String Error");
        return NULL;
    }
    token = strtok(str, " \t\n");
    while (token != NULL)
    {
        words[count++] = token;
        token = strtok(NULL, " \t\n");
    }
    return words;
}

int main(void)
{
    size_t n = 0;
    char  *line = NULL;
    char **split_words = NULL;
    char cwd[MAX_INPUT_LENGTH];
    pid_t pid;
    int status;

    while(1)
    {
        getcwd(cwd, sizeof(cwd));
        printf("\n╭─%s\n╰─> ", cwd);
        if (getline(&line, &n, stdin) == -1)
        {
            printf("Error reading command");
            return (0);
        }
        split_words = split_str(line);
        pid =  fork();

        if (pid == -1)
        {
            printf("Error forking");
            continue;
        }

        if(pid == 0)
        {
            if(execvp(split_words[0], split_words) == -1)
        {
            printf("Execution Error");
            return 0;
        }
        }

        else 
        {
            if(wait(&status) == -1)
            {
                perror("wait");
                continue;
            }
        }

        
        
        
    }

    free(line);
    return(1);
}