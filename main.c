#include "main.h"

int main(int ac, char **argv)
{
    char *prompt = "(Mshell) $ ";
    char *lineptr = NULL, *lineptr_copy = NULL;
    size_t n = 0;
    ssize_t nchars_read;
    const char *delim = " \n";
    int num_tokens = 0;
    char *token;
    int i;
    int status;
    pid_t child_pid;
   
    
    /* Declare void variables */
    (void)ac;

    /* Create a loop for the shell's prompt */
    while (1)
    {
        printf("%s", prompt);
        nchars_read = getline(&lineptr, &n, stdin);
        
        /* Check if the getline function failed or reached EOF or the user used CTRL + D */
        if (nchars_read == -1)
        {
            printf("Exiting shell....\n");
            return (-1);
        }

        /* Allocate space for a copy of the lineptr */
        lineptr_copy = malloc(sizeof(char) * nchars_read);
        if (lineptr_copy == NULL)
        {
            perror("tsh: memory allocation error");
            return (-1);
        }
        
        /* Copy lineptr to lineptr_copy */
        strcpy(lineptr_copy, lineptr);
        /********** Split the string (lineptr) into an array of words ********/
        
        /* Calculate the total number of tokens */
        token = strtok(lineptr, delim);
	child_pid = fork();
	if(child_pid == -1)
	{
	perror("Error:failed to create");
	exit(41);
	}
	if(child_pid == 0)
	{
	perror("Error:Failed");
	exit(7);
	}
	else
	{
	wait(&status);
	}
        while (token != NULL)
        {
            num_tokens++;
            token = strtok(NULL, delim);
        }
        num_tokens++;

        /* Allocate space to hold the array of strings */
        argv = malloc(sizeof(char *) * num_tokens);

        /* Store each token in the argv array */
        token = strtok(lineptr_copy, delim);
        
        for (i = 0; token != NULL; i++)
        {
            argv[i] = malloc(sizeof(char) * strlen(token));
            strcpy(argv[i], token);
            token = strtok(NULL, delim);
        }
        argv[i] = NULL;

        /* Execute the command */
        execmd(argv);
    }

    /* Free up allocated memory */
    free(lineptr_copy);
    free(lineptr);

    return (0);
}

