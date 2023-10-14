#include "main.h"

/**
 * note - To print the function that display the prompt(output)
 *
 * @letter: input prompt
 *
 * Return: void
 */
void note(const char *letter)
{
	int leng;

	for (leng = 0; letter[leng] != '\0'; )
	{
		leng++;
	}

	/* This helps to print the stdout */
	write(STDOUT_FILENO, letter, leng);

}


/**
 * execom - To prints fxn that execute a command with arguments
 *
 * @comm: This is the command
 * @aug: array of arguments
 * @shel: shell pointer
 *
 * Return: void
 */
void execom(const char *comm, char *const aug[], char *shel)
{
	pid_t pikin_pid = fork();

	if (pikin_pid == -1)
	{
		perror("Our Fork has failed");
		return;
	}
	else if (pikin_pid > -1 && pikin_pid < 1)
	{
		/* The child process */
		execvp(comm, aug);
		perror(shel);
		exit(1);
	}
	else
	{
		int status;

		/* The parent process */
		waitpid(pikin_pid, &status, 0);
	}
}

