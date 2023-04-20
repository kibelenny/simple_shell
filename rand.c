#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_ARGS 10

int main() {
    char line[256];
    while (1) {
        // Print the prompt and read a line of input
        printf("$ ");
        fgets(line, sizeof(line), stdin);

        // Parse the line into command and arguments
        char *command = strtok(line, " \t\n");
        if (command == NULL) {
            continue;  // Empty line, ignore
        }
        char *args[MAX_ARGS + 1] = {command};
        int arg_count = 1;
        char *arg;
        while ((arg = strtok(NULL, " \t\n")) != NULL) {
            if (arg_count >= MAX_ARGS) {
                fprintf(stderr, "Too many arguments\n");
                break;
            }
            args[arg_count++] = arg;
        }
        args[arg_count] = NULL;

        // Fork a child process to execute the command
        pid_t pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            // Child process: execute the command
            execvp(command, args);
            // If execvp returns, there was an error
            perror("execvp");
            exit(EXIT_FAILURE);
        } else {
            // Parent process: wait for the child to finish
            int status;
            waitpid(pid, &status, 0);
            if (WIFEXITED(status)) {
                int exit_status = WEXITSTATUS(status);
                printf("Child exited with status %d\n", exit_status);
            } else if (WIFSIGNALED(status)) {
                int signal_number = WTERMSIG(status);
                printf("Child terminated by signal %d\n", signal_number);
            }
        }
    }
    return 0;
}
