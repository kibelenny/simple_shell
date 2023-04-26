#include "main.h"

/**
* print_prompt - Prints the prompt
* Return: None
*/

void print_prompt(void)
{
	char cwd[1024];

	getcwd(cwd, sizeof(cwd));
	printf("\n╭─%s\n╰─> ", cwd);
}
