#include "main.h"

#define MAX_INPUT_LENGTH 1024

/**
* main - main function
* Return: 1
*/

int main(void)
{
	size_t n = 0;
	char *line = NULL;
	char **split_words = NULL;



	while (1)
	{
		print_prompt();
		if (getline(&line, &n, stdin) == -1)
		{
			printf("Exiting 😞....\n");
			break;
		}

		split_words = split_str(line);

		if (exec_cmd(split_words) == 1)
			continue;
		else
			return (0);
	}

	free(line);
	return (1);

}
