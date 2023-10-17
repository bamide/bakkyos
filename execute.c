#include "main.h"

/**
  * print_prompt - Print the prompt to the user
  */

void print_prompt(void)
{
	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "MShell$ ", 9);
}

/**
  * read_input - Reads the input from the users
  *
  * Return: Character variable to the program
  */

char *read_input(void)
{
	char *input_buffer;
	size_t buf_size;
	ssize_t nread;

	input_buffer = NULL;
	buf_size = 0;
	nread = getline(&input_buffer, &buf_size, stdin);

	if (nread == -1 || strcmp(input_buffer, "exit\n") == 0)
	{
		free(input_buffer);
		exit(0);
	}

	return (input_buffer);
}


/**
  * execute_command - Executes the input from the buffer
  * @input: The argument from the buffer
  * @env: Environment variables
  */

/**
  * tokenize_input - Tokenizes the input strings
  * @input: Argument input
  * @args: The array of strings
  *
  * Return: Number of the items tokenized
  */

int tokenize_input(char *input, char *args[])
{
	int count;
	char *token;

	count = 0;
	token = strtok(input, " \n");

	while (token)
	{
		args[count] = token;
		token = strtok(NULL, " \n");
		count++;
	}

	args[count] = NULL;
	return (count);
}

/**
  * handle_builtin_commands - Handle all the built in commands
  * @args: Arguments to the built in commands
  * @num_args: Number of argument
  * @input: The input command
  * @env: The environment variables
  *
  * Return: 1 if successful 0, if unsuccessful
  */

int handle_builtin_commands(char **args, int num_args, char *input, char **env)
{
	if (strcmp(args[0], "exit") == 0)
	{
		handle_exit(input);
		return (1);
	}
	else if (strcmp(args[0], "cd") == 0)
	{
		handle_cd(args, num_args);
		return (1);
	}
	else if (strcmp(args[0], "env") == 0)
	{
		print_env(env);
		return (1);
	}

	return (0);
}
