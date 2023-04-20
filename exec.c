#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main()
{
    char *path = getenv("PATH");
    char *p, *dir;
    

    while(*path != '\0')
    {
        dir = path;
        p = strchr(dir, ':');
        if(p == NULL)
        {
            printf("dead");
            break;
        }
        path = p + 1;
        printf("%s\n\n",p);
    }

    return 1;
}