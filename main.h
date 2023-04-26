#ifndef _MAIN_
#define _MAIN_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

char **split_str(char *str);
void print_prompt(void);
int exec_cmd(char **split_words);

#endif
