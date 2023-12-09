#include "shell.h"

/**
 * _myExit - simple implementation of exit
 * @ptrs: structure containing all malloced memory.
 */

void _myExit(shell_t *ptrs)
{
	unsigned int i;
	char *exit_str;

	exit_str = ptrs->input_token[1];
	if (exit_str != NULL || ptrs == NULL)
	{
		errno = 0;
		for (i = 0; exit_str[i] != '\0'; i++)
		{
			errno = errno * 10 + (exit_str[i] - '0');
		}
	}
	free_shell_t(ptrs);
	if (errno > 255)
	{
		errno %= 256;
	}
	exit(errno);
}

/**
 *   _printEnv - prints out the current environment
 *   @ptrs: structure containing all malloced memory
 */
void _printEnv(shell_t *ptrs)
{
	unsigned int i, k;
	char newline = '\n';

	(void)ptrs;
	if (environ == NULL)
		return;

	for (i = 0; environ[i] != NULL; i++)
	{
		k = _strlen(environ[i]);
		if (k != 0)
		{
			write(STDOUT_FILENO, environ[i], k);
			write(STDOUT_FILENO, &newline, 1);
		}
	}
	errno = 0;
}
