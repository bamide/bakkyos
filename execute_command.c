#include "main.h"

/**
 * execute_env - Prints the current environment variables.
 */
void execute_env(void)
{                                                       
        int i;
	/* Declare a pointer to the environment variables */
	extern char **environ;

	/* Loop through the environment variables and print them */
	for (i = 0; environ[i] != NULL; i++)
	{
		printf("%s\n", environ[i]);
	}
} 
