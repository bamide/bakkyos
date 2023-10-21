#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Simple shell with cd command.
 *
 * Return: Always 0.
 */
int main(void)
{
    char *home = getenv("HOME");
    char *prev_dir = NULL;
    char *current_dir = NULL;
    char input[100];

    while (1)
    {
        printf("$ ");
        fgets(input, sizeof(input), stdin);

        if (input[strlen(input) - 1] == '\n')
        {
            input[strlen(input) - 1] = '\0';
        }

        if (strncmp(input, "cd ", 3) == 0)
        {
            char *path = input + 3;
            if (strcmp(path, "-") == 0)
            {
                if (prev_dir != NULL)
                {
                    chdir(prev_dir);
                }
            }
            else
            {
                prev_dir = current_dir;
                current_dir = getcwd(NULL, 0);

                if (chdir(path) == 0)
                {
                    if (prev_dir != NULL)
                    {
                        free(prev_dir);
                    }
                    prev_dir = current_dir;
                    current_dir = getcwd(NULL, 0);

                    setenv("PWD", current_dir, 1);
                }
                else
                {
                    fprintf(stderr, "cd: %s: No such file or directory\n", path);
                }
            }
        }
        else if (strcmp(input, "cd") == 0)
        {
            if (home != NULL)
            {
                prev_dir = current_dir;
                current_dir = getcwd(NULL, 0);

                if (chdir(home) == 0)
                {
                    setenv("PWD", home, 1);
                }
                else
                {
                    fprintf(stderr, "cd: %s: No such file or directory\n", home);
                }
            }
        }
        else
        {
            // Handle other commands
            // ...
        }
    }

    return (0);
}
