#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * set_env - Initialize a new environment variable or modify an existing one.
 * @variable: Name of the environment variable.
 * @value: Value to set for the environment variable.
 *
 * Return: 0 on success, -1 on failure.
 */
int set_env(char *variable, char *value)
{
	if (setenv(variable, value, 1) != 0)
	{
		fprintf(stderr, "Error setting environment variable\n");
		return -1;
	}
	return 0;
}

/**
 * unset_env - Remove an environment variable.
 * @variable: Name of the environment variable to remove.
 *
 * Return: 0 on success, -1 on failure.
 */
int unset_env(char *variable)
{
	if (unsetenv(variable) != 0)
	{
		fprintf(stderr, "Error unsetting environment variable\n");
		return -1;
	}
	return 0;
}

int main(void)
{
	/* Example usage */
	set_env("MY_VARIABLE", "some_value");
	unset_env("MY_VARIABLE");

	return 0;
}
