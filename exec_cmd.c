#include "main.h"

/**
* exec_cmd - exeuctes command
* @split_words: words with command to run
* Return: 1 if error, 0 otherwise
*/

int exec_cmd(char **split_words)
{
	pid_t pid;
	int status;

	pid = fork();
		if (pid == -1)
		{
			printf("Error forking");
			return (1);
		}

		if (pid == 0)
		{
			if (execvp(split_words[0], split_words) == -1)
			{
				printf("Execution Error");
				return (0);
			}
		} else
		{
			if (wait(&status) == -1)
			{
				perror("wait");
				return (1);
			}
		}

	return (1);
}
