#include "main.h"

/**
* split_str - Splits string and returns split tokens
* @str: string to split
* Return: array of words
*/

char **split_str(char *str)
{
	char *token, **words = malloc(50 * sizeof(char *));
	int count = 0;

	if (!str)
	{
		printf("String Error");
		return (NULL);
	}

	token = strtok(str, " \t\n");

	while (token != NULL)
	{
		words[count++] = token;
		token = strtok(NULL, " \t\n");
	}
	return (words);
}
