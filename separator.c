#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

/**
 * execute_command - Execute a command.
 * @command: The command to execute.
 */
void execute_command(char *command)
{
    char *args[100];
    int i = 0;

    char *token = strtok(command, " ");
    while (token != NULL)
    {
        args[i++] = token;
        token = strtok(NULL, " ");
    }
    args[i] = NULL;

    if (execvp(args[0], args) == -1)
    {
        perror("Error executing command");
    }
}

/**
 * main - Simple shell with command separator.
 *
 * Return: Always 0.
 */
int main(void)
{
    char input[1000];

    while (1)
    {
        printf("alex@~$ ");
        fgets(input, sizeof(input), stdin);

        if (input[strlen(input) - 1] == '\n')
        {
            input[strlen(input) - 1] = '\0';
        }

        char *command = strtok(input, ";");
        while (command != NULL)
        {
            int pid = fork();
            if (pid == 0)
            {
                // Child process
                execute_command(command);
                exit(0);
            }
            else if (pid > 0)
            {
                // Parent process
                wait(NULL);
            }
            else
            {
                perror("Fork failed");
            }
            command = strtok(NULL, ";");
        }
    }

    return 0;
}
